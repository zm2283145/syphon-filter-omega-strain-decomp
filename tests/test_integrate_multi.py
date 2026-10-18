"""integrate_pending sizes a new C unit from all of the object's code."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import integrate_pending  # noqa: E402


class Sec(dict):
    def __init__(self, name, size, align):
        super().__init__(sh_size=size, sh_addralign=align)
        self.name = name


class Obj:
    def __init__(self, *secs):
        self.secs = secs

    def iter_sections(self):
        return iter(self.secs)


class ObjectTextEndTests(unittest.TestCase):
    def test_one_function(self):
        self.assertEqual(integrate_pending.object_text_end(Obj(Sec(".text", 0x5A8, 16))), 0x5A8)

    def test_functions_in_separate_sections_are_laid_out_aligned(self):
        # CodeWarrior emits one .text section per function; the linker aligns each one.
        obj = Obj(Sec(".text", 0x62C, 16), Sec(".data", 0x40, 16), Sec(".text", 0x60C, 16))
        self.assertEqual(integrate_pending.object_text_end(obj), 0x630 + 0x60C)

    def test_other_sections_are_ignored(self):
        obj = Obj(Sec(".rodata", 0x100, 16), Sec(".text", 0x300, 8), Sec(".dtors_drop", 8, 4))
        self.assertEqual(integrate_pending.object_text_end(obj), 0x300)


if __name__ == "__main__":
    unittest.main()
