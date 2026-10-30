# Matching techniques

A digest of what has worked when matching functions of this game. Treat it as a list of
starting points, not as rules: always confirm with `tools/check_match.py`, and count a match
only after the full build prints the `OK:` line.

## Compilers

| kind | compiler | used for |
|---|---|---|
| `mw38` | CodeWarrior PS2 3.0 build 38 (Mar 2003) | most game code; try it first |
| `mw50` | CodeWarrior PS2 3.0 build 50 | some STL code (unrolled vector-erase copy loops) |
| `mw304` | CodeWarrior 3.04 | a few units |
| `mw` | CodeWarrior 3.0.3 | older units (the default) |
| `gcc296` / `gcc296g0` | EE-GCC 2.96, `-O2` / `-O2 -G0` | library code (newlib, XML, timing, IOP RPC clients) |
| `gcc29` | EE-GCC 2.9-ee-991111, `-O2 -G0` | older Sony SDK code (s-registers saved 16 bytes apart, `ra` restored first) |
| `gcc` | EE-GCC 2.95.3 | some library code (uses `mult` for small multiplies) |

- MW flags: `-O4,p -sdatathreshold 0 -char signed`. Do not use CodeWarrior 3.03J.
- Signs that a function is GCC-built: `%gp_rel` data, branch-likely instructions, `movz`/`movn`,
  `sd` register saves, `lui $at` + `mtc1` float constants. MW saves s-registers with `sq`.
- Build 52 reproduces both b38 and b50 output; no other CodeWarrior build fits the game better.

## Acceptance

- Every function line MATCH, no UNDEF line except `__dl__FPv`, any DATA line MATCH, one function per file.
- Data: one contiguous retail block per unit in compiler emission order; no `.bss`/`.sbss`/common
  definitions (use `extern`); never call a `D_` symbol (callees are `func_XXXXXXXX` or their names).
- Inline asm only for instructions C cannot express (VU0/COP2, MMI, `max.s`/`min.s`/`abs.s`, the
  documented 16-byte copy idioms). Scheduling barriers and weak stubs carry a one-line comment.
  Never transcribe ordinary compiled code into asm.

## CodeWarrior: general

- Per-function pragmas, always wrapped in `#pragma push` / `#pragma pop`: `optimization_level 1`
  (wrappers keeping a frame), `peephole off`, `opt_propagation off`, `opt_common_subs off`,
  `opt_dead_assignments off`, `opt_strength_reduction off`, `opt_rotateloops off` (loops entered
  with a jump to the bottom test; whole-function), `tailcall off`, `global_optimizer off`,
  `inline_depth(10)`. `#pragma peephole` applies per function, by its state at the closing brace.
- Register and stack-slot order follow local declaration order; on mw38 the first declared local
  gets the highest address. Function-scope locals come first, then block-scope locals, then
  temporaries. Scalars are placed before aggregates. Moving a declaration into a nested block, or
  wrapping a helper in extra `static inline` pass-through layers, shifts slots.
- At `optimization_level 1`, locals of size <= 8 form separate groups at the top of the frame (at the
  bottom when the frame exceeds 32 KB); everything else is placed in reverse declaration order,
  16-aligned.
- Inline-function arguments are evaluated right to left, which sets `addiu` order and argument registers.
- `return a <= b;` gives the branchy bool; `#pragma bool off` with an int-returning inline gives the
  materialised `xori` form; `!(x >= 0)` gives `slt; xori; xori`.
- A ternary instead of if/else removes the pad `nop` before a branch-target label. Dynamic casts:
  `p = (p && p->IsA(&type)) ? p : 0;`.
- A switch's compare chain is emitted in reverse source-case order. A one-case-plus-default switch
  gives the `beq` + `b` layout.
- `(T*)((char*)base + i*size)` or index-first `(Row*)((i << 5) + (int)m)` fixes operand-order diffs.
- `n > 0x22E8BA` instead of `n >= 0x22E8BB` gives the `$at` compare. `n > 1` and `n >= 2` can pick
  different registers. `if (i > -1)` gives `slti`+`bnez`.
