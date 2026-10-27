#!/usr/bin/env python3
"""Minimal DWARF version 1 (.debug section, MIPS_DEBUG) parser for the
Metrowerks-built SFOS prototype ELFs.  Little-endian.

Each DIE: u32 length, u16 tag, then attributes (u16 code = name<<4|form).
Children of a DIE occupy [off+len, AT_sibling).
"""
import struct

TAGS = {0x01: 'array_type', 0x02: 'class_type', 0x03: 'entry_point', 0x04: 'enumeration_type',
        0x05: 'formal_parameter', 0x06: 'global_subroutine', 0x07: 'global_variable',
        0x0a: 'label', 0x0b: 'lexical_block', 0x0c: 'local_variable', 0x0d: 'member',
        0x0f: 'pointer_type', 0x10: 'reference_type', 0x11: 'compile_unit', 0x12: 'string_type',
        0x13: 'structure_type', 0x14: 'subroutine', 0x15: 'subroutine_type', 0x16: 'typedef',
        0x17: 'union_type', 0x18: 'unspecified_parameters', 0x19: 'variant', 0x1a: 'common_block',
        0x1b: 'common_inclusion', 0x1c: 'inheritance', 0x1d: 'inlined_subroutine', 0x1e: 'module',
        0x1f: 'ptr_to_member_type', 0x20: 'set_type', 0x21: 'subrange_type', 0x22: 'with_stmt'}
ATTRS = {0x001: 'sibling', 0x002: 'location', 0x003: 'name', 0x005: 'fund_type', 0x006: 'mod_fund_type',
         0x007: 'user_def_type', 0x008: 'mod_u_d_type', 0x009: 'ordering', 0x00a: 'subscr_data',
         0x00b: 'byte_size', 0x00c: 'bit_offset', 0x00d: 'bit_size', 0x00f: 'element_list',
         0x010: 'stmt_list', 0x011: 'low_pc', 0x012: 'high_pc', 0x013: 'language', 0x014: 'member',
         0x015: 'discr', 0x016: 'discr_value', 0x019: 'string_length', 0x01a: 'common_reference',
         0x01b: 'comp_dir', 0x01c: 'const_value', 0x01d: 'containing_type', 0x01e: 'default_value',
         0x020: 'inline', 0x021: 'is_optional', 0x022: 'lower_bound', 0x025: 'producer',
         0x027: 'prototyped', 0x02a: 'return_addr', 0x02c: 'start_scope', 0x02e: 'stride_size',
         0x02f: 'upper_bound', 0x030: 'virtual'}
FUND = {1: 'char', 2: 'signed char', 3: 'unsigned char', 4: 'short', 5: 'short', 6: 'unsigned short',
        7: 'int', 8: 'int', 9: 'unsigned int', 0xa: 'long', 0xb: 'long', 0xc: 'unsigned long',
        0xd: 'void*', 0xe: 'float', 0xf: 'double', 0x10: 'long double', 0x14: 'void', 0x15: 'bool',
        0x17: 'label', 0x8008: 'long long', 0x8208: 'unsigned long long', 0xa510: 'u_long128'}


class Die:
    __slots__ = ('off', 'tag', 'attrs', 'children', 'parent')

    def __init__(self, off, tag, attrs):
        self.off, self.tag, self.attrs, self.children, self.parent = off, tag, attrs, [], None

    def get(self, k, d=None):
        return self.attrs.get(k, d)

    @property
    def tname(self):
        return TAGS.get(self.tag, 'tag_%x' % self.tag)


