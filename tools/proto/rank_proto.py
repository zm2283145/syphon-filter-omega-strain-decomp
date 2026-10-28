#!/usr/bin/env python3
"""Rank unmatched functions by prototype similarity (WSL, repo root).
usage: .venv/bin/python tools/proto/rank_proto.py > build/agents/proto_rank.tsv"""
import sys, os, json, subprocess, difflib, csv, pickle
sys.path.insert(0, 'tools/proto')
from common import *  # noqa
import spotcheck

j = json.loads(subprocess.run(['.venv/bin/python', 'tools/rank_candidates.py', '--report', 'progress/report.json',
                               '--json', '--limit', '5000'], capture_output=True, text=True).stdout)
rows = {r['retail_addr']: r for r in csv.DictReader(open(os.path.join(P1, 'map.tsv')), delimiter='\t')}
P = {}
for w in ('early', 'earlier'):
    P[w] = {f['addr']: f for f in pickle.load(open(os.path.join(CACHE, w + '.pkl'), 'rb'))['funcs']}
print('addr\tsize\tname\tratio\tproto_len\tretail_len\tconf\twhich\tdemangled\towner\tobject')
for c in j['candidates']:
    a = int(c['address'], 16); key = '%08X' % a
    row = rows.get(key)
    ratio, pl, rl, w, dm, conf, obj = 0.0, 0, 0, '-', '', 'none', ''
    if row:
        conf, dm, obj = row['confidence'], row['demangled'], row['object']
        w = 'early' if row['early_addr'] else ('earlier' if row['earlier_addr'] else '-')
        if w != '-':
            pa = int(row[w + '_addr'], 16)
            r_ = spotcheck.dis(os.path.join(P1, 'retail_built.elf'), a, int(c['size_bytes']))
            p_ = spotcheck.dis(PROTOS[w], pa, P[w].get(pa, {}).get('size', 0))
            ratio = difflib.SequenceMatcher(None, r_, p_, autojunk=False).ratio()
            pl, rl = len(p_), len(r_)
    print('\t'.join([key, str(c['size_bytes']), c['name'], '%.3f' % ratio, str(pl), str(rl), conf, w, dm[:90], c['owner'], obj]))
    sys.stdout.flush()
