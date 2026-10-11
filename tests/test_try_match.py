import contextlib
import io
import json
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest
from unittest.mock import patch

from elftools.common.exceptions import ELFError

from tools import try_match


COMPARE = try_match.check_match.compare


def call_object():
    """Minimal MIPS ELF with a relocated call to an external symbol."""
    strings = b"\0example\0target\0"
    section_names = b"\0.text\0.symtab\0.strtab\0.shstrtab\0.rel.text\0"
    symbols = bytes(16)
    symbols += struct.pack("<IIIBBH", 1, 0, 8, 0x12, 0, 1)
    symbols += struct.pack("<IIIBBH", 9, 0, 0, 0x10, 0, 0)
    payloads = [struct.pack("<II", 0x0C000000, 0), symbols, strings,
                section_names, struct.pack("<II", 0, (2 << 8) | 4)]
    content = bytearray(52)
    offsets = []
    for payload in payloads:
        content.extend(bytes(-len(content) % 4))
        offsets.append(len(content))
        content.extend(payload)
    content.extend(bytes(-len(content) % 4))
    section_offset = len(content)
    content.extend(bytes(40))
    sections = [(".text", 1, 6, 0, 0, 4, 0), (".symtab", 2, 0, 3, 1, 4, 16),
                (".strtab", 3, 0, 0, 0, 1, 0), (".shstrtab", 3, 0, 0, 0, 1, 0),
                (".rel.text", 9, 0, 2, 1, 4, 8)]
    for offset, payload, (name, kind, flags, link, info, alignment, entry_size) in zip(offsets, payloads, sections):
        content.extend(struct.pack("<IIIIIIIIII", section_names.index(name.encode()), kind, flags,
                                   0, offset, len(payload), link, info, alignment, entry_size))
    identification = b"\x7fELF\x01\x01\x01" + bytes(9)
    content[:52] = struct.pack("<16sHHIIIIIHHHHHH", identification, 1, 8, 1, 0, 0,
                               section_offset, 0, 52, 0, 0, 40, 6, 4)
    return content


