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
        q = p.resolve().relative_to(ROOT).as_posix()
    except (ValueError, OSError):
        q = str(p).replace("\\", "/")
    if " " in q:
        q = f'"{q}"'
    return q.replace("$", "$$")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("--elf", help="path to your retail SCUS_972.64")
    ap.add_argument("--binutils", help="binutils prefix, e.g. mips-linux-gnu-")
    ap.add_argument("--compiler", default=DEFAULT_COMPILER,
                    help=f"compiler directory under .tools/mwcc (default {DEFAULT_COMPILER})")
    ap.add_argument("--wrapper", default=None,
                    help="program used to run the Windows compiler on Linux/macOS (wibo or wine)")
    ap.add_argument("--objdiff", default=None, help="path to objdiff-cli")
    ap.add_argument("--no-split", action="store_true", help="do not (re)run splat")
    args = ap.parse_args()

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
    compiler_dir = ROOT / ".tools" / "mwcc" / args.compiler
    mwcc = compiler_dir / "mwccps2.exe"
    wrapper = args.wrapper
    if wrapper is None and not IS_WINDOWS:
        local_wibo = ROOT / ".tools" / "wibo"
        wrapper = (str(local_wibo) if local_wibo.exists() else None) or shutil.which("wibo") or shutil.which("wine") or "wibo"
    cc = (f"{cmd_path(wrapper) if Path(wrapper).exists() else wrapper} " if wrapper else "") + cmd_path(mwcc)
    objdiff = args.objdiff or str(ROOT / ".tools" / ("objdiff-cli" + EXE))

    subs = subsegments(cfg)
    asm_objs, c_units, link_objs, units = [], [], [], []
    for start, typ, name in subs:
        if typ in ("asm", "hasm", "data", "rodata", "bss"):
            uname = unit_name(typ, name, start)
            src = Path("asm") / ("data/" + uname + ".data.s" if typ == "data" else uname + ".s")
            if typ in ("rodata",):
                src = Path("asm") / "data" / (uname + ".rodata.s")
            obj = Path("build") / src.with_suffix(".o")
            asm_objs.append((src, obj))
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
            c_units.append((src, obj, target_s, target))
            link_objs.append(obj)
            units.append({"name": name, "target_path": str(target).replace("\\", "/"),
                          "base_path": str(obj).replace("\\", "/"),
                          "metadata": {"progress_categories": ["main"], "complete": False,
                                       "source_path": str(src).replace("\\", "/")}})

    py = cmd_path(sys.executable)
    lines = [
        "# Generated by configure.py; do not edit.",
        "ninja_required_version = 1.10",
        f"as = {tool('as')}",
        f"ld = {tool('ld')}",
        f"objcopy = {tool('objcopy')}",
        f"cc = {cc}",
        f"python = {py}",
        f"asflags = {ASFLAGS}",
        f"cflags = {CFLAGS} -Iinclude -Isrc",
        "",
        "rule as",
        "  command = $as $asflags -o $out $in",
        "  description = AS $in",
        "rule cc",
        "  command = $cc $cflags -o $out $in",
        "  description = CC $in",
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
    for src, obj in asm_objs:
        lines.append(f"build {ninja_path(obj)}: as {ninja_path(src)}")
    for src, obj, target_s, target in c_units:
        lines.append(f"build {ninja_path(obj)}: cc {ninja_path(src)}")
        lines.append(f"build {ninja_path(target)}: as {ninja_path(target_s)}")
    targets = " ".join(ninja_path(t) for *_, t in c_units)
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
    .main {seg["vram"]:#x} : AT(0) SUBALIGN(16)
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
