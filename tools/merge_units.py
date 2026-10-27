#!/usr/bin/env python3
"""Merge per-function C units back into translation units.

usage:
    python tools/merge_units.py MODULE...          # e.g. SFOGame/Source/AIMsgs lib/lgaud
    python tools/merge_units.py --all-complete     # every module with no asm left in its range
    python tools/merge_units.py --all              # every run of adjacent units of one module
    python tools/merge_units.py --dry-run ...      # print the groups, change nothing
    python tools/merge_units.py --unmerge UNIT...  # split merged units back into func_<ADDR>.c

Run from the repository root after `python configure.py` (it needs splat's
asm/ for the symbol addresses and build/orig/SCUS_972.64.rom). CW38_DIR,
CW50_DIR and CW304_DIR name the licensed Metrowerks installs, as for
tools/check_match.py. See docs/merge_units.md.

A *module* is one original source file, a path from config/tu_ranges.txt such
as SFOGame/Source/game: its units are the part files src/SFOGame/Source/game.c,
game_2.c, ... and the per-function units src/SFOGame/Source/game/*.c (see
module_of). Units outside those files keep the older scheme, one module per
directory src/<main|lib>/<module>/. A *run* is a sequence of `c` subsegments of
one module with nothing between them in config/splat.yaml. Each run is cut into groups
greedily in address order; a unit joins the current group only if the merged
source, compiled and linked on its own at the retail addresses, reproduces the
retail bytes of all of the group's code and data:

* one compiler: the group's compiler (a unit built with another Metrowerks or
  EE-GCC build joins if the merged file still matches with one of the two);
* one data block: the units' data subsegments must be adjacent in
  config/splat.yaml (they become one `[ROM, .rodata|.data, unit]`);
* the merged file must compile (conflicting declarations of one symbol stop
  the group) and give the same code and data bytes.

The merged file keeps each original file as one block, in address order,
between `/* merge_units: begin func_XXXXXXXX */` and `... end ...` markers.
Duplicate type definitions and declarations are dropped (the first copy, or
the header's, stays), conflicting type names / statics are renamed with the
block's address as suffix, a macro redefined differently is #undef'd first,
and Metrowerks blocks are wrapped in `#pragma push`/`#pragma pop` so that
per-file pragmas stay per function.
"""
import argparse
import concurrent.futures
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
sys.path.insert(1, str(ROOT))
import integrate_pending as ip  # noqa: E402
try:
    import lit_pool  # noqa: E402  (EE-GCC literal pool, newer trees)
except ImportError:
    lit_pool = None

BASE = 0x100000
os.environ["GLIBC_TUNABLES"] = "glibc.cpu.hwcaps=-SSSE3,-SSE4_1,-SSE4_2,-AVX,-AVX2,-ERMS,-FSRM,-BMI1,-BMI2,-POPCNT,-LZCNT,-MOVBE"  # see compile_aligned.py
ROM_PATH = ROOT / "build" / "orig" / "SCUS_972.64.rom"
KIND_OF = {v: k for k, v in ip.OVR.items()}          # compiler_overrides value -> kind
OVR_OF = dict(ip.OVR)                                 # kind -> compiler_overrides value
MW_KINDS = ip.MW_KINDS
PIECE_TYPES = ip.PIECE_TYPES
LINKED = (".text",) + PIECE_TYPES   # configure.LINK_SECTIONS: .text* .data* .rodata* .sdata*
TAG = "/* merge_units */"
BEGIN = re.compile(r"^/\* merge_units: begin (\S+) \*/$")
END = re.compile(r"^/\* merge_units: end (\S+) \*/$")
FUNC_UNIT = re.compile(r"func_([0-9A-F]{8})$")
EXCLUDE_MODULES = ("main/sinit",)   # static initialisers of many modules, in the tail


# --------------------------------------------------------------------------- C text
KEYWORDS = set("""auto break case char const continue default do double else enum extern float for goto if
inline int long register restrict return short signed sizeof static struct switch typedef union unsigned void
volatile while asm __asm__ __attribute__ __inline__ __inline __volatile__ __extension__ __typeof__ typeof
_Bool class template namespace operator public private protected virtual friend new delete this""".split())

TOKEN = re.compile(r"""
  (?P<ws>\s+)
| (?P<cmt>//[^\n]*|/\*.*?\*/)
| (?P<str>"(?:\\.|[^"\\\n])*"|'(?:\\.|[^'\\\n])*')
| (?P<id>[A-Za-z_$][\w$]*)
| (?P<num>\.?\d(?:[eEpP][+-]|[\w.])*)
| (?P<op>::|->|\.\.\.|<<=|>>=|[-+*/%&|^<>=!]=|&&|\|\||\+\+|--|<<|>>|.)
""", re.S | re.X)


def tokens(text):
    """[(kind, value, start, end)] of a C fragment (comments and whitespace included)."""
    out, pos = [], 0
    while pos < len(text):
        m = TOKEN.match(text, pos)
        out.append((m.lastgroup, m.group(), pos, m.end()))
        pos = m.end()
    return out


def sig(text):
    """The significant tokens of a fragment (no comments, no whitespace)."""
    return [(k, v) for k, v, _, _ in tokens(text) if k not in ("ws", "cmt")]


def norm(text):
    return " ".join(v for _, v in sig(text))


def pp_lines(text):
    """Split preprocessor lines (with continuations) off: yields (is_pp, fragment)."""
    out, cur = [], []
    lines = text.split("\n")
    i = 0
    in_comment = False
    while i < len(lines):
        line = lines[i]
        if not in_comment and line.lstrip().startswith("#"):
            if cur:
                out.append((False, "\n".join(cur) + "\n")); cur = []
            pp = [line]
            while pp[-1].endswith("\\") and i + 1 < len(lines):
                i += 1; pp.append(lines[i])
            out.append((True, "\n".join(pp) + "\n"))
        else:
            cur.append(line)
            # track /* ... */ spanning lines so a '#' inside a comment is not a directive
            s = ("/*" if in_comment else "") + line
            s = re.sub(r'"(?:\\.|[^"\\])*"', '""', s)
            s = re.sub(r"//.*", "", s)
            s = re.sub(r"/\*.*?\*/", "", s)
            in_comment = "/*" in s
        i += 1
    if cur:
        out.append((False, "\n".join(cur) + "\n"))
    if out and not text.endswith("\n"):
        last = out[-1]
        out[-1] = (last[0], last[1][:-1])
    return out


