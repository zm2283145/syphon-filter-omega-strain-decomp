#!/usr/bin/env python3
"""Integrate hand-matched single-function C files into the splat layout.

usage: python tools/integrate_pending.py REPO PENDING_DIR

Files are named <KIND>_<ADDR>.c, KIND being the compiler the match was made
with: mw (3.0.3, the default), mw304, mw38, mw50, gcc (2.95.3), gcc296,
gcc296g0 or gcc29 (a bare <ADDR>.c is 2.95.3). Metrowerks files go to
src/main/<tu>/func_<ADDR>.c, EE-GCC ones to src/lib/...; kinds other than the
defaults get an entry in config/compiler_overrides.json.

Data: a file may define its own data (string literals, float tables, switch
jump tables, initialised globals). Such a file is compiled (CW304_DIR,
CW38_DIR and CW50_DIR name the licensed Metrowerks installs, as for
check_match.py), its data block (all its data sections in object order) is placed
with check_match.data_pieces and must MATCH the retail bytes. The block is
then cut out of the asm data segment that holds it and becomes a
`[ROM, .rodata, unit]` (or .data) subsegment of the unit, so the build links
it from C (docs/data_split.md). A file whose data does not match, cannot be
placed or does not lie inside one asm data segment is skipped with the reason.
EE-GCC 2.96 float/double constants (.lit4/.lit8, gp-relative) are not cut
out: they live in the retail linker's shared literal pool, which stays where
it is; each one must equal the pool entry its retail load uses
(check_match.pooled_literals), and the build points the loads at those
entries (tools/lit_pool.py).

Functions inside the static-initialiser island (asm segments named sinit_*)
become main/sinit/func_<ADDR> units, as with integrate_island.py.

A file for a function that is already a C unit replaces that unit's source
when it brings data the unit does not link yet (an extern D_ symbol turned
back into the literal or table it stands for); otherwise it is skipped. If
the unit links a data block already, the new block must contain it; it grows
into the unnamed asm data next to it.
"""
import json
import os
import re
import sys
from pathlib import Path

BASE = 0x100000
OVR = {"mw304": "cwps2-3.04", "mw38": "cwps2-3.0b38", "mw50": "cwps2-3.0b50", "gcc296": "ee-gcc2.96",
       "gcc296g0": "ee-gcc2.96-G0", "gcc29": "ee-gcc2.9-991111"}
MW_KINDS = ("mw", "mw304", "mw38", "mw50")
PIECE_TYPES = (".data", ".rodata", ".sdata")  # configure.DATA_PIECE_TYPES
SEG = re.compile(r"(\s*)- \[0x([0-9A-F]+), ([.\w]+)(?:, ([^\]]+))?\]\s*$")


def load_segments(lines):
    """Parse the main segment's subsegments.

    Returns (first, last, segs, indent): lines[first:last] are the
    subsegment lines, segs = [[start, type, name, comment_lines]] (comment
    lines are kept in front of the subsegment that follows them)."""
    first = lines.index("    subsegments:") + 1
    segs, pending, indent = [], [], None
    last = first
    for i in range(first, len(lines)):
        l = lines[i]
        if l.strip().startswith("#"):
            pending.append(l); continue
        m = SEG.match(l)
        if not m or (indent is not None and m.group(1) != indent):
            last = i; break
        indent = m.group(1)
        segs.append([int(m.group(2), 16), m.group(3), m.group(4), pending]); pending = []
    else:
        sys.exit("config/splat.yaml: no end of the subsegment list")
    if pending:
        sys.exit("config/splat.yaml: comment after the last subsegment")
    return first, last, segs, indent


def end_of_segments(lines, last):
    m = re.match(r"\s*- \[0x([0-9A-Fa-f]+)\]", lines[last])
    if not m:
        sys.exit(f"config/splat.yaml: unexpected line after the subsegments: {lines[last]!r}")
    return int(m.group(1), 16)


def dump_segments(segs, indent):
    """Subsegment lines for segs (the inverse of load_segments)."""
    out = []
    for s, t, n, comments in segs:
        out += comments
        out.append(f"{indent}- [0x{s:06X}, {t}" + (f", {n}]" if n else "]"))
    return out


def find(segs, off):
    return max(i for i, s in enumerate(segs) if s[0] <= off)


