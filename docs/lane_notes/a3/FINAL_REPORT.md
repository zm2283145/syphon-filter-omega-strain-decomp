# A3 final report (2026-11-02)

No matches; nothing staged. One large improvement.

| Function | Addr | Before | After | Draft |
|---|---|---|---|---|
| cFireObj_ctor_cPopulationR | 0x2625B0 | 21 words (k7 fo9.c) | **9 words**, exact size | build/agents/A3/fo_best9.c (alt fo_bar9.c, 9) |
| Monster_ctor | 0x405660 | 22 words | unchanged | k6 base_405660.c (= A3/mo0.c) |
| cVisionFxMan_DeactivateFx | 0x25F930 | 28 words | unchanged | k7 k_vf0.c |
| cAgentData_ctor | 0x336700 | 28 | unchanged | k7 ad_best28.c |
| GetCollisionDist | 0x22A8C0 | 28 | unchanged | k7 gcd_best28.c |
| CheckBulletCollisions | 0x22BA30 | 29 | not attempted | k7 bc2.c |

## FireObj
The copy constructor stores through `this` (`asm volatile { lq t, 0(ps); sq t, 0(this) }`) and ScaleR calls
`ScaleV(&r, &a, s)` directly; ScaleV keeps a `pa = a` local but stores through its parameter `r`. This is the Z2 read-form
rule: it fixed the result/copy-dest colours in both scale blocks. What is left: ScaleV's operand pointer gets v0, late
(retail a2, early). A barrier after `const cVector* q = &a;` in ScaleR fixes that but moves the copy temp to v0 (fo_bar9.c).

## Findings
- Read forms, applied per helper and found with an exhaustive template sweep (sweep.py, about 0.07 s per variant), cut FireObj 26 -> 9 lab lines.
  The same forms do nothing for GetCollisionDist (its v0/v1 swap is insensitive to everything tried).
- MW materialises a u64 constant converted to u128 as a compiler-generated `pcpyld x,zero,x`; a non-constant conversion
  emits nothing. The scheduler fills after a compiler pcpyld but not after an asm pcpyld (Monster_ctor).
- cAgentData_ctor: retail's inner loop looks less-optimised (no SR, per-iteration sp addresses, `bnez; nop`), but the
  rest is optimised, so the function-level trigger is wrong (128 lines).
Details and every dead end: NOTES.md.