class Item:
    """One top-level piece of a C file: a preprocessor line or a declaration/definition."""

    def __init__(self, lead, text, pp):
        self.lead, self.text, self.pp = lead, text, pp
        self.s = [] if pp else sig(text)
        self.kind, self.names, self.static = self.classify()

    def classify(self):
        if self.pp:
            m = re.match(r"\s*#\s*(\w+)\s*(.*)", self.text, re.S)
            d = m.group(1) if m else ""
            if d == "define":
                n = re.match(r"(\w+)", m.group(2))
                return "define", [n.group(1)] if n else [], False
            return d or "pp", [], False
        s = self.s
        vals = [v for _, v in s]
        if not vals:
            return "empty", [], False
        static = "static" in vals[:vals.index("{")] if "{" in vals else "static" in vals
        tags = [vals[i + 1] for i in range(len(vals) - 2)
                if vals[i] in ("struct", "union", "enum") and s[i + 1][0] == "id" and vals[i + 2] == "{"]
        enums = []
        for i in range(len(vals) - 1):
            if vals[i] == "enum" and "{" in vals[i:i + 3]:
                j = vals.index("{", i); depth = 0
                expect = True
                for k in range(j, len(vals)):
                    v = vals[k]
                    if v in "({[":
                        depth += 1
                    elif v in ")}]":
                        depth -= 1
                        if depth == 0:
                            break
                    elif depth == 1 and expect and s[k][0] == "id":
                        enums.append(v); expect = False
                    elif depth == 1 and v == ",":
                        expect = True
        if self.is_function():
            return "func", [self.func_name()], static
        if vals[0] == "typedef":
            return "type", tags + enums + self.declarators(), False
        if vals[0] in ("struct", "union", "enum") and vals[-1] == ";" and "{" in vals:
            close = self.match_close(vals.index("{"))
            if close == len(vals) - 2:
                return "type", tags + enums, False
        decl = "=" not in vals and "{" not in vals and ("extern" in vals or self.is_prototype())
        return ("decl" if decl else "var"), tags + enums + self.declarators(), static

    def match_close(self, i):
        vals = [v for _, v in self.s]
        depth = 0
        for k in range(i, len(vals)):
            if vals[k] in "({[":
                depth += 1
            elif vals[k] in ")}]":
                depth -= 1
                if depth == 0:
                    return k
        return len(vals) - 1

    def is_function(self):
        vals = [v for _, v in self.s]
        depth = 0
        for k, v in enumerate(vals):
            if v == "{" and depth == 0:
                return k > 0 and (vals[k - 1] == ")" or vals[k - 1] == "const") and "=" not in vals[:k]
            if v in "([":
                depth += 1
            elif v in ")]":
                depth -= 1
        return False

    def func_name(self):
        vals = [v for _, v in self.s]
        k = vals.index("(")
        # `int (*f(void))(int) {`: skip a parenthesised declarator start
        while k > 0 and vals[k - 1] in ("(", "*"):
            k = vals.index("(", k + 1)
        return vals[k - 1]

    def is_prototype(self):
        s = self.s
        for k, (t, v) in enumerate(s):
            if v == "(":
                return k > 0 and s[k - 1][0] == "id" and s[k - 1][1] not in KEYWORDS
        return False

    def declarators(self):
        """Names declared at the outer level (typedef names, variables, functions)."""
        s = self.s
        out, depth, k = [], 0, 0
        # skip a struct/union/enum body
        vals = [v for _, v in s]
        while k < len(s):
            t, v = s[k]
            if v in "{":
                k = self.match_close(k) + 1; continue
            if v in "([":
                # the name of `(*name)` / `(name)` is inside the first parenthesis
                if v == "(" and depth == 0 and k + 1 < len(s) and s[k + 1][1] in ("*", "&"):
                    j = k + 1
                    while j < len(s) and s[j][1] in ("*", "&", "const", "volatile", "__restrict"):
                        j += 1
                    if j < len(s) and s[j][0] == "id":
                        out.append(s[j][1])
                depth += 1
            elif v in ")]":
                depth -= 1
            elif depth == 0 and t == "id" and v not in KEYWORDS and k + 1 < len(s) \
                    and s[k + 1][1] in (";", ",", "[", "=", "(", ":") and v != "__attribute__":
                out.append(v)
            if v == "=" and depth == 0:
                # skip the initialiser up to the next top-level comma
                d = 0
                while k < len(s):
                    if s[k][1] in "({[":
                        d += 1
                    elif s[k][1] in ")}]":
                        d -= 1
                    elif s[k][1] in (",", ";") and d == 0:
                        break
                    k += 1
                continue
            k += 1
        return [n for n in dict.fromkeys(out)]


def split_items(text):
    """Top-level items of a C file. Comments and blank lines in front of an
    item become its `lead`; trailing ones a final empty item."""
    items, lead = [], ""
    linkage = [0]
    for is_pp, frag in pp_lines(text):
        if is_pp:
            if items and not items[-1].pp and items[-1].kind == "open":
                items[-1].text += frag  # a directive inside a body
                continue
            items.append(Item(lead, frag, True)); lead = ""
            continue
        toks = tokens(frag)
        i = 0
        # continue an item left open by a directive inside it
        if items and getattr(items[-1], "kind", None) == "open":
            it = items.pop()
            buf, depth, func = it.text, it._depth, it._func
            prev = it._prev
            lead = it.lead
        else:
            buf, depth, func, prev = None, 0, False, None
        trail = None
        while i < len(toks):
            k, v, a, b = toks[i]
            if buf is None:
                if k == "ws" and "\n" in v:
                    trail = None
                if trail is not None and k in ("ws", "cmt") and "\n" not in v:
                    trail.text += v; i += 1; continue  # a comment on the item's last line stays with it
                if k in ("ws", "cmt"):
                    lead += v; i += 1; continue
                if v == "}" and linkage[0] > 0:
                    it = Item(lead, v, False); it.kind = "linkage"
                    items.append(it); lead = ""; trail = it; linkage[0] -= 1; i += 1; continue
                buf, depth, func, prev = "", 0, False, None
            buf += v
            if k not in ("ws", "cmt"):
                if v == "{" and depth == 0 and prev == '"C"' and [x for _, x in sig(buf)] == ["extern", '"C"', "{"]:
                    # extern "C" { ... }: a linkage block, its contents are items of their own
                    it = Item(lead, buf, False); it.kind = "linkage"
                    items.append(it); lead = ""; buf = None; trail = it; linkage[0] += 1; i += 1; continue
                if v == "{" and depth == 0 and prev == ")":
                    func = True
                if v in "({[":
                    depth += 1
                elif v in ")}]":
                    depth -= 1
                if depth == 0 and (v == ";" or (v == "}" and func)):
                    it = Item(lead, buf, False)
                    items.append(it); lead = ""; buf = None; trail = it
                prev = v
            i += 1
        if buf is not None:
            it = Item.__new__(Item)
            it.lead, it.text, it.pp, it.kind = lead, buf, False, "open"
            it._depth, it._func, it._prev = depth, func, prev
            it.s, it.names, it.static = [], [], False
            items.append(it); lead = ""
    if items and items[-1].kind == "open":
        it = items.pop()
        items.append(Item(it.lead, it.text, False))
    if lead.strip():
        tail = Item(lead, "", False)
        items.append(tail)
    return items


