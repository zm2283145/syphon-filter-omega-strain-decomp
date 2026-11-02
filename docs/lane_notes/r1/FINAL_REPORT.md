# R1 final report (2026-11-01 night)

## Staged (2)
- build/pending/r1/mw38_00199980.c: cHuman_Choke_NextFrame 0x199980 (1448 B), MATCH (source ck_clean.c).
  Coordinator trigger draft (11 lines) -> 0: AEv tail inlined with function-scope e1/e2 pointers (p1 = &e1 ...
  passed to AddRequest and to cMessage_dtor; 192-variant grid) 11 -> 7; dropping q3's `opt_common_subs off` 7 -> 0.
  In the mode every q3 workaround was unnecessary: no opt_ pragmas at all, plain name-copy loop (no
  `.set reorder`, no pointer copies), `RandRange_L(D / 2.0f, D)` call sites. Unused helpers pruned. Keeps the
  commented `if (0) { asm volatile { nop } }` mode selector (needed: without it 130 lines).
- build/pending/r1/mw38_001E7F40.c: cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans 0x1E7F40
  (2072 B), MATCH (source df_match.c). p6l df_best.c (2) + min helper `float r = 0.0f; ... asm { min.s r, aa, bb }`
  (non-volatile, C zero) + IsPH returning int with an unsigned char flag and `int isPlayerHuman`. No trigger needed
  (the cVector copy-ctor volatile asm already selects the mode). Same asm unit as Transport_StartOfFrameUpdate but
  both boundaries are 16-byte aligned (next symbol 0x1E8760).

## Findings
- HandleDeath (k8 pG.c) is in the mode with NO volatile asm: five `asm { .set reorder }` barriers jointly switch it
  (removing any one leaves the mode). No single non-volatile asm does. Earlier "barrier" wins elsewhere may really
  be mode switches; with the trigger, 8 barriers become removable. Still 21 (hd_best21.c).
- HJ, HM<0>, HM<1>, Validate, DetectFor: retail is in the mode and the drafts already were (their volatile copy
  asm is inlined into the body; removing volatile costs 180-1016 lines). The trigger adds nothing there.
- cHuman_NextFrame: mode signs present, but retail uses the compiler's dpadd/dptofp helpers (0x11C1A8, 0x11C928);
  a match needs extra.ld aliases `dpadd`/`dptofp` (checked: MW emits exactly those UNDEF names). Not started.

Details, tried lists and next ideas: build/agents/R1/NOTES.md.
