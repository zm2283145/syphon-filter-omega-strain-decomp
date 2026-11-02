# Q1 notes (2026-11-01 evening): large human functions

Tools: l.sh (generic lab diff: l.sh file FUNC START END [-v]), hj.sh (HandleJumpInit lab), fill.sh (counts
unfilled branch delay slots; hj0 baseline = 31/68, "unfilled mode" = 49/68), var.py (one-string substitution),
linebis.py (delete each statement, report fill mode), grid1.py/grid2.py, m/mc.sh (micro compile+disasm).

## 001914C0 cHuman_HandleJumpInit (4608 B) - best still hj0.c (= P8L hj_best.c): 22 lines, exact size
- (B) X3/X4 argument order. Grid (grid1.py, 96 combos: init via p1/&e1, p2/&e2, args p1/&e1, p2/&e2, dtor form,
  position of xx = x): nothing below 22. Passing &e1 puts `move t1` late (retail order right) but RA then gives the
  e2 vt lui v1 and the -1.0 lui v0, so the -1.0 lui is hoisted (58). Float locals w/z, (signed char) casts,
  *blend/&blend[1], `x` instead of xx: no change. Real C++ temporaries `AddRequest(..., AMsgC(), AMsgC(), ...)`:
  messages addressed via sp instead of s1/s2 (273). Prototype has the same t3,t0,...,t1,t2 order (and only one
  float arg; retail adds f13 = 0.0).
- (A) case-21 copy. Facts found:
  * "Unfilled mode" (no delay-slot filling in the whole function) is NOT caused by C-level 128-bit copies as such
    (micro tests m/t1..t3 fill normally). In HJ it is caused by a C-level 128-bit copy of msg->vec together with the
    later asm copy `QCp1_L(self->jump.plc.p, &msg->vec)`. Adding `asm { .set reorder }` right AFTER that jump
    copy (or after `paramsValid = 1;` in the same block) restores filled mode (hj2.c, 37 lines).
  * With the C-level copy last (hj2.c), the case-21 block has retail's shape (beqz nop, lui v0 first, args
    li v0,4/a1/a2 hoisted, field temps t0/a3/v1) but: pc is coalesced with the call's a0 (retail keeps t3 and
    recomputes a0), and MW folds the 128-bit copy offsets (lq v1,48(s1)/sq v1,48(a0)) where retail has
    addiu t1,s1,48 / addiu t2,t3,48 early and lq/sq last. No C form avoids the folding (helpers with pointer or
    reference params, __int128 struct members/arrays, char*-offset pointers: all fold).
  * Asm copy last (vq.c, 64): asm is not a post-RA barrier (args get scheduled between lq and sq), but RA gives the
    copy a0..a3 because the args are defined after the copy in pre-RA order; retail's register choice implies the
    args were live across the copy (as in the C-level version, where the pre-RA scheduler hoists them).
    Tried: copy inside the call's argument expression (Prep_L returning pointer/reference), C++ class with copy
    ctor and temporaries/named object (MsgV, mkq.py): 64-67 or stack-slot breakage.
  * Prototype .line: the whole copy+QueueMessage+dtor is one source line (12196); vtables cMessage ->
    cCharActionMsg -> cCharActionMsg_Vector.
- Next idea: a 128-bit copy form that is C-level for the pre-RA scheduler but keeps pointer operands (maybe a
  GCC-style non-volatile asm with "r" inputs, or an asm whose pointers are computed in a deeper inline pass).
- Non-volatile copies are parsed and optimized like C: GCC-style `__asm__("lq ...")` without volatile and MW `asm {}`
  without volatile both get their offsets folded (lq v1,48(s1)); only `asm volatile` keeps retail's pointer
  operands (addiu t1,s1,48; lq v1,0(t1)), and `asm volatile` blocks the pre-RA hoisting of the call arguments.
  Inline depth of the copy helper (0-4 wrappers) and `volatile __int128` C copies: no change (37).
- Drafts: best/hj_best.c (22, = P8L), best/hj_ccopy37.c (C copy last + barrier, filled mode, 37),
  best/hj_asmlast64.c (asm volatile copy last, 64).

## 001BC4B0 cHuman_HandleMoveMessage_cMoveMsgTemplateR_2 (4316 B) - best/hm1_best.c: lab 33, check_match +46
- Retail <1> is exactly retail <0> (0x1BB1D0) plus a tail (rdis.py diff, ratio 0.937): the only other change is the
  ctrl pointer in s1 instead of s0. So p2l hm2.c (= k8 bb4.c with real names) + the tail gives the same residual
  as <0>: lab 33 / check_match +46 for both. The tail matches retail on the first try:
  `if (a->phys) a->phys->f11 = 1; if ((a->flags >> 10) & 1) cHuman_Land(a, 0);
   if (((a->flags >> 7) & 1) || ((a->flags >> 8) & 1)) Send(ActMsg(0x13), a);
   if (((a->flags >> 16) & 1) && !((a->flags >> 15) & 1)) Send(ActMsg(0x24), a);
   if (a->phys) PhysReset(a->phys); a->f30A0 = 0; a->f30A4 = -3.4028235e38f; a->f30A8 = 0; return 1;`
  (the `if (0) Send(...)` lines in <0>'s draft are where these sit in the template). Names fixed to
  symbol_addrs (cMessage_ctor_cMessageNameR, QueueMessage_cMessageR_cSystemP_int, cHuman_Land).
- Residual (shared with <0>): msg/edge s4<->s2 swap (~28 lines), extra `andi v0,0xff` in the first Free test,
  one addiu order at the Q(M44) ctor. Any fix for <0> applies to <1> unchanged.
- Swap facts (g/g4 table): among the anchors, the FIRST declared is always coloured s4 unless it is flor
  (flor first -> s0). A msg copy declared first is coalesced with the param and gets s0/s1; using the param
  directly (pointer or reference, or through an inline Body(a, msg) wrapper) gives msg s0, a s1 (117).
  A local `const Msg& mr = *msg0` behaves like the copy (33 after anchors, 117/118 before). Casts on the copy
  ((Msg*)(int), +0, &msg0[0], const, register) don't stop coalescing. The prototype has the same colouring
  (flor s3, edge s2, ladd s1, msg s4) without AllFree, so the retail colour is natural for the original source.
- Pragma sweep (opt_lifetimes, propagation, common_subs, loop_invariants, dead_code, scheduling, register_coloring,
  global_optimizer): no change; peephole off / optimize_for_size worse.

## 0018A950 cHuman_HandleDeath - looked only (k8 pG.c, lab 21, 3 clusters: P56 pair store order, InstNR `an`
  colour (retail computes an=s3 before the PlaybackGroupId ctor and loads model via 0(s3)), TailC s0/s3).
  No new attempt.

## 001B1710 cHuman_NextFrame - not attempted.
- Use-count check: `msg->row3` instead of `msg->Trans()` (more direct msg uses) leaves the colours unchanged
  (msg s2, edge s4) and breaks the temp slots (120), so the colour order is not simple use-count priority.