def rename_text(text, mapping):
    """Replace identifiers outside strings, comments and #include lines."""
    if not mapping:
        return text
    out = []
    for is_pp, frag in pp_lines(text):
        if is_pp and re.match(r"\s*#\s*include\b", frag):
            out.append(frag); continue
        out.append("".join(mapping.get(v, v) if k == "id" else v for k, v, _, _ in tokens(frag)))
    return "".join(out)


# --------------------------------------------------------------------------- headers
class Headers:
    """Names defined by the headers a file includes (recursively), for conflict checks."""

    def __init__(self):
        self.cache = {}

    def resolve(self, name, here):
        for d in [here, ROOT / "include", ROOT / "src"]:
            p = (d / name)
            if p.is_file():
                return p.resolve()
        return None

    def defs(self, path, seen=None):
        """{name: normalized defining text} for types, {macro: body} and {function: prototype}."""
        seen = seen if seen is not None else set()
        if path in seen:
            return {}, {}, {}
        seen.add(path)
        if path in self.cache:
            return self.cache[path]
        types, macros, protos = {}, {}, {}
        try:
            text = path.read_text(errors="replace")
        except OSError:
            return types, macros, protos
        for it in split_items(text):
            if it.pp:
                m = re.match(r'\s*#\s*include\s*"([^"]+)"', it.text)
                if m:
                    p = self.resolve(m.group(1), path.parent)
                    if p:
                        t, mc, pr = self.defs(p, seen)
                        types.update(t); macros.update(mc); protos.update(pr)
                elif it.kind == "define" and it.names:
                    macros[it.names[0]] = norm(it.text)
                continue
            if it.kind == "type":
                for n in it.names:
                    types[n] = norm(it.text)
            else:
                p = proto(it)
                if p:
                    protos.setdefault(p[0], p[1])
        self.cache[path] = (types, macros, protos)
        return types, macros, protos


def proto(it):
    """(name, normalized prototype) of a function declaration or definition, else None."""
    if it.pp or it.kind not in ("decl", "func") or len(it.names) != 1:
        return None
    vals = [v for _, v in it.s]
    if it.kind == "decl":
        if not it.is_prototype() or "__attribute__" in vals or vals[-1] != ";":
            return None
        vals = vals[:-1]
    else:
        vals = vals[:vals.index("{")]
    vals = [v for v in vals if v not in ("extern", "static", "inline", "__inline")]
    return it.names[0], vals


def split_proto(name, vals):
    """(return type tokens, [parameter type tokens], variadic) of a prototype, or None."""
    k = vals.index(name)
    ret, rest = vals[:k], vals[k + 1:]
    if not rest or rest[0] != "(" or rest[-1] != ")" or "(" in rest[1:-1] or "[" in rest:
        return None
    params, cur = [], []
    for v in rest[1:-1] + [","]:
        if v == ",":
            params.append(cur); cur = []
        else:
            cur.append(v)
    if params == [[]] or params == [["void"]]:
        return ret, [], False
    variadic = params[-1] == ["..."]
    out = []
    for p in params[:-1] if variadic else params:
        if not p:
            return None
        if len(p) > 1 and re.fullmatch(r"[A-Za-z_]\w*", p[-1]) and p[-1] not in KEYWORDS \
                and p[-2] not in ("struct", "union", "enum"):
            p = p[:-1]
        out.append(p)
    return ret, out, variadic


def object_macro(name, vals):
    """`#define D (*(T*)&D)` (or `((T*)&D)` for an array) to use an object that is
    already declared with another type as the block's declaration says."""
    vals = [v for v in vals if v != "extern"]
    if vals[-1:] != [";"] or vals.count(name) != 1 or "(" in vals or "=" in vals or "," in vals:
        return None
    k = vals.index(name)
    typ, rest = vals[:k], vals[k + 1:-1]
    if not typ or "*" in rest:
        return None
    if not rest:
        return f"#define {name} (*({' '.join(typ)}*)&{name})"
    if rest[0] == "[" and rest[-1] == "]" and rest.count("[") == 1:
        return f"#define {name} (({' '.join(typ)}*)&{name})"
    return None


def call_macro(name, mine, theirs):
    """A function-like macro that calls name with the prototype already in scope
    (theirs), converting the arguments to it and the result to the block's
    own return type (mine): `#define f(a0) ((T)f((U)(a0)))`. None if the
    prototypes do not have the same number of parameters."""
    a, b = split_proto(name, mine), split_proto(name, theirs)
    if not a or not b or len(a[1]) != len(b[1]) or a[2] or b[2]:
        return None
    args = [f"a{i}" for i in range(len(a[1]))]
    call = ", ".join(f"({' '.join(tb)})({x})" if ta != tb else f"({x})"
                     for x, ta, tb in zip(args, a[1], b[1]))
    body = f"{name}({call})"
    if a[0] != b[0]:
        body = f"({' '.join(a[0])})" + body
    return f"#define {name}({', '.join(args)}) ({body})"


HEADERS = Headers()


# --------------------------------------------------------------------------- chunks
class Chunk:
    """One original per-function file (a block of a merged file)."""

    def __init__(self, label, text, kind, cpp):
        self.label, self.text, self.kind, self.cpp = label, text, kind, cpp

    @property
    def addr(self):
        return int(self.label[5:], 16)


def is_cpp(text):
    return bool(re.search(r"^\s*#\s*pragma\s+cplusplus\s+on\b", text, re.M))


