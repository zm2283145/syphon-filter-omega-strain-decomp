# Y3 final report (2026-11-02)

## Staged
- cMan_GetGunBarrelMatrix 0x385240 (236 B): MATCH, build/pending/y3/mw38_00385240.c (draft build/agents/Y3/gb/f2.c).
  It is the only function in asm unit 0x285240..0x285330.

## Unchanged near misses (best drafts are still the old ones)
| Function | Lab lines | Draft |
|---|---|---|
| XLib_DisplayLastFrame 0x37B5C0 | 7 | docs/lane_notes/k3/drafts/b_37B5C0.c |
| cHumanIkRoutine_PositionLeg 0x1D1140 | 9 (8 words) | docs/lane_notes/k4/drafts/k1.c |
| cHumanIkRoutine_AimHeadIndependently 0x1D0780 | 9 | docs/lane_notes/k4/drafts/h18.c |
| cMemMan_Init_int_uint_uint 0x36B3B0 | 7 | docs/lane_notes/k3/drafts/b_36B3B0.c |
| cSplinedMotion_QuaternionLERP_1_UpdateVelocity 0x180580 | 17 | docs/lane_notes/k6/drafts/sq_a.c |

Everything tried is in build/agents/Y3/NOTES.md (grids and scripts under Y3/xl, pl, ah, mm, sq).

## New technique
- **Float locals declared in one order and read in another.** In the matrix-row setters, `float y, z, w, x; w = v.w; z = v.z; y = v.y; x = v.x;`
  gives retail's FP colours and load order together. Declaration order sets the colouring order, here x, w, z, y, with greedy lowest-free.
  Assignment order sets which loads the scheduler hoists. A 576-variant declaration x assignment grid on the other row found the same pair,
  and only that pair gives 0. It took GunBarrel from 6 to 0. Try it on any float colour rotation where reordering the statements alone
  fixes the load order but swaps colours.
- **Colour order versus interference (DisplayLastFrame).** To tell them apart, replace the competing value with something that no longer
  interferes, for example `dw = kMagH*7`. If the colours do not move, the cause is colouring order.
