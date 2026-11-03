"""Synthetic MW DWARF1 enum fixtures; no prototype or retail bytes."""
import contextlib
import io
from pathlib import Path
import struct
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

from tools.proto import dwarf1
from tools.proto import extract_proto


def elements(width, entries):
    return b''.join((value % (1 << (8 * width))).to_bytes(width, 'little')
                    + name.encode('latin-1') + b'\0' for name, value in entries)


def enum_die(width, entries, name='Synthetic'):
    return dwarf1.Die(0x123, 0x04, {'byte_size': width, 'name': name,
                                   'element_list': elements(width, entries)})


def enum_record(name, width, entries):
    data = elements(width, entries)
    attrs = (struct.pack('<H', 0x0038) + name.encode('ascii') + b'\0'
             + struct.pack('<HH', 0x00B5, width)
             + struct.pack('<HH', 0x00F3, len(data)) + data)
    return struct.pack('<IH', 6 + len(attrs), 0x04) + attrs


def synthetic_debug():
    children = (enum_record('Synthetic8', 1, [('absent', -1), ('high', 128), ('second', 7)])
                + enum_record('Synthetic16', 2, [('low', 0x1234), ('negative', -2)])
                + enum_record('Synthetic32', 4, [('wide', 0x12345678), ('negative', -3)]))
    name = struct.pack('<H', 0x0038) + b'synthetic.cc\0'
    length = 6 + len(name) + 6
    attrs = name + struct.pack('<HI', 0x0011, length + len(children))
    return struct.pack('<IH', length, 0x11) + attrs + children


class TestEnumValues(unittest.TestCase):
    def test_byte_values_do_not_consume_name_prefix(self):
        entries = [('missing', -1), ('zero', 0), ('last', 21)]
        self.assertEqual(dwarf1.enum_values(enum_die(1, entries)), entries)

    def test_two_byte_little_endian_signed_values(self):
        entries = [('wide', 0x1234), ('negative', -2)]
        self.assertEqual(dwarf1.enum_values(enum_die(2, entries)), entries)

    def test_four_byte_legacy_values(self):
        entries = [('wide', 0x12345678), ('negative', -3)]
        self.assertEqual(dwarf1.enum_values(enum_die(4, entries)), entries)

    def test_eight_byte_values(self):
        entries = [('wide', 0x0102030405060708), ('negative', -0x100000002)]
        self.assertEqual(dwarf1.enum_values(enum_die(8, entries)), entries)

    def test_explicit_unsigned_interpretation(self):
        for width in (1, 2, 4, 8):
            with self.subTest(width=width):
                value = (1 << (8 * width)) - 1
                die = enum_die(width, [('high', value)])
                self.assertEqual(dwarf1.enum_values(die, signed=False), [('high', value)])
                self.assertEqual(dwarf1.enum_values(die), [('high', -1)])

    def test_missing_width_retains_four_byte_default(self):
        die = enum_die(4, [('legacy', -7)])
        del die.attrs['byte_size']
        self.assertEqual(dwarf1.enum_values(die), [('legacy', -7)])

    def test_forward_declaration_is_empty(self):
        self.assertEqual(dwarf1.enum_values(dwarf1.Die(0, 4, {'name': 'Forward'})), [])

    def test_malformed_values_fail_with_context(self):
        cases = [(4, b'\x01\x02', 'truncated enum value'),
                 (1, b'\x01name', 'unterminated enum name'),
                 (1, b'\x01\0', 'empty enum name'),
                 (3, b'\x01\x02\x03name\0', 'unsupported enum byte_size')]
        for width, data, message in cases:
            with self.subTest(width=width, data=data):
                die = dwarf1.Die(0x123, 4, {'byte_size': width, 'element_list': data})
                with self.assertRaisesRegex(ValueError, message + '.*0x123'):
                    dwarf1.enum_values(die)

    def test_parser_reads_synthetic_die_and_child_ranges(self):
        parsed = dwarf1.Dwarf1(synthetic_debug())
        self.assertEqual(len(parsed.cus), 1)
        enums = parsed.cus[0].children
        self.assertEqual([die.get('byte_size') for die in enums], [1, 2, 4])
        self.assertEqual(dwarf1.enum_values(enums[0]), [('absent', -1), ('high', -128), ('second', 7)])


class TestExtractOutput(unittest.TestCase):
    def test_mixed_width_output(self):
        """Exercise the production extractor callsite, not a duplicate renderer."""
        debug = synthetic_debug()
        elf = SimpleNamespace(get_section_by_name=lambda name:
                              SimpleNamespace(data=lambda: debug))

        def open_fake_elf(stream):
            stream.close()
            return elf

        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            source = root / 'synthetic.elf'
            source.write_bytes(b'synthetic fixture, not an executable')
            cache = root / 'cache'
            cache.mkdir()
            with patch.dict(extract_proto.PROTOS, {'synthetic': str(source)}, clear=True), \
                    patch.object(extract_proto, 'P1', str(root / 'out')), \
                    patch.object(extract_proto, 'CACHE', str(cache)), \
                    patch.object(extract_proto, 'ELFFile', side_effect=open_fake_elf), \
                    patch.object(extract_proto, 'load_main', return_value=(0x100000, b'')), \
                    patch.object(extract_proto, 'elf_symbols', return_value=[]), \
                    patch.object(extract_proto.pickle, 'dump',
                                 side_effect=lambda value, stream: stream.close()), \
                    contextlib.redirect_stdout(io.StringIO()):
                extract_proto.main('synthetic')
            text = (root / 'out/synthetic/types.txt').read_text()
            # Preserve the extractor's existing reverse presentation order.
            self.assertIn('enum Synthetic8 { second=7, high=128 /* signed -128 */, absent=255 /* signed -1 */ }', text)
            self.assertIn('enum Synthetic16 { negative=65534 /* signed -2 */, low=4660 }', text)
            self.assertIn('enum Synthetic32 { negative=-3, wide=305419896 }', text)


if __name__ == '__main__':
    unittest.main()
