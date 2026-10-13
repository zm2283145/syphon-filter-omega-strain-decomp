#!/usr/bin/env python3
"""Resolve an EE-GCC object's gp-relative literal pool to the retail pool.

usage: lit_pool.py ROM GP VRAM OBJ

EE-GCC 2.96 without -G0 puts float/double constants it cannot build with
lui/ori in .lit4/.lit8 and loads them gp-relative (R_MIPS_LITERAL). The
original link merged these small literals of all objects into one shared
pool in the gp area: a function's literals are scattered over it (and shared
with other functions), so a unit's .lit4 cannot be placed as a block of its
own (docs/data_split.md). The pool is linked from the data-only units
(tools/data_gen.py) like any other retail data.

This tool does what the original linker's literal merging did: every load of
a pooled literal is pointed at the retail pool entry. VRAM is the retail
address of the object's .text, GP the retail gp value; the pool address of
each load comes from the retail instruction at the same place. The literal
value the C source produced must equal the retail pool bytes at that
address, else the tool fails (the pool bytes come from the data units, so
this is the only check of the source's constants). Each R_MIPS_LITERAL
against .lit4/.lit8 becomes an R_MIPS_GPREL16 against an undefined symbol
named like splat's label (config/symbol_addrs.txt, else D_<ADDR>), with
addend 0, and the .lit4/.lit8 sections are removed. Objects without them are
left alone. The result is the same instruction and relocation that splat's
assembly of the function has (`%gp_rel(D_xxx)($gp)`), so objdiff pairs them.
"""
import re
import struct
import sys
from pathlib import Path

BASE = 0x100000
LIT = {".lit4": 4, ".lit8": 8}
R_MIPS_GPREL16, R_MIPS_LITERAL = 7, 8
SHT_SYMTAB, SHT_REL, SHT_MIPS_REGINFO = 2, 9, 0x70000006
ROOT = Path(__file__).resolve().parent.parent


def sext16(v):
    return ((v & 0xFFFF) ^ 0x8000) - 0x8000


