# P8L notes (2026-11-01): P6L's near misses (wrists, DetectFor) + HandleJumpInit / NextFrame if time

Tools: micro/run.py (DetectFor rate block micro, prints from the 15.0 lui), micro/t24.py (wrist case-24 micro,
prints after the QMulT sqc2), df/l.sh (lab diff for DetectFor), lw/common.py + lw/one.py + lw/grid*.py (case-24
full-file grids scored with P6L/tools/lab.py), lw/show.py (diff one grid cell).

## 001D2F90 LeftWrist + 001D40E0 UpperBody_HandRotation (RightWrist) - STAGED 17:13 (both MATCH, DATA MATCH)
- Files: lw/lw_match.c -> pending/p8/mw38_001D2F90.c, rw/rw_match.c -> pending/p8/mw38_001D40E0.c.
  0x1D2F90 is already its own `asm` segment in splat.yaml (0x0D2F90..0x0D3A60), so no unit split is needed.
- The fix is one site-specific chain for the case-24 `PreMul(rot, Inverse1(elbow rot))`:
  `V& MulR0(V& r, a, b) { V* p = &r; QMulT(p, &a, &b); p = &r; return *p; }`
  `V MulR(a, b) { V r; return V(MulR0(r, a, b), 1); }` with a new copy ctor
  `V(const V& o, int) { const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(this) } }`,
  then PreMulR0 = the old PreMul0 (asm copy t -> q).
- Why it works (found with micro/t24.py + grids lw/grid1..11):
  1. `p = &r;` re-assigned after the QMulT asm makes MW rematerialise the address (`addiu v1,sp,304` right before
     the lq) instead of keeping p live; this alone gives retail's lui-first order (lui/base, dst1, jointRef, src2,
     src1), but swaps v1/a0 across the whole Inverse+QMulT region.
  2. Building the return copy one level UP (in MulR, from a reference returned by MulR0) instead of inside the
     helper that owns p flips the colouring order of p vs the copy's pointers -> v1/a0 right.
  3. The copy needs a separate data temp (`__int128 t`), ps named and `this` used directly in the asm.
     Data-in-src forms (tagged `lq ps,0(ps)`) give the right colours but lose the lui hoist (9 words); C-level
     __int128 stores fold the dst into `sq v0,480(sp)` (6 words).
