# A3 notes (2026-11-02, older near misses)

Tools (all in build/agents/A3/, scored with the P4L lab.py, ~0.07 s per compile):
- sweep.py TEMPLATE FUNC START END [--rand N]: choice points `{{a|b}}`, `{{a@@b}}` or `<<<a@@b>>>` (use `<<<>>>` when an
  option contains braces); `{{#NAME:..}}` links points that share an index. Enumerates (or samples) every combination.
- pick.py TEMPLATE OUT i,j,..: render one combination. perm.py: random shuffles of the lines between `//P<` and `//P>`.
- fo_gen*.py / gcd_gen.py: one-off generators (barrier placement, dead locals, parameter orders). cdis.sh: compile+objdump.

## cFireObj_ctor_cPopulationR 0x2625B0 (1040 B)
- best: **fo_best9.c, 9 check_match words (k7 fo9.c was 21 / lab 26 -> lab 9)**, exact size.
- change (fo_t1.c sweep, 2400 combos): the copy constructor stores through `this` (`asm volatile { lq t, 0(ps); sq t, 0(this) }`,
  `ps = &o` local kept) and ScaleR passes `ScaleV(&r, &a, s)` with no pointer locals; ScaleV keeps `pa = a` but stores through
  its parameter `r`. This is the Z2 read-form rule: which pointer is a named local and which is read directly sets the colours.
  It fixed result=v1 / copy-dest=a1 in both scale blocks.
- remaining (both scale blocks): ScaleV's operand pointer pa gets v0 and is materialised late (retail: a2, between `lui` and `mtc1`).
- fo_bar9.c (also 9 words): `const cVector* q = &a; asm volatile {}; cVector r; ScaleV(&r, q, s);` in ScaleR (or a GCC
  `__asm__("" : "+r"(q))`) puts pa in a2 at retail's position, but then the copy temp takes v0 instead of a0 and the copy
  source `addiu a0,sp,128` moves below `lui` in block 1.
- no gain (all >= 9): ScaleV parameter orders (6), ScaleV declaration vs assignment orders (Y3, 144), copy-ctor declaration
  orders with/without the barrier (112), member operator* forms, asm written directly in operator* (33+), `half` float local,
  dead pointer locals in ScaleR/operator*/ScaleV/operator+ (540 combos), barrier type x placement (10 sites x 2 kinds, pairs),
  16 pragmas (opt_*/peephole/scheduling/inline_depth), function-level less-optimised trigger (already in that mode).

## Monster_ctor 0x405660 (728 B)
- best unchanged: mo0.c (= k6 base_405660.c), lab 25, check_match 22 words.
- remaining: SUB/TYPE/LOD/FULL mask block: scheduling + registers (retail TYPE pcpyld result shares TYPE2's a1, FULL shares v0).
- prototype __ct__7MonsterFv 0x3F1220 is byte-identical to retail apart from relocations; one source line per statement
  (1210..1231, `pl.sh 3f1220 2d8`). Prototype locals: all masks are `unsigned long` (u64).
- finding: MW materialises a u64 *constant* converted to u128 (inline u128 parameter) as a compiler-generated
  `pcpyld x,zero,x`; a non-constant conversion emits nothing. The scheduler fills after a compiler-generated pcpyld
  but not after an asm pcpyld.
- no gain: per-site helper forms (kpu/kraw/kfr2/ksub/kqq/(u128) casts; 1500 random of 9 sites, mo_t1/mo_t2),
  1500 random declaration orders of the 12 u64 locals (perm.py: 25..52), per-site `asm volatile` helpers (1024, size grows).

## cVisionFxMan_DeactivateFx 0x25F930 (632 B)
- best unchanged: k_vf0.c, lab 18, check_match 28 words.
- note: retail's a, b, g, r store order (a first, then one trunc and three mfc1 for b, g, r) looks like right-to-left argument
  evaluation of a 4-argument call/ctor. Tried tIRGBA(int,int,int,int) ctor (3 body forms) and Set(int x4) with
  float/int arguments (vf_t1.c): 37, still one mfc1. Function-level less-optimised trigger: 26.

## cAgentData_ctor 0x336700 (812 B)
- best unchanged: ad_best28.c, lab 27 (201 vs 203 instructions).
- the inner j loop in retail looks less-optimised (no strength reduction of j*24, per-iteration `addiu s6,sp,164`/`s8`,
  `bnez; nop`), but the rest of the function is optimised (unrolled member-ctor loops), so the function-level trigger is wrong
  (128). Barrier variants (volatile/non-volatile GCC asm with s/j operands, memory clobber, asm nop) and index forms: 27-47.

## GetCollisionDist 0x22A8C0 (604 B)
- best unchanged: gcd_best28.c, lab 29.
- residual is a v0/v1 swap of {result ptr rp, copy temp} vs {operand ptr, mfc1 temp, copy dest}, again in the Length block.
- FireObj's cure does not transfer: MulV/SubV helpers storing through the param, ap/bp local vs direct, MW asm copy ctor with
  `sq t, 0(this)` (31, rp moves to a0), `asm volatile` and noreorder options (5184 combos, best 25 but 153 instructions),
  MulV parameter orders x bulMat read forms (BM()/TD() accessors), `const V&` direction param: all 29.

## CheckBulletCollisions 0x22BA30 (1636 B)
- not attempted (time). bc2.c still uses placeholder callee names; n2 NOTES list the real names.
