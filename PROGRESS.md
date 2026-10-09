# Matching decomp — progress log

## Decisions needed (owner)

1. **Exact compiler build.** The game code is Metrowerks CodeWarrior PS2.
   The decomp.me archive builds that run without a FlexLM license
   (`mwcps2-3.0-011126`, `3.0.1-020123`, `3.0.3-020716`) reproduce small and
   straight-line functions, but differ systematically from the retail code in
   instruction scheduling around calls and branch targets (an extra `nop`
   before branch targets and after calls, different delay-slot filling). The
   2003 builds (`3.0b38`…`3.0.1b87`), which very likely match, need a valid
   license. The owner's CodeWarrior 3.0.1 install is identical to
   `3.0.1-020123`; the 3.0.4 (build 22) install came with an evaluation
   license that expired in November 2002. Only a genuine permanent license
   would let us test those builds; no license workaround is used.
2. **CI access to the executable** — not needed for decomp.dev: reports are
   generated locally and uploaded by CI (see [DECOMP_DEV.md](DECOMP_DEV.md)).

## Current status (2026-10-09)

| Item | State |
| --- | --- |
| Round-trip build | **Byte-identical**, SHA-256 `9924da91…31dc6` (Windows, native tools) |
| Build with C | **Byte-identical** with 3,405 functions compiled from C |
| Functions (objdiff) | 3,405 / 14,327 matched (23.8 %) |
| Code bytes (objdiff) | 87,332 / ~3.66 MB (2.39 %) |
| Named functions | 152 (from the port project's research notes) |
| Data | not tracked yet (data stays in assembly) |
| decomp.dev | listed: https://decomp.dev/zm2283145/syphon-filter-omega-strain-decomp |

"Matched" means the whole executable still builds with the SHA-256 of the
retail file and objdiff reports the function as identical. Function totals
are splat/spimdisasm's function detection and shift slightly as boundaries
are refined.

## How the matched C was produced

Most of `src/main/` is machine-generated and then verified, not hand-written:

* **Templates (≈1,750 functions):** two-instruction accessors and other leaf
  patterns, plus byte-for-byte duplicates of any matched leaf function (C++
  template instances such as container swap, iterator begin/end/compare,
  copy constructors) reuse the same source.
* **Symbolic translator (≈1,300):** branch-free functions, with or without
  calls and global data, become C expressions; callee arity and return kind
  are inferred from the callee's code.
* **Register-level translator (≈350):** functions with branches, stack locals,
  virtual calls and tail jumps become C with one variable per register and
  `goto`s; Metrowerks' optimizer reproduces the original code for many small
  functions.
* **Hand-written (≈40):** container, vector and script helpers.

Every candidate is compiled with `mwccps2 -O4,p`, compared with the retail
bytes (relocations masked), and finally checked by the full byte-identical
build. Generated code is deliberately low-level (`*(int*)((char*)p + 8)`);
replacing it with real structs, types and names is ongoing work.

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

1. Replace generated pointer arithmetic with real structs and names, starting
   with the classes the research notes describe (actors, curves, transforms,
   objectives).
2. Find translation-unit boundaries (`.cc` strings, function order, vtables)
   and move functions into real source files.
3. Split game code from SDK/middleware and add objdiff progress categories;
   libraries need EE-GCC (decomp.me has ee-gcc 2.9x builds).
4. Split data/rodata by unit so data progress can be tracked.
5. Resolve the compiler-build question (decision 1); with a 2003 build most
   larger functions should become matchable.
