# V2 NOTES (2026-11-02, lane V2: LensFlares + ManDMA near misses)

Tools here: ir.sh draft.c (ManDMA loop preheader compiled with `#pragma schedule off`, raw lui immediates via lab_raw.py),
lfgen*.py (LensFlares cover-block variant grids); proto .line dumps were regenerated on demand with P6L/tools/pl.sh (379640 D90 / 36C020 150C) and deleted (private).

## 00385D40 cMan_ManDMA — best md_best11.c (unchanged, 9 lab lines). Only the hoisted faceBlend `addiu a0,9200; sw 1264` is misplaced.
- Mode: the function is compiled in MW's less-optimised mode (the volatile busy-wait asm). Plain C `one / two`, non-volatile
  GCC asm, MW `asm {}` (non-volatile), volatile `one/two` -> 808-814 instrs, ~950-1070 lines. MW `asm volatile {}` gives the
  same code plus MW's own `mflo zero; nop; nop` (13). Keep the GCC volatile asm.
- Prototype line table: 5120 = `} else if (partType == 3)`, 5121/5122 have no in-place code, 5123 = first continue. So the
  faceBlend def most likely sits on 5122 (best11's spot: first statement of the pT3 block, before the continues).
- Preheader order experiments (ir.sh, schedule off):
  * def before a continue on its way to the use (pT3 block top, loop top before the first continue, for-condition): appended
    LAST (idx 104) = best11.
  * def at loop-body level after the top continues (before `type =`, after bloodPtr): with the other named-variable hoists
    (vifBlood, vifCode1/2) in source order (idx 83/87); 20-22 lines.
  * def in pT3 after both continues (y_11..y_13 = P1L's m0): joins the early group right after the 0.0f constant and before
    0x10000003 (its address is shared with the `faceBlends[0]` load); named slot 0x4F0 still right (lcmp.py 0 mismatches), but the
    preheader RA/schedule cascades (36 / 0x1000404<<32 temps get v0/t2 instead of t0/t3): 81 lines.
  * for-init def: idx 4-5 (first), 86 lines. Def in pT0 (dead/duplicate, or `{ U64* fb = ...; }`): dropped before LICM, no effect.
  * faceBlend++ between the reads (lines 5137/5139/5141 have no code): multi-def -> not hoisted (41-53).
- Marker experiments (unique constant stores at 17 positions): single-use constants from outer-loop blocks are hoisted in a
  second group whose order is NOT source order (bloodPtr-if, else block, pT3 head, pT0 parts, loop top, after mouthOff, after
  strap); constants hoisted out of inner loops and CSE'd (multi-use) constants come first in source order of first occurrence;
  duplicating each marker at the end of the else block puts them in source order. Retail needs faceBlend between pT0's d[1]
  combo and the pT0 blood-loop 32<<32, i.e. a first-group position no dominating def can produce (U2 reached the same reading).
- No effect (all 9): pragma sweep (opt_propagation/common_subs/dead_*/lifetimes/unroll/strength_reduction/loop_invariants on,
  global_optimizer off, optimization_level 3, rebuildlogicals ...); mw50 (9), mw304 (29); real member function `cMan::ManDMA`
  (with or without `self = this`); `if (0) { asm volatile { nop } }` at every statement position of the function (all 9);
  increment helpers `bloodPtr += Inc32()` / `IncP(&bloodPtr)`.
- Next idea: the preheader schedule seems to be pre-RA (schedule off changes s-register choice). A model of MW's list scheduler
  would tell which IR position retail needs; or search two-statement moves in the y_11 world (81) with mutate.py.

## 003781B0 XLib_DrawLensFlares — best lf_best8.c (unchanged, 8 lab lines): alpha chain t2/uv v0, retail v0/t2.
- Also compiled in the less-optimised mode (cVector copies use GCC volatile asm).
- Colouring reading: named locals are coloured before temps and take the lowest free register. best8: uv named -> v0 (ga dead
  there), chain = temp -> t2, scrH temp a3 and 2048 temp t1 as retail. Named chain (`S64 g = (S64)ga << 24`, `g <<= 24`, in-place
  shift inside an inline param, `Sh(&g)`): chain v0 but uv (named) then takes a3 before the scrH temp -> 34. Retail = uv coloured
  AFTER the scrH/2048 temps (uv a temp) and the whole chain coalesced with ga.
- uv as a CSE temp (expression written at both stores): uv t2 like retail but the sign-extension goes to t1 and the loads
  reschedule (41). Exhaustive in that world: 2 uv spellings x 3 g forms x all corner/g declaration orders (528) -> best 31.
- Inline helpers in the cover block change nothing here: uv by pointer (UVp(&uv,..), UVp2(.., &uv)), by value, g by pointer,
  alpha word by pointer (AWp(vif++,..), AWp2), corners by value / by pointer pairs / one 4-pointer helper (both orders): all 8 with
  sp masked (helpers with locals only add a 16-byte frame slot). `Sh24(&g)` 34. `Half()` 29.
- ga as S64/long: 258. `(S64)ga << 24` inline or `int g`: 15. mw50 8, mw304 383.
