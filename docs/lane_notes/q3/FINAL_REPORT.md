# Q3 final report (2026-11-01 evening)

## Staged
- GuiEquipmentSetup_ctor 0x2A47E0 (3004 B): build/pending/q3/mw38_002A47E0.c. check_match MATCH, no UNDEF and
  no DATA lines. Its asm unit (asm/1A47E0.s) holds only this function.
  Built from the matched sibling GuiScoresEquip_ctor (0x35D430). Went 221 -> 0 gd lines in about 1.5 h.
  The keys were:
  - fx and msg declared in the main block;
  - opt_loop_invariants left on;
  - FindSex called before SortParts;
  - the two rotation copies split into separate helpers, with only the light_rot copy zero-initialising its
    quad temp (gives retail's single paddub in t6).

## Improved near misses
- cHuman_Choke_NextFrame 0x199980: 116 -> 65 gd lines (Q3/ck8.c).
  - RandRange is solved with a runtime 2^31 local and opt_common_subs off.
  - The string-copy loop is solved.
  - The first-block stack slots are fixed.
  - Left: `this` s0/s1 colouring, the Recip_L join nops and delay-slot fill, and the AEvRun tail.

## No progress (dead ends logged in NOTES.md)
- cInterfaceModel_Render 0x3ED2E0: 39. The FPR colouring of the byte->float conversions did not move under any
  form or pragma tried.
- SphereSweptRay 0x3BDA00: 25. Grids over outer-transform and post-loop forms found nothing better.

## Lessons
- Before rebuilding a big function, check whether a matched sibling exists: grep src/ for its distinctive callees.
  GuiScoresEquip_ctor gave most of GuiEquipmentSetup_ctor.
- When a quadword temp's register or a paddub's position is off, split shared copy helpers per site and try
  the zero-init on one site at a time.
- `opt_common_subs off` stops constant hoisting into callee-saved FPRs, but it also loses loop-invariant
  hoisting, so hoist loop bases by hand with pointer locals.
