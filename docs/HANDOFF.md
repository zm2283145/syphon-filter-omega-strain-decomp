# Handoff: continuing the matching decompilation

This is the working state and the routine for whoever continues this project
(person or AI agent). Read [README.md](../README.md) for setup,
[PROGRESS.md](../PROGRESS.md) for the evidence and history, and
[MATCHING_TECHNIQUES.md](MATCHING_TECHNIQUES.md) before matching any function.

## Status

| | |
|---|---|
| Functions matched | 13,745 of 14,344 |
| Code matched | 83.72% |
| Data matched | 99.92% |
| Full build | reproduces the retail executable byte for byte |

The total rose from 14,331 to 14,344 when R138 split the `0x416830` thunk unit. That split
briefly cost 224 bytes of data credit: the vtables in `func_00416A00.c` and
`guiManager_417AE0.c` still listed the thunks as raw addresses (`(void*)0x416850`), while the
target now has relocations to `func_00416850` etc. Naming them restored 99.92% (`aa3e99f`).
**After adding `// type:func` symbols, grep `src/` for `(void*)0x<addr>` table entries and name them.**

The ten r139 matches staged on the Windows checkout were verified and integrated in R139 (`6fabca5`).


The objdiff report undercounts `func_0038A800`: its full 2,328-byte body and the
linked executable match retail, but target-only relocations on scratchpad
constants (`D_70000040` and `D_70000008`) produce a 99.93% symbolic comparison.
The status above follows the generated report without manually changing totals.

What is left (from `progress/report.json`):

| Function size | Unmatched | Bytes |
|---|---|---|
| under 100 bytes | 180 | 3 KB |
| 100–1,200 bytes | 342 | 212 KB |
| 1,200–3,000 bytes | 107 | 195 KB |
| over 3,000 bytes | 48 | 258 KB |

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
- Register pinning (`register T x asm("$n")`) is allowed only as a last resort in EE-GCC
  library code (`src/lib/`), after declaration order, temporaries and types have failed,
  with a one-line comment saying why. Never in Metrowerks game code. It emits no
  instructions but forces register choice, so the original source almost certainly did
  not contain it.
- Keep line endings LF.

## Tools you need

The build needs three licensed CodeWarrior PS2 installs, named by environment variables:
`CW38_DIR` (3.0 build 38), `CW50_DIR` (3.0 build 50) and `CW304_DIR` (3.04 build 22,
its `PS2_Tools/Command_Line_Tools` directory). EE-GCC 2.9-ee-991111, 2.95.3 and 2.96
are also used. Their Linux binaries run natively on Linux and through WSL on Windows.
`tools/setup_tools.py` downloads the freely available tools.

On Linux the CodeWarrior compilers run through wibo. A 4-core GitHub codespace does a
full round build (configure, data generation, configure, ninja, report) in about
6–7 minutes. A local WSL (Ubuntu) tree with `ninja -j8` works as well and takes
about 10–13 minutes. It needs `tools/setup_tools.py` run inside WSL, which creates the
`ee-gcc2.9-991111-as296` hybrid compiler. Without the hybrid, libcdvd/libmpeg units
drop out of the report while the executable still matches.

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

- `tools/data_obj.py` used to pad an odd-sized data block with `objcopy --update-section`,
  which silently dropped the block's relocations (jump tables then scored < 100% in the
  report while the executable still matched). It now pads inside the `ld -r` link script
  (`tests/test_data_obj_pad.py`). If a unit's data section scores below 100% with the build
  matching, check its relocations first.

- Never give a function a C library or compiler-runtime name (`abort`, `sscanf`, `strncat`,
  `toupper`, `__moddi3`, `_calloc_r`, `memcpy`, `sqrtf`, ...) in `config/symbol_addrs.txt`.
  GCC treats such names as builtins: naming 0x00121B60 `abort` made the caller a no-return
  tail jump and shrank the executable by 16 bytes. Use a prefixed name (`Math_Sqrtf`) or
  leave it `func_`.
- After `tools/apply_names.py` renames functions in `include/`, rebuild every C file
  (`find src -name '*.c' -exec touch {} +`); otherwise stale objects keep the old
  `func_` references and the link fails.

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

