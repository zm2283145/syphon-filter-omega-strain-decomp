# R2 notes (2026-11-01 evening) - less-optimised mode survey

Tools (build/agents/R2/): l.py (lab by name: `l.py draft FUNC [-v]`), trig.py (insert the `if (0) { asm volatile { nop } }`
trigger at the top of FUNC), var.py/v.sh (literal-substitution variants + score), volsweep.py (strip each asm volatile
one at a time, trigger kept), tools/cm_dbg.py (check_match copy that prints the data layout on a placement failure).

## Mode survey (lab diff; NV = every asm made non-volatile; T = trigger added at top of the target)
| Function | base | base+T | NV (mode off) | NV+T (mode on, asm non-volatile) | verdict |
|---|---|---|---|---|---|
| XLib_DrawLensFlares | 8 | 8 | 1188 | 84 | draft already in mode; retail in mode |
| cMan_ManDMA | 9 | 9 | 955 | 9 | in mode; retail in mode (div asm only volatile) |
| cMachine_NextFrame | 14 | 14 | 161 | 31 | in mode; retail in mode |
| cGrenade_CalculateArcPoints | 14 | 14 | 385 | 159 | in mode; retail in mode |
| SphereSweptRay...MovementOfCollidingObjects | 23 | 23 | 160 | 140 | in mode; retail in mode |
| cInterfaceModel_Render | 34 | 34 | 272 | 91 | in mode; retail in mode |
| PlayerInput_Update | 35 | 35 | 3540 | 398 | in mode; retail in mode |
| cScriptInterpreter_execute | 45 | 38 | - | - | draft NOT in mode (no asm volatile); retail IS -> MATCHED |
- Reading: for the seven asm-heavy drafts base+T == base, i.e. the inlined volatile asm already puts the target body in
  the mode. NV vs NV+T (same asm, only the mode differs) is always far worse without the mode, so retail was compiled in
  the mode for all of them. The leftover diffs are NOT a wrong-mode effect; they must be closed inside the mode.
- NV+T > base everywhere except ManDMA: the asm blocks themselves also need to stay volatile (non-volatile MW/GCC asm is
  folded/scheduled like C or deleted when it has no outputs), so per-asm-site volatility is a separate knob.

## 003DDFC0 cScriptInterpreter_execute - MATCH, staged build/pending/r2/mw38_003DDFC0.c
- From k6 best_3DDFC0.c (lab 45). Trigger -> 38. In mode all five `#pragma opt_*` lines are no-ops (they were k6's way
  of approximating the mode) -> dropped. Then:
  1. case 1: plain `self->mStackPtr = (int*)((char*)self->mStackPtr - data * 4); MemClear(self->mStackPtr, data * 4)`
     with an `int n` MemClear param (k6's `short n` trick no longer needed; mode keeps one sll) 34.
  2. case 0x42: `id = v ? v->typeId : -1;` gives retail's unthreaded `b; lw; nop / li -1; nop / b test; nop` 30.
  3. case 0x25: `bool t = true;` declared before `int* stk = self->mStack;` 24.
  4. string loop: `self->mDepth == ScSD(ScAt(self, i))` (two small inline accessors: depth created after the chain) 17.
  5. case 0x40 decl order `int i; ScGroup* g; int numArgs; int cnt; int* saveIP; ScFuncDef* newf;` (saveIP hoisted
     out of the inner loop) 2.
  6. Schedule prototype from the DWARF: `Schedule(FuncDef*, float time, int* args, int cnt)` -> call
     `Schedule(self, fd, time, args, numArgs)` (same EABI registers, but argument order sets the mov.s/move order) 0.
- DATA: `"scriptManager.cc"` -> `extern char D_004BD4C0[]` (shared string owned by another unit); `"%d"` written as
  `"%d\0\0"` (retail gives that literal 8-byte alignment; MW aligns <=4-byte literals to 4; precedent playerControls_12
  `"X\0\0\0"`). DATA .rodata 0x004BD510 size 0x250 MATCH.

## 003781B0 XLib_DrawLensFlares - unchanged, 8 lab (p1l lf_best8.c; check_match 6 addrs +2)
- Mode: in mode via the inlined GCC volatile copy ctor (line 21). Making the copy ctor non-volatile (trigger kept) 84;
  operator= volatility irrelevant (8 either way). Retail in mode. Remaining alpha/uv v0<->t2 swap is in-mode colouring.

## 00385D40 cMan_ManDMA - unchanged, 9 lab (p1l md_best11.c; the first lab line is a lab masking artefact)
- Mode: in mode only through the busy-wait div asm; NV+T 9 == base, NV 955 -> retail in mode, the div asm itself need
  not be volatile once the trigger is present.
- faceBlend hoist position (retail: 3rd hoisted invariant of the part-loop preheader; ours appended last, or not hoisted):
  sweep of the `faceBlend = (U64*)self->faceBlends` def over every statement boundary of the loop body (md_pos.py):
  best 8 only when the def sits at the end of the partType==0 branch (semantically wrong, and the def then is simply
  not hoisted). Top-level decl+init (a2) 9 with a different slot, decl before the busy-wait 14, inline FBP/FBQ/FBR
  accessors 21 (forwarded into ld). Not closed.

## 00167C40 cMachine_NextFrame - unchanged, 14 lab (q2 mn_best10.c; lab lines with 2048(at)/-29596 are masking artefacts,
   check_match: viewport rect a1/a3 + quit-box fe/msg s4/s5)