def read_chunks(path, kind):
    """The chunks of a unit's source: one for a per-function file, the blocks of a merged one."""
    text = path.read_text(errors="replace")
    lines = text.split("\n")
    if not any(BEGIN.match(l) for l in lines):
        label = path.stem if FUNC_UNIT.match(path.stem) else path.stem
        return [Chunk(label, text if text.endswith("\n") else text + "\n", kind, is_cpp(text))]
    chunks, cur, label = [], None, None
    # Text before the first block (some merged files hoist the includes and
    # declarations their blocks share there) belongs to the first block, minus
    # the generated title comment.
    first = next(i for i, l in enumerate(lines) if BEGIN.match(l))
    pre = "\n".join(lines[:first])
    pre = re.sub(r"\A\s*/\*.*?\*/\n?", lambda m: "" if "merge_units" in m.group(0) else m.group(0), pre, flags=re.S)
    pre = re.sub(r"^/\* headers shared by the blocks below \*/\n", "", pre.strip("\n") + "\n", flags=re.M)
    preamble = [l for l in pre.split("\n") if not l.rstrip().endswith(TAG)] if pre.strip() else []
    for l in lines:
        m = BEGIN.match(l)
        if m:
            cur, label = ([] if chunks else list(preamble)), m.group(1); continue
        m = END.match(l)
        if m and cur is not None:
            body = [x for x in cur if not x.rstrip().endswith(TAG)]
            t = "\n".join(body).strip("\n") + "\n"
            chunks.append(Chunk(label, t, kind, is_cpp(t)))
            cur = None; continue
        if cur is not None:
            cur.append(l)
    return chunks


def synthesize(chunks, unit_dir, mw, title, cast=False):
    """Merged source for chunks (in order). Returns the text.

    cast: a function declared again with another prototype is called through
    a cast to the block's prototype instead of being redeclared."""
    out = [f"/*\n * {title}\n * One translation unit merged from per-function files by tools/merge_units.py\n"
           f" * (docs/merge_units.md); each `merge_units: begin` block is one original file.\n */\n"]
    types = {}       # type name -> normalized defining text (in scope)
    decl_seen = set()  # normalized declarations / type definitions emitted
    macros = {}      # macro -> normalized definition
    includes = set()
    statics = {}     # static name -> normalized text
    declared = set()  # names of objects and functions declared so far
    protos = {}      # function -> prototype tokens
    objdecls = {}    # object -> normalized first declaration
    comments = set()
    for c in chunks:
        text = c.text
        # rename conflicting type names and statics (to a fixpoint)
        mapping = {}
        for _ in range(8):
            items = split_items(rename_text(text, mapping))
            new = {}
            for it in items:
                if it.pp:
                    continue
                if it.kind == "type":
                    nt = norm(it.text)
                    if nt in decl_seen:
                        continue
                    for n in it.names:
                        prev = types.get(n)
                        if prev is not None and prev != nt and n not in mapping:
                            new[n] = f"{n}_{c.label[5:]}"
                elif it.kind in ("func", "var", "decl") and it.static:
                    nt = norm(it.text)
                    for n in it.names:
                        if n in mapping or (it.kind == "func" and statics.get(n) == nt):
                            continue
                        if n in declared or n in statics:
                            new[n] = f"{n}_{c.label[5:]}"
            if not new:
                break
            mapping.update(new)
        text = rename_text(text, mapping)
        items = split_items(text)
        block, undefs = [], []
        for it in items:
            lead = it.lead
            keep = True
            if it.pp:
                m = re.match(r'\s*#\s*include\s*(["<][^">]+[">])', it.text)
                if m:
                    if m.group(1) in includes:
                        keep = False
                    else:
                        includes.add(m.group(1))
                        if m.group(1).startswith('"'):
                            p = HEADERS.resolve(m.group(1)[1:-1], unit_dir)
                            if p:
                                t, mc, pr = HEADERS.defs(p)
                                for n, d in t.items():
                                    types.setdefault(n, d)
                                for n, d in mc.items():
                                    macros.setdefault(n, d)
                                for n, d in pr.items():
                                    protos.setdefault(n, d)
                                    declared.add(n)
                elif it.kind == "define" and it.names:
                    n, d = it.names[0], norm(it.text)
                    if n in macros and macros[n] != d:
                        block.append(lead); lead = ""
                        block.append(f"#undef {n} {TAG}\n")
                    elif macros.get(n) == d:
                        keep = False
                    macros[n] = d
                elif it.kind == "undef":
                    n = re.match(r"\s*#\s*undef\s+(\w+)", it.text)
                    if n:
                        macros.pop(n.group(1), None)
            elif it.kind == "type":
                nt = norm(it.text)
                if nt in decl_seen or (it.names and all(types.get(n) == nt for n in it.names)):
                    keep = False
                else:
                    decl_seen.add(nt)
                    for n in it.names:
                        types[n] = nt
            elif it.kind == "decl":
                nt = norm(it.text)
                p = proto(it)
                if nt in decl_seen:
                    keep = False
                elif cast and p and p[0] in protos and protos[p[0]] != p[1] and p[0] not in macros \
                        and (mac := call_macro(p[0], p[1], protos[p[0]])):
                    n = p[0]
                    block.append(f"{lead}#if 0 {TAG}\n{it.text.strip()}\n#endif {TAG}\n{mac} {TAG}\n")
                    undefs.append(n)
                    continue
                elif cast and not p and len(it.names) == 1 and objdecls.get(it.names[0], nt) != nt \
                        and it.names[0] not in macros and (mac := object_macro(it.names[0], [v for _, v in it.s])):
                    block.append(f"{lead}#if 0 {TAG}\n{it.text.strip()}\n#endif {TAG}\n{mac} {TAG}\n")
                    undefs.append(it.names[0])
                    continue
                if not p and len(it.names) == 1:
                    objdecls.setdefault(it.names[0], nt)
                decl_seen.add(nt)
                if p:
                    protos.setdefault(p[0], p[1])
                declared.update(it.names)
            elif it.kind in ("func", "var"):
                nt = norm(it.text)
                if it.static and it.kind == "func" and any(statics.get(n) == nt for n in it.names):
                    keep = False
                for n in it.names:
                    if it.static:
                        statics[n] = nt
                    declared.add(n)
                p = proto(it)
                if p:
                    protos.setdefault(p[0], p[1])
            if keep:
                block.append(lead + it.text)
            else:
                # keep a dropped item's comment unless it repeats one already kept
                if lead.strip() and lead.strip() not in comments:
                    block.append(lead)
            if lead.strip():
                comments.add(lead.strip())
        body = "".join(block).strip("\n") + "\n"
        out.append(f"\n/* merge_units: begin {c.label} */\n")
        if mw:
            out.append(f"#pragma push {TAG}\n")
        out.append(body)
        for n in undefs:
            out.append(f"#undef {n} {TAG}\n")
        if mw:
            if "merge_flush_" not in body:
                # an empty inline function: MW generates the block's deferred code here,
                # under the block's own pragmas (C/C++ mode), before the pop
                out.append(f"static inline void merge_flush_{c.label}(void) {{}} {TAG}\n")
            out.append(f"#pragma pop {TAG}\n")
        out.append(f"/* merge_units: end {c.label} */\n")
    return "".join(out)


