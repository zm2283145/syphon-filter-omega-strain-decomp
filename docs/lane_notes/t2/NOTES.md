# T2 notes (2026-11-02) - ActorPhys_RunResponse 0x1E2180 (12016 B, ends 0x1E5070)

Base: S1 ar_best.c (lab 463 / sp-masked 222). Best now: build/agents/T2/ar_best.c (= t20.c): **lab 371 / masked 116**
(P4L lab.py), frame 0x14D0, all 333 call targets identical to retail (calls.py), length 3002 vs 3004.

Tools (build/agents/T2/): sec.py draft.c [-q] [-s LO HI] [-o mine.s] [-d]  (one compile, prints sp AND nosp counts;
-d prints the cumulative instruction delta, i.e. where ours is longer/shorter); v.py base out old new...;
brute.py base.c OLDBLOCK.txt variants.py (scores generated replacements, ~0.4 s each); where.sh base 'old' 'new'
(shows which of OUR instruction lines change: finds the source of an asm site); calls.py draft.c (call-target
sequence vs retail, since sec.py masks jal targets); rng.py file.s LO-HI; slotmap.py/runs.py (from S1).

## Function: ActorPhys_RunResponse
best draft: ar_best.c (t20.c); words: lab 371 / nosp 116.

### Progress table (lab sp / nosp)
| draft | sp | nosp | change |
|---|---|---|---|
| t0 (=S1 ar_best) | 463 | 222 | base |
| t1 | 445 | 204 | floor force v: `ground->z` -> `GetZv_L(*ground)` (any inline accessor on ground works); fixes scheduling of the whole v/lim block, -2 instrs |
| t2 | 443 | 202 | fA20: `float c = 0.2f; ClampX_L(AbsZ_L((hi - l10E0.z) + c) / 2.5f, ...)` |
| t3 | 440 | 199 | `hasSum = sum > 0.0f;` (plain bool expr, = proto line 2166) instead of Gt0_L: -2 instrs (andi/mtc1 order, nop) |
| t4 | 434 | 191 | MM_L: `V4* s = (V4*)&v;` before `cVector_ctor_cVectorR(&t, s)` -> retail evaluates src (a1) before dst (a0) |
| t5 | 432 | 187 | SubVI uses SubVS_L = SubV_L with `V4* s = (V4*)&a;` (a1 before a0). NOT for the SubV_L GetPosition sites (they want a0 first) |
| t6 | 427 | 181 | l10C0.z site: SubB_L (operator- body with `V4* s = (V4*)&b;`) -> a2 before a0 |
| t7 | 423 | 177 | tagged ctor `MXc(const void* pl, int)` with `void* s = (void*)pl;` for the first MXc(&l1010) only |
| t8 | 413 | 167 | both probe calls: pass `p->f370` twice directly instead of `float rr = p->f370` |
| t9 | 411 | 164 | `const VV& rf = lF80; if (!IsZero4_L((V4*)&rf)) { ... NZ_L(rf, &len)` -> &lF80 shared in a1 like retail |
| t10 | 409 | 161 | `AV(p->v2F0) = cVector_GetTransformed(...)` (VV::operator= -> Q1D_L dead+real addiu) instead of Q1_L |
| t11 | 407 | 159 | Norm3_L as GCC `__asm__ volatile(... : : "r"(v) : "memory")` instead of an MW asm block: the volatile asm is a CSE barrier, so &dv is recomputed for the following copy like retail |
| t12 | 401 | 153 | VAdd_L as GCC `__asm__ volatile` (same reason) |
| t13 | 400 | 151 | Water_L: `V4* pl = (V4*)&l7B0;` before DetectForWater (a2 before a0) |
| t14 | 396 | 147 | NodePos blocks: `char* nd = m->p20 + ...;` BEFORE `void* c = m->ctl;` (retail loads mdl->0x20 before mdl->0x28) |
| t16 | 389 | 140 | slope block: the three copies in one inline `Cp3_L(&lE60, &res.v50, &lE90, p70, pv30)` (all addresses become inline params evaluated before the copies, like retail), and the four float-constant assignments AFTER it |
| t17 | 387 | 134 | `unsigned char a1 = lE90.z < lE50.z; unsigned char a0 = lE90.z > lE50.z;` (plain exprs; inline args are evaluated right to left, so LtR_L/GtR_L loaded the operands in the wrong order) |
| t18 | 379 | 124 | `float c = 0.2f; unsigned char v1 = NLt0_L(c + (lE90.z - l10E0.z));` |
| t19 | 375 | 120 | Remap_L: `float z = a;` BEFORE `float one = 1.0f;` |
| t20 | 371 | 116 | LerpAndNormalize prototype reordered to `(void* out, void* a, void* b, float t)` (same registers; the real C++ signature is (ret, const cQ&, const cQ&, float), so f12 is set up after a1/a2) |