class Dwarf1:
    def __init__(self, data):
        self.d = data
        self.by_off = {}
        self.cus = self._list(0, len(data), None)

    def _die(self, off):
        d = self.d
        ln = struct.unpack_from('<I', d, off)[0]
        if ln < 8:
            return ln, None
        tag = struct.unpack_from('<H', d, off + 4)[0]
        p, end = off + 6, off + ln
        attrs = {}
        while p < end:
            code = struct.unpack_from('<H', d, p)[0]; p += 2
            form = code & 0xf; name = code >> 4
            if form in (1, 2, 6):
                v = struct.unpack_from('<I', d, p)[0]; p += 4
            elif form == 5:
                v = struct.unpack_from('<H', d, p)[0]; p += 2
            elif form == 7:
                v = struct.unpack_from('<Q', d, p)[0]; p += 8
            elif form == 3:
                n = struct.unpack_from('<H', d, p)[0]; p += 2
                v = bytes(d[p:p + n]); p += n
            elif form == 4:
                n = struct.unpack_from('<I', d, p)[0]; p += 4
                v = bytes(d[p:p + n]); p += n
            elif form == 8:
                q = d.index(b'\0', p)
                v = d[p:q].decode('latin-1'); p = q + 1
            else:
                break  # unknown form: stop parsing this DIE
            attrs[ATTRS.get(name, 'at_%x' % name)] = v
        return ln, Die(off, tag, attrs)

    def _list(self, start, end, parent):
        out = []
        off = start
        while off < end:
            ln, die = self._die(off)
            if die is None:
                off += max(ln, 4)
                continue
            die.parent = parent
            self.by_off[off] = die
            sib = die.get('sibling')
            if sib is not None and sib > off + ln:
                die.children = self._list(off + ln, min(sib, end), die)
                off = sib
            else:
                off += ln
            out.append(die)
        return out

    # ---- type rendering -------------------------------------------------
    def type_of(self, die, depth=0):
        a = die.attrs
        if 'fund_type' in a:
            return FUND.get(a['fund_type'], 'ft_%x' % a['fund_type'])
        if 'user_def_type' in a:
            return self.udt_name(a['user_def_type'], depth)
        if 'mod_fund_type' in a:
            b = a['mod_fund_type']
            return self._mods(b[:-2], FUND.get(struct.unpack('<H', b[-2:])[0], 'ft?'))
        if 'mod_u_d_type' in a:
            b = a['mod_u_d_type']
            return self._mods(b[:-4], self.udt_name(struct.unpack('<I', b[-4:])[0], depth))
        return 'void'

    @staticmethod
    def _mods(mods, base):
        s = base
        for m in reversed(mods):
            if m == 1: s += '*'
            elif m == 2: s += '&'
            elif m == 3: s = 'const ' + s
            elif m == 4: s = 'volatile ' + s
        return s

    def udt_name(self, ref, depth=0):
        t = self.by_off.get(ref)
        if t is None:
            return 'type@%x' % ref
        n = t.get('name')
        if n:
            return n
        if depth > 6:
            return '?'
        if t.tag == 0x01:
            el, dims = self.array_info(t, depth)
            return el + ''.join('[%s]' % x for x in dims)
        if t.tag == 0x15:
            return '%s(*)()' % self.type_of(t, depth + 1)
        if t.tag == 0x0f:
            return self.type_of(t, depth + 1) + '*'
        if t.tag in (0x13, 0x17, 0x02):
            return '<anon %s @%x size %s>' % (t.tname, t.off, t.get('byte_size'))
        if t.tag == 0x04:
            return '<anon enum @%x>' % t.off
        if t.tag == 0x1f:
            return '<ptrmem>'
        return '<%s@%x>' % (t.tname, t.off)

    def array_info(self, t, depth=0):
        b = t.get('subscr_data') or b''
        dims = []
        p = 0
        el = '?'
        while p < len(b):
            fmt = b[p]; p += 1
            if fmt == 0:  # FT_C_C
                p += 2
                lo, hi = struct.unpack_from('<ii', b, p); p += 8
                dims.append(str(hi - lo + 1))
            elif fmt in (1, 2, 3, 4, 5, 6, 7):
                # variable bounds; skip conservatively (rare)
                dims.append('?'); break
            elif fmt == 8:  # FMT_ET: element type attribute follows
                code = struct.unpack_from('<H', b, p)[0]; p += 2
                form = code & 0xf; name = ATTRS.get(code >> 4)
                fake = Die(0, 0, {})
                if form == 5:
                    fake.attrs[name] = struct.unpack_from('<H', b, p)[0]; p += 2
                elif form in (1, 2, 6):
                    fake.attrs[name] = struct.unpack_from('<I', b, p)[0]; p += 4
                elif form == 3:
                    n = struct.unpack_from('<H', b, p)[0]; p += 2
                    fake.attrs[name] = b[p:p + n]; p += n
                el = self.type_of(fake, depth + 1)
                break
            else:
                break
        return el, dims


GPR = ['zero', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3', 't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
       's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 't8', 't9', 'k0', 'k1', 'gp', 'sp', 'fp', 'ra']


def loc_str(b):
    """Render a DWARF1 location expression (MW: op 0x80 = FPU register)."""
    if not b:
        return ''
    ops = []
    p = 0
    try:
        while p < len(b):
            op = b[p]; p += 1
            if op in (1, 2, 3, 4, 0x80):
                v = struct.unpack_from('<i' if op == 4 else '<I', b, p)[0]; p += 4
                ops.append((op, v))
            else:
                ops.append((op, None))
    except struct.error:
        return 'raw:' + b.hex()
    # common shapes
    if len(ops) == 1:
        op, v = ops[0]
        if op == 1: return '$' + (GPR[v] if v < 32 else 'r%d' % v)
        if op == 0x80: return '$f%d' % v
        if op == 3: return 'addr:%08X' % v
        if op == 2: return '0(%s)' % (GPR[v] if v < 32 else 'r%d' % v)
    if len(ops) == 3 and ops[0][0] == 2 and ops[1][0] == 4 and ops[2][0] == 7:
        r = ops[0][1]
        return '0x%X(%s)' % (ops[1][1], GPR[r] if r < 32 else 'r%d' % r)
    names = {1: 'reg', 2: 'basereg', 3: 'addr', 4: 'const', 5: 'deref2', 6: 'deref4', 7: 'add', 0x80: 'fpreg'}
    return ' '.join(names.get(op, 'op%x' % op) + ('' if v is None else ':%d' % v) for op, v in ops)


def member_offset(b):
    if not b:
        return None
    p = 0
    off = None
    while p < len(b):
        op = b[p]; p += 1
        if op in (1, 2, 3, 4):
            v = struct.unpack_from('<i', b, p)[0]; p += 4
            if op == 4: off = v
    return off
