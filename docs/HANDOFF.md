# Handoff: continuing the matching decompilation

This is the working state and the routine for whoever continues this project
(person or AI agent). Read [README.md](../README.md) for setup,
[PROGRESS.md](../PROGRESS.md) for the evidence and history, and
[MATCHING_TECHNIQUES.md](MATCHING_TECHNIQUES.md) before matching any function.

## Status

| | |
|---|---|
| Functions matched | 13,039 of 14,331 |
| Code matched | 65.45% |
| Data matched | 99.92% |
| Full build | reproduces the retail executable byte for byte |


The objdiff report undercounts `func_0038A800`: its full 2,328-byte body and the
linked executable match retail, but target-only relocations on scratchpad
constants (`D_70000040` and `D_70000008`) produce a 99.93% symbolic comparison.
The status above follows the generated report without manually changing totals.

What is left (from `progress/report.json`):

| Function size | Unmatched | Bytes |
|---|---|---|
| under 100 bytes | 200 | 5 KB |
| 100–1,200 bytes | 811 | 445 KB |
| 1,200–3,000 bytes | 202 | 362 KB |
| over 3,000 bytes | 79 | 453 KB |

Almost every remaining function under 1,200 bytes has been attempted at least once,
most of them by several workers. Code percentage is by bytes, so the large functions
are where the percentage moves.
The ones under 100 bytes are mostly hand-written assembly (`plzcw`, quadword copies
through temporaries) that C cannot express. The cheapest remaining gains are:

1. **Near misses.** Drafts that are a few instructions off (register swaps, delay-slot
   choice, stack-slot order). See "Near-miss techniques" below.
2. **Functions of 1,200–3,000 bytes**, which have barely been attempted.
3. **Families of similar functions.** `tools/clone_match.py` turns one matched function
   into matches for every function with the same instruction shape.

## Ground rules

- A match counts only when the full build prints
  `OK: build/SCUS_972.64 matches retail SCUS_972.64 (SHA-256 9924da91767c8145411f37fa6c14c9d77208264c17f1ce9ee157d51abdd31dc6)`.
- Never commit game content: no executable, `asm/`, `build/`, `orig/`, `.tools/`,
  disassembly or extracted data. Never commit the licensed compilers.
- Per-file acceptance with `tools/check_match.py`: every function line MATCH, no UNDEF
  line except `__dl__FPv`, any DATA line MATCH, one function per file, and the file
  covers the full size of its retail unit.
- Inline asm only for instructions C cannot express. A scheduling barrier, weak stub or
  fake `x++; x--;` pair needs a one-line comment saying why it is there.
- Never use CodeWarrior 3.03J. Never force-push or rewrite published history.
- Keep line endings LF.

## Tools you need

The build needs three licensed CodeWarrior PS2 installs, named by environment variables:
`CW38_DIR` (3.0 build 38), `CW50_DIR` (3.0 build 50) and `CW304_DIR` (3.04 build 22,
its `PS2_Tools/Command_Line_Tools` directory). EE-GCC 2.9-ee-991111, 2.95.3 and 2.96
are also used. Their Linux binaries run natively on Linux and through WSL on Windows.
`tools/setup_tools.py` downloads the freely available tools.

On Linux the CodeWarrior compilers run through wibo. A 4-core GitHub codespace does a
full round build (configure, data generation, configure, ninja, report) in about
6–7 minutes.

**EE-GCC 2.96 is nondeterministic across CPUs.** Its 32-bit `cc1` reads uninitialized
memory, so its output depended on which CPU-specific glibc string routines ran and on
the environment size. `tools/compile_aligned.py`, `check_match.py`, `merge_units.py`
and `wsl_gcc.py` set
`GLIBC_TUNABLES=glibc.cpu.hwcaps=-SSSE3,-SSE4_1,-SSE4_2,-AVX,-AVX2,-ERMS,-FSRM,-BMI1,-BMI2,-POPCNT,-LZCNT,-MOVBE`,
which makes it match on both Intel and AMD hosts. Any new script that runs `cc1` must do
the same.

## Matching one function

1. **Pick a candidate.** `python tools/rank_candidates.py --report progress/report.json --json`
   lists unmatched functions with their owner unit and size. Read the function in
   `asm/` (search for its `glabel`; the file name in the ranking can be stale).
