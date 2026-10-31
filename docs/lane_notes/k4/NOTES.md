# k4 lane notes

## 001D4EB0 cHumanIkRoutine_CalculateRightWristTargetPos_SkelSpace — MATCHED (session 3)
- build/pending/k4/mw38_001D4EB0.c (from work/d19.c); check_match -c mw38: MATCH + .rodata, no UNDEF.
- Route (181 -> 0): (1) took the matched D3E30 file (same source file) as the header/case-4/5/23
  body; (2) `#pragma inline_depth(10)` (not 16) fixed all non-slot code diffs; (3) Translate's
  `t * w` via a separate `MulT` inline with `int t;` declared BEFORE `cVector r` (fixes v1/a0 vs
  a1/v1 colour of the VU0 scale); (4) stack-slot puzzle solved with dead `if (0)` inlines.
- Stack-slot rule (mw38), verified: named locals take the top of the frame in declaration order
  (unused locals get NO slot unless referenced, even from `if (0)`); below them compiler temps are
  laid out in ROUNDS by inline depth (round k = temps at inline depth k-1), and inside each round
  in source order of the switch cases. A gap of n slots in retail at round k after case X = n
  dead temps at depth k-1 at the head of the next case (or tail of X). Dead helpers used:
  `R0(v)` (returns cVector by value: 1 depth-0 temp), `Dz(v)` (depth-1 local), `D2(v)` (depth 2),
  `D3(v)` (depth 3). Tool: work/lay.ps1 prints both layouts annotated with case region + gap sizes.

## 001D3E30 cHumanIkRoutine_CalculateLeftWristTargetPos_SkelSpace — MATCHED
- build/pending/k4/mw38_001D3E30.c (from work/t135.c); check_match -c mw38: MATCH + .rodata, no UNDEF.
- Key mw38 tricks that closed it (50 -> 0):
  1. `.set noreorder` / `.set reorder` inside the VU0 `asm volatile {}` block removes MW's
     hazard nop between `mfc1 t,fN` and `qmtc2.ni t,vfN` (splitting asm blocks does not).
  2. Dead use of `this` after an out-of-line ctor call (`cVector* t = this; (void)t;`)
     reproduces retail's dead `addiu reg,sp,X` (MW ctor returns this).
  3. Named locals get a vreg at declaration; colouring is roughly reverse creation order,
     scheduling follows the definition point. To get "computed first, coloured later":
     declare uninitialised first, assign later (`const Q* rot; const V* pos = &p.pos; rot = &p.rot;`).
  4. Passing a member expr (`self->q250`) to an inline that copies `&x` into a local pointer
     (IsNearIdentityR) materialises the pointer late, unlike a named `cQuaternion& q` local.
- Earlier: stack-slot order follows inline nesting depth; dead nested inlines in `if(0)` push
  slots later; MW has no NRVO; MW rejects "f" operand for mfc1 inside GCC asm.

## 001D0780 AimHeadIndependently — 8 dif lines (work/h0.c)
- else-if(notId) branch: QMul temp copy source address coalesced into a1 (data reg) vs retail v1;
  &rot then hoists above the copy. Tried (h2-h12): QMul/PostMul body forms, uninit-pointer forms,
  pragmas, site-specific same-depth PostMulA/B bodies, statement forms. No gain; wrappers change
  inline depth and shift stack slots.

## 001D1140 cHumanIkRoutine_PositionLeg — 16 dif lines (work/k1.c)
- 3 independent colouring swaps: 0x12c a0/a1 (Scale_ pv/pr), 0x2fc v0/a0 (PreMultiply lookAt temp),
  0x4dc/0x4f0 fp/s3 (hipRot vs sideHip lookAt.Pos in nIk_TwoLimbIK args).
- k7/k8: site-specific `PosK(){cPose* t=this; cVector* r=&t->pos; return *r;}` for kneeIk Pos +
  `PosB` variants fixes fp (hipRot) but then swaps s3/s4 (lookAt vs Pos) — still 16.
- Scale_ pr-first fixes 0x12c order but recolours the AddG copy (0xec..). k2-k14 grids, no gain.

