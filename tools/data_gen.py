#!/usr/bin/env python3
"""Turn the unowned retail data into data-only C units.

usage:
    python tools/data_gen.py [--repo DIR] [--jobs N] [--dry-run] [--only ADDR ...]
    python tools/data_gen.py release [--repo DIR] (--all | ADDR ...)

Everything in the data region that no C unit links is an asm `data`
subsegment of config/splat.yaml. This tool reads splat's disassembly of each
such subsegment (asm/data/<name>.data.s: `dlabel`s and `.word`/`.short`/
`.byte`/`.float`/`.asciz` items, `.word SYMBOL + n` for relocations) and
writes, for each contiguous run of items it can reproduce, a data-only C unit
src/data/d_<VRAM>.c with one ordinary C definition per label (string /
char arrays, int / short / unsigned char / float arrays, pointer tables, a
struct when a label mixes kinds), and replaces the run in config/splat.yaml
with `[ROM, .data, data/d_<VRAM>]` (configure.py builds such a unit like the
data block of a C unit, see docs/data_gen.md).

Every unit is compiled with the default Metrowerks compiler and checked
before it is written: each label must become one `.data` section of exactly
its retail size whose alignment puts it at its retail address (an explicit
`__attribute__((aligned(N)))` lowers the size-based Metrowerks alignment
where the retail address needs it), its bytes must equal the retail bytes
and its relocations the symbols and addends of the disassembly. A label
that cannot be reproduced (and the bytes up to a 4-byte aligned run
boundary) stays assembly.

The tool is idempotent and can be run again on a newer tree: data-only units
already in the tree are regenerated from splat's current disassembly of
their block (unchanged if nothing changed) and new runs are cut from the
remaining asm data. Run `configure.py` first so asm/ matches
config/splat.yaml; afterwards run `configure.py` and `ninja` again.

`release` turns data-only units back into asm data (all of them, or those
containing the given addresses), e.g. before integrating a function whose
string literals or tables lie in such a unit; run the generator again after
the integration to cover the rest.
"""
import argparse
import concurrent.futures
import hashlib
import os
import platform
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

BASE = 0x100000  # vram of rom offset 0 in the main segment
CODE_END = 0x00476B00  # retail: code below, data from here on
MWCC = "mwcps2-3.0.3-020716"
CFLAGS = ["-c", "-O4,p", "-nostdinc", "-sdatathreshold", "0", "-char", "signed", "-lang", "c"]
UNIT_PREFIX = "data/d_"
SEG = re.compile(r"(\s*)- \[0x([0-9A-F]+), ([.\w]+)(?:, ([^\]]+))?\]\s*$")
ENTRY = re.compile(r"\s*/\* ([0-9A-F]+) ([0-9A-F]{8})(?: [0-9A-F]+)? \*/ \.(word|short|byte|float|asciz)\s+(.*?)\s*$")
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*$")
SYMREF = re.compile(r"([A-Za-z_][A-Za-z0-9_.$]*)(?:\s*([-+])\s*(0x[0-9A-Fa-f]+|\d+))?$")
C_KEYWORDS = set("""auto break case char const continue default do double else enum extern float for goto if
inline int long register restrict return short signed sizeof static struct switch typedef union unsigned void
volatile while asm""".split())
LEVELS = 3  # 0: typed, 1: floats as int words, 2: bytes (pointers kept)


# ---------------------------------------------------------------- splat.yaml

def load_segments(lines):
    """(first, last, segs, indent): segs = [[rom, type, name, comment lines]]."""
    first = lines.index("    subsegments:") + 1
    segs, pending, indent = [], [], None
    for i in range(first, len(lines)):
        l = lines[i]
        if l.strip().startswith("#"):
            pending.append(l)
            continue
        m = SEG.match(l)
        if not m or (indent is not None and m.group(1) != indent):
            last = i
            break
        indent = m.group(1)
        segs.append([int(m.group(2), 16), m.group(3), m.group(4), pending])
        pending = []
    else:
        sys.exit("config/splat.yaml: no end of the subsegment list")
    if pending:
        sys.exit("config/splat.yaml: comment after the last subsegment")
    m = re.match(r"\s*- \[0x([0-9A-Fa-f]+)\]", lines[last])
    if not m:
        sys.exit(f"config/splat.yaml: unexpected line after the subsegments: {lines[last]!r}")
    return first, last, segs, indent, int(m.group(1), 16)