- Read through a volatile pointer to force a separate load that retail performs.
- A pointer-typed argument scheduled too late: declare that parameter `int` and pass `(int)ptr`.
- Nops after `div.s` come from C shape (e.g. `r = r / arg;` before the call), not the compiler version.
- MW fuses into `madd` unless a float expression is split into separate statements.
- Delay slot filled from the fall-through path: set the value before the `if` and put an empty
  `asm { .set reorder }` in the then-arm (a barrier; comment it).
- `#pragma optimization_level 3` plus an asm barrier reproduces "b + delay slot, unfilled beqz,
  jr ra; nop" with label padding.

## CodeWarrior: C++

- Virtual calls (`lw $t9, slot(vt); jalr $t9`): a local C++ class with numbered, declared-but-undefined
  virtual slots; slot `i` sits at vtable offset `8 + 4*i`. Use `#pragma cplusplus on` and `extern "C"`
  on the matched function. Virtual methods returning floats must be declared `virtual float`.
- Out-of-line helper destructors must not stay in `.text`: mark them `__declspec(weak)
  __declspec(DROPDTOR)` with `#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX`
  (weak first), as `include/alloc_guard.h` does. The allocator lock guard `AllocGuard` gives the +16 frame.
- Real out-of-line constructors/destructors whose body only reproduces as `T::T(...)` need the
  mangled name; keep them separate.
- Returning a struct by value from a virtual method: give the struct an empty constructor so the
  result is constructed in place.
- Plain C with explicit vtable stores often matches C++ message temporaries better than real C++.
  Event classes differ in size; the wrong size shifts every stack slot.
- Iterator families: 4-byte raw structs returned by value plus a converter;
  `while ((conv_end(&end, f_end(list)), node != end))` shares one temporary across both End calls.
  Keep `end` at function scope, iterator/node in inner blocks, AllocGuard in its own block.
- 1-bit bitfields whose type is a template parameter give word `lw`/`sw`; plain ones narrow to a byte.
- Weak-handle getters: `bool ok = !t || t->serial == h->serial; return ok ? t : 0;` gives the `andi`
  form; the `isNull`/`ok` two-flag form gives `bnez`/`movz`.

## 16-byte copies and VU0

- Struct copies with `lq`/`sq` come from 16-byte aligned struct assignment, or an `__int128` member.
- Unfolded `addiu` + `lq/sq 0(reg)`: `#pragma peephole off` + `opt_propagation off` and a local copy of
  the parameter; or keep peephole on and use the `V4Copy` idiom (`lq` under `.set noreorder`,
  `.set reorder` between `lq` and `sq`). Freely scheduled copies: `VCopyF`/`VCopyFF`, or each `lq`/`sq`
  as its own `asm { .set reorder; ... }` statement.
- Copies alternating two registers (`lq lq sq lq sq ...`): two named `__int128` temporaries written in
  pipelined order with peephole off, destination pointer declared before the temporaries. Don't name
  C locals like machine registers (`s0`, `t0`, `a0`, `v0`, ...): inline asm parses them as registers.
- An unfolded copy of a global into a stack temp is often an aligned struct passed by value to an inline.
- VU0: write the instructions in `asm { }` blocks inside ordinary C; C variables can be operands and
  declaration order steers register choice. `.set noreorder` emits a block exactly as written.
  `vcallmsr` counts as a call. `#pragma opt_dead_assignments off` keeps dead zero-inits before asm blocks.
- Grouped float4 copies under propagation/common-subs off: declaration and load/store order of the
  four floats picks the FPR allocation.

## EE-GCC

- 2.96 makes the C then-block the fall-through: flip conditions to match the retail layout.
  Cross-jumping copies the last statement before a merge into both branches.
- Branch-likely vs plain branch where the fall-through starts with a call: in the original
  translation unit the callee was defined in the same file. A weak empty stub of that callee in a
  section the link discards reproduces it:
  `void __attribute__((weak, section(".dtors_drop"))) func_XXXXXXXX(void) { }`
  (the strong definition still wins at link time; comment the stub).
