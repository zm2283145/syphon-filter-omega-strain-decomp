#!/usr/bin/env python3
"""Compile a C file and report, per function, whether it matches the retail code.

usage: python tools/check_match.py FILE.c [-c mw,mw304,mw38,mw50,gcc,gcc296,gcc296g0,gcc29,gcc29as296] [-I DIR ...]

Run from the repository root after a configure + build (it reads
build/orig/SCUS_972.64.rom and splat's asm/). Each compiler in -c is tried in
turn and every function is reported per compiler, so one run shows which
compiler (if any) produces the retail bytes:

  mw     Metrowerks mwccps2 3.0.3 (.tools/mwcc/mwcps2-3.0.3-020716), the default
  mw304  a licensed CodeWarrior 3.04 install (build 22): --cw304 DIR or the
         CW304_DIR environment variable (its PS2_Tools/Command_Line_Tools dir)
  mw38   CodeWarrior PS2 3.0 build 38 (2003-03-07): --cw38 DIR or CW38_DIR
  mw50   CodeWarrior PS2 3.0 build 50 (2003-05-27): --cw50 DIR or CW50_DIR
  gcc    EE-GCC 2.95.3 (-O2 -G0), for library code under src/lib/
  gcc296 EE-GCC 2.96 (-O2), Linux build; through WSL on Windows
  gcc296g0 the same with -G0 (no gp-relative data), as used by part of the library
  gcc29  EE-GCC 2.9-ee-991111 (-O2 -G0), the older SCE SDK code (s-registers saved 16 bytes apart); through WSL
  gcc29as296 the 991111 compiler with the EE-GCC 2.96 assembler (.tools/eegcc/ee-gcc2.9-991111-as296),
         for SDK objects whose delay slots were filled by the newer gas (libcdvd sceCdRead, ...)

Relocated fields are masked, then call targets and %hi/%lo pairs are checked
against the retail addresses (template clones are not interchangeable).

Data the file defines itself (string literals, float tables, switch jump
tables, initialised globals) is checked too: the %hi/%lo pairs that load it
give its retail address, the per-entity sections are laid out the way the
build merges them (tools/data_obj.py) and the bytes and relocations are
compared with the retail data. The data forms one block in object order:

  [mw38] DATA .rodata 0x004BE4B0 size 0x18: MATCH

A file with data is a match only if every DATA line says MATCH; the
integrator then links the data from C (docs/data_split.md).

EE-GCC 2.96 (gcc296, -G8) puts float/double constants in .lit4/.lit8 and
loads them gp-relative from the retail linker's shared literal pool. Each
load is checked against the pool entry the retail instruction uses
(tools/lit_pool.py, docs/data_split.md):

  [gcc296] LIT .lit4 0x004E1BD0: MATCH

Every LIT line must say MATCH. (gcc 2.96 rounds some decimal float literals
one ulp off: spell the constant differently until it does.)
Symbols are resolved through config/symbol_addrs.txt and splat's labels.
Nothing derived from the game is written anywhere except build/.
"""
import argparse, json, os, re, shutil, struct, subprocess, sys, tempfile
from pathlib import Path
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lit_pool  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x100000
IS_WINDOWS = os.name == "nt"
os.environ["GLIBC_TUNABLES"] = "glibc.cpu.hwcaps=-SSSE3,-SSE4_1,-SSE4_2,-AVX,-AVX2,-ERMS,-FSRM,-BMI1,-BMI2,-POPCNT,-LZCNT,-MOVBE"  # see compile_aligned.py
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
    elif kind in ("gcc296", "gcc296g0", "gcc29", "gcc29as296"):
        build = {"gcc29": "ee-gcc2.9-991111", "gcc29as296": "ee-gcc2.9-991111-as296"}.get(kind, "ee-gcc2.96")
        d = ROOT / ".tools" / "eegcc" / build
        if not (d / "bin" / "ee-gcc").exists():
            return None, f"{build} not installed under .tools/eegcc (tools/setup_tools.py makes it)"
        flags = ["-c", "-O2", "-w"] + (["-G0"] if kind in ("gcc296g0", "gcc29", "gcc29as296") else [])
        fd, out = tempfile.mkstemp(suffix=".o", dir=ROOT / "build"); os.close(fd); os.unlink(out)
        cmd = ([sys.executable, str(ROOT / "tools" / "wsl_gcc.py"), str(d)] if IS_WINDOWS else [str(d / "bin" / "ee-gcc")])
        r = subprocess.run(cmd + flags + incs + ["-o", out, str(src)], capture_output=True, text=True, cwd=ROOT)
        if r.returncode or not os.path.exists(out):
            return None, (r.stdout[-3000:] + r.stderr[-1500:]).strip()
        return out, None
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
                if not e.get_section(sec["sh_info"]).name.startswith(".text"):
                    continue  # e.g. a guard dtor sent to a discarded section
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
            if not e.get_section(s["st_shndx"]).name.startswith(".text"):
                continue  # not linked (the link script discards non-.text code)
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
        called = {sym.name for t, sym, j, rels in relinfo.values() if t == 4}
        for s in symtab.iter_symbols():
            if s["st_shndx"] != "SHN_UNDEF" or not s.name or s.name in names:
                continue
            m = re.fullmatch(r"func_([0-9A-F]{8})", s.name)
            if m:
                a = int(m.group(1), 16)
                if a in starts and a not in byaddr:
                    continue
                undef.append(f"{s.name}: " + (f"named {byaddr[a]}" if a in byaddr else "not a function start"))
            elif s.name in called:
                undef.append(f"{s.name}: called as a function (name it func_...)")
            elif not re.fullmatch(r"D_[0-9A-F]{8}", s.name):
                undef.append(f"{s.name}: unknown symbol")
    return results, undef


