#!/usr/bin/env python3
"""Extract functions, compile units, types and locals from a prototype ELF.

usage: extract_proto.py earlier|early
writes build/agents/P1/<proto>/{cu.tsv,types.txt,locals.tsv,globals.tsv}
and cache/<proto>.pkl (used by match.py)
"""
import sys, os, re, struct, pickle, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import *
import dwarf1
from demangle import demangle
from elftools.elf.elffile import ELFFile

FUNDSIZE = {1: 1, 2: 1, 3: 1, 4: 2, 5: 2, 6: 2, 7: 4, 8: 4, 9: 4, 0xa: 4, 0xb: 4, 0xc: 4, 0xd: 4,
            0xe: 4, 0xf: 8, 0x10: 8, 0x15: 1}


def is_header(path):
    return not re.search(r'\.(cc|cpp|c|s|asm)$', path or '', re.I)


def main(which):
    path = PROTOS[which]
    out = os.path.join(P1, which)
    os.makedirs(out, exist_ok=True)
    elf = ELFFile(open(path, 'rb'))
    dw = dwarf1.Dwarf1(elf.get_section_by_name('.debug').data())
    base, blob = load_main(path)

    # ---------------- functions from the symbol table ----------------
    syms = elf_symbols(path)
    funcs = {}
    names_at = collections.defaultdict(list)
    for n, v, sz, t, b, sh in syms:
        if t == 'STT_FUNC' and isinstance(sh, int) and sh == 5 and n:
            names_at[v].append((n, sz, b))
    objs = {}
    for n, v, sz, t, b, sh in syms:
        if t == 'STT_OBJECT' and n:
            objs.setdefault(v, []).append((n, sz))
    dem = {n: demangle(n)[0] for l in names_at.values() for n, _, _ in l}

    # ---------------- compile units ----------------
    cu_of = {}   # low_pc -> (cu path, function DIE)
    for cu in dw.cus:
        lo = cu.get('low_pc')
        if lo is None or cu.get('name') is None:
            continue
        fd = None
        for ch in cu.children:
            if ch.tag in (0x06, 0x14) and ch.get('low_pc') == lo:
                fd = ch; break
        if fd is None:
            for ch in cu.children:
                if ch.tag in (0x06, 0x14):
                    fd = ch; break
        cu_of[lo] = (cu.get('name'), fd, cu.get('high_pc'))

    addrs = sorted(names_at)
    flist = []
    for i, a in enumerate(addrs):
        l = sorted(names_at[a], key=lambda x: (x[2] != 'STB_GLOBAL', -x[1], x[0]))
        n, sz, b = l[0]
        if sz == 0:
            nxt = addrs[i + 1] if i + 1 < len(addrs) else a
            sz = nxt - a
        cu = cu_of.get(a)
        flist.append(dict(addr=a, size=sz, name=n, dem=dem.get(n, n), bind=b,
                          aliases=[x[0] for x in l[1:]], src=cu[0] if cu else '',
                          dwname=(cu[1].get('name') if cu and cu[1] else '')))
    # object (.cc) assignment: header-CU functions take the .cc of the nearest
    # non-header neighbour (inline/weak functions are emitted into the object)
    srcs = [f['src'] for f in flist]
    obj = [None] * len(flist)
    last = None
    for i, f in enumerate(flist):
        if f['src'] and not is_header(f['src']):
            last = f['src']
        obj[i] = f['src'] if (f['src'] and not is_header(f['src'])) else None
    # header (inline/template) functions: walk left/right without crossing
    # functions that have no debug info; take the nearer .cc (prefer the next
    # one on ties: MW emits weak inlines after the object's own functions less
    # often than before them... both happen, so distance decides)
    N = len(flist)
    prevc = [None] * N; nextc = [None] * N
    p = None
    for i in range(N):
        if obj[i]: p = (i, obj[i])
        prevc[i] = p
    p = None
    for i in range(N - 1, -1, -1):
        if obj[i]: p = (i, obj[i])
        nextc[i] = p
    for i, f in enumerate(flist):
        if obj[i]:
            f['obj'] = obj[i]; f['objhow'] = 'cu'; continue
        lp, rp = prevc[i], nextc[i]
        tag = 'hdr' if f['src'] else 'nodebug'
        if lp and rp and lp[1] == rp[1]:
            f['obj'] = lp[1]; f['objhow'] = tag + '-between'
            continue
        cands = [(i - lp[0], lp[1]) if lp else None, (rp[0] - i, rp[1]) if rp else None]
        cands = [c for c in cands if c]
        lim = 8 if f['src'] else 3
        if cands and min(cands)[0] <= lim:
            f['obj'] = min(cands)[1]; f['objhow'] = tag + '-nearest'
        else:
            f['obj'] = ''; f['objhow'] = tag + '-unknown'

    # ---------------- normalisation ----------------
    for f in flist:
        o = f['addr'] - base
        code = strip_trailing_nops(blob[o:o + f['size']])
        h0, h1, h2, calls, refs = normalise(code, f['addr'])
        f['h0'], f['h1'], f['h2'] = hsh(h0), hsh(h1), hsh(h2)
        f['ops'] = h2
        f['calls'] = calls
        f['strs'] = [s for s in (cstring_at(blob, base, r) for r in refs) if s]
        f['refs'] = refs
        f['ninsn'] = len(code) // 4

    # ---------------- vtables ----------------
    vt = {}
    for v, l in objs.items():
        for n, sz in l:
            if n.startswith('__vt__'):
                o = v - base
                if 0 <= o < len(blob):
                    words = struct.unpack_from('<%dI' % (sz // 4), blob, o)
                    vt[n] = (v, list(words))
    # data objects (for string/global naming)
    dobjs = {v: l[0][0] for v, l in objs.items()}

    pickle.dump(dict(funcs=flist, vtables=vt, dobjs=dobjs), open(os.path.join(CACHE, which + '.pkl'), 'wb'))

    # ---------------- cu.tsv ----------------
    with open(os.path.join(out, 'cu.tsv'), 'w') as fo:
        fo.write('object\tsource_cu\taddr\tsize\tmangled\tdemangled\tbind\tobj_assign\n')
        for f in flist:
            fo.write('%s\t%s\t%08X\t%d\t%s\t%s\t%s\t%s\n' % (f['obj'], f['src'], f['addr'], f['size'], f['name'],
                                                         f['dem'], f['bind'][4:], f['objhow']))

    # ---------------- locals.tsv ----------------
    def walk(d, depth, rows):
        for g in d.children:
            if g.tag in (0x05, 0x0c):
                loc = dwarf1.loc_str(g.get('location'))
                if g.tag == 5 and loc == '$v0':
                    loc = '(incoming arg reg; MW emits reg 2 here)'
                rows.append((('param' if g.tag == 5 else 'local'), depth, g.get('name') or '', dw.type_of(g), loc))
            elif g.tag == 0x0b:
                walk(g, depth + 1, rows)
            elif g.tag == 0x18:
                rows.append(('param', depth, '...', '', ''))
            elif g.tag == 0x07:  # function-static
                rows.append(('static', depth, g.get('name') or '', dw.type_of(g), dwarf1.loc_str(g.get('location'))))
    fmap = {f['addr']: f for f in flist}
    with open(os.path.join(out, 'locals.tsv'), 'w') as fo:
        fo.write('addr\tmangled\treturn\tkind\tblock_depth\tname\ttype\tlocation\n')
        for lo in sorted(cu_of):
            src, fd, hi = cu_of[lo]
            if fd is None:
                continue
            f = fmap.get(lo)
            mn = f['name'] if f else fd.get('name')
            rows = []
            walk(fd, 0, rows)
            ret = dw.type_of(fd)
            if not rows:
                fo.write('%08X\t%s\t%s\t-\t\t\t\t\n' % (lo, mn, ret))
            for r in rows:
                fo.write('%08X\t%s\t%s\t%s\t%d\t%s\t%s\t%s\n' % ((lo, mn, ret) + r))

    # ---------------- types.txt / globals.tsv ----------------
    def tsize(d):
        a = d.attrs
        if 'fund_type' in a:
            return FUNDSIZE.get(a['fund_type'])
        if 'mod_fund_type' in a or 'mod_u_d_type' in a:
            b = a.get('mod_fund_type') or a.get('mod_u_d_type')
            mods = b[:-2] if 'mod_fund_type' in a else b[:-4]
            if any(m in (1, 2) for m in mods):
                return 4
            if 'mod_fund_type' in a:
                return FUNDSIZE.get(struct.unpack('<H', b[-2:])[0])
            ref = struct.unpack('<I', b[-4:])[0]
        elif 'user_def_type' in a:
            ref = a['user_def_type']
        else:
            return None
        t = dw.by_off.get(ref)
        if t is None:
            return None
        if t.get('byte_size') is not None:
            return t.get('byte_size')
        if t.tag == 0x16 or t.tag == 0x0f:
            return tsize(t) if t.tag == 0x16 else 4
        if t.tag == 0x01:
            el, dims = dw.array_info(t)
            return None
        return None

    seen = {}
    enums = {}
    typedefs = {}
    for cu in dw.cus:
        if cu.get('low_pc') is not None:
            continue
        stack = list(cu.children)
        while stack:
            t = stack.pop()
            if t.tag in (0x02, 0x13, 0x17):
                name = t.get('name') or '<anon@%x>' % t.off
                mem = []
                for m in t.children:
                    if m.tag == 0x0d:
                        off = dwarf1.member_offset(m.get('location'))
                        bits = ''
                        if m.get('bit_size') is not None:
                            bits = ' :%d (bit_off %d)' % (m.get('bit_size'), m.get('bit_offset'))
                        mem.append(('m', off, m.get('name') or '', dw.type_of(m), tsize(m), bits))
                    elif m.tag == 0x1c:
                        acc = 'virtual ' if 'virtual' in m.attrs or 'at_26' in m.attrs else ''
                        mem.append(('b', dwarf1.member_offset(m.get('location')), '', acc + dw.type_of(m), None, ''))
                    stack.extend(m.children if m.tag in (0x02, 0x13, 0x17) else [])
                if not mem and not t.get('byte_size'):
                    continue  # forward declaration
                key = (name, t.get('byte_size'), tuple(mem))
                seen.setdefault(key, (t.tname, cu.get('name')))
            elif t.tag == 0x04:
                el = t.get('element_list') or b''
                vals = []
                p = 0
                while p + 4 <= len(el):
                    v = struct.unpack_from('<i', el, p)[0]; p += 4
                    q = el.find(b'\0', p)
                    vals.append((el[p:q].decode('latin-1'), v)); p = q + 1
                vals.reverse()
                enums.setdefault((t.get('name') or '<anon enum>', tuple(vals)), cu.get('name'))
            elif t.tag == 0x16:
                typedefs.setdefault((t.get('name'), dw.type_of(t)), cu.get('name'))
            stack.extend(c for c in t.children if c.tag in (0x02, 0x13, 0x17, 0x04, 0x16))
    with open(os.path.join(out, 'types.txt'), 'w') as fo:
        fo.write('// structs/classes/unions from the %s prototype DWARF (offsets in hex, sizes in bytes)\n' % which)
        for (name, size, mem), (kind, src) in sorted(seen.items(), key=lambda x: (x[0][0], x[0][1] or 0)):
            fo.write('\n%s %s  // size 0x%X  (%s)\n' % (kind.replace('_type', ''), name, size or 0, src))
            for k, off, mn, ty, sz, bits in mem:
                if k == 'b':
                    fo.write('    : %s  @0x%X\n' % (ty, off or 0))
                else:
                    fo.write('    +0x%03X %-28s %s%s%s\n' % (off if off is not None else -1, ty, mn, bits,
                                                           '' if sz is None else '  // %d' % sz))
        fo.write('\n\n// ---- enums ----\n')
        for (name, vals), src in sorted(enums.items()):
            fo.write('enum %s { %s }  (%s)\n' % (name, ', '.join('%s=%d' % v for v in vals), src))
        fo.write('\n// ---- typedefs ----\n')
        for (name, ty), src in sorted(typedefs.items(), key=lambda x: (str(x[0][0]), x[0][1])):
            fo.write('typedef %s %s;  (%s)\n' % (ty, name, src))
    with open(os.path.join(out, 'globals.tsv'), 'w') as fo:
        fo.write('addr\tname\tlinkage\ttype\tsource_cu\n')
        rows = set()
        for cu in dw.cus:
            for g in cu.children:
                if g.tag == 0x07:
                    loc = dwarf1.loc_str(g.get('location'))
                    if loc.startswith('addr:'):
                        rows.add((loc[5:].upper(), g.get('name') or '', g.get('at_200', ''), dw.type_of(g), cu.get('name') or ''))
        for r in sorted(rows):
            fo.write('\t'.join(r) + '\n')
    print(which, 'funcs', len(flist), 'with CU', sum(1 for f in flist if f['src']), 'types', len(seen),
          'enums', len(enums), 'vtables', len(vt))


if __name__ == '__main__':
    for w in sys.argv[1:] or ['earlier', 'early']:
        main(w)
