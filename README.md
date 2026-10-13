# Syphon Filter: The Omega Strain — matching decompilation

This repository holds a **matching decompilation** of the PS2 executable
`SCUS_972.64` (NTSC-U). The goal is C source that, built with the original
compiler, reproduces the retail executable byte for byte.

No game data is stored in Git. You need your own copy of the game; every file
derived from it (split assembly, objects, the rebuilt executable) is created
locally in git-ignored folders.

## Status

See [PROGRESS.md](PROGRESS.md) for the current match percentage, evidence and
open decisions, and [DECOMP_DEV.md](DECOMP_DEV.md) for listing on decomp.dev.
To continue the work, start with [docs/HANDOFF.md](docs/HANDOFF.md).

## Toolchain (identified)

| Part | Tool |
| --- | --- |
| Game code | Metrowerks CodeWarrior for PS2, `mwccps2` (C/C++), flags `-O4,p` |
| Linker (original) | `mwldps2` — writes `.comment = "MW MIPS C Compiler (2.4.1.01)"` |
| SDK / middleware | prebuilt Sony libraries (libgraph/libpad2 "2800" = SDK 2.8), Medius 1.50, lgaud, 989snd — built with EE-GCC |
| Here: split | [splat](https://github.com/ethteck/splat) (`config/splat.yaml`) |
| Here: assemble/link | GNU binutils for MIPS (`binutils-mips-ps2-decompals`) |
| Here: compile | `mwcps2-3.0.3-020716` by default; per-unit overrides use CodeWarrior PS2 3.0 build 38 and 3.04 build 22; libraries use EE-GCC 2.95.3-136 and 2.96 |
| Here: diff/progress | [objdiff](https://github.com/encounter/objdiff) |

## Layout

```
./
  configure.py            generates build.ninja + objdiff.json, runs splat
  config/
    splat.yaml            splat config: which address ranges are C and which stay asm
    symbol_addrs.txt      known symbol names/addresses
    compiler_overrides.json  per-unit Metrowerks compiler selections
    target.sha256         SHA-256 of the retail executable (the build target)
    elf_layout.json       ELF container metadata (header layout of the retail file)
    extra.ld              extra linker definitions
  src/                    hand-written C (committed)
  include/                headers (splat's generated macro.inc/include_asm.h are ignored)
  tools/                  helper scripts
  orig/                   PUT YOUR SCUS_972.64 HERE (ignored)
  asm/  build/  .tools/   generated / downloaded (ignored)
```

## Setup

Requirements: Python 3.10+ and an internet connection for the one-time tool
download. Windows runs everything natively; Linux/macOS run the Windows
compiler through [wibo](https://github.com/decompals/wibo) (downloaded on Linux)
or wine.

1. **Your executable.** Copy `SCUS_972.64` from the root of your own disc (or an
   image of it) to `orig/SCUS_972.64`. Its SHA-256 must be
   `9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6`.
2. **Python packages** (a virtual environment is recommended):
   ```
   python -m venv .venv
   .venv\Scripts\activate          # Linux/macOS: source .venv/bin/activate
   pip install -r requirements.txt
   ```
3. **Tools.** `python tools/setup_tools.py` downloads into `.tools/`:
   MIPS binutils, the CodeWarrior PS2 compiler build used here, objdiff-cli and
   (Linux) wibo. The compiler is proprietary Metrowerks software archived by
   decomp.me; download it only if you are entitled to use it. It is never
   committed.
4. **Additional compilers.** Units listed in `config/compiler_overrides.json`
   use CodeWarrior PS2 3.0 build 38 and, for one retained static initializer,
   3.04 build 22. Both installations are licensed tools and are not included
   or downloaded by the setup script. Pass their command-line tools directories
   when configuring:
   ```
   python configure.py --compiler-dir "cwps2-3.0b38=<licensed build 38 directory>" --compiler-dir "cwps2-3.04=<licensed build 3.04 directory>"
   ninja
   ```
   Replace each placeholder with its compiler directory containing `mwccps2.exe`
   and its normal runtime/license files. Alternatively, put installations under
   `.tools/mwcc/cwps2-3.0b38/` and `.tools/mwcc/cwps2-3.04/`. Compiler files and
   generated configuration remain ignored.
   `configure.py` checks your executable's hash, extracts the program image,
   runs splat (about a minute; reruns only when the yaml or symbols change)
   and writes `build.ninja` and `objdiff.json`. `ninja` assembles the asm,
   compiles `src/`, links, rebuilds the ELF container and verifies the result:

   ```
   OK: build/SCUS_972.64 matches retail SCUS_972.64 (SHA-256 9924da91...)
   ```

## Per-unit compiler selection

`--compiler` selects the default Metrowerks compiler; it does not replace the
explicit selections in `config/compiler_overrides.json`. That file maps C unit
names from `splat.yaml` (without `src/` or `.c`) to compiler names. Unlisted game
units retain the default compiler, and `src/lib/` units retain EE-GCC.

`--compiler-dir NAME=DIRECTORY` supplies a local installation without committing
machine-specific paths. The option is repeatable and must be supplied again
when configuring unless the installation lives under `.tools/mwcc/NAME/`.
Missing override compilers fall back to the matching retail assembly with a
warning; unknown units and attempted GCC-unit overrides are errors. Keep
compiler choices per-unit: the exact retail hash is the final check, not an
object comparison or compiler-version guess.

The configuration tests run with
`python -m unittest discover -s tests -p "test_configure.py"`.

## Progress report (objdiff)

```
ninja report          # -> build/report.json
python tools/publish_report.py   # -> progress/report.json (commit it; CI uploads it for decomp.dev)
```

`objdiff.json` lists one unit per C file (target = the retail code of that
range, assembled from splat's output; base = the compiled C) and one unit per
remaining asm chunk (target only, counted as not yet decompiled). Open the
repository folder in the objdiff GUI to diff functions interactively.

## Automatic decompilation of simple functions

`tools/autodecomp/` translates functions that are still assembly into C,
compiles them and keeps only byte-identical results:

```
python tools/autodecomp/run.py scan       # -> build/autodecomp/candidates.c
python tools/autodecomp/run.py verify     # compile + compare with the retail bytes
python tools/autodecomp/run.py integrate  # add verified functions to src/main and the yaml
python configure.py && ninja              # must still print OK
```

The output is low-level C (one variable per register, pointer arithmetic);
treat it as a starting point for real types and names.

## Matching a function

### Prioritize families and byte gains

Rank unowned functions before choosing the next matching task:

```
python tools\rank_candidates.py --start 0x00400000 --end 0x00476B00
python tools\rank_candidates.py --start 0x00400000 --end 0x00476B00 --json > build\candidate-ranking.json
```

The ranking uses ordered `splat.yaml` ownership and section-relative objdiff
addresses, so secondary functions in an existing C unit are not offered as new
work. Function sizes count toward potential gains; gaps and crossing functions
do not. With generated `asm/` available, it groups repeated instruction patterns
while preserving registers, constants, external calls and relocation expressions.
Groups are heuristic candidates, not matches or measured completion-time estimates.
Warnings identify missing inventory, incomplete signatures and stale ownership.

`--input-root`, `--config`, `--report` and `--asm-root` select read-only snapshots.
An optional `--research-index` points to a port research `ADDRESS_INDEX.md` and
adds document citations and research-supported byte totals. Native-port behavior
is useful evidence for readable source, but does not establish a compiler match.

### Run bounded compiler experiments

After configuring and generating a current `check_match.py` symbol cache, compare
a candidate with a small, explicitly selected compiler/profile matrix:

```
python tools\try_match.py candidate.c -c mw,mw38 --profiles source,no-peephole --compiler-dir "mw38=<licensed build 38 directory>" --keep exact --json
```

The default is one serial `mw`/`source` trial. Plans are limited to six trials
unless `--max-trials` is explicitly raised, with a hard ceiling of 15 and a
per-compiler timeout. Available profiles are `source`, `no-peephole`,
`no-common-subs`, `no-propagation` and `no-strength-reduction`.
Profiles request compiler prefix pragmas; source/header pragmas remain intact
and may override them, so an effective per-function setting is not guaranteed.
Use `-I` for source-relative header directories.

The runner leaves sources unchanged and creates isolated scratch directories
under `build/`. `--keep exact` retains objects with at least one exact function;
other functions and undefined-symbol diagnostics still require review.
`--keep all` retains every successfully compared object. `near` means the
existing checker's actual `DIFF` result, not a similarity score. Compile failures
and unknown addresses are separate outcomes. `--rom` and `--symbols` select
existing reference inputs; use a consistent snapshot, since the runner never
regenerates the symbol cache.

For parallel work, assign non-overlapping functions and isolated output/input
snapshots. Keep shared configuration, whole builds and publication under one
integrator. Batch compatible candidates into the final full-image check; neither
ranking nor compiler-trial output authorizes a match claim.

### Integrate a candidate

1. Pick a function from `asm/*.s` (functions must start on a 16-byte boundary,
   and so must the next function, because every object is 16-byte aligned).
2. In `config/splat.yaml`, insert a `c` subsegment at its start and an
   `asm` subsegment where the C unit ends, e.g.
   ```
   - [0x030AE0, c, main/func_00130AE0]
   - [0x030AF0, asm]
   ```
3. Write `src/main/func_00130AE0.c`, run `python configure.py` and `ninja`.
   The SHA-256 check is the final word; use objdiff to find differences.
   Only commit functions that build byte-identically.

Tooling and configuration tests run with
`python -m unittest discover -s tests -p "test_*.py"`.

Name functions in `config/symbol_addrs.txt` (`name = 0xADDRESS; // type:func`)
once their purpose is known.

## Rules

* Never commit the executable, disc data, split assembly, objects, decompiler
  output or BIOS files. `.gitignore` covers `orig/`, `asm/`, `build/`,
  `.tools/`.
* Claim a match only when the build's SHA-256 check passes.
