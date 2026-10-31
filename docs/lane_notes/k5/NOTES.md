# k5 lane notes

| addr | name | best | draft | remaining |
|---|---|---|---|---|
| 003CD260 | cGOBJ_GetCenterOfMass | **MATCH** | pending\k5\mw38_003CD260.c | - |
| 003BB360 | cTexture_UploadBoth | 11 | work\ub_c.c | head mask-constant regalloc (uninit decl order c,m,t gave 13->12) |
| 003BD450 | SphereSweptRay_TestLineSegment_IgnoringEndPoints | **MATCH** | pending\k5\mw38_003BD450.c (work\bd_j.c) | - |
| 00394AD0 | cVUM_GOBJ_Render | **MATCH** | pending\k5\mw38_00394AD0.c | - |
| 003BBDC0 | cSKYBOX_GOBJ_Load | **MATCH** | pending\k5\mw38_003BBDC0.c (work\sk_h.c) | - |
| 0039EF90 | cParticleShatter_SetShatterData | **MATCH** | pending\k5\mw38_0039EF90.c (work\sh_m.c) | - |
| 003B0280 | cSkaTransPlayback_UpdateWhatToPlay | **MATCH** | pending\k5\mw38_003B0280.c (work\bo_k.c) | - |
| 003B17D0 | cSkaAnim_ProcessAnimData | **MATCH** | pending\k5\mw38_003B17D0.c (work\pa_r.c) | - |
| 0039FC10 | cParticleSpline_ComputeBezierFactors | **MATCH** | pending\k5\mw38_0039FC10.c | - |

## Findings
- **Split copy + volatile empty-asm address barrier (bz MATCH):** retail had `lq; lui/addiu (global addr); sq` i.e. a
  constant address materialised *inside* a 16-byte copy. Write the copy as two volatile asms (`lq` then `sq`) with
  `const T* pm; __asm__ volatile("" : "=r"(pm) : "0"(this));` between them; the la lands between lq and sq.
  Use a separate `void* xx = &r` for the sq address (avoids CSE with later use) plus an extra dead `void* yy = &r`
  for the dead addiu. Barrier alone (no split, or non-ordered) has no effect.
- **`.set noreorder` around the whole MW asm{} block** (vs only around mfc1/qmtc2) changes surrounding scheduling:
  sh `operator*=` -> lwc1 hoisted before `daddu` (sh 20 -> 17).
- **`sltu $at,$zero,x; beqz $at`**: unsigned `<` against a late-propagated constant 0, e.g. member
  `int At(unsigned i){ if (i < info->count) return ids[i]; return -1; }` called `At(0)` (literal `0u < n` -> beqz v1).
- **Tagged return in a by-value wrapper** picks one specific copy's flavour: `return cVector(r, 0);` in ScD (sk 23->20),
  member SubK `return V4(r,(unsigned char)0)` used only by Sub() (sh). Tagging where no copy existed adds a copy.
- 394AD0: retail copies `lq a1,0(a1)` = temp coalesced with dying src. MW GCC-asm always makes outputs
  interfere with inputs ("=r" == "=&r", split lq/sq asm identical, MW asm{} blocks fold offsets, C loads fold).
  Registers of whole region shift by one because of it.

## 00394AD0 MATCHED -> build\pending\k5\mw38_00394AD0.c (mw38+mw50)
- from l4 best (17): copy ctor body reordered: `__int128 t;` declared FIRST: `{ __int128 t; cVector* d = this; const cVector* s = &o; void* xx = this; asm(lq/sq ... "=&r"(t) : "r"(d), "r"(s)) }`. 72-perm grid (work\gen1.py): every order with t first -> 0 diffs. Temp vreg created first => coloured so it can share the dying src reg (retail lq a1,0(a1)).


## 0039FC10 (33, work\bz_best33.c)
- Function-local `static cMatrix m(...)` can't be linked (bss). Replaced by manual guard on extern globals:
  `if (!D_0053BB00) { D_004BC560.Init(cVector(..),...); D_0053BB00 = 1; }` -> guard block matches (incl. nop).
  Init = inline member `{ const cVector& aa = a; cMatrix_Set_...(this, aa, b, c, d); }` (the `aa` ref fixed a1-before-a0 order).
