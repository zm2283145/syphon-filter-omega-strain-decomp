"""Tests for folding alignment padding into the unit in front (tools/fold_padding.py)."""
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

import configure

sys.path.insert(0, str(configure.ROOT / "tools"))
import fold_padding  # noqa: E402
import integrate_pending  # noqa: E402

BIN = configure.ROOT / ".tools" / "binutils" / ("mips-ps2-decompals-" + "{}" + configure.EXE)
HAVE_BINUTILS = Path(str(BIN).format("as")).exists()

JR_RA, ADDIU = 0x03E00008, 0x27BDFFF0


def rom_with(words):
    """ROM image from {offset: word}; every other word is zero."""
    rom = bytearray(0x100)
    for off, w in words.items():
        struct.pack_into("<I", rom, off, w)
    return bytes(rom)


def seg(start, typ, name=None, comments=None):
    return [start, typ, name, comments or []]


class FoldTests(unittest.TestCase):
    # a C function at 0x00..0x13 (ends with jr ra + delay slot), zero words up to
    # 0x20, a function at 0x20..0x27, zero words up to 0x30, a function at 0x30
    ROM = rom_with({0x00: ADDIU, 0x0C: JR_RA, 0x10: ADDIU, 0x20: JR_RA, 0x30: ADDIU, 0x34: JR_RA})

    def fold(self, segs, end=0x40, rom=ROM):
        return fold_padding.fold([list(s) for s in segs], end, rom)

    def test_asm_subsegment_starts_at_first_instruction(self):
        segs, changes = self.fold([seg(0x00, "c", "main/func_00100000"), seg(0x14, "asm")])
        self.assertEqual([s[:3] for s in segs], [[0x00, "c", "main/func_00100000"], [0x20, "asm", None]])
        self.assertEqual(changes, [(0x14, 0x20)])

    def test_padding_only_subsegment_is_dropped(self):
        segs, changes = self.fold([seg(0x00, "c", "main/func_00100000"), seg(0x14, "asm", None, ["# note"]),
                                   seg(0x20, "c", "main/func_00100020"), seg(0x28, "asm")])
        self.assertEqual([s[:3] for s in segs], [[0x00, "c", "main/func_00100000"],
                                                 [0x20, "c", "main/func_00100020"], [0x30, "asm", None]])
        self.assertEqual(segs[1][3], ["# note"])  # comments stay in front of the next subsegment
        self.assertEqual(changes, [(0x14, None), (0x28, 0x30)])

    def test_idempotent(self):
        segs, _ = self.fold([seg(0x00, "c", "main/func_00100000"), seg(0x14, "asm")])
        again, changes = self.fold(segs)
        self.assertEqual(again, segs)
        self.assertEqual(changes, [])

    def test_leading_nop_of_a_function_is_kept(self):
        # the run ends on a 4-aligned address that the previous end does not align up to:
        # the zero word is the first instruction of a function, not padding
        rom = rom_with({0x00: ADDIU, 0x0C: JR_RA, 0x24: ADDIU})
        segs, changes = self.fold([seg(0x00, "c", "main/func_00100000"), seg(0x10, "asm")], rom=rom)
        self.assertEqual(changes, [])
        self.assertEqual(segs[1][:2], [0x10, "asm"])

    def test_padding_before_data_is_kept(self):
        segs, changes = self.fold([seg(0x00, "c", "main/func_00100000"), seg(0x14, "asm"),
                                   seg(0x20, "data", "data_100020")])
        self.assertEqual(changes, [])

    def test_only_after_code(self):
        segs, changes = self.fold([seg(0x00, "data", "d"), seg(0x14, "asm")])
        self.assertEqual(changes, [])
        segs, changes = self.fold([seg(0x14, "asm")])  # nothing in front
        self.assertEqual(changes, [])

    def test_nonzero_start_is_kept(self):
        segs, changes = self.fold([seg(0x00, "c", "main/func_00100000"), seg(0x20, "asm")])
        self.assertEqual(changes, [])

    def test_island_name_follows_its_start(self):
        segs, _ = self.fold([seg(0x00, "c", "main/sinit/func_00100000"), seg(0x14, "asm", "sinit_100014")])
        self.assertEqual(segs[1][:3], [0x20, "asm", "sinit_100020"])

    def test_yaml_lines_round_trip(self):
        yaml = ["segments:", "  - name: main", "    subsegments:", "      - [0x000000, c, main/func_00100000]",
                "      # x", "      - [0x000014, asm]", "  - [0x000040]", ""]
        first, last, segs, indent = integrate_pending.load_segments(yaml)
        self.assertEqual(integrate_pending.dump_segments(segs, indent), yaml[first:last])


@unittest.skipUnless(HAVE_BINUTILS, "MIPS binutils not installed (tools/setup_tools.py)")
class LinkTests(unittest.TestCase):
    """The build recreates folded padding: the next object is aligned by its address."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dir = Path(self.tmp.name)

    def obj(self, name, words, start):
        src, obj = self.dir / (name + ".s"), self.dir / (name + ".o")
        src.write_text(".set noreorder\n.text\n" + "".join(f".word {w:#x}\n" for w in words))
        subprocess.check_call([sys.executable, str(configure.ROOT / "tools" / "assemble.py"),
                               str(BIN).format("as"), str(BIN).format("objcopy"),
                               str(fold_padding.alignment(start)), str(obj), str(src),
                               "-EL", "-march=r5900", "-mabi=eabi", "-G0"])
        return obj

    def link(self, *objs):
        script, elf, image = self.dir / "link.ld", self.dir / "out.elf", self.dir / "out.bin"
        script.write_text(configure.link_script(0, 0x100000))
        subprocess.check_call([str(BIN).format("ld"), "-EL", "-T", str(script), "-o", str(elf)] + [str(o) for o in objs])
        subprocess.check_call([str(BIN).format("objcopy"), "-O", "binary", str(elf), str(image)])
        return image.read_bytes()

    def test_zero_fill_up_to_the_next_function(self):
        # a 0x14-byte unit, then a function whose subsegment was moved to 0x20
        image = self.link(self.obj("c", [ADDIU, 0, 0, JR_RA, ADDIU], 0x100000),
                          self.obj("asm", [JR_RA, 0], 0x100020))
        expect = rom_with({0x00: ADDIU, 0x0C: JR_RA, 0x10: ADDIU, 0x20: JR_RA})[:0x30]
        self.assertEqual(image, expect)
        segs, _ = fold_padding.fold([seg(0x00, "c", "c"), seg(0x14, "asm")], 0x30, expect)
        self.assertEqual(segs[1][0], 0x20)  # the fold agrees with what the linker produced


ROM = configure.ROOT / "build" / "orig" / "SCUS_972.64.rom"


@unittest.skipUnless(ROM.exists(), "retail ROM not extracted yet (python configure.py)")
class LayoutTests(unittest.TestCase):
    def test_no_subsegment_starts_on_alignment_padding(self):
        y = (configure.ROOT / "config" / "splat.yaml").read_text().split("\n")
        first, last, segs, _ = integrate_pending.load_segments(y)
        end = integrate_pending.end_of_segments(y, last)
        _, changes = fold_padding.fold(segs, end, ROM.read_bytes())
        self.assertEqual([f"{s + fold_padding.BASE:08X}" for s, _ in changes], [],
                         "asm subsegments start on padding: run tools/fold_padding.py")


if __name__ == "__main__":
    unittest.main()
