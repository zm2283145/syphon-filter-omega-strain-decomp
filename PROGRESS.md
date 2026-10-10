# Matching decomp — progress log

## Decisions needed (owner)

1. **Exact compiler build.** The game code is Metrowerks CodeWarrior PS2.
   The decomp.me archive builds that run without a FlexLM license
   (`mwcps2-3.0-011126`, `3.0.1-020123`, `3.0.3-020716`) reproduce small and
   straight-line functions, but differ systematically from the retail code in
   instruction scheduling around calls and branch targets (an extra `nop`
   before branch targets and after calls, different delay-slot filling). The
   2003 builds (`3.0b38`…`3.0.1b87`), which very likely match, need a valid
   license. A previously checked CodeWarrior 3.0.1 installation was identical
   to `3.0.1-020123`. The 3.04 installation reports `Version 3.0 build 22`,
   built September 26, 2002, and now compiles as installed, with no licensing
   changes or workaround. This supersedes the earlier assumption that an
   expired evaluation license prevented testing it. It reproduces instruction
   sequences that the default compiler does not, but a global switch breaks
   the full retail hash. `config/compiler_overrides.json` therefore selects it
   only for individual units; see README.md for licensed-installation setup.
   These results do not establish the exact compiler used for every retail unit.
2. **CI access to the executable** — not needed for decomp.dev: reports are
   generated locally and uploaded by CI (see [DECOMP_DEV.md](DECOMP_DEV.md)).

## Current status (2026-10-10)

### CodeWarrior 3.04 batch

This batch adds 24 functions (1,612 code bytes) in the reserved
`0x00400000`–`0x00476B00` range: object-registry lookup and collision checking,
local-player publication, GUI and menu helpers, lobby callbacks, destructors,
and initialization routines. Per-unit 3.04 build 22 selection enables all 24.
The independently recovered `func_0045A7A0` landed upstream during the rebase;
its upstream implementation is preserved and is not counted in this batch.
All 24 are identical in objdiff, and the mixed-compiler whole build prints
`OK: build/SCUS_972.64 matches retail SCUS_972.64` with SHA-256
`9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6`.
The 24 selected functions do not reproduce with the default 3.0.3 compiler.
The table below is the earlier progress snapshot.

| Item | State |
| --- | --- |
| Round-trip build | **Byte-identical**, SHA-256 `9924da91…31dc6` (Windows, native tools) |
| Build with C | **Byte-identical** with 5,122 functions compiled from C (Metrowerks + EE-GCC) |
| Functions (objdiff) | 5,122 / 14,328 matched (35.7 %) |
| Code bytes (objdiff) | 191,704 / 3,661,248 (5.24 %) |
| Linked code | 5.24 % — every C unit is fully matched and linked, so units are marked complete |
| Named functions | ~2,700 in `config/symbol_addrs.txt` |
| Data | not tracked yet (data stays in assembly) |
| decomp.dev | listed: https://decomp.dev/zm2283145/syphon-filter-omega-strain-decomp |

"Matched" means the whole executable still builds with the SHA-256 of the
retail file and objdiff reports the function as identical. Function totals
are splat/spimdisasm's function detection and shift slightly as boundaries
are refined.

## How the matched C was produced

* **Automatic translators (≈3,400):** templates for leaf patterns and clones,
  a symbolic translator for branch-free code and a register-level translator
  for small branchy functions, each verified against the retail bytes.
* **Readability pass (all of `src/main/`):** the generated code was rewritten
  with typed structs (`include/*_types.h`), named fields and locals and
  structured control flow, file by file, re-verifying every function.
* **Hand matching (≈1,100):** functions the translators could not reproduce,
  written as readable C. Techniques that the retail code turned out to need:
  per-file optimizer pragmas (`optimization_level 1` for areas built at -O1,
  `peephole off`, `opt_propagation off`, `opt_common_subs off`), C++ mode
  (`#pragma cplusplus on`) with class declarations for virtual calls through
  `$t9`, empty allocator/tag structs passed by value, the SSO string layout,
  and staging of script arguments through stack slots.
