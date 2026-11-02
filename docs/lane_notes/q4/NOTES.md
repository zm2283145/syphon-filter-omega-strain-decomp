# Q4 notes (2026-11-01 night)

Tools: l.sh (lab diff: l.sh file FUNC START END [-v] [-n]), var.py (literal substitutions: var.py in out old new ...).

## 001A0B30 cHuman_Land - STAGED (ld_match.c -> pending/q4/mw38_001A0B30.c), MATCH
- From n5 ld3.c (209 lab). Steps (lab -n diff): drop n5's opt pragmas + Fall recipe (const cMsg&, AddR with
  `pg = b + 1`) 234 -> any volatile asm in the function 52 (KEY: retail Land is compiled in MW's less-optimised
  mode: un-strength-reduced Init loops, cAnimCheckpoints ctor `this` kept in s2 + `move s3,s2`, n kept as int)
  -> RandRange(70,100) with `int r = Libc_Rand(); F2I(...)` and asm cvt.w.s F2I 41 -> `if (0) { <third request
  block> }` reproduces BOTH frame holes (in the less-optimised mode the dead block's slots survive; in normal
  mode they are freed, which is what n5 saw) -> else-branch cSkaAnimCheckpoints/cSkaCrossFadeDuration as
  temporaries (`cSkaSystem_PlayAnimation(as, blend, 3, cCfd().Ctor(Default(*as)), &cCp3())`) puts them below
  the messages: all sp offsets right (38) -> the volatile asm moved into the dead block (F2I non-volatile so
  the AllocGuard lbu schedules across cvt.w.s) 33 -> declaration order for colours: else `as` before `blend`,
  block 2 `ac` before `blend`, block 1 `char* ac; int* blend;` declared before pcp and assigned late (10)
  -> `inWater` before `t2 = g_DefaultMotionTransition` (6) -> IsDeadOrDying `unsigned char r; s = ...; r = 1;` (0).
- General lesson: a volatile asm (MW `asm volatile {}` or GCC `__asm__ volatile`) placed inside an `if (0)`
  block emits nothing but still switches the whole function to the less-optimised mode, and dead blocks
  keep their stack slots in that mode. Non-volatile asm (MW or GCC) does not switch the mode.

## 001A1C80 cHuman_GrabLedge - STAGED (gl_match.c -> pending/q4/mw38_001A1C80.c), MATCH
- Rewritten from scratch on the Land source (not on gl3.c): same mode trigger (`if (0) { asm volatile { nop } }`,
  no holes here) -> 186 -> 53 lab. Then: inline Play(sys, node, mode, cf, cp) { if (node) AddRequest(
  func_0018C6A0(sys), node, mode, cf, nSka_GetPlaybackGroupId(node), cAnimEndedMsgT(), cAnimEndedMsgT(), cp,
  -1, 0); } with nSka_GetPlaybackGroupId declared as RETURNING the struct (hidden a0 = result slot, a1 = node):
  the by-value call result is deferred, giving retail's order msg ctor, msg ctor, func_0018C6A0, GetPlaybackGroupId
  (39); `cAnimCheckpoints* pcp;` declared before `cSkaSys* sys = &self->sys;` (pcp s2, sys s1) (4);
  the 48-byte name declared first in the block and filled with Init() (slot above cf/cp) (0).
- Q2's open points (b;nop branches, extra s-regs, RandRange int n, loop shape) were all the less-optimised mode.

## 001914C0 cHuman_HandleJumpInit - unchanged (Q2 hj_best16.c, 16 lab)
- Facts added (copy at the end of MsgCopy_L, with Q1's `.set reorder` barrier): MW folds `addiu rX,rB,48;
  lq q,0(rX)` into `lq q,48(rB)` for every non-volatile form, including GCC `__asm__` with "r" operands,
  pointers declared at the top of MsgCopy_L, `(char*)p + 0` pointers, and even explicit non-volatile asm
  `addiu` instructions (hjr_*.c, hjx_*.c, hjq_*.c: all 31). Pragma sweep (common_subs, propagation,
  lifetimes, dead_code, loop_invariants, peephole, strength_reduction...) on that variant: none helps.
- Volatile copy last + call arguments as named locals defined before the copy (hjy*.c): `int qz = 0` before
  the copy makes a2 live early and moves pc off a0 (pc t0 instead of retail t3) but `self`/`&copy` copies are
  coalesced (58-60). Copy + f20=4 inside the call's argument expression (Prep_L pointer/reference, hjp*.c): 58.
- Reading of retail: the args (li v0,4 / a0 / a1 / a2) can be hoisted post-RA if RA keeps a0-a2 free; retail
  RA did (pc t3, field temp t0, pointers t1/t2), ours puts the copy in a0-a3. The missing piece is still an
  RA choice, not the copy idiom.
- Also tried: inline Send wrapper taking (&copy, self, 0) as params before the copy body (hjs*.c): params are
  propagated, 58. Next idea: find what makes MW's RA skip a0-a2 for the copy temporaries (maybe a call-arg
  preference that only exists when the args are *expressions* evaluated before the copy in the IR, e.g. a
  constructor-call argument list), or test the dead-block mode trigger in place of the live QCp1_L volatile
  copies to see whether HJ's live volatile asm is itself what changes RA order.
