# N2 NOTES (session 2026-11-01, near-miss lane: human / IK / game code)

Work dir: build/agents/N2/work/. Tools: bin/nd.py (draft vs retail diff, `nd.py draft.c FUNC ADDR [ctx]`), cm.sh (check_match wrapper).

## 0013FF40 cWeapon_FireIfReady - MATCH (work/fwL.c)
- From k8 fw50.c (7 words, s0/s1 swap of v=slot->id and p=&ev in the out-of-ammo message).
- Fix: the message as an inline C++ class `OutMsg` whose ctor takes the *Slot\** and loads `int i = s->id` inside the ctor after `OutMsg* t = this;`, with `__declspec(weak) __declspec(DROPDTOR)` dtor. Ctor taking `int` (by value or const&), temporaries, and p locals all kept the swap (fwB-fwJ).

## 00230DE0 Global_Shatter - 5 words (work/gs1.c), from k6 g_230DE0.c (12)
- Sound block written as plain aligned char arrays with explicit ctor/dtor calls (as in FireIfReady's fw draft) instead of cSndFx/cPlaySoundMsg RAII classes: fixes (b) the &msg CSE into s0 and (c) the extra nop (12 -> 5).
- Remaining (a) 0x28C copy chain: retail dst1(1312)=a0, dst2(512)=v1; ours swapped. Friend operator- (gs2.c) gets order but swaps a0/v1 over the whole sub+copy (8). Tried: 2-arg early-dst ctor for operator- return / GetNormalized (gs1e-m), friend GetNormalized forms (gs3*), asm operand permutations in a friend-only helper (gs2_*): none < 5.

## 001A1590 cHuman_Fall - 5 words (work/fc1.c), from k8 fa0.c (19, and fa0 also had .bss DATA lines + an out-of-line cMsgT dtor)
- Function statics converted to externs with explicit guards (D_0049D080/A0/C0/E0 cString16N, guards D_004EEE00/08/10/18; velocity zero vector D_004E1D90, guard D_004E1D88) via an Init() member mirroring the ctor: identical code, no DATA lines. cMsgT dtor made weak DROPDTOR.
- AddRequest call routed through a pass-through inline wrapper `AddR(s, id, mode, cf, pg, m1, m2, x, f0, f1)` (all args incl. -1.0f/0.0f passed as params): fixes the float-arg schedule (19 -> 5).
- Remaining 5: arg-setup schedule before the jal (retail: addiu t0 (pg) first, move t2 in the delay slot; ours the reverse). Tried: 150 random wrapper param orders (fperm.py), wrapper body copies, member/two-level wrappers, ref params (revert floats), named msg locals (worse), pg/id/cf expression forms. None < 5.

## General finding: MW register colouring order (micro-tests)
- Among simultaneously-live temporaries MW colours the *later-defined* virtual first and gives it the lowest free register (v0 when the function makes calls, else v1, then a0, a1, ...). Definition order follows source evaluation order (GCC asm operand list order counts; MW asm instruction order does not). A value defined inside a MW asm (e.g. the `mfc1 t` temp) is a late definition and grabs the low register, pushing earlier-defined address temps up. This explains most of the VU0 copy-chain swaps (GCD, FireObj, PositionLeg, Global_Shatter, QuaternionLERP), but no C form tried reorders the definitions the way retail needs.

## 00230DE0 Global_Shatter (5) - additional negatives
- All 68 copy-ctor idioms used in src/ swapped in globally (with member and friend operator-): best still 5 (work/ccs/).
- Site-specific helpers (NormDiff/NormOf/Sub2/Id wrappers, gs6*/gs7*), GetNormalized bodies (gs4*), operator- bodies (gs5*): none < 5.

## 0022A8C0 GetCollisionDist - 20 by check_match (README's 28 was a different count), unchanged
- 68 copy idioms x 7 operator* forms (bin/gcdsearch.py): none < 20. In-place construction (gcdn_*) changes size.

## 00290610 cSkeleton_ResetBBoxContributors - 20 words, exact size (work/rb_best.c; was rb_best22.c = 58 words + size by check_match)
- Loop 2 copy as GCC asm (`lq` via __asm__ with "r"(src), `sq` via MW asm or GCC asm; work/rb2_M.c) gives retail's exact loop-2 instruction set and size (unfolded `addiu +16; lq`, separate `addiu a2,sp,96` for the sq), but ANY GCC asm in the function turns loop 1's `swc1 $f0` zero-vector stores into `sw zero` (32-33). Remaining loop-2 diff then is the data load: retail loads `*pd` early and unfolded (`addiu v0,s1,32; lw v0,0(v0)`), ours either late (after the volatile asm) or folded (`lw a3,32(s1)`) when read before the copy. Next idea: find a GetZero form that keeps float stores with GCC asm present, or a non-GCC way to stop MW folding the +16 into the asm lq.
- UPDATE: 58 words + size (rb_best22.c by check_match) -> **20 words, exact size** (work/rb_best.c = rb9_c.c; work/rbE_q3.c is the same 20 with a pure MW-asm one-line typed copy `{ cVector* pd2 = &offv; const cVector* ps = &(*it)->offset; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd2) } }`).
  - Loop-1 fix: pass the zero as a float variable declared just before loop 1 (`float z = 0.0f;` -> InitContribF(p, z) -> GetZeroF(z)); MW then hoists `mtc1 zero,$f0` like retail and keeps `swc1` whatever asm form loop 2 uses (micro-tested: a float *constant* stored in a loop becomes `sw zero` once any GCC asm is in the function, a float *variable* does not).
  - Remaining 20 = loop 2 only: retail loads `*pd` (boneList.data) early and unfolded (`addiu v0,s1,32 ... lw v0,0(v0)` before the it-derefs); ours loads it after the copy asm (asm is a barrier). Reading it before the copy always folds to `lw 32(s1)` and drops the join nops (size -0xC): tried data/ref/volatile/DataV/pd-first orders, split lq/sq with the load between, non-volatile GCC lq (folds everything), MW-asm forms (rbA_*, rbB_*, rbC_*, rbD_*, rbF_*).

## Other targets probed this session (no change)
- 001D1140 cHumanIkRoutine_PositionLeg (8, k4 k1.c): Scale_ decl orders (pla-plf), non-member scale forms for kneeEndVec (plea-plef), TwoLimb pass-through wrapper (size change), all 68 copy-ctor / operator= idioms (bin/plsearch.py), RotB accessor forms at the 2nd PreMultiply site (plr_*): none < 8. Cluster 2 (0x2fc) is a single temp (s0+128 from `Rot()`'s `t = this`) coloured a0 instead of v0.
- 001D0780 cHumanIkRoutine_AimHeadIndependently (9, k4 h18.c): all 68 copy idioms for V4 copy ctor / operator= / both (bin/ahsearch.py): none < 9.
- 001DD6A0 cAimComponent_NextFrame (11, k7 ac0.c; NB config address is 0x1DD6A0, unmatched_r215.tsv lists it under 1DD1C0): the 3 extra ext pairs. Micro-tests: with `peephole off` every char->int conversion gets dsll32/dsra32 (so retail's b1 index sites without ext imply peephole ON); with peephole ON an ext right after lb is always removed (direct, inline, member accessor, ref, volatile, cast, bitfield, local copy, Valid() inline, switch, compare-reversal forms all tested) except for values arriving in a register as a char-typed *parameter*. Peephole-on draft (acp1.c) loses the compare-site ext and folds the sq offsets. No C form found for retail's "lb; ext; beq" + reload + ext.
- 00180580 QuaternionLERP UpdateVelocity (17): member/late-address Mul variants (sqm_*): unchanged 17.
- 0018A950 cHuman_HandleDeath (22 by README; check_match 22): P56 pair-set helpers (hd_*): 22-24.
- 004073C0 SKL_CompressSKL (16): region-2 invariants as explicit block locals before the outer loop in all 6 orders (sklx_*): 38 (count still coloured last). NB the draft uses `{ asm { nop } }` for empty branches, which would need review before it could be staged.
- 0025F930 cVisionFxMan_DeactivateFx (25): micro-tests of the triple `mfc1` after one `trunc.w.s`: every form (chained/separate/inline/ctor/loop, with common_subs/propagation/lifetimes/peephole pragmas) gives either 1 mfc1 or 3 trunc+mfc1.
- 0022BA30 CheckBulletCollisions (29): not worked; the draft's UNDEF callees resolve to WorldObjList_Get -> details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2 (0x141870), Mtx_Transpose3x3 -> cMatrix_InvertRot (0x13EE20, 1 arg), Mtx_IsTranslationZero -> cMatrix_IsZeroTranslation (0x13EDB0); also Vec4_Assign -> cVector_ctor_cVectorR, Vec3_Negate -> cVector_NegateXYZ, Mtx_TransformByTranspose -> cVector_Rotate_cMatrixR, cMatrix_SetTranslation (0x131E70).
- 002625B0 cFireObj_ctor (21), 00405660 Monster_ctor (21), 00336700 cAgentData_ctor (28): read notes and diffs only; same VU0 colouring / asm-hoisting / LICM families as above, nothing new tried.
- 17-word variants (by check_match count) exist but look structurally further from retail: work/rb17.c = copy first, then idx/r/pd (statement-order search, bin/rbperm.py, no `register`); mutate.py found the same 17 using `register` locals (work/mut/rb.best.c). Kept rb_best.c (20) as the main lead since it has retail's statement shape.
- Plain-C volatile __int128 copies (rbV_*) and `#pragma peephole off` (rbP_*) break loop 1 (worse).
- mutate.py 60 min each (-j 1): cHuman_Fall fc1.c 8,955 variants -> still 5; ResetBBox rb_best.c 9,581 variants -> 17 (only the early `register`/statement-order swap noted above).