* **Library code with EE-GCC (src/lib/):** Sony SDK and middleware functions
  matched with EE-GCC 2.95.3-136 (`-O2 -G0`).

Every candidate is compiled, compared with the retail bytes (call targets and
`%hi/%lo` data addresses included) and finally checked by the full
byte-identical build.

## What blocks the rest (14,328 − 5,122)

| Group | Functions | Reason |
| --- | ---: | --- |
| Branch targets padded to 8 bytes | ~4,500 | the retail Metrowerks build inserts a `nop` so branch targets are 8-byte aligned; the license-free 2002 builds never do (decision 1) |
| Other branchy/scheduling differences | ~1,700 | delay-slot filling, `nop` after FP compares, `beql`, `cvt.w.s`, destructor epilogues — also compiler-build differences |
| GCC library code, 8-byte aligned | ~1,250 | EE-GCC 2.95.3 matches part; the rest needs per-function work |
| `sd`-saving library code | ~860 | built with EE-GCC 2.96 (or 2.9-991111), which only exists as a Linux binary; usable on Windows only through WSL |
| VU0 macro code | ~600 | needs inline assembly |

## Toolchain identification — evidence

* **ELF container**: 5 `PT_LOAD` entries (0x00100000 empty, 0x00100000 image
  filesz 0x3E1D80 / memsz 0x498980, 0x00598980 empty, 0x01E68000 memsz
  0x180000, 0x70000000 scratchpad), unnamed section headers, empty
  `.symtab`/`.strtab`, `.reginfo` with gp = 0x004E9B70: characteristic of the
  Metrowerks linker `mwldps2`.
* **`.comment`** = `"MW MIPS C Compiler (2.4.1.01)\0PlayStation2\0"`. Every
  archived `mwldps2.exe` embeds this string, so it identifies the linker, not
  the compiler build.
* **Startup**: `_start` at 0x00100008 clears all GPRs with `padduw`, zeroes
  BSS (0x004E1D80–0x00598980), sets gp and calls `SetupThread` — Metrowerks
  `__start`.
* **Code idioms**: game functions save `ra` with `sd` and callee-saved
  registers with `sq`, move with `daddu rd, rs, $zero`, keep `ra` below the
  locals, and are 16-byte aligned. Library code (Sony SDK 2.8, Medius 1.50,
  lgaud 1.09, 989snd, …) is EE-GCC style (8-byte alignment, `move a0,sp`,
  locals below `ra`) and is linked between game objects.
* **Test compiles**: `mwccps2 -O4,p` (`,p` gives the post-call `nop` inside
  loops) matches thousands of functions with the license-free builds; the
  remaining scheduling differences are described in decision 1.
* **Code in the data area**: rt_crypt assembly routines (0x004AE1C0,
  0x004B13D0) and the static-initialiser functions (0x004C3700–0x004D8D0C,
  called through the table at 0x004D8D10 by `StaticInit_RunAll`) are split
  as code.

## Setup

* `configure.py` + ninja; splat 0.50.0 / spimdisasm 1.42.4; binutils
  mips-ps2-decompals v0.10; objdiff-cli v3.8.2. See README.md.
* `tools/extract_rom.py` takes the program image from the user's ELF,
  `tools/elf_rebuild.py` rebuilds the retail container,
  `tools/check_sha256.py` verifies it, `tools/publish_report.py` copies the
  objdiff report for CI.
* Objects are linked in address order with a short wildcard linker script and
  a response file (fast with thousands of objects); every object is 16-byte
  aligned, so a C unit must start and end on 16-byte function boundaries.

## Next steps

1. Keep hand-matching the remaining compiler-compatible functions (agents in
   parallel; the address range 0x00400000–0x00476B00 is reserved for a second
   contributor working through pull requests).
2. EE-GCC 2.96 for the `sd`-saving libraries (optional WSL path in
   `configure.py`), which would unlock ~860 functions.
3. Recover more structures and merge single-function files into real
   translation units (`config/tu_ranges.txt`).
4. Add objdiff progress categories (game vs. SDK/middleware).
5. Split data/rodata by unit so data progress can be tracked.
6. Resolve the compiler-build question (decision 1): the 8-byte branch-target
   padding is the single largest blocker.
