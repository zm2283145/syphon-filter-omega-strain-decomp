#!/usr/bin/env python3
"""Wrap a linked program image back into the retail ELF container.

GNU ld cannot reproduce the exact header layout written by the original
Metrowerks linker (five PT_LOAD entries, unnamed section headers, .comment
and .reginfo after the image). The build links with GNU ld, extracts the raw
image with objcopy and then calls this script, which rebuilds the container
from config/elf_layout.json so the result can be compared byte-for-byte with
the retail executable.
"""
import argparse
import json
import struct

EHDR_SIZE = 0x34
PHDR_SIZE = 0x20
SHDR_SIZE = 0x28
IMAGE_OFFSET = 0x100


def num(v):
    return int(v, 0) if isinstance(v, str) else int(v)


def build(image, layout):
    loads = layout["loads"]
    phoff = EHDR_SIZE
    assert phoff + PHDR_SIZE * len(loads) <= IMAGE_OFFSET
    end_image = IMAGE_OFFSET + len(image)

    shstrtab = b"\0.shstrtab\0.strtab\0.symtab\0.comment\0.reginfo\0"
    name = {n: shstrtab.index(n.encode() + b"\0") for n in
            (".shstrtab", ".strtab", ".symtab", ".comment", ".reginfo")}
    comment = b"".join(s.encode() + b"\0" for s in layout["comment_section"])
    ri = layout["reginfo"]
    reginfo = struct.pack("<6I", num(ri["gprmask"]), *[num(x) for x in ri["cprmask"]],
                          num(ri["gp_value"]))

    off_shstr = end_image
    off_comment = off_shstr + len(shstrtab)
    off_reginfo = (off_comment + len(comment) + 3) & ~3
    shoff = off_reginfo + len(reginfo)

    out = bytearray(shoff + SHDR_SIZE * (5 + len(loads) + 1))
    ident = b"\x7fELF\x01\x01\x01" + b"\0" * 9
    struct.pack_into("<16sHHIIIIIHHHHHH", out, 0, ident, 2, 8, 1, num(layout["entry"]),
                     phoff, shoff, num(layout["e_flags"]), EHDR_SIZE, PHDR_SIZE,
                     len(loads), SHDR_SIZE, 5 + len(loads) + 1, 1)

    sections = []
    for i, ld in enumerate(loads):
        vaddr = num(ld["vaddr"])
        if ld["image"]:
            off, filesz = IMAGE_OFFSET, len(image)
        else:
            # empty segments sit before the image if they precede it, else after it
            off, filesz = (IMAGE_OFFSET - 0x20 if i == 0 else end_image), 0
        struct.pack_into("<8I", out, phoff + i * PHDR_SIZE, 1, off, vaddr, vaddr, filesz,
                         num(ld["memsz"]), ld["flags"], num(ld["align"]))
        shflags = 7 if ld["flags"] & 1 else 3
        sections.append((0, 1, shflags, vaddr, off, filesz, 0, 0, num(ld["align"]), 1))

    out[IMAGE_OFFSET:end_image] = image
    out[off_shstr:off_shstr + len(shstrtab)] = shstrtab
    out[off_comment:off_comment + len(comment)] = comment
    out[off_reginfo:off_reginfo + len(reginfo)] = reginfo

    shdrs = [(0,) * 10,
             (name[".shstrtab"], 3, 0, 0, off_shstr, len(shstrtab), 0, 0, 1, 1),
             (name[".strtab"], 3, 0, 0, 0, 0, 0, 0, 1, 1),
             (name[".symtab"], 2, 0, 0, 0, 0, 2, 0, 1, 16)]
    shdrs += sections
    shdrs += [(name[".comment"], 1, 0, 0, off_comment, len(comment), 0, 0, 1, 1),
              (name[".reginfo"], 0x70000006, 0, 0, off_reginfo, len(reginfo), 0, 0, 4, 1)]
    for i, sh in enumerate(shdrs):
        struct.pack_into("<10I", out, shoff + i * SHDR_SIZE, *sh)
    return bytes(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image", help="raw program image (objcopy -O binary)")
    ap.add_argument("layout", help="config/elf_layout.json")
    ap.add_argument("out")
    a = ap.parse_args()
    image = open(a.image, "rb").read()
    layout = json.load(open(a.layout))
    open(a.out, "wb").write(build(image, layout))


if __name__ == "__main__":
    main()