- Mode: in mode via the VU0 matrix asm (line 581). Retail in mode (NV 161 / NV+T 31).
- ResetViewportA: every order of i/r/j/k/v decls (with/without the j/k copies, ref or pointer r: mn_rv.py), RectCp /
  member-wise copy / SetWin inlines, XLibT* / vp-array pointer locals, dead `xx = &r`: never moves r off a1 (14-26).

## 0025CDC0 cGrenade_CalculateArcPoints - unchanged, 14 lab (p5l arcpoints_best.c)
- Mode: in mode (copy ctor line 12 must stay volatile: 79 without; the VU0 helpers' volatility is irrelevant).
- New lead: a DEAD def right before `V start = startPos;` (`{ float z = 0.0f; }` 7, `{ int z = 0; }` / `{ const V* q = &fwd; }`
  / `{ __int128 t = 0; }` 9) gives retail's Cross-copy colouring (copy source in v0, MulT's paddub hoisted before it),
  but the mode keeps the dead instruction (+2 size). Same root cause as p5l's dead-xx Cross copy (11 -> 6 lines, +2).
  Dead defs inside `if (0)`, dead copies of live values (`{ float g2 = gravity; }`), and moving real defs (gravity,
  maxVelSq, endz, the K constant) to that spot do nothing or worse. Retail needs an extra early vreg that emits no code.

## 003BDA00 cCollisionProbe_SphereSweptRay_..._AccountForMovementOfCollidingObjects - unchanged, 23 lab (p5l sweptray_s12.c)
- Mode: in mode (copy ctor line 21 must stay volatile: 39 without; every other asm volatility irrelevant). Retail in mode
  (NV 160 / NV+T 140, both bad because the copy asm changes; trigger alone == base). Remaining = positions of retail's
  dead `addiu` (copy-pointer materialisations the mode keeps); not worked further (p5l/q3 grids already cover it).

## 003ED2E0 cInterfaceModel_Render - unchanged, 34 lab / 349 vs 347 (p5l rn24_d.c)
- Mode: in mode via M copy ctor / operator= GCC volatile asm. operator= non-volatile -> exact size 347 but 49 (its copy
  then folds `lq 2688(v0)` instead of retail's `addiu a2; lq 0(a2)`), so it must stay volatile. Retail in mode.
- `asm { .set reorder }` at 5 positions around ActuallyDraw/DrawText: no change at all (DrawText double nop untouched).
- 24 tRGBA::Set forms (k first/after conversions, k*x / x*k, pre-converted floats, `k *= x` last; rn_k.py) and 6 more:
  best stays 34. FP colour (retail K f0) unchanged by the mode.

## 0024B5D0 PlayerInput_Update - unchanged, 35 lab (n5 pi_best.c; ~10 of the lab lines are lqc2/lui masking artefacts)
- Mode: in mode via the V4 copy/paddub asm members. Retail in mode (NV 3540 / NV+T 398). volsweep (23 sites): only the
  Cp/CpE/SetX copy asms matter (79/89/46/47 when non-volatile), the rest are neutral. Not worked further.

## Per-site volatility (volsweep.py, trigger kept, one asm made non-volatile at a time)
- In every target the only asm whose volatility matters are the quadword copy asms (copy ctor / operator= / Cp);
  VU0 arithmetic helpers, ClampG/MaxP/AbsP, the ManDMA div and the MN VU0 matrix asm are neutral once the function is
  in mode. Nothing improved by making a block non-volatile (unlike q4's F2I in cHuman_Land).

## Lessons for whoever continues
- A draft that carries a set of `#pragma opt_*` off lines and no volatile asm is a candidate for the mode: on 3DDFC0
  the trigger made all five pragmas no-ops and dropped 45 -> 38 immediately, after which ordinary colouring fixes
  worked (k6's earlier dead ends were partly fighting the wrong mode). build/agents/R2/mode_sweep.py does that check
  for a directory of drafts (needs T_ copies with the trigger).
- In mode, dead defs are kept as instructions (mtc1 zero, paddub, addiu, move zero): a dead def changes colouring of the
  following block (ArcPoints 14 -> 7) but costs its instruction; empty output-only asm, `if (0)` defs and coalescing
  copies do not reproduce the effect.
- check_match DATA: a shared literal owned by another unit must be an extern D_ symbol; MW aligns literals of <=4 bytes
  to 4 - a retail 8-aligned 3-byte literal needs padding NULs to reach 5 bytes.