def standalone(chunks, k, unit_dir, mw):
    """A self-contained source for chunk k of a merged file: the declarations
    visible before it that it uses (transitively), then its own text."""
    before = []
    cxx = re.compile(r"^[ \t]*#[ \t]*pragma[ \t]+cplusplus[ \t]+on\b", re.M)
    own_cxx = bool(cxx.search(chunks[k].text))
    for c in chunks[:k]:
        is_cxx = bool(cxx.search(c.text))
        if is_cxx and not own_cxx:
            continue  # C++ declarations are no use to a C block
        for it in split_items(c.text):
            it.cxx = is_cxx
            if it.pp:
                if re.match(r"\s*#\s*(include|define|undef)\b", it.text):
                    before.append(it)
            elif it.kind in ("type", "decl"):
                before.append(it)
            elif it.kind == "func" and it.static and re.search(r"\binline\b", it.text):
                before.append(it)
    own = chunks[k].text
    mine = set()
    for it in split_items(own):
        if not it.pp:
            mine.update(it.names)
        else:
            m = re.match(r"\s*#\s*define\s+(\w+)", it.text)
            if m:
                mine.add(m.group(1))
    # the block's own declarations win over earlier blocks' (possibly conflicting) ones
    before = [it for it in before if not (set(it.names) & mine)
              and not ((m := re.match(r"\s*#\s*(?:define|undef)\s+(\w+)", it.text)) and m.group(1) in mine)]
    # names the included headers declare are taken from there; of the earlier blocks'
    # declarations of one name only the first was in effect in the merged file
    hdr = set()
    for t in [own] + [it.text for it in before if it.pp]:
        for inc in re.findall(r'^\s*#\s*include\s*"([^"]+)"', t, re.M):
            p = HEADERS.resolve(inc, unit_dir)
            if p:
                for d in HEADERS.defs(p):
                    hdr.update(d)
    seen, kept = set(hdr), []
    for it in before:
        if not it.pp and it.kind in ("type", "decl") and it.names:
            if set(it.names) & (seen if it.kind == "decl" else hdr):
                continue
            seen.update(it.names)
        kept.append(it)
    before = kept
    used = {v for k_, v in sig(own) if k_ == "id"}
    for _, frag in pp_lines(own):
        used |= {v for k_, v, _, _ in tokens(frag) if k_ == "id"}
    keep = set()
    changed = True
    while changed:
        changed = False
        for i, it in enumerate(before):
            if i in keep:
                continue
            if it.pp and re.match(r"\s*#\s*include\b", it.text):
                keep.add(i); changed = True; continue
            if any(n in used for n in it.names):
                keep.add(i); changed = True
                used |= {v for k_, v, _, _ in tokens(it.text) if k_ == "id"}
    # C blocks' declarations go first (in C mode, as in the merged file), C++ blocks'
    # after the block's own `#pragma cplusplus on`
    pre = "".join(before[i].text.rstrip("\n") + "\n" for i in sorted(keep) if not before[i].cxx)
    post = "".join(before[i].text.rstrip("\n") + "\n" for i in sorted(keep) if before[i].cxx)
    m = cxx.search(own)
    if post and m:
        e = own.index("\n", m.end()) + 1 if "\n" in own[m.end():] else len(own)
        own = own[:e] + post + "\n" + own[e:]
    # an own declaration repeated in the prefix is harmless; a pragma state is not carried over
    return (pre + ("\n" if pre else "") + own)


# --------------------------------------------------------------------------- layout
def load_layout():
    yp = ROOT / "config" / "splat.yaml"
    y = yp.read_text().split("\n")
    i0, i1, segs, indent = ip.load_segments(y)
    end_off = ip.end_of_segments(y, i1)
    return y, i0, i1, segs, indent, end_off


def unit_kind(name, overrides):
    v = overrides.get(name)
    if v:
        return KIND_OF.get(v, v)
    return "gcc" if ip.is_gcc_unit(name) else "mw"


_SOURCES = None


def source_modules():
    """Original source files (config/tu_ranges.txt paths without extension)."""
    global _SOURCES
    if _SOURCES is None:
        _SOURCES = ip.source_modules(ROOT)
    return _SOURCES


def module_of(name):
    """The module a c unit is grouped in, or None if it is never merged.

    Original source files: SFOGame/Source/game/<file> (a per-function unit) and
    SFOGame/Source/game, game_2, ... (part files) all belong to module
    SFOGame/Source/game. Older scheme: main/<module>/<file> and lib/<module>/<file>
    belong to main/<module> and lib/<module>; main/<file> belongs to none."""
    if not name or name.startswith("data/"):
        return None
    head = name.rsplit("/", 1)[0] if "/" in name else ""
    if head.split("/")[0] in ("", "main", "lib"):
        if name.count("/") != 2:
            return None
        return None if head in EXCLUDE_MODULES else head
    if head in source_modules():
        return head
    stem = re.sub(r"_\d+$", "", name)
    if stem in source_modules():
        return stem
    return None


def is_source_module(mod):
    return mod.split("/")[0] not in ("main", "lib")


def files_dir(mod):
    """Directory that holds a module's merged files: src/<dir of the original
    file> for an original source file, src/<module> in the older scheme."""
    return ROOT / "src" / (mod.rsplit("/", 1)[0] if is_source_module(mod) else mod)


def runs(segs):
    """[(module, [segment index])]: maximal runs of adjacent c units of one module."""
    out, cur, mod = [], [], None
    for i, (s, t, n, _) in enumerate(segs):
        m = module_of(n) if t == "c" else None
        if m is not None and m == mod:
            cur.append(i); continue
        if cur:
            out.append((mod, cur))
        cur, mod = ([i], m) if m is not None else ([], None)
    if cur:
        out.append((mod, cur))
    return out


def complete_modules(segs):
    first, last, count = {}, {}, {}
    for i, (s, t, n, _) in enumerate(segs):
        m = module_of(n) if t == "c" else None
        if m:
            first.setdefault(m, i); last[m] = i
    done = set()
    for m in first:
        rng = segs[first[m]:last[m] + 1]
        if all(t == "c" and module_of(n) == m for _, t, n, _ in rng):
            done.add(m)
    return done


def data_of(segs):
    """{unit: [segment index of its data subsegments]}"""
    out = {}
    for i, (s, t, n, _) in enumerate(segs):
        if t in PIECE_TYPES and n:
            out.setdefault(n, []).append(i)
    return out


