#!/usr/bin/env python3
"""Extract the loadable image ("rom") from the user's own SCUS_972.64.

The rom is the concatenation of the PT_LOAD segments that carry file data
(for this executable: one segment at vram 0x00100000). splat splits this
rom; the build re-links it and tools/elf_rebuild.py wraps it back into an ELF.
Nothing produced here may be committed.
"""
import argparse
import hashlib
import struct
import sys


def load_segments(data):
    if data[:4] != b"\x7fELF":
        sys.exit("not an ELF file")
    (phoff,) = struct.unpack_from("<I", data, 0x1C)
    phentsize, phnum = struct.unpack_from("<HH", data, 0x2A)
    segs = []
    for i in range(phnum):
        p_type, off, vaddr, paddr, filesz, memsz, flags, align = struct.unpack_from(
            "<8I", data, phoff + i * phentsize
        )
        if p_type == 1 and filesz:
            segs.append((vaddr, off, filesz))
    return segs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("elf")
    ap.add_argument("rom")
    ap.add_argument("--sha256", help="expected SHA-256 of the input ELF")
    a = ap.parse_args()
    data = open(a.elf, "rb").read()
    if a.sha256:
        got = hashlib.sha256(data).hexdigest()
        if got.lower() != a.sha256.lower():
            sys.exit(f"{a.elf}: SHA-256 {got} does not match expected {a.sha256}")
    segs = load_segments(data)
    if len(segs) != 1:
        sys.exit(f"expected exactly one file-backed PT_LOAD segment, found {len(segs)}")
    vaddr, off, size = segs[0]
    with open(a.rom, "wb") as f:
        f.write(data[off : off + size])
    print(f"wrote {a.rom}: {size:#x} bytes (vram {vaddr:#010x})")


if __name__ == "__main__":
    main()
