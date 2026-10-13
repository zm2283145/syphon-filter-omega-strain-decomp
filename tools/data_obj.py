#!/usr/bin/env python3
"""Prepare the object of a C unit that links its own data.

usage: data_obj.py LD OBJCOPY RAW.o BASE.o LINK.o START [TEXT [TARGET.o]]

A unit with a `[ROM, .rodata, unit]` (or .data) subsegment in config/splat.yaml
emits its data from C. The original link kept each object's data sections in
object order as one block (string literals and jump tables interleaved, not
grouped by section kind), far from the object's code. START is the retail
address of that block.

LINK.o is RAW.o with every data section renamed .tail.<START> (and, for a unit
whose code is in the tail too, .text renamed .tail.<TEXT>): the linker script
places .tail.* sections sorted by name, i.e. by address, after the code, in
object order and with their own alignment (tools/tail_obj.py, configure.py).

BASE.o is the objdiff base: `ld -r` merges all data sections, in object order,
into one section named like the block's subsegment type (.rodata if the unit
has any .rodata, else .data), laid out as if it started at START (so inner
16-byte alignments fall where they do in the retail block) and padded to a
multiple of 4 bytes, the way the block is cut out of the retail data. With
TARGET.o (the unit's objdiff target), retail data labels that have no symbol in
the block (GCC's anonymous `.LC` data) get one, so objdiff can pair them.

Uninitialised data (.bss/.sbss/common) cannot be placed yet and is an error.
"""
import os
import struct
import subprocess
import sys

import tail_obj

DATA_KINDS = (".data", ".rodata", ".sdata")
NOBITS = 8
SHF_ALLOC, SHF_EXECINSTR = 2, 4
# not data: assembler bookkeeping, and the C++ exception index the link discards for all units
NOT_DATA = (".reginfo", ".MIPS.", ".pdr", ".mdebug", ".gnu", ".note", ".exceptix", ".exception")


