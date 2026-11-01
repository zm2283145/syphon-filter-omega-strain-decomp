# P6L notes (2026-11-01): prototype-guided human/IK targets (P2L ranking)

Tools (tools/): lab.py/u.sh (diff vs ROM; u.sh = UpdateClimbingEdge), smap.py -x -u + us.sh (labelled retail slot map),
myslots.py (my sp slots with first uses), dis.sh (disassemble mine), pcmp.py/pl.sh (proto vs retail, proto + .line).

## 001DFB80 cHumanCollisionRoutine_UpdateClimbingEdge (4816 B) - in progress (uce/)
Retail = proto (humanCollision.cc 3871-4260) with retail offsets (+0x70 for list/ladder fields, 0xDC/0xDE flags,
0x310 pm vector, 0x394 float, ledge dir 0xA10) + differences: floor path facing = skeleton(+8)->node(+0x28)->GetMatrix()
row1, PlusOffset = ref + v310 * 0.1f (f20 loaded before Find); ext distance 14->2.0, 15->3.5, 13->2.5; ladder
fudge -0.75/0.75.
Frame model found (all named/temps placed, 57/65 slots by u15):
- small (<=4 B) and large slots are separate regions, each ordered named > main temps > pass groups.
- vector ops are 3 deep (operator -> X1 -> X0 { V r; asm; return r; }); then the retail pass groups are
  A=3 (lerp/qlerp r, init-op r), B=4 (args of operator= / unary-), C=5 (nested), D=6 (edge-group temp, cMatrix(q) temps,
  ProjectOntoEdge temps). cMatrix(const cQuatVec&) inline ctor; `cQuatVec(QLerpN(..), Lerp(..).SetW(1.0f))`
  (SetW returns V&, keeps &temp in s6). Begin iterators: `It r = P2I(v, imp_begin(v)); return r;` with
  P2I(EdgeVec*, cCollisionEdge* p) by value (imp temp one pass deeper).
- ProjectOntoEdge (proto line 4073): void deep chain writing `bool& r`, top `bool found; PE3(found, ..., Sel(c, a, b), ...)`
  then `unsigned char intersectionFound = found;` - Sel (ref-returning inline) makes the ternary eager (s6);
  returning chains add an extra andi per hop.
- 14:58 best/uce_best.c (= uce/u31.c): check_match 17 words, exact size, all 65 slots right. Path u1 452 -> u18 91 ->
  u22 60 -> u26 37 -> u29 22 -> u31 17. Keys after the frame: pointer locals in Add/Sub asm (`V* pd=d; pa; pb`), MulT
  `pa; t=0; pd`; edge flags `tEdgeFlags f; f.m_flags = e->edgeFlags.m_flags;`; PushBack/p2i via const-ref local
  (`const T* const* pv = &v` / `T* const& q = p`) for arg order; GetWeight() accessor (float regs); validator ctor with
  `cLedgeValidator* t = this` body + face list stored last (pointer member); iterator ==: `const T* q = o.p; return p == q;`
  with != as `!(*this == o)`; FoundLedge()/UnitEdgeVector() ref accessors (separate addiu); Dot via 5-level free chain
  and Sub via 4-level (`Abs(DotW4(Sub3(v0, ladPos), facing))`); AsXY0 `V r = v; V* p = &r; p->z = 0; return *p;`;
  Neg0 `V r; const V* pa = &a; V* pd = &r; NegT(pd, pa); return r;`.
  Remaining 17: (1) cv/AsXY/neg block: retail cv-init copy data a3/dst t0 + neg d shares a2, mine copy coalesces
  (tagged); (2) midpoint op+ return copy: retail copy t = v1 (lq hoisted above paddub), mine v0 after mtc1;
  (3) RecordLedge arg schedule: retail [copy loop] lw a3, sltu, lbu, xori, a0, a1, a2, t0..t2, f12, t3, sd, jal, sd;
  mine computes a2 early and lw a3 / f12 last (with `&*currEdge` the a3 load is hoisted above the copy loop).
  Tried for (2): MulT/Mul0 forms, tagged Add0 (fixes copy, shifts MulT regs), copy ctor GCC/MW/C forms.

