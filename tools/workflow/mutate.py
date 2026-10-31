#!/usr/bin/env python3
"""Random textual mutation search for near-miss C/C++ functions.

decomp-permuter cannot parse our C++ drafts, so this works on source lines:
it mutates only the body of the target function, scores each variant with
tools/check_match.py --json (number of differing instruction words), and
hill-climbs with plateau moves. Run it in WSL from the repo root, with the
compiler copied to a Linux path (CW38_DIR=~/cw/... gives ~0.2 s per check):

  .venv/bin/python tools/workflow/mutate.py draft.c --func loadingThread -c mw38 -j 16 --minutes 30

The best variant is written next to the draft as <draft>.best.c (and
<draft>.match.c on a full match). A match must still pass verify_pending.ps1.
"""
import argparse, concurrent.futures as cf, json, os, random, re, subprocess, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CHECK = ROOT / "tools" / "check_match.py"
BAD = 10 ** 6

TYPE = r"(?:const\s+|volatile\s+|register\s+|unsigned\s+|signed\s+|struct\s+|union\s+)*[A-Za-z_]\w*(?:\s*\*+\s*|\s+)"
DECL = re.compile(r"^(\s*)(" + TYPE + r")([A-Za-z_]\w*(?:\[[^\]]*\])?)(\s*(?:=.*)?;\s*)$")
OPND = r"[A-Za-z_][\w]*(?:\[[^\[\]]*\]|->\w+|\.\w+)*|\d[\w.]*"
COMM = re.compile(r"(?<![\w\]\)>.])(" + OPND + r")\s*(\+|\*|&|\||\^|==|!=)\s*(" + OPND + r")(?![\w\[(.]|->)")
CMP = re.compile(r"(?<![\w\]\)>.])(" + OPND + r")\s*(<=|>=|<|>)\s*(" + OPND + r")(?![\w\[(.]|->)")
FLIP = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}
CTRL = re.compile(r"^\s*(if|else|for|while|do|switch|case|default|return|break|continue|goto|\}|\{|#|//|/\*)")


def score(path, func, comps):
    try:
        r = subprocess.run([sys.executable, str(CHECK), str(path), "-c", comps, "--json"],
                           capture_output=True, text=True, cwd=ROOT, timeout=120)
        rep = json.loads(r.stdout[r.stdout.index("{"):])
    except Exception:
        return BAD
    best = BAD
    for c in rep.values():
        if not isinstance(c, dict):
            continue
        for f in c.get("functions", []):
            if f.get("name") != func:
                continue
            res = f.get("result", "")
            if res == "MATCH":
                return 0
            m = re.match(r"DIFF at (.*?)(?: \(\+(\d+)\))?$", res)
            if m:
                n = len(m.group(1).split(",")) + int(m.group(2) or 0)
                n += 50 * ("size" in m.group(1))
                best = min(best, n)
    return best


def body_range(lines, func):
    pat = re.compile(r"\b" + re.escape(func) + r"\s*\(")
    for i, l in enumerate(lines):
        if pat.search(l) and not l.rstrip().endswith(";"):
            depth, start = 0, None
            for j in range(i, len(lines)):
                depth += lines[j].count("{") - lines[j].count("}")
                if start is None and "{" in lines[j]:
                    start = j + 1
                if start is not None and depth == 0:
                    return start, j
    raise SystemExit(f"function {func} not found")


def simple(l):
    s = l.strip()
    return s.endswith(";") and not CTRL.match(l) and "{" not in s and "}" not in s


def indent(l):
    return len(l) - len(l.lstrip())


