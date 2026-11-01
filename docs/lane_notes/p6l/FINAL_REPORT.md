# P6L final report (2026-11-01, 13:58-20:00)

## Staged
- cHumanCollisionRoutine_UpdateClimbingEdge 0x1DFB80 (4816 B) -> build/pending/p6/mw38_001DFB80.c
  (source: build/agents/P6L/uce/u36.c = best/uce_best.c). check_match MATCH; no undefined symbols;
  no data or literal problems. The only inline asm is for EE instructions C cannot express (128-bit lq/sq
  copies, VU0 macro ops, abs.s/min.s/max.s). There is a comment saying so at the top of the file.
  No register pinning.

## Best near misses (check_match words)
- cHumanIkRoutine_CalculateLeftWristTargetRot_Local 0x1D2F90 (2760 B): best/lw_best.c (= lw/l2.c), 10 words.
  Exact size; the jump table DATA (.rodata 0x49FF90) matches. Written from the RightWrist draft; the h480
  case matched on the first try.
- UpperBody_HandRotation (= CalculateRightWristTargetRot_Local) 0x1D40E0 (3528 B): best/rw_best.c
  (= rw/r18.c), 10 words (down from 20 this session). Exact size; DATA .rodata 0x4A0070 matches.
  Both wrists now differ ONLY in the same case-24 block: retail schedules the jointRef lui/addiu before the
  two PreMul copies and rematerialises the copy source. The gun-recoil hunk is fixed in both: named
  `const V* pr = &self->gunRecoil`, a tagged Identity return, and QLerp1 as `V r; V* pr = &r;
  QLerpO(pr, a, b, t); return r;`. The best case-24 lead (lw/t_ps1c1.c) gives retail's order but swaps
  v1/a0 and does not rematerialise; see NOTES.md. Fixing case 24 should match BOTH wrists. Note
  (M19's report): LeftWrist shares an asm unit with PositionArm 0x1D2C10, so it needs a split or a
  two-function file.
- cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans 0x1E7F40 (P4L's): best/df_best.c
  (= df/d3.c), 2 words (down from 9). The zero is now kept by writing `mtc1 zero, r` inside the
  `.set reorder` min asm (same idiom as the matched ska_19.c Clamp01). The only remaining difference is
  two instructions swapped (the zero and the 22.0 move at +0x9c/+0xb0). A match would also unblock
  P4L's Transport_StartOfFrameUpdate, which already matches and shares the unit.
- Not started: cHuman_HandleJumpInit 0x1914C0, cHuman_NextFrame 0x1B1710.

## Reusable findings (details in NOTES.md)
1. Prototype .line attribution: tools/pl.sh ADDR SIZE prints the early-prototype disassembly with source
   line numbers. Where the prototype's code generation equals retail (both wrists, UpdateClimbingEdge), this
   gives the source statement order directly. Example: in case 24, the references declared at the top of the
   case (line 3040/3041) are followed by a separate per-statement reference for jointRef (line 3054).
2. Micro harnesses: compile one statement in isolation with the real helper header and print the scheduled
   instructions (micro/midrun.py, micro/cvrun.py, micro/t24run.py, micro/qlrun.py; tools/mc.sh). About 1 s
   per variant, so hundreds of forms can be tried quickly. This found all three final UpdateClimbingEdge fixes.
3. "One level deeper" copy trick: route one specific quadword copy through `Cp1 -> Cp0` (the asm copy in a
   tiny inline helper). This shifts its vreg creation order, and so its registers and schedule, without
   moving stack slot groups. The same idea fixed the RecordLedge argument order: put the cBitArray by-value
   copy one level deeper with `Copy()` and declare the extern with references.
4. Site-specific operator chains: when one expression site needs a different copy flavour (tagged return,
   different MulT local order), give it its own chain at the same inline depth (`MulP2(AddG2(..), k)`)
   instead of changing the global operators.
5. MW asm: ALU ops (addiu/lui) are scheduled across `asm volatile` blocks. The flavour of a copy block
   (volatile, plain, GCC-style) did not matter in these functions.
6. A dead `r = 0.0f` before a `.set reorder` asm is removed by MW's dataflow, but `mtc1 zero, r` written
   inside the same asm is kept, and it is scheduled like retail (DetectFor went from 9 to 2 words).
7. Search tooling in tools/: rsearch.py, lsearch*.py, usearch.py and df/dsearch.py do random or exhaustive
   knob searches scored by lab or check_match; tools/l.sh and tools/r.sh give lab diffs for the wrists;
   tools/mc.sh compiles and disassembles any micro file.