## 001E7F40 DetectForAndHandleCollisionWithOtherHumans (P4L's, 10 words) - side experiment, df/
- Micro tests (micro/mm4.c): with plain `asm volatile` min.s the first `r = 0.0f` (mtc1 zero,$f21) is kept, but the
  isPlayerHuman andi doubles; with `.set reorder` the andi is single but MW drops the first zero. Named non-const
  float constants (`float k15 = 15.0f, k22 = 22.0f`) reproduce retail's early 22.0 -> $f2 and `mul.s f0,f2,f12`
  exactly (lab 3 lines, only the first zero missing), but change size by 2 insns in the full file.
- df/d1.c (first min with local copies `float aa = a, bb = b;` + `.set reorder`, second plain volatile): 9 words.

## 001D40E0 UpperBody_HandRotation (= CalculateRightWristTargetRot_Local, 3528 B) - rw/, best/rw_best.c
- Structure: switch(iMode) 25-entry jump table (all unhandled cases listed explicitly so MW emits the table; DATA
  .rodata 0x4A0070 MATCH); cases {3-7,10,11,23}: static quat (euler PI/2,0,PI/2 -> cMatrix_Set_ColumnMajorForm ->
  MtxToQuat asm) via explicit extern guard D_004F47C0 / storage D_0049FF60 (function statics would be .bss),
  gun recoil QLerp(Identity(), q250, 0.35), lookAt (new in retail: GetNormalized/Dot/Fabs/MakeLookAtMatrix with
  g_IdentityMatrix fallbacks) -> named cMatrix copy -> Q(m) premul, w<0 negate, currAim premul, Inverse(elbow rot)
  premul; {12,16}: second static (D_004F47C8/D_0049FF70) + aimAtRot premul; {13-15}: rw = rWristIk +0x40;
  {24}: h660.rot, Inverse(parent rot), hemisphere vs rWristIk.jointRef (cfc2/beql asm).
- Keys: cEuler 16-byte aligned temp; cMatrixC ctors call cMatrix_ctor_void / cMatrix_ctor_cMatrixR; LookAt is 3 deep
  (LookAt3->2->1) so its locals land in the deepest group; PreMul `V t = a * q; q = t;` (op* not deferred);
  IsNeg via `const float* pw = &q.w` 2 wrappers deep; Inverse `V r(q); return Conjugate(r);` with Conjugate using
  `&q` directly in the asm; QMulT pointer locals DBA/BDA; ref accessors LimbPose()/Pos()/Rot()/Parent()/JointRef()/
  H660() for retail's separate addiu; case 24 uses `{ cBoneIk& rWristIk = D_004F46B0; ... }` per statement.
- 16:00 r11: check_match 48 words, exact size; lab nosp 36. Remaining: (1) aimDir op- r slot: retail keeps it in
  the first pass group (op- not deferred) while the temp address is rematerialised; passing `a - b` to LookAt3
  defers op- (slot one group late), a `const V&` local keeps the address in s2; (2) QLerp/Identity block vreg order;
  (3) case 24 vreg order.
- 16:00-17:00 r12-r15: check_match 20 words, exact size, DATA MATCH (best/rw_best.c = rw/r15.c). Keys added: PreMul two
  levels deep with an explicit asm copy in PreMul0; QLerp1/Identity1/Inverse1 one-level wrappers so slot groups line
  up; IsNeg3 chain. Remaining 3 hunks (all scheduling, lab nosp 18): (a) `addiu t0,s4,592` (QLerp b ptr) retail
  before the Identity sqc2 - a named `const V* pr = &self->gunRecoil` fixes it but the Identity1 return copy then
  takes data reg v1 instead of a0; (b) case 24 `rw = h660.rot` lq/sq interleave vs the parent chain lui;
  (c) case 24 jointRef lui/addiu retail before both PreMul copies. ALU ops (addiu/lui) DO move across MW asm volatile
  blocks; asm-flavour (volatile/plain/GCC) of the copies makes no difference. LeftWrist 0x1D2F90 retail has the very
  same three hunks (same code shape: Euler(PI/2,0,-PI/2), D_004F45B0, h480/h4A0), so it is not an easier target.

