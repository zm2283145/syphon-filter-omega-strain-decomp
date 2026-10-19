"""data_obj.py: padding an odd-sized data block keeps the block's relocations.

A GCC unit whose block ends with a string of odd length (0x4AFF30 + 0x173 for unit 0x30C780) has to be
padded to a multiple of 4. The old code did that with `objcopy --update-section`, which drops the section's
relocations, so the jump-table words lost their R_MIPS_32 entries and objdiff scored the block 92.89%.
It reuses the DataObjectTests helpers from tests/test_data_split.py.
"""
import struct
import subprocess
import sys
import unittest

import configure

sys.path.insert(0, str(configure.ROOT / "tools"))
import data_obj  # noqa: E402

sys.path.insert(0, str(configure.ROOT / "tests"))
from test_data_split import DataObjectTests, tool  # noqa: E402

SHT_REL = 9


def relocs(blob, name):
    """[(offset, type, symbol index)] of the SHT_REL section that applies to section NAME."""
    secs = data_obj.sections(blob)
    target = next(s[0] for s in secs if s[2] == name)
    out = []
    for s in secs:
        if s[3] != SHT_REL:
            continue
        info, = struct.unpack_from("<I", blob, s[1] + 0x1C)
        if info != target:
            continue
        off, = struct.unpack_from("<I", blob, s[1] + 0x10)
        for j in range(s[5] // 8):
            r_offset, r_info = struct.unpack_from("<II", blob, off + 8 * j)
            out.append((r_offset, r_info & 0xFF, r_info >> 8))
    return out


class DataObjectPadTests(DataObjectTests):
    # a switch-style jump table (GCC's `.word .L<n>`: R_MIPS_32 against .text) followed by a
    # 3-byte string, so the merged block is 16 + 3 = 19 bytes and needs one pad byte
    PAD_SRC = """
        .set noreorder
        .text
        .globl func_00100000
        .type func_00100000, @function
    func_00100000:
        lui $a0, %hi(jt)
        addiu $a0, $a0, %lo(jt)
    L1:
        jr $ra
        nop
    L2:
        lui $a1, %hi(str)
        addiu $a1, $a1, %lo(str)
        .size func_00100000, . - func_00100000
        .section .rodata
        .balign 16
    jt:
        .word L1, L2, L1, L2
    str:
        .asciz "ab"
    """

    def test_odd_block_padded_with_relocations(self):
        obj = self.assemble(self.PAD_SRC)
        self.assertEqual(len(relocs(obj.read_bytes(), ".rodata")), 4)
        base, link = self.dir / "b.o", self.dir / "l.o"
        subprocess.check_call([sys.executable, str(configure.ROOT / "tools" / "data_obj.py"),
                               tool("ld"), tool("objcopy"), str(obj), str(base), str(link), "0x100040"])
        blob = base.read_bytes()
        rodata = next(s for s in data_obj.sections(blob) if s[2] == ".rodata")
        self.assertEqual(rodata[5], 20)  # 19 bytes padded to 20
        off, = struct.unpack_from("<I", blob, rodata[1] + 0x10)
        self.assertEqual(blob[off + 16:off + 20], b"ab\0\0")
        rel = relocs(blob, ".rodata")
        self.assertEqual([r[0] for r in rel], [0, 4, 8, 12])
        self.assertEqual({r[1] for r in rel}, {data_obj.R_MIPS_32})
        # function_relative rewrote them against the function, with in-function offsets as addends
        self.assertEqual(struct.unpack_from("<4I", blob, off), (8, 16, 8, 16))


if __name__ == "__main__":
    unittest.main()