Rules found:
- Inline call arguments are evaluated RIGHT TO LEFT (G2_L test, LtR_L/GtR_L loads, Remap_L). Choose the parameter
  order of a helper so the operand retail loads first is the LAST argument, or write the expression inline.
- A GCC `__asm__ volatile(... "memory")` block is a CSE barrier; MW `asm {}` blocks are not. Where retail recomputes an
  address after a VU0 asm helper, make that helper GCC volatile (Norm3_L, VAdd_L). Tried and NOT wanted: Dot3_L,
  Dot3N_L, the Lerp blocks, ZQ_L, Z4c, the sqc2-zero stores.
- (several sites): in this mode MW evaluates call args so that a value already held in a *local pointer
variable* is set up before plain `&local` address args; copying an inline's reference param to a local pointer
(`V4* s = (V4*)&v;`) moves that arg earlier (fixes `addiu a1; jal; addiu a0` delay-slot patterns). Apply per site.

### Remaining diff (t20, masked 116, by retail offset; windows 200:5 a00:5 c00:2 1000:3 1600:9 1a00:8 1e00:9 2000:30 2200:15 2400:2 2600:7 2800:4 2a00:14 2c00:3)
- 0x36C-0x384 dh else-branch: colours r/pp->z swapped (proto line 2119 is ONE expression; tried expression, decl
  orders, accessors: no change).
- 0x0B6C-0x0B88 / 0x0C20: z0 compare colours in r1 ladder block (literal vs named z0 compile identically).
- 0x16E8: VV(0,0,h,0) temp stores must come BEFORE the m50 load (retail: m50 = &mdl->0x50 loaded after the VV,
  spilled in the GetSkeletonTargetTransform delay slot). Found forms that fix the code but break the frame:
  * G2_L(void* m50, const VV& d, Root_L* r0, const VV& hv) called `G2_L(p->mdl->m50, AV(l10D0), r0, VV(...))`
    (args are evaluated right to left): nosp -9 but the 6 main temps 0x860..0x810 become inline temps (z3.c).
  * GTW_L(void* mx, void* m) { return cVector_GetTransformed(m, mx); } (swapped params): nosp -5, frame +0x10
    (by-value return copy) (z6.c).
  Probably the original is a member call `mdl->vec50.GetTransformed(mtx)` (this evaluated first).
- 0x1A64-0x1AAC len/Dot: colours (len f0 / zero f2 in retail); proto 2821/2823/2825 show zero and 1.0 reused
  by the clamp. Tried 32 forms (brute.py s/var3.py) - none better.
- 0x2050-0x2120 floor force: top f1/f2 swap (every form of top compiles identically) and the v/lim colours
  (l10E0.z f5, vel f7, ground f3 in retail).
- 0x21D0-0x2220 fA20 colours: c (0.2) must get f2: z/diff/sum f1, c f2, 1.0 f3, ClampX r f4.
- 0x2304-0x2350 slope copies (after Cp3_L): first copy data reg a1 (retail t0), 2nd copy src reuses d1 (retail
  fresh a1), n025 mtc1 placement. 128 Cp3 copy-form combos tried: none better.