2. **Decide the compiler** from the code's shape (see the table in
   MATCHING_TECHNIQUES.md). Game code is usually `mw38`; library code is EE-GCC.
3. **Write the C** in a scratch file named `<kind>_<ADDR>.c`. Copy the style of nearby
   matched units in `src/` for declarations and types. `m2c` gives a first draft.
4. **Check it.** `python tools/check_match.py FILE.c -c mw38,mw50,mw304,mw` (or
   `-c gcc296g0,gcc296,gcc29,gcc` for library code). The output shows each compiler's
   per-function result and an instruction diff. `tools/try_match.py` runs pragma
   experiments (`#pragma opt_propagation off`, `peephole off`, ...) without editing the
   file.
5. **Stage** each accepted file as `<kind>_<ADDR>.c` in a staging directory (by
   convention `build/pending/<round>/`).

## Integrating a round

```
python tools/data_gen.py release --all           # give data back to the units that own it
python tools/integrate_pending.py . build/pending/<round>
python tools/apply_names.py                      # apply config/symbol_addrs.txt names to C
python configure.py --compiler-dir "cwps2-3.0b38=$CW38_DIR" --compiler-dir "cwps2-3.0b50=$CW50_DIR" --compiler-dir "cwps2-3.04=$CW304_DIR"
python tools/data_gen.py
python configure.py ...same flags...
ninja                                           # must print the OK line
ninja report && python tools/publish_report.py
git add src config include progress && git commit && git push
```

`integrate_pending.py` prints `+` for each added unit and the reason for each skipped one.
If the build fails, find the first differing byte (`cmp -l build/SCUS_972.64 orig/SCUS_972.64`),
map it to a unit, move that file out of the round and rebuild. Commit messages follow the
existing ones: what was matched, the OK line, and the new totals.

`tools/merge_units.py --all-complete` merges per-function files of fully matched modules
into translation units. Run it occasionally; see [merge_units.md](merge_units.md).

## Pitfalls already hit

- `merge_units: begin/end func_<ADDR>` markers must keep their address labels:
  `merge_units.py` and `clone_match.py` parse them. `apply_names.py` leaves them alone.
- GCC 2.96 accepts string literals that span lines. A trailing space before such a line
  break is part of the string, so never strip trailing whitespace across the tree.
- Ninja does not track header dependencies here. After editing a header, touch every
  `.c` file that includes it, including through another header. A fresh source rebuild
  exposed a duplicate `HumanColPreset` definition hidden by the incremental cache;
  `humanCollision_types.h` now owns that type and the preset setter uses its fields.
  When taking over an existing build cache, rebuild all C sources before trusting it.
- Naming a data symbol in `config/symbol_addrs.txt` makes splat redo its whole split.
- Python and some editors on Windows write CRLF; convert back to LF before committing.
- When several workers match in parallel, give each one a disjoint candidate list,
  generated from the current `progress/report.json` and excluding everything already
  staged. Overlapping lists wasted a full round of work twice.
- The `asm=` path that the candidate ranking prints can be stale after a re-split;
  search `asm/` for the `glabel` instead.
- Readability edits (names, struct types, comments) are free, but changing a type's
  width or signedness, expression shape or declaration order can change code
  generation. Rebuild after each batch.

## Near-miss techniques (newest)

- **mw38 inline helpers:** exposing a helper's locals in the caller and changing their
  declaration order can resolve register allocation without changing control flow.
  This finished `AnimCtl_UpdateTransitions` and `PlayerSlots_Get`.
- **mw50 indexed pointers:** integer byte-address addition can choose different
  temporary registers from pointer indexing. This finished both texture-cache
  update functions at `00382190` and `00382540`.
- **GCC register copies:** bind a local copy rather than the incoming parameter.
  Assigning it after the null test preserved the original branch register in
  `00311120`; assigning the shared second argument before the final call branch
  recovered both argument delay slots in `0027C410`.

- **gcc296:** a weak stub of the callee in the same file
  (`int __attribute__((weak, section(".dtors_drop"))) f(...) { return 0; }`) can change
  `bnel` and delay-slot choices. `int r = K; return r;` keeps `v0` live across
  branches. A struct copy produces `ldl`/`ldr`/`sdl`/`sdr`. A ternary produces `movz`.
  The callee's declared return type and pointer-vs-int fields change register
  allocation.
