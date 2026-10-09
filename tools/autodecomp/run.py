#!/usr/bin/env python3
"""Automatic decompilation of simple functions, verified against the retail code.

Workflow (run from the repository root after `python configure.py && ninja`):

    python tools/autodecomp/run.py scan       # translate unmatched functions to C
    python tools/autodecomp/run.py verify     # compile them and keep byte-identical ones
    python tools/autodecomp/run.py integrate  # add them to src/main and config/splat.yaml
    python configure.py && ninja              # must still print OK

`scan` reads the split assembly in asm/ (only functions still in assembly,
starting and ending on 16-byte boundaries), translates each one with
straight.py (branch-free functions, expression form) or goto.py (any simple
function, one variable per register) and writes build/autodecomp/candidates.c.
`verify` compiles that file with the project's compiler and flags and
compares every function with the retail bytes (relocated fields masked);
byte-identical duplicates of verified leaf functions are added as clones.
`integrate` merges the verified functions into the matched units. The final
proof is always the byte-identical build.

Generated code is deliberately low-level; give it real types and names by hand.
"""
import argparse
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT))

import straight  # noqa: E402
import goto  # noqa: E402

OUT = ROOT / "build" / "autodecomp"
GLABEL = re.compile(r"^glabel (\S+)")
INSN = re.compile(r"^\s+/\* \S+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+(.*)")
BASE = 0x100000


def parse_asm(paths):
    funcs = []
    for p in paths:
        cur = None
        for line in p.read_text().splitlines():
            m = GLABEL.match(line)
            if m:
                cur = {"name": m.group(1), "ins": [], "file": p}
                funcs.append(cur)
                continue
            if line.startswith("endlabel"):
                cur = None
                continue
            m = INSN.match(line)
            if m and cur is not None:
                cur["ins"].append((int(m.group(1), 16), re.sub(r"\s+", " ", m.group(3).strip()).replace(" ,", ",")))
    funcs = [f for f in funcs if f["ins"]]
    for f in funcs:
        f["addr"] = f["ins"][0][0]
        # the spimdisasm text uses aligned columns; normalise to "op a, b"
        f["ins"] = [(a, re.sub(r"^(\S+)\s+", r"\1 ", x)) for a, x in f["ins"]]
    funcs.sort(key=lambda f: f["addr"])
    for a, b in zip(funcs, funcs[1:]):
        a["next"] = b["addr"]
    if funcs:
        funcs[-1]["next"] = None
    return funcs


def all_functions():
    asm = ROOT / "asm"
    chunk_files = sorted(p for p in asm.glob("*.s"))
    unit_files = []
    for d in ("main", "lib"):
        if (asm / d).exists():
            unit_files += sorted((asm / d).rglob("*.s"))
    every = parse_asm(chunk_files + unit_files)
    pending = {id(f) for f in every if f["file"].parent == asm}
    return every, pending


def text_end():
    return 0x476B00


