#!/usr/bin/env python3
"""Side-by-side disassembly diff for a retail address and its prototype match.

usage: spotcheck.py ADDR [ADDR...]            (hex retail addresses)
       spotcheck.py --sample N [--method M] [--conf high] [--seed S]
"""
import sys, os, re, subprocess, random, difflib, csv
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import *


def dis(elf, addr, size):
    p = subprocess.run([BIN + 'objdump', '-d', '-z', '--no-show-raw-insn', '-M', 'no-aliases',
                        '--start-address=0x%x' % addr, '--stop-address=0x%x' % (addr + size), elf],
                       capture_output=True, text=True)
    out = []
    for line in p.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+(\S+)\s*(.*)$', line)
        if not m:
            continue
        ins, ops = m.group(2), m.group(3)
        ops = re.sub(r'<[^>]*>', '', ops)
        ops = re.sub(r'\b0x[0-9a-f]{5,}\b|\b[0-9a-f]{6,}\b', 'ADDR', ops)
        if ins in ('beq', 'bne', 'b', 'beql', 'bnel', 'bgez', 'bltz', 'blez', 'bgtz', 'bc1t', 'bc1f', 'bc1tl', 'bc1fl'):
            ops = re.sub(r',?\s*[0-9a-f]+\s*$', ',L', ops)
        out.append((ins + ' ' + ops).strip())
    return out


def show(row, quiet=False):
    a = int(row['retail_addr'], 16)
    which = 'early' if row['early_addr'] else 'earlier'
    pa = int(row[which + '_addr'], 16)
    import pickle
    P = {f['addr']: f for f in pickle.load(open(os.path.join(CACHE, which + '.pkl'), 'rb'))['funcs']}
    r = dis(os.path.join(P1, 'retail_built.elf'), a, int(row['size']))
    p = dis(PROTOS[which], pa, P[pa]['size'])
    sm = difflib.SequenceMatcher(None, r, p, autojunk=False)
    print('=' * 100)
    print('%08X %s  ->  %s %08X %s  [%s %s sim=%s]  textratio=%.3f  len %d/%d' % (
        a, row['retail_name'], which, pa, row['demangled'][:80], row['confidence'], row[which + '_method'],
        row[which + '_sim'], sm.ratio(), len(r), len(p)))
    if not quiet:
        for line in list(difflib.unified_diff(r, p, 'retail', which, n=1, lineterm=''))[:40]:
            print('   ', line)
    return sm.ratio()


def main():
    rows = list(csv.DictReader(open(os.path.join(P1, 'map.tsv')), delimiter='\t'))
    by = {r['retail_addr']: r for r in rows}
    args = sys.argv[1:]
    if args and args[0] == '--sample':
        n = int(args[1]); meth = None; conf = 'high'; seed = 1; quiet = '--quiet' in args
        if '--method' in args: meth = args[args.index('--method') + 1]
        if '--conf' in args: conf = args[args.index('--conf') + 1]
        if '--seed' in args: seed = int(args[args.index('--seed') + 1])
        pool = [r for r in rows if r['confidence'] == conf and (r['early_addr'] or r['earlier_addr'])
                and (meth is None or (r['early_method'] or r['earlier_method']).startswith(meth))]
        random.Random(seed).shuffle(pool)
        for r in pool[:n]:
            show(r, quiet)
    else:
        for a in args:
            show(by['%08X' % int(a, 16)])


if __name__ == '__main__':
    main()