## 001ED120 cEdgeGroup_IsEdgeInsideGroup — parked, 12 words (work/e0.c)
- Pure colouring diff 0x70-0x84 (retail p=v0, chain=a1, y=a3; ours chain=v0, y=a1, p=a3).
- MW asm{} QEq idiom (e1.c) much worse. e2-e8: operator==/operator*/loop-body/constraint/
  C-deref-lq forms all keep the same colouring.

## 001D4EB0 — code size exact, 248 lines (work/d12.c)
- Frame 0x2E0 vs retail 0x490: retail keeps many more 16-byte temps; slot layout far off.

## Late session (19:10-19:25)
- D0780 h13: site-specific QMulB/QMulC return-copy forms + copy-ctor shapes: no gain (8).
- ED120 e9-e11: pragma matrix, swapped operator== operand order, MSL-style two-level __wrap_iterator (operator* / operator++ forms): no gain (24 lines). mw50 identical for k1/h0/e0.

## 001CB160 cHumanIkRoutine_NextFrame — 10 words (hg/best.c = hg/w12.c), session 2026-10-31
- Progression: 104 -> 54 -> 42 -> 41 -> 39 -> 37 -> 28 -> 22 (w9) -> 18 (w10) -> 13 (w11) -> 10 (w12).
- w10 OffC fix: V4Copy with no param copies (VZ_3) + QRotV clone that copies only v + direct `&plc->q`.
- w11 0x504 fix: QHemi call moved INSIDE QA_L (after final V4Copy), QHemi clone copying only `ref`
  (QHZ_16), ref passed as extra QA param (QAZ_16(&qa,&plc,&wm,&pos,&self->q150)).
- w12 Aim fix (partial): zero vector as by-value return of a struct with inline copy ctor
  (`struct VV_0 {Q_L q; VV_0(){} VV_0(const VV_0& o){V4Copy(&q,&o.q);}}; VV_0 vv = ZeroV_0(); Q_L& v = vv.q;`).
- Remaining: 0x5d8-0x5f4 Aim (retail t=v0,q=v1,d=a1 + dead pw addiu, lq scheduled right after sqc2;
  ours re-materialises &t and lq/sq land late), 0x31a4/31ac + 0x34bc/34c4 L4 Lerp operand addiu
  order (retail d,b,c; ours c,b,d; immune to identity-inline / pointer / member-asm / CQ ctor grids),
  0x3818/381c alignment padding.
- Insight: explicit `v1` in asm gives retail t/q colouring but asm stays unscheduled (lq/sq adjacent).
- Batch grid tool: hg/runc.sh DIR N (WSL, ~0.2 s/file) — grids of param-copy subsets x call-site forms work.

### NextFrame (001CB160) — MATCHED 07:28 (hg/w15.c -> build/pending/k4/mw38_001CB160.c)
Progression 104->54->42->41->39->37->28->22->18->13->10->6->4->MATCH.
- Aim 0x5d8 (w13/w14): MW keeps asm blocks in source order and statements between them stay between
  ("barrier model"). Zero3_L(v){ t; pt=&t; V4StoreVF0(pt); Q_L* d = v; asm{lq v1,0(pt)} return d; }
  then in Aim: `const Q_L* q;` declared first, then pv, pp=plc, pw, then `asm{sq v1,0(d)}`, y store,
  `q = cQuatVec_Rotation(pp)`. Explicit hardware v1 across separate asm blocks works.
- L4 operand order (w15): `{ Q_L* pd = &t; asm { .set at } const Q_L* pa = a; const Q_L* pb = b;
  Lerp4x_L(pd, pa, pb, s); }`. A no-byte asm directive block (`.set at`/`.set noat`) is a real barrier
  (empty asm {} / GCC "" asm are not), pinning pd's addiu before pa/pb's.

## 001ED120 cEdgeGroup_IsEdgeInsideGroup — MATCHED 07:55 (build/pending/k4/mw38_001ED120.c)
- Progress 12 -> 10 (explicit a1/a3 regs in lq/pceqw/ppach asm) -> 7 (whole compare incl. sltu/xori/andi in one asm, output `res`) -> MATCH.
- Final trick: declare `unsigned char res;` FIRST in the function (before CI currEdge/end) and inline the compare asm in the loop body, with `const EL* pe=&edge.edgeLocator; long long m=-1; __asm__("":"+r"(m)); const EL* pb=&inputEdge.edgeLocator;` in that order. Early declaration of the result vreg moves it off v0 so the iterator pointer gets v0 (retail colouring).

