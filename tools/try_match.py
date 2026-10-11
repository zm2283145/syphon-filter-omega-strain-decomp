#!/usr/bin/env python3
"""Run a small, serial compiler/pragma experiment without changing the source.

Examples (from the repository root):
  python tools/try_match.py src/main/example.c
  python tools/try_match.py candidate.c -c mw,mw38 --profiles source,no-peephole
  python tools/try_match.py candidate.c -c mw38 --compiler-dir mw38=LICENSED_DIR
  python tools/try_match.py candidate.c --profiles source,no-propagation --keep exact --json

Supported builds: mw (3.0.3), mw38 (3.0 build 38), mw304 (3.04 build 22).
No tools are downloaded. --compiler-dir selects an existing licensed installation.
The default is one source-profile trial with mw. Selection order is preserved;
duplicates and plans over --max-trials are rejected, never silently truncated.
There are at most 15 trials, with a separate bounded timeout for each compiler.

Profiles request a pragma PREFIX, not a forced setting for every function.
The compiler's -prefix option preserves the original source and its own pragmas.
Source/header pragmas take precedence over the prefix; its effect is NOT verified.
Successful compiler warnings are included in the report. The source profile
adds no prefix or pragmas. Include paths are made absolute before compiling in
scratch. The checker's repository-root-first include search is preserved; add
-I for source-relative header directories, including nested ones, as needed.

Per-function exact means check_match.compare returned MATCH; near means its
actual DIFF diagnostic, NOT a similarity threshold, percentage, or mismatch
count. Unknown addresses remain unresolved. Failed compiles cannot yield
per-function results. No trial is whole-build verified, even if every function
is exact. Undefined-symbol diagnostics must also be reviewed.

Only existing --rom and --symbols inputs are read; caches are never regenerated.
All compiler working files live in unique ignored build/try-match-* directories,
even when inputs or compiler installations are elsewhere. Transients are removed
on failure as well as success. --keep exact retains objects with at least one
exact function; --keep all retains every successfully compared object. Both keep
the JSON report and selected prefix files, but not failed/partial objects.
Exit status: 0 for completed comparisons (including differences), 1 if any trial
failed, 2 for invalid input, 130 for interruption.
"""
import argparse
import hashlib
import json
import math
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time

from elftools.common.exceptions import ELFError

if __package__:
    from . import check_match
else:
    import check_match


ROOT = Path(__file__).resolve().parent.parent
COMPILERS = {
    "mw": "mwcps2-3.0.3-020716",
    "mw38": "cwps2-3.0b38",
    "mw304": "cwps2-3.04",
}
PROFILES = {
    "source": (),
    "no-peephole": ("#pragma peephole off",),
    "no-common-subs": ("#pragma opt_common_subs off",),
    "no-propagation": ("#pragma opt_propagation off",),
    "no-strength-reduction": ("#pragma opt_strength_reduction off",),
}
MAX_TRIALS = len(COMPILERS) * len(PROFILES)
PREFIX_NOTICE = (
    "Requested prefix only; source/header pragmas take precedence. "
    "Effective per-function settings are not verified."
)


def selection(value, choices):
    selected = tuple(part.strip() for part in value.split(","))
    if any(part not in choices for part in selected):
        raise argparse.ArgumentTypeError("choose a comma list from: " + ", ".join(choices))
    if len(set(selected)) != len(selected):
        raise argparse.ArgumentTypeError("duplicate selections are not allowed")
    return selected


def compiler_directory(value):
    name, separator, directory = value.partition("=")
    if not separator or name not in COMPILERS or not directory:
        raise argparse.ArgumentTypeError("expected mw|mw38|mw304=DIRECTORY")
    return name, Path(directory).resolve()


def trial_limit(value):
    number = int(value)
    if not 1 <= number <= MAX_TRIALS:
        raise argparse.ArgumentTypeError(f"must be between 1 and {MAX_TRIALS}")
    return number


def timeout_seconds(value):
    number = float(value)
    if not math.isfinite(number) or not 0 < number <= 300:
        raise argparse.ArgumentTypeError("must be greater than 0 and at most 300 seconds")
    return number


def parser():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", type=Path)
    ap.add_argument("-c", "--compilers", type=lambda s: selection(s, COMPILERS),
                    default=("mw",), help="comma list: mw,mw38,mw304 (default: mw)")
    ap.add_argument("--profiles", type=lambda s: selection(s, PROFILES), default=("source",),
                    help="comma list: " + ",".join(PROFILES) + " (default: source)")
    ap.add_argument("--max-trials", type=trial_limit, default=6,
                    help=f"reject larger plans before compiling (default: 6, hard cap: {MAX_TRIALS})")
    ap.add_argument("--timeout", type=timeout_seconds, default=30.0,
                    help="seconds per compiler invocation (default: 30, maximum: 300)")
    ap.add_argument("--compiler-dir", action="append", type=compiler_directory, default=[],
                    metavar="NAME=DIRECTORY", help="repeatable; directory containing mwccps2.exe")
    ap.add_argument("--wrapper", help="program to run Windows compilers elsewhere (default: check_match wrapper)")
    ap.add_argument("-I", dest="includes", action="append", type=Path, default=[],
                    help="include directory; repeatable, searched before repository include/ and src/")
    ap.add_argument("--rom", type=Path, default=ROOT / "build" / "orig" / "SCUS_972.64.rom")
    ap.add_argument("--symbols", type=Path, default=ROOT / "build" / "check_symbols.json",
                    help="existing check_match symbol JSON; never regenerated")
    ap.add_argument("--keep", choices=("none", "exact", "all"), default="none")
    ap.add_argument("--json", action="store_true", help="print one JSON report instead of text")
    return ap