- **mw38:** declaration order sets which saved register a local gets, but not its
  stack slot. Reading a field through a cast inside a loop makes the compiler hoist and
  spill the pointer; declaring the field in the struct avoids it. Declaring callee
  parameters `int` rather than `long long` avoids sign extension. A `static inline`
  helper that returns `p + 1` stops store offsets being folded.
- **mw38 stack slots:** moving a local's declaration into a nested block `{ ... }`
  changes the order of spill slots when declaration order alone does not.
- **mw38 static initializers:** the store order in `__sinit_*` follows the member
  declaration order of the struct or class, not the order of the assignments.
- **mw38 switches:** sparse `case` labels are tested in reverse source order; reorder
  the cases to match the compare chain.
- **mw38 calls:** a call through a C function pointer goes through `v0`, while a C++
  virtual call goes through `t9`. Pick whichever matches the retail register.
- **Decompiler argument omissions:** check every call against the original argument
  setup, including unused receivers, fifth/sixth integer arguments and floating-point
  arguments. A lower difference score can hide an incomplete prototype.
- **mw38 loop guards:** after initializing an index to zero, `index < count` can
  retain a separate comparison that `count > 0` replaces with a direct branch.
  A pointer const-reference helper used only in the loop update can preserve the
  original count and data-pointer setup.
- **mw38 inlined wrappers:** a getter taking a global value as an argument can
  preserve an eager load; a queue wrapper with the iterator initialized after its
  entry fields can preserve stack-store order. Use the surrounding source semantics
  to choose the wrapper rather than adding instruction assembly.
- **mw38 dead aligned slot:** a `volatile int x[4];` local reproduces an aligned
  16-byte stack slot that is written but never read.
- **Return registers:** declaring a `void` callee as returning `int` can fix
  `v0`/`v1` choices in the caller.
- **gcc296:** wrapping one of two adjacent `memcpy`s in `do { } while (0)` keeps the
  compiler from merging or reordering them.
- **SCE assembler padding:** some SDK functions were built with the SCE assembler,
  which inserts `nop`s after `li.s`/`div.s` and in short loops. A small inline `asm`
  sequence reproduces it (comment why).
- **gp swaps and libgcc aliases:** a short asm barrier fixes a swapped `gp` load; a
  libgcc routine that the game re-exports can be expressed as an alias,
  `__asm__("__floatdisf = func_XXXXXXXX");`.
- **Permutation over declaration order:** for mw38 near misses that differ only in
  saved registers or slots, a small script that tries every order of the local
  declarations (and a few block nestings) finds the match quickly. Give each trial its
  own scratch directory; a shared directory corrupted scores in parallel runs.
- **mw pragmas:** `opt_rotateloops off` gives the "branch to the loop test" layout,
  `opt_unroll_loops off` stops fixed-count copy loops being unrolled, `peephole off`
  stops constant offsets being folded into loads/stores, `opt_propagation off` keeps
  separate copies of inlined-function arguments.
- **Unsolved pattern:** several large mw38 functions keep code from inlined helpers that
  the compiler would normally optimize away (dead `if (out)` branches, unfolded offsets,
  recomputed index arithmetic). No pragma combination reproduces it yet.
- **decomp-permuter** found several GCC matches in long runs (20 minutes or more). It
  can't parse the C++ drafts.

## Known blocked work

- Some functions reference `.lit4` float literals that the current linking cannot place.
- `0x286570`: both function bodies match, but the unit needs a splat split at `0x286590`.
- Hand-written assembly functions stay as assembly.

## Readability

Fully matched modules were cleaned up module by module (names, shared struct headers
in `include/`, enums for magic numbers). [HEADERS.md](HEADERS.md) lists the headers.
Function names live in `config/symbol_addrs.txt`; add a name there and run
`tools/apply_names.py` so every caller is renamed. Many matched modules still use
`func_XXXXXXXX`, `D_XXXXXXXX` and raw offsets.

## Open decisions for the owner

- Whether to commit hand-written assembly functions as `.s` units.
- Whether to give data the same readability treatment as code.