def sections(blob):
    """[(index, header offset, name, type, flags, size, align)] of an ELF32 LE object."""
    shoff, = struct.unpack_from("<I", blob, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", blob, 0x2E)
    hdr = lambda i: shoff + i * shentsize
    stroff, = struct.unpack_from("<I", blob, hdr(shstrndx) + 0x10)
    out = []
    for i in range(shnum):
        h = hdr(i)
        name_off, typ, flags = struct.unpack_from("<III", blob, h)
        size, = struct.unpack_from("<I", blob, h + 0x14)
        align, = struct.unpack_from("<I", blob, h + 0x20)
        end = blob.index(b"\0", stroff + name_off)
        out.append((i, h, blob[stroff + name_off:end].decode(), typ, flags, size, align))
    return out


def grow_last_symbol(blob, secs, index, size):
    """Let the block's last data symbol cover the padding to 4 bytes.

    objdiff compares data symbol by symbol; the retail item (splat's label)
    runs up to the next 4-byte aligned label, the compiled one ends at its
    last byte."""
    symtab = next((s for s in secs if s[3] == 2), None)  # SHT_SYMTAB
    if symtab is None:
        return
    off, = struct.unpack_from("<I", blob, symtab[1] + 0x10)
    entsize, = struct.unpack_from("<I", blob, symtab[1] + 0x24)
    ends = []
    for k in range(symtab[5] // entsize):
        e = off + k * entsize
        value, sz = struct.unpack_from("<II", blob, e + 4)
        info, = struct.unpack_from("<B", blob, e + 12)
        shndx, = struct.unpack_from("<H", blob, e + 14)
        if shndx == index and sz and info & 0xF != 3:  # not STT_SECTION
            ends.append((value + sz, e, value))
    if ends:
        end, e, value = max(ends)
        if end < size:
            struct.pack_into("<I", blob, e + 8, size - value)


def symbols(blob, secs):
    """[(entry offset, name, value, size, type, shndx)] of an ELF32 LE object's symtab."""
    symtab = next((s for s in secs if s[3] == 2), None)  # SHT_SYMTAB
    if symtab is None:
        return []
    off, = struct.unpack_from("<I", blob, symtab[1] + 0x10)
    entsize, = struct.unpack_from("<I", blob, symtab[1] + 0x24)
    link, = struct.unpack_from("<I", blob, symtab[1] + 0x18)
    stroff, = struct.unpack_from("<I", blob, secs[link][1] + 0x10)
    out = []
    for k in range(symtab[5] // entsize):
        e = off + k * entsize
        name_off, value, sz = struct.unpack_from("<III", blob, e)
        info, = struct.unpack_from("<B", blob, e + 12)
        shndx, = struct.unpack_from("<H", blob, e + 14)
        end = blob.index(b"\0", stroff + name_off)
        out.append((e, blob[stroff + name_off:end].decode(), value, sz, info & 0xF, shndx))
    return out


def target_labels(target):
    """{name: block offset} of the retail data labels in the objdiff target.

    GCC emits string literals and other anonymous data under local `.LC` labels
    that do not reach the symbol table, so objdiff finds nothing in the base to
    pair with the retail labels and scores the bytes as unmatched. The base gets
    a symbol at each retail label offset that has none (name_block)."""
    blob = open(target, "rb").read()
    secs = sections(blob)
    data = {s[0] for s in secs
            if s[4] & SHF_ALLOC and not s[4] & SHF_EXECINSTR and s[5] and s[3] != NOBITS
            and not s[2].startswith(NOT_DATA)}
    if len(data) != 1:
        return {}
    return {name: value for _, name, value, _, typ, shndx in symbols(blob, secs)
            if shndx in data and typ == 1 and not name.endswith(".NON_MATCHING")}  # STT_OBJECT


def name_block(objcopy, base, kind, labels):
    """Add a local object symbol at every retail label offset of the block that has no symbol."""
    if not labels:
        return
    blob = open(base, "rb").read()
    secs = sections(blob)
    index = next(s[0] for s in secs if s[2] == kind)
    size = secs[index][5]
    syms = symbols(blob, secs)
    taken = {value for _, _, value, _, typ, shndx in syms if shndx == index and typ != 3}
    names = {name for _, name, *_ in syms}
    add = [(off, name) for name, off in labels.items()
           if off < size and off not in taken and name not in names]
    if not add:
        return
    args = []
    for off, name in sorted(add):
        args += ["--add-symbol", f"{name}={kind}:{off:#x},local,object"]
    subprocess.check_call([objcopy, *args, base])
    # objcopy cannot set sizes: each added symbol runs to the next symbol or the block end
    blob = bytearray(open(base, "rb").read())
    secs = sections(blob)
    syms = symbols(blob, secs)
    starts = sorted({value for _, _, value, _, typ, shndx in syms if shndx == index and typ != 3} | {size})
    added = {name for _, name in add}
    for e, name, value, sz, typ, shndx in syms:
        if shndx == index and name in added and not sz:
            nxt = next(s for s in starts if s > value)
            struct.pack_into("<I", blob, e + 8, nxt - value)
    open(base, "wb").write(blob)


def block_kind(names):
    """Section name of a unit's merged data block (= its subsegment type)."""
    for k in (".rodata", ".data", ".sdata"):
        if k in names:
            return k


def main():
    ld, objcopy, raw, base, link, start = sys.argv[1:7]
    start = int(start, 0)
    text = int(sys.argv[7], 0) if len(sys.argv) > 7 and sys.argv[7] != "-" else None
    target = sys.argv[8] if len(sys.argv) > 8 else None
    blob = open(raw, "rb").read()
    secs = sections(blob)
    for i, h, name, typ, flags, size, align in secs:
        if typ == NOBITS and size and flags & SHF_ALLOC:
            sys.exit(f"{raw}: uninitialised data ({name}, {size:#x} bytes) cannot be linked from C yet; "
                     "declare it extern")
        if (flags & SHF_ALLOC and not flags & SHF_EXECINSTR and size and name not in DATA_KINDS
                and not name.startswith(NOT_DATA)):
            sys.exit(f"{raw}: data section {name} cannot be linked from C yet")
    present = {s[2] for s in secs if s[5] and s[2] in DATA_KINDS}
    kind = block_kind(present)
    if kind is None:
        sys.exit(f"{raw}: the unit has a data subsegment but no data")
    script = base + ".ld"
    with open(script, "w") as f:
        f.write("SECTIONS\n{\n    .text 0 : { *(.text*) }\n"
                f"    {kind} {start % 16:#x} : {{ *({' '.join(DATA_KINDS)}) }}\n}}\n")
    # GCC objects carry ECOFF debug info (.mdebug) that `ld -r` cannot merge; the base needs none
    tmp = base + ".in.o"
    subprocess.check_call([objcopy, "--remove-section", ".mdebug", "--remove-section", ".pdr", raw, tmp])
    try:
        subprocess.check_call([ld, "-EL", "-r", "-T", script, "-o", base, tmp])
    finally:
        os.unlink(tmp)
    # pad the block to a multiple of 4 (`. = ALIGN(4)` does not grow a section in `ld -r`)
    out = open(base, "rb").read()
    for i, h, name, typ, flags, size, align in sections(out):
        if name == kind and size % 4:
            off, = struct.unpack_from("<I", out, h + 0x10)
            pad = base + ".pad"
            with open(pad, "wb") as f:
                f.write(out[off:off + size] + bytes(-size % 4))
            try:
                subprocess.check_call([objcopy, "--update-section", f"{kind}={pad}", base])
            finally:
                os.unlink(pad)
    if target:
        name_block(objcopy, base, kind, target_labels(target))
    out = bytearray(open(base, "rb").read())
    secs = sections(out)
    for i, h, name, typ, flags, size, align in secs:
        if name == kind:
            struct.pack_into("<I", out, h + 0x0C, 0)  # sh_addr: the layout is done
            grow_last_symbol(out, secs, i, size)
    open(base, "wb").write(out)
    # the link object is rewritten only when it changes (the rule has restat), so a change
    # that only affects the objdiff base does not relink the executable
    tail_obj.rename(objcopy, raw, link, text, start)


if __name__ == "__main__":
    main()