def plan(args):
    count = len(args.compilers) * len(args.profiles)
    if count > args.max_trials or count > MAX_TRIALS:
        raise ValueError(f"{count} trials exceed the limit of {min(args.max_trials, MAX_TRIALS)}; "
                         "select fewer compilers/profiles or explicitly raise --max-trials")
    directories = {}
    for name, directory in args.compiler_dir:
        if name in directories:
            raise ValueError(f"duplicate --compiler-dir for {name}")
        directories[name] = directory
    return [(kind, profile) for kind in args.compilers for profile in args.profiles], directories


def read_symbols(path):
    # Deliberately do not call symbols(): it can regenerate caches in an input checkout.
    data = json.loads(path.read_bytes())
    if not isinstance(data, dict) or not isinstance(data.get("names"), dict) or not isinstance(data.get("starts"), list):
        raise ValueError(f"{path}: expected names object and starts list")
    names, starts = data["names"], data["starts"]
    if (any(not isinstance(name, str) or type(addr) is not int or not 0 <= addr <= 0xFFFFFFFF
            for name, addr in names.items())
            or any(type(addr) is not int or not 0 <= addr <= 0xFFFFFFFF for addr in starts)):
        raise ValueError(f"{path}: symbol addresses must be unsigned 32-bit integers")
    return names, set(starts)


def compiler_path(kind, directories):
    env_name = {"mw38": "CW38_DIR", "mw304": "CW304_DIR"}.get(kind)
    default = ROOT / ".tools" / "mwcc" / COMPILERS[kind]
    if env_name and os.environ.get(env_name):
        default = Path(os.environ[env_name])
    return (directories.get(kind, default) / "mwccps2.exe").resolve()


def output_text(value):
    return value.decode(errors="replace") if isinstance(value, bytes) else (value or "")


def diagnostics(stdout, stderr):
    return (output_text(stdout)[-3000:] + output_text(stderr)[-1500:]).strip()


def compare_functions(obj, rom, names, starts):
    results, undefined = check_match.compare(obj, rom, names, starts)
    functions = []
    for name, address, result in results:
        status = "exact" if result == "MATCH" else "near" if result.startswith("DIFF at ") else "unresolved"
        functions.append({"name": name, "addr": f"{address:08X}" if address is not None else None,
                          "status": status, "result": result})
    return functions, undefined


def run_trial(kind, profile, source, command_prefix, includes, directory, timeout, rom, names, starts):
    started = time.perf_counter()
    obj = directory / "candidate.o"
    requested = PROFILES[profile]
    prefix_flags = []
    if requested:
        prefix = directory / "prefix.c"
        prefix.write_text("\n".join(requested) + "\n", encoding="ascii")
        prefix_flags = ["-prefix", str(prefix)]
    command = (command_prefix + list(check_match.MWFLAGS) + ["-cwd", "explicit"] + includes
               + prefix_flags + ["-o", str(obj), str(source)])
    result = {"compiler": kind, "profile": profile, "requested_pragmas": list(requested),
              "profile_effect": PREFIX_NOTICE if requested else "Unmodified source; no requested pragmas.",
              "command": command, "status": "compile-failure", "functions": [], "undefined": [],
              "compile_seconds": 0.0, "compare_seconds": 0.0, "diagnostics": ""}
    try:
        completed = subprocess.run(command, cwd=directory, capture_output=True, text=True,
                                   errors="replace", timeout=timeout)
    except subprocess.TimeoutExpired as error:
        result["error"] = f"compiler timed out after {timeout:g} seconds"
        result["diagnostics"] = diagnostics(error.stdout, error.stderr)
    except OSError as error:
        result["error"] = f"cannot run compiler: {error}"
    else:
        result["returncode"] = completed.returncode
        result["diagnostics"] = diagnostics(completed.stdout, completed.stderr)
        if completed.returncode:
            result["error"] = f"compiler exited with status {completed.returncode}"
        elif not obj.is_file():
            result["error"] = "compiler reported success but produced no object"
        else:
            result["status"] = "compiled"
    result["compile_seconds"] = time.perf_counter() - started
    if result["status"] == "compiled":
        compare_started = time.perf_counter()
        try:
            result["functions"], result["undefined"] = compare_functions(obj, rom, names, starts)
        except (ELFError, OSError, ValueError, struct.error) as error:
            result["status"] = "compare-failure"
            result["error"] = f"{type(error).__name__}: {error}"
        else:
            result["status"] = "compared"
        result["compare_seconds"] = time.perf_counter() - compare_started
    result["total_seconds"] = time.perf_counter() - started
    return result