- Likely vs non-likely mismatches are otherwise structural: combine early-outs that return the same
  value with `||`, nest the tail with a single return, or flip if/else.
- `int ret = N;` at the top then `return ret;` puts the `li` in the first branch's delay slot.
- An empty `__asm__ __volatile__("")` after a call stops the tail-call optimisation (gcc29 turns a final
  call into `j`; `return f()` also stops it). Callee return type picks the temporary register.
- `volatile` on globals stops branch-likely delay-slot filling and keeps store order. `extern volatile`
  stops a `%gp_rel` load landing in a delay slot. A local `T *p = &G` forces the base into an s-register.
- Callee-side `andi 0xFFFF/0xFF` masks mean `unsigned short`/`unsigned char` parameters.
- 2.96 rounds decimal float literals slightly differently: use hex float literals. fdlibm constants
  go in function-local `const float`; tables and constants that fold to infinity are `extern const`.
- newlib: ctype macros as written in newlib (`(table + 1)[c]`); varargs with `__builtin_va_list` and
  `__builtin_stdarg_start`. gcc29 varargs: `ap = (char*)__builtin_next_arg(fmt) - ...` places `ap` at the
  saved `a1`. A 64-bit multiply: call the helper declared `__attribute__((const))` instead of `*`.
- Constant byte stores emitted as `li v0,0xB0`: go through an `int` local. Keep the else-if sense with
  `(unsigned)id >> 31` instead of `id < 0`.
- Listing switch cases in reverse value order reproduces a binary-tree layout (gcc29).

## Data

- Write data naturally: string literals, switch statements (jump tables), `static const` tables,
  initialised globals. A string used by several functions belongs to the first user; others keep
  `extern char D_xxxxxxxx[];`. See `docs/data_split.md`.
- Never put raw control characters (CR, LF) inside a string literal; write `\r`, `\n`.
- Float literals: emit the shortest decimal whose value equals the float exactly.
- Tables of pointers can only refer to symbols that exist at link time; labels inside another unit's
  linked data block, or inside the table's own block, are not defined symbols.
- Owned strings passed only as family-macro arguments: define `char D_x[] = "...";` before the macro line.

## Large and generated functions

- Builders made only of calls (straight-line `optimization_level 1` functions) can be generated from
  the asm: track argument registers per call, nest call results in left-to-right argument order, turn
  results used twice into temporaries, float callee-saved registers become `float` locals, and size
  locals from address gaps (`struct { char d[N]; }`), grouping 8-byte objects into 16-aligned blocks.
- Static initializers: move each `__register_global_object` call right after its object's init;
  template-static guard blocks are one-level `if (!guard) { ... }`.
- Registration helpers taking a value argument from 8-byte-stride constants: pass `(int)&D_x` with
  `extern char D_x;` to get the retail `lui` order.

## Workflow tips

- Iterate with `tools/try_match.py` (fast compile matrix); confirm with `tools/check_match.py`.
- Start from a decompiler draft for control flow and offsets, then type the fields from matched
  neighbours; restore leading parameters the draft dropped and size the last local to the frame gap.
- Solve one member of a family, then share a typed helper header and keep each instance's own
  relocation targets (template clones are not interchangeable).
- Search spaces worth brute-forcing: local declaration order, statement order inside a block,
  pragma combinations, and compiler kind.

## Array-stride constants mistaken for addresses

An already byte-identical C function can report a small objdiff mismatch when splat
turns a large numeric array offset into a symbol relocation. In voBufCreate, four
unrolled multiples of the 0x4CE40 VoTag stride happened to coincide with text addresses;
the actual code adds a runtime buffer base before the store.

Only reviewed pairs belong in config/asm_literal_offsets.json. The assembler helper
checks their original words, signed HI/LO value and dynamic-base addition before
restoring literal operands for that unit. Check the normalized comparison target
against retail and preserve the full build hash. The configuration does not disable
symbol checks globally.