## 001E7F40 DetectFor (cont.)
- MW asm semantics: plain `asm volatile {}` (noreorder) disables scheduling/peephole in its basic block (double andi,
  hazard nops kept, consts not hoisted) but keeps a dead `r = 0`; `.set reorder` lets the block schedule but its
  dataflow kills the dead zero. Retail needs both (block scheduled + both zeros kept). Tried: GCC-style "=f"/"+f"/"0",
  non-volatile, directive placement, caller-side `rate = 0.0f;` then assign, ref/ptr outputs (illegal addressing):
  none keeps the zero under reorder. lab.py drops some nops - use check_match / tools/dis.sh for exact sizes.

## Session 2 (15:30-) prototype .line insight
- tools/pl.sh ADDR SIZE prints the early-proto disasm with source line numbers. Retail = proto codegen for both
  wrists, so the line attribution tells the source statement order directly. Worth doing FIRST on any target.
- RightWrist case 24 (proto lines 3040/3041/3048/3051/3054): `cBoneIk& rWristIk = D_004F46B0; cBoneIk& rElbowIk =
  *rWristIk.Parent();` declared at case top (lw parent before the h660 copy), then copy, PreMul(Inverse1(rElbowIk...)),
  then SameHemisphere with a fresh per-statement reference `{ cBoneIk& w = D_004F46B0; ... w.JointRef() }` (retail
  re-materialises the lui; using rWristIk there CSEs it into a2; `D_004F46B0.JointRef()` folds +32 into the reloc).
  -> rw/r17.c = best/rw_best.c: check_match 15 words (was 20), lab nosp 12. Left: (a) t0 gunRecoil ptr before the
  Identity sqc2 (proto line 2944, one statement), (b) case 24 jointRef lui/addiu scheduled before the PreMul copies.
- UpdateClimbingEdge RecordLedge arg schedule FIXED: make the cBitArray by-value copy one inline level deeper
  (`void Copy(const cBitArray& o) { for ... } cBitArray(const cBitArray& o) { Copy(o); }`) and declare the extern with
  references (`cLedgeValidator&, cBitArray, const cCollisionEdge&, const V&...`) passing `*currEdge` etc. Now the
  copy loop precedes `lw a3` like retail. -> uce/u32.c = best/uce_best.c: check_match 10 words (was 21).
  Left: (1) line 4178 `V v = a - b` copy: retail data a3 / dst t0 (src a2 dies, neg dst reuses a2), mine coalesces
  data into src; (2) midpoint `(v0 + v1) * 0.5f`: retail Add return-copy lq before MulT's paddub (t = 0) and
  constant, mine after. Grids tried: copy-ctor local orders, statement forms, Mul/Add depth x MulT local order (54),
  tagged Add at the site, knob search (usearch.py on u32, 107 evals): none.

## 16:15 STAGED UpdateClimbingEdge 0x1DFB80 (uce/u36.c -> build/pending/p6/mw38_001DFB80.c), check_match MATCH,
   no undefined/data/literal issues. Final three fixes (all found with tiny "micro" harnesses that compile one
   statement in isolation and print the scheduled sequence - micro/midrun.py, micro/cvrun.py; ~1 s per variant):
- midpoint `(v0 + v1) * 0.5f`: site-specific chain `MulP2(AddG2(v0, v1), 0.5f)` where AddG0 returns the tagged copy
  `V(r, (short)0)` and MulTP declares its locals `pa, pd, t = 0` (t last): puts the Add return-copy lq before the
  paddub/constant, as retail. (Global operator changes broke other sites; same depth as op*/op+ is required.)