- Use D_004BC560 directly in each expression (a `cMatrix& m` ref gets CSE'd). Call forms: s1 `D*cp`, s2 `Mm1(D,cp)`, s3 `Mm2(D,cp)` (162-grid).
- Remaining: m address pseudo gets a1 (lui hoisted to stmt start) and r-dest (copy-ctor this) gets v1 late; retail opposite.
  No gain from: op* body forms (~15), by-value params, free fns, global in asm, cc/op grid, #pragma scheduling/opt_* off.

## 003CD260 MATCHED -> build\pending\k5\mw38_003CD260.c (mw38+mw50)
- Stack slots follow inline-expansion "event" order: later-created temps get LOWER sp offsets. Call bodies in
  argument position are expanded later than the outer call; adding an inline wrapper layer defers a body further.
- Problem: deferring Scale's local via a wrapper fixed slots but changed vreg numbering -> copy temps coloured v1.
- Fix: keep Scale as-is; make Xf's local a DEFAULT ARGUMENT `Xf(const V& in, M* m, V o = V()) { o = in; ... }`
  (temp created at call time = earlier slot, registers unchanged) and call it through a const-ref alias wrapper
  `XfW(const V& in, M* m) { const V& i2 = in; return Xf(i2, m); }` which defers that call one event so the slot
  lands between Scale's param v and Scale's local c. (Plain wrapper without alias: slots right, regs wrong.)
- Trailing alignment nops (0x1b8 vs 0x1c0) do not matter for check_match.

## 003BD450 (16): default-arg Add7/Sub7 and alias-wrapper depth grids (gi4/gi5) all >= 21.
## 003B0280 (18): x*=x2 forms, ref-param clamps, asm clamps all >= 20.

## 003BBDC0 sk (28, work\sk_c.c / sk_b.c)
- 32->28: `operator/=` as `return *this *= 1.0f / k;` (sk_b) OR `pl->brad = 0.5f * (bhi - blo).Length();` member-call
  form instead of wrapper (sk_c: puts 1.0f into t0 like retail, fixes B0 regs). Colouring of loop-invariant t-regs
  follows LICM/vreg creation order (retail t8..t0: q,p,r,dst,src,Length D0,C0,B0,1.0).
- No gain: operator- pointer decl perms, Size() asm/operator/caller forms, `cSLayer& layer` loop (55), default-arg
  Size temp / wrappers for 0x90/0xA0 slot swap, mw50/mw304 identical.

## 003B0280 bo (18, work\bo_e.c) - sinus block only
- Retail: lui 1.0(v1),2.0(a1),3.0(a0); x f2, x2 f3, x3=x*x2 into f2 early; mul f0=3.0*x2, mul f1=2.0*x3, UNFUSED
  sub.s f1,f0,f1; 1.0 in f4 (mtc1 late). f4 => 1.0 float vreg interferes with x/x2 pre-schedule.
- Fusion (mula/msub) avoided by compound forms: `x *= x2; float v = 3.0f*x2; v -= 2.0f*x;` (gn6 f1, 26) gives the
  exact instruction shape but regs 3.0/2.0 swapped (f1/f0), x f4, 1.0 f2. `w = -(2*x); w += 3*x2` gets const regs
  right but neg.s/add.s. #pragma fp_contract/STDC FP_CONTRACT: no effect.
- `__asm__ volatile` clamp kills loop opts (135). Non-volatile GCC asm = 20.
- Splitting `lui` into separate early asm (One()/LuiOne()) moves source position but scheduler ignores it;
  asm One() with mtc1 inside forces 1.0 first but then mtc1 isn't deferred and f-reg pressure rises (17-24).
- C 1.0f constant to clamp gets hoisted function-wide (31-48).

## 003BB360 ub (13, work\ub_a.c) - head only (rest matches)
- Retail: `lui v1; ori a3,v1; ...; dsll32 t0,a3,0; or v1,v1,t0; pcpyld v1,zero,v1` + ld t1, and t0,t1,v1, clut t2.
  Ours: dsll32 a3,a3; or a3,v1,a3; pcpyld t2,zero,a3 (mask local) or lui a3/ori a3,a3 (inline const).
- Tried ~60 head forms (gm5-gm8, gf*): typedef unsigned long, ~mask, split masks, statement orders, x/c/t locals,
  file-scope const, signed long, inline helpers. Best 13. Prototype disasm identical, head has no named locals.

## 003BD450 bd (16) n = D + tP - uE
- Retail slots: sum 0x60, sub result 0x50; copy of sum -> 0xC0 (by-value param). Alias wrapper SubW(D+tP,uE)
  fixes slots (23) but address-register colouring differs; 24 decl-order x return x wrapper perms (gn1) and
  6 asm operand orders (gn2: no effect at all) -> best 23. Split statements (gm9) worse.

## 003B0280 MATCHED -> build\pending\k5\mw38_003B0280.c (mw38+mw50)
- FP constants as VARIABLES with compound ops: `float c2 = 2.0f; float c3 = 3.0f; c3 *= x2; c2 *= x; float v = c3 - c2;`
  (+ `float x2; x2 = x*x; x *= x2;`) -> unfused mul/mul/sub with retail f-regs. Decl order of const vars picks a0/v1.
- Explicit `return;` inside the first inner branch (keeping the common return after if/else) fixed retail's
  branch threading (`b exit; nop` pattern and direct branch targets).
- HARD-REGISTER ASM: separate small non-volatile `asm { lui v1, 0x3F80 }` at block start STAYS at block start
  (unlike asm outputs into C vars, which are rematerialised at use). A later asm reads `v1` directly
  (`mtc1 v1, $f4; min.s r, r, $f4` - pre-coloured f4 also works, `fp4` doesn't). Allocator respects the hard
  reg liveness. Volatile hard-reg asm breaks everything (120+). Multi-insn asm blocks schedule as a unit (no
  interleave with prologue). `asm { la v1, SYMBOL }` compiles; %hi/@ha forms don't.

## 0039EF90 sh 48 -> 23 (work\sh_c.c)
- Loop-entry extra nop (retail 0x17c) is just loop-head ALIGNMENT padding: fix the instruction count before it
  and it appears automatically.
- Copy-ctor FLAVOURS via tag param: `V4(const V4& s, int)` (no dead `xx=this`), `(V4, char)` (src local) etc.
  Each dead `void* xx = this` emits a dead addiu; choosing which copy has it fixes head and STACK SLOT ORDER
  (slot swap 0x100/0x110 fixed by giving the operator- return copy no xx and GetNormalized's copy the xx).
- Member `SubN`/`SubM(b, int)` = operator- whose `return V4(r, tag)` picks the flavour for just one call site.
- `return r;` vs `V4& rr = r; return rr;` in Cross/unary-minus flips copy src/dst materialisation order (36->23).
- No gain: Has()/ternary forms for `sltu $at`, best/j decl placements for 0x284 sched, Cross decl perms,
  static CrossS, Sub body forms.

## Segment findings (late)
- pa 105 -> work\pa_b.c (float rate = pr->speed; rate *= (float)n after t). Remaining: s-reg rotation, hasT/end slot swap 0xB0/0xC0.
- GCC-style multi-insn __asm__ is scheduled per instruction (compiler addiu can land between lq/sq); MW asm{} is a unit.
- Stack slot groups: [named locals] > [inline params/by-value temps] > [inline-fn locals]; default-arg temp moves object into params group. Decl order of plain locals irrelevant.
- register T x __asm__("$4") unsupported in MW.
- bd pragma grid (19 pragmas): none below 16.

## A0540 cParticleSpline_NextFrame (late session)
- l6 C++ draft 154 -> extern "C" direct conversion (`work\nf_c.c`, 154) -> **74 (`work\nf_l.c`)**.
- Conversion: keep class with inline member forwarders to extern "C" callees (by-value return ABI identical:
  a0=ret buf, a1=self); body written directly as extern "C" fn with `self->`. Wrapping an inline member in an
  extern "C" shell costs an inline_depth level and wrecks codegen (396/176).
- Gains: decl order of vars used as MW asm{} operands matters (IsZero `int t; int f; int res; a`, operator-/^
  `o, a, pb`); copy-ctor decl order `refThis; reg; xx` (94->74); ApplyRotS single pointer for load+store
  returning `*a`; `Assign` = operator= without dead xx at the IsZero-true sites; operator*= with two
  pointer operands (d, a) reproduces retail's loop address recomputation; `return cVector(v).ApplyRotS(m)`.
- No gain: tagged copy flavours at every return/copy site, "=r"/"+r"/"=&r" for t, IsZero inits/types,
  named-local perms (current best), splineDelta top-level/scoped/second var, asm form of copy ctor.
- Remaining: NF3 temp slot rotation (sites 1/3), v0/v1 colouring at copy sites, retail `daddu v0,zero,zero`
  at the IsZero copies (ours dead addiu), site-2 lui/addiu scheduling at 0x5a0.
- UPDATE: A0540 now **55 (`work\nf_p.c`, mw38 and mw50)**: 74 -> 72 tagged no-xx copy ctor `cVector(const cVector&, int)`
  at operator^ return + dead `int z = 0;` first in IsZero (reproduces retail `daddu v0,zero,zero` at both IsZero
  sites) -> 65/59 wrapping returns in tagged copies `return cVector(cVector(v, T).ApplyRotS(m), T)` and
  `return cVector(cVector(*this).NormalizeI(), T)` with reg-before-refThis flavours -> 56 with 36 enum-tagged
  flavours (all decl perms of refThis/reg/ps/xx; `enum En{Env}` tag types) -> 55 with splineDelta via
  `static inline cVector SubV(cVector v /*by value*/, const cVector& b)` (param copy = retail's copy order).
- Technique: enum tag types give unlimited copy-ctor flavours; grid flavour x site. Explicit named local copy
  instead of by-value param is much worse (103).
- Remaining A0540 diffs: NF3 site-1 temps slot rotation (ours site1 lowest), GetNormalizedI inner copy
  src/dst order, SubV-return copy dst addiu scheduled late, site-2 lui scheduling, site-3 a2/a3 colouring.

## Session 3 (R212 follow-up)
- **sh 17 -> 10 (`work\sh_g.c`)**: Cross region @0x47c fixed by `CrossR3` (3-deep const-ref wrapper chain
  CrossR3->CrossR2->CrossR->a.Cross(b)) + Cross body decl order `V4 r; V4* o = &r; const V4* a = this; const V4* pb = &b;`
  (oab). CrossR4 same. Remaining only maxd-loop hoisted addresses: ours o=a2,c0=a3,dst=a0,LSq-this=t0. With SubM body
  `o,a,b` hoist ORDER becomes retail's (o first) but colours rotate (this coloured last, retail first): 11.
  No gain: SubM perms x 9 copy flavours x LengthSq this/local (gsh4), LengthSq decl perms/dummy `xx=this`/volatile,
  free/member wrappers on SubM/LengthSq (LSr/LSv/SMr/D1-3/L1-4/LS1-2), named/operator= temp, SubN/SubK/op- forms.
- **bd 16 -> 15 (`work\bd_d.c`)**: free `static inline V operator-(V a /*by value*/, const V& b)` with body
  `V c; const V* p = &a; V* r = &c; const V* q = &b;` + `V n = D + t_Times_P - u_Times_E; self->collisionNormal = n.Normalize();`.
  Marker-nop (`sync`) inside copy ctor proved the 0x3cc copy is the user copy ctor. Remaining: slots sum 0x50/sub 0x60
  swapped vs retail, colouring (retail: q v0, r v1, src a0, dst a1, p a2). No gain: Add variants, Sub wrappers
  (by-value/by-ref depth 1-3 -> 71+; inline_depth 8 limit?), sum as ref/local, copy-ctor flavours, SubI forwarding.
- **sk**: gsk19-23 (SetDir/Ml/As/Dv, Length member depth chains, distance wrappers, Length impls, brad statement forms):
  Len address always coloured t8 (retail t3); any wrapper around Length adds dead addiu. Best stays 20/22.
- **ub**: 16 head statement orders -> 13. The `dsll32 t0; or v1,v1,t0; pcpyld v1` constant expansion is internal.
- Compiler sweep: 3.0b38/b50/b52 identical; all 3.0.1 builds far worse (160-445).
- Technique: depth of wrapper chain (inline expansion event order) + body decl order are independent knobs; grid both.
## 003B17D0 MATCHED -> build\pending\k5\mw38_003B17D0.c (mw38+mw50, zero UNDEF)
- Path 105 -> 32 (pa_m) -> 15 (pa_o) -> 13 (pa_q) -> 0 (pa_r).
- Lerp: `struct W2 { float w[2]; W2(){} W2(float x){ w[0]=x; w[1]=1.0f-w[0]; } };` declared mid-block
  `W2 wt(pos - (float)(int)pos);` (no f0 var, `(int)pos` inline everywhere) -> exact `mov.s f0,f0` sequence.
- Head colouring: DECLARATION ORDER OF UNINITIALISED SCALARS matters: `ClipS *c = st->clip; int f1; float pos;`.
- Speed load in bltz delay slot + `mul.s f20,f0,f1`: `float sp = *(volatile float *)&pr->speed; float rate = (float)n * sp;`
  (non-volatile temp gets copy-propagated and the load sinks).
- Final it<->c/b s-reg swap: iterator struct given a CONSTRUCTOR `BIt(BoneS *q) : p(q) {}` and declared at the
  init point `BIt it(*deleter(bv)); BIt end(... + bv->count);` (instead of declared-at-top + `it.p = ...`) - only
  with loop-local `V4 *k0, *k1` (with shared top k1 it was 31). Aggregate init `= {..}` = 293, plain pointers 57+.
- No gain on the way: rate/speed forms, loop var types/positions, hasT/hasR scope (top/head/body x bool/uchar/int),
  k0/k1 placement grid (41 variants), b reference/const forms, inline DoBone() loop body, LerpQ inline.

## 0039EF90 MATCHED -> build\pending\k5\mw38_0039EF90.c (mw38+mw50, zero UNDEF)
- SubM uninit-decl order `V4 r; const V4* a; V4* o = &r; const V4* pb = &b; a = this;` gave 10->9 (sh_h.c).
- Winner: vsub "compute" ctor `V4(const V4& x, const V4& y, float) { const V4* pb=&y; const V4* a=&x; asm{lqc2 vf1,0(a); lqc2 vf2,0(pb); vsub; sqc2 vf1,0(this)} }`
  (use `this` directly - an `o = this` copy adds a dead addiu), SubM body `V4 r(*this, b, 0.0f); return V4(r, (long)0);`
  where the long copy flavour has `void* xx = this;` (supplies retail's dead addiu 0x1E0).
- Callees renamed per check_match: func_00182270->cCollisionModelMaster_GetData, func_00231EC0->cCollisionModel_Data_GetVertex, func_00380FB0->cTexMan_AddTextureReference.

## Named-local-via-compute-ctor technique (sh/bd/sk) - try this first on vector-temp slot/colour problems
- bd 15->11: SubI `V c(a, b, 0); return V(c, (unsigned char)0);` (uc flavour: `src=&o; xx=this; asm(this,src)`) fixed sum/sub slot swap (bd_g 12),
  then Normalize `V* p=this; asm(p); void* xx=this;` (n8) -> 11 (bd_h.c). Left: copy dst/Normalize ptr a0<->v0 swap and final operator= dst addiu placement.
  No gain: operator= decl variants (5), copy-ctor decl variants (5), statement forms (Unit, n(...), separate Normalize, V& r = ...).
- sk 20->9: ctor k1 `cVector(a,b,float){ p=&a; r=&b; asm{...sqc2 vf1,0(this)} }`, operator- `cVector t(*this, o, 0.0f); return cVector(t, 0);` (sk_f.c).
  Left: Size temp 0x90 vs retail 0xA0 / loop sub temp 0xA0 vs 0x90, and Size bmin/bmax colour. No gain: Size ctor forms (20-21), Size decl perms (21),
  gcc-asm operand orders (9), Size/sub inline wrappers (11+), ScD/operator- copy flavours (9), bsize stmt forms (9+), Length call forms (9+), ctor body perms (9).

## Session 4 (post-R212) - negative results (no new matches beyond pa/sh)
- **sk (9)**: depth theory confirmed: inline-body locals are allocated by inline depth (deeper = lower slot) and vreg
  creation (=> colouring of LICM-hoisted t-regs) follows the same order. Depth-3 sub (op- -> SubT1 -> SubT0, gsk9 d2)
  fixes the Size/sub slot swap exactly but rotates loop t-reg colours -> 33. Deepening /=, Dv, Ml, SetDirR on d2: 29+.
  Default-arg Size (`Size(cVector t = cVector())`) 16-21, tagged Size returns r1-r4 (char = 9), compute-ctor Size 20-21,
  default-arg sub SbD 21+, Size via op- (s1/s2 20, `return cVector(bmax,bmin,0.0f)` 62), inline bmax-bmin in call 20,
  `const cBox& bb` + bb.Size() 9, named `sz` local (32+), member receiver ScM (53+), loop `cSLayer& layer` ref (37).
  Prototype code is identical to retail here (locals fm,tf,pHName,pTName,outter,l,pFName,extension,bsize,blo,bhi,i, layer).
  mw50/mw304 also 9.
- **nf (55)**: NF3 wrapper depth per site (64+13 variants, best 71), tagged inner copy in GetNormalizedI (44 tags, all 63).
  Retail NF3 temp order high->low: site1 sum 0x1B0, site1 copy 0x1A0, site2 sum 0x190, site3 sum 0x180, site3 copy 0x170;
  ours puts site2 highest, site1 lowest.
- **bd (11)**: Normalize variants x SubI copy flavours (110), SubI flavour perm grid (114), operator= perms x Normalize
  n1/n2/n3 (147): best 12 when Normalize has 4 pre-copy addiu's (retail count). Statement forms (pn->, (&n)->, Set, V& m)
  11+. Remaining: copy-dst addiu scheduled after Normalize-p (ours) vs before (retail) => a0/v0 swap.
- **ub (12)**: mask 128-bit/long types (best 12), member `&=`/`|=` forms (25), inline-constant with local t (20+),
  decl-order x init-style x clut-stmt-position grid (54, floor 12), helper SA() forms (12), shared function-scope
  mask/temp vars (56), GS TEX0 bitfield struct (26-28).
- **Session 4 late**: bd MW `asm{}` copy forms (best 11), 120-variant `double`-tag copy-flavour grid (12), Unit()/
  separate-Normalize/extra SubJ depth/`V n(...)` forms (11-83). sk: bbox accessor forms (BBox()/Info()/model.Size(), all 9),
  Size asm operand-order/pointer-local grid (9 each; operand order has NO effect on colouring). ub: u64-param helpers p1-p8
  (12), int128 mask (12), operand-order/`t &= M` forms (12-22), statement perms with named `a` (19+).
- **ub new lead (not yet better than 12)**: inlining the constant into a chained compound assignment
  `t = self->tex01 &= 0xFFF8001FFFFFC000ULL;` reproduces retail's IN-PLACE `or v1,v1,t0; pcpyld v1,zero,v1`
  (a named `m` variable always gives a separate pcpyld dest). With `u64_t a = (u64_t)texAddr;` computed first,
  `ld t1` / `and t0,t1,v1` also match retail (gub9 a_at_at_ca 15; ac0 variants with `c=(u64)clut; t|=(c<<37)` 14).
  Remaining: tex/clut regs (ours t2/a3, retail a3/t2) and lo-mask chain colour. Grids done: ~330 variants of
  named {a,c,c0} x decl/stmt perms x OR order x `&=`/separate store; floor 14.
- **Session 5 (sk)**: Size via `return cVector(bmax,bmin,0.0f)` + ScD(const&) local copy (c_r1 25) puts loop sub t at 0x90 (correct)
  but Size result at 0xF0. ScB(const cBox&, k, v=default, r=default){ s(bmax,bmin,0); v=s; ...} (22) gives ALL slots right
  (s 0xA0, v 0xF0, sub 0x90) but the copy reuses &s (retail recomputes addiu 0xA0) + loop constant vreg order differs.
  Depth-3 sub colour analysis: retail colours (lowest-first) 1.0,B0,C0,D0,copysrc,D0,blo,bhi,subdst; d2 colours the
  sub group first => sub vregs created later. So in retail Size is expanded EARLIER, not sub deeper.
  No gain: MW asm Size forms (9), receiver-position `Size().Scl(k)` member (p3/p4 9, others 18-68), cBox::Half/ScS wrappers (21+),
  placement-new/asm copy forms in ScB (22+). HSet/MSet u64-param helper grid for ub: 21+.
- **Session 6 bd MATCH (mw38+mw50)**: wrap the Normalize call in a reference-returning inline
  `static inline V& Nz1(V& v) { return v.Normalize(); }` and write `self->collisionNormal = Nz1(n);` (one extra inline
  depth => Normalize's ptr vreg created after the copy-dst => colours swap to retail; 11 -> 10). Then Normalize body
  `V* p = this; void* xx = this; asm(...); return *this;` (dead `this` before the asm, not after) + SubI copy tag `0L`
  -> 0. Depth of the operator- chain must stay as-is (SubI2/SubI3 wrappers 15-17, inlined body 21).
- **Session 6 ub**: random head generator work\genub.py (decl-init, register, nested blocks, memory barriers; ~11.5k
  variants over seeds 2-5): floor 11 (work\ub_c.c: m=~0x0007FFE000003FFF, l=tex01, c=clut<<37, t=l&m, store, t|=a, t|=c).
  Pointer/compound `(self->tex01 &= M) | ...` forms 21-28.
- **Session 6 sk (still 9)**: random depth generator work\gensk.py (OPF env: 0 in-class op-, 1 op-->SubT0, 2 op-->SubT1->SubT0,
  3 SubA with depth-2 local; plus Sz/ScD/Sb/Ln/Dv/Ml/SetDir wrapper depths): seed2 6000 mixed floor 9, op=2 floor 19,
  op=3 floor 18, op=1 26. Size wrapper depth (Sz1-Sz6, BxR) has NO effect on Size slot; Dv6 exceeds inline_depth(8).
  Retail slot map: 0x120 bsize, 0x110/0x100 bhi/blo, 0xF0 ScD v, 0xE0 r, 0xD0 op- ret copy, 0xC0/0xB0 Dv/Ml rets,
  0xA0 Size t, 0x90 op- t, 0x80/0x70 op* locals. No gain: const-ref bound Size temp (`const cVector& sz = Size()`, 27+),
  identity ref wrappers Id/Id2/Id3 around Size/ScD/sub operands (9/19/44+), op- out-of-class at 6 file positions and
  Size out-of-class (all 9, definition position irrelevant), loop-local `cSLayer* pl` / top-scope bsize,blo,bhi,i (37-107),
  op- returning ctor directly x by-value Length wrappers Lz/LzC/LzT/cVector(x,0).Length() (12-46).
- **Session 6 ub (still 11)**: genub2.py (+ in-place `z <<= 37`, `t = X; t &= M;`) 1500 variants floor 12; explicit hi/lo
  mask construction (named hi/lo, `m <<= 32`) drops the pcpyld synthesis (15-23); `((u64)hi<<32)|lo` folds (11).
- **Session 6 late (sk 9 -> 5, `work\sk_g.c`)**: `bsize = ScB(outter->model.info->bbox, 0.5f)` with
  `static inline cVector ScB(const cBox& b, float k, cVector v = cVector(), cVector r = cVector()) { cVector s; <gcc asm vsub &s,&b.bmax,&b.bmin>; void* pv = &v; CpG(v, s); r.SetMul(v, k); return cVector(r, 0); }`,
  `CpG(d,s){ d.Cp(s); }` (Cp = copy-ctor asm as member). Fixes the Size/sub slot swap AND copy-address CSE. Only the bmin/bmax a0/v0 colour + trailing nop remain.
  Colour invariant across: asm operand order/pointer locals (84), ScB param kinds (ref/ptr/info/layer/member SizeTo), MW asm (15, breaks copy). Param perms worse.
- **sk MATCH (`work\sk_h.c`)**: from sk_g (5) the bmin/bmax colour was fixed by passing the box halves as SEPARATE ref
  params in (bmax, bmin) order with bmax via an identity ref accessor: `ScB3(Mx(bbox), bbox.bmin, 0.5f)` where
  `Mx(const cBox& b){ return b.bmax; }` (`Bx(bbox).bmax, Bx(bbox).bmin` also works). MW binds inline ref args right-to-left; the
  later-created address vreg takes the in-place colour (v0). Plain `bbox.bmax` folds to info+0x40 (3). Callees renamed to symbol_addrs
  names (Libc_Strcpy, cFileMan_EncodeFilename_charP_cHogFileR_bool, cMemMan_Allocate, EnableIntc, ...). MATCH mw38+mw50, zero UNDEF.
- **Session 7 ub (still 11)**: no-local head forms (`self->tex01 &= M; ...`, 21-25: retail in-place `or v1` but tex01 reload),
  inline helper SA(self,m,a,c) param/arg perms (144, best 23), And/AndR/Sh/Mk helper x stmt-order grid (180, floor 11).
- **Session 7 nf (still 55) - stack-slot model**: frame groups (low->high) = deeper inline levels first; within a group
  slots are reverse creation order. C (0x260+) = temps/ret-temps for calls written in NextFrame's own text + named locals;
  B (0x1D0-0x250) = body locals of calls at expression depth 1 (op= is depth 0, e.g. op* r); A (0x170-0x1C0) = depth 2
  (e.g. wind inner op* r @0xb4); depth >= 3 below A. Ret temps of calls written inside an inline body go to that body's level.
  Retail site1: op+ r and GetNormalized copy both depth 2 (A) while op* r is depth 1 and op+/GN ret temps are in C.
  Ours (NF3(a+b)*d): op+ and copy depth 3 (=> lowest). `(a+b).GetNormalizedI()*d` / GN(a+b) put copy at A but sum stays
  depth 3 (67-71). `NA(a,b)*d` with in-body vadd + `cVector(cVector(r).NormalizeI(),uc)` (h4) gives EXACT retail A slots
  but loses the op+ ret-temp copy via 0x370 (C shifts, 114); adding a Cp(r) ret temp inside NA lands in A (121).
  Also no effect: dummy earlier function using the same inlines (first-use theory rejected); implicit op= (lwc1 copies, 236);
  cUV normalizing ctor / cVector(x).NormalizeI() temp objects go to C (128-184).
- **Session 8 nf 55 -> 14 (`work\nf_q.c`, mw38)**: (1) `cVector()` temp passed as `const cVector& t` arg lands in the C
  ret-temp slot (0x370): `NA(a,b,cVector())` does in-body vadd, `const_cast<cVector&>(t).SetX(r)` (op=-like body with
  `void* xx=this`), `const cVector& tt = t; return cVector(cVector(tt,E8v).NormalizeI(),uc)` -> site1 exact (55->39).
  (2) Same trick for subtraction: `SubT(v,b,cVector())` { `const void* xx=&t;` (restores retail dead addiu) `const cVector& tt=t;
  cVector& w=const_cast<cVector&>(t); w=v;` vsub a=&tt; `cVector& rr=r; return rr;` } for both splineDelta sites (->23).
  (3) site3 `MulT(tm, SubS(springPos[1], springPos[0]))` with `MulT{ const cVector& vv=v; return cVector(cVector(vv,E6v).ApplyRotS(m),uc); }`
  and `SubS(const cVector& v,const cVector& b){ r;o;a=&v;pb=&b; vsub; return cVector(r,(unsigned char)0); }` -> site3 exact (16).
  (4) site2 cross via a named member `Cr2` (same body as op^, any decl order) instead of `operator^` fixes o=a0 (14).
  Remaining (14): site2 0x5a0-0x5d4 only: retail ret-copy dest a1/data a2, op= copy data a1, op^ this v1/pb v0 (lui after
  first sq); ours copies take v0/v1 and op^ gets a2/a1 (lui hoisted). Invariant across: Cr2 decl perms/ret tags (86),
  friend/reversed-this forms (36), SubT2 decl perms (24), Set2 op= bodies (6), ref/ptr pre-binding (18), wrapper depths
  (22), chained `(sd = SubT(..)).Cr2`, scoped re-declared splineDelta (frame +0x10), ref-bound tmp (12, 50+).
- nf SubInto lead (session 8 end): statement-form `SubInto(cVector& d, v, b, const cVector& t, const cVector& u){<SubT body to vsub>; const void* yy=&u; const_cast<cVector&>(u).SetX(r); d=u;}` called as `SubInto(splineDelta, p[2], p[1], cVector(), cVector());` then `if (splineDelta.Cr2(D).IsZero())` scores 21 but gives exact retail op^ colours (this=v1,pb=v0,o=a0) and lui placement; remaining: r lands at B top 0x250 (want 0x200) and copy colours differ. Expression forms (comma, .Cr2 on returned ref, ^ on returned ref, arg-order perms; 48 variants) all 22; nesting SubT inside SubInto blows up to 151. Best remains work\nf_q.c = 14.

- **Session 9 (R214 list) cParticleShatter_Render 0x39B7B0 (5048 B): 695 -> 107, best `rs\n6.c` (mw38=mw50=107).**
  Key wins: (1) drop `#pragma opt_loop_invariants/opt_strength_reduction/opt_rebuildconditionals off` (only
  `opt_rotateloops off` kept) -> size aligns; (2) particle_13.c-style Vif_PutV/Vif_Put/Vif_PadTo/QCopy1/QCopy helpers,
  `Unpack(a,n)` inline; (3) out-of-class `inline Mx::Mx(void* q)` calling cAxisAngle_X/Y/Z/Angle into locals (left-to-right);
  (4) stack layout EXACT via inline-depth rule (locals allocated per nesting-depth pass, source order within a pass):
  UV temp 3 levels deep (UVT->UVT0->UVT1 holding `V tmp`), `operator+` = wrapper around `AddH` (r at depth 3);
  (5) operator= with `void* xx=this; V* dd; const V* ps;` asm lq/sq; (6) two separate `Part* e` (loop / flash block) per DWARF.
  Remaining 107 = register colours only in the 6 vertex blocks: retail AddH region dst a0,&a a2,&b v0,&r v1,t a1 (pt reused),
  ours dst v0,&a a1,&b a0,&r a2,t v1,pt a3; vertex-1 m.t copy (retail 0x350=v1,src/t=v0, Xform copy xx a0,ps a1,dd a2).
  Reading (reverse-creation colouring): in ours AddH's &r/&a/&b vregs are created BEFORE Xform's return copy; retail
  creates &a, then Xform ret copy, then AddH body. Insensitive/worse: V(ptr,int) grid, copy-ctor grid, AddH operand/decl
  grid (36), `=&r` vs `=r` (all 107), decals_4 lq+C-store idiom (120+), compiler struct copies for m.t (127-141),
  Xform forms (*pt, return t, V t(&v,0), pointer m, param swap, Xf wrapper: 107-230), operator+ by-value (107/256),
  named temp (153), m.t inside an XformT (117-133), mw50/mw304 (107/117).
  Next idea: operator+ bodies that bind `a` first (`const V* pa=&a; return AddH(*pa,b)`, pointer AddP(&a,&b)) so &a
  vreg precedes the Xform copy, keeping r at depth 3. Before delivery rename placeholders (func_003820E0 cTexMan_SetActive,
  0025CD10 XLib_NewStrip, 0015C2B0/2A0/290/280 cAxisAngle_X/_Y/_Z/_Angle, 0025CA40 XLib_NextBatchVert, 0025C9D0
  tIRGBA_opAssign_tRGBAR, 0025F220 tVifFloatToInt_short_4_Bias, 00132000 cVector_ctor_float_float_float_float,
  00371200 XLib_DrawStrip, Random_Next Libc_Rand, ...) from config\symbol_addrs.txt.
- Other near misses unchanged this session: nf `work\nf_q.c` 14, ub `work\ub_c.c` 11 (see above).
