import contextlib
import copy
import io
import json
from pathlib import Path
import tempfile
import unittest

import yaml

from tools import rank_candidates as rank


BASE = 0x400000


def config(subs=None, end=0x60):
    return {"segments": [{"type": "code", "start": 0, "vram": BASE,
                          "subsegments": subs or [[0, "asm"], [0x40, "data"]]}, [end]]}


def unit(name, size, functions, complete=False):
    total = sum(length for _, _, length in functions)
    return {"name": name, "sections": [{"name": ".text", "size": str(size)}],
            "functions": [{"name": name, "address": str(offset), "size": str(length)}
                          for name, offset, length in functions],
            "metadata": {"complete": complete},
            "measures": {"total_code": str(total), "complete_code": str(total if complete else 0)}}


def report(*units):
    return {"units": list(units)}


class CandidateRankingTests(unittest.TestCase):
    def setUp(self):
        # Even synthetic assembly stays in the ignored build directory.
        directory = rank.ROOT / "build"
        directory.mkdir(exist_ok=True)
        self.temp = tempfile.TemporaryDirectory(dir=directory)
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def assembly(self, name, start, instructions, label=None, label_at=2):
        lines = ["glabel " + name]
        for i, text in enumerate(instructions):
            if label and i == label_at:
                lines.append(label + ":")
            lines.append(f"/* {i * 4:06X} {start + i * 4:08X} 00000000 */ {text}")
        lines.append("endlabel " + name)
        (self.root / (name + ".s")).write_text("\n".join(lines), encoding="utf-8")

    def test_c_span_owns_multiple_functions_without_source_files(self):
        cfg = config([[0, "c", "main/container"], [0x20, "asm"], [0x40, "data"]])
        rep = report(unit("main/container", 0x20, [("renamed", 0, 12), ("secondary", 16, 16)], True),
                     unit("asm/400020", 0x20, [("pending", 0, 20)]))
        result = rank.rank_candidates(cfg, rep)
        self.assertEqual([r["name"] for r in result["candidates"]], ["pending"])
        self.assertEqual(result["summary"]["function_counts"]["owned_c_complete"], 2)
        self.assertEqual(result["summary"]["potential_gain_bytes"], 20)
        self.assertTrue(result["summary"]["inventory_complete"])

    def test_unverified_c_and_stale_asm_inventory_remain_reserved(self):
        cfg = config([[0, "asm"], [0x10, "c", "main/new"], [0x30, "asm"], [0x40, "data"]])
        rep = report(unit("asm/400000", 0x40, [("first", 0, 8), ("new", 16, 8),
                                             ("secondary", 32, 8), ("last", 48, 8)]))
        result = rank.rank_candidates(cfg, rep)
        self.assertEqual([r["name"] for r in result["candidates"]], ["first", "last"])
        self.assertEqual(result["summary"]["function_counts"]["owned_c_unverified"], 2)

    def test_c_metadata_without_complete_bytes_is_unverified(self):
        cfg = config([[0, "c", "main/partial"], [32, "asm"], [64, "data"]])
        owned = unit("main/partial", 32, [("first", 0, 8), ("second", 16, 8)], True)
        owned["measures"]["complete_code"] = "8"
        result = rank.rank_candidates(cfg, report(owned, unit("asm/400020", 32, [("next", 0, 8)])))
        self.assertEqual(result["summary"]["function_counts"]["owned_c_unverified"], 2)
        self.assertEqual([r["name"] for r in result["candidates"]], ["next"])

    def test_complete_report_without_c_owner_is_not_offered(self):
        result = rank.rank_candidates(config(), report(unit("asm/400000", 0x40, [("f", 0, 16)], True)))
        self.assertEqual(result["candidates"], [])
        self.assertFalse(result["summary"]["inventory_complete"])
        self.assertTrue(any("disagrees" in s for s in result["warnings"]))

    def test_half_open_range_excludes_crossing_functions(self):
        rep = report(unit("asm/400000", 0x40, [("a", 0, 16), ("b", 16, 16), ("c", 32, 16)]))
        result = rank.rank_candidates(config(), rep, BASE + 8, BASE + 32)
        self.assertEqual([r["name"] for r in result["candidates"]], ["b"])
        self.assertEqual(result["summary"]["function_bytes"]["range_boundary"], 8)
        self.assertEqual(result["summary"]["configured_code_span_bytes"], 24)
        result = rank.rank_candidates(config(), rep, BASE, BASE + 40)
        self.assertEqual([r["name"] for r in result["candidates"]], ["a", "b"])

    def test_function_crossing_owner_boundary_is_not_offered(self):
        cfg = config([[0, "asm"], [0x10, "c", "main/new"], [0x40, "data"]])
        result = rank.rank_candidates(cfg, report(unit("asm/400000", 0x40, [("crosses", 0, 32)])))
        self.assertEqual(result["candidates"], [])
        self.assertFalse(result["summary"]["inventory_complete"])
        self.assertEqual(result["summary"]["function_bytes"]["ownership_boundary"], 32)

    def test_sizes_exclude_padding_and_last_function_stops_at_section(self):
        rep = report(unit("asm/400000", 0x40, [("small", 0, 8), ("large", 16, 20), ("last", 48, 8)]))
        result = rank.rank_candidates(config(), rep)
        self.assertEqual([r["name"] for r in result["candidates"]], ["large", "small", "last"])
        self.assertEqual(result["summary"]["potential_gain_bytes"], 36)
        self.assertEqual(result["summary"]["covered_non_function_bytes"], 28)
        self.assertEqual([r["following_gap_bytes"] for r in result["candidates"]], [12, 8, 8])

    def test_missing_report_coverage_is_explicit(self):
        result = rank.rank_candidates(config(), report(unit("asm/400000", 16, [("f", 0, 8)])))
        self.assertFalse(result["summary"]["inventory_complete"])
        self.assertEqual(result["summary"]["missing_report_span_bytes"], 48)

    def test_range_outside_code_is_not_a_complete_inventory(self):
        result = rank.rank_candidates(config(), report(), BASE + 64, BASE + 96)
        self.assertEqual(result["candidates"], [])
        self.assertFalse(result["summary"]["inventory_complete"])
        self.assertEqual(result["summary"]["configured_code_span_bytes"], 0)

    def test_unmapped_units_do_not_fall_back_to_function_names(self):
        result = rank.rank_candidates(config(), report(unit("main/removed", 16, [("func_00400000", 0, 8)])))
        self.assertEqual(result["unmapped_report_units"], ["main/removed"])
        self.assertEqual(result["candidates"], [])
        self.assertFalse(result["summary"]["inventory_complete"])

    def test_data_is_excluded_and_segment_translation_uses_start(self):
        cfg = {"segments": [{"type": "code", "start": 0x100, "vram": BASE,
                             "subsegments": [[0x100, "asm"], [0x120, "data"],
                                             {"start": 0x140, "type": "asm", "name": "island"}]},
                            [0x160]]}
        rep = report(unit("asm/400000", 0x20, [("code", 0, 12)]),
                     unit("data/400020", 0, []),
                     unit("asm/400040", 0x20, [("island", 0, 16)]))
        result = rank.rank_candidates(cfg, rep)
        self.assertEqual(result["summary"]["configured_code_span_bytes"], 64)
        self.assertEqual(result["summary"]["potential_gain_bytes"], 28)
        self.assertTrue(result["summary"]["inventory_complete"])

    def test_groups_preserve_constants_registers_calls_and_relocations(self):
        variants = [
            ["lw $v0, 4($a0)", "jal target_one", "lui $a1, %hi(global_one)", "nop"],
            ["lw $v0, 4($a0)", "jal target_one", "lui $a1, %hi(global_one)", "nop"],
            ["lw $v0, 8($a0)", "jal target_one", "lui $a1, %hi(global_one)", "nop"],
            ["lw $v0, 4($a1)", "jal target_one", "lui $a1, %hi(global_one)", "nop"],
            ["lw $v0, 4($a0)", "jal target_two", "lui $a1, %hi(global_one)", "nop"],
            ["lw $v0, 4($a0)", "jal target_one", "lui $a1, %hi(global_two)", "nop"],
            ["lw $v0, 4($a0)", "jal target_one", "lui $a1, %lo(global_one)", "nop"],
            ["lw $v0, 4($a0)", "jal target_one", "lui $a1, %hi(global_one+4)", "nop"],
        ]
        funcs = []
        for i, instructions in enumerate(variants):
            self.assembly(f"f{i}", BASE + i * 16, instructions)
            funcs.append((f"f{i}", i * 16, 16))
        result = rank.rank_candidates(config([[0, "asm"], [128, "data"]], 144),
                                      report(unit("asm/400000", 128, funcs)), asm_root=self.root)
        self.assertEqual(len(result["families"]), 1)
        self.assertEqual(result["families"][0]["members"], ["0x00400000", "0x00400010"])
        self.assertEqual(result["families"][0]["potential_gain_bytes"], 32)
        self.assertTrue(result["families"][0]["heuristic"])
        serialized = json.dumps(result)
        for operand in ("target_one", "global_one", "lw $v0"):
            self.assertNotIn(operand, serialized)

    def test_local_labels_normalized_but_branch_destinations_distinct(self):
        funcs = []
        for i in range(3):
            label_at = 3 if i == 2 else 2
            label = f".L{BASE + 16 * i + 4 * label_at:08X}"
            instructions = [f"beqz $a0, {label}", "nop", "jr $ra", "nop"]
            self.assembly(f"f{i}", BASE + 16 * i, instructions, label, label_at)
            funcs.append((f"f{i}", 16 * i, 16))
        result = rank.rank_candidates(config(), report(unit("asm/400000", 64, funcs)), asm_root=self.root)
        self.assertEqual(result["families"][0]["candidate_count"], 2)
        self.assertEqual(result["summary"]["signature_available_functions"], 3)

    def test_family_bytes_take_priority_over_individual_size(self):
        funcs = [("single", 0, 20), ("pair1", 24, 16), ("pair2", 40, 16)]
        self.assembly("single", BASE, ["nop"] * 5)
        for name, offset, _ in funcs[1:]:
            self.assembly(name, BASE + offset, ["nop"] * 4)
        result = rank.rank_candidates(config(), report(unit("asm/400000", 64, funcs)), asm_root=self.root)
        self.assertEqual([r["name"] for r in result["candidates"]], ["pair1", "pair2", "single"])

    def test_missing_assembly_never_creates_partial_signature(self):
        self.assembly("partial", BASE, ["nop"])
        result = rank.rank_candidates(config(), report(unit("asm/400000", 64, [("f", 0, 8)])),
                                      asm_root=self.root)
        self.assertEqual(result["summary"]["signature_available_functions"], 0)
        self.assertEqual(result["families"], [])
        self.assertTrue(any("sequence" in s for s in result["warnings"]))

    def test_conflicting_assembly_is_an_error(self):
        self.assembly("a", BASE, ["nop", "jr $ra"])
        self.assembly("b", BASE, ["nop", "jr $v0"])
        with self.assertRaisesRegex(ValueError, "conflicting assembly"):
            rank.rank_candidates(config(), report(unit("asm/400000", 64, [("f", 0, 8)])),
                                 asm_root=self.root)

    def test_research_entry_and_interior_citations_count_candidate_once(self):
        index = self.root / "ADDRESS_INDEX.md"
        index.write_text("| `00400000` | image | [A](A.md) | start |\n"
                         "| `00400004` | image | [A](A.md), [B](B.md) | interior |\n"
                         "| `00400010` | image | [A](A.md) | padding |\n"
                         "| `00400040` | image | [OUT](OUT.md) | outside |\n", encoding="utf-8")
        result = rank.rank_candidates(config(), report(unit("asm/400000", 64, [("f", 0, 8)])),
                                      research_index=index)
        self.assertEqual(result["summary"]["research_candidate_bytes"], 8)
        self.assertEqual([r["potential_gain_bytes"] for r in result["research_groups"]], [8, 8])
        self.assertEqual([r["location"] for r in result["candidates"][0]["research"]],
                         ["entry", "interior", "interior"])
        self.assertNotIn("OUT.md", json.dumps(result))

    def test_invalid_order_ranges_report_overlap_and_sizes_fail(self):
        with self.assertRaisesRegex(ValueError, "ordered"):
            rank.config_spans(config([[0, "asm"], [32, "c", "x"], [16, "data"]]))
        rep = report(unit("asm/400000", 64, [("a", 0, 12), ("b", 8, 8)]))
        with self.assertRaisesRegex(ValueError, "overlapping"):
            rank.rank_candidates(config(), rep)
        with self.assertRaisesRegex(ValueError, "--start"):
            rank.rank_candidates(config(), report(), BASE, BASE)
        bad = unit("asm/400000", 64, [("f", 0, 8)])
        bad["measures"]["total_code"] = "12"
        with self.assertRaisesRegex(ValueError, "total_code"):
            rank.rank_candidates(config(), report(bad))

    def test_deterministic_output_independent_of_report_order_and_limit(self):
        cfg = config([[0, "asm"], [32, "asm"], [64, "data"]])
        rep = report(unit("asm/400000", 32, [("b", 16, 8), ("a", 0, 8)]),
                     unit("asm/400020", 32, [("c", 0, 8)]))
        expected = rank.rank_candidates(cfg, rep)
        shuffled = copy.deepcopy(rep)
        shuffled["units"].reverse()
        self.assertEqual(expected, rank.rank_candidates(cfg, shuffled))
        self.assertIn("Showing 1/3", rank.human_output(expected, 1))
        cfg_path, rep_path = self.root / "splat.yaml", self.root / "report.json"
        cfg_path.write_text(yaml.safe_dump(cfg), encoding="utf-8")
        rep_path.write_text(json.dumps(rep), encoding="utf-8")
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            self.assertEqual(rank.main(["--config", str(cfg_path), "--report", str(rep_path),
                                        "--input-root", str(self.root), "--json", "--limit", "1"]), 0)
        self.assertEqual(json.loads(output.getvalue()), expected)
        self.assertNotIn(str(self.root), output.getvalue())

    def test_cli_explicit_missing_inputs_fail_without_json_success(self):
        with contextlib.redirect_stderr(io.StringIO()), contextlib.redirect_stdout(io.StringIO()):
            with self.assertRaises(SystemExit) as error:
                rank.main(["--report", str(self.root / "missing.json")])
        self.assertEqual(error.exception.code, 2)

    def test_input_root_defaults_and_explicit_missing_asm(self):
        config_dir, report_dir = self.root / "config", self.root / "progress"
        config_dir.mkdir()
        report_dir.mkdir()
        (config_dir / "splat.yaml").write_text(yaml.safe_dump(config()), encoding="utf-8")
        (report_dir / "report.json").write_text(
            json.dumps(report(unit("asm/400000", 64, [("f", 0, 8)]))), encoding="utf-8")
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            rank.main(["--input-root", str(self.root), "--json"])
        self.assertEqual(json.loads(output.getvalue())["summary"]["potential_gain_bytes"], 8)
        with contextlib.redirect_stderr(io.StringIO()), contextlib.redirect_stdout(io.StringIO()):
            with self.assertRaises(SystemExit) as error:
                rank.main(["--input-root", str(self.root), "--asm-root", str(self.root / "missing")])
        self.assertEqual(error.exception.code, 2)


if __name__ == "__main__":
    unittest.main()
