#!/usr/bin/env python3
"""Retail function list + normalised fingerprints -> cache/retail.pkl

Function boundaries/names come from the byte-matching rebuild's ELF
(build/SCUS_972.64.elf, snapshot copied to build/agents/P1/retail_built.elf),
code bytes from orig/SCUS_972.64, splat unit per address from the link map.
"""
import sys, os, re, pickle, bisect, subprocess, shutil
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import *


def main():
    elfp = os.path.join(P1, 'retail_built.elf')
    if not os.path.exists(elfp) or '--refresh' in sys.argv:
        shutil.copy(os.path.join(REPO, 'build', 'SCUS_972.64.elf'), elfp)
    syms = elf_symbols(elfp)
    byaddr = {}
    for n, v, sz, t, b, sh in syms:
        if t != 'STT_FUNC' or not n or n.endswith('.NON_MATCHING'):
            continue
        cur = byaddr.get(v)
        # prefer a real name over func_ and larger size
        if cur is None or (cur[0].startswith('func_') and not n.startswith('func_')) or sz > cur[1]:
            byaddr[v] = (n, sz)
    base, blob = load_main(os.path.join(REPO, 'orig', 'SCUS_972.64'))
    # splat units from the link map
    units = []
    mp = os.path.join(REPO, 'build', 'SCUS_972.64.map')
    for line in open(mp):
        m = re.match(r'\s*\.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+build/(\S+)\.o$', line)
        if m:
            units.append((int(m.group(1), 16), int(m.group(2), 16), m.group(3)))
    units.sort()
    ustarts = [u[0] for u in units]
    # report.json functions (the "main code" set the progress report counts)
    rep = json.load(open(os.path.join(REPO, 'progress', 'report.json')))
    repnames = {f['name'] for u in rep['units'] for f in u.get('functions', [])}
    funcs = []
    addrs = sorted(byaddr)
    for a in addrs:
        n, sz = byaddr[a]
        o = a - base
        code = strip_trailing_nops(blob[o:o + sz])
        h0, h1, h2, calls, refs = normalise(code, a)
        i = bisect.bisect_right(ustarts, a) - 1
        unit = units[i][2] if i >= 0 and units[i][0] <= a < units[i][0] + units[i][1] else ''
        funcs.append(dict(addr=a, size=sz, name=n, h0=hsh(h0), h1=hsh(h1), h2=hsh(h2), ops=h2, calls=calls,
                          refs=refs, strs=[s for s in (cstring_at(blob, base, r) for r in refs) if s],
                          ninsn=len(code) // 4, unit=unit, inreport=n in repnames))
    # data words (for vtable search)
    pickle.dump(dict(funcs=funcs, base=base, blob=blob), open(os.path.join(CACHE, 'retail.pkl'), 'wb'))
    print('retail funcs', len(funcs), 'in report', sum(f['inreport'] for f in funcs), 'units', len(units))


if __name__ == '__main__':
    main()