- **Quad copy split at the call site (M16):** writing a 16-byte copy as a volatile asm `lq` plus
  a C `sq` (instead of a class `operator=` or a full asm block) changes MW's register pairing; it
  closed cNIEventOBJ_v01 and PlayerCamera_ComputeSlopePitch. `build/agents/M16/tools/splitlq.py`
  tries it at every quad-copy site of a draft.
- **Local message structs:** a destructor can match the inlined teardown yet still emit a weak
  out-of-line `__dt__…` that check_match counts as an extra function; call an explicit teardown
  method (`m.Done()`) instead. `#pragma exceptions off` does not stop it.
- **Below 0x300000, fresh targets and sibling twins are exhausted (2026-10-26).** Remaining small
  near misses (TargetVis_Test 1 line, Actor_GetEyeNode, ZoneMgr_DeactivateObject,
  LosRegion_GetCollection, func_0022D3C0, GuiAgentCreate_UpdateCount 4 each) are listed with
  drafts in `build/agents/M16/FINAL_REPORT.md`; the large functions are now the main lever.

- **MW `asm volatile {}` and float constants (2026-10-26):** after a volatile asm block (MW or
  gcc `__asm__ volatile`), float constants later in the same basic block are stored from FPRs
  (`mtc1` + `swc1`) instead of as integer stores (`sw zero`). Non-volatile MW asm does not do this.
  MW asm blocks are scheduled with the surrounding code, so an `sq` can land in a call delay slot.
- **A non-empty GCC-style `__asm__` switches MW to a less-optimised mode for the whole function:**
  bool temporaries stay as `move/daddiu` pairs, pointer ternaries stay as branches (no `movz`),
  and `x == a || x == b` stays a compare chain. If retail shows these, write the quad copies with
  gcc asm. An empty `__asm__("")`, MW `asm {}` blocks and pragmas do not trigger it.
- **mw38 frame layout:** named function locals first (first declared at the highest address),
  then function temporaries, then inline locals by nesting depth. Moving an object between those
  classes is the main lever. By-value inline parameters are built straight into the parameter's
  slot; a conversion constructor `V(M m)` builds its result in place.
- **Small levers:** an empty weak destructor on a stack object (in `.dtors_drop`) reproduces a
  branch to the end of the block; a `volatile` cast on one read reproduces one retail reload;
  a float constant held in a local keeps `mul.s` operand order; `if (f && ...)` gives
  `c.eq.s f,zero` while `f != 0.0f` swaps the operands; MW's small-set bit test is
  `(unsigned)(c - 3) < 8 && ((1 << (c - 3)) & mask)`.
- **Whole-function `asm void` is not accepted:** hand-written functions (e.g. 0x3020A8, which
  keeps a total in `$at`, and Sha1_ByteSwapWords 0x4B3320) stay as assembly; drafts are held in
  `build/agents/held/`. Sha1_StoreDigest 0x4B3350 is instruction-identical, but check_match sizes it
  up to the next function start past the island's trailing data (0x74 vs 0x160).

- **Splitting a packed asm unit (2026-10-21):** when one splat unit holds several functions
  (thunk tables, for example `0x416830`), add each unnamed function to
  `config/symbol_addrs.txt` as `func_XXXXXXXX = 0xXXXXXXXX; // type:func` and write all of them
  in one file in retail order. Any `symbol_addrs` change invalidates `check_match`'s symbol
  cache, so the next run rescans every asm file (10+ minutes on Windows).
- **mw38 argument scheduling:** where a float parameter sits among the int parameters of a
  callee's prototype changes which instruction fills the call's delay slot (0x19D950).
- **mw50 stack slots** appear to be ordered by size rather than declaration order; a named
  handle local or moving an `int` into a nested inline can fix slot offsets (0x22C720).
- **mw38 stack slots:** function locals, then temps, then inline locals, then nested-inline
  locals. Plain `asm { sq zero, 0(d) }` blocks keep retail's unfolded `addiu` + `sq`. An
  `asm { .set reorder }` changes how later asm blocks in the same function compile.
- **Open near misses** (drafts under `build/agents/<lane>/work/best_*.c`): 0x0026C570 (3 diffs,
  f2 zero-load placement around an asm block), 0x00143DF0 (3, delay-slot source),
  0x00234110 (4), 0x003C5EA0 (3), 0x00476998 (3, `lui; jr; lw %lo` form), 0x0015C390
  (23, s0/s1 swap), 0x00190060 (28, lq/sq temp registers), 0x00179620 (41), 0x003ADA60 (42),
  0x001B0A50 (61), 0x001D3AD0 (85).

