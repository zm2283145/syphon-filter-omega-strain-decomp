#!/usr/bin/env python3
"""Map retail functions to prototype functions.

usage: match.py [earlier|early ...]   -> cache/match_<proto>.pkl, <proto>/match.tsv
Stages (see README):
  1 anchors: unique normalised-hash matches (h0 exact-mod-addresses, h1 opcode+regs, h2 opcode)
  2 ordered chains of anchors; gaps between consecutive anchors aligned by DP (link-order / CU order)
  3 call-graph propagation (jal lists of matched pairs aligned) to fixpoint
  4 vtable slot alignment
  5 shared rare string references
Each pair gets a similarity (difflib ratio on opcode sequences) and a method tag.
"""
import sys, os, pickle, collections, difflib, struct, bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import *

MINI = 3  # functions shorter than this (instructions) never anchor on hash uniqueness alone


def ratio(a, b):
    if not a and not b:
        return 1.0
    la, lb = len(a), len(b)
    if min(la, lb) / max(la, lb) < 0.4:
        return min(la, lb) / max(la, lb) * 0.5
    if la * lb > 4_000_000:
        # n-gram approximation for very large functions
        ga = collections.Counter(zip(a, a[1:], a[2:])); gb = collections.Counter(zip(b, b[1:], b[2:]))
        inter = sum((ga & gb).values()); tot = max(sum(ga.values()), sum(gb.values()))
        return inter / tot if tot else 0
    return difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()


def hist_sim(ha, hb, la, lb):
    if la == 0 or lb == 0:
        return 1.0 if la == lb else 0.0
    if min(la, lb) / max(la, lb) < 0.5:
        return 0.0
    common = 0
    for k, v in ha.items():
        w = hb.get(k)
        if w:
            common += v if v < w else w
    return 2 * common / (la + lb)