## Session 2026-11-01 (morning, after NextFrame/ED120 matches) — h0 / k1 / 1D02B0 grids
### 001D0780 AimHeadIndependently — 9 words (work/h18.c; work/h20.c = same 9 with prototype decl order)
- Prototype (early, MW 2.4.1) disasm is register-identical to retail; locals in order:
  isGunRecoilNonZero(s0), halfGunRecoilResistance(0x1D0), headIk(a0), neckIk(v1), chestIk(v0, unused),
  desiredRot(0x1C0), desiredRot(0x1B0). h20 = notId first, rot after it, a/b as block locals: still 9.
- Both PostMul sites are the same construct in retail (QMul into l0 -> return temp -> operator=);
  only the o-site copy1 is interleaved with the s-site start. Remaining diff 0x414-0x438 is the
  copy1 value register (retail a1, ours v1 coalesced with the source ptr) + rot ptr (retail v1 after sq).
- Failed (all >=9): split asm/C copy ctor (lq asm + C sq / C lq + sq asm), ctor statement orders,
  PostMulB temp forms, every B/C/member combo at both sites, trivial V4P struct (word copies, size+),
  `.set at` barriers, top __int128 by ref, shared rot ptr, CPM helper, V4P return.
### 001D1140 PositionLeg — 8 words (work/k1.c)
- Prototype is hash-exact with retail; k1.c already uses its local order (toeIk..hipIk, newKneeRot_Local,
  newToePos_SkelSpace, kneeStartVec, kneeEndVec, fudgeRot). Note DWARF block_depth is flattened (always 1).
- Grids this session (all worse/unchanged): hoisted reference locals (49 subsets), Scale_ uninit ptr /
  `.set at` forms (19), Rot()/PreMultiply variant matrix at first PreMultiply site (8 or size change).
### 001D02B0 CalculateResultPose — 127 words (work/r0.c, from p03ik/d02b0_best.c)
- Structure is 100% identical to retail; the whole diff is a permutation of 11 loop-hoisted vregs.
  Retail colour order (v1,a0,a1,a2,a3,t0,..t5): l0(0x60), temp(0x70), result(0xA0), nextRot, currRot,
  currBoneIk, [t1 temp], case consts 1,2,3,4 (t2..t5). Ours: consts 1..4 get v1,a0,a1,a2 first, then
  l0, result, temp, nextRot, currRot, currBoneIk (t4). i.e. our hoisted switch constants get the highest
  vreg numbers; retail's the lowest.
- Immune: switch case order / default / ptr-return / (int)/(uchar) casts / if-chains (size+),
  loop-local vs function-level decls of result/curr/next/currRot/nextRot, boneList moved after
  iterators (worse, prologue), non-transition-first if shape (worse), GCC-style asm for copies/NLERP
  (identical output), asm with reference operands (compile error).

### Late-morning grids (08:05-08:20)
- k1 (8 words): accessor forms on nIk_TwoLimbIK args (direct member / const cast), named ref locals for shPos/hRot,
  Scale_ pr-first x AddG return forms x copy-ctor forms, cPose/cLimbPose member types, PreMultiply x operator* bodies (19): none < 8.
  pr-first Scale_ makes MW CSE sp+0x220 (copy dest == pv) -> worse. Remaining 3 pairs are colour/schedule swaps (0x12c, 0x2fc, 0x4dc/0x4f0 fp<->s3).
- 1D02B0 (127): retail colour order = addrs(v1,a0..a3), currBoneIk t0, curr t1 (DWARF), consts t2..t5, t6, next t7.
  Ours puts the 4 switch consts first (v1,a0,a1,a2), everything else same relative order. Wrapping the loop body
  in an inline (out-param) reorders the address vregs (sorted by stack offset) but consts stay first; returning by value grows size.
  mw (3.0.3) is far worse (size 0x520).
- h0 (9): QMulC/QMulToC argument-order variants (5 signatures, pl/pq pointer locals), PostMulC call forms
  (ptr/ref/swapped params, direct assign, block-local p -> shifts stack +35), explicit-a1 asm in V4B copy ctor
  (acts as a barrier, 21): none < 9. Retail computes &l0 (sp+0x60) before &rot (sp+0x1D0); ours always the reverse.
