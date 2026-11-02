# T2 final report - ActorPhys_RunResponse 0x1E2180 (12016 B; ends 0x1E5070)

No match; nothing staged. Best draft is build/agents/T2/ar_best.c (= t20.c). Lab diff (P4L lab.py) went from
463 to 371; with sp masked it went from 222 to 116. The frame is still 0x14D0, all 333 call targets match retail,
and the length is 3002 against retail's 3004.

Code changes that gained (full table in NOTES.md):
- floor-force block: GetZv_L(*ground);
- hasSum as a plain bool expression;
- argument evaluation order at 7 call sites (local-pointer copies, tagged MXc ctor, reordered LerpAndNormalize
  prototype);
- Norm3_L and VAdd_L as GCC `__asm__ volatile` (CSE barrier);
- AV(v2F0) = GetTransformed(...);
- NodePos decl order;
- Cp3_L for the three slope copies;
- plain-expression slope booleans;
- named 0.2f in v1;
- Remap_L decl order;
- p->f370 passed directly to both probe calls.

Rules found:
1. MW evaluates inline call arguments right to left.
2. A GCC volatile asm with a memory clobber stops CSE; an MW `asm {}` block does not.
3. Copying an argument into a local pointer variable moves its set-up earlier.

Still open (see NOTES.md):
- the temp-region slots (about 255 sp-only lines);
- the m50 / VV(0,0,h,0) order at 0x16E8;
- colour swaps at about 10 sites;
- no jump threading at 0x2C4C;
- the Remap 0.0f copy.