def mutate(lines, lo, hi, rng):
    L = list(lines)
    kind = rng.choice(["swap", "swap", "decl", "decl", "commute", "cmp", "register", "type", "sink"])
    idx = list(range(lo, hi))
    rng.shuffle(idx)
    if kind == "swap":
        for i in idx:
            if i + 1 < hi and simple(L[i]) and simple(L[i + 1]) and indent(L[i]) == indent(L[i + 1]):
                L[i], L[i + 1] = L[i + 1], L[i]
                return L, kind
    elif kind == "decl":
        for i in idx:
            if DECL.match(L[i]) and "=" not in L[i]:
                for j in (i - 1, i + 1):
                    if lo <= j < hi and DECL.match(L[j]) and indent(L[j]) == indent(L[i]):
                        L[i], L[j] = L[j], L[i]
                        return L, kind
    elif kind in ("commute", "cmp"):
        rx = COMM if kind == "commute" else CMP
        for i in idx:
            ms = list(rx.finditer(L[i]))
            if CTRL.match(L[i]) and not re.match(r"\s*(if|while|for|return)", L[i]):
                continue
            if ms:
                m = rng.choice(ms)
                op = m.group(2) if kind == "commute" else FLIP[m.group(2)]
                L[i] = L[i][:m.start()] + f"{m.group(3)} {op} {m.group(1)}" + L[i][m.end():]
                return L, kind
    elif kind == "register":
        for i in idx:
            m = DECL.match(L[i])
            if m:
                t = m.group(2)
                t = t.replace("register ", "", 1) if "register " in t else "register " + t
                L[i] = m.group(1) + t + m.group(3) + m.group(4)
                return L, kind
    elif kind == "type":
        swaps = [("unsigned int ", "int "), ("int ", "unsigned int "), ("short ", "int "),
                 ("unsigned char ", "int "), ("char ", "int "), ("int ", "short ")]
        for i in idx:
            m = DECL.match(L[i])
            if m and "*" not in m.group(2):
                a, b = rng.choice(swaps)
                t = m.group(2)
                if t.lstrip().startswith(a) or t.replace("register ", "").startswith(a):
                    L[i] = m.group(1) + t.replace(a, b, 1) + m.group(3) + m.group(4)
                    return L, kind
    elif kind == "sink":
        # move a simple statement one line past a neighbouring control line/brace
        for i in idx:
            if simple(L[i]):
                j = i + rng.choice((-1, 1))
                if lo <= j < hi and not DECL.match(L[i]) and L[j].strip() not in ("{", "}") \
                        and not re.match(r"\s*(else|case|default|return)", L[j]) and simple(L[j]) is False \
                        and L[j].strip().endswith(";"):
                    L[i], L[j] = L[j], L[i]
                    return L, kind
    return None, kind


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("source")
    ap.add_argument("--func", required=True)
    ap.add_argument("-c", "--compilers", default="mw38")
    ap.add_argument("-j", "--jobs", type=int, default=max(1, (os.cpu_count() or 2) - 2))
    ap.add_argument("--minutes", type=float, default=20)
    ap.add_argument("--seed", type=int, default=None)
    ap.add_argument("--plateau", type=float, default=0.3, help="chance to accept an equal score")
    a = ap.parse_args()
    rng = random.Random(a.seed)
    src = Path(a.source).resolve()
    tmpdir = src.parent / f".mut_{src.stem}_{os.getpid()}"
    tmpdir.mkdir(exist_ok=True)
    base = src.read_text().splitlines(keepends=True)
    cur = best = base
    cur_s = best_s = score(src, a.func, a.compilers)
    print(f"start {a.func}: {cur_s} differing words", flush=True)
    if cur_s >= BAD:
        raise SystemExit("baseline does not compile or the function was not found")
    deadline, n, it = time.time() + a.minutes * 60, 0, 0
    with cf.ThreadPoolExecutor(a.jobs) as ex:
        while time.time() < deadline and best_s:
            it += 1
            lo, hi = body_range(cur, a.func)
            cands = []
            for k in range(a.jobs):
                L, kinds = cur, []
                for _ in range(rng.choice((1, 1, 1, 2, 3))):
                    M, kind = mutate(L, lo, hi, rng)
                    if M is not None:
                        L = M; kinds.append(kind)
                if kinds:
                    p = tmpdir / f"m{k}.c"
                    p.write_text("".join(L))
                    cands.append((L, kinds, p))
            res = list(ex.map(lambda c: score(c[2], a.func, a.compilers), cands))
            n += len(cands)
            order = sorted(range(len(cands)), key=lambda k: res[k])
            if not order:
                continue
            k = order[0]
            s = res[k]
            if s < cur_s or (s == cur_s and rng.random() < a.plateau):
                cur, cur_s = cands[k][0], s
            if s < best_s:
                best, best_s = cands[k][0], s
                Path(str(src)[:-2] + ".best.c").write_text("".join(best))
                print(f"[{n} tried, {time.time() - deadline + a.minutes * 60:.0f}s] best {best_s} via {cands[k][1]}", flush=True)
            if it % 50 == 0 and cur_s > best_s and rng.random() < 0.2:
                cur, cur_s = best, best_s  # occasional restart from the best
    for p in tmpdir.glob("*"):
        p.unlink()
    tmpdir.rmdir()
    if best_s == 0:
        Path(str(src)[:-2] + ".match.c").write_text("".join(best))
        print("MATCH", flush=True)
    print(f"done: {n} variants, best {best_s}", flush=True)


if __name__ == "__main__":
    main()
