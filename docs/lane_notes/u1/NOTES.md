# U1 notes (2026-11-02)

Tools: grid.py (copy of R4's: base.c outdir FUNC lo hi variants.py), rx.py (HM s-reg extractor: a/msg/edge/ladd/flor
colours of each draft), regs.sh, mkmember.py, m/ (micro tests, run with build/agents/T1/mc.sh). Variant files
hmv*.py, hjv*.py, hdv*.py, nfv*.py; outputs in hm/, hj/, hd/, nf/.

## 001BB1D0 / 001BC4B0 cHuman_HandleMoveMessage <0>/<1> - MATCH, both staged
- Files: hm0_match.c -> pending/u1/mw38_001BB1D0.c, hm1_match.c -> pending/u1/mw38_001BC4B0.c (from p2l hm2.c / q1 hm1_best.c, 45 lab).
- KEY (colour order): retail colours a s0, ladd s1, edge s2, flor s3, msg s4 (msg coloured LAST). The draft's msg was
  coloured early because ONE site passed `a` into an inline together with a msg->Trans() temporary:
  `Translate(a, msg->Trans())` (mode-3 block). Found by toggling each of the 9 msg->Trans() uses to msg->row3
  (hmv12, 512 variants): only that site flips the whole colour set. Fix: pass the context pointer instead of the actor:
  `TrA(&a->mc, msg->Trans())` with `TrA(MCtx* mc, const V& d) { const V& dd = d; MCtx* m = mc; m->comp->Translate(dd); UpdateBBox(m); UpdateCOM(m); }`
  (the named dd/m copies keep mc in s1 as retail; without them mc is folded to 11896(s0); `MCtx* m = mc` alone breaks the colours).
- Then: msg used as the parameter directly (no `Msg* msg = msg0` copy), anchors declared flor, edge, ladd (45 -> 19 -> ...).
- Free2 without the named `bool f` (removes the extra andi and nop: 19 -> 17).
- delta copy `{ const void* s = &D_004E1D90; V* dp = &delta; RQ3(dp, s); }` (source address first: 17 -> 15).
- mode-4 site `Rotate(a, flor, Q(m, 0))` with a tagged `Q(const M44& m, short) { MtxToQuat(&m, this); }` (this before &m);
  the IsRot site keeps the untagged `pm`-first ctor (changing it breaks 0x5B0/0xC2C). 15 -> MATCH.
- <1> = <0> + the tail (q1 notes), same edits: MATCH. The dead `if (0) Send(...)` lines in <0> are required (frame slots).
- General lesson: when a set of s-registers is rotated, look for ONE inline call that receives the variable (or a sibling)
  together with a temporary; toggling each use site individually (2^n grid) finds it quickly.

## 001914C0 cHuman_HandleJumpInit
- best draft: unchanged (q2 hj_best16.c), lab 16.
- New facts:
  * GCC `__asm__ volatile` lq/sq copy LAST with "memory" clobber (hj/vm.c, 66): gives retail's separate pc register
    and recomputed `addiu a0,sp,1088` for the call, unfolded t1/t2-style pointers and v1 data reg, BUT the call args
    stay after the asm, so RA gives the field temps a0..a3 (retail t0/a3/v1 with a0-a2 left free).
  * Non-volatile GCC asm with "memory" (h5): folded `lq v1,48(s1)` and pc coalesced with a0 (like the C copy).
  * An EMPTY asm string (`__asm__ volatile("" ::: "memory")`, or with an "=r" output) is ignored by MW: no barrier,
    no mode effect (micro m/m1.c f2, m2.c f1/f2; hjv7: all 31 = unchanged).
  * The t1 block-local trigger (volatile asm with an output, real instruction) unfolds C struct copies done with
    lwc1/swc1 but NOT __int128 C copies (`lq v0,48(a0)` stays folded; micro m3/m4). memcpy is a real call (m5).
  * Copy and f20=4 inside the call's first argument (PrepP_L/PrepR_L, right-to-left args): no change (h4: 16-25).
  * lq as GCC volatile with output + C-level store / non-volatile sq, every pointer form (h6, 72 variants): 58+.

## 0018A950 cHuman_HandleDeath
- best draft: unchanged (r3 hd_best6.c), lab 6.
- More tried (after the HM finding): GI/GAC/GD wrapper depths x 4 hoisted an forms (hdv5: best 10 = GI fixed, an/GAC
  swapped), InstNR signatures without sel/ps, reversed, an/sys params (hdv6: 10-18), AddRequest wrapped in an inline
  with 6 parameter orders (hdv8: 18-24), temp-then-copy an (hdv7: 11), reference locals (hdv9: 6-32).
- Note: even a non-coalesced `an = &a->sys.anim` defined before the y ctor is coloured s0, so it is not the An_L inline.
- Tried: `Act_L* aa = a` local-pointer copy (d1_A, 6 = no change); Sys_L* param with copy (d1_B, 7); an as
  inline param at 3 positions (d1_C/d3: 10-11; hoisted, rotated colours); right-to-left wrapper
  `an = G4_L(An_L(a), YI_L(&y), &out, ps)` (an evaluated before the y ctor by arg order; d2: 7, not hoisted);
  replacing each of the 6 later `an` uses by An_L(a)/&a->sys.anim (d4, 128 variants: 11); pragma sweep at the
  function push (no effect at all).
- Model: when `an` is defined before the y ctor, MW colours it first (s0) and GAC/GI after it (s1/s3); retail colours
  GAC (s0), GI (s1) first and an last (s3).

## 001B1710 cHuman_NextFrame
- best draft: unchanged (r4 nf_best8.c), lab 8.
- Tried: vcall through an explicit function pointer (n1: jalr v0, not t9), member-pointer, reference wrapper; local
  pointer copies of the controller in IsHC/IsHuman2 (n2, 11 forms: no change); 2^7 toggles of other inline sites in
  the particle loop (n3: all 8 or 11, the two clusters never move).
- Retail evidence: the same IsHuman sequence at 0x1B19C4 (outside the loop) and in HandleJumpInit uses a0 directly, and
  the Dying test after the loop (0x1B2178) uses a0; only the loop-body copies avoid a0.