- Neg0 `V r; const V* pa = &a; NegT(&r, pa); return r;` (pd taken directly in the call) - fixes neg pd timing.
- AsXY0 `V r; Cp1(r, v); return Z0(r);` with `Cp1 -> Cp0` = quadword copy asm one inline level deeper and
  `Z0(V& r) { V* p = &r; p->z = 0.0f; return *p; }` - fixes the 4178 copy data/dst register choice without moving
  AsXY's stack slot (AsXY2 fixed the registers but moved the slot).
- General lesson: when a copy's registers or position are off, push THAT copy one inline level deeper through a tiny
  helper (Cp1 -> Cp0); it shifts its vreg creation order without touching slot groups.

## ~16:50 wrists hunk (a) FIXED -> both wrists 10 words (lw/l2.c, rw/r18.c = best/*)
- `const V* pr = &self->gunRecoil; V g = QLerp1(Identity1(), *pr, 0.35f);` + Identity returns tagged `V(r, (short)0)`
  + QLerp1 as out-pointer form: `V r; V* pr = &r; QLerpO(pr, a, b, t); return r;` with QLerpO locals
  `q = &b; p = &a; d = o; int tt;` and the same asm. (`return *pr` keeps the pointer live instead of retail's
  rematerialised addiu; `return r` gives a separate vreg -> remat.)
- Remaining in both: case 24 jointRef lui/addiu before the PreMul copies. Shared-pointer op* (`V r; V* p = &r;
  QMulT(p,..); return *p;`) + Cp1 gives retail's shape there but disturbs the Inverse copy registers.

## ~17:40 case 24 (both wrists) - status and leads
- Retail case-24 tail = lui/addiu(base)/addiu dst1/addiu +32/addiu src2/addiu src1/lq/sq/lq/sq. src1 is a
  rematerialised `addiu v1,sp,304` = the same register as QMulT's pd (v1).
- Only the shared-pointer op* (`MulP0(V& r,..) { V* p = &r; QMulT(p, &a, &b); return *p; }` via MulP1, plus
  `Cp1(q, t)`) reproduces the lui-first order (lw/t_ps1c1.c). But: (1) the copy reuses p (a0) with no remat, and
  (2) v1/a0 are swapped across the whole Inverse+QMulT region. Conjugate/Inverse/QMulT-local-order grids (72
  combos) do not undo the swap.
- Micro facts (micro/schedrun.py, micro/sched*.c): C-level pointer copies (`*(__int128*)pd = *(const __int128*)ps`)
  give lui-first after a short COP2 asm, but adding `vsubaz.w ACC, vf3, vf3z` (as in QMulT) to the preceding
  asm flips it back. Non-volatile QMulT also gives lui-first in the micro but breaks codegen. None of this
  carried over to the full function.

## ~16:45 DetectFor 0x1E7F40 -> 2 words (df/d3.c = best/df_best.c)
- Fix for the dropped zero: put the zero INSIDE the reorder asm: `float r; float aa = a; float bb = b;
  asm volatile { .set reorder; mtc1 zero, r; min.s r, aa, bb } return r;` (precedent: ska_19.c Clamp01 has
  `mtc1 zero, r` in asm) for both mins, plus named constants `float k15 = 15.0f, k22 = 22.0f;` after
  isPlayerHuman. The block now schedules like retail; single andi; both zeros kept.
- Left: two instructions swapped: retail `mtc1 zero,$f21` at +0x9c and `mtc1 v1,$f2` (k22) at +0xb0; mine has
  them the other way round. Tried: separate zero asm (before/after aa/bb), zero asm at caller level,
  declaration orders, IsPH return types, MB for the second min, a wrapper depth: no change (df/dsearch.py grid).