def cmd_scan(args):
    every, pending = all_functions()
    arity_tab = {f["name"]: straight.arity(f["ins"]) for f in every}
    for f in every:
        straight.WR[f["name"]] = straight.writes(f["ins"])
    res = {}
    stats = {}
    for f in every:
        if id(f) not in pending or f["addr"] % 8 or not f["next"] or f["next"] % 8:
            continue
        if f["addr"] >= text_end() or len(f["ins"]) > args.max_insns:
            continue
        ops = [x.split()[0] for _, x in f["ins"]]
        branches = any(o.startswith("b") and o != "break" for o in ops)
        code = None
        if not branches:
            try:
                code, ext = straight.render(f["name"], f["ins"], arity_tab)
                refs = {t: line for t, line in ext}
                stats["straight"] = stats.get("straight", 0) + 1
            except straight.Unsupported:
                code = None
        if code is None:
            try:
                code, ex, ds = goto.translate(f["name"], f["ins"], arity_tab, straight.WR, straight.WR[f["name"]])
                refs = {}
                for t, (ni, nf, rk) in ex.items():
                    ps = ["int"] * ni + ["float"] * nf
                    refs[t] = f'extern {rk} {t}({", ".join(ps) if ps else "void"});'
                for d in ds:
                    if d.startswith("func_"):
                        ni, nf = arity_tab.get(d, (0, 0))
                        ps = ["int"] * ni + ["float"] * nf
                        refs[d] = f'extern {straight.WR.get(d, "int")} {d}({", ".join(ps) if ps else "void"});'
                    else:
                        refs[d] = f"extern char {d}[];"
                stats["goto"] = stats.get("goto", 0) + 1
            except (goto.Unsupported, KeyError, ValueError):
                continue
        res[f["name"]] = {"addr": f["addr"], "next": f["next"], "code": code, "refs": refs}
    OUT.mkdir(parents=True, exist_ok=True)
    # one compilation unit: unify declarations; candidates whose declarations
    # conflict with another candidate's definition are skipped
    sigs = {n: own_signature(c["code"], n) for n, c in res.items()}
    decls, drop = {}, set()
    for n, c in res.items():
        for t, line in c["refs"].items():
            if t in sigs and sigs[t] and norm(sigs[t]) != norm(line):
                drop.add(n)
                continue
            if t in decls and norm(decls[t]) != norm(line):
                drop.add(n)
                continue
            decls[t] = line
    for n, c in res.items():
        for t in c["refs"]:
            d = sigs.get(t) or decls.get(t, "")
            if d.startswith("extern void") and re.search(r"= " + re.escape(t) + r"\(", c["code"]):
                if t in sigs:
                    drop.add(n)
                else:
                    decls[t] = decls[t].replace("extern void", "extern int", 1)
    keep = {n: c for n, c in res.items() if n not in drop}
    for c in keep.values():
        c["refs"] = {t: decls.get(t, line) if t not in sigs else line for t, line in c["refs"].items()}
    with open(OUT / "candidates.c", "w") as fo:
        fo.write('typedef struct Q { float x, y, z, w; } __attribute__((aligned(16))) Q;\n\n')
        need = sorted({t for c in keep.values() for t in c["refs"]} - set(keep))
        for t in need:
            fo.write(decls[t] + "\n")
        for n in sorted(keep):
            if sigs[n]:
                fo.write(sigs[n] + "\n")
        fo.write("\n")
        for n in sorted(keep):
            fo.write(keep[n]["code"] + "\n")
    (OUT / "candidates.json").write_text(json.dumps(keep, indent=1))
    print(f"{len(keep)} candidates ({stats}) -> build/autodecomp/candidates.c")


def norm(s):
    return re.sub(r"\s+", "", s)


def own_signature(body, name):
    m = re.search(r"^(\w+(?:\s*\*)?)\s+" + re.escape(name) + r"\(([^)]*)\)", body, re.M)
    if not m:
        return None
    ps = [re.sub(r"\s*\w+$", "", p.strip()) for p in m.group(2).split(",") if p.strip() and p.strip() != "void"]
    return f'extern {m.group(1)} {name}({", ".join(ps) if ps else "void"});'


def compiler_command(kind):
    import configure  # noqa: F401  (constants only)
    if kind == "gcc":
        exe = ROOT / ".tools" / "eegcc" / configure.DEFAULT_GCC / "bin" / "ee-gcc.exe"
        flags = configure.GCCFLAGS.split()
    else:
        exe = ROOT / ".tools" / "mwcc" / configure.DEFAULT_COMPILER / "mwccps2.exe"
        flags = configure.CFLAGS.split() + ["-w", "off"]
    cmd = [str(exe)]
    if not configure.IS_WINDOWS:
        wibo = ROOT / ".tools" / "wibo"
        cmd = [str(wibo) if wibo.exists() else "wibo"] + cmd
    return cmd + flags


def cmd_verify(args):
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection

    cands = json.loads((OUT / "candidates.json").read_text())
    rom = (ROOT / "build" / "orig" / "SCUS_972.64.rom").read_bytes()
    ok = {}
    for kind in ("cc", "gcc"):
        obj = OUT / f"candidates_{kind}.o"
        if obj.exists():
            obj.unlink()
        r = subprocess.run(compiler_command(kind) + ["-o", obj.name, "candidates.c"],
                           capture_output=True, text=True, cwd=OUT)
        if not obj.exists():
            sys.exit(f"{kind} compile failed:\n" + r.stdout[-3000:] + r.stderr[-3000:])
        for n in compare(obj, cands, rom, ELFFile, RelocationSection):
            if n in ok:
                continue
            if kind == "cc" and cands[n]["addr"] % 16:
                continue
            ok[n] = dict(cands[n], compiler=kind)
    finish_verify(ok, cands, rom)


