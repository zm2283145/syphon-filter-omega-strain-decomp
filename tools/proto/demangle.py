#!/usr/bin/env python3
"""Demangler for Metrowerks / cfront-ARM style C++ names, e.g.
   Load__6cHumanFPv               -> cHuman::Load(void*)
   __ct__7cMatrixFRC11cQuaternion -> cMatrix::cMatrix(const cQuaternion&)
Returns (pretty, info) where info = dict(cls=[qualifiers], base=name, kind=
'ctor'|'dtor'|'op'|'method'|'func'|'data', const=bool, params=str).
"""
import re

OPS = {'as': 'operator=', 'eq': 'operator==', 'ne': 'operator!=', 'pl': 'operator+', 'mi': 'operator-',
       'ml': 'operator*', 'dv': 'operator/', 'md': 'operator%', 'apl': 'operator+=', 'ami': 'operator-=',
       'amu': 'operator*=', 'adv': 'operator/=', 'amd': 'operator%=', 'vc': 'operator[]', 'cl': 'operator()',
       'nw': 'operator new', 'dl': 'operator delete', 'nwa': 'operator new[]', 'dla': 'operator delete[]',
       'lt': 'operator<', 'gt': 'operator>', 'le': 'operator<=', 'ge': 'operator>=', 'rf': 'operator->',
       'ad': 'operator&', 'aa': 'operator&&', 'oo': 'operator||', 'nt': 'operator!', 'co': 'operator~',
       'ls': 'operator<<', 'rs': 'operator>>', 'pp': 'operator++', 'mm': 'operator--', 'er': 'operator^',
       'or': 'operator|', 'aer': 'operator^=', 'aor': 'operator|=', 'aad': 'operator&=', 'ars': 'operator>>=',
       'als': 'operator<<=', 'cm': 'operator,', 'rm': 'operator->*'}
# identifier-friendly operator names
OPID = {'as': 'opAssign', 'eq': 'opEq', 'ne': 'opNe', 'pl': 'opAdd', 'mi': 'opSub', 'ml': 'opMul', 'dv': 'opDiv',
        'md': 'opMod', 'apl': 'opAddAssign', 'ami': 'opSubAssign', 'amu': 'opMulAssign', 'adv': 'opDivAssign',
        'amd': 'opModAssign', 'vc': 'opIndex', 'cl': 'opCall', 'nw': 'opNew', 'dl': 'opDelete', 'nwa': 'opNewArray',
        'dla': 'opDeleteArray', 'lt': 'opLt', 'gt': 'opGt', 'le': 'opLe', 'ge': 'opGe', 'rf': 'opArrow',
        'ad': 'opAnd', 'aa': 'opLogAnd', 'oo': 'opLogOr', 'nt': 'opNot', 'co': 'opCompl', 'ls': 'opShl',
        'rs': 'opShr', 'pp': 'opInc', 'mm': 'opDec', 'er': 'opXor', 'or': 'opOr', 'aer': 'opXorAssign',
        'aor': 'opOrAssign', 'aad': 'opAndAssign', 'ars': 'opShrAssign', 'als': 'opShlAssign', 'cm': 'opComma',
        'rm': 'opArrowStar'}
BUILTIN = {'v': 'void', 'c': 'char', 's': 'short', 'i': 'int', 'l': 'long', 'x': 'long long', 'f': 'float',
           'd': 'double', 'r': 'long double', 'b': 'bool', 'w': 'wchar_t', 'e': '...'}


class P:
    def __init__(self, s):
        self.s, self.i = s, 0

    def peek(self):
        return self.s[self.i] if self.i < len(self.s) else ''

    def num(self):
        m = re.match(r'\d+', self.s[self.i:])
        if not m:
            raise ValueError('num')
        self.i += len(m.group())
        return int(m.group())

    def name(self):
        n = self.num()
        r = self.s[self.i:self.i + n]
        if len(r) != n:
            raise ValueError('name')
        self.i += n
        return tmpl(r)

    def qual(self):
        if self.peek() == 'Q':
            self.i += 1
            if self.peek() == '_':
                self.i += 1; c = self.num(); self.i += 1
            else:
                c = int(self.s[self.i]); self.i += 1
            return [self.name() for _ in range(c)]
        return [self.name()]

    def typ(self, params):
        pre = []
        while True:
            c = self.peek()
            if c == 'C': pre.append('const'); self.i += 1
            elif c == 'V': pre.append('volatile'); self.i += 1
            elif c == 'U': pre.append('unsigned'); self.i += 1
            elif c == 'S': pre.append('signed'); self.i += 1
            else: break
        c = self.peek()
        if c == 'P':
            self.i += 1
            if self.peek() == 'F':
                return self.typ(params)
            return self._cv(pre, self.typ(params) + '*')
        if c == 'R':
            self.i += 1
            return self._cv(pre, self.typ(params) + '&')
        if c == 'A':
            self.i += 1; n = self.num(); self.i += 1
            return self.typ(params) + '[%d]' % n
        if c == 'F':
            self.i += 1
            ps = self.plist('_')
            self.i += 1
            ret = self.typ(params)
            return '%s(*)(%s)' % (ret, ', '.join(ps))
        if c == 'M':
            self.i += 1
            cl = '::'.join(self.qual())
            t = self.typ(params)
            return '%s %s::*' % (t, cl)
        if c.isdigit() or c == 'Q':
            t = '::'.join(self.qual())
        elif c in BUILTIN:
            self.i += 1
            t = BUILTIN[c]
        else:
            raise ValueError('type %r' % c)
        return ' '.join(pre + [t])

    @staticmethod
    def _cv(pre, t):
        return t + (' const' if 'const' in pre else '')

    def plist(self, end=''):
        ps = []
        while self.i < len(self.s) and self.peek() != end:
            c = self.peek()
            if c == 'T':
                self.i += 1; n = int(self.s[self.i]); self.i += 1
                ps.append(ps[n - 1] if n - 1 < len(ps) else '?')
            elif c == 'N':
                self.i += 1; cnt = int(self.s[self.i]); n = int(self.s[self.i + 1]); self.i += 2
                ps.extend([ps[n - 1] if n - 1 < len(ps) else '?'] * cnt)
            else:
                ps.append(self.typ(ps))
        return ps