def dump_segments(segs, indent):
    out = []
    for s, t, n, comments in segs:
        out += comments
        out.append(f"{indent}- [0x{s:06X}, {t}" + (f", {n}]" if n else "]"))
    return out


def merge_data(segs):
    """Merge consecutive unnamed asm `data` subsegments (after a release)."""
    out = []
    for s in segs:
        if out and s[1] == "data" and out[-1][1] == "data" and not s[2] and not s[3]:
            continue
        out.append(s)
    return out


def is_unit(name):
    return bool(name) and name.startswith(UNIT_PREFIX)


# ---------------------------------------------------------------- asm parsing

class Obj:
    """One retail label: [addr, end) with its items."""

    def __init__(self, name, addr):
        self.name, self.addr, self.end = name, addr, None
        self.items = []  # (addr, size, kind, reloc)  kind in w f h b s; reloc = (sym, addend) or None
        self.level = 0
        self.ok = True
        self.why = ""

    @property
    def size(self):
        return self.end - self.addr


def parse_asm(path, start, end):
    """Objects of a data subsegment [start, end) (vram) from splat's disassembly, or (None, reason)."""
    labels, entries = [], []
    pending = []
    for line in Path(path).read_text(errors="replace").splitlines():
        s = line.strip()
        if not s or s.startswith(("/*", ".include", ".section", "nonmatching", "enddlabel", ".align")) \
                and not ENTRY.match(line):
            continue
        m = re.match(r"dlabel (\S+)", s)
        if m:
            pending.append(m.group(1))
            continue
        m = ENTRY.match(line)
        if not m:
            return None, f"unknown line {s[:60]!r}"
        addr = int(m.group(2), 16)
        for n in pending:
            labels.append((addr, n))
        pending = []
        entries.append((addr, m.group(3), m.group(4)))
    if pending:
        return None, "label after the last item"
    if not entries or entries[0][0] != start:
        return None, "does not start with an item"
    objs, by_addr = [], {}
    for addr, name in labels:
        if addr in by_addr:
            by_addr[addr].ok = False
            by_addr[addr].why = f"two labels at {addr:08X}"
            continue
        o = Obj(name, addr)
        by_addr[addr] = o
        objs.append(o)
    if not objs or objs[0].addr != start:
        return None, "no label at the start"
    for i, o in enumerate(objs):
        o.end = objs[i + 1].addr if i + 1 < len(objs) else end
    k = 0
    for i, (addr, kind, operand) in enumerate(entries):
        nxt = entries[i + 1][0] if i + 1 < len(entries) else end
        while objs[k].end <= addr:
            k += 1
        o = objs[k]
        stop = min(nxt, o.end)
        size = stop - addr
        reloc = None
        if kind in ("word", "float"):
            kind_c = "w" if kind == "word" else "f"
            if kind == "word" and not operand.startswith(("0x", "-0x")) and not operand.lstrip("-").isdigit():
                m = SYMREF.match(operand)
                if not m:
                    return None, f"cannot parse .word {operand!r}"
                off = int(m.group(3), 0) if m.group(3) else 0
                reloc = (m.group(1), -off if m.group(2) == "-" else off)
                if not IDENT.match(reloc[0]) or reloc[0] in C_KEYWORDS:
                    o.ok, o.why = False, f"reference to {reloc[0]!r}"
            if size != 4:
                if reloc:
                    o.ok, o.why = False, "relocation not on a 4-byte item"
                kind_c = "b"
        elif kind == "short":
            kind_c = "h" if size == 2 else "b"
        elif kind == "byte":
            kind_c = "b"
        else:
            kind_c = "s"
        o.items.append((addr, size, kind_c, reloc))
        if nxt > o.end:  # an item that runs over the next label
            o.ok, o.why = False, "item crosses a label"
    for o in objs:
        if not o.items or o.items[0][0] != o.addr:
            o.ok, o.why = False, "label not on an item"
        if o.ok and (not IDENT.match(o.name) or o.name in C_KEYWORDS):
            o.ok, o.why = False, f"name {o.name!r} is not a C identifier"
    return objs, None


# ---------------------------------------------------------------- C generation