# --------------------------------------------------------------------------- checking
def first_error(err):
    """The compiler's first error message (later ones are mostly consequences)."""
    lines = [l.strip() for l in (err or "").splitlines()]
    for i, l in enumerate(lines):
        if re.match(r"#\s+Error:", l) or re.search(r":\d+: ", l):
            if l.startswith("#"):
                # MW: '#   NNN: source', '#   Error:   ^', '#   message...' up to the next block
                j = i + 1
                msg = []
                while j < len(lines) and lines[j].startswith("#") and not lines[j].startswith("###") \
                        and not re.match(r"#\s+\d+:", lines[j]) and len(msg) < 4:
                    msg.append(lines[j].lstrip("# ").strip()); j += 1
                src = lines[i - 1].lstrip("# ").strip() if i else ""
                return " ".join(msg) + " | at: " + src
            return l
    return " | ".join(lines[-8:])



class Checker:
    def __init__(self, segs, end_off):
        import check_match as cm
        import configure
        self.cm = cm
        self.rom = (ROOT / "build" / "orig" / "SCUS_972.64.rom").read_bytes()
        self.names, _ = cm.symbols()
        self.segs, self.end_off = segs, end_off
        prefix = configure.binutils_prefix(None)
        exe = ".exe" if os.name == "nt" else ""
        self.ld = prefix + "ld" + exe
        self.objcopy = prefix + "objcopy" + exe
        import yaml
        cfg = yaml.safe_load((ROOT / "config" / "splat.yaml").read_text())
        self.gp = cfg["options"]["gp_value"]
        self.dirs = {"mw304": os.environ.get("CW304_DIR"), "mw38": os.environ.get("CW38_DIR"),
                     "mw50": os.environ.get("CW50_DIR")}
        self.work = ROOT / "build" / "merge_units"
        self.work.mkdir(parents=True, exist_ok=True)

    def nxt(self, k):
        return self.segs[k + 1][0] if k + 1 < len(self.segs) else self.end_off

    def addr_of(self, name):
        a = self.names.get(name)
        if a is None:
            m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})", name)
            if m:
                a = int(m.group(1), 16)
        return a

    def check(self, text, kind, unit_dir, text_idx, pieces):
        """None if the merged text reproduces the retail code/data of the group, else the reason.

        text_idx: segment indices of the group's c units; pieces: segment indices
        of its data subsegments (adjacent, in order)."""
        from elftools.elf.elffile import ELFFile
        # in the unit's directory, so that #include "x.h" finds the same files as in the build
        fd, src = tempfile.mkstemp(prefix=".merge_units_", suffix=".c", dir=unit_dir)
        os.close(fd)
        Path(src).write_text(text, newline="\n")
        obj = elf = script = None
        try:
            obj, err = self.cm.compile_with(kind, Path(src), ["-Iinclude", "-Isrc"], self.dirs)
            if obj is None:
                return "compile: " + first_error(err)
            start = self.segs[text_idx[0]][0] + BASE
            align = next(a for a in (16, 8, 4) if start % a == 0)
            if kind not in MW_KINDS or align != 16:
                # configure.py: the cc_aligned / gcc rules set the .text alignment from the start address;
                # the gcc rule also points .lit4/.lit8 loads at the retail literal pool (tools/lit_pool.py)
                extra = []
                if kind not in MW_KINDS and lit_pool is not None:
                    for n in lit_pool.resolve(obj, str(ROM_PATH), self.gp, start):
                        extra += ["--remove-section", n]
                subprocess.run([self.objcopy, "--set-section-alignment", f".text={align}", *extra, obj],
                               check=True)
            with open(obj, "rb") as fh:
                e = ELFFile(fh)
                syms = list(e.get_section_by_name(".symtab").iter_symbols())
                undef = sorted({s.name for s in syms if s["st_shndx"] == "SHN_UNDEF" and s.name})
                common = [s.name for s in syms if s["st_shndx"] == "SHN_COMMON"]
                # like the build's link script: .text* .data* .rodata* .sdata* are linked, the rest
                # is discarded (C++ exception tables and the like); allocated data elsewhere is lost
                bad = [s.name for s in e.iter_sections() if s["sh_flags"] & 2 and s["sh_size"]
                       and ((s["sh_type"] == "SHT_NOBITS")
                            or (not s["sh_flags"] & 4 and not s.name.startswith(LINKED)
                                and not s.name.startswith(self.cm.NOT_DATA)))]
                datas = [s for s in e.iter_sections()
                         if s.name.startswith(PIECE_TYPES) and s["sh_size"]]
            if bad or common:
                return "sections/symbols the build cannot link: " + ",".join(bad + common)
            if datas and not pieces:
                return "data without a data subsegment"
            tend = self.nxt(text_idx[-1]) + BASE
            lines = ["SECTIONS\n{", f"    _gp = {self.gp:#x};"]
            for n in undef:
                a = self.addr_of(n)
                if a is not None:  # else only used by discarded sections, or the link fails
                    lines.append(f"    {n} = {a:#x};")
            lines.append(f"    .text {start:#x} : {{ *(.text*) }}")
            pstart = pend = None
            if pieces:
                pstart = self.segs[pieces[0]][0] + BASE
                pend = self.nxt(pieces[-1]) + BASE
                lines.append(f"    .dat {pstart:#x} : {{ *(.data* .rodata* .sdata*) }}")
            lines += ["    /DISCARD/ : { *(*) }", "}"]
            script = obj + ".ld"
            Path(script).write_text("\n".join(lines) + "\n")
            elf = obj + ".elf"
            r = subprocess.run([self.ld, "-EL", "-T", script, "-o", elf, obj, "--no-check-sections"],
                               capture_output=True, text=True)
            if r.returncode:
                return "link: " + " | ".join((r.stdout + r.stderr).strip().splitlines()[-3:])
            with open(elf, "rb") as fh:
                e = ELFFile(fh)
                t = e.get_section_by_name(".text")
                code = t.data() if t is not None else b""
                d = e.get_section_by_name(".dat")
                dat = d.data() if d is not None else b""
            end = start + len(code)
            if end > tend:
                return f"code {len(code):#x} bytes longer than the units ({tend - start:#x})"
            nstart = tend
            nalign = next(a for a in (16, 8, 4) if nstart % a == 0) if nstart != self.end_off + BASE else 4
            if (end + nalign - 1) // nalign * nalign < nstart or any(self.rom[end - BASE:tend - BASE]):
                return f"code {len(code):#x} bytes shorter than the units ({tend - start:#x})"
            rom = self.rom[start - BASE:end - BASE]
            if code != rom:
                k = next(i for i in range(len(code)) if code[i] != rom[i])
                return f"code differs at {start + k:08X}"
            if pieces:
                if (len(dat) + 3) // 4 * 4 != pend - pstart:
                    return f"data {len(dat):#x} bytes vs data subsegments {pend - pstart:#x}"
                rd = self.rom[pstart - BASE:pstart - BASE + len(dat)]
                if dat != rd:
                    k = next(i for i in range(len(dat)) if dat[i] != rd[i])
                    return f"data differs at {pstart + k:08X}"
            return None
        finally:
            if not os.environ.get("MERGE_UNITS_KEEP"):
                for p in (src, obj, script, elf):
                    if p and os.path.exists(p):
                        os.unlink(p)
            elif src and os.path.exists(src):
                shutil.move(src, str(obj or src) + ".c")


