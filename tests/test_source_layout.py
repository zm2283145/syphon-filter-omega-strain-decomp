"""Units in the original source layout (docs/merge_units.md): integrate_pending
places new functions, merge_units groups and names units per original file."""
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import integrate_pending as ip  # noqa: E402
sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
import configure  # noqa: E402
import merge_units as mu  # noqa: E402

SOURCES = {"SFOGame/Source/game", "Libs/SFOLib/Source/mem", "SFOGame/Source/AIMsgs"}


class TuRangesTests(unittest.TestCase):
    def test_paths_and_bare_names(self):
        with tempfile.TemporaryDirectory() as d:
            (Path(d) / "config").mkdir()
            (Path(d) / "config" / "tu_ranges.txt").write_text(
                "# comment\n0x00102A90 0x00102B40 libgraph.c?\n"
                "0x0012ECD0 0x00138AB0 SFOGame/Source/game.cc\n")
            self.assertEqual(ip.load_tu_ranges(d), [(0x102A90, 0x102B40, "libgraph"),
                                                    (0x12ECD0, 0x138AB0, "SFOGame/Source/game")])
            self.assertEqual(ip.source_modules(d), {"SFOGame/Source/game"})


class UnitPathTests(unittest.TestCase):
    def test_original_source_file(self):
        self.assertEqual(ip.unit_path("SFOGame/Source/game", 0x130000, True),
                         "SFOGame/Source/game/func_00130000")

    def test_gcc_function_in_an_original_file_stays_in_lib(self):
        self.assertEqual(ip.unit_path("SFOGame/Source/game", 0x130000, False), "lib/func_00130000")

    def test_older_scheme(self):
        self.assertEqual(ip.unit_path("libgraph", 0x102A90, False), "lib/libgraph/func_00102A90")
        self.assertEqual(ip.unit_path(None, 0x102A90, True), "main/func_00102A90")

    def test_compiler_family_by_path(self):
        self.assertTrue(ip.is_gcc_unit("lib/lgaud/func_00324680"))
        self.assertFalse(ip.is_gcc_unit("SFOGame/Source/game"))
        self.assertFalse(ip.is_gcc_unit("main/func_00100218"))


class ModuleTests(unittest.TestCase):
    def setUp(self):
        self.saved = mu._SOURCES
        mu._SOURCES = SOURCES

    def tearDown(self):
        mu._SOURCES = self.saved

    def test_original_source_units(self):
        for name in ("SFOGame/Source/game/func_00130000", "SFOGame/Source/game/game_131000",
                     "SFOGame/Source/game", "SFOGame/Source/game_2", "SFOGame/Source/game_12"):
            self.assertEqual(mu.module_of(name), "SFOGame/Source/game", name)

    def test_unknown_original_paths_are_not_merged(self):
        self.assertIsNone(mu.module_of("SFOGame/Source/other"))
        self.assertIsNone(mu.module_of("SFOGame/Source/other/func_00130000"))

    def test_older_scheme(self):
        self.assertEqual(mu.module_of("main/aiMsgs/aiMsgs"), "main/aiMsgs")
        self.assertEqual(mu.module_of("lib/lgaud/func_00324680"), "lib/lgaud")
        self.assertIsNone(mu.module_of("main/func_00100218"))
        self.assertIsNone(mu.module_of("main/sinit/func_00480000"))
        self.assertIsNone(mu.module_of("data/d_00480000"))

    def test_unit_kind_defaults(self):
        self.assertEqual(mu.unit_kind("SFOGame/Source/game", {}), "mw")
        self.assertEqual(mu.unit_kind("lib/lgaud/func_00324680", {}), "gcc")
        self.assertEqual(mu.unit_kind("SFOGame/Source/game", {"SFOGame/Source/game": "cwps2-3.0b38"}), "mw38")

    def test_files_dir(self):
        self.assertEqual(mu.files_dir("SFOGame/Source/game"), mu.ROOT / "src" / "SFOGame" / "Source")
        self.assertEqual(mu.files_dir("main/aiMsgs"), mu.ROOT / "src" / "main" / "aiMsgs")

    def test_group_names(self):
        segs = [[0x100, "c", "SFOGame/Source/game/func_00100100", []],
                [0x110, "c", "SFOGame/Source/game/func_00100110", []],
                [0x120, "asm", None, []],
                [0x130, "c", "SFOGame/Source/game/func_00100130", []],
                [0x140, "c", "SFOGame/Source/game/func_00100140", []],
                [0x150, "c", "SFOGame/Source/game_2", []]]
        g1, g2 = ["mw", [0, 1], [], None, False], ["mw", [3, 4], [], None, False]
        names = mu.name_groups("SFOGame/Source/game", [g1, g2], segs)
        # game_2 is taken by a unit that is not regrouped
        self.assertEqual([names[id(g1)], names[id(g2)]], ["SFOGame/Source/game", "SFOGame/Source/game_3"])

    def test_group_names_older_scheme(self):
        segs = [[0x100, "c", "main/zzNoSuchModule/func_00100100", []], [0x110, "c", "main/zzNoSuchModule/func_00100110", []]]
        g = ["mw", [0, 1], [], None, False]
        self.assertEqual(mu.name_groups("main/zzNoSuchModule", [g], segs)[id(g)], "main/zzNoSuchModule/zzNoSuchModule")

    def test_runs_split_at_file_boundaries(self):
        segs = [[0x100, "c", "SFOGame/Source/game/func_00100100", []],
                [0x110, "c", "SFOGame/Source/game_2", []],
                [0x120, "c", "SFOGame/Source/AIMsgs", []],
                [0x130, "c", "SFOGame/Source/AIMsgs/func_00100130", []]]
        self.assertEqual(mu.runs(segs), [("SFOGame/Source/game", [0, 1]), ("SFOGame/Source/AIMsgs", [2, 3])])