def c_string(data):
    out, prev = [], ""
    for b in data:
        c = chr(b)
        if c == '"' or c == "\\":
            t = "\\" + c
        elif c == "\n":
            t = "\\n"
        elif c == "\t":
            t = "\\t"
        elif c == "?" and prev == "?":
            t = "\\?"
        elif 0x20 <= b < 0x7F:
            t = c
        else:
            t = f"\\{b:03o}"
        out.append(t)
        prev = c
    # split long literals into adjacent pieces after newlines / every ~72 characters
    pieces, cur, n = [], "", 0
    for t in out:
        cur += t
        n += len(t)
        if t == "\\n" or n >= 72:
            pieces.append(cur)
            cur, n = "", 0
    if cur or not pieces:
        pieces.append(cur)
    return pieces


def c_float(bits):
    """Shortest literal for a single-precision value, or None (NaN/inf)."""
    v, = struct.unpack("<f", struct.pack("<I", bits))
    if v != v or v in (float("inf"), float("-inf")):
        return None
    for p in range(6, 18):
        s = f"{v:.{p}g}"
        if struct.unpack("<I", struct.pack("<f", float(s)))[0] == bits:
            break
    else:
        return None
    if "e" not in s and "." not in s:
        s += ".0"
    elif "e" in s and "." not in s.split("e")[0]:
        a, e = s.split("e")
        s = a + ".0e" + e
    return s + "f"


def groups(o, rom, level):
    """Members of an object: [(kind, offset, size, items)] or None if it cannot be laid out."""
    gs = []
    for addr, size, kind, reloc in o.items:
        if level >= 1 and kind == "f":
            kind = "w"
        if level >= 2 and kind != "w" or (level >= 2 and kind == "w" and not reloc):
            kind = "b"
        if kind == "w":
            kind = "p" if reloc else "i"
        g = gs[-1] if gs else None
        merge = g and (g[0] == kind or (g[0] in "pi" and kind in "pi")
                       or (g[0] == "s" and kind == "b"))
        if merge:
            if kind == "p":
                g[0] = "p"
            g[2] += size
            g[3].append((addr, size, kind, reloc))
        else:
            gs.append([kind, addr - o.addr, size, [(addr, size, kind, reloc)]])
    align = {"p": 4, "i": 4, "f": 4, "h": 2, "b": 1, "s": 1}
    for kind, off, size, _ in gs:
        a = align[kind]
        if off % a or size % a:
            return None
    m = max(align[g[0]] for g in gs)
    if o.size % m:
        return None
    if level >= 2 and len(gs) > 1 and not any(g[0] == "p" for g in gs):
        return None
    return gs


CTYPE = {"p": "void *", "i": "int ", "f": "float ", "h": "short ", "b": "unsigned char ", "s": "char "}
ESIZE = {"p": 4, "i": 4, "f": 4, "h": 2, "b": 1, "s": 1}


def initializer(kind, off, size, items, o, rom, symtype, indent):
    data = rom[o.addr - BASE + off:o.addr - BASE + off + size]
    if kind == "s":
        stripped = data.rstrip(b"\0")
        pieces = c_string(stripped)
        if len(pieces) == 1:
            return f'"{pieces[0]}"'
        return ("\n" + indent).join(f'"{p}"' for p in pieces)
    vals = []
    if kind in "pi":
        relocs = {a: r for a, _, _, r in items if r}
        for k in range(0, size, 4):
            a = o.addr + off + k
            w, = struct.unpack_from("<I", data, k)
            if a in relocs:
                sym, add = relocs[a]
                ref = sym if symtype.get(sym) == "array" else f"&{sym}"
                if add:
                    ref = f"(char *)&{sym} {'+' if add > 0 else '-'} {abs(add):#x}"
                vals.append(ref)
            elif kind == "p":
                vals.append(f"(void *){w:#x}" if w else "0")
            else:
                vals.append(f"{w:#x}" if w else "0")
        per = 4
    elif kind == "f":
        for k in range(0, size, 4):
            w, = struct.unpack_from("<I", data, k)
            f = c_float(w)
            if f is None:
                return None
            vals.append(f)
        per = 4
    elif kind == "h":
        vals = [f"{v:#x}" if v else "0" for v in struct.unpack(f"<{size // 2}H", data)]
        per = 8
    else:
        vals = [f"{v:#04x}" for v in data]
        per = 16
    lines = [", ".join(vals[i:i + per]) for i in range(0, len(vals), per)]
    if len(lines) == 1 and len(lines[0]) < 60:
        return "{ " + lines[0] + " }"
    return "{\n" + "".join(f"{indent}    {l},\n" for l in lines) + indent + "}"


