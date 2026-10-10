#!/usr/bin/env python3
"""Generate build.ninja and objdiff.json for the Omega Strain matching decomp.

Usage (from the repository root):
    python configure.py            # split (if needed) and write build.ninja/objdiff.json
    ninja                          # build build/SCUS_972.64 and verify its SHA-256
    ninja report                   # objdiff progress report -> build/report.json

The user's own retail executable is read from orig/SCUS_972.64 (or the path
given with --elf). Nothing derived from it is ever written outside the
git-ignored directories asm/, build/, orig/ and .tools/.
"""
import argparse
import hashlib
import json
import os
import platform
import re
import shutil
import subprocess
import sys
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parent
CONFIG = ROOT / "config"
SPLAT_YAML = CONFIG / "splat.yaml"
EXPECTED_SHA256 = (CONFIG / "target.sha256").read_text().split()[0]

IS_WINDOWS = platform.system() == "Windows"
EXE = ".exe" if IS_WINDOWS else ""

DEFAULT_COMPILER = "mwcps2-3.0.3-020716"
# Sony SDK / middleware libraries were built with EE-GCC; units under src/lib/
# are compiled with this GCC build (Windows executable from decomp.me's archive).
DEFAULT_GCC = "ee-gcc2.95.3-136"
GCCFLAGS = "-c -O2 -G0 -w"
# Flags reproduced by test compiles against retail code (see PROGRESS.md).
CFLAGS = "-c -O4,p -nostdinc -sdatathreshold 0 -char signed -lang c"
ASFLAGS = "-EL -march=r5900 -mabi=eabi -no-pad-sections -G0 -Iinclude"


def find_elf(arg):
    cands = [Path(arg)] if arg else [ROOT / "orig" / "SCUS_972.64"]
    for c in cands:
        if c.is_file():
            return c
    sys.exit("Retail executable not found. Copy your own SCUS_972.64 to orig/ "
             "(see README.md) or pass --elf PATH.")


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def binutils_prefix(arg):
    if arg:
        return arg
    local = ROOT / ".tools" / "binutils" / "mips-ps2-decompals-"
    if Path(str(local) + "as" + EXE).exists():
        return str(local)
    for p in ("mips-ps2-decompals-", "mips-linux-gnu-", "mipsel-linux-gnu-"):
        if shutil.which(p + "as"):
            return p
    sys.exit("No MIPS binutils found; run `python tools/setup_tools.py` (see README.md).")


def subsegments(cfg):
    """Return [(start, type, name)] for the main code segment, in order."""
    seg = cfg["segments"][0]
    subs = []
    for s in seg["subsegments"]:
        if isinstance(s, dict):
            subs.append((s["start"], s["type"], s.get("name")))
        else:
            start, typ = s[0], s[1]
            name = s[2] if len(s) > 2 else None
            subs.append((start, typ, name))
    return subs


def unit_name(typ, name, start):
    # splat names unnamed subsegments after their rom offset in hex
    return name if name else f"{start:X}"


def ninja_path(p):
    return str(p).replace("\\", "/").replace(" ", "$ ").replace(":", "$:")


def cmd_path(p):
    """Path usable inside a ninja command: relative to the repository root when possible, quoted otherwise."""
    p = Path(p)
    try:
        relative = p.resolve().relative_to(ROOT)
        q = str(relative) if IS_WINDOWS else relative.as_posix()
    except (ValueError, OSError):
        q = str(p) if IS_WINDOWS else str(p).replace("\\", "/")
    if " " in q:
        q = f'"{q}"'
    return q.replace("$", "$$")


def compiler_directory(value):
    name, separator, directory = value.partition("=")
    if not separator or not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_.-]*", name) or not directory:
        raise argparse.ArgumentTypeError("expected NAME=DIRECTORY for --compiler-dir")
    return name, Path(directory)


