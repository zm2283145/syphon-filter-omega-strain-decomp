"""Tests for linking data from C units (docs/data_split.md)."""
import contextlib
import io
import json
import struct
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch
from pathlib import Path

import configure

sys.path.insert(0, str(configure.ROOT / "tools"))
import check_match  # noqa: E402
import assemble  # noqa: E402
import data_obj  # noqa: E402
import tail_obj  # noqa: E402
import integrate_pending  # noqa: E402

BIN = configure.ROOT / ".tools" / "binutils" / ("mips-ps2-decompals-" + "{}" + configure.EXE)
HAVE_BINUTILS = Path(str(BIN).format("as")).exists()


def tool(name):
    return str(BIN).format(name)



class DataDiagnosticTests(unittest.TestCase):
    def run_report(self, piece, json_output=False):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            rom = root / "build" / "orig" / "SCUS_972.64.rom"
            rom.parent.mkdir(parents=True)
            rom.write_bytes(b"\0" * 16)
            obj = root / "candidate.o"
            obj.write_bytes(b"mock object")
            argv = ["check_match.py", str(root / "candidate.c"), "-c", "gcc29"]
            if json_output:
                argv.append("--json")
            output = io.StringIO()
            with contextlib.ExitStack() as stack:
                stack.enter_context(patch.object(check_match, "ROOT", root))
                stack.enter_context(patch.object(sys, "argv", argv))
                stack.enter_context(patch.object(check_match, "symbols", return_value=({}, set())))
                stack.enter_context(patch.object(check_match, "compile_with", return_value=(str(obj), None)))
                stack.enter_context(patch.object(check_match, "compare", return_value=([], [])))
                stack.enter_context(patch.object(check_match, "ELFFile"))
                stack.enter_context(patch.object(check_match, "data_pieces", return_value=[piece]))
                stack.enter_context(contextlib.redirect_stdout(output))
                check_match.main()
            self.assertFalse(obj.exists())
            return output.getvalue()

    def test_unknown_size_reports_rejection(self):
        for reason in ("not referenced from code (cannot be placed)",
                       "inconsistent placement",
                       "the referenced items cannot be laid out in object order at their retail addresses"):
            with self.subTest(reason=reason):
                output = self.run_report(dict(section=".rodata", start=None, size=None, result=reason))
                self.assertEqual(output, f"[gcc29] DATA .rodata ? size ?: {reason}\n")

    def test_known_size_keeps_hex_format(self):
        output = self.run_report(dict(section=".rodata", start=0x100040, size=0x2C, result="MATCH"))
        self.assertEqual(output, "[gcc29] DATA .rodata 0x00100040 size 0x2c: MATCH\n")

    def test_unknown_size_stays_null_in_json(self):
        piece = dict(section=".rodata", start=None, size=None,
                     result="not referenced from code (cannot be placed)")
        report = json.loads(self.run_report(piece, json_output=True))
        self.assertEqual(report["gcc29"]["data"], [piece])


class DataPieceConfigTests(unittest.TestCase):
    subs = [(0x1000, "c", "main/f"), (0x1010, "asm", None), (0x2000, "data", "data"),
            (0x2100, ".rodata", "main/f"), (0x2118, "data", None)]

    def test_pieces_by_unit(self):
        self.assertEqual(configure.data_pieces(self.subs), {"main/f": [(0x2100, ".rodata")]})

    def test_piece_of_unknown_unit_rejected(self):
        with self.assertRaisesRegex(SystemExit, "not a C unit"):
            configure.data_pieces(self.subs + [(0x2300, ".rodata", "main/g")])

    def test_two_pieces_of_one_unit_rejected(self):
        with self.assertRaisesRegex(SystemExit, "more than one"):
            configure.data_pieces(self.subs + [(0x2300, ".data", "main/f")])

    def test_unsupported_dot_type_rejected(self):
        with self.assertRaisesRegex(SystemExit, "unsupported"):
            configure.data_pieces(self.subs + [(0x2300, ".bss", "main/f")])

    def test_link_script_sorts_the_tail(self):
        lines = [l.strip() for l in configure.link_script(0x4E9B70, 0x100000).splitlines()]
        i = lines.index(f"*({configure.LINK_SECTIONS})")
        self.assertEqual(lines[i + 1], "*(SORT_BY_NAME(.tail.*))")
        # renamed tail sections never match the code wildcard
        self.assertFalse(any(p.rstrip("*") and ".tail".startswith(p.rstrip("*"))
                             for p in configure.LINK_SECTIONS.split()))

    def test_block_labels_are_provided(self):
        with tempfile.TemporaryDirectory() as d:
            f = Path(d) / "b.rodata.s"
            f.write_text("dlabel D_004BED60\n    /* 3BED60 004BED60 */ .asciz \"x\"\n"
                         "dlabel jtbl_004BED70\n    /* 3BED70 004BED70 00000000 */ .word 0\n")
            labels = configure.block_labels(f)
        self.assertEqual(labels, [("D_004BED60", 0x4BED60), ("jtbl_004BED70", 0x4BED70)])
        self.assertIn("PROVIDE(D_004BED60 = 0x4bed60);", configure.link_script(0, 0x100000, labels))

    def test_tail_names_sort_by_address(self):
        names = [tail_obj.tail_name(a) for a in (0x4A7D30, 0x499BE8, 0x4BE4B0, 0x4C3700)]
        self.assertEqual(sorted(names), [tail_obj.tail_name(a) for a in (0x499BE8, 0x4A7D30, 0x4BE4B0, 0x4C3700)])