def mw_align(size):
    return 4 if size <= 4 else 8 if size < 16 else 16


def definition(o, rom, symtype):
    """(declaration, definition) of an object at its level, or None."""
    gs = groups(o, rom, o.level)
    if gs is None:
        return None
    attr = ""
    a = mw_align(o.size)
    if o.addr % a:
        attr = f" __attribute__((aligned({o.addr & -o.addr})))"
    if len(gs) == 1:
        kind, off, size, items = gs[0]
        init = initializer(kind, off, size, items, o, rom, symtype, "")
        if init is None:
            return None
        n = size // ESIZE[kind]
        decl = f"{CTYPE[kind]}{o.name}[{n}]"
        return f"extern {decl};", f"{decl}{attr} = {init};"
    tag = f"{o.name}_s"
    members, inits = [], []
    for j, (kind, off, size, items) in enumerate(gs):
        init = initializer(kind, off, size, items, o, rom, symtype, "    ")
        if init is None:
            return None
        members.append(f"    {CTYPE[kind]}m{j}[{size // ESIZE[kind]}];")
        inits.append(f"    {init},")
    body = f"struct {tag} {{\n" + "\n".join(members) + "\n};"
    return (f"{body}\nextern struct {tag} {o.name};",
            f"struct {tag} {o.name}{attr} = {{\n" + "\n".join(inits) + "\n};")


def unit_source(objs, rom, symkind):
    defined = {o.name for o in objs}
    symtype = {}
    for o in objs:
        gs = groups(o, rom, o.level)
        symtype[o.name] = "array" if gs is not None and len(gs) == 1 else "struct"
    refs = []
    for o in objs:
        for _, _, _, r in o.items:
            if r and r[0] not in defined and r[0] not in refs:
                refs.append(r[0])
    for r in refs:
        symtype[r] = "array" if symkind(r) == "data" else "func"
    out = [f"/* {objs[0].addr:08X}-{objs[-1].end:08X}: retail data, generated by tools/data_gen.py */", ""]
    for r in sorted(refs):
        out.append(f"extern char {r}[];" if symtype[r] == "array" else f"extern void {r}();")
    if refs:
        out.append("")
    decls, defs = [], []
    for o in objs:
        d = definition(o, rom, symtype)
        if d is None:
            return None, o
        decls.append(d[0])
        defs.append(d[1])
    referenced = {r[0] for o in objs for _, _, _, r in o.items if r}
    for o, d in zip(objs, decls):
        # struct tags always; extern declarations only for labels used before their definition
        if d.startswith("struct"):
            out.append(d if o.name in referenced else d.rsplit("\n", 1)[0])
        elif o.name in referenced:
            out.append(d)
    if out[-1] != "":
        out.append("")
    for d in defs:
        out.append(d)
        out.append("")
    return "\n".join(out), None


# ---------------------------------------------------------------- checking

def read_elf(path):
    from elftools.elf.elffile import ELFFile
    with open(path, "rb") as f:
        elf = ELFFile(f)
        secs = []
        for s in elf.iter_sections():
            secs.append({"name": s.name, "type": s["sh_type"], "flags": s["sh_flags"], "size": s["sh_size"],
                         "align": s["sh_addralign"], "data": s.data() if s["sh_type"] != "SHT_NOBITS" else b""})
        symtab = elf.get_section_by_name(".symtab")
        syms = [(sym.name, sym["st_shndx"], sym["st_value"], sym["st_size"], sym["st_info"]["type"])
                for sym in symtab.iter_symbols()] if symtab else []
        relocs = {}
        for s in elf.iter_sections():
            if s["sh_type"] in ("SHT_REL", "SHT_RELA"):
                tab = elf.get_section(s["sh_link"])
                for r in s.iter_relocations():
                    sym = tab.get_symbol(r["r_info_sym"])
                    relocs.setdefault(s["sh_info"], []).append(
                        (r["r_offset"], r["r_info_type"], sym.name, sym["st_shndx"], sym["st_value"],
                         r["r_addend"] if s["sh_type"] == "SHT_RELA" else None))
    return secs, syms, relocs


