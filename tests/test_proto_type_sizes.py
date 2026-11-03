"""Extractor output for synthetic Metrowerks EE fundamental types."""
import contextlib
import io
from pathlib import Path
import struct
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

from tools.proto import extract_proto


def named(name):
    return struct.pack('<H', 0x0038) + name.encode('ascii') + b'\0'


def member(name, offset, type_attr):
    location = b'\x04' + struct.pack('<i', offset) + b'\x07'
    attrs = (named(name) + type_attr
             + struct.pack('<HH', 0x0023, len(location)) + location)
    return struct.pack('<IH', 6 + len(attrs), 0x0d) + attrs


def fund(code):
    return struct.pack('<HH', 0x0055, code)


def modified(modifier, code):
    payload = bytes([modifier]) + struct.pack('<H', code)
    return struct.pack('<HH', 0x0063, len(payload)) + payload


def synthetic_debug():
    members = (member('tick', 0, fund(0x0a))
               + member('total', 8, fund(0x0c))
               + member('address', 16, modified(1, 0x0c))
               + member('count', 20, fund(7))
               + member('limit', 24, modified(3, 0x0b)))
    cu_name = named('synthetic.cc')
    cu_length = 6 + len(cu_name) + 6
    type_attrs = named('SyntheticClock') + struct.pack('<HH', 0x00b5, 32)
    type_length = 6 + len(type_attrs) + 6
    end = cu_length + type_length + len(members)
    sibling = struct.pack('<HI', 0x0011, end)
    return (struct.pack('<IH', cu_length, 0x11) + cu_name + sibling
            + struct.pack('<IH', type_length, 0x02) + type_attrs + sibling
            + members)


class TestNativeTypeSizes(unittest.TestCase):
    def test_long_is_eight_bytes_while_int_and_pointers_are_four(self):
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
            self.assertRegex(text, r'\+0x000\s+long\s+tick\s+// 8')
            self.assertRegex(text, r'\+0x008\s+unsigned long\s+total\s+// 8')
            self.assertRegex(text, r'\+0x010\s+unsigned long\*\s+address\s+// 4')
            self.assertRegex(text, r'\+0x014\s+int\s+count\s+// 4')
            self.assertRegex(text, r'\+0x018\s+const long\s+limit\s+// 8')


if __name__ == '__main__':
    unittest.main()
