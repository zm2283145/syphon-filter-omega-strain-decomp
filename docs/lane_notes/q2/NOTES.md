# Q2 notes (2026-11-01 evening)

Tools: dd.py (side-by-side mine|retail for an offset range), gsgrid.py + g*.py (Global_Shatter site grids),
micro/run.py + micro/full.py (DetectFor rate block: micro and full-file variants).

## 00230DE0 Global_Shatter - STAGED (gs_match.c -> pending/q2/mw38_00230DE0.c), MATCH
- Fix: `(a - b).GetNormalizedR()` with
  `V NormalizedInto(V& r) const { r = *this; V* p = &r; p->Normalize(); return *p; }`
  `V GetNormalizedR() const { V r; return NormalizedInto(r); }`
- Why: the local r must be declared at the depth-1 level (slot 512 above the later temps), but the copy and the
  return-by-value must happen one inline level deeper; that flips the creation order of the two copy dst
  pointers (dst1 a0, dst2 v1). Making the whole GetNormalized one level deeper fixed the colours but moved r's
  slot below the sub temp (8 words); deferring only the copy (CI helper) did nothing.

## 001E7F40 DetectFor - still 2 words (df0.c = p6l df_best.c)
- Retail's first zero is a free-scheduled instruction. Tried: GCC-asm zero (volatile/non-volatile, at 6 positions in
  the helper, separate Z at all P/K/Z permutations): GCC asm makes the block unscheduled (double andi);
  register float, non-volatile reorder asm, directive orders (.set noreorder after min.s), labels/goto/empty asm
  after the first min, dead-use instructions (mov.s t,r is removed together with the zero; mfc1 keeps the zero
  but schedules it directly before the asm). A kept C zero is always scheduled right before the asm block.

## 001A1590 cHuman_Fall - STAGED (fc_match.c -> pending/q2/mw38_001A1590.c), MATCH
- From n2 fc1.c (5 words). Two changes: (1) the two cSkaAnimEndedMessage args are `const cMsg&` (pass `cMsgT()`
  temporaries directly; the mangled proto name has RC20cSkaAnimEndedMessage) -> t1/t2 right (grid f3: 64 ptr/ref
  combos, m2 ref is the key); (2) the wrapper takes the blend pointer and builds the playback-group arg as a named
  local: `AddR(void* s, int* b, ...) { void* pg = b + 1; AddRequest(s, b[0], mode, cf, pg, m1, m2, x, f0, f1); }`
  -> t0 first like retail (pg as call expression / ref / outer named local: all wrong or size change).

## 00167C40 cMachine_NextFrame - 10 gd lines / 10 check_match words (mn_best10.c; was n19_d.c 10 gd / 22 cm words)
- Quit site 1 (QuitBoxA) now has retail's exact schedule (fe `lui at` before the GetQuitMessage jalr, `lw` in its
  delay slot) AND retail's time/title/resetID colours (time s3, resetID s1, title s2) with an inline whose params
  put msg before fe: `PQP(char* title, char* msg, int resetID, FrontEnd* fe)` called `PQP(title, GetQuitMessage(),
  resetID, D_004FFC04)` (args are evaluated right to left, so fe is loaded first). Left at this site: fe s4 / msg s5
  (retail s5 / s4), immune to 48 param orders, FE()/QM() accessor depths, wrapper depths (m8, m12), named fe/msg
  locals (those fix the schedule too but drop fe below time: m2/m3/m4), const-qualified loads.
- Viewport rect a1 vs a3 (6 lines) untouched.

## 001914C0 cHuman_HandleJumpInit (4608 B) - lab 22 -> 16 (hj_best16.c, from Q1/P8L hj_best.c)
- Part (B) (X3/X4 = Blend_L/BlendS_L AddRequest argument order) SOLVED with the Fall recipe: extern takes the two
  messages as `const AMsg_L&` (Play0_L passes `*(AMsg_L*)&e1/e2`), and both Blend sites call
  `AddR_L(void* s, int* b, signed char mode, void* r, const AMsg_L& m1, const AMsg_L& m2, void* x, float f0, float f1)
  { void* pg = b + 1; cSkaRequestStream_AddRequest(s, b[0], mode, r, pg, m1, m2, x, f0, f1); }` passing the
  message OBJECTS e1/e2 (passing `*p1` keeps t1 early; direct call without the wrapper is worse: 58).
- Left (16 lab lines): only part (A), the case-21 msg->vec copy block (see Q1 NOTES).

## 0025CDC0 cGrenade_CalculateArcPoints - unchanged (11 gd lines, ap0.c = p5l best)
- Deferred Cross (`CrX(a,b) { V r; return CrI(r, a, b); }`, CrI does the asm and returns by value) fixes the dead
  paddub position and the Cross-copy src register v0, but the copy data register becomes v0 and the multiply's
  global address a0/a1 (gd 17-19). Grids: Cross forms (a1), mul/add forms (a2, a5), tagged return-copy bodies
  incl. GCC earlyclobber (a3, a6), assignment helpers (a4): nothing below 11 gd.
- (A) probes (h3/h4, compiled only, asm/ was absent during the coordinator HOLD): copy moved to the END of
  MsgCopy_L. Volatile forms (MW/GCC, pointers at top or in a block, split lq/sq volatility) keep unfolded pointers
  but the QueueMessage args stay after the copy (field temps a0/a2 instead of t0/t3). Non-volatile `asm { lq } asm
  { sq }` (h4 mn2) gives retail's whole block shape (args hoisted, t0 field temp, vt order) except the two known
  problems: base coalesced with the call's a0 (retail t3) and folded `lq v1,48(s1)/sq v1,48(a0)` (retail
  addiu t1/t2 + 0 offsets). Note hj_best16's copy-first form already has retail's t1/t2/t3 pointer registers.

## 001A1C80 cHuman_GrabLedge (2032 B, fresh; unit now split after Fall) - draft gl3.c, gd 215 lines, size -8
- Built from the HJ draft helpers (Prio_L, XInit_L/Set5_L/Set4_L/XDtor_L, NAME_COPY_LEN, Play_L) + human_134's
  callback idiom (AllocGuard + InitEv, nCallback_SetCallback) + human_22's AnimPriority_Helper1 "find top" loop
  (on self+0x3310: top at +0x28, bits at +0x2C, from bit 12) + Global_Shatter's raw sound block.
  Structure (both request blocks, bit ops, sound, callback) lines up with retail.
- Open: (1) mw38 delay-slot policy: retail never retargets branches (`b; nop`), ours fills from the target
  (ternaries, C++ new, removing the asm blocks, pragmas: no flip); (2) two extra s-regs (X pairs/tail addresses
  CSE'd into s1/s2 and reused by XDtor; retail recomputes sp+const) -> frame +32 and every slot +32;
  (3) RandRange: retail keeps n=21 as an int in s1 across Libc_Rand and converts at run time, ours folds to
  21.0f (inline depth, I2F helpers: no change); (4) name-copy loop shape (retail indexed `addu v0,v1,a2`, ours
  pointer-increment with sign extension); (5) flag test needs an `unsigned char` IsSet inline (gives sltu).
