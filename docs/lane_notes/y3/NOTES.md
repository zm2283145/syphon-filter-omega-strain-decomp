# Y3 lane notes (2026-11-02)

## cMan_GetGunBarrelMatrix 00385240 - MATCH (staged build/pending/y3/mw38_00385240.c, draft Y3/gb/f2.c)
- From k3 t_g5.c (lab 6). Residual was FP colour of rows 0 and 2.
- Colour analysis: greedy lowest-free colouring; retail colours each row in the order x, w, z, y while the loads of w, z are hoisted.
- Lever: "declare in one order, assign in another": `float y, z, w, x; w = v.w; z = v.z; y = v.y; x = v.x;` in SetZAxis
  (6 -> 4), then a 576-variant grid (decl order x assign order) on row 0: only the same yzwx/wzyx pair gives 0 (grid.py).
- Row 0 as a SetXAxis inline with that body also matches; uniform SetAxis(i, v) for all 3 rows does not (row 1 needs SetRow/Set4 pointer form).

## XLib_DisplayLastFrame 0037B5C0 - 7 lab lines (k3 b_37B5C0.c unchanged), work in Y3/xl/
- Residual analysed: colouring order, dw is coloured before dx (dw takes t0 once width dies at the mult, dx t1). Retail colours dx first.
- dw is coloured first even when dx comes first in the source, when dw reads depth or dh instead of width, and with any block declaration order
  (24x2 grid: 7 or 10; dh,dw,dx,dy order gives dh t0 / dw a3).
- No change (7): block moved into an inline SetDisp2(o, ...) with all 120 parameter orders; pointer-taking setter with destination
  first/last/wrapped; pointer local for the register; u_long64 result local.
- Worse: less-optimised trigger at function top or in the block (70); local-vs-inline-argument grid of dh/dw/dx/dy with all orders (65 variants, best 10).

## cHumanIkRoutine_PositionLeg 001D1140 - 9 lab lines / 8 words (k4 k1.c unchanged), work in Y3/pl/
- Cluster 1 (0x12c, Scale_ pv/pr order): Scale_ through a helper MulXTo with all 6 parameter orders (destination last etc.), with and
  without the dead `u_long128 z`: 20-22 (r's slot moves 416 -> 432 whatever the order).
- Cluster 2 (0x2fc, Rot() temp a0 instead of v0): QMulTo parameter order (6): 9 or 27; site-1 PreMultiplyB with reversed-argument
  multiply helper (QMulRev ref 69 / by value 26, the latter swaps slots 320/336), pointer-to-q forms 9; Rot accessor depth/forms
  (wrapper 1-2 deep, pointer, direct member, const-cast) x PreMultiply forms (same / wrapper 31 / no p 9 / p without reload 23).

## cHumanIkRoutine_AimHeadIndependently 001D0780 - 9 lab lines (k4 h18.c unchanged), work in Y3/ah/
- Residual: else-if(notId) branch, the three chained copy values take v1 (retail a1); rot pointer (464) then a1 (retail v1).
- V4B copy-ctor forms (11): MW asm volatile / MW asm / GCC asm volatile / GCC asm / C via local / lq-asm+C sq / C lq+sq-asm: 12;
  ps declared before pd 9; dead less-optimised trigger in the ctor 9; real `asm volatile { nop }` 11 (values still v1).
- rot pointer local at the top of the branch / after o-site / used by both sites: 17-32; s->cur pointer local before or after o-site: 16-18.

## cMemMan_Init_int_uint_uint 0036B3B0 - 7 lab lines (k3 b_36B3B0.c unchanged), work in Y3/mm/
- Residual: first temp of the pool*0x818 shift/add chain is v1 (coalesced with the chain); retail gives it v0 and then schedules lui a2 before lui v0.
- Grid (60): pool ternary / if / new local x 5 bin-address forms (index, plus, reversed index, BinAt(i) inline, BinAtP(t,i))
  x size-check before/after pool x one extra wrapper level: best 7 (ternary, size check after pool; wrapper always worse).
- Reversed byte-offset sums (`pool*sizeof + (char*)D`, unsigned forms): identical (7).
- (late) 3^6 grid over the six address arguments of nIk_TwoLimbIK (accessor / one-deeper wrapper / direct member): wrappers change
  nothing (9), any direct member is far worse (84-218). Cluster 3 (s3/s8 swap of sideHip Pos vs hip Rot) unchanged.

## cSplinedMotion_QuaternionLERP_1_UpdateVelocity 00180580 - 17 lab lines (k6 sq_a.c unchanged), work in Y3/sq/
- Per-site pointer-taking QMulTo helpers (u3 technique) at the Mul site and the projectedRot site, all 6 parameter orders, plain and
  one wrapper deeper (169): best 17 (site-2 helper 18: &m->rot moves to a3 and r to a2, closer to retail's v1/a1/a2, but the copy
  chain still takes v1 first).
- Same x 8 V copy-ctor forms (GCC =r / =&r / swapped operands / MW asm / "+r" / pointer locals / split lq+sq): copy form has no effect.
- Mul forms (pa first, swapped params with swapped call, ref-to-pointer inner helper, pointer param, QMul(*pa, b)): 17-63.
- XLib_DisplayLastFrame (late): full 24x24 declaration-order x assignment-order grid of dh/dw/dx/dy (576): best 7; function-scope
  declarations at 6 positions x 24 orders: best 7. dw is coloured before dx even when dw = kMagH*7 (no width use), so it is colour
  order, not interference with width.
- cMemMan_Init (late): AllocGuard as a C++ temporary `(AllocGuard(), MemAllocate(...))` 7; guarded inline wrappers 58.