- **mw38 value-returning vector operators:** write `operator-` etc. as `V r; SubV(&r, this, &o); return r;`
  with the VU0 asm in its own inline one level deeper; this removes an extra return-slot
  address and improved every draft it was tried on.
- **mw38 misc (newest):** zero float struct fields through an int view to stop MW CSE-ing the
  field address; an `(unsigned)` index cast blocks strength reduction; route a call result through
  a temp to load a field after the call; an unconditional multiply before a ternary gives retail's
  speculative `mul` in the delay slot; `(T*)(int)&x` stops constant-address folding; a one-iteration
  copy loop keeps a separate source register; `i = 0; goto test;` enters a loop at its test; when
  every delay slot in a function is unfilled, look for an asm copy macro.
- **Fresh targets:** with most callees named, functions no earlier lane has drafted (grep the
  address under `build/agents/`) have been the most productive targets.

- **gcc 2.96 calls are cross-jumped too:** jump2 merges a call into a shared `jalr` when at
  least two trailing instructions match, so write each arm as its own call followed by its
  own copy of the cleanup tail to get retail's single shared call (unit 0x30C780).
- **gcc 2.96 delay slots and calls:** the delay-slot pass stops its liveness scan at any call
  that might throw; a call counts as non-throwing only if the callee was defined earlier in
  the same source file. A weak `.dtors_drop` stub of that callee (commented) reproduces it
  and fixes wrongly annulled `beqzl`/`bnezl` slots (RtUdp_SendPump, RtUdp_UpdateTransport,
  RtUdp_ParsePacket).
- **gcc 2.96 `return 0`:** directly after `if (r) return r;` it is deleted (v0 known zero),
  which shifts later registers; route it through one shared final `return 0`. Nested ifs keep
  `k < 8 && k >= 0` as two branches instead of one unsigned compare. Units with short
  literals that would go to `.sdata` under -G8 are -G0 (`gcc296g0`).

- **mw38 stack slots of memory-resident locals:** MW splits a local that must stay in memory
  into one live range per reassignment; every live range after the first gets its own
  4-byte slot at the bottom of the frame (below the temporaries, ascending in program order),
  and the value is re-read every pass. One function-scope `union { LNode* p; }` iterator
  shared by all list loops (first loop assigns the member, later loops assign the whole
  union, a block move) reproduces it (`func_00436380`).
- **mw38 table-walking pointers** come from MW strength-reducing plain int indexes
  (`tbl[row][col]`); explicit pointer locals put the setup before the loop guard instead.
- **mw38 float constants through integer registers:** route only one constant through a
  float local (`float ka = 0.5235988f; c->fov = ka; c->f2E4 = 1.0000001f; ...`) to get
  retail's load order (`002A2590`, `GuiScoresEquip_UpdateFigures`).
- **mw38 misc (newest):** `#pragma optimize_for_size on` changes delay-slot filling; a weak
  destructor on RAII helpers suppresses the out-of-line `__dt__`; byte-offset element
  addressing fixes `addu` operand order; never name an MW asm operand `s1`/`s2`;
  `asm volatile { .set noreorder ... }` is a real barrier; `ok = !(s <= zero)` with an
  unsigned zero local gives `sltu; xori; xori`.
- **gcc 2.96 (newest):** declare callees `int` rather than `void` early (stores move in and
  out of call delay slots); `return 0` right after `if (ret) return ret;` lets gcc reuse
  the known-zero v0, so send it through a single final `return 0`; volatile fields fix
  store order; store zeros as `0.0f`. Register pinning: see Ground rules.