def check(objs, obj_path, rom):
    """{object name: reason} for the objects that do not match."""
    secs, syms, relocs = read_elf(obj_path)
    bad = {}
    where = {}
    for name, shndx, value, size, typ in syms:
        if isinstance(shndx, int) and shndx > 0 and typ == "STT_OBJECT":
            where[name] = (shndx, value, size)
    for i, s in enumerate(secs):
        if s["flags"] & 2 and s["size"] and s["name"] not in (".data",) and not s["flags"] & 4:
            for n, (k, _, _) in where.items():
                if k == i:
                    bad[n] = f"in section {s['name']}"
    last = 0
    for o in objs:
        if o.name in bad:
            continue
        if o.name not in where:
            bad[o.name] = "no symbol"
            continue
        k, value, size = where[o.name]
        s = secs[k]
        if k <= last:
            bad[o.name] = "out of order"
            continue
        last = k
        if value != 0 or s["size"] != o.size or s["name"] != ".data":
            bad[o.name] = f"section {s['name']} size {s['size']:#x} (want {o.size:#x})"
            continue
        if o.addr % max(s["align"], 1):
            bad[o.name] = f"alignment {s['align']}"
            continue
        want = rom[o.addr - BASE:o.end - BASE]
        got = bytearray(s["data"])
        exp = {a - o.addr: r for a, _, _, r in o.items if r}
        seen = set()
        for off, typ, sym, shndx, sval, addend in relocs.get(k, []):
            if typ != 2:  # R_MIPS_32
                bad[o.name] = f"relocation type {typ}"
                break
            inline, = struct.unpack_from("<I", got, off)
            add = addend if addend is not None else inline
            if add >= 0x80000000:
                add -= 1 << 32
            if sym == "" and isinstance(shndx, int):  # section symbol: our own label
                tgt = next((n for n, (kk, v, _) in where.items() if kk == shndx and v == 0), None)
                sym, add = tgt, add
            if exp.get(off) != (sym, add):
                bad[o.name] = f"relocation at +{off:#x}: {sym}+{add:#x}, want {exp.get(off)}"
                break
            seen.add(off)
            got[off:off + 4] = want[off:off + 4]
        else:
            if set(exp) != seen:
                bad[o.name] = "missing relocation"
            elif bytes(got) != want:
                d = next(i for i in range(len(want)) if got[i] != want[i])
                bad[o.name] = f"bytes differ at +{d:#x}"
    return bad


# ---------------------------------------------------------------- driver

class Tools:
    def __init__(self, repo, cc):
        self.repo = repo
        if cc:
            self.cc = cc.split()
        else:
            exe = repo / ".tools" / "mwcc" / MWCC / "mwccps2.exe"
            if not exe.is_file():
                sys.exit(f"{exe} not found (run tools/setup_tools.py or pass --cc)")
            if platform.system() == "Windows":
                self.cc = [str(exe)]
            else:
                wibo = repo / ".tools" / "wibo"
                w = str(wibo) if wibo.exists() else shutil.which("wibo") or shutil.which("wine")
                self.cc = [w, str(exe)]

    def compile(self, src, out):
        rel = lambda p: os.path.relpath(p, self.repo)
        r = subprocess.run(self.cc + CFLAGS + ["-o", rel(out), rel(src)], capture_output=True, text=True,
                           cwd=self.repo)
        if r.returncode or not Path(out).exists():
            return (r.stdout + r.stderr).strip() or "compile error"
        return None


def symbol_kinds(repo):
    """name -> 'func' | 'data' for the names in config/symbol_addrs.txt."""
    kinds = {}
    for l in (repo / "config" / "symbol_addrs.txt").read_text().splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+)\s*;(.*)", l)
        if m:
            a = int(m.group(2), 16)
            t = "func" if "type:func" in m.group(3) or (0x100000 <= a < CODE_END and "type:" not in m.group(3)) \
                else "data"
            kinds.setdefault(m.group(1), t)
    return kinds


def runs_of(objs):
    """Maximal runs of good objects starting and ending on 4-byte boundaries."""
    out, cur = [], []

    def flush():
        while cur and cur[0].addr % 4:
            cur.pop(0)
        while cur and cur[-1].end % 4:
            cur.pop()
        if cur:
            out.append(list(cur))
        cur.clear()

    for o in objs:
        if o.ok:
            cur.append(o)
        else:
            flush()
    flush()
    return out