class Matcher:
    def __init__(self, R, P):
        self.R, self.P = R, P
        self.r_by_addr = {f['addr']: i for i, f in enumerate(R)}
        self.p_by_addr = {f['addr']: i for i, f in enumerate(P)}
        self.r2p, self.p2r = {}, {}
        self.info = {}  # ri -> (method, sim)
        self.rhist = [collections.Counter(f['ops']) for f in R]
        self.phist = [collections.Counter(f['ops']) for f in P]
        self._rc = {}
        self.rejected = {}
        self.dmap = {}

    def sim(self, ri, pj):
        k = (ri, pj)
        if k not in self._rc:
            r, p = self.R[ri], self.P[pj]
            if r['h0'] == p['h0']: s = 1.0
            elif r['h1'] == p['h1']: s = 0.99
            elif r['h2'] == p['h2']: s = 0.97
            else: s = ratio(r['ops'], p['ops'])
            self._rc[k] = s
        return self._rc[k]

    def add(self, ri, pj, method, s=None):
        if ri in self.r2p or pj in self.p2r or (ri, pj) in self.rejected:
            return False
        if s is None:
            s = self.sim(ri, pj)
        self.r2p[ri] = pj; self.p2r[pj] = ri
        self.info[ri] = (method, s)
        return True

    # ---- stage 1 -----------------------------------------------------------
    def anchors(self):
        n = 0
        for key, tag in (('h0', 'hash-exact'), ('h1', 'hash-regs'), ('h2', 'hash-ops')):
            rc = collections.defaultdict(list); pc = collections.defaultdict(list)
            for i, f in enumerate(self.R):
                if i not in self.r2p: rc[f[key]].append(i)
            for j, f in enumerate(self.P):
                if j not in self.p2r: pc[f[key]].append(j)
            for h, ris in rc.items():
                pjs = pc.get(h)
                if pjs and len(ris) == 1 and len(pjs) == 1 and self.R[ris[0]]['ninsn'] >= MINI:
                    n += self.add(ris[0], pjs[0], tag)
        return n

    # ---- stage 2 -----------------------------------------------------------
    def chains(self, maxgap=400):
        """Consecutive matched pairs (in retail order) whose proto indices increase
        bound a gap that is aligned by DP."""
        pairs = sorted(self.r2p.items())
        added = 0
        for (r0, p0), (r1, p1) in zip(pairs, pairs[1:]):
            gr, gp = r1 - r0 - 1, p1 - p0 - 1
            if gr <= 0 or gp <= 0 or p1 <= p0 or gr > maxgap or gp > maxgap:
                continue
            ris = [i for i in range(r0 + 1, r1) if i not in self.r2p]
            pjs = [j for j in range(p0 + 1, p1) if j not in self.p2r]
            if not ris or not pjs:
                continue
            added += self.align(ris, pjs, 'order-gap')
        # leading/trailing edges of chains: extend runs outward while similar
        added += self.extend_runs()
        return added

    def align(self, ris, pjs, tag, thr=0.55):
        n, m = len(ris), len(pjs)
        if n == 1 and m == 1:
            s = self.sim(ris[0], pjs[0])
            if s >= thr:
                return self.add(ris[0], pjs[0], tag + '-1:1', s)
            return 0
        R, P = self.R, self.P
        S = [[0.0] * m for _ in range(n)]
        for a, ri in enumerate(ris):
            lr = R[ri]['ninsn']; hr = self.rhist[ri]
            for b, pj in enumerate(pjs):
                if R[ri]['h1'] == P[pj]['h1']:
                    S[a][b] = 1.0
                else:
                    S[a][b] = hist_sim(hr, self.phist[pj], lr, P[pj]['ninsn'])
        # DP: maximise sum(S - thr) over matched pairs, monotone
        D = [[0.0] * (m + 1) for _ in range(n + 1)]
        for a in range(1, n + 1):
            Sa = S[a - 1]; Da = D[a]; Dp = D[a - 1]
            for b in range(1, m + 1):
                v = Dp[b - 1] + Sa[b - 1] - thr
                x = Dp[b]; y = Da[b - 1]
                Da[b] = max(v, x, y)
        a, b, got = n, m, []
        while a > 0 and b > 0:
            if abs(D[a][b] - (D[a - 1][b - 1] + S[a - 1][b - 1] - thr)) < 1e-9 and S[a - 1][b - 1] > thr:
                got.append((ris[a - 1], pjs[b - 1])); a -= 1; b -= 1
            elif D[a][b] == D[a - 1][b]:
                a -= 1
            else:
                b -= 1
        c = 0
        for ri, pj in got:
            s = self.sim(ri, pj)
            if s >= thr - 0.1:
                c += self.add(ri, pj, tag, s)
        return c

    def extend_runs(self):
        c = 0
        changed = True
        while changed:
            changed = False
            for ri, pj in sorted(self.r2p.items()):
                for d in (1, -1):
                    a, b = ri + d, pj + d
                    while 0 <= a < len(self.R) and 0 <= b < len(self.P) and a not in self.r2p and b not in self.p2r:
                        s = self.sim(a, b)
                        if s < 0.6:
                            break
                        if not self.add(a, b, 'order-extend', s):
                            break
                        c += 1; changed = True
                        a += d; b += d
        return c

    # ---- stage 3 -----------------------------------------------------------
    def callgraph(self):
        c = 0
        for ri, pj in list(self.r2p.items()):
            rc = [self.r_by_addr.get(t) for t in self.R[ri]['calls']]
            pc = [self.p_by_addr.get(t) for t in self.P[pj]['calls']]
            rc = [x for x in rc if x is not None]; pc = [x for x in pc if x is not None]
            if not rc or not pc:
                continue
            # tokens: mapped callees compare equal via proto index
            rt = [('m', self.r2p[x]) if x in self.r2p else ('u', x) for x in rc]
            pt = [('m', x) if x in self.p2r else ('u', x) for x in pc]
            sm = difflib.SequenceMatcher(None, rt, pt, autojunk=False)
            for op, i1, i2, j1, j2 in sm.get_opcodes():
                if op == 'replace' and (i2 - i1) == (j2 - j1):
                    for k in range(i2 - i1):
                        a, b = rt[i1 + k], pt[j1 + k]
                        if a[0] == 'u' and b[0] == 'u' and a[1] not in self.r2p and b[1] not in self.p2r:
                            s = self.sim(a[1], b[1])
                            if s >= 0.6:
                                c += self.add(a[1], b[1], 'callgraph', s)
        return c

    # ---- stage 4 -----------------------------------------------------------
    def vtables(self, pvt, rblob, rbase):
        # retail word index: function-address words
        n = len(rblob) // 4
        words = struct.unpack_from('<%dI' % n, rblob[:n * 4])
        pos = collections.defaultdict(list)
        for i, w in enumerate(words):
            if w in self.r_by_addr:
                pos[w].append(rbase + i * 4)
        c = 0
        self.vt_map = {}
        for vname, (vaddr, ents) in pvt.items():
            votes = collections.Counter()
            for k, e in enumerate(ents):
                pj = self.p_by_addr.get(e)
                if pj is None or pj not in self.p2r:
                    continue
                ra = self.R[self.p2r[pj]]['addr']
                for p in pos.get(ra, ()):
                    votes[p - 4 * k] += 1
            if not votes:
                continue
            start, v = votes.most_common(1)[0]
            mapped = sum(1 for e in ents if self.p_by_addr.get(e) in self.p2r)
            if v < 2 or v < 0.6 * mapped:
                continue
            self.vt_map[vname] = (start, v, mapped, len(ents))
            for k, e in enumerate(ents):
                pj = self.p_by_addr.get(e)
                o = start - rbase + 4 * k
                if pj is None or o + 4 > len(rblob):
                    continue
                ri = self.r_by_addr.get(struct.unpack_from('<I', rblob, o)[0])
                if ri is None or ri in self.r2p or pj in self.p2r:
                    continue
                s = self.sim(ri, pj)
                if s >= 0.35:
                    c += self.add(ri, pj, 'vtable', s)
        return c

    # ---- stage 5 -----------------------------------------------------------
    def strings(self):
        rs = collections.defaultdict(set); ps = collections.defaultdict(set)
        for i, f in enumerate(self.R):
            for s in set(f['strs']): rs[s].add(i)
        for j, f in enumerate(self.P):
            for s in set(f['strs']): ps[s].add(j)
        votes = collections.defaultdict(collections.Counter)
        for s, ris in rs.items():
            pjs = ps.get(s)
            if not pjs or len(ris) > 2 or len(pjs) > 2 or len(s) < 6:
                continue
            for ri in ris:
                for pj in pjs:
                    votes[ri][pj] += 1
        c = 0
        for ri, cnt in votes.items():
            if ri in self.r2p:
                continue
            (pj, v), *rest = cnt.most_common(2) + [(None, 0)]
            if pj in self.p2r or (rest and rest[0][1] == v):
                continue
            s = self.sim(ri, pj)
            if s >= 0.3:
                c += self.add(ri, pj, 'strings', s)
        return c

    # ---- stage 6: ambiguous exact hashes resolved by neighbours ------------
    def ambiguous(self):
        """For a retail function whose h1 has several proto candidates, choose the
        candidate whose index is consistent with the nearest matched neighbours."""
        pc = collections.defaultdict(list)
        for j, f in enumerate(self.P):
            if j not in self.p2r: pc[f['h1']].append(j)
        pairs = sorted(self.r2p.items())
        rkeys = [p[0] for p in pairs]
        c = 0
        for i, f in enumerate(self.R):
            if i in self.r2p:
                continue
            cands = [j for j in pc.get(f['h1'], []) if j not in self.p2r]
            if not cands:
                continue
            k = bisect.bisect_left(rkeys, i)
            exp = []
            if k > 0: exp.append(pairs[k - 1][1] + (i - pairs[k - 1][0]))
            if k < len(pairs): exp.append(pairs[k][1] - (pairs[k][0] - i))
            best = None
            for j in cands:
                d = min(abs(j - e) for e in exp) if exp else 999
                if d <= 3 and (best is None or d < best[0]):
                    best = (d, j)
            if best:
                c += self.add(i, best[1], 'hash-neighbour', self.sim(i, best[1]))
        return c


    # ---- stage 7: data-reference correspondence + consistency ----------------
    def build_datamap(self):
        votes = collections.defaultdict(collections.Counter)
        for ri, pj in self.r2p.items():
            meth, s = self.info[ri]
            if s < 0.97:
                continue
            a, b = self.R[ri]['refs'], self.P[pj]['refs']
            if len(a) != len(b):
                continue
            for x, y in zip(a, b):
                votes[x][y] += 1
        dm = {}
        for x, c in votes.items():
            (y, v), *rest = c.most_common(2)
            if not rest or rest[0][1] * 3 < v:
                dm[x] = y
        self.dmap = dm
        self.pref_index = collections.defaultdict(set)
        for j, f in enumerate(self.P):
            for y in set(f['refs']):
                self.pref_index[y].add(j)
        return len(dm)

    def consistency(self, ri, pj):
        """(agree, disagree) over data refs and callees whose counterpart is known."""
        ag = dis = 0
        pr = set(self.P[pj]['refs'])
        for x in set(self.R[ri]['refs']):
            y = self.dmap.get(x)
            if y is None:
                continue
            if y in pr: ag += 1
            else: dis += 1
        pc = set(self.P[pj]['calls'])
        for t in set(self.R[ri]['calls']):
            k = self.r_by_addr.get(t)
            if k is None or k not in self.r2p:
                continue
            if self.P[self.r2p[k]]['addr'] in pc: ag += 1
            else: dis += 1
        return ag, dis

    def prune(self):
        """Drop matches whose data/call evidence contradicts them."""
        bad = []
        for ri, pj in list(self.r2p.items()):
            ag, dis = self.consistency(ri, pj)
            if dis >= 2 and dis > 2 * ag:
                bad.append(ri)
            elif dis >= 1 and ag == 0 and self.info[ri][0] not in ('hash-exact',) and self.R[ri]['ninsn'] < 40:
                bad.append(ri)
        for ri in bad:
            pj = self.r2p.pop(ri); self.p2r.pop(pj)
            self.rejected[(ri, pj)] = self.info.pop(ri)
        return len(bad)

    def by_data(self):
        c = 0
        for ri, f in enumerate(self.R):
            if ri in self.r2p:
                continue
            cnt = collections.Counter()
            for x in set(f['refs']):
                y = self.dmap.get(x)
                if y is None:
                    continue
                cands = self.pref_index.get(y, ())
                if len(cands) > 6:
                    continue
                for j in cands:
                    if j not in self.p2r:
                        cnt[j] += 1
            if not cnt:
                continue
            best = cnt.most_common(2)
            j, v = best[0]
            if len(best) > 1 and best[1][1] == v:
                # tie: pick by similarity if clearly better
                sims = sorted(((self.sim(ri, jj), jj) for jj, vv in best if vv == v), reverse=True)
                if sims[0][0] - sims[1][0] < 0.1:
                    continue
                j = sims[0][1]
            if (ri, j) in self.rejected:
                continue
            s = self.sim(ri, j)
            if s >= 0.5:
                c += self.add(ri, j, 'datarefs', s)
        return c

    # ---- stage 8: global fuzzy search over what is left -------------------
    def fuzzy_global(self, minlen=16):
        ur = [i for i in range(len(self.R)) if i not in self.r2p and self.R[i]['ninsn'] >= minlen]
        up = [j for j in range(len(self.P)) if j not in self.p2r and self.P[j]['ninsn'] >= minlen // 2]
        c = 0
        props = []
        for ri in ur:
            lr = self.R[ri]['ninsn']
            cands = []
            for pj in up:
                hs = hist_sim(self.rhist[ri], self.phist[pj], lr, self.P[pj]['ninsn'])
                if hs >= 0.7:
                    cands.append((hs, pj))
            cands.sort(reverse=True)
            scored = sorted(((self.sim(ri, pj), pj) for hs, pj in cands[:5]), reverse=True)
            if not scored or scored[0][0] < 0.7:
                continue
            if len(scored) > 1 and scored[0][0] - scored[1][0] < 0.08:
                continue
            props.append((scored[0][0], ri, scored[0][1]))
        for s, ri, pj in sorted(props, reverse=True):
            c += self.add(ri, pj, 'fuzzy-global', s)
        return c


def confidence(method, s, r, p):
    small = r['ninsn'] < 6
    if method.startswith('hash'):
        if method == 'hash-neighbour':
            return 'high' if not small else 'medium'
        return 'high' if (r['ninsn'] >= 8 or method == 'hash-exact') else 'medium'
    if method in ('order-gap-1:1', 'order-gap', 'order-extend', 'callgraph'):
        if s >= 0.97 and not small: return 'high'
        if s >= 0.80: return 'high' if r['ninsn'] >= 12 else 'medium'
        if s >= 0.60: return 'medium'
        return 'low'
    if method == 'vtable':
        if s >= 0.80: return 'high'
        if s >= 0.50: return 'medium'
        return 'low'
    if method == 'fuzzy-global':
        if s >= 0.92 and r['ninsn'] >= 30: return 'high'
        return 'medium' if s >= 0.75 else 'low'
    if method == 'datarefs':
        if s >= 0.8: return 'high'
        if s >= 0.5: return 'medium'
        return 'low'
    if method == 'strings':
        if s >= 0.70: return 'high'
        if s >= 0.40: return 'medium'
        return 'low'
    return 'low'


def run(which):
    R = pickle.load(open(os.path.join(CACHE, 'retail.pkl'), 'rb'))
    PD = pickle.load(open(os.path.join(CACHE, which + '.pkl'), 'rb'))
    m = Matcher(R['funcs'], PD['funcs'])
    log = []
    log.append(('anchors', m.anchors()))
    for it in range(8):
        a = m.chains(); b = m.callgraph(); c = m.vtables(PD['vtables'], R['blob'], R['base'])
        d = m.strings(); e = m.anchors(); f = m.ambiguous()
        m.build_datamap(); g = m.prune(); h = m.by_data()
        log.append(('iter%d' % it, a, b, c, d, e, f, 'pruned', g, 'data', h))
        print(which, log[-1], 'total', len(m.r2p), flush=True)
        if a + b + c + d + e + f + h == 0 and g == 0:
            break
    fg = m.fuzzy_global()
    m.build_datamap(); fp = m.prune()
    log.append(('fuzzy-global', fg, 'pruned', fp))
    print(which, log[-1], 'total', len(m.r2p), flush=True)
    out = {}
    for ri, pj in m.r2p.items():
        meth, s = m.info[ri]
        r, p = m.R[ri], m.P[pj]
        ag, dis = m.consistency(ri, pj)
        conf = confidence(meth, s, r, p)
        if dis > ag and conf == 'high':
            conf = 'medium'
        elif conf == 'medium' and ag >= 2 and dis == 0 and s >= 0.6:
            conf = 'high'
        out[r['addr']] = dict(paddr=p['addr'], pname=p['name'], pdem=p['dem'], method=meth, sim=round(s, 3),
                              conf=conf, agree=ag, disagree=dis, obj=p.get('obj', ''), src=p.get('src', ''))
    pickle.dump(dict(map=out, log=log, vt=getattr(m, 'vt_map', {})), open(os.path.join(CACHE, 'match_%s.pkl' % which), 'wb'))
    return out


if __name__ == '__main__':
    for w in sys.argv[1:] or ['early', 'earlier']:
        run(w)