class ReadChunksTests(unittest.TestCase):
    def test_preamble_goes_to_the_first_block(self):
        text = ("/*\n * x: range (2 files)\n * One translation unit merged from per-function files by "
                "tools/merge_units.py\n */\n\n/* headers shared by the blocks below */\n#include \"types.h\"\n\n"
                "/* merge_units: begin func_00100000 */\n#pragma push /* merge_units */\nint a(void) { return 0; }\n"
                "#pragma pop /* merge_units */\n/* merge_units: end func_00100000 */\n"
                "/* merge_units: begin func_00100010 */\nint b(void) { return 1; }\n"
                "/* merge_units: end func_00100010 */\n")
        with tempfile.TemporaryDirectory() as d:
            p = Path(d) / "x.c"
            p.write_text(text)
            a, b = mu.read_chunks(p, "mw")
        self.assertEqual((a.label, b.label), ("func_00100000", "func_00100010"))
        self.assertEqual(a.text, '#include "types.h"\n\nint a(void) { return 0; }\n')
        self.assertEqual(b.text, "int b(void) { return 1; }\n")

    def test_flush_stub_added_once(self):
        c = mu.Chunk("func_00100000", "int a(void) { return 0; }\n", "mw", False)
        t = mu.synthesize([c], mu.ROOT / "include", True, "t")
        self.assertEqual(t.count("merge_flush_func_00100000"), 1)
        self.assertIn(mu.TAG, t.split("merge_flush_func_00100000")[1].split("\n")[0])

    def test_first_error(self):
        err = ("### mwccps2.exe Compiler:\n#     169: x = f();\n#   Error:     ^\n#   illegal explicit conversion"
               " from 'void' to\n#   'int'\n### mwccps2.exe Compiler:\n#     170: y\n#   Error: ^\n#   later\n")
        self.assertEqual(mu.first_error(err), "illegal explicit conversion from 'void' to 'int' | at: 169: x = f();")


class CategoryTests(unittest.TestCase):
    RANGES = [(0x102A90, 0x102B40, "libgraph.c?"), (0x12ECD0, 0x13905C, "SFOGame/Source/game.cc"),
              (0x442000, 0x443000, "Libs/SFOLobby/SFOLobby/SFOLobby_Mission.cc")]

    def test_by_path(self):
        self.assertEqual(configure.categories("SFOGame/Source/game", 0, []), ["main", "game"])
        self.assertEqual(configure.categories("Libs/SFOLib/Source/mem/func_00100000", 0, []), ["main", "libs"])
        self.assertEqual(configure.categories("lib/lgaud/func_00324680", 0, []), ["main", "sdk"])

    def test_by_address(self):
        self.assertEqual(configure.categories(None, 0x130000, self.RANGES), ["main", "game"])
        self.assertEqual(configure.categories("main/func_00442100", 0x442100, self.RANGES), ["main", "libs"])
        self.assertEqual(configure.categories(None, 0x102AA0, self.RANGES), ["main", "sdk"])
        self.assertEqual(configure.categories("main/sinit/func_004D8C10", 0x4D8C10, self.RANGES), ["main"])


if __name__ == "__main__":
    unittest.main()
