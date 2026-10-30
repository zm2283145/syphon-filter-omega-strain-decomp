import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from tools import check_match, integrate_pending


class SymbolAliasTests(unittest.TestCase):
    def test_linker_aliases_are_checked_and_cache_tracks_changes(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for folder in ("asm", "config", "build"):
                (root / folder).mkdir()
            (root / "asm/runtime.s").write_text(
                "nonmatching runtime, 0x4\nglabel runtime\n/* 0 00101250 00000000 */ nop\n")
            (root / "config/symbol_addrs.txt").write_text(
                "runtime = 0x00101250;\n")
            aliases = root / "config/extra.ld"
            aliases.write_text("__unexpected = 0x00101250; /* runtime */\n")
            with patch.object(check_match, "ROOT", root):
                names, starts = check_match.symbols()
                self.assertEqual(names["__unexpected"], 0x101250)
                self.assertIn(0x101250, starts)
                self.assertEqual(check_match.function_ends()[0x101250], 0x101254)
                self.assertEqual(check_match.symbols(), (names, starts))
                aliases.write_text("__unexpected = 0x00100D20;\n")
                self.assertEqual(check_match.symbols()[0]["__unexpected"], 0x100D20)
                aliases.unlink()
                self.assertNotIn("__unexpected", check_match.symbols()[0])


class CompilerProfileTests(unittest.TestCase):
    def test_gcc29a_uses_original_assembler_and_g0(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            compiler = root / ".tools/eegcc/ee-gcc2.9-991111a/bin/ee-gcc"
            compiler.parent.mkdir(parents=True)
            compiler.touch()
            (root / "build").mkdir()
            commands = []

            def compile_object(command, **kwargs):
                commands.append(command)
                Path(command[command.index("-o") + 1]).touch()
                from types import SimpleNamespace
                return SimpleNamespace(returncode=0, stdout="", stderr="")

            with patch.object(check_match, "ROOT", root), \
                 patch.object(check_match, "IS_WINDOWS", False), \
                 patch.object(check_match.subprocess, "run", side_effect=compile_object):
                obj, error = check_match.compile_with("gcc29a", root / "draft.c", [], {})
            self.assertIsNone(error)
            self.assertTrue(Path(obj).is_file())
            self.assertEqual(commands[0][0], str(compiler))
            self.assertIn("-G0", commands[0])
            self.assertEqual(integrate_pending.OVR["gcc29a"], "ee-gcc2.9-991111a")


class DiscardedDataTests(unittest.TestCase):
    def test_only_known_discard_section_is_ignored(self):
        from unittest.mock import MagicMock
        for section_name in (".dtors_drop", ".custom_data", ".dtors_drop_extra"):
            section = MagicMock()
            section.name = section_name
            fields = {"sh_type": "SHT_PROGBITS", "sh_flags": 2, "sh_size": 4}
            section.__getitem__.side_effect = fields.__getitem__
            elf = MagicMock()
            elf.iter_sections.return_value = iter([section])
            pieces = check_match.data_pieces(elf, b"", {})
            if section_name == ".dtors_drop":
                self.assertEqual(pieces, [])
            else:
                self.assertEqual(pieces[0]["result"], "section kind cannot be linked from C yet")


class FunctionExtentTests(unittest.TestCase):
    def test_recorded_end_excludes_following_padding_and_data(self):
        import struct
        from test_try_match import call_object
        with tempfile.TemporaryDirectory() as directory:
            obj = Path(directory) / "call.o"
            obj.write_bytes(call_object())
            rom = struct.pack("<II", 0x0C040008, 0) + b"non-code" + bytes(48)
            names = {"example": 0x100000, "target": 0x100020}
            starts = {0x100000, 0x100040}
            ends = {0x100000: 0x100008}
            results, undefined = check_match.compare(obj, rom, names, starts, ends)
            self.assertEqual(results, [("example", 0x100000, "MATCH")])
            self.assertEqual(undefined, [])
            # Neither a guessed short extent nor a boundary crossing is accepted.
            for bad_ends, bad_starts in (({0x100000: 0x100004}, starts),
                                         (ends, {0x100000, 0x100004})):
                results, _ = check_match.compare(obj, rom, names, bad_starts, bad_ends)
                self.assertIn("size", results[0][2])
            changed = rom[:4] + struct.pack("<I", 1) + rom[8:]
            results, _ = check_match.compare(obj, changed, names, starts, ends)
            self.assertIn("0x4", results[0][2])