def solve(tools, work, key, objs, rom, symkind):
    """Compile and check the runs of one subsegment until every remaining object matches.

    Returns [(objs, source)]."""
    results = []
    for _ in range(12):
        runs = runs_of(objs)
        if not runs:
            return []
        changed = False
        results = []
        for n, run in enumerate(runs):
            src, failed = unit_source(run, rom, symkind)
            if src is None:
                failed.level += 1
                if failed.level >= LEVELS:
                    failed.ok, failed.why = False, "no representation"
                changed = True
                break
            cfile = work / f"{key}_{n}.c"
            ofile = work / f"{key}_{n}.o"
            cfile.write_text(src, newline="\n")
            if ofile.exists():
                ofile.unlink()
            err = tools.compile(cfile, ofile)
            if err:
                # find the culprit by line number when the compiler names one
                m = re.search(r"#\s+(\d+):", err)
                line = int(m.group(1)) if m else None
                culprit = None
                if line:
                    text = src.splitlines()
                    for k in range(min(line, len(text)) - 1, -1, -1):
                        mm = re.match(r"(?:struct \w+ |[\w ]+?\*?\s*)(\w+)(?:\[\d+\])?(?: __attribute__.*)? = ",
                                      text[k])
                        if mm and any(o.name == mm.group(1) for o in run):
                            culprit = next(o for o in run if o.name == mm.group(1))
                            break
                culprit = culprit or run[0]
                culprit.level += 1
                if culprit.level >= LEVELS:
                    culprit.ok, culprit.why = False, "compile error: " + err.splitlines()[-1][:80]
                changed = True
                continue
            bad = check(run, ofile, rom)
            for o in run:
                if o.name in bad:
                    o.level += 1
                    while o.level < LEVELS and groups(o, rom, o.level) is None:
                        o.level += 1
                    if o.level >= LEVELS:
                        o.ok, o.why = False, bad[o.name]
                    changed = True
            if not bad:
                results.append((run, src))
        if not changed:
            return results
    return results


def stamp_ok(repo):
    stamp = repo / "build" / "splat.stamp"
    want = hashlib.sha256((repo / "config" / "splat.yaml").read_bytes()
                          + (repo / "config" / "symbol_addrs.txt").read_bytes()).hexdigest()
    return stamp.exists() and stamp.read_text() == want and (repo / "asm").is_dir()


