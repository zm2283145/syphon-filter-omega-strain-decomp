"""Synthetic DWARF1 array fixtures; no game or prototype data."""
import struct
import unittest

from tools.proto import dwarf1


def bounds(lo, hi):
    return b'\0' + struct.pack('<Hii', 0x0a, lo, hi)


def element_ref(offset):
    return b'\x08' + struct.pack('<HI', 0x0072, offset)


def element_fund(type_code):
    return b'\x08' + struct.pack('<HH', 0x0055, type_code)


class TestArrayTypes(unittest.TestCase):
    def setUp(self):
        self.dw = dwarf1.Dwarf1(b'')

    def array(self, offset, dimensions, element, **attrs):
        die = dwarf1.Die(offset, 0x01, dict(
            subscr_data=b''.join(bounds(lo, hi) for lo, hi in dimensions) + element,
            **attrs))
        self.dw.by_off[offset] = die
        return die

    def test_one_dimension_retains_extent(self):
        die = self.array(0x100, [(0, 6)], element_fund(14))
        self.assertEqual(self.dw.array_info(die), ('float', ['7']))
        self.assertEqual(self.dw.udt_name(0x100), 'float[7]')

    def test_nested_dimensions_are_outermost_first(self):
        self.array(0x200, [(0, 3)], element_fund(14))
        outer = self.array(0x100, [(0, 2)], element_ref(0x200))
        self.assertEqual(self.dw.array_info(outer), ('float', ['3', '4']))
        member = dwarf1.Die(0x300, 0x0d, {'user_def_type': 0x100})
        self.assertEqual(self.dw.type_of(member), 'float[3][4]')

    def test_nested_class_elements(self):
        self.dw.by_off[0x300] = dwarf1.Die(0x300, 0x02, {'name': 'Part'})
        self.array(0x200, [(0, 31)], element_ref(0x300))
        self.array(0x100, [(0, 1)], element_ref(0x200))
        self.assertEqual(self.dw.udt_name(0x100), 'Part[2][32]')

    def test_multiple_bounds_in_one_record(self):
        die = self.array(0x100, [(1, 3), (-2, 1)], element_fund(7))
        self.assertEqual(self.dw.array_info(die), ('int', ['3', '4']))

    def test_mixed_flat_and_nested_records(self):
        self.array(0x200, [(0, 4)], element_fund(7))
        outer = self.array(0x100, [(0, 1), (0, 2)], element_ref(0x200))
        self.assertEqual(self.dw.array_info(outer), ('int', ['2', '3', '5']))

    def test_three_nested_records(self):
        self.array(0x300, [(0, 4)], element_fund(14))
        self.array(0x200, [(0, 3)], element_ref(0x300))
        self.array(0x100, [(0, 2)], element_ref(0x200))
        self.assertEqual(self.dw.udt_name(0x100), 'float[3][4][5]')

    def test_named_array_element_retains_its_name(self):
        self.array(0x200, [(0, 3)], element_fund(14), name='Row')
        self.array(0x100, [(0, 2)], element_ref(0x200))
        self.assertEqual(self.dw.udt_name(0x100), 'Row[3]')

    def test_pointer_element_is_not_flattened(self):
        self.dw.by_off[0x200] = dwarf1.Die(0x200, 0x0f, {'fund_type': 14})
        outer = self.array(0x100, [(0, 2)], element_ref(0x200))
        self.assertEqual(self.dw.array_info(outer), ('float*', ['3']))

    def test_unknown_element_remains_visible(self):
        self.array(0x100, [(0, 2)], element_ref(0x999))
        self.assertEqual(self.dw.udt_name(0x100), 'type@999[3]')

    def test_cyclic_array_is_depth_limited(self):
        outer = self.array(0x100, [(0, 2)], element_ref(0x100))
        el, dims = self.dw.array_info(outer)
        self.assertEqual(el, '?')
        self.assertLessEqual(len(dims), 8)


if __name__ == '__main__':
    unittest.main()