# --------------------------------------------------------------------------- planning
def plan_run(chk, mod, idx, segs, overrides, dpieces, log):
    """Greedy grouping of one run. Returns [(kind, [segment index], text or None)]."""
    unit_dir = files_dir(mod)
    unit_dir.mkdir(parents=True, exist_ok=True)
    units = []
    for i in idx:
        name = segs[i][2]
        kind = unit_kind(name, overrides)
        chunks = read_chunks(ROOT / "src" / (name + ".c"), kind)
        units.append((i, name, kind, chunks))
    groups = []

    def pieces_of(members):
        ps = sorted(p for i in members for p in dpieces.get(segs[i][2], []))
        return ps

    def adjacent(ps):
        return all(b == a + 1 for a, b in zip(ps, ps[1:]))

    def family(k):
        return "mw" if k in MW_KINDS else "gcc"

    cur = None  # [kind, members, chunks, text, cast]
    for i, name, kind, chunks in units:
        if cur is not None and family(kind) == family(cur[0]):
            members = cur[1] + [i]
            ps = pieces_of(members)
            if not adjacent(ps):
                log(f"  {name}: data subsegments not adjacent to the group's -> new group")
            else:
                why = None
                cs = cur[2] + chunks
                for k in dict.fromkeys([cur[0], kind]):
                    for cast in ([True] if cur[4] else [False, True]):
                        text = synthesize(cs, unit_dir, family(k) == "mw", mod, cast)
                        if cast and not cur[4] and (not why.startswith("compile") or f"#if 0 {TAG}" not in text):
                            continue  # the cast variant only helps against conflicting prototypes
                        why = chk.check(text, k, unit_dir, members, ps)
                        if why is None:
                            break
                    if why is None:
                        cur = [k, members, cs, text, cast]
                        break
                if why is None:
                    continue
                log(f"  {name}: {why} -> new group")
        if cur is not None:
            groups.append(cur)
        cur = [kind, [i], list(chunks), None, False]
    if cur is not None:
        groups.append(cur)
    return groups


def remove_empty_dirs(d):
    """Remove d and its parents up to src/ while they are empty (a module's
    per-function directory once all of its units are merged)."""
    src = ROOT / "src"
    while d != src and src in d.parents and d.is_dir() and not any(d.iterdir()):
        d.rmdir()
        d = d.parent


def is_part_name(mod, name):
    """SFOGame/Source/game, SFOGame/Source/game_2, ... for module SFOGame/Source/game."""
    return name == mod or re.fullmatch(re.escape(mod) + r"_\d+", name) is not None


def needs_part_name(mod, name):
    return is_source_module(mod) and not is_part_name(mod, name)


def name_groups(mod, groups, segs):
    """Names for the merged groups in address order, skipping names of units of
    the module that are not regrouped: SFOGame/Source/game, game_2, ... for an
    original source file; <module>/<base>, <base>_2, ... in the older scheme."""
    base = mod.rsplit("/", 1)[1]
    prefix = mod if is_source_module(mod) else f"{mod}/{base}"
    # a lone unit (merged before or not) stays as is - except in an original source
    # file, where it moves out of the per-function directory to a part-file name
    merged = [g for g in groups if len(g[1]) > 1 or needs_part_name(mod, segs[g[1][0]][2])]
    mine = {segs[i][2] for g in merged for i in g[1]}
    taken = {n for _, t, n, _ in segs if t == "c" and n and n not in mine}
    rel = files_dir(mod).relative_to(ROOT / "src").as_posix()
    taken |= {f"{rel}/{p.stem}" for p in files_dir(mod).glob("*.c")} - mine
    names, n = {}, 1
    for g in sorted(merged, key=lambda g: segs[g[1][0]][0]):
        while (name := prefix + ("" if n == 1 else f"_{n}")) in taken:
            n += 1
        names[id(g)] = name
        n += 1
    return names


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--all-complete", action="store_true")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--unmerge", action="store_true", help="split the named merged units into per-function files")
    ap.add_argument("--jobs", type=int, default=os.cpu_count())
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()
    os.chdir(ROOT)
    y, i0, i1, segs, indent, end_off = load_layout()
    op = ROOT / "config" / "compiler_overrides.json"
    overrides = json.loads(op.read_text()) if op.exists() else {}
    if args.unmerge:
        return unmerge(args, y, i0, i1, segs, indent, end_off, overrides, op)
    dpieces = data_of(segs)
    allruns = runs(segs)
    if args.all:
        want = {m for m, _ in allruns}
    elif args.all_complete:
        want = complete_modules(segs)
    else:
        want = set(args.modules)
        unknown = want - {m for m, _ in allruns}
        if unknown:
            sys.exit(f"no units for module(s): {', '.join(sorted(unknown))}")
    todo = [(m, idx) for m, idx in allruns
            if m in want and (len(idx) > 1 or needs_part_name(m, segs[idx[0]][2]))]
    chk = Checker(segs, end_off)

    def work(r):
        m, idx = r
        lines = []
        groups = plan_run(chk, m, idx, segs, overrides, dpieces, lines.append)
        return m, idx, groups, lines

    results = []
    with concurrent.futures.ThreadPoolExecutor(max(1, args.jobs)) as ex:
        for m, idx, groups, lines in ex.map(work, todo):
            results.append((m, idx, groups))
            n = sum(len(g[2]) for g in groups)
            print(f"{m}: {len(idx)} units ({n} functions/files) -> {len(groups)} units")
            if args.verbose:
                for l in lines:
                    print(l)
            for g in groups:
                if len(g[1]) > 1 or args.verbose:
                    a, b = segs[g[1][0]][0] + BASE, segs[g[1][-1]][0] + BASE
                    print(f"    {g[0]:9} {a:08X}-{b:08X} {len(g[2])} files")
    if args.dry_run:
        return
    # rewrite: per module, name the merged groups in address order
    bymod = {}
    for m, idx, groups in results:
        bymod.setdefault(m, []).extend(groups)
    rename, drop, new_files, ovr = {}, set(), {}, {}
    old_files = []
    for m, groups in bymod.items():
        names = name_groups(m, groups, segs)
        for g in groups:
            if id(g) not in names:
                continue
            kind, members, chunks, text, cast = g
            new = names[id(g)]
            if len(members) == 1:
                # a lone unit renamed to a part file: a merged file keeps its text, a
                # per-function file becomes a one-block file if that still matches
                old = segs[members[0]][2]
                text = (ROOT / "src" / (old + ".c")).read_text(errors="replace")
                if not any(BEGIN.match(l) for l in text.split("\n")):
                    text = synthesize(chunks, files_dir(m), kind in MW_KINDS,
                                      f"{m}: 1 file, {segs[members[0]][0] + BASE:08X}")
                    why = chk.check(text, kind, files_dir(m), members, dpieces.get(old, []))
                    if why is not None:
                        print(f"  {old}: stays (as a one-block file: {why})")
                        continue
                new_files[new] = text
                old_files.append(old)
                rename[old] = new
                ovr[new] = kind
                continue
            text = synthesize(chunks, files_dir(m), kind in MW_KINDS, f"{m}: {len(chunks)} files, "
                              f"{segs[members[0]][0] + BASE:08X}-{segs[members[-1]][0] + BASE:08X}", cast)
            new_files[new] = text
            for i in members:
                old_files.append(segs[i][2])
                rename[segs[i][2]] = new
            ovr[new] = kind
    # segments
    out = []
    for s in segs:
        start, t, n, comments = s
        if n in rename:
            new = rename[n]
            if t == "c" and out and out[-1][1] == "c" and out[-1][2] == new:
                out[-1][3] += comments; continue
            if t in PIECE_TYPES and out and out[-1][1] in PIECE_TYPES and out[-1][2] == new:
                out[-1][3] += comments
                if t == ".rodata" or (t == ".data" and out[-1][1] == ".sdata"):
                    out[-1][1] = t
                continue
            out.append([start, t, new, list(comments)])
        else:
            out.append([start, t, n, list(comments)])
    for old in old_files:
        overrides.pop(old, None)
    for new, kind in ovr.items():
        if kind in OVR_OF:
            overrides[new] = OVR_OF[kind]
        else:
            overrides.pop(new, None)
    for old in old_files:
        p = ROOT / "src" / (old + ".c")
        if p.exists() and old not in new_files:
            p.unlink()
            remove_empty_dirs(p.parent)
    for new, text in new_files.items():
        (ROOT / "src" / (new + ".c")).parent.mkdir(parents=True, exist_ok=True)
        (ROOT / "src" / (new + ".c")).write_text(text, newline="\n")
    y[i0:i1] = ip.dump_segments(out, indent)
    (ROOT / "config" / "splat.yaml").write_text("\n".join(y), newline="\n")
    op.write_text(json.dumps(overrides, indent=2) + "\n", newline="\n")
    print(f"merged {len(old_files)} units into {len(new_files)}")


