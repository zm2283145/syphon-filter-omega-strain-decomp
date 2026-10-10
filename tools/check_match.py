#!/usr/bin/env python3
"""Compile a C file and report, per function, whether it matches the retail code.

usage: python tools/check_match.py FILE.c [-c mw,mw304,gcc] [-I DIR ...]

Run from the repository root after a configure + build (it reads
build/orig/SCUS_972.64.rom and splat's asm/). Each compiler in -c is tried in
turn and every function is reported per compiler, so one run shows which
compiler (if any) produces the retail bytes:

  mw     Metrowerks mwccps2 3.0.3 (.tools/mwcc/mwcps2-3.0.3-020716), the default
  mw304  a licensed CodeWarrior 3.04 install (build 22): --cw304 DIR or the
         CW304_DIR environment variable (its PS2_Tools/Command_Line_Tools dir)
  gcc    EE-GCC 2.95.3 (-O2 -G0), for library code under src/lib/

Relocated fields are masked, then call targets and %hi/%lo pairs are checked
against the retail addresses (template clones are not interchangeable).
Symbols are resolved through config/symbol_addrs.txt and splat's labels.
Nothing derived from the game is written anywhere except build/.
"""
import argparse, json, os, re, shutil, struct, subprocess, sys, tempfile
from pathlib import Path
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x100000
IS_WINDOWS = os.name == "nt"
MWFLAGS = ["-c", "-O4,p", "-nostdinc", "-sdatathreshold", "0", "-char", "signed", "-lang", "c"]
GCCFLAGS = ["-c", "-O2", "-G0", "-w"]


