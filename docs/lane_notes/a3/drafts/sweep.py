#!/usr/bin/env python3
"""sweep.py TEMPLATE FUNC START END [--rand N] [--keep K]
Template choice points: {{a|b|c}} (each independent). Optional named groups {{#name:a|b}}
share the same index for all points with the same name. Enumerates all combos (or N random),
scores with P4L lab.py, prints best. Writes best to TEMPLATE.best.c"""
import sys, re, itertools, random, subprocess, os, tempfile
ROOT = str(__import__("pathlib").Path(__file__).resolve().parents[4])  # repo root
LAB = [ROOT + "/.venv/bin/python", ROOT + "/build/agents/P4L/tools/lab.py"]
tpl_path, func, lo, hi = sys.argv[1:5]
args = sys.argv[5:]
nrand = int(args[args.index("--rand") + 1]) if "--rand" in args else 0
keep = int(args[args.index("--keep") + 1]) if "--keep" in args else 8
tpl = open(tpl_path).read()
pts = list(re.finditer(r"(?:\{\{|<<<)(#(\w+):)?(.*?)(?:\}\}|>>>)", tpl, re.S))
groups = []  # list of (name, nopts)
ptgroup = []
for m in pts:
    name = m.group(2)
    opts = m.group(3).split("@@") if "@@" in m.group(3) else m.group(3).split("|")
    if name:
        idx = next((i for i, g in enumerate(groups) if g[0] == name), None)
        if idx is None:
            groups.append((name, len(opts))); idx = len(groups) - 1
    else:
        groups.append((None, len(opts))); idx = len(groups) - 1
    ptgroup.append((idx, opts))
def render(combo):
    out = []; last = 0
    for m, (gi, opts) in zip(pts, ptgroup):
        out.append(tpl[last:m.start()]); out.append(opts[combo[gi]]); last = m.end()
    out.append(tpl[last:]); return "".join(out)
sizes = [g[1] for g in groups]
total = 1
for s in sizes: total *= s
combos = itertools.product(*[range(s) for s in sizes]) if not nrand or nrand >= total else (tuple(random.randrange(s) for s in sizes) for _ in range(nrand))
res = []
tmp = tempfile.mktemp(suffix=".c", dir=os.path.dirname(os.path.abspath(tpl_path)))
for c in combos:
    open(tmp, "w").write(render(c))
    r = subprocess.run(LAB + [tmp, func, lo, hi], capture_output=True, text=True).stdout
    m = re.search(r"diff (\d+)", r)
    sc = int(m.group(1)) if m else 9999
    mm = re.search(r"retail (\d+) mine (\d+)", r)
    res.append((sc, c, mm.group(0) if mm else r.strip()[-80:]))
os.unlink(tmp)
res.sort()
print("combos", len(res), "groups", sizes)
for sc, c, info in res[:keep]: print(sc, c, info)
open(tpl_path + ".best.c", "w").write(render(res[0][1]))