def tmpl(n):
    """Demangle template arguments inside a class name: cTree<27cFoo,i> -> cTree<cFoo,int>"""
    if '<' not in n:
        return n
    a = n.index('<'); b = n.rindex('>')
    inner = n[a + 1:b]
    parts = []
    depth = 0; cur = ''
    for ch in inner:
        if ch == '<': depth += 1
        if ch == '>': depth -= 1
        if ch == ',' and depth == 0:
            parts.append(cur); cur = ''
        else:
            cur += ch
    parts.append(cur)
    out = []
    for p in parts:
        try:
            q = P(p); t = q.typ([])
            out.append(t if q.i == len(p) else p)
        except Exception:
            out.append(p)
    return n[:a] + '<' + ','.join(out) + '>' + n[b + 1:]


def demangle(sym):
    info = dict(cls=[], base=sym, kind='func', const=False, params=None)
    s = sym
    start = 2 if s.startswith('__') else 0
    k = s.find('__', start)
    while k == 0:
        k = s.find('__', 2)
    if k <= 0 or k + 2 >= len(s):
        return sym, info
    base, rest = s[:k], s[k + 2:]
    # base name containing an extra '__' (e.g. names ending in _): try next split if parse fails
    for attempt in range(3):
        try:
            p = P(rest)
            cls = []
            if p.peek().isdigit() or p.peek() == 'Q':
                cls = p.qual()
            const = False
            if p.peek() == 'C':
                const = True; p.i += 1
            if p.peek() == 'F':
                p.i += 1
                ps = p.plist('_')
                if p.peek() == '_':  # function template: explicit return type
                    p.i += 1
                    p.typ(ps)
                kind = 'method' if cls else 'func'
            elif p.i == len(rest) and cls:
                ps = None; kind = 'data'
            else:
                raise ValueError('no F')
            if p.i != len(rest):
                raise ValueError('trailing')
            break
        except Exception:
            k2 = s.find('__', k + 1)
            if k2 < 0:
                return sym, info
            k = k2
            base, rest = s[:k], s[k + 2:]
    else:
        return sym, info
    disp = tmpl(base)
    targs = ''
    if '<' in base:
        targs = tmpl(base)[base.index('<'):]
        base = base[:base.index('<')]
    if base == '__ct':
        kind = 'ctor'; disp = cls[-1].split('<')[0] if cls else base
    elif base == '__dt':
        kind = 'dtor'; disp = '~' + (cls[-1].split('<')[0] if cls else base)
    elif base.startswith('__op'):
        kind = 'conv'
        try:
            disp = 'operator ' + P(base[4:]).typ([])
        except Exception:
            disp = base
    elif base.startswith('__') and base[2:] in OPS:
        kind = 'op'; disp = OPS[base[2:]] + targs
    info.update(cls=cls, base=base, kind=kind, const=const, params=ps)
    q = '::'.join(cls + [disp]) if cls else disp
    if ps is None:
        return q, info
    pl = ', '.join(x for x in ps if x != 'void') if ps != ['void'] else ''
    return '%s(%s)%s' % (q, pl, ' const' if const else ''), info


def ident(c):
    c = re.sub(r'<.*>', lambda m: 'T', c) if '<' in c else c
    return re.sub(r'[^A-Za-z0-9_]', '_', c)


def c_ident(sym):
    """Identifier in the repo's convention: Class_Method / Class_ctor / Class_dtor / free name."""
    pretty, info = demangle(sym)
    cls = info['cls']
    base = info['base']
    kind = info['kind']
    if kind == 'ctor': m = 'ctor'
    elif kind == 'dtor': m = 'dtor'
    elif kind == 'op': m = OPID.get(base[2:], 'op')
    elif kind == 'conv':
        try:
            m = 'opCast_' + ident(P(base[4:]).typ([]).replace('*', 'Ptr').replace('&', 'Ref').replace(' ', ''))
        except Exception:
            m = 'opCast'
    else:
        m = base
    if cls:
        # template class: cTreeNode<cFoo> -> cTreeNode_cFoo
        parts = []
        for c in cls:
            if '<' in c:
                a = c.index('<')
                args = re.sub(r'[^A-Za-z0-9]+', '_', c[a + 1:c.rindex('>')]).strip('_')
                parts.append(c[:a] + ('_' + args if args else ''))
            else:
                parts.append(c)
        return '_'.join(parts) + '_' + ident(m), pretty, info
    return ident(m), pretty, info


if __name__ == '__main__':
    import sys
    for a in sys.argv[1:]:
        print(a, '->', demangle(a)[0], '|', c_ident(a)[0])