def run_trials(args):
    trials, directories = plan(args)
    source = args.source.resolve()
    if source.suffix.lower() != ".c":
        raise ValueError("source must be a .c file (the checker uses -lang c)")
    original = source.read_bytes()
    rom_path, symbols_path = args.rom.resolve(), args.symbols.resolve()
    rom = rom_path.read_bytes()
    if not rom:
        raise ValueError(f"{rom_path}: empty retail ROM")
    names, starts = read_symbols(symbols_path)
    # MW normally searches cwd first. Reproduce the checker's ROOT cwd without
    # letting compiler side effects or implicit header lookup escape scratch.
    includes = [f"-I{path.resolve()}" for path in [ROOT] + args.includes + [ROOT / "include", ROOT / "src"]]
    if args.wrapper:
        wrapper_path = Path(args.wrapper)
        wrapper = [str(wrapper_path.resolve()) if wrapper_path.parent != Path(".")
                   or wrapper_path.is_file() else args.wrapper]
    else:
        wrapper = check_match.wrapper()
    source_pragmas = re.findall(rb"(?m)^[ \t]*#[ \t]*pragma[^\r\n]*", original)
    report = {"source": str(source), "source_sha256": hashlib.sha256(original).hexdigest(),
              "source_pragmas": [line.decode(errors="replace").strip() for line in source_pragmas],
              "rom": str(rom_path), "rom_sha256": hashlib.sha256(rom).hexdigest(),
              "symbols": str(symbols_path), "whole_build_verified": False,
              "notice": "Object comparisons only; a passing candidate is NOT whole-build verified.",
              "near_meaning": "Checker DIFF, not a measured similarity threshold or mismatch count.",
              "trial_count": len(trials), "timeout_seconds": args.timeout, "trials": [],
              "retained_directory": None}
    build = ROOT / "build"
    build.mkdir(exist_ok=True)
    run_directory = Path(tempfile.mkdtemp(prefix="try-match-", dir=build))
    retained = False
    started = time.perf_counter()
    try:
        for index, (kind, profile) in enumerate(trials, 1):
            with tempfile.TemporaryDirectory(prefix=f"{index:02d}-{kind}-", dir=run_directory) as scratch:
                directory = Path(scratch)
                compiler = compiler_path(kind, directories)
                result = run_trial(kind, profile, source, wrapper + [str(compiler)], includes,
                                   directory, args.timeout, rom, names, starts)
                if source.read_bytes() != original:
                    raise ValueError("source changed during trials; results discarded (source was not restored)")
                keep_object = result["status"] == "compared" and (
                    args.keep == "all" or args.keep == "exact" and
                    any(function["status"] == "exact" for function in result["functions"]))
                if keep_object:
                    destination = run_directory / f"{index:02d}-{kind}-{profile}"
                    destination.mkdir()
                    shutil.copyfile(directory / "candidate.o", destination / "candidate.o")
                    if PROFILES[profile]:
                        shutil.copyfile(directory / "prefix.c", destination / "prefix.c")
                    result["retained_object"] = str(destination / "candidate.o")
                report["trials"].append(result)
        report["total_seconds"] = time.perf_counter() - started
        if args.keep != "none":
            report["retained_directory"] = str(run_directory)
            (run_directory / "report.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
            retained = True
        return report
    finally:
        if not retained:
            shutil.rmtree(run_directory)


def print_report(report):
    print(report["notice"])
    print("near = " + report["near_meaning"])
    if report["source_pragmas"]:
        print("Existing source pragmas (preserved; may override requested prefixes):")
        for pragma in report["source_pragmas"]:
            print("  " + pragma)
    for trial in report["trials"]:
        label = f"[{trial['compiler']} / requested {trial['profile']}]"
        print(f"{label} {trial['status']} ({trial['compile_seconds']:.3f}s compile, "
              f"{trial['compare_seconds']:.3f}s compare)")
        if trial["requested_pragmas"]:
            print("  " + trial["profile_effect"])
        if "error" in trial:
            print("  " + trial["error"] + "; per-function results unavailable")
        if trial["status"] == "compared" and not trial["functions"]:
            print("  No comparable functions; not an exact candidate.")
        for function in trial["functions"]:
            print(f"  {function['name']}: {function['status']} - {function['result']}")
        for undefined in trial["undefined"]:
            print("  UNDEF " + undefined)
        if trial["diagnostics"]:
            print(trial["diagnostics"])
    print(f"{report['trial_count']} serial trials in {report['total_seconds']:.3f}s")
    if report["retained_directory"]:
        print("Retained results: " + report["retained_directory"])


def main(argv=None):
    ap = parser()
    args = ap.parse_args(argv)
    try:
        report = run_trials(args)
    except (OSError, ValueError) as error:
        ap.error(str(error))
    except KeyboardInterrupt:
        print("Interrupted; transient trial outputs removed.", file=sys.stderr)
        return 130
    if args.json:
        print(json.dumps(report))
    else:
        print_report(report)
    return int(any(trial["status"] != "compared" for trial in report["trials"]))


if __name__ == "__main__":
    sys.exit(main())
