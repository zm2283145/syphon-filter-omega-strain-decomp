#!/usr/bin/env python3
"""Per-function prototype dossier for matching lanes.

usage (WSL, repo root): .venv/bin/python dossier.py OUTDIR ADDR [ADDR...]
Writes OUTDIR/<ADDR>.txt with: map row, prototype source file, params/locals in
declaration order, layouts of the class and of struct types used, the prototype's
own disassembly (with symbols) and a normalised retail-vs-prototype diff.
"""
import sys, os, re, csv, difflib, subprocess, pickle
sys.path.insert(0, 'tools/proto')
from common import *  # noqa: E402,F401  (BIN, P1, CACHE, PROTOS)
import spotcheck  # noqa: E402

rows = {r['retail_addr']: r for r in csv.DictReader(open(os.path.join(P1, 'map.tsv')), delimiter='\t')}


def load_locals(which):
    d = {}
    for r in csv.DictReader(open(os.path.join(P1, which, 'locals.tsv')), delimiter='\t'):
        d.setdefault(r['mangled'], []).append(r)
    return d


def load_types(which):
    blocks, cur, name = {}, [], None
    for line in open(os.path.join(P1, which, 'types.txt')):
        m = re.match(r'^(class|structure|union|enum|typedef)\s+(\S+)', line)
        if m:
            if name and cur:
                blocks.setdefault(name, '\n'.join(cur))
            name, cur = m.group(2), [line.rstrip()]
        elif line.strip() == '':
            if name and cur:
                blocks.setdefault(name, '\n'.join(cur))
            name, cur = None, []
        elif name:
            cur.append(line.rstrip())
    if name and cur:
        blocks.setdefault(name, '\n'.join(cur))
    return blocks


LOC, TYP = {}, {}


def raw_dis(elf, addr, size):
    p = subprocess.run([BIN + 'objdump', '-d', '-z', '--no-show-raw-insn', '-M', 'no-aliases',
                        '--start-address=0x%x' % addr, '--stop-address=0x%x' % (addr + size), elf],
                       capture_output=True, text=True)
    return [l for l in p.stdout.splitlines() if re.match(r'\s*[0-9a-f]+:', l) or l.endswith('>:')]


def typenames(t):
    return set(re.findall(r'[A-Za-z_@][A-Za-z0-9_@:]*', t or '')) - {
        'unsigned', 'signed', 'char', 'short', 'int', 'long', 'float', 'double', 'void', 'const', 'volatile', 'bool'}


def one(addr, outdir):
    key = '%08X' % addr
    row = rows.get(key)
    out = []
    if not row:
        out.append('no prototype mapping row for %s' % key)
    else:
        out.append('retail %s %s  size %s' % (key, row['retail_name'], row['size']))
        out.append('prototype: %s  confidence=%s  object=%s' % (row['demangled'], row['confidence'], row.get('object', '')))
        for k in ('early', 'earlier'):
            if row.get(k + '_addr'):
                out.append('  %s: %s %s method=%s sim=%s' % (k, row[k + '_addr'], row.get(k + '_symbol', ''), row[k + '_method'], row[k + '_sim']))
        if row.get('notes'):
            out.append('  notes: ' + row['notes'])
        for which in ('early', 'earlier'):
            if not row.get(which + '_addr'):
                continue
            if which not in LOC:
                LOC[which], TYP[which] = load_locals(which), load_types(which)
            pa = int(row[which + '_addr'], 16)
            P = {f['addr']: f for f in pickle.load(open(os.path.join(CACHE, which + '.pkl'), 'rb'))['funcs']}
            pf = P.get(pa, {})
            mangled = row.get(which + '_symbol') or pf.get('name', '')
            lv = LOC[which].get(mangled, [])
            out.append('\n== %s prototype params/locals (declaration order; block_depth; type; location)' % which)
            if lv:
                out.append('returns ' + lv[0]['return'])
                for r in lv:
                    if r['kind'] in ('param', 'local', 'static'):
                        out.append('  %s%-6s %-28s %-30s %s' % ('  ' * int(r['block_depth'] or 0), r['kind'], r['type'], r['name'], r['location']))
            else:
                out.append('  (none recorded)')
            names = set()
            dm = row['demangled']
            if '::' in dm:
                names.add(dm.split('(')[0].rsplit('::', 1)[0].split('::')[-1])
            for r in lv:
                names |= typenames(r['type'])
            shown = 0
            out.append('\n== %s prototype type layouts used' % which)
            for n in sorted(names):
                b = TYP[which].get(n)
                if b and shown < 12:
                    lines = b.splitlines()
                    out.append('\n'.join(lines[:90]) + ('\n    ... (%d more members; see build/agents/P1/%s/types.txt)' % (len(lines) - 90, which) if len(lines) > 90 else ''))
                    out.append('')
                    shown += 1
            out.append('\n== %s prototype disassembly (%s, %d bytes)' % (which, mangled, pf.get('size', 0)))
            out.extend(raw_dis(PROTOS[which], pa, pf.get('size', 0))[:700])
            try:
                r_ = spotcheck.dis(os.path.join(P1, 'retail_built.elf'), addr, int(row['size']))
                p_ = spotcheck.dis(PROTOS[which], pa, pf.get('size', 0))
                sm = difflib.SequenceMatcher(None, r_, p_, autojunk=False)
                out.append('\n== normalised diff retail(-) vs %s prototype(+)  ratio=%.3f  len %d/%d' % (which, sm.ratio(), len(r_), len(p_)))
                out.extend(list(difflib.unified_diff(r_, p_, 'retail', which, n=2, lineterm=''))[:400])
            except Exception as e:
                out.append('diff failed: %s' % e)
            break  # early (Jan 2004) is closest to retail; fall back to earlier only if absent
    os.makedirs(outdir, exist_ok=True)
    open(os.path.join(outdir, key + '.txt'), 'w').write('\n'.join(out) + '\n')


if __name__ == '__main__':
    for a in sys.argv[2:]:
        one(int(a, 16), sys.argv[1])
