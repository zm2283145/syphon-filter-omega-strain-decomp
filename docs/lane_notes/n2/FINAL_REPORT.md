# N2 final report (session 2026-11-01, near-miss lane: human / IK / game code)

Note: this file overwrote, by mistake, the older r113 N2 report. Its first part is restored in
FINAL_REPORT_r113_partial.md; the rest is lost. That lane's match copies are still in build/agents/N2/*.c.

## Staged (1)
- build/pending/n2/mw38_0013FF40.c  cWeapon_FireIfReady (since collected by the coordinator into build/integrated/r216_batch022857/). check_match: MATCH, no UNDEF, no DATA lines.
  Started from k8 fw50.c (7 words: s0/s1 swap of `v = slot->id` and `p = &ev` in the
  out-of-ammo message). Fix: write the message as an inline C++ class whose constructor
  takes the `Slot*` and loads the id inside the constructor after `OutMsg* t = this;`.
  The destructor is `__declspec(weak) __declspec(DROPDTOR)`, so no out-of-line copy is emitted.
  A constructor taking `int` (by value or const&), temporaries, and pointer locals all kept the swap.

## Improved near misses (drafts in build/agents/N2/work/, details in NOTES.md)
| Function | Before | Now | Draft | What changed / what remains |
|---|---|---|---|---|
| 00230DE0 Global_Shatter | 12 | 5 | gs1.c | Sound block as plain aligned char arrays + explicit ctor/dtor calls (fixes &msg CSE and the extra nop). Remaining: a0/v1 swap of the two copy destinations at 0x28C. |
| 001A1590 cHuman_Fall | 19 (+5 .bss DATA lines, out-of-line dtor) | 5, clean | fc1.c | Function statics turned into extern D_ symbols with explicit guard bytes (same code, no DATA). cMsgT dtor weak/DROPDTOR. AddRequest call goes through a pass-through inline wrapper with the float args as params, which fixes the float-arg schedule. Remaining: the arg-move schedule before the jal (t0 vs t2 in the delay slot). |
| 00290610 cSkeleton_ResetBBoxContributors | 58 + size | 20, exact size (17 variants exist: rb17.c, mut/rb.best.c) | rb_best.c (or rbE_q3.c, pure MW asm) | Loop 1: pass the zero as a float variable declared just before the loop; MW then hoists `mtc1 zero` and keeps `swc1` like retail. Loop 2: a typed one-line copy (MW asm, or GCC lq + MW sq) gives retail's unfolded addresses and separate &offv. Remaining: retail loads `*pd` early and unfolded; ours loads it after the copy, and reading it earlier folds it. |

## Unchanged (probed, negatives in NOTES.md)
PositionLeg 8, AimHeadIndependently 9, cAimComponent_NextFrame 11 (config address 0x1DD6A0),
SKL_CompressSKL 16, QuaternionLERP_1_UpdateVelocity 17, Monster_ctor 21, cFireObj_ctor 21,
cHuman_HandleDeath 22, cVisionFxMan_DeactivateFx 25, GetCollisionDist (20 by check_match),
cAgentData_ctor 28, CheckBulletCollisions 29 (its draft has stale callee names; the correct
symbol names are listed in NOTES.md).

## Findings worth keeping
- Wrapping a C++ message in an inline class whose constructor takes the *source pointer* and
  reads the field inside the constructor fixed the s0/s1 swap that resisted every local-order trick.
- A float constant stored inside a loop compiles to `sw zero` once any GCC-style asm is
  present in the function. A float *variable* declared before the loop keeps `mtc1` (hoisted)
  plus `swc1`. Micro-tested.
- A pass-through `static inline` wrapper around an extern call, taking every argument as a
  parameter, changes the argument-setup schedule (it fixed Fall's float args).
- Micro-tests on MW colouring: of two overlapping temporaries, the one defined later gets the
  lower register (v0 when the function calls out, then v1, a0, a1...). Order inside a MW asm
  block does not matter; the order of the GCC asm operand list does. This is the mechanism
  behind the VU0 copy-chain swaps, but no source form found reproduces retail's order.
- Every remaining near miss here is register colouring or scheduling inside the VU0 temp chains,
  plus three structural blockers: Fall's arg schedule, ResetBBox's `*pd` load, and AimComponent's
  `lb; ext` at the compare sites.

## Tools (build/agents/N2/bin/)
nd.py (draft vs retail diff with relocation masking), od.py (our disassembly), rdis.sh (retail
disassembly by address), cm.sh (check_match wrapper), and search scripts gssearch.py,
gcdsearch.py, rbsearch.py, ahsearch.py/plsearch.py (copy-idiom sweeps), fperm.py,
fsearch*.py and fdummy.py (Fall).

mutate.py, 60 min each: Fall stayed at 5 (8,955 variants); ResetBBox went 20 -> 17 (9,581 variants).