DATA_KINDS = (".data", ".rodata", ".sdata")  # tools/data_obj.py
SHF_ALLOC, SHF_EXECINSTR = 2, 4
# not data: assembler bookkeeping, and the C++ exception index the link discards for all units
NOT_DATA = (".reginfo", ".MIPS.", ".pdr", ".mdebug", ".gnu", ".note", ".exceptix", ".exception")


def _sext16(v):
    return ((v & 0xFFFF) ^ 0x8000) - 0x8000


def _layout(secs, members, start):
    """Absolute address of each data section when the block starts at start."""
    pos, out = start, {}
    for i in members:
        al = max(1, secs[i]["sh_addralign"])
        pos = (pos + al - 1) // al * al
        out[i] = pos
        pos += secs[i]["sh_size"]
    return out, (pos - start + 3) // 4 * 4


def text_bases(e, names):
    """{section index: retail address} of each .text section, from the functions in it."""
    text_base = {}
    for s in e.get_section_by_name(".symtab").iter_symbols():
        if s["st_info"]["type"] != "STT_FUNC" or not isinstance(s["st_shndx"], int):
            continue
        a = names.get(s.name)
        if a is None and re.fullmatch(r"func_[0-9A-F]{8}", s.name):
            a = int(s.name[5:], 16)
        if a is not None:
            text_base.setdefault(s["st_shndx"], a - s["st_value"])
    return text_base


def pooled_literals(obj, rom, names):
    """Check an EE-GCC object's gp-relative literals (.lit4/.lit8) against the retail pool.

    The build points each load at the retail pool entry its instruction uses
    (tools/lit_pool.py); the value the source produced must equal it.
    Returns [{"section", "start", "size", "result"}], one per load and one per
    pool entry no code loads (which cannot be pooled)."""
    with open(obj, "rb") as fh:
        blob = fh.read()
        fh.seek(0)
        text_base = text_bases(ELFFile(fh), names)
    out = []
    loads = lit_pool.literals(blob, text_base, rom, lit_pool.gp_value(ROOT))
    for ld in loads:
        out.append({"section": ld["section"], "start": ld["addr"], "size": ld["size"],
                    "result": "MATCH" if ld["match"] else f"DIFF (+{ld['offset']:#x} of the object's pool)"})
    used = {(ld["section"], ld["offset"]) for ld in loads}
    for sec in lit_pool.sections(blob):
        name, size = sec[2], sec[6]
        for o in range(0, size if name in lit_pool.LIT else 0, lit_pool.LIT.get(name, 4)):
            if (name, o) not in used:
                out.append({"section": name, "start": None, "size": lit_pool.LIT[name],
                            "result": f"+{o:#x} not loaded by the code (cannot be pooled)"})
    return out