def symbols():
    """address <-> name maps and the set of function starts, cached per split."""
    cache = ROOT / "build" / "check_symbols.json"
    stamp = ROOT / "build" / "splat.stamp"
    key = (stamp.read_text() if stamp.exists() else "") + str((ROOT / "config/symbol_addrs.txt").stat().st_mtime)
    if cache.exists():
        c = json.loads(cache.read_text())
        if c.get("key") == key:
            return {k: v for k, v in c["names"].items()}, set(c["starts"])
    names, starts = {}, set()
    lab = re.compile(r"(?:glabel|nonmatching) (\w+)")
    ins = re.compile(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ")
    for f in (ROOT / "asm").rglob("*.s"):
        if "data" in f.parts:
            continue
        pending = None
        for l in f.read_text(errors="replace").splitlines():
            m = lab.match(l)
            if m:
                pending = m.group(1); continue
            if pending:
                m = ins.match(l)
                if m:
                    a = int(m.group(1), 16)
                    names[pending] = a; starts.add(a); pending = None
    for l in (ROOT / "config/symbol_addrs.txt").read_text().splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;", l)
        if m:
            names[m.group(1)] = int(m.group(2), 16)
    cache.write_text(json.dumps({"key": key, "names": names, "starts": sorted(starts)}))
    return names, starts


def wrapper():
    if IS_WINDOWS:
        return []
    w = ROOT / ".tools" / "wibo"
    return [str(w)] if w.exists() else [shutil.which("wibo") or shutil.which("wine") or "wibo"]


def compile_with(kind, src, incs, dirs):
    if kind == "mw":
        cc = ROOT / ".tools" / "mwcc" / "mwcps2-3.0.3-020716" / "mwccps2.exe"; flags = MWFLAGS
    elif kind in dirs:
        if not dirs[kind]:
            return None, f"no directory for {kind} (--cw{kind[2:]} or CW{kind[2:].upper()}_DIR)"
        cc = Path(dirs[kind]) / "mwccps2.exe"; flags = MWFLAGS
    elif kind == "gcc":
        cc = ROOT / ".tools" / "eegcc" / "ee-gcc2.95.3-136" / "bin" / "ee-gcc.exe"; flags = GCCFLAGS
    else:
        return None, f"unknown compiler {kind}"
    fd, out = tempfile.mkstemp(suffix=".o", dir=ROOT / "build"); os.close(fd); os.unlink(out)
    r = subprocess.run(wrapper() + [str(cc)] + flags + incs + ["-o", out, str(src)],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode or not os.path.exists(out):
        if os.path.exists(out):
            os.unlink(out)
        return None, (r.stdout[-3000:] + r.stderr[-1500:]).strip()
    return out, None


def compare(obj, rom, names, starts):
    byaddr = {}
    for n, a in names.items():
        byaddr.setdefault(a, n)
    results, undef = [], []
    with open(obj, "rb") as fh:
        e = ELFFile(fh)
        symtab = e.get_section_by_name(".symtab")
        masks, relinfo = {}, {}
        for sec in e.iter_sections():
            if isinstance(sec, RelocationSection):
                rels = list(sec.iter_relocations())
                for j, rel in enumerate(rels):
                    t = rel["r_info_type"]
                    masks[(sec["sh_info"], rel["r_offset"])] = 0xFC000000 if t == 4 else 0xFFFF0000
                    relinfo[(sec["sh_info"], rel["r_offset"])] = (t, symtab.get_symbol(rel["r_info_sym"]), j, rels)

        def symaddr(sym):
            if sym.name in names:
                return names[sym.name]
            m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})", sym.name)
            return int(m.group(1), 16) if m else None

        for s in symtab.iter_symbols():
            if s["st_info"]["type"] != "STT_FUNC" or s["st_shndx"] == "SHN_UNDEF":
                continue
            n = s.name
            a = names.get(n)
            if a is None and re.fullmatch(r"func_[0-9A-F]{8}", n):
                a = int(n[5:], 16)
            if a is None:
                results.append((n, None, "unknown address")); continue
            sec = e.get_section(s["st_shndx"])
            sdata = sec.data()
            data = sdata[s["st_value"]:s["st_value"] + s["st_size"]]
            orig = rom[a - BASE:a - BASE + len(data)]
            nxt = min((x for x in starts if x > a), default=None)
            bad = []
            if nxt is not None and a + len(data) != nxt and a + len(data) < nxt:
                # shorter than the retail function: only alignment nops may follow
                tail = rom[a + len(data) - BASE:nxt - BASE]
                if any(tail) or len(tail) >= 16:
                    bad.append(f"size {len(data):#x} vs {nxt - a:#x}")
            elif nxt is not None and a + len(data) > nxt:
                bad.append(f"size {len(data):#x} vs {nxt - a:#x}")
            for k in range(0, len(data), 4):
                w1, = struct.unpack_from("<I", data, k)
                w2, = struct.unpack_from("<I", orig, k)
                m = masks.get((s["st_shndx"], s["st_value"] + k), 0xFFFFFFFF)
                if (w1 & m) != (w2 & m):
                    bad.append(hex(k)); continue
                ri = relinfo.get((s["st_shndx"], s["st_value"] + k))
                if not ri:
                    continue
                t, sym, j, rels = ri
                sa = symaddr(sym)
                if sa is None:
                    continue
                if t == 4:
                    if (((w2 & 0x3FFFFFF) << 2) | ((a + k) & 0xF0000000)) != sa + ((w1 & 0x3FFFFFF) << 2):
                        bad.append(f"{k:#x}(call {sym.name})")
                elif t == 5:
                    lo = next((r for r in rels[j + 1:] if r["r_info_type"] == 6
                               and r["r_info_sym"] == rels[j]["r_info_sym"]), None)
                    if lo is None:
                        continue
                    lw, = struct.unpack_from("<I", sdata, lo["r_offset"])
                    full = sa + ((w1 & 0xFFFF) << 16) + (((lw & 0xFFFF) ^ 0x8000) - 0x8000)
                    if ((full + 0x8000) >> 16) & 0xFFFF != (w2 & 0xFFFF):
                        bad.append(f"{k:#x}(hi {sym.name})")
                    lo_off = lo["r_offset"] - s["st_value"]
                    if 0 <= lo_off < len(orig):
                        rw, = struct.unpack_from("<I", orig, lo_off)
                        if (rw & 0xFFFF) != (full & 0xFFFF):
                            bad.append(f"{lo_off:#x}(lo {sym.name})")
            results.append((n, a, "MATCH" if not bad else "DIFF at " + ",".join(bad[:6])
                            + (f" (+{len(bad) - 6})" if len(bad) > 6 else "")))
        for s in symtab.iter_symbols():
            if s["st_shndx"] != "SHN_UNDEF" or not s.name or s.name in names:
                continue
            m = re.fullmatch(r"func_([0-9A-F]{8})", s.name)
            if m:
                a = int(m.group(1), 16)
                if a in starts and a not in byaddr:
                    continue
                undef.append(f"{s.name}: " + (f"named {byaddr[a]}" if a in byaddr else "not a function start"))
            elif not re.fullmatch(r"D_[0-9A-F]{8}", s.name):
                undef.append(f"{s.name}: unknown symbol")
    return results, undef


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("source")
    ap.add_argument("-c", "--compilers", default="mw", help="comma list of mw, mw304, gcc (default mw)")
    ap.add_argument("-I", dest="incs", action="append", default=[])
    ap.add_argument("--cw304", default=os.environ.get("CW304_DIR"))
    ap.add_argument("--json", action="store_true", help="print one JSON object instead of text")
    args = ap.parse_args()
    rom = (ROOT / "build" / "orig" / "SCUS_972.64.rom").read_bytes()
    names, starts = symbols()
    incs = [f"-I{d}" for d in args.incs + ["include", "src"]]
    report = {}
    for kind in args.compilers.split(","):
        obj, err = compile_with(kind, Path(args.source).resolve(), incs,
                                {"mw304": args.cw304})
        if obj is None:
            report[kind] = {"error": err}
        else:
            try:
                res, undef = compare(obj, rom, names, starts)
            finally:
                os.unlink(obj)
            report[kind] = {"functions": [{"name": n, "addr": f"{a:08X}" if a else None, "result": r}
                                          for n, a, r in res], "undefined": undef}
    if args.json:
        print(json.dumps(report)); return
    for kind, r in report.items():
        if "error" in r:
            print(f"[{kind}] COMPILE ERROR\n{r['error']}"); continue
        for f in r["functions"]:
            print(f"[{kind}] {f['name']}: {f['result']}")
        for u in r["undefined"]:
            print(f"[{kind}] UNDEF {u}")


if __name__ == "__main__":
    main()
