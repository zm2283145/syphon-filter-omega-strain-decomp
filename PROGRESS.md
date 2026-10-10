# Matching decomp — progress log

## Decisions needed (owner)

1. **Exact compiler build.** The game code is Metrowerks CodeWarrior PS2.
   The decomp.me archive builds that run without a FlexLM license
   (`mwcps2-3.0-011126`, `3.0.1-020123`, `3.0.3-020716`) reproduce small and
   straight-line functions, but differ systematically from the retail code in
   instruction scheduling around calls and branch targets (an extra `nop`
   before branch targets and after calls, different delay-slot filling).
   The owner-licensed CodeWarrior PS2 3.0 build 38 installation reports
   `Version 3.0 build 38`, built March 7, 2003, and is now the primary game
   compiler for units selected in `config/compiler_overrides.json`. CodeWarrior
   3.04 build 22 remains selected for one static initializer, with default
   3.0.3 and EE-GCC 2.95.3/2.96 used for their own matched units. A clean full
   build with these per-unit choices reproduces the retail executable byte for
   byte. This establishes code-generation compatibility, not proof of the
   exact compiler used for every retail unit.
2. **CI access to the executable** — not needed for decomp.dev: reports are
   generated locally and uploaded by CI (see [DECOMP_DEV.md](DECOMP_DEV.md)).

## Current status (2026-10-10)

### Library batch and build fixes

56 more EE-GCC library functions (C library, SDK, MPEG, network helpers)
and one Metrowerks MPEG parser stub are matched. Two build changes go with
them:

- A Metrowerks unit that starts on an 8-byte (not 16-byte) boundary gets its
  `.text` alignment from its retail address, as the GCC units already did.
- Without a licensed override compiler, `configure.py` now prints a warning
  and builds its assigned units from their retail assembly, so the
  license-free build still matches (those functions then count as unmatched
  in a local report).

`tools/check_match.py FILE.c -c mw,mw38,mw304,gcc,gcc296` compiles a candidate
with each selected compiler and reports per function which one reproduces the
retail bytes.

### Toolchain fingerprints in the unmatched code

A scan of the 7,873 unmatched functions outside `0x00400000`–`0x00476B00`:
573 contain a single-precision compare followed directly by `bc1t`/`bc1f`
(3.04 emits this; 3.0.3 always inserts a `nop`), against 7 with the 3.0.3
form; and 1,452 of 2,302 functions with loops have loop heads padded to an
8-byte boundary by a `nop`, which 3.04 also produces. Most of the remaining
game code therefore looks like 3.04 output, while existing matches show some
units need 3.0.3, so the compiler stays a per-unit choice.

### Earlier CodeWarrior 3.04 batch

This batch adds 24 functions (1,612 code bytes) in the reserved
`0x00400000`–`0x00476B00` range: object-registry lookup and collision checking,
local-player publication, GUI and menu helpers, lobby callbacks, destructors,
and initialization routines. These original matches were made with 3.04 and
have since been retested with CodeWarrior 3.0 build 38 overrides.
The independently recovered `func_0045A7A0` landed upstream during the rebase;
its upstream implementation is preserved and is not counted in this batch.
All 24 are identical in objdiff, and the mixed-compiler whole build prints
`OK: build/SCUS_972.64 matches retail SCUS_972.64` with SHA-256
`9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6`.

| Item | State |
| --- | --- |
| Round-trip build | **Byte-identical**, SHA-256 `9924da91…31dc6` (Windows, native tools) |
| Build with C | **Byte-identical** with 5,948 matched functions (Metrowerks 3.0.3 / 3.0 build 38 / 3.04 + EE-GCC 2.95.3 / 2.96) |
| Functions (objdiff) | 5,948 / 14,845 matched (40.07 %) |
| Code bytes (objdiff) | 285,656 / 3,663,320 (7.80 %) |
| Linked code | 7.80 % — every matched C unit is fully linked |
| Named functions | ~2,700 in `config/symbol_addrs.txt` |
| Data | 339,552 bytes counted separately; not linked from C |
| decomp.dev | listed: https://decomp.dev/zm2283145/syphon-filter-omega-strain-decomp |

### Additional reserved-range matches using CodeWarrior 3.0 build 38

Fifty-four readable functions (9,268 code bytes) were added in the reserved range:
`0x00412110`, `0x0041C0D0`, `0x0041C0F0`, `0x0041DA60`, `0x00421670`,
`0x00425E00`, `0x0042AFC0`, `0x00431850`, `0x00436BA0`, `0x004375D0`,
`0x00444E10`, `0x0044A070`, `0x00452C70`, `0x0045A968`, `0x0045EC60`,
`0x0041ACE0`, `0x00426350`, `0x004320F0`, `0x00437830`, `0x004459D0`,
`0x00448270`, `0x0043A810`, `0x00457040`, `0x00457110`, `0x0040BBD0`,
`0x00421480`, `0x004214C0`, `0x00421500`, `0x00434740`, `0x00434920`,
`0x0043A8B0`, `0x0041D400`, `0x0041D5C0`, `0x0041D780`, `0x0041D8C0`,
`0x0041DAA0`, `0x0041DB80`, `0x0041DC70`, `0x0041DDC0`, `0x0041DF00`,
`0x0041E040`, `0x0041E130`, `0x0041E230`, `0x0041E2B0`, `0x0041E330`,
`0x0041E3B0`, `0x0041E470`, `0x0041EBF0`, `0x0041C560`, `0x0041EE50`,
`0x0041EF10`, `0x0041EFA0`, `0x0041F090`, and `0x0041F210`.
All fifty-four are identical in objdiff. Fifty-two use CodeWarrior 3.0 build 38 overrides;
`0x00412110` and `0x0045A968` also match with the default 3.0.3 compiler. The
complete clean mixed build printed the retail SHA-256 OK line without any
compiler falling back to assembly. The latest addition comprises two layered
widget stream loaders and four GUI state/registration routines: six functions
totaling 1,356 code bytes plus 52 padding bytes. The loaders preserve
NUL-terminated string scanning, temporary string lifetime, four-byte stream
alignment, numeric fields and flag updates. State notifications preserve
flag-update order and live end-iterator queries after child callbacks. The
companion `0x0041ED20` routine remains assembly because its draft still differs.

The existing helper at `0x001C43A0` forwards `String_Compare`'s integer
result, rather than assigning a string. Its return declaration and comment
were corrected for the new name-search consumer while retaining the legacy
symbol and identical machine code; this is not counted as a new match.
The clean build also confirms the extended shared GUI layouts and virtual-slot
declarations leave the previous traversal, lookup, dispatch and lifecycle blocks
unchanged. Compiler exception metadata is discarded by the existing linker
script. The two new stream loaders match with build 38 but differ with both
3.04 and default 3.0.3 for the same source and flags; the four state/registration
routines also match with 3.04. This is further evidence of build 38's practical
code-generation advantage, not proof of the original compiler's provenance.

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