def data_pieces(e, rom, names):
    """Place and compare the data a compiled object defines.

    The data sections form one block in object order (the original link kept
    each object's literals and tables together, see tools/data_obj.py). Its
    address comes from the %hi/%lo pairs in the code that load it. Returns
    [] or [{"section", "start", "size", "result"}]; "section" is the block's
    subsegment type (.rodata if the unit has any .rodata, else .data)."""
    symtab = e.get_section_by_name(".symtab")
    secs = list(e.iter_sections())
    out = []
    for sec in secs:
        if sec["sh_type"] == "SHT_NOBITS" and sec["sh_flags"] & SHF_ALLOC and sec["sh_size"]:
            out.append({"section": sec.name, "start": None, "size": sec["sh_size"],
                        "result": "uninitialised data cannot be linked from C; declare it extern"})
        elif (sec["sh_flags"] & SHF_ALLOC and not sec["sh_flags"] & SHF_EXECINSTR and sec["sh_size"]
              and sec["sh_type"] != "SHT_NOBITS" and sec.name not in DATA_KINDS
              and sec.name not in lit_pool.LIT and not sec.name.startswith(NOT_DATA)):
            out.append({"section": sec.name, "start": None, "size": sec["sh_size"],
                        "result": "section kind cannot be linked from C yet"})
    members = [i for i, sec in enumerate(secs) if sec.name in DATA_KINDS and sec["sh_size"]]
    if not members:
        return out
    kind = next(k for k in (".rodata", ".data", ".sdata") if any(secs[i].name == k for i in members))
    text_base = text_bases(e, names)
    # %hi/%lo pairs in code that point into a data section give its address
    seen = {}
    for rs in e.iter_sections():
        if not isinstance(rs, RelocationSection) or rs["sh_info"] not in text_base:
            continue
        tdata = secs[rs["sh_info"]].data(); tb = text_base[rs["sh_info"]]
        last_hi = {}
        for rel in rs.iter_relocations():
            t, si = rel["r_info_type"], rel["r_info_sym"]
            if t == 5:
                last_hi[si] = rel["r_offset"]; continue
            if t != 6 or si not in last_hi:
                continue
            sym = symtab.get_symbol(si)
            if sym["st_shndx"] not in members:
                continue
            ho, lo = last_hi[si], rel["r_offset"]
            hw, = struct.unpack_from("<I", tdata, ho); lw, = struct.unpack_from("<I", tdata, lo)
            off = sym["st_value"] + ((hw & 0xFFFF) << 16) + _sext16(lw)
            rh, = struct.unpack_from("<I", rom, tb + ho - BASE); rl, = struct.unpack_from("<I", rom, tb + lo - BASE)
            seen.setdefault(sym["st_shndx"], set()).add(((rh & 0xFFFF) << 16) + _sext16(rl) - off)
    entry = {"section": kind, "start": None, "size": None}
    out.append(entry)
    if not seen:
        entry["result"] = "not referenced from code (cannot be placed)"; return out
    if any(len(v) > 1 for v in seen.values()):
        entry["result"] = "inconsistent placement"; return out
    # block starts: the first section's alignment steps below the lowest known address
    lo_i = min(seen, key=lambda i: members.index(i))
    known = next(iter(seen[lo_i]))
    step = max(1, secs[members[0]]["sh_addralign"])
    total = sum(secs[i]["sh_size"] + secs[i]["sh_addralign"] for i in members)
    if members.index(lo_i) == 0:
        starts = [known]
    else:
        top = (known - 1) - (known - 1) % step
        starts = range(top, known - total - step, -step)
    cands = []
    for st in starts:
        pos, size = _layout(secs, members, st)
        if all(pos[i] == next(iter(v)) for i, v in seen.items()):
            cands.append((st, pos, size))
    if not cands:
        entry["result"] = "the referenced items cannot be laid out in object order at their retail addresses"
        return out

    def compare(start, offs, size):
        img = bytearray(size)
        for i in members:
            img[offs[i] - start:offs[i] - start + secs[i]["sh_size"]] = secs[i].data()
        bad, undef = [], []
        for rs in e.iter_sections():
            if not isinstance(rs, RelocationSection) or rs["sh_info"] not in offs:
                continue
            for rel in rs.iter_relocations():
                o = offs[rs["sh_info"]] - start + rel["r_offset"]
                if rel["r_info_type"] != 2:
                    bad.append(f"{o:#x}(reloc type {rel['r_info_type']})"); continue
                sym = symtab.get_symbol(rel["r_info_sym"])
                sh = sym["st_shndx"]
                if sh in offs:
                    target = offs[sh] + sym["st_value"]
                elif sh in text_base:
                    target = text_base[sh] + sym["st_value"]
                elif sh == "SHN_UNDEF":
                    target = names.get(sym.name)
                    m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})", sym.name)
                    if target is None and m:
                        target = int(m.group(1), 16)
                else:
                    target = None
                if target is None:
                    undef.append(sym.name or f"section {sh}"); continue
                w, = struct.unpack_from("<I", img, o)
                struct.pack_into("<I", img, o, (w + target) & 0xFFFFFFFF)
        orig = rom[start - BASE:start - BASE + size]
        bad += [f"{k:#x}" for k in range(0, size, 4) if img[k:k + 4] != orig[k:k + 4]]
        if undef:
            bad.append("unknown symbols " + ",".join(sorted(set(undef))))
        return bad

    results = [(compare(st, pos, size), st, size) for st, pos, size in cands]
    bad, start, size = min(results, key=lambda r: len(r[0]))
    entry.update(start=start, size=size)
    entry["result"] = "MATCH" if not bad else "DIFF at " + ",".join(bad[:6]) + (f" (+{len(bad) - 6})" if len(bad) > 6 else "")
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("source")
    ap.add_argument("-c", "--compilers", default="mw", help="comma list of mw, mw304, gcc, gcc296 (default mw)")
    ap.add_argument("-I", dest="incs", action="append", default=[])
    ap.add_argument("--cw304", default=os.environ.get("CW304_DIR"))
    ap.add_argument("--cw38", default=os.environ.get("CW38_DIR"))
    ap.add_argument("--cw50", default=os.environ.get("CW50_DIR"))
    ap.add_argument("--json", action="store_true", help="print one JSON object instead of text")
    args = ap.parse_args()
    rom = (ROOT / "build" / "orig" / "SCUS_972.64.rom").read_bytes()
    names, starts = symbols()
    incs = [f"-I{d}" for d in args.incs + ["include", "src"]]
    report = {}
    for kind in args.compilers.split(","):
        obj, err = compile_with(kind, Path(args.source).resolve(), incs,
                                {"mw304": args.cw304, "mw38": args.cw38, "mw50": args.cw50})
        if obj is None:
            report[kind] = {"error": err}
        else:
            try:
                res, undef = compare(obj, rom, names, starts)
                with open(obj, "rb") as fh:
                    data = data_pieces(ELFFile(fh), rom, names)
                lits = pooled_literals(obj, rom, names)
            finally:
                os.unlink(obj)
            report[kind] = {"functions": [{"name": n, "addr": f"{a:08X}" if a else None, "result": r}
                                          for n, a, r in res], "undefined": undef,
                            "data": [dict(d, start=f"{d['start']:08X}" if d["start"] is not None else None)
                                     for d in data],
                            "literals": [dict(d, start=f"{d['start']:08X}" if d["start"] is not None else None)
                                         for d in lits]}
    if args.json:
        print(json.dumps(report)); return
    for kind, r in report.items():
        if "error" in r:
            print(f"[{kind}] COMPILE ERROR\n{r['error']}"); continue
        for f in r["functions"]:
            print(f"[{kind}] {f['name']}: {f['result']}")
        for d in r["data"]:
            size = f"{d['size']:#x}" if d["size"] is not None else "?"
            print(f"[{kind}] DATA {d['section']} {'0x' + d['start'] if d['start'] else '?'} size {size}: {d['result']}")
        for d in r["literals"]:
            print(f"[{kind}] LIT {d['section']} {'0x' + d['start'] if d['start'] else '?'}: {d['result']}")
        for u in r["undefined"]:
            print(f"[{kind}] UNDEF {u}")


if __name__ == "__main__":
    main()