def unmerge(args, y, i0, i1, segs, indent, end_off, overrides, op):
    """Split merged units back into one func_<ADDR>.c unit per block.

    Each block's code must start at the retail address of its function and
    each data subsegment is handed to the block whose function references it
    (checked with the same compile-and-link test as merging)."""
    chk = Checker(segs, end_off)
    dpieces = data_of(segs)
    out = [list(s) for s in segs]
    writes, unlinks = [], []
    for unit in args.modules:
        k = next((j for j, s in enumerate(out) if s[1] == "c" and s[2] == unit), None)
        if k is None:
            sys.exit(f"{unit}: not a c unit")
        kind = unit_kind(unit, overrides)
        path = ROOT / "src" / (unit + ".c")
        chunks = read_chunks(path, kind)
        if len(chunks) < 2:
            sys.exit(f"{unit}: not a merged unit")
        # per-function units go back to the module's directory: SFOGame/Source/game_2 ->
        # SFOGame/Source/game/func_<ADDR>, main/aiMsgs/aiMsgs -> main/aiMsgs/func_<ADDR>
        mod = module_of(unit) or unit.rsplit("/", 1)[0]
        (ROOT / "src" / mod).mkdir(parents=True, exist_ok=True)
        texts = [standalone(chunks, j, ROOT / "src" / mod, kind in MW_KINDS) for j in range(len(chunks))]
        # new text subsegments
        starts = [c.addr - BASE for c in chunks]
        if starts[0] != out[k][0]:
            sys.exit(f"{unit}: first block {chunks[0].label} does not start the unit")
        new_text = [[a, "c", f"{mod}/{c.label}", out[k][3] if j == 0 else []] for j, (a, c) in enumerate(zip(starts, chunks))]
        out[k:k + 1] = new_text
        # data: try to give each block the pieces it needs (one block owns all if only one has data)
        pidx = [j for j, s in enumerate(out) if s[2] == unit and s[1] in PIECE_TYPES]
        owner = None
        if pidx:
            if len(pidx) != 1:
                sys.exit(f"{unit}: several data subsegments")
            for j, t in enumerate(texts):
                seg_tmp = out
                chk.segs = seg_tmp
                ti = [k + j]
                why = chk.check(t, kind, ROOT / "src" / mod, ti, pidx)
                if why is None:
                    owner = j; break
            if owner is None:
                sys.exit(f"{unit}: no single block reproduces the unit's data; split it by hand")
            out[pidx[0]][2] = f"{mod}/{chunks[owner].label}"
        chk.segs = out
        for j, t in enumerate(texts):
            ti = [k + j]
            why = chk.check(t, kind, ROOT / "src" / mod, ti, pidx if j == owner else [])
            if why is not None:
                sys.exit(f"{unit}: block {chunks[j].label} does not match on its own: {why}")
        if args.dry_run:
            print(f"{unit}: would split into {len(chunks)} units"); continue
        for c, t in zip(chunks, texts):
            writes.append((ROOT / "src" / mod / (c.label + ".c"), t))
            if kind in OVR_OF:
                overrides[f"{mod}/{c.label}"] = OVR_OF[kind]
        overrides.pop(unit, None)
        unlinks.append(path)
        print(f"{unit}: split into {len(chunks)} units")
    if args.dry_run:
        return
    # only now that every unit passed: a failure above leaves the tree untouched
    for p in unlinks:
        p.unlink()
    for p, t in writes:
        p.write_text(t, newline="\n")
    y[i0:i1] = ip.dump_segments(out, indent)
    (ROOT / "config" / "splat.yaml").write_text("\n".join(y), newline="\n")
    op.write_text(json.dumps(overrides, indent=2) + "\n", newline="\n")


if __name__ == "__main__":
    main()