def compare(obj, cands, rom, ELFFile, RelocationSection):
    elf = ELFFile(open(obj, "rb"))
    masks = {}
    for sec in elf.iter_sections():
        if isinstance(sec, RelocationSection):
            for rel in sec.iter_relocations():
                masks[(sec["sh_info"], rel["r_offset"])] = 0xFC000000 if rel["r_info_type"] == 4 else 0xFFFF0000
    good = []
    for sym in elf.get_section_by_name(".symtab").iter_symbols():
        if sym["st_info"]["type"] != "STT_FUNC" or sym["st_shndx"] == "SHN_UNDEF" or sym.name not in cands:
            continue
        sec = elf.get_section(sym["st_shndx"])
        data = sec.data()[sym["st_value"]:sym["st_value"] + sym["st_size"]]
        a = cands[sym.name]["addr"] - BASE
        orig = rom[a:a + len(data)]
        same = len(orig) == len(data) and len(data) > 0
        for i in range(0, len(data) if same else 0, 4):
            w1, = struct.unpack_from("<I", data, i)
            w2, = struct.unpack_from("<I", orig, i)
            m = masks.get((sym["st_shndx"], sym["st_value"] + i), 0xFFFFFFFF)
            if (w1 & m) != (w2 & m):
                same = False
                break
        if same:
            good.append(sym.name)
    return good


def finish_verify(ok, cands, rom):
    # clones: unmatched leaf functions byte-identical to a verified leaf function
    every, pending = all_functions()
    lib = {}
    for n, c in ok.items():
        if not c["refs"]:
            size = c["next"] - c["addr"]
            lib.setdefault(rom[c["addr"] - BASE:c["addr"] - BASE + size], n)
    clones = 0
    for f in every:
        if id(f) not in pending or f["name"] in ok or f["addr"] % 8 or not f["next"] or f["next"] % 8:
            continue
        if any(x.split()[0] in ("jal", "j", "jalr", "lui") or "%" in x for _, x in f["ins"]):
            continue
        key = rom[f["addr"] - BASE:f["next"] - BASE]
        if key in lib:
            src = lib[key]
            if ok[src]["compiler"] == "cc" and f["addr"] % 16:
                continue
            ok[f["name"]] = dict(ok[src], addr=f["addr"], next=f["next"],
                                 code=re.sub(r"\b" + src + r"\b", f["name"], ok[src]["code"]))
            clones += 1
    (OUT / "verified.json").write_text(json.dumps(ok, indent=1))
    kinds = {k: sum(1 for c in ok.values() if c["compiler"] == k) for k in ("cc", "gcc")}
    print(f"verified {len(ok) - clones} of {len(cands)} candidates ({kinds} incl. clones), plus {clones} clones -> build/autodecomp/verified.json")


FUNC_START = re.compile(r"^[A-Za-z_][\w \t\*]*?\b(\w+)\(([^;{]*)\)\s*\{", re.M)


def read_units():
    """Return {address: (next, name, body, {ident: extern_line})} for all functions in src/main."""
    names = {}
    for line in (ROOT / "config" / "symbol_addrs.txt").read_text().splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
        if m:
            names[m.group(1)] = int(m.group(2), 16)
    units = {}
    paths = [(p, "cc") for p in sorted((ROOT / "src" / "main").rglob("*.c"))]
    paths += [(p, "gcc") for p in sorted((ROOT / "src" / "lib").rglob("*.c"))]
    for path, kind in paths:
        text = path.read_text()
        externs = {}
        for line in text.splitlines():
            if line.startswith("extern "):
                m = re.search(r"(\w+)(?:\(|\[)", line[7:])
                if m:
                    externs[m.group(1)] = line
        starts = list(FUNC_START.finditer(text))
        for i, m in enumerate(starts):
            name = m.group(1)
            # body runs to the matching closing brace
            depth, j = 0, text.index("{", m.start())
            while True:
                if text[j] == "{":
                    depth += 1
                elif text[j] == "}":
                    depth -= 1
                    if depth == 0:
                        break
                j += 1
            begin = m.start()
            # keep a comment or local declarations directly attached above the function
            prev_end = 0
            if i:
                prev_end = text.index("\n}\n", starts[i - 1].start()) + 3
            pre = text[prev_end:begin]
            keep_pre = "\n".join(l for l in pre.splitlines()
                                 if l and not l.startswith(("extern ", "#include", "/*", " *", " */")))
            body = (keep_pre + "\n\n" if keep_pre.strip() else "") + text[begin:j + 1] + "\n"
            addr = names.get(name) or (int(name[5:], 16) if re.fullmatch(r"func_[0-9A-F]{8}", name) else None)
            if addr is None:
                raise SystemExit(f"{path}: cannot resolve the address of {name}")
            refs = {t: l for t, l in externs.items() if re.search(r"\b" + t + r"\b", body)}
            units[addr] = [None, name, body, refs, kind]
    return units