- **Multi-function retail units:** write one file with every function of the unit in
  retail order; `integrate_pending.py` now sizes the new C unit from all of the object's
  `.text` sections (it used to take the first function's size only).

- **mw38 asm blocks and scheduling:** any MW `asm {}` block in a function stops MW filling
  branch delay slots from the fall-through path; write the instruction as gcc-style
  `__asm__ volatile` instead. A non-volatile MW `asm {}` is not a scheduling barrier;
  `__asm__ volatile` and MW `asm volatile` are. `else { asm { .set reorder } }` keeps an
  empty else block.
- **mw38 address CSE:** fields read through `template<int O, class T> struct At { char pad[O]; T v; };`
  are not CSE'd into a saved address register. An inline returning `&e->sub` keeps a
  `+off` base unfolded. `(T*)((char*)base + n*sizeof(T))` with a fresh loop variable stops
  strength reduction.
- **mw38 floats:** float registers are assigned in declaration order but loaded in
  assignment order (declare `ax, ay, az`, assign z, y, x). `cvt.w.s` needs inline asm
  (a C cast gives a different conversion; objdump spells it `trunc.w.s`). A float passed
  to varargs gets `SoftFloat_FloatToDouble` automatically; double compares can call
  `SoftFloat_FloatToDouble` / `SoftFloat_DoubleGreaterEqual` explicitly.
- **mw38 misc:** a `bool` local gives `daddiu` where `int` gives `addiu`; copies of the
  parameters as the first locals order the s-registers; an unused `const T* rr = &r;`
  reproduces a dead address load; a dead address-taken local reserves a scalar slot;
  `*(volatile int*)&x` (commented) reloads a value every pass; initialize a matrix where
  it is declared to avoid temporary copies; a value-initialised default argument
  (`const T& v = T()`) on an inline wrapper gives the zero-fill loop with a null check;
  `#pragma bool off` with `r = c1; r = r ? c2 : r;` materializes test results;
  `{ p = Alloc(); if (p) p = ctor(); n = p; }` keeps the switch join block.
- **Sibling search:** comparing instruction shapes against every matched function finds
  templates for most large matches (`clone_match.py`, and the ROM-based finders used this
  round). objdump folds zero words into `...` unless given `-z`, hiding padding nops in
  diffs; and it prints `move`/`li`, so compare bytes with relocations masked rather than
  mnemonics (addiu vs daddiu, ori vs addiu).

## Earlier near-miss techniques

- **gcc 2.96 types:** changing the declared type of a pointer field (`void*` vs struct
  pointer) or a callee's return type (`int` vs `void`) shifts scheduling and register
  choice; it finished `003177D0`, `003041B0` and `002E6F40`. Weak `.dtors_drop` stubs for
  both callees of an `||` condition turned a stray `bnel` into `bnez` (`002F0E60`).
- **gcc 2.96 shared error exit:** route every later `return N` to one `err:` label placed
  after the first check (`002FF308`). `memcpy(&dst, p, N)` reproduces retail's unaligned
  `ldl/ldr` copies where struct assignment does not.
- **mw38 loop trampoline:** to keep retail's extra jump to the loop test, start the loop
  with `goto tramp;` and put `tramp: asm { nop } goto test;` after the final `return`
  (`ShadowMgr_Construct`).
- **mw38 misc:** `#pragma opt_strength_reduction off` plus a `volatile` read of the count
  (`0032D0D0`); `#pragma opt_arithtransformation off` with an explicit if/else for a
  0/1 result (`002D2BD0`); a trivial `T() {}` constructor on a returned struct makes MW
  build it straight into the local's slot; gcc-style `__asm__` copies stop mw38 from
  unrolling a copy loop, MW `asm{}` blocks do not. Never write an empty `asm {}` block:
  it hangs mwcc.
- **mw38 scheduling barrier:** an empty `asm { .set noreorder; .set reorder }` (or
  gcc's `__asm__ __volatile__("")`) emits nothing but stops instructions moving across
  it. Several committed files already use it.
- **mw38 register order:** the order function-scope locals are declared (in C and C++
  mode) changes which registers MW assigns them.
- **gcc 2.96:** whichever parameter is stored first gets `s0`; copy a parameter into the
  loop variable after an early `return`, not before; `for(;;)` with `break` and one
  return after the loop reproduces retail's block order.
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
- **mw38 stack-slot order by inline depth:** locals of deeper inlines get later (lower)
  slots. Wrapping a helper in pass-through inlines moves its temporary down; declaring
  named struct locals in the outer function and passing them by reference moves them up.
- **Per-call-site helper copies:** when one inline helper is used at several sites and
  each site needs a different register or operand order, give each site its own copy.
- **Hidden return slots:** an inline returning a struct computes the return-slot address
  at the start of the inline; a hand-written copy (`{ V* pt = &tmp; *pt = *p; }`) fixes
  the order.
- **VU0 vector compare:** the original code tests VU0 flags with
  `vnop` ×4, `cfc2.ni f, vi17`, `bne k, f, done`, `ori r, zero, 1`. This sequence is the
  only accepted asm that contains a branch.

## Naming from the PC port research

The private PC port keeps research notes with a generated `ADDRESS_INDEX.md` of every EE
address it cites. Name syncs (2026-10-18/19: 731 function names, 104 data names) went like this:

1. Collect every cited address that is still `func_`/`D_`, read the note or port source comment,
   and name it only where the research states what it does (mark guesses `(inferred)` and leave
   them out). Follow the existing style (`Module_VerbNoun`, `g_` for globals, vtable names
   from the class). Prefix C library names (`Libc_Abort`, never `abort`).
2. Function names: append to `config/symbol_addrs.txt` (`Name = 0xADDR; // type:func`) and run
   `tools/apply_names.py`, then rebuild every C file and require the OK line.
3. Data names: append `Name = 0xADDR;`, rename the `D_XXXXXXXX` tokens in `src/` and `include/`
   yourself (token-exact; `apply_names.py` only renames functions), then the normal round
   (`data_gen.py release --all` ... `data_gen.py` ... `ninja`). The whole split is redone.
4. Commit names separately from matches.

## Merging into translation units

Matched functions are first committed one per file. Fully matched modules are then merged
into one translation unit per original source file (`src/main/<mod>/<mod>.c`), checked
byte for byte over the whole unit's code and data. Merge batches are prepared in
`build/cleanup/` (not committed) with an apply script that refuses a changed tree and a
revert list. On 2026-10-19 `merge_units.py --all-complete` merged 284 units of 61 complete
modules into 110; run it again whenever modules become complete. `--unmerge` cannot split
`main/guiTextListWidget/guiTextListWidget_6`, whose blocks are themselves earlier merged units. Gotchas: every merged block ends with an empty `static inline` function so
the compiler emits each function in the right C/C++ mode; MW 3.0.3 and 3.0b38 order
locals differently; a shared helper prototype that callers use inconsistently is declared
K&R in a shared header (for example `include/SFOLobby_helpers.h`).

## Known blocked work

- `func_004769A4` (gcc296) is instruction-identical, but its asm unit (0x476998) runs on
  into the data block at 0x476B00; it needs a split at 0x476ABC near the fragile
  `d_00476B00` data units.
- `Mem_Init` (0x36B630) references `D_01FF0000`, `D_0059A980`, `D_0059C980`, which have
  no symbol entries.
- Some functions reference `.lit4` float literals that the current linking cannot place.
- `0x286570`: both function bodies match, but the unit needs a split at `0x286590` (see below).
- Hand-written assembly functions stay as assembly.
- `0x2B69A0` (gcc 2.96 -G0) matches in `check_match`, but the `"/"` string it owns at
  `0x4AC1C8` lies inside `lib/func_002B6808`'s `.rodata`, so integration skips it. The
  draft is `build/pending/hold/gcc296g0_002B69A0.c`; that rodata needs splitting by hand.
  (`0x31D558` went in with `0x31D2A8` in R133, and `0x31A630` was integrated earlier.)
- `0x286570` may now be fixable the same way as the `0x416830` thunk unit: add a
  `// type:func` symbol at `0x286590` and integrate both functions in one file.
- `0x17D700` is a C++ constructor; a match compiles to
  `__ct__10Curve_d700FRC2V4RC2V4RC2V4RC2V4f`, so `config/symbol_addrs.txt` needs that
  mangled name (or the real class name) at that address first.

## Readability

Fully matched modules were cleaned up module by module (names, shared struct headers
in `include/`, enums for magic numbers). [HEADERS.md](HEADERS.md) lists the headers.
Function names live in `config/symbol_addrs.txt`; add a name there and run
`tools/apply_names.py` so every caller is renamed. Many matched modules still use
`func_XXXXXXXX`, `D_XXXXXXXX` and raw offsets.

## Open decisions for the owner

- Whether to commit hand-written assembly functions as `.s` units.
- Whether to give data the same readability treatment as code.