- General lesson: when an asm-copy schedule is right but colours are a consistent swap, move the copy's inline
  level relative to the helper that owns the competing pointer (not the copy's own depth).

## 001E7F40 DetectForAndHandleCollisionWithOtherHumans - still 2 words (unchanged from P6L's df_best.c)
- Retail: lui15 | mtc1 f0 | lui22(v1) | mtc1 zero,f21 | andi s8 | mul.s | lui1 | mtc1 f1 | mtc1 v1,f2 | min.s f21.
  Mine: the zero and `mtc1 v1,f2` swapped.
- Facts found: a zero written in the same asm block as the min.s is ALWAYS emitted directly before the min.s (every
  form, every flavour) -> retail's free-floating first zero is not in the min's asm block. A separate
  `asm volatile { .set reorder; mtc1 zero, rate }` statement acts as a scheduling barrier for FPU ops after it in
  source (ALU lui can still cross only if its register allows). Best separate-zero form: P,k15,Z,k22 -> 4 words
  (zero early as in retail, but lui22 gets v0 and is not hoisted, mtc1 f2 before mul.s).
- A dead C `float r = 0.0f` survives only in the LAST min of a block (micro m3/a forms), not in the first.
- Tried (all >= 2): k22 placement permutations with separate Z (df/search1, 307 combos), reversed statement order
  (search2), k22 assigned inside the min helper (search3/4), GCC "+f"/"=f"/"0" forms (zero eliminated),
  reference parameters (1.0 goes to the literal pool), mov.s/dummy instructions (peephole removes them).

## 001914C0 cHuman_HandleJumpInit (4608 B) - draft best/hj_best.c (= hj/h90_T_0.c): lab 22 lines, EXACT size
- Started 17:15 from the retail asm (asm/914C0.s names) + proto .line + DWARF locals; the anim-checkpoint idioms come
  from matched src/SFOGame/Source/human_44.c (XInit/XSetR/XDtor/Play/Prio/AddI/NAME_COPY/QZero/QCopy). Path:
  824 -> 324 (frame) -> 85 -> 78 (exact size) -> 62/41 -> 39 -> 24 -> 22. All 79 stack slots right since h13.
- Frame model that fixed every slot: named function-scope locals `transform, takeOffAnimName, inAirIdleAnimName`
  first; then block locals in source order at main level; Blend's (Find iterator + 2 cMessage) one pass deeper;
  AsPoint's `pos` two passes deeper; Play's and AddI's three passes deeper (Play_L -> Play1_L -> Play0_L wrappers).
  Small (4 B) and 8/12 B slots are separate regions above the 16 B region.
- Must-haves: GetState (vt 0x108) via a C++ class with VPAD slots (t9 jalr); `if (prio == 4) return; if (prio == 5)
  return;` (not ||); no C-level 128-bit copies anywhere (switches MW to "unfilled" mode: no delay-slot filling in the
  whole function; hj/chk.sh tests this) - every quadword copy is asm lq/sq; `sys = &self->sys;` BEFORE the rate
  stores in both case-20 blocks; early rate = constant stores, late rate = `float d = 0.2f; ... Recip(d)`; Set5
  starts with the pointerless setter, Set4 with the `Pair_L* p` setter; separate p1/p2 for ScheduleEvent results.
- New fixes 85 -> 22:
  1. Block-1 clamp `ClampQ_L(x) { float r = 0.0f; float lo = 0.0f; float hi = 1.0f; asm { max.s r,x,lo; min.s r,r,hi }
     return r; }` (dead `r = 0` init survives as retail's second `mtc1 zero,$f1`) -> exact size (-7).
  2. X3/X4: declare main-level `Sys_L* bsys; int* bblend; X_L* px;` in that order and pass bsys/bblend by reference
     into BlendS_L -> s-register colouring right (-37). Declaration order of main-level locals decides s-reg colours.
  3. AddRequest second message passed as `&e2` (not through p2) (-2).
  4. Block-2 NAME_COPY with no named source pointer (`(src)[i]` directly) -> a-register colouring right (-15).
  5. Case-21 MsgCopy: `QCpT_L(&pc->vec, &m->vec)` data-in-source asm copy first, then vt/field copies (-2).
- Left (22 lines): (A) case-21 message copy: retail has a nop in the beqz delay slot, vt1 lui first and the vec lq/sq
  LAST (after the vt3 store); mine does the vec asm first. Asm last kills the argument hoist (61-64); C-level copies
  trigger unfilled mode (70-76, h98a-d). The extra nop after cMessage_dtor follows from the same one-instruction
  shift (MW pads so branch targets are 8-byte aligned). (B) X3 and X4 AddRequest argument order: retail t3 (x),
  t0 (blend+4) ... `move t1,s2` (p1) last, mine sets t1 first. Passing &e1 fixes the order but perturbs the vt/-1.0
  constant schedule (60+).

## 001B1710 cHuman_NextFrame (3936 B) - scoped only
- Retail asm (asm/B1710.s, compacted in hj/nf_retail.txt) is far from the prototype (pcmp ratio 0.706): a large new
  multiplayer front part (cNetHuman sync of hitpoints/weapon/flashlight via m_NetHuman 0x3584, IsActive/Is58/Is5C
  controller tests, printf + cNetHuman_Activate/Deactivate, state-bit copies into 0x3248 incl. 0x40000000/0x80000000
  dsll32/dsrl32 bitfield code, an ActorAction message 0x43), then Motion/Choke/AnimationEvents, the 3-entry
  particle-effect safe-pointer loop (0x3548 cSafePtr[3], Actor_Ignite / SetParticleEffect / fire damage through vt 0x100
  and SoftFloat double math), splined motions, ladder/anchor weights. ~70 calls, 13 virtual. Needs the same human_44
  style headers as HandleJumpInit; not started as a draft.
