"""Reviewed stride offsets must not become symbol-address relocations."""
import json
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

import configure
from tools import assemble

BIN = configure.ROOT / ".tools" / "binutils" / ("mips-ps2-decompals-" + "{}" + configure.EXE)
HAVE_BINUTILS = all(Path(str(BIN).format(name)).exists() for name in ("as", "ld", "objcopy"))
TEXT = """.set noat
.set noreorder
.section .text, "ax"
.globl example
example:
/* 0 00100000 1300013C */ lui $at, %hi(offset)
/* 4 00100004 21088100 */ addu $at, $a0, $at
/* 8 00100008 003920AC */ sw $zero, %lo(offset)($at)
"""
PAIR = {"hi": "0x100000", "lo": "0x100008", "value": "0x133900"}


class LiteralOffsetTests(unittest.TestCase):
    def test_explicit_pair_only_and_idempotence(self):
        other = "lui $v1, %hi(real_global)\nlw $v0, %lo(real_global)($v1)\n"
        result = assemble.literal_offsets(TEXT + other, [PAIR])
        self.assertIn("lui $at, 0x13", result)
        self.assertIn("sw $zero, 14592($at)", result)
        self.assertTrue(result.endswith(other))
        self.assertEqual(assemble.literal_offsets(result, [PAIR]), result)

    def test_signed_low_half(self):
        text = TEXT.replace("1300013C", "1D00013C").replace("003920AC", "80D520AC")
        pair = dict(PAIR, value="0x1CD580")
        result = assemble.literal_offsets(text, [pair])
        self.assertIn("lui $at, 0x1d", result)
        self.assertIn("sw $zero, -10880($at)", result)

    def test_reject_stale_values_missing_instructions_and_wrong_pattern(self):
        cases = [(TEXT, dict(PAIR, value="0x133904")),
                 (TEXT, dict(PAIR, lo="0x100010")),
                 (TEXT.replace("21088100", "00000000"), PAIR),
                 (TEXT.replace("003920AC", "0039208C"), PAIR),
                 (TEXT.replace("%lo(offset)", "0x3900"), PAIR)]
        for text, pair in cases:
            with self.subTest(pair=pair, text=text):
                with self.assertRaises(ValueError):
                    assemble.literal_offsets(text, [pair])

    def test_configuration_is_scoped_to_one_assembly_unit(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "config").mkdir()
            (root / "config/asm_literal_offsets.json").write_text(json.dumps({
                "example": {"pairs": [PAIR]}}))
            with patch.object(assemble, "ROOT", root):
                self.assertEqual(assemble.literal_offset_pairs(root / "asm/example.s"), [PAIR])
                self.assertEqual(assemble.literal_offset_pairs(root / "asm/other.s"), [])
                self.assertEqual(assemble.literal_offset_pairs(root / "other/example.s"), [])

    @unittest.skipUnless(HAVE_BINUTILS, "MIPS binutils unavailable")
    def test_linked_instruction_bytes_are_unchanged(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            images = []
            for label, text in (("symbolic", TEXT),
                                ("literal", assemble.literal_offsets(TEXT, [PAIR]))):
                source, obj, elf, binary = (root / (label + suffix) for suffix in (".s", ".o", ".elf", ".bin"))
                source.write_text(text)
                subprocess.run([str(BIN).format("as"), "-EL", "-march=r5900", "-mabi=eabi",
                                "-no-pad-sections", "-o", str(obj), str(source)], check=True, capture_output=True)
                subprocess.run([str(BIN).format("ld"), "-EL", "-Ttext", "0x100000", "-e", "example",
                                "--defsym", "offset=0x133900", "-o", str(elf), str(obj)], check=True, capture_output=True)
                subprocess.run([str(BIN).format("objcopy"), "-j", ".text", "-O", "binary", str(elf), str(binary)],
                               check=True, capture_output=True)
                images.append(binary.read_bytes())
            self.assertEqual(images[0], images[1])
            self.assertEqual(images[0][:12], bytes.fromhex("1300013C21088100003920AC"))
