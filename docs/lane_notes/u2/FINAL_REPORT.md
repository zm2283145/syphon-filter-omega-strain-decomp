# U2 final report (2026-11-02)

Staged: build/pending/u2/mw38_0025CDC0.c - cGrenade_CalculateArcPoints 0x25CDC0 (1544 B), check_match MATCH,
no UNDEF, no DATA. Source = p5l arcpoints_best.c with the VU0 multiply helper's parameters swapped to
`MulT(const V* src, V* dst, float s)` (inline args are evaluated right to left, so &dst is created first), unused
helper variants removed. Lab 14 -> 3 (the 3 are lab masking artefacts).

Not matched (unchanged): XLib_DrawLensFlares 8 (retail has no extra nop/branch in the window: 1347 = 1347
instructions, so the approved idioms do not apply), cMan_ManDMA 9, cMachine_NextFrame 14 lab / 10 words,
XLib_Init 52. Details and every variant tried are in NOTES.md.

New rule: where retail's address/pointer setup order is wrong around an asm helper, swap the helper's parameter order
(destination pointer last, so it is evaluated first). This is the right-to-left rule applied to helper signatures, and
it fixed what r2 described as an "extra early vreg that emits no code".