HEADER = """/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
"""


def tu_ranges():
    path = ROOT / "config" / "tu_ranges.txt"
    out = []
    if path.exists():
        for line in path.read_text().splitlines():
            m = re.match(r"\s*(0x[0-9A-Fa-f]+)\s+(0x[0-9A-Fa-f]+)\s+(\S+)", line)
            if m:
                stem = re.sub(r"\.(cc|cpp|c)$", "", m.group(3))
                out.append((int(m.group(1), 16), int(m.group(2), 16), stem))
    return out


def cmd_integrate(args):
    ranges = tu_ranges()

    def tu_of(addr):
        for s, e, stem in ranges:
            if s <= addr <= e:
                return stem
        return None

    verified = json.loads((OUT / "verified.json").read_text())
    every, _ = all_functions()
    nexts = {f["addr"]: f["next"] for f in every}
    units = read_units()
    for addr, u in units.items():
        u[0] = nexts.get(addr)
        if u[0] is None:
            raise SystemExit(f"no function boundary after {u[1]} ({addr:#x}); run configure.py first")
    added = 0
    for n, c in verified.items():
        if c["addr"] not in units:
            units[c["addr"]] = [c["next"], n, c["code"], dict(c["refs"]), c.get("compiler", "cc")]
            added += 1
    # group adjacent functions with the same compiler and source file; start a
    # new unit where declarations would conflict inside one file
    def conflicts(group, addr):
        defined = {units[a][1]: a for a in group}
        defined[units[addr][1]] = addr
        chosen = {}
        for a in group + [addr]:
            for t, line in units[a][3].items():
                if t in defined:
                    own = own_signature(units[defined[t]][2], t)
                    if own is None or norm(own) != norm(line):
                        return True
                if t in chosen and norm(chosen[t]) != norm(line):
                    return True
                chosen[t] = line
        return False

    groups = []
    for addr in sorted(units):
        prev = groups[-1][-1] if groups else None
        if (prev is not None and units[prev][0] == addr and units[prev][4] == units[addr][4]
                and tu_of(prev) == tu_of(addr) and not conflicts(groups[-1], addr)):
            groups[-1].append(addr)
        else:
            groups.append([addr])
    bad = [g for g in groups if len(g) == 1 and conflicts([], g[0])]
    for g in bad:
        if units[g[0]][1] in verified:
            groups.remove(g)
            del units[g[0]]
            added -= 1
    for d in ("main", "lib"):
        (ROOT / "src" / d).mkdir(exist_ok=True)
        for p in (ROOT / "src" / d).rglob("*.c"):
            p.unlink()
    lines = ["      - [0x000000, asm]"]
    for g in groups:
        first = units[g[0]]
        fname = f"func_{g[0]:08X}"
        refs = {}
        for a in g:
            refs.update(units[a][3])
        ext = "".join(refs[t] + "\n" for t in sorted(refs))
        bodies = "\n".join(units[a][2] for a in g)
        sub = "lib" if first[4] == "gcc" else "main"
        tu = tu_of(g[0])
        if tu:
            sub = f"{sub}/{tu}"
            (ROOT / "src" / sub).mkdir(parents=True, exist_ok=True)
        (ROOT / "src" / sub / f"{fname}.c").write_text(HEADER + ("\n" + ext if ext else "") + "\n" + bodies)
        off = g[0] - BASE
        if lines[-1] == f"      - [0x{off:06X}, asm]":
            lines.pop()
        lines.append(f"      - [0x{off:06X}, c, {sub}/{fname}]")
        lines.append(f"      - [0x{units[g[-1]][0] - BASE:06X}, asm]")
    ypath = ROOT / "config" / "splat.yaml"
    y = ypath.read_text()
    head, rest = y.split("    subsegments:\n", 1)
    tail = rest[rest.index("      - [0x376B00, data, data]"):]
    if lines[-1] == "      - [0x376B00, asm]":
        lines.pop()
    ypath.write_text(head + "    subsegments:\n" + "\n".join(lines) + "\n" + tail)
    print(f"integrated {added} new functions into {len(groups)} units; now run configure.py and ninja")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("command", choices=["scan", "verify", "integrate"])
    ap.add_argument("--max-insns", type=int, default=200)
    args = ap.parse_args()
    {"scan": cmd_scan, "verify": cmd_verify, "integrate": cmd_integrate}[args.command](args)


if __name__ == "__main__":
    main()