def generate(args):
    repo = Path(args.repo).resolve()
    if not stamp_ok(repo):
        sys.exit("asm/ is not split from the current config/splat.yaml; run configure.py first")
    rom = (repo / "build" / "orig" / "SCUS_972.64.rom").read_bytes()
    kinds = symbol_kinds(repo)

    def symkind(name):
        if name.startswith("func_"):
            return "func"
        if name.startswith("D_"):
            return "data"
        return kinds.get(name, "data")

    tools = Tools(repo, args.cc)
    work = repo / "build" / "data_gen"
    shutil.rmtree(work, ignore_errors=True)
    work.mkdir(parents=True)
    yp = repo / "config" / "splat.yaml"
    lines = yp.read_text().split("\n")
    i0, i1, segs, indent, end_off = load_segments(lines)
    nxt = lambda k: segs[k + 1][0] if k + 1 < len(segs) else end_off
    first_data = next((s[0] for s in segs if s[1] == "data" or s[1].startswith(".")), None)
    only = [int(a, 16) for a in args.only] if args.only else None

    jobs = []
    for k, (start, typ, name, _) in enumerate(segs):
        if first_data is None or start < first_data:
            continue
        unit = typ == ".data" and is_unit(name)
        if not (typ == "data" or unit):
            continue
        S, E = start + BASE, nxt(k) + BASE
        if only and not any(S <= a < E for a in only):
            continue
        if unit:
            path = repo / "asm" / "data" / (name + ".data.s")
        else:
            path = repo / "asm" / "data" / ((name or f"{start:X}") + ".data.s")
        jobs.append((k, S, E, path, unit))

    def work_one(job):
        k, S, E, path, unit = job
        if S % 4 or E % 4:
            return k, None, "subsegment not 4-byte aligned"
        if not path.exists():
            return k, None, f"{path} missing"
        objs, why = parse_asm(path, S, E)
        if objs is None:
            return k, None, why
        return k, (objs, solve(tools, work, f"{S:08X}", objs, rom, symkind)), None

    results, problems = {}, []
    with concurrent.futures.ThreadPoolExecutor(args.jobs) as ex:
        for k, res, why in ex.map(work_one, jobs):
            if why:
                problems.append((segs[k][0] + BASE, why))
            results[k] = res

    # rewrite the subsegments
    new_segs, written, keep_files = [], {}, set()
    total = {"units": 0, "bytes": 0, "skipped": 0, "kept": 0}
    skipped = []
    for k, seg in enumerate(segs):
        start, typ, name, comments = seg
        res = results.get(k)
        if res is None:
            new_segs.append(seg)
            if is_unit(name) and typ == ".data":
                keep_files.add(name)
            continue
        objs, runs = res
        S, E = start + BASE, nxt(k) + BASE
        pieces = []
        pos = S
        for run, src in runs:
            a, b = run[0].addr, run[-1].end
            if a > pos:
                pieces.append([pos - BASE, "data", None, []])
            unit = f"{UNIT_PREFIX}{a:08X}"
            pieces.append([a - BASE, ".data", unit, []])
            written[unit] = src
            total["units"] += 1
            total["bytes"] += b - a
            pos = b
        if pos < E:
            pieces.append([pos - BASE, "data", None, []])
        # the first piece keeps the comments and, if it is asm data, the name
        pieces[0][3] = comments
        if pieces[0][1] == "data" and pieces[0][0] == start and typ == "data":
            pieces[0][2] = name
        new_segs += pieces
        for o in objs:
            if not any(o in run for run, _ in runs):
                total["skipped"] += o.size
                skipped.append((o.addr, o.size, o.name, o.why or "run boundary"))
    new_segs = merge_data(new_segs)

    changed_files = 0
    for unit, src in written.items():
        p = repo / "src" / (unit + ".c")
        if not p.exists() or p.read_text() != src:
            changed_files += 1
            if not args.dry_run:
                p.parent.mkdir(parents=True, exist_ok=True)
                p.write_text(src, newline="\n")
    removed = []
    for k, seg in enumerate(segs):
        if is_unit(seg[2]) and seg[2] not in written and seg[2] not in keep_files:
            removed.append(seg[2])
    if not args.dry_run:
        for unit in removed:
            p = repo / "src" / (unit + ".c")
            if p.exists():
                p.unlink()
        new_lines = lines[:i0] + dump_segments(new_segs, indent) + lines[i1:]
        if new_lines != lines:
            yp.write_text("\n".join(new_lines), newline="\n")
    print(f"data-only units: {total['units']} ({total['bytes']} bytes), {changed_files} files written, "
          f"{len(removed)} units released; {total['skipped']} bytes stay assembly")
    for addr, why in problems:
        print(f"  subsegment {addr:08X}: {why}")
    if args.verbose:
        for a, s, n, why in skipped:
            print(f"  skip {a:08X} +{s:#x} {n}: {why}")


def release(args):
    repo = Path(args.repo).resolve()
    yp = repo / "config" / "splat.yaml"
    lines = yp.read_text().split("\n")
    i0, i1, segs, indent, end_off = load_segments(lines)
    nxt = lambda k: segs[k + 1][0] if k + 1 < len(segs) else end_off
    addrs = [int(a, 16) for a in args.addr]
    gone = []
    for k, seg in enumerate(segs):
        if seg[1] == ".data" and is_unit(seg[2]):
            S, E = seg[0] + BASE, nxt(k) + BASE
            if args.all or any(S <= a < E for a in addrs):
                gone.append(seg[2])
                seg[1], seg[2] = "data", None
    segs = merge_data(segs)
    for unit in gone:
        p = repo / "src" / (unit + ".c")
        if p.exists():
            p.unlink()
    yp.write_text("\n".join(lines[:i0] + dump_segments(segs, indent) + lines[i1:]), newline="\n")
    print(f"released {len(gone)} data-only units")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", nargs="?", default="generate", choices=["generate", "release"])
    ap.add_argument("addr", nargs="*", help="release: addresses (hex) inside the units to release")
    ap.add_argument("--repo", default=str(Path(__file__).resolve().parent.parent))
    ap.add_argument("--cc", help="compiler command (default: .tools/mwcc/%s/mwccps2.exe, under wibo off Windows)"
                    % MWCC)
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--only", nargs="*", help="generate: only the asm data subsegments containing these addresses")
    ap.add_argument("--all", action="store_true", help="release: all data-only units")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()
    if args.command == "release":
        if not args.all and not args.addr:
            ap.error("release needs --all or addresses")
        release(args)
    else:
        generate(args)


if __name__ == "__main__":
    main()
