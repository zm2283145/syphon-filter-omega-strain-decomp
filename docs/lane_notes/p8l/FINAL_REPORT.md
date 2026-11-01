# P8L final report (2026-11-01, 16:51-18:25)

## Staged (2)
- cHumanIkRoutine_CalculateLeftWristTargetRot_Local 0x1D2F90 (2760 B) -> build/pending/p8/mw38_001D2F90.c
  (source build/agents/P8L/lw/lw_match.c). check_match: function MATCH, DATA .rodata 0x49FF90 MATCH.
- UpperBody_HandRotation (= CalculateRightWristTargetRot_Local) 0x1D40E0 (3528 B) -> build/pending/p8/mw38_001D40E0.c
  (source build/agents/P8L/rw/rw_match.c). check_match: function MATCH, DATA .rodata 0x4A0070 MATCH.
- Both: no UNDEF symbols; callees as in P6L's drafts (project names); inline asm only for lq/sq quadword copies, VU0
  macro ops, cfc2 flag tests, abs.s and MtxToQuat (comment at the top of each file); no register pinning; no
  whole-function asm. 0x1D2F90 is already its own `asm` segment in config/splat.yaml (0x0D2F90-0x0D3A60), so LeftWrist
  stages alone (no PositionArm unit split needed). Checked with HOLD absent.
- The fix (same in both wrists) is one site-specific chain for the case-24 premultiply:
  `V& MulR0(V& r, a, b) { V* p = &r; QMulT(p, &a, &b); p = &r; return *p; }`,
  `V MulR(a, b) { V r; return V(MulR0(r, a, b), 1); }` with a new copy ctor
  `V(const V& o, int) { const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(this) } }`.
  Re-taking `p = &r` after the asm makes MW rematerialise the address (retail's late `addiu v1,sp,304` and lui-first
  schedule); building the return copy one inline level above the helper that owns p fixes the v1/a0 colour swap.

## Near misses
- cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans 0x1E7F40: unchanged at 2 words (P6L's
  best/df_best.c). About 5000 more variants (statement/constant orders, separate zero asm blocks of every flavour,
  dead C zeros, reversed rate order, GCC asm forms, MW-asm cVector copies) never beat 2. A zero inside the min's asm
  block is always emitted right before the min.s, and a separate zero asm is a scheduling barrier, so retail's
  early first zero with lui22 hoisted above it was never reproduced. Details: NOTES.md.
- cHuman_HandleJumpInit 0x1914C0 (4608 B): new draft best/hj_best.c (= hj/h90_T_0.c), written from the retail asm
  with human_44.c's anim-checkpoint idioms. lab 22 lines, exact size (1152 insns), all 79 stack slots right. Left:
  (A) case-21 message-copy vec lq/sq placement (retail last; mine first) plus a related beqz delay-slot nop and a
  nop shift; (B) X3/X4 AddRequest argument order (t1 = p1 set first in mine, last in retail). Details: NOTES.md.
- cHuman_NextFrame 0x1B1710: scoped only (NOTES.md).

## Reusable findings
1. Address rematerialisation: re-assigning a pointer (`p = &r;`) after an asm block that used it makes MW recompute
   the address at the use (late `addiu`), instead of keeping p live or computing a fresh vreg early.
2. Colour swap across a region: move the copy's inline level relative to the helper that owns the competing pointer
   (return-copy one level up), rather than changing the copy's own depth.
3. A C-level 128-bit copy (`*(__int128*)d = *(__int128*)s` or an aligned struct assignment) anywhere in a function
   makes MW stop filling branch delay slots in the whole function. Use asm lq/sq for every quadword copy.
4. Statement order still matters for the pre-RA scheduler: a constant pointer setup (`sys = &self->sys`) placed before
   constant stores changed ~40 lines in HandleJumpInit.
5. `asm volatile { .set reorder; ... }` copies are scheduled, but they are barriers for the following ALU argument
   setup. Putting such a copy FIRST in an inline copy lets the call arguments hoist (t-register copy temps).
6. Inline pass depth decides frame groups. Wrappers (Play_L -> Play1_L -> Play0_L) push a helper's locals to retail's
   group; this fixed all 79 HandleJumpInit slots.
7. Main-level declaration order decides s-register colours: declaring `Sys_L* bsys; int* bblend; X_L* px;` at main
   level and passing them by reference into the inline helper fixed HandleJumpInit's X3/X4 colouring (-37 lines).
8. A dead init in a clamp helper (`float r = 0.0f;` overwritten by the asm max.s) survives as a dead `mtc1 zero`,
   matching retail's otherwise unreproducible extra zero.
9. Indexing a macro's source directly (no named source pointer) changes a-register colouring in a byte-copy loop.
10. Extra/missing nops can come from MW padding branch targets to 8-byte alignment: a one-instruction difference
    earlier in the function shows up as a nop elsewhere.