def main():
    repo, pend = Path(sys.argv[1]).resolve(), Path(sys.argv[2])
    sys.path.insert(0, str(repo / "tools"))
    import check_match  # noqa: E402  (needs the repository's tools/ on sys.path)
    from elftools.elf.elffile import ELFFile

    a2n = {}
    for l in (repo / "config/symbol_addrs.txt").read_text().splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;", l)
        if m:
            a2n.setdefault(int(m.group(2), 16), m.group(1))

    # function sizes from splat's asm segment files
    size = {}
    for f in (repo / "asm").glob("*.s"):
        want = None
        for l in f.read_text(errors="replace").splitlines():
            m = re.match(r"nonmatching (\S+), (0x[0-9A-Fa-f]+)", l)
            if m:
                want = int(m.group(2), 16); continue
            if want is not None:
                m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ", l)
                if m:
                    size[int(m.group(1), 16)] = want; want = None

    ranges = []
    for l in (repo / "config/tu_ranges.txt").read_text().splitlines():
        if l.startswith("#") or not l.strip():
            continue
        s, e, n = l.split()[:3]
        ranges.append((int(s, 16), int(e, 16), n.rstrip("?").rsplit(".", 1)[0]))

    def tu_of(a):
        for s, e, n in ranges:
            if s <= a <= e:
                return n

    yp = repo / "config/splat.yaml"
    y = yp.read_text().split("\n")
    i0, i1, segs, indent = load_segments(y)
    end_off = end_of_segments(y, i1)
    nxt_of = lambda k: segs[k + 1][0] if k + 1 < len(segs) else end_off

    op = repo / "config/compiler_overrides.json"
    overrides = json.loads(op.read_text()) if op.exists() else {}
    sym = re.compile(r"\b(func|D)_([0-9A-F]{8})\b")
    rom = names = None
    dirs = {"mw304": os.environ.get("CW304_DIR"), "mw38": os.environ.get("CW38_DIR"),
            "mw50": os.environ.get("CW50_DIR")}
    incs = [f"-I{repo / d}" for d in ("include", "src")]
    added, skipped = [], []
    for f in sorted(pend.glob("*.c")):
        kind, _, hexa = f.stem.rpartition("_")
        kind = kind or "gcc"
        mw = kind in MW_KINDS
        try:
            a = int(hexa, 16)
        except ValueError:
            skipped.append((f.name, "not <KIND>_<ADDR>.c")); continue
        A = a - BASE
        k = find(segs, A)
        existing = segs[k][0] == A and segs[k][1] == "c"
        if existing:
            # a matched unit that now brings its data
            path = segs[k][2]
            if path.startswith("main/") != mw:
                skipped.append((f.name, f"compiler kind does not fit unit {path}")); continue
            have = any(n == path and t.startswith(".") for _, t, n, _ in segs)
        else:
            if a not in size:
                skipped.append((f.name, "no function start in asm (already split?)")); continue
            E = A + size[a]
            if segs[k][1] != "asm" or E > nxt_of(k):
                skipped.append((f.name, f"segment {segs[k][:3]}")); continue
            if (segs[k][2] or "").startswith("sinit_"):
                if not mw:
                    skipped.append((f.name, "static initialiser island takes Metrowerks files only")); continue
                path = f"main/sinit/func_{a:08X}"
            else:
                tu = tu_of(a)
                path = ("main" if mw else "lib") + (f"/{tu}" if tu else "") + f"/func_{a:08X}"
        dst = repo / "src" / (path + ".c")
        if dst.exists() and not existing:
            skipped.append((f.name, "exists")); continue

        # data the file defines itself
        if rom is None:
            rom = (repo / "build" / "orig" / "SCUS_972.64.rom").read_bytes()
            names, _ = check_match.symbols()
        obj, err = check_match.compile_with(kind, f.resolve(), incs, dirs)
        if obj is None:
            skipped.append((f.name, "compile error: " + err.splitlines()[-1] if err else "compile error")); continue
        try:
            with open(obj, "rb") as fh:
                pieces = check_match.data_pieces(ELFFile(fh), rom, names)
            lits = check_match.pooled_literals(obj, rom, names)
        finally:
            os.unlink(obj)
        bad = [f"{p['section']}: {p['result']}" for p in pieces if p["result"] != "MATCH"]
        bad += [f"{p['section']} literal {p['start'] or 0:08X}: {p['result']}" for p in lits if p["result"] != "MATCH"]
        bad += [f"{p['section']}: not linkable from C yet" for p in pieces if p["section"] not in PIECE_TYPES]
        if bad:
            skipped.append((f.name, "data " + "; ".join(bad))); continue
        saved = None
        if existing:
            if not pieces:
                skipped.append((f.name, "exists (and brings no data)")); continue
            if have:
                # The unit's block grows: give its old subsegment back to the
                # asm data, merged with the unnamed data around it, and cut
                # the new (larger) block out of that below. Undone if the new
                # block does not fit.
                d = next(j for j, s in enumerate(segs) if s[2] == path and s[1].startswith("."))
                os_, oe = segs[d][0], nxt_of(d)
                R, RE = pieces[0]["start"] - BASE, pieces[0]["start"] - BASE + pieces[0]["size"]
                if (R, RE, pieces[0]["section"]) == (os_, oe, segs[d][1]):
                    skipped.append((f.name, "exists (its data is linked from C already)")); continue
                if not (R <= os_ and RE >= oe):
                    skipped.append((f.name, f"data {R + BASE:08X}+{RE - R:#x} does not contain the linked "
                                            f"block {os_ + BASE:08X}+{oe - os_:#x}")); continue
                saved = [list(s) for s in segs]
                segs[d] = [os_, "data", None, segs[d][3]]
                while d + 1 < len(segs) and segs[d + 1][1] == "data" and segs[d + 1][2] is None \
                        and segs[d + 1][0] < RE:
                    segs[d][3] += segs[d + 1][3]; del segs[d + 1]
                if R < os_ and d > 0 and segs[d - 1][1] == "data":
                    segs[d - 1][3] += segs[d][3]; del segs[d]
        cuts = []
        for p in pieces:
            R, RE = p["start"] - BASE, p["start"] - BASE + p["size"]
            j = find(segs, R)
            if segs[j][1] != "data" or RE > nxt_of(j):
                bad.append(f"{p['section']} {p['start']:08X}+{p['size']:#x} not inside one asm data segment "
                           f"({segs[j][:3]})")
            cuts.append((R, RE, p["section"]))
        if bad:
            if saved is not None:
                segs[:] = saved
            skipped.append((f.name, "data " + "; ".join(bad))); continue

        text = f.read_text()
        text = sym.sub(lambda m: a2n.get(int(m.group(2), 16), m.group(0)), text)
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_text(text, newline="\n")
        for start, stop, typ in ([] if existing else [(A, E, "c")]) + cuts:
            j = find(segs, start)
            old = segs[j]
            stop_at = nxt_of(j)
            new = []
            if start > old[0]:
                new.append(old)
            new.append([start, typ, path, [] if start > old[0] else old[3]])
            if stop < stop_at:
                rest = f"sinit_{stop + BASE:X}" if (old[2] or "").startswith("sinit_") else None
                new.append([stop, old[1], rest, []])
            segs[j:j + 1] = new
        added.append((f.name, path, 0 if existing else size[a],
                      " ".join(f"{t}@{s + BASE:08X}+{e - s:#x}" for s, e, t in cuts)))
        if kind in OVR:
            overrides[path] = OVR[kind]
        else:
            overrides.pop(path, None)

    # A new unit ends at its last instruction; the alignment padding after it
    # would open the next asm subsegment as a one-nop "function". Fold it into
    # the unit (tools/fold_padding.py; also repairs older layouts).
    import fold_padding  # noqa: E402  (tools/ is on sys.path)
    if rom is None:
        rom = (repo / "build" / "orig" / "SCUS_972.64.rom").read_bytes()
    segs, folded = fold_padding.fold(segs, end_off, rom)
    y[i0:i1] = dump_segments(segs, indent)
    yp.write_text("\n".join(y), newline="\n")
    op.write_text(json.dumps(overrides, indent=2) + "\n", newline="\n")
    print("added", len(added), "bytes", sum(x[2] for x in added))
    for x in added:
        print("  +", *[v for v in x if v != ""])
    if folded:
        print("folded padding at", len(folded), "subsegment starts")
    print("skipped", len(skipped))
    for x in skipped:
        print("  -", *x)


if __name__ == "__main__":
    main()