class TrialTests(unittest.TestCase):
    def setUp(self):
        temporary = tempfile.TemporaryDirectory()
        self.addCleanup(temporary.cleanup)
        self.root = Path(temporary.name).resolve()
        self.source = self.root / "nested source" / "candidate.c"
        self.source.parent.mkdir()
        self.original = b'#include "local.h"\r\n#pragma opt_propagation on\r\nint example(void) { return VALUE; }\r\n'
        self.source.write_bytes(self.original)
        (self.source.parent / "local.h").write_text("#define VALUE 1\n")
        self.rom = self.root / "reference.rom"
        self.rom.write_bytes(b"\0" * 64)
        self.symbols = self.root / "symbols.json"
        self.symbols.write_text(json.dumps({"names": {"example": 0x100000}, "starts": [0x100000]}))
        self.addCleanup(patch.stopall)
        patch.object(try_match, "ROOT", self.root).start()
        patch.object(try_match.check_match, "wrapper", return_value=[]).start()
        self.compiler = patch.object(try_match.subprocess, "run", side_effect=self.compile_ok).start()
        self.comparer = patch.object(try_match.check_match, "compare",
                                     return_value=([("example", 0x100000, "MATCH")], [])).start()
        self.symbol_loader = patch.object(try_match.check_match, "symbols",
                                          side_effect=AssertionError("must not regenerate cache")).start()
        self.invocations = []
        self.prefixes = []

    def args(self, *options):
        return try_match.parser().parse_args([str(self.source), "--rom", str(self.rom),
                                              "--symbols", str(self.symbols), *options])

    def compile_ok(self, command, **kwargs):
        directory = Path(kwargs["cwd"])
        obj = Path(command[command.index("-o") + 1])
        self.assertEqual(obj.parent, directory)
        self.assertTrue(directory.is_relative_to(self.root / "build"))
        self.assertEqual(command[-1], str(self.source))
        self.invocations.append((command, kwargs))
        if "-prefix" in command:
            prefix = Path(command[command.index("-prefix") + 1])
            self.assertEqual(prefix.parent, directory)
            self.prefixes.append(prefix.read_text())
        obj.write_bytes(b"mock object")
        (directory / "compiler.side-effect").write_text("temporary")
        return subprocess.CompletedProcess(command, 0, "compiler warning\n", "")

    def assert_clean(self):
        self.assertEqual(list((self.root / "build").iterdir()), [])
        self.assertEqual(self.source.read_bytes(), self.original)

    def test_default_is_one_unmodified_serial_trial(self):
        report = try_match.run_trials(self.args())
        self.assertEqual(report["trial_count"], 1)
        self.assertEqual(report["trials"][0]["profile"], "source")
        self.assertEqual(self.invocations[0][0][-1], str(self.source))
        self.assertEqual(self.invocations[0][1]["timeout"], 30)
        self.assertIn("-O4,p", self.invocations[0][0])
        self.assertIn(f"-I{self.root / 'include'}", self.invocations[0][0])
        self.symbol_loader.assert_not_called()
        self.assert_clean()

    def test_selection_order_is_reproducible(self):
        args = self.args("-c", "mw38,mw", "--profiles", "no-propagation,source")
        expected = [("mw38", "no-propagation"), ("mw38", "source"),
                    ("mw", "no-propagation"), ("mw", "source")]
        self.assertEqual(try_match.plan(args)[0], expected)
        report = try_match.run_trials(args)
        self.assertEqual([(trial["compiler"], trial["profile"]) for trial in report["trials"]], expected)
        self.assert_clean()

    def test_invalid_selections_and_bounds(self):
        for options in (("-c", "gcc"), ("-c", "mw,mw"), ("-c", "mw,"),
                        ("--profiles", "source,source"), ("--profiles", "everything"),
                        ("--max-trials", "0"), ("--max-trials", "16"),
                        ("--timeout", "0"), ("--timeout", "301"),
                        ("--timeout", "nan"), ("--timeout", "inf"),
                        ("--compiler-dir", "3.03J=local")):
            with self.subTest(options=options), contextlib.redirect_stderr(io.StringIO()):
                with self.assertRaises(SystemExit):
                    self.args(*options)
        self.compiler.assert_not_called()

    def test_over_budget_rejected_before_inputs_or_compiling(self):
        args = self.args("-c", "mw,mw38,mw304", "--profiles", ",".join(try_match.PROFILES))
        self.source.unlink()
        with self.assertRaisesRegex(ValueError, "15 trials exceed"):
            try_match.run_trials(args)
        self.compiler.assert_not_called()
        self.assertFalse((self.root / "build").exists())
        args.max_trials = 15
        self.assertEqual(len(try_match.plan(args)[0]), 15)

    def test_directory_selection_spaces_equals_and_duplicates(self):
        directory = self.root / "licensed tools=build"
        args = self.args("-c", "mw38", "--compiler-dir", f"mw38={directory}")
        try_match.run_trials(args)
        self.assertEqual(self.invocations[0][0][0], str(directory / "mwccps2.exe"))
        args.compiler_dir *= 2
        with self.assertRaisesRegex(ValueError, "duplicate --compiler-dir"):
            try_match.run_trials(args)
        self.assert_clean()

    def test_relative_wrapper_path_is_resolved_before_entering_scratch(self):
        relative = str(Path("local tools") / "runner")
        try_match.run_trials(self.args("--wrapper", relative))
        self.assertEqual(self.invocations[0][0][0], str(Path(relative).resolve()))
        self.assert_clean()

    def test_prefix_preserves_source_include_paths_and_pragma_precedence(self):
        include = self.root / "custom include"
        report = try_match.run_trials(self.args("--profiles", "no-propagation", "-I", str(include)))
        self.assertEqual(self.prefixes, ["#pragma opt_propagation off\n"])
        command = self.invocations[0][0]
        self.assertEqual(command[command.index("-cwd") + 1], "explicit")
        self.assertLess(command.index(f"-I{self.root}"), command.index(f"-I{include}"))
        self.assertLess(command.index(f"-I{include}"), command.index(f"-I{self.root / 'include'}"))
        trial = report["trials"][0]
        self.assertIn("source/header pragmas take precedence", trial["profile_effect"])
        self.assertIn("not verified", trial["profile_effect"])
        self.assertEqual(report["source_pragmas"], ["#pragma opt_propagation on"])
        self.assertEqual(trial["diagnostics"], "compiler warning")
        self.assert_clean()

    def test_unique_isolated_trial_and_run_directories(self):
        for _ in range(2):
            try_match.run_trials(self.args("--profiles", "source,no-peephole"))
        directories = [kwargs["cwd"] for _, kwargs in self.invocations]
        self.assertEqual(len(set(directories)), 4)
        self.assertEqual(len({path.parent for path in directories}), 2)
        self.assertTrue(all(not path.exists() for path in directories))
        self.assert_clean()

    def test_each_trial_finishes_cleanup_before_the_next_compiler(self):
        def compile_serial(command, **kwargs):
            if self.invocations:
                self.assertFalse(Path(self.invocations[-1][1]["cwd"]).exists())
            return self.compile_ok(command, **kwargs)
        self.compiler.side_effect = compile_serial
        try_match.run_trials(self.args("-c", "mw,mw38,mw304"))
        self.assertEqual(len(self.invocations), 3)
        self.assert_clean()

    def test_failure_partial_output_is_removed_and_next_trial_runs(self):
        def compile_some(command, **kwargs):
            completed = self.compile_ok(command, **kwargs)
            return completed if len(self.invocations) == 2 else subprocess.CompletedProcess(command, 7, "", "bad source")
        self.compiler.side_effect = compile_some
        report = try_match.run_trials(self.args("--profiles", "source,no-peephole"))
        self.assertEqual([trial["status"] for trial in report["trials"]], ["compile-failure", "compared"])
        self.assertEqual(report["trials"][0]["diagnostics"], "bad source")
        self.assertEqual(report["trials"][0]["functions"], [])
        self.assertEqual(self.comparer.call_count, 1)
        self.assert_clean()

    def test_timeout_and_launch_errors_are_reported(self):
        for failure in (subprocess.TimeoutExpired(["compiler"], 1, output=b"partial", stderr=b"error"),
                        FileNotFoundError("missing compiler")):
            with self.subTest(failure=failure):
                self.compiler.side_effect = failure
                report = try_match.run_trials(self.args("--timeout", "1"))
                self.assertEqual(report["trials"][0]["status"], "compile-failure")
                self.assertIn("error", report["trials"][0])
                self.comparer.assert_not_called()
                self.assert_clean()

    def test_timeout_removes_partial_outputs(self):
        def compile_timeout(command, **kwargs):
            self.compile_ok(command, **kwargs)
            raise subprocess.TimeoutExpired(command, 1, output=b"partial output")
        self.compiler.side_effect = compile_timeout
        report = try_match.run_trials(self.args("--timeout", "1"))
        self.assertEqual(report["trials"][0]["status"], "compile-failure")
        self.assertEqual(report["trials"][0]["diagnostics"], "partial output")
        self.comparer.assert_not_called()
        self.assert_clean()

    def test_missing_object_is_not_success(self):
        self.compiler.side_effect = lambda command, **kwargs: subprocess.CompletedProcess(command, 0, "", "")
        report = try_match.run_trials(self.args())
        self.assertIn("produced no object", report["trials"][0]["error"])
        self.comparer.assert_not_called()
        self.assert_clean()

    def test_actual_checker_diagnostics_are_not_reinterpreted(self):
        self.comparer.return_value = (
            [("exact_fn", 0x100000, "MATCH"), ("different", 0x100010, "DIFF at 0x0,0x4(call target) (+9)"),
             ("unknown", None, "unknown address")], ["external: unknown symbol"])
        report = try_match.run_trials(self.args())
        functions = report["trials"][0]["functions"]
        self.assertEqual([function["status"] for function in functions], ["exact", "near", "unresolved"])
        self.assertEqual(functions[1]["result"], "DIFF at 0x0,0x4(call target) (+9)")
        self.assertNotIn("mismatch_count", functions[1])
        self.assertEqual(report["trials"][0]["undefined"], ["external: unknown symbol"])
        self.assertFalse(report["whole_build_verified"])
        self.assertGreaterEqual(report["trials"][0]["compile_seconds"], 0)
        self.assertGreaterEqual(report["trials"][0]["compare_seconds"], 0)
        self.assert_clean()

    def test_real_relocation_aware_checker_exact_and_different_call_target(self):
        def compile_elf(command, **kwargs):
            completed = self.compile_ok(command, **kwargs)
            Path(command[command.index("-o") + 1]).write_bytes(call_object())
            return completed
        self.compiler.side_effect = compile_elf
        self.comparer.side_effect = COMPARE
        target = 0x100020
        self.symbols.write_text(json.dumps({"names": {"example": 0x100000, "target": target},
                                            "starts": [0x100000, 0x100008]}))
        for address, expected in ((target, "MATCH"), (target + 4, "DIFF at 0x0(call target)")):
            with self.subTest(address=address):
                self.rom.write_bytes(struct.pack("<II", 0x0C000000 | (address >> 2), 0) + bytes(56))
                report = try_match.run_trials(self.args())
                function = report["trials"][0]["functions"][0]
                self.assertEqual(function["result"], expected)
                self.assertEqual(function["status"], "exact" if expected == "MATCH" else "near")
                self.assert_clean()

    def test_expected_comparison_errors_are_reported_and_cleaned(self):
        for error in (ELFError("invalid object"), struct.error("reference too short")):
            with self.subTest(error=error):
                self.comparer.side_effect = error
                report = try_match.run_trials(self.args())
                self.assertEqual(report["trials"][0]["status"], "compare-failure")
                self.assertIn(str(error), report["trials"][0]["error"])
                self.assert_clean()

    def test_unexpected_error_and_interruption_clean_everything(self):
        for error in (RuntimeError("unexpected"), KeyboardInterrupt()):
            with self.subTest(error=error):
                self.comparer.side_effect = [([("example", 0x100000, "MATCH")], []), error]
                with self.assertRaises(type(error)):
                    try_match.run_trials(self.args("--profiles", "source,no-peephole", "--keep", "all"))
                self.assert_clean()

    def test_source_change_is_detected_but_not_overwritten(self):
        changed = b"/* edit made outside the runner */\n"
        def compile_edit(command, **kwargs):
            self.source.write_bytes(changed)
            return self.compile_ok(command, **kwargs)
        self.compiler.side_effect = compile_edit
        with self.assertRaisesRegex(ValueError, "source changed"):
            try_match.run_trials(self.args("--keep", "all"))
        self.assertEqual(self.source.read_bytes(), changed)
        self.assertEqual(list((self.root / "build").iterdir()), [])

    def test_selected_retention_excludes_failed_and_nonexact_objects(self):
        self.comparer.side_effect = [
            ([("example", 0x100000, "DIFF at 0x0")], []),
            ([("example", 0x100000, "MATCH")], []),
        ]
        report = try_match.run_trials(self.args("--profiles", "source,no-peephole", "--keep", "exact"))
        retained = Path(report["retained_directory"])
        self.assertEqual({path.name for path in retained.iterdir()}, {"report.json", "02-mw-no-peephole"})
        self.assertEqual({path.name for path in (retained / "02-mw-no-peephole").iterdir()},
                         {"candidate.o", "prefix.c"})
        self.assertEqual(json.loads((retained / "report.json").read_text()), report)
        self.assertEqual(self.source.read_bytes(), self.original)

    def test_keep_all_retains_near_but_not_failed_outputs(self):
        self.comparer.return_value = ([("example", 0x100000, "DIFF at 0x0")], [])
        report = try_match.run_trials(self.args("--keep", "all"))
        self.assertTrue(Path(report["trials"][0]["retained_object"]).is_file())
        def compile_bad(command, **kwargs):
            self.compile_ok(command, **kwargs)
            return subprocess.CompletedProcess(command, 1, "", "failure")
        self.compiler.side_effect = compile_bad
        failed = try_match.run_trials(self.args("--keep", "all"))
        retained = Path(failed["retained_directory"])
        self.assertEqual([path.name for path in retained.iterdir()], ["report.json"])

    def test_read_only_reference_cache_validation(self):
        for value in ([], {}, {"names": [], "starts": []}, {"names": {"x": True}, "starts": []},
                      {"names": {}, "starts": ["100000"]}, {"names": {}, "starts": [-1]}):
            with self.subTest(value=value):
                self.symbols.write_text(json.dumps(value))
                before = self.symbols.read_bytes()
                with self.assertRaises(ValueError):
                    try_match.run_trials(self.args())
                self.assertEqual(self.symbols.read_bytes(), before)
        self.compiler.assert_not_called()
        self.symbol_loader.assert_not_called()

    def test_json_exit_status_and_no_functions_are_not_exact(self):
        with contextlib.redirect_stdout(io.StringIO()) as stdout:
            status = try_match.main([str(self.source), "--rom", str(self.rom),
                                     "--symbols", str(self.symbols), "--json"])
        report = json.loads(stdout.getvalue())
        self.assertEqual(status, 0)
        self.assertEqual(report["trials"][0]["functions"][0]["result"], "MATCH")
        self.compiler.side_effect = FileNotFoundError("compiler")
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(try_match.main([str(self.source), "--rom", str(self.rom),
                                            "--symbols", str(self.symbols), "--json"]), 1)
        self.compiler.side_effect = self.compile_ok
        self.comparer.return_value = ([], [])
        report = try_match.run_trials(self.args("--keep", "exact"))
        self.assertNotIn("retained_object", report["trials"][0])
        with contextlib.redirect_stdout(io.StringIO()) as stdout:
            try_match.print_report(report)
        self.assertIn("No comparable functions; not an exact candidate.", stdout.getvalue())


if __name__ == "__main__":
    unittest.main()
