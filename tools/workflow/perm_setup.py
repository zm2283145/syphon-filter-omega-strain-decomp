#!/usr/bin/env python3
"""Make a decomp-permuter directory for a near-miss draft (WSL).

  ~/permvenv/bin/python tools/workflow/perm_setup.py draft.c FUNC OUTDIR [-c mw38|mw304|mw50]
  ~/permvenv/bin/python ~/decomp-permuter/permuter.py OUTDIR -j 16 --stop-on-zero

base.c is the draft preprocessed with gcc's cpp (import.py's stubs for
__attribute__/__asm__), compile.sh runs mwccps2 through wibo with
check_match.py's flags, and target.o is the function's retail asm
(asm/*.s from splat) assembled with the project's binutils. Any result
must still pass tools/check_match.py and tools/workflow/verify_pending.ps1.
"""
import argparse, os, re, shlex, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PERM = Path(os.environ.get("PERMUTER_DIR", Path.home() / "decomp-permuter"))
sys.path.insert(0, str(PERM))
import importlib.util  # noqa: E402
_spec = importlib.util.spec_from_file_location("perm_import", PERM / "import.py")
_imp = importlib.util.module_from_spec(_spec); _spec.loader.exec_module(_imp)

MWFLAGS = ["-c", "-O4,p", "-nostdinc", "-sdatathreshold", "0", "-char", "signed", "-lang", "c", "-Iinclude", "-Isrc"]
ASFLAGS = ["-EL", "-march=r5900", "-mabi=eabi", "-no-pad-sections", "-G0", "-Iinclude"]
CW = {"mw38": "CW38_DIR", "mw304": "CW304_DIR", "mw50": "CW50_DIR"}


def find_asm(func):
    pat = re.compile(r"^glabel " + re.escape(func) + r"\s*$", re.M)
    for p in sorted((ROOT / "asm").glob("**/*.s")):
        t = p.read_text(errors="replace")
        if pat.search(t):
            m = re.search(r"^glabel " + re.escape(func) + r"\s*\n(.*?)^endlabel " + re.escape(func), t, re.M | re.S)
            return m.group(0) + "\n"
    raise SystemExit(f"no asm for {func}")


# The permuter's cpp stubs out __attribute__ (pycparser can't parse it), but
# alignment changes code, so compile.sh puts each one back on its declarator.
REATTR = r'''import re, sys
s = open(sys.argv[1]).read()
for name, attr in @ATTRS@:
    a = " __attribute__((" + attr + "))"
    s, n = re.subn(r"(\}\s*)(" + name + r"\s*;)", r"\1" + a + r" \2", s, count=1)
    if not n:
        s = re.sub(r"\b(" + name + r"(?:\s*\[[^\]]*\])*)(\s*[;=,])", r"\1" + a + r"\2", s, count=1)
s = re.sub(r"(?<![\w.])(?:__asm__|asm)(?:\s+volatile|\s+__volatile__)?\s*\(", "__asm__ volatile (", s)
sys.stdout.write(s)
'''


def find_attrs(compiler, draft):
    cpp = _imp.CPP + [str(draft)] + [x for x in compiler if x.startswith("-I") or x == "-nostdinc"]
    s = subprocess.check_output(cpp + ["-D_Static_assert(x, y)="], cwd=ROOT, encoding="utf-8")
    out = []
    att = r"__attribute__\s*\(\(((?:[^()]|\([^()]*\))*)\)\)"
    for m in re.finditer(att + r"\s*(\w+)\s*;", s):
        out.append((m.group(2), m.group(1)))
    for m in re.finditer(r"(\w+)\s*((?:\[[^\]]*\]\s*)*)" + att, s):
        if m.group(1) not in ("struct", "union", "__attribute__"):
            out.append((m.group(1), m.group(3)))
    return list(dict.fromkeys(out))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("draft"); ap.add_argument("func"); ap.add_argument("outdir")
    ap.add_argument("-c", "--compiler", default="mw38")
    a = ap.parse_args()
    out = Path(a.outdir).resolve(); out.mkdir(parents=True, exist_ok=True)
    cwdir = (str(ROOT / ".tools" / "mwcc" / "mwcps2-3.0.3-020716") if a.compiler == "mw"
             else os.environ.get(CW[a.compiler]) or sys.exit(f"set {CW[a.compiler]}"))
    compiler = [str(ROOT / ".tools" / "wibo"), str(Path(cwdir) / "mwccps2.exe")] + MWFLAGS
    draft = Path(a.draft).resolve()
    src = _imp.import_c_file(compiler, str(ROOT), str(draft), None)
    src = re.sub(r"__asm__\s+volatile\s*\(", "__asm__(", src)
    source, _ = _imp.prune_source(src, False, a.func)
    (out / "base.c").write_text(source)
    attrs = find_attrs(compiler, draft)
    (out / "reattr.py").write_text(REATTR.replace("@ATTRS@", repr(attrs)))
    cmd = " ".join(shlex.quote(x) for x in compiler)
    (out / "compile.sh").write_text(
        "#!/usr/bin/env bash\nset -uo pipefail\n"
        'INPUT="$(realpath "$1")"\nOUTPUT="$(realpath "$3")"\n'
        f'T="$(mktemp --suffix=.c)"\npython3 {shlex.quote(str(out / "reattr.py"))} "$INPUT" > "$T"\n'
        f"cd {shlex.quote(str(ROOT))}\n{cmd} \"$T\" -o \"$OUTPUT\"; rc=$?\nrm -f \"$T\"\nexit $rc\n")
    os.chmod(out / "compile.sh", 0o755)
    if attrs:
        print("re-inserted attributes:", attrs)
    body = re.sub(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/", "    ", find_asm(a.func), flags=re.M)
    (out / "target.s").write_text('.include "macro.inc"\n.set noat\n.set noreorder\n.section .text, "ax"\n' + body)
    subprocess.check_call([str(ROOT / ".tools" / "binutils" / "mips-ps2-decompals-as")] + ASFLAGS
                          + [str(out / "target.s"), "-o", str(out / "target.o")], cwd=ROOT)
    _imp.create_write_settings_toml(a.func, "mwcc", str(out / "settings.toml"),
                                    str(ROOT / ".tools" / "binutils" / "mips-ps2-decompals-objdump") + " -drz -m mips:5900")
    _imp.compile_base(str(out / "compile.sh"), source, str(draft), str(out / "base.o"))
    print(f"ready: {out}")


if __name__ == "__main__":
    main()