def sections(blob):
    """[(index, header offset, name, type, flags, offset, size, link, info, entsize)]"""
    shoff, = struct.unpack_from("<I", blob, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", blob, 0x2E)
    hdr = lambda i: shoff + i * shentsize
    stroff, = struct.unpack_from("<I", blob, hdr(shstrndx) + 0x10)
    out = []
    for i in range(shnum):
        h = hdr(i)
        name, typ, flags, _, off, size, link, info, _, entsize = struct.unpack_from("<10I", blob, h)
        end = blob.index(b"\0", stroff + name)
        out.append((i, h, blob[stroff + name:end].decode(), typ, flags, off, size, link, info, entsize))
    return out


def gp_value(repo=ROOT):
    m = re.search(r"^\s*gp_value:\s*(0x[0-9A-Fa-f]+|\d+)", (repo / "config" / "splat.yaml").read_text(), re.M)
    return int(m.group(1), 0)


def literals(blob, text_base, rom, gp):
    """Every pooled-literal load of the object.

    text_base: {section index: retail address} of its code sections.
    Returns [{"section", "offset", "size", "addr", "match", "rel", "insn"}]:
    the literal's section and offset in the object, its retail pool address
    (from the retail instruction), whether the bytes are equal, and the file
    offsets of the relocation entry and of the instruction."""
    secs = sections(blob)
    lits = {s[0]: s for s in secs if s[2] in LIT}
    if not lits:
        return []
    symtab = next(s for s in secs if s[3] == SHT_SYMTAB)
    reginfo = next((s for s in secs if s[3] == SHT_MIPS_REGINFO), None)
    gp0 = struct.unpack_from("<i", blob, reginfo[5] + 20)[0] if reginfo else 0
    out = []
    for rs in secs:
        if rs[3] != SHT_REL or rs[8] not in text_base:
            continue
        text = secs[rs[8]]
        for k in range(rs[6] // 8):
            e = rs[5] + k * 8
            r_offset, r_info = struct.unpack_from("<II", blob, e)
            if r_info & 0xFF not in (R_MIPS_LITERAL, R_MIPS_GPREL16):
                continue
            se = symtab[5] + (r_info >> 8) * 16
            value, = struct.unpack_from("<I", blob, se + 4)
            shndx, = struct.unpack_from("<H", blob, se + 14)
            if shndx not in lits:
                continue
            insn = text[5] + r_offset
            w, = struct.unpack_from("<I", blob, insn)
            offset = value + sext16(w) + gp0
            lit = lits[shndx]
            size = LIT[lit[2]]
            rw, = struct.unpack_from("<I", rom, text_base[rs[8]] + r_offset - BASE)
            addr = gp + sext16(rw)
            mine = blob[lit[5] + offset:lit[5] + offset + size]
            retail = rom[addr - BASE:addr - BASE + size] if addr >= BASE else b""
            out.append({"section": lit[2], "offset": offset, "size": size, "addr": addr,
                        "match": len(mine) == size and mine == retail, "rel": e, "insn": insn})
    return out


def label_names(repo=ROOT):
    names = {}
    for l in (repo / "config" / "symbol_addrs.txt").read_text().splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;", l)
        if m:
            names.setdefault(int(m.group(2), 16), m.group(1))
    return names


def redirect(blob, loads, names):
    """The object with each load pointed at an undefined symbol for its pool entry.

    New symbols are appended to the symbol table (globals come last, so the
    order rules hold); the symbol and string tables move to the end of the
    file. The literal sections stay (now unreferenced) for objcopy to drop."""
    blob = bytearray(blob)
    secs = sections(blob)
    symtab = next(s for s in secs if s[3] == SHT_SYMTAB)
    strtab = secs[symtab[7]]
    syms = bytearray(blob[symtab[5]:symtab[5] + symtab[6]])
    strs = bytearray(blob[strtab[5]:strtab[5] + strtab[6]])
    index = {}
    for k in range(len(syms) // 16):
        name, = struct.unpack_from("<I", syms, k * 16)
        info, = struct.unpack_from("<B", syms, k * 16 + 12)
        if info >> 4:  # global or weak
            index.setdefault(bytes(strs[name:strs.index(b"\0", name)]).decode(), k)
    for ld in loads:
        name = names.get(ld["addr"], f"D_{ld['addr']:08X}")
        if name not in index:
            index[name] = len(syms) // 16
            syms += struct.pack("<IIIBBH", len(strs), 0, 0, 0x10, 0, 0)  # GLOBAL NOTYPE UND
            strs += name.encode() + b"\0"
        r_offset, = struct.unpack_from("<I", blob, ld["rel"])
        struct.pack_into("<II", blob, ld["rel"], r_offset, (index[name] << 8) | R_MIPS_GPREL16)
        w, = struct.unpack_from("<I", blob, ld["insn"])
        struct.pack_into("<I", blob, ld["insn"], w & 0xFFFF0000)
    blob += bytes(-len(blob) % 4)
    struct.pack_into("<II", blob, strtab[1] + 0x10, len(blob), len(strs))
    blob += strs + bytes(-len(strs) % 4)
    struct.pack_into("<II", blob, symtab[1] + 0x10, len(blob), len(syms))
    blob += syms
    return bytes(blob)


def resolve(path, rom_path, gp, vram, repo=ROOT):
    """Rewrite the object at path in place; returns the literal sections to remove ([] if none)."""
    blob = open(path, "rb").read()
    secs = sections(blob)
    present = [s[2] for s in secs if s[2] in LIT and s[6]]
    if not present:
        return []
    rom = open(rom_path, "rb").read()
    texts = [s[0] for s in secs if s[2] == ".text"]
    loads = literals(blob, {texts[0]: vram}, rom, gp)
    bad = [ld for ld in loads if not ld["match"]]
    if bad:
        sys.exit(f"{path}: pooled literal{'s' if len(bad) > 1 else ''} "
                 + ", ".join(f"{ld['section']}+{ld['offset']:#x} -> {ld['addr']:08X}" for ld in bad)
                 + " differ from the retail pool")
    used = {(ld["section"], ld["offset"]) for ld in loads}
    for i, h, name, typ, flags, off, size, *_ in secs:
        if name in LIT:
            for o in range(0, size, LIT[name]):
                if (name, o) not in used:
                    sys.exit(f"{path}: {name}+{o:#x} is not loaded by the code; cannot be pooled")
    open(path, "wb").write(redirect(blob, loads, label_names(repo)))
    return present


def main():
    rom_path, gp, vram, obj = sys.argv[1:5]
    resolve(obj, rom_path, int(gp, 0), int(vram, 0))


if __name__ == "__main__":
    main()
