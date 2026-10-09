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

## Toolchain (identified)

| Part | Tool |
| --- | --- |
| Game code | Metrowerks CodeWarrior for PS2, `mwccps2` (C/C++), flags `-O4,p` |
| Linker (original) | `mwldps2` — writes `.comment = "MW MIPS C Compiler (2.4.1.01)"` |
| SDK / middleware | prebuilt Sony libraries (libgraph/libpad2 "2800" = SDK 2.8), Medius 1.50, lgaud, 989snd — built with EE-GCC |
| Here: split | [splat](https://github.com/ethteck/splat) (`config/splat.yaml`) |
| Here: assemble/link | GNU binutils for MIPS (`binutils-mips-ps2-decompals`) |
| Here: compile | `mwccps2.exe` build `mwcps2-3.0.3-020716` (game code, `src/main/`) and EE-GCC 2.95.3-136 (libraries, `src/lib/`), both from decomp.me's compiler archive |
| Here: diff/progress | [objdiff](https://github.com/encounter/objdiff) |

## Layout

```
./
  configure.py            generates build.ninja + objdiff.json, runs splat
  config/
    splat.yaml            splat config: which address ranges are C and which stay asm
    symbol_addrs.txt      known symbol names/addresses
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
4. **Configure and build:**
   ```
   python configure.py
   ninja
   ```
   `configure.py` checks your executable's hash, extracts the program image,
   runs splat (about a minute; reruns only when the yaml or symbols change)
   and writes `build.ninja` and `objdiff.json`. `ninja` assembles the asm,
   compiles `src/`, links, rebuilds the ELF container and verifies the result:

   ```
   OK: build/SCUS_972.64 matches retail SCUS_972.64 (SHA-256 9924da91...)
   ```

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

Name functions in `config/symbol_addrs.txt` (`name = 0xADDRESS; // type:func`)
once their purpose is known.

## Rules

* Never commit the executable, disc data, split assembly, objects, decompiler
  output or BIOS files. `.gitignore` covers `orig/`, `asm/`, `build/`,
  `.tools/`.
* Claim a match only when the build's SHA-256 check passes.