class TargetAssemblyTests(unittest.TestCase):
    def test_jump_table_entries_become_function_offsets(self):
        text = "\n".join(["glabel func_00100000", "    /* 0 00100000 00000000 */ nop",
                          "  jlabel .L00100048", ".section .rodata", "dlabel jtbl_00200000",
                          "    /* 100000 00200000 48001000 */ .word .L00100048",
                          "    /* 100004 00200004 00000000 */ .word .L00090000"])
        out = assemble.relative_jumptables(text)
        self.assertIn(".word func_00100000 + 0x48", out)
        self.assertIn(".word .L00090000", out)  # no function owns it: unchanged


class IntegratorSegmentTests(unittest.TestCase):
    yaml = ["segments:", "  - name: main", "    subsegments:",
            "      - [0x000000, asm]", "      - [0x000100, c, main/func_00100100]",
            "      - [0x000200, data, data]", "      # island", "      - [0x000300, asm, island_400300]",
            "      - [0x000400, .rodata, main/func_00100100]", "  - [0x000500]", ""]

    def test_parse_keeps_comments(self):
        first, last, segs, indent = integrate_pending.load_segments(self.yaml)
        self.assertEqual((first, last, indent), (3, 9, "      "))
        self.assertEqual([s[:3] for s in segs], [[0, "asm", None], [0x100, "c", "main/func_00100100"],
                                                 [0x200, "data", "data"], [0x300, "asm", "island_400300"],
                                                 [0x400, ".rodata", "main/func_00100100"]])
        self.assertEqual(segs[3][3], ["      # island"])
        self.assertEqual(integrate_pending.end_of_segments(self.yaml, last), 0x500)


@unittest.skipUnless(HAVE_BINUTILS, "MIPS binutils not installed (tools/setup_tools.py)")
class DataObjectTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.dir = Path(self.tmp.name)

    def assemble(self, text):
        src, obj = self.dir / "t.s", self.dir / "t.o"
        src.write_text(text)
        subprocess.check_call([tool("as"), "-EL", "-march=r5900", "-mabi=eabi", "-G0", "-o", str(obj), str(src)])
        return obj

    SRC = """
        .set noreorder
        .text
        .globl func_00100000
        .type func_00100000, @function
    func_00100000:
        lui $a0, %hi(tab)
        addiu $a0, $a0, %lo(tab)
        jr $ra
        nop
        .section .rodata
        .balign 16
    tab:
        .word 1, 2
        .word func_00100000 + 8
        .section .data
        .balign 16
    str:
        .asciz "abcdefghijklmnopq"
        .text
        lui $a1, %hi(str)
        addiu $a1, $a1, %lo(str)
    """

    def rom(self):
        rom = bytearray(0x100)
        struct.pack_into("<4I", rom, 0, 0x3C040010, 0x24840060, 0x03E00008, 0)   # tab at 0x100060
        struct.pack_into("<2I", rom, 0x10, 0x3C050010, 0x24A50040)                # str at 0x100040
        struct.pack_into("<3I", rom, 0x60, 1, 2, 0x100008)
        rom[0x40:0x40 + 18] = b"abcdefghijklmnopq\0"
        return rom

    def pieces(self, rom):
        from elftools.elf.elffile import ELFFile
        with open(self.assemble(self.SRC), "rb") as fh:
            return check_match.data_pieces(ELFFile(fh), bytes(rom), {})

    def test_block_placed_and_matched(self):
        # one block in object order (GNU as puts .data before .rodata): the string, then the 16-aligned table
        self.assertEqual(self.pieces(self.rom()),
                         [{"section": ".rodata", "start": 0x100040, "size": 0x2C, "result": "MATCH"}])

    def test_wrong_jump_target_detected(self):
        rom = self.rom()
        struct.pack_into("<I", rom, 0x68, 0x10000C)
        self.assertEqual(self.pieces(rom)[0]["result"], "DIFF at 0x28")

    def test_items_out_of_object_order_rejected(self):
        rom = self.rom()
        struct.pack_into("<4I", rom, 0, 0x3C040010, 0x24840020, 0x03E00008, 0)  # table before the string
        self.assertIn("cannot be laid out", self.pieces(rom)[0]["result"])

    def test_data_obj_merges_and_renames(self):
        obj = self.assemble(self.SRC)
        base, link = self.dir / "b.o", self.dir / "l.o"
        subprocess.check_call([sys.executable, str(configure.ROOT / "tools" / "data_obj.py"),
                               tool("ld"), tool("objcopy"), str(obj), str(base), str(link), "0x100058"])
        blob = base.read_bytes()
        b = {s[2]: s for s in data_obj.sections(blob)}
        self.assertNotIn(".data", b)
        # the 16-aligned string is laid out from 0x100058 like the retail block would be: 8 bytes of
        # alignment, then the string, the table at the next 16-byte boundary, padded to 4
        self.assertEqual(b[".rodata"][5], 8 + 0x20 + 12)
        addr, = struct.unpack_from("<I", blob, b[".rodata"][1] + 0x0C)
        self.assertEqual(addr, 0)
        names = [s[2] for s in data_obj.sections(link.read_bytes())]
        self.assertIn(".text", names)
        self.assertEqual(names.count(".tail.00100058"), 2)  # string and table, in object order
        self.assertFalse({".data", ".rodata"} & set(names))

    def test_tail_obj_renames_code_and_data(self):
        obj, out = self.assemble(self.SRC), self.dir / "t.link.o"
        tail_obj.rename(tool("objcopy"), str(obj), str(out), 0x4C3700, 0x4A7D30)
        names = {s[2] for s in data_obj.sections(out.read_bytes())}
        self.assertTrue({".tail.004C3700", ".tail.004A7D30"} <= names)
        self.assertFalse({".text", ".data", ".rodata"} & names)


if __name__ == "__main__":
    unittest.main()