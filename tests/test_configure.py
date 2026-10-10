import argparse
import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import configure


class CompilerSelectionTests(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory()
        self.addCleanup(self.directory.cleanup)
        self.root = Path(self.directory.name)
        self.config = self.root / "compiler_overrides.json"
        self.subs = [(0x300000, "c", "main/example"),
                     (0x310000, "asm", None),
                     (0x320000, "c", "lib/example")]

    def write_overrides(self, value):
        self.config.write_text(json.dumps(value))

    def test_missing_config_preserves_default(self):
        self.assertEqual(configure.compiler_overrides(self.config, self.subs), {})

    def test_named_unit_override(self):
        overrides = {"main/example": "cwps2-3.04"}
        self.write_overrides(overrides)
        self.assertEqual(configure.compiler_overrides(self.config, self.subs), overrides)

    def test_unknown_unit_rejected(self):
        self.write_overrides({"main/missing": "cwps2-3.04"})
        with self.assertRaisesRegex(SystemExit, "unknown C unit"):
            configure.compiler_overrides(self.config, self.subs)

    def test_gcc_override_rejected(self):
        self.write_overrides({"lib/example": "cwps2-3.04"})
        with self.assertRaisesRegex(SystemExit, "GCC unit"):
            configure.compiler_overrides(self.config, self.subs)

    def test_invalid_shapes_rejected(self):
        for value in ([], {"main/example": 3}, {"main/example": "../compiler"}):
            with self.subTest(value=value):
                self.write_overrides(value)
                with self.assertRaises(SystemExit):
                    configure.compiler_overrides(self.config, self.subs)

    def test_invalid_json_reported(self):
        self.config.write_text("{")
        with self.assertRaisesRegex(SystemExit, "Cannot read"):
            configure.compiler_overrides(self.config, self.subs)

    def test_directory_argument_allows_spaces_and_equals(self):
        self.assertEqual(configure.compiler_directory("cwps2-3.04=local tools=304"),
                         ("cwps2-3.04", Path("local tools=304")))

    def test_directory_argument_requires_name_and_path(self):
        for value in ("compiler", "=tools", "compiler=", "../compiler=tools"):
            with self.subTest(value=value):
                with self.assertRaises(argparse.ArgumentTypeError):
                    configure.compiler_directory(value)

    def test_explicit_installation(self):
        compiler = self.root / "mwccps2.exe"
        compiler.touch()
        self.assertEqual(configure.mwcc_path("cwps2-3.04", {"cwps2-3.04": self.root}), compiler)

    def test_default_installation(self):
        compiler = self.root / ".tools" / "mwcc" / "example" / "mwccps2.exe"
        compiler.parent.mkdir(parents=True)
        compiler.touch()
        with patch.object(configure, "ROOT", self.root):
            self.assertEqual(configure.mwcc_path("example", {}), compiler)

    def test_missing_compiler_is_actionable(self):
        with self.assertRaisesRegex(SystemExit, "--compiler-dir"):
            configure.mwcc_path("missing", {"missing": self.root})

    def test_optional_missing_compiler_falls_back(self):
        self.assertIsNone(configure.mwcc_path("missing", {"missing": self.root}, required=False))

    def test_native_relative_executable_path(self):
        compiler = configure.ROOT / ".venv" / "Scripts" / "python.exe"
        expected = str(Path(".venv") / "Scripts" / "python.exe")
        if not configure.IS_WINDOWS:
            expected = expected.replace("\\", "/")
        self.assertEqual(configure.cmd_path(compiler), expected)

    def test_command_path_quotes_spaces_and_escapes_dollars(self):
        compiler = configure.ROOT / "local tools" / "$compiler.exe"
        result = configure.cmd_path(compiler)
        self.assertTrue(result.startswith('"') and result.endswith('"'))
        self.assertIn("$$compiler.exe", result)


if __name__ == "__main__":
    unittest.main()