- DBB20 InitWeaponSlotIkTargetTable (work/b4.c, 99): first diff is temp stack-slot order in the
  cQuaternion(0).PreMultiply(...) chains (retail: identity r @0x150 then return temps 0x140/0x130; ours r @0x130,
  temps 0x160/0x150). Identity ctor forms (direct sqc2 into this, QIdF(), pointer local) x PreMultiply forms: best 99 (no gain).
  DWARF lists no locals, so retail is a single expression.

### Final (08:40)
- mutate.py 55 min runs: k1 PositionLeg 32,806 variants -> still 8; h0 AimHeadIndependently 30,929 variants -> still 9. Remaining diffs are register colouring / scheduling, not reachable by line mutation.
- DBB20: IdTag identity ctor forms (expression temp, cQuaternion(cQuaternion(IdTag()))) all change size (0x15a4/0x15b4) -> worse than b4.c (99).
- h0: second-branch copy variants (__int128 copies, PostMulB, QMulC assign, inline block QMulToC) all worse (12..101).
- Best drafts left in work/: h18.c/h20.c (h0, 9), k1.c (k1, 8), r0.c (1D02B0, 127, register permutation only), b4.c (DBB20, 99).
- Delivered: pending/k4/mw38_001CB160.c (NextFrame, from prototype DWARF) and mw38_001ED120.c, both re-verified MATCH at 08:41.
- 1D02B0 GetRot forms (case order reversed 139+6, default-case 0x438 size, ptr-select/int cases = 127 same, if-chain size 0x4a0): no gain.

## Session 4 (R214 list, wrap-up)
No new full matches this session. Pending dir untouched.

### 001D1740 nIk_TwoLimbIK (4380 B) -- best work/tl/best_tl.c = 109 words, exact size
- Source structure: work/tl/t7.c + work/tl/hdr.h (best_tl.c is the self-contained hdr-inlined form). Started from l5's 651-word draft.
- Gains: Invert asm on 0(this); op+ = `return cVector(*this) += b;` (gives retail's dead addiu v0); GetInverse0 =
  `{ cQuaternion r(s); r.Invert(); return r; }` (238); op*(float) with `.set noreorder` and rr declared before a; cosTargetAngle
  via CLAMP4_I; cQuaternion op= declaring d before s (109). In-place clamp (`float r=0; l; h; r=a; asm max/min r`) = 108.
- Remaining diffs: (a) float block 0x454-0x4ac: register colouring (retail lB^2 f4, d^2 f5, h f6, l f7, lA temp coalesced into
  cosTargetAngle f8, mtc1 zero,f8 scheduled first); (b) dead `addiu v0,<temp>` after both cQuaternion_GetConjugate calls
  (0x740, 0xe48) and after GetInverse(pivotARot) (0xa40); (c) GetInverse return copy should reuse Invert's register
  (achieved with `return cQuaternion(s).Invert();` but that loses 4 instrs since the dead addius are missing);
  (d) SetRotationArc/op+ interleave at 0x32c, v0/v1 swaps at 0x108 and 0x6cc, Rotate result-copy order at 0xa88/0xe14.
- Promising alt: work/tl/alt_tl_258.c (GetInverse0 = `return cQuaternion(s).Invert();` + cQuaternion copy ctor as direct
  lq/sq asm instead of CopyFrom): only 2 instrs short and very few hunks left (float block, 0x740/0xe48 dead addius,
  ACJL branch nop placement 0x828/0xf34). Score 258 is mostly shift. BEST NEXT IDEA: find the construct producing the
  dead `addiu v0,&temp` after the GetConjugate calls in that alt draft (that alone should fix size and drop it far below 109).
- Tried w/o gain: GetConjugate wrappers (static inline, ref-binding identity, ref param decl, const return, casts), member
  Mul on the conj temp, op*/SetMul pointer-order forms, GetInverse wrapper chains/member/one-level, Invert with local
  pointers, Rotate with local `this` copies, expression order of the cos formula, zero-init placement of cosTargetAngle.
- mutate.py 45 min on the 109 draft: no improvement.

### Other near misses (unchanged): k1 PositionLeg 0x1D1140 work/k1.c 8; h0 AimHeadIndependently 0x1D0780 work/h18.c 9;
1D02B0 CalculateResultPose work/r0.c 127; DBB20 InitWeaponSlotIkTargetTable work/b4.c 99.