- 0x25EC a0 compare register order; 0x2684-0x26AC Remap: retail materialises the 0.0f arg early (mtc1 zero f4, the
  ClampW r) and copies it (mov.s f3,f4) for z; ours materialises z late. 24 ClampW/Remap combos tried.
- 0x2C4C: retail `sw zero,352(s1); b; nop` (inner-if false branches target the b, no jump threading); ours threads and
  fills the delay slot. if/else instead of goto, labels, empty statement: no change.
- 0x1E2C RayQInit `&q->from` arg order, 0x1E90 Los_CombineResult arg order, 0x1EA0 zc compare colours (not fixed).
- 0x29E4-0x2A10: retail has `swc1 f1,lE90.z` then `mov.s $f1,$f1` before h's sub (store->load forwarding copy
  that survived). Every source form tried (Tele_L returning z, z copy, accessor) compiles identically.
- Length: ours 3002 vs 3004: the 0x2684 mov.s/mtc1 pair (Remap) and the 0x2B68 dead addiu in ChildOff_L (a
  `void* xx = d;` in a Cp2X copy adds it but costs colours: 165 vs 159).

### Frame / temp region (unchanged from S1 except where noted)
- 118-120 mismatched sp slots, nearly all temps 0x1E0-0x7E0 (S1 grp.py model: G0 main temps code order, G1, G2
  pass 1, G3 pass 2).
- Scalar spill words: retail order (descending) ZeroF 130, plc 12C, GetPos 128/124/120 (@1660/@1760/@17E4),
  tri 11C, then inline memory scalars fb 100, m50 F0. With m50 as inline param + tri inside
  `FaceSetX_L(f, s0, s7) { FaceSet_L(f, cCollisionModel_GetFace(s0, s7), s7, s0); }` the spill words come out in
  retail order (plc, G1, G2, G3, tri) but fb/m50 are still allocated before them (z5.c). Wrappers around
  CQH2_L/G2_L do not move fb/m50.

### Tried without gain (T2)
GCC-style `__asm__` for abs/max (identical code); operand order of commutative ops (canonicalised); top as
expression / inline / (top = ...); v30.z via accessor or `>`; f2C4 forms; ClampY/ClampZ/ClampW for fA20; extra
named constants (one, zz, k); slope-block statement orders; P4 copy-ctor declaration for lE60; SubtractTo0_L
pointer forms (the VU0Subtract sites at 0x1510/0x173C are SubVI, not SubtractTo0_L); IsZero4_L decl orders.

### Next ideas
1. Temp region (0x1E0-0x7E0): still the biggest pool (lab 371 - masked 116 = 255 sp-only lines, ~120 slots). Use
   S1 grp.py / runs.py; retail = G0 main temps (code order) > G1 > G2 pass 1 > G3 pass 2.
2. m50 (0x16E8): the VV(0,0,h,0) temp must be built before the m50 address is taken, with m50 an inline-class
   16-byte scalar (F0). Inline-param forms fix the code but either turn the 0x860-0x810 main temps into inline temps
   (G2_L, z3.c) or add a by-value return copy (GTW_L, z6.c). A form that evaluates m50 like a member call's `this`
   without an extra temp is still missing.
3. Apply the two rules above (right-to-left inline args; GCC volatile asm as a CSE barrier) to the remaining
   colour sites (0x36C dh, 0x0B6C z0 compare, 0x1A64 len/Dot, 0x2050 top, 0x21D0 fA20, 0x29E4 mov.s).
4. Scalar spill order: with z5.c's FaceSetX_L (tri as a param of a nested inline) the packed spill words come out in
   retail order (plc, G1, G2, G3, tri); only fb/m50 still get allocated before them.

Drafts: t0..t20 (t20 = ar_best.c), z1-z6 (m50/tri frame experiments on t8 base), s/ (brute-force inputs).
