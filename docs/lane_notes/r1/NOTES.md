# R1 notes (2026-11-01 night)

## 00199980 cHuman_Choke_NextFrame - STAGED (ck_clean.c -> pending/r1/mw38_00199980.c), MATCH
- From coordinator ck_trigger11.c (q3 draft + `if (0) { asm volatile { nop } }`, 11 lab).
- AEv tail: inline AEvRun_L into the block with function-scope pointers: decl `r, x, e1, e2, p1, p2, s2, sys`,
  then XInit, RateDef, s2=, sys=, `p1 = &e1; AEvInit_L(p1); p2 = &e2; AEvInit_L(p2);`, AddRequest(p1, p2),
  `e2.vtable = ..; cMessage_dtor(p2, 0); e1.vtable = ..; cMessage_dtor(p1, 0);` (11 -> 7; t3 grid of 192).
- Drop q3's `#pragma opt_common_subs off` (7 -> 0: retail shares the li a1,25 between compare and Prio arg).
- In mode ALL q3 workarounds were unnecessary: every opt_ pragma removed, plain name-copy loop (no
  .set reorder, no ckc_s/ckc_d copies), RandRange_L(D/2.0f, D) call sites. Unused helpers pruned (prune.py).

## 001E7F40 cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans - STAGED (df_match.c -> pending/r1/mw38_001E7F40.c), MATCH
- From p6l df_best.c (2). Already in mode (cVector copy ctor GCC `__asm__ volatile` lq/sq inlined in the body);
  dead trigger changes nothing; making the copy non-volatile leaves the mode (240).
- Fix: min helper with a C zero and NON-volatile asm: `float r = 0.0f; float aa = a; float bb = b; asm { min.s r, aa, bb }`
  puts retail's free-floating `mtc1 zero,$f21` in place (6, but andi chain x3), then IsPH returning `int` with an
  `unsigned char r` and `int isPlayerHuman` -> single andi -> 0 (125-variant type grid t6/; 8 combos match).
- No trigger needed in the staged file (the copy-ctor volatile asm keeps the mode).

## 0018A950 cHuman_HandleDeath - NOT matched, 21 (t/hd1.c = k8 pG.c + trigger, 8 barriers removed)
- Retail IS in mode. pG.c was already in mode WITHOUT any volatile asm: the 5 `asm { .set reorder }` barriers at
  b3/b9/b10/b12/b14 jointly put it there (dropping any one leaves the mode: 28-49; with the trigger each is
  unneeded). No single non-volatile asm triggers the mode; a combination does (unexplained; maybe a
  complexity limit). So some older "barrier" wins may really have been mode switches.
- With trigger: removed 8 `.set reorder` barriers (b3,b9-b15), still 21. All opt_ pragmas removable except the
  push-block `opt_common_subs off` (28 without).
- Tried in mode (no gain): TailC px forms (c1-c9, d1-d7, XInit2/3 e0-e5; retail has `move s0,s3` px copy of
  XInit's internal pointer plus a dead nop after `b` in RateF - both vanish together when we get px separate);
  InstNR `an` 4 forms x 7 decl positions x before/after ctor (56, best 21: hoist fixes schedule, rotates s-regs);
  P56 72 decl/assign/store orders (id-first: schedule right but id a0/pp v1 swapped, 22).
- Best: hd_best21.c (pG.c + trigger, barriers b3,b9-b15 dropped). Next idea: retail TailC needs px as a
  NON-coalesced copy of XInit's internal pointer (`move s0,s3` placed after the pair-4 stores and id andi);
  every form that derives px from XInit's return coalesces (s3) and also loses the dead nop after `b` in the
  following RateF, so the two are linked; find what blocks coalescing in mode.

## Mode probe on other cHuman drafts (trigger = dead `if (0) { asm volatile { nop } }`; novol = all asm volatile removed)
| draft | base | +trigger | novol (leave mode) | volatile in own body? |
| k8 pG.c HandleDeath | 21 | 21 | 21 (barrier combo keeps mode) | none; .set reorder combo |
| q2 hj_best16.c HandleJumpInit | 16 | 16 | 736 | yes (QCp*/Cp* copies inlined) |
| p2l hm2.c HandleMoveMessage<0> 0x1BB1D0 | 45 | 45 | 200 | yes (RQ*/VU0 GCC asm) |
| q1 hm1_best.c HandleMoveMessage<1> 0x1BC4B0 | 45 | 45 | 180 | yes |
| p2l v17.c Validate | 58 | 58 | 1016 | yes (V copy ctor, VU0 ops) |
| p6l df_best.c DetectFor | 2 | 2 | 240 | yes -> now MATCH |
- All six retail functions are in the mode; all drafts already were (helpers are inlined; syms.sh shows no local
  helper calls). Per-asm volatile removal with the trigger in place (pervol.py): no gains (HJ 16..100,
  HM 45..68, V 58..239); hm's empty `__asm__ volatile("" : : "r"(&m))` and HJ's QCpR/CpA/CpB become
  unnecessary-for-mode but give no change.
- HJ: copy at end of MsgCopy_L in 7 forms with the trigger (C __int128, GCC/MW volatile/non-volatile, pointers
  at top): 55-70, worse than 16.
- HM<0>: head statement order sweep (msg copy / edge / ladd / flor / AllFree, 120): best 45 (unchanged). Retail
  copies msg into s4 in the prologue; making it the first statement moves the copy but rotates colours (96).
- Validate: repeated per-block diff = the tagged V(r, short) return copy uses v1 where retail uses a1, which lets
  `addiu a1,sp,<tmp>` hoist; not solved.

## 001B1710 cHuman_NextFrame - not started (mode signs present, blocker)
- Signs: `sll v0,s0,3; addu a0,v0,s1` recomputed 3x in the particle loop (no CSE), `sw v0,828(sp); addiu v0,sp,828;
  lw v0,0(v0)` (no propagation), unreduced copy loops (sll/addu per iteration), dead nop after `b` (x3 plus after
  delay-filled b's). Probably mode.
- Blocker: calls SoftFloat_DoubleAdd 0x11C1A8 and SoftFloat_DoubleToFloat 0x11C928 as compiler helpers (after
  fptodp): a C match would leave UNDEF dpadd/dptofp (only fptodp is aliased in config/extra.ld). Coordinator
  would need `dpadd = 0x0011C1A8; dptofp = 0x0011C928;` aliases first. 3936 B, ~75 calls, 13 virtual.