def compiler_overrides(path, subs):
    if not path.exists():
        return {}
    try:
        overrides = json.loads(path.read_text())
    except (OSError, ValueError) as error:
        sys.exit(f"Cannot read {path}: {error}")
    if not isinstance(overrides, dict) or any(
        not isinstance(name, str) or not isinstance(version, str)
        or not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_.-]*", version)
        for name, version in overrides.items()
    ):
        sys.exit(f"{path}: expected a JSON object mapping C unit names to compiler names")
    units = {name for _, typ, name in subs if typ == "c"}
    for name in overrides:
        if name not in units:
            sys.exit(f"{path}: compiler override names unknown C unit {name}")
        if name.startswith("lib/"):
            sys.exit(f"{path}: cannot assign a Metrowerks compiler to GCC unit {name}")
    return overrides


def mwcc_path(version, directories, required=True):
    directory = directories.get(version, ROOT / ".tools" / "mwcc" / version)
    compiler = directory / "mwccps2.exe"
    if not compiler.is_file():
        if not required:
            return None
        sys.exit(f"Compiler {version!r} not found at {compiler}. "
                 f"Run tools/setup_tools.py for the default compiler, or supply your "
                 f"licensed installation with --compiler-dir {version}=DIRECTORY.")
    return compiler


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("--elf", help="path to your retail SCUS_972.64")
    ap.add_argument("--binutils", help="binutils prefix, e.g. mips-linux-gnu-")
    ap.add_argument("--compiler", default=DEFAULT_COMPILER,
                    help=f"compiler directory under .tools/mwcc (default {DEFAULT_COMPILER})")
    ap.add_argument("--compiler-dir", action="append", type=compiler_directory, default=[],
                    metavar="NAME=DIRECTORY",
                    help="local installation for a compiler named in config/compiler_overrides.json; repeatable")
    ap.add_argument("--gcc", default=DEFAULT_GCC,
                    help=f"EE-GCC directory under .tools/eegcc (default {DEFAULT_GCC})")
    ap.add_argument("--wrapper", default=None,
                    help="program used to run the Windows compiler on Linux/macOS (wibo or wine)")
    ap.add_argument("--objdiff", default=None, help="path to objdiff-cli")
    ap.add_argument("--no-split", action="store_true", help="do not (re)run splat")
    args = ap.parse_args()
    compiler_dirs = {}
    for name, directory in args.compiler_dir:
        if name in compiler_dirs:
            ap.error(f"duplicate --compiler-dir for {name}")
        compiler_dirs[name] = directory

    os.chdir(ROOT)
    elf = find_elf(args.elf)
    got = sha256(elf)
    if got != EXPECTED_SHA256:
        sys.exit(f"{elf} has SHA-256 {got}; expected the NTSC-U retail file {EXPECTED_SHA256}")

    rom = ROOT / "build" / "orig" / "SCUS_972.64.rom"
    rom.parent.mkdir(parents=True, exist_ok=True)
    if not rom.exists():
        subprocess.check_call([sys.executable, "tools/extract_rom.py", str(elf), str(rom)])

    cfg = yaml.safe_load(SPLAT_YAML.read_text())
    subs = subsegments(cfg)
    overrides = compiler_overrides(CONFIG / "compiler_overrides.json", subs)
    # The default compiler is required. A per-unit compiler that is not
    # installed (a licensed CodeWarrior build, say) is optional: its units are
    # then built from their retail assembly, so the build still matches.
    compilers = {version: mwcc_path(version, compiler_dirs, required=version == args.compiler)
                 for version in {args.compiler, *overrides.values()}}
    for version in sorted(v for v, c in compilers.items() if c is None):
        count = sum(1 for v in overrides.values() if v == version)
        print(f"warning: compiler {version!r} not found; building its {count} units from assembly "
              f"(supply it with --compiler-dir {version}=DIRECTORY)")
    stamp = ROOT / "build" / "splat.stamp"
    want = hashlib.sha256(SPLAT_YAML.read_bytes() + (CONFIG / "symbol_addrs.txt").read_bytes()).hexdigest()
    if not args.no_split and (not stamp.exists() or stamp.read_text() != want or not (ROOT / "asm").exists()):
        shutil.rmtree(ROOT / "asm", ignore_errors=True)
        subprocess.check_call([sys.executable, "-m", "splat", "split", str(SPLAT_YAML)])
        stamp.write_text(want)

    prefix = binutils_prefix(args.binutils)
    if Path(prefix + "as" + EXE).exists():
        tool = lambda t: cmd_path(prefix + t + EXE)
    else:
        tool = lambda t: prefix + t + EXE
    wrapper = args.wrapper
    if wrapper is None and not IS_WINDOWS:
        local_wibo = ROOT / ".tools" / "wibo"
        wrapper = (str(local_wibo) if local_wibo.exists() else None) or shutil.which("wibo") or shutil.which("wine") or "wibo"
    wrap = (f"{cmd_path(wrapper) if Path(wrapper).exists() else wrapper} " if wrapper else "")
    cc = wrap + cmd_path(compilers[args.compiler])
    gcc = wrap + cmd_path(ROOT / ".tools" / "eegcc" / args.gcc / "bin" / "ee-gcc.exe")
    objdiff = args.objdiff or str(ROOT / ".tools" / ("objdiff-cli" + EXE))

    asm_objs, c_units, link_objs, units = [], [], [], []
    for start, typ, name in subs:
        if typ in ("asm", "hasm", "data", "rodata", "bss"):
            uname = unit_name(typ, name, start)
            src = Path("asm") / ("data/" + uname + ".data.s" if typ == "data" else uname + ".s")
            if typ in ("rodata",):
                src = Path("asm") / "data" / (uname + ".rodata.s")
            obj = Path("build") / src.with_suffix(".o")
            asm_objs.append((src, obj, next(a for a in (16, 8, 4) if (start + 0x100000) % a == 0)))
            link_objs.append(obj)
            if typ in ("asm", "hasm"):
                units.append({"name": f"asm/{start + 0x100000:06X}", "target_path": str(obj).replace("\\", "/"),
                              "metadata": {"progress_categories": ["main"], "auto_generated": True}})
        elif typ == "c":
            src = Path("src") / (name + ".c")
            obj = Path("build") / "src" / (name + ".o")
            # splat (make_full_disasm_for_code) writes the retail code of the
            # unit to asm/<unit>.s; it is assembled as the objdiff target.
            target_s = Path("asm") / (name + ".s")
            target = Path("build") / "target" / (name + ".o")
            align = next(a for a in (16, 8, 4) if (start + 0x100000) % a == 0)
            if name in overrides and compilers[overrides[name]] is None:
                obj = Path("build") / "fallback" / (name + ".o")
                asm_objs.append((target_s, obj, align))
                link_objs.append(obj)
                units.append({"name": name, "target_path": str(obj).replace("\\", "/"),
                              "metadata": {"progress_categories": ["main"], "auto_generated": True}})
                continue
            c_units.append((src, obj, target_s, target, "gcc" if name.startswith("lib/") else "cc",
                            next(a for a in (16, 8, 4) if (start + 0x100000) % a == 0)))
            link_objs.append(obj)
            units.append({"name": name, "target_path": str(target).replace("\\", "/"),
                          "base_path": str(obj).replace("\\", "/"),
                          "metadata": {"progress_categories": ["main"], "complete": True,
                                       "source_path": str(src).replace("\\", "/")}})

    py = cmd_path(sys.executable)
    lines = [
        "# Generated by configure.py; do not edit.",
        "ninja_required_version = 1.10",
        f"as = {tool('as')}",
        f"ld = {tool('ld')}",
        f"objcopy = {tool('objcopy')}",
        f"cc = {cc}",
        f"gcc = {gcc}",
        f"gccflags = {GCCFLAGS} -Iinclude -Isrc",
        f"python = {py}",
        f"asflags = {ASFLAGS}",
        f"cflags = {CFLAGS} -Iinclude -Isrc",
        "",
        "rule as",
        "  command = $python tools/assemble.py $as $objcopy $align $out $in $asflags",
        "  description = AS $in",
        "rule cc",
        "  command = $cc $cflags -o $out $in",
        "  description = CC $in",
        "rule cc_aligned",
        "  command = $python tools/compile_aligned.py $objcopy $align $out $in -- $cc $cflags",
        "  description = CC $in",
        "rule gcc",
        "  command = $python tools/compile_aligned.py $objcopy $align $out $in -- $gcc $gccflags",
        "  description = GCC $in",
        "rule ld",
        "  command = $ld -EL -T build/undefined_syms_auto.txt -T build/undefined_funcs_auto.txt "
        "-T config/extra.ld -T build/link.ld -Map build/SCUS_972.64.map "
        "--no-check-sections -o $out @build/link.rsp",
        "  description = LD $out",
        "rule image",
        "  command = $objcopy -O binary $in $out",
        "  description = OBJCOPY $out",
        "rule elf",
        "  command = $python tools/elf_rebuild.py $in config/elf_layout.json $out",
        "  description = ELF $out",
        "rule check",
        f"  command = $python tools/check_sha256.py $in {EXPECTED_SHA256} $out",
        "  description = CHECK $in",
        "rule report",
        f"  command = {cmd_path(objdiff)} report generate -p . -o $out",
        "  description = REPORT $out",
        "  pool = console",
        "",
    ]
    for src, obj, align in asm_objs:
        lines.append(f"build {ninja_path(obj)}: as {ninja_path(src)}")
        lines.append(f"  align = {align}")
    for src, obj, target_s, target, rule, align in c_units:
        # Metrowerks aligns .text to 16; a unit starting on an 8-byte boundary
        # gets the alignment its retail address implies, like the GCC units.
        if rule == "cc" and align != 16:
            rule = "cc_aligned"
        lines.append(f"build {ninja_path(obj)}: {rule} {ninja_path(src)}")
        if rule != "cc":
            lines.append(f"  align = {align}")
        if rule != "gcc":
            name = src.relative_to("src").with_suffix("").as_posix()
            if name in overrides:
                lines.append(f"  cc = {wrap}{cmd_path(compilers[overrides[name]])}")
        lines.append(f"build {ninja_path(target)}: as {ninja_path(target_s)}")
        lines.append("  align = 16")
    targets = " ".join(ninja_path(u[3]) for u in c_units)
    lines += [
        f"build build/SCUS_972.64.elf: ld | {' '.join(ninja_path(o) for o in link_objs)} build/link.ld build/link.rsp config/extra.ld",
        "build build/SCUS_972.64.rom: image build/SCUS_972.64.elf",
        "build build/SCUS_972.64: elf build/SCUS_972.64.rom | config/elf_layout.json tools/elf_rebuild.py",
        "build build/SCUS_972.64.ok: check build/SCUS_972.64",
        f"build targets: phony {targets}",
        "build build/report.json: report | build/SCUS_972.64.ok targets objdiff.json",
        "build report: phony build/report.json",
        "default build/SCUS_972.64.ok targets",
        "",
    ]
    (ROOT / "build.ninja").write_text("\n".join(lines))

    # Objects are passed in address order on the command line (via a response
    # file) and collected with plain wildcards. This is equivalent to splat's
    # per-object linker script but much faster for thousands of objects.
    (ROOT / "build" / "link.rsp").write_text("\n".join(str(o).replace("\\", "/") for o in link_objs) + "\n")
    gp = cfg["options"]["gp_value"]
    seg = cfg["segments"][0]
    (ROOT / "build" / "link.ld").write_text(f"""SECTIONS
{{
    _gp = {gp:#x};
    .main {seg["vram"]:#x} : AT(0)
    {{
        FILL(0x00000000);
        /* one pattern keeps the command-line (address) order of all objects */
        *(.text* .data* .rodata* .sdata*)
        . = ALIGN(16);
    }}
    /DISCARD/ : {{ *(*) }}
}}
""")

    objdiff_cfg = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "custom_make": "ninja",
        "custom_args": [],
        "build_target": False,
        "build_base": True,
        "watch_patterns": ["*.c", "*.h", "*.s", "*.yaml", "*.txt"],
        "progress_categories": [{"id": "main", "name": "SCUS_972.64"}],
        "units": units,
    }
    (ROOT / "objdiff.json").write_text(json.dumps(objdiff_cfg, indent=2) + "\n")
    print(f"wrote build.ninja and objdiff.json ({len(c_units)} C units, {len(asm_objs)} asm objects)")


if __name__ == "__main__":
    main()
