# P5L lane notes (session 2026-11-01): mid-size human / interface / collision functions

Tools: g.sh DRAFT [-A] (P3L gd.py on the current target, FUNC/ADDR/SIZE env), slotmap.py (pipe `g.sh -A` into it:
maps my stack slots to retail's by aligned instructions, `*` = mismatch), v/*.py variant files for P3L var.py.
Dossiers: dossier/ (tools/proto/dossier.py). Prototype disasm with .line: P3L tools/pl.sh.

## Ranking (proto vs retail, P3L pcmp normalised diff lines; map.tsv sim in brackets)
- 410E50 cSubtitleFont_Display 88 (0.981), 3E8190 cInterfaceElement_DrawText 120 (0.99),
  192800 cHuman_HandleRunningJumpOffLedge 124 (0.992), 1A1C80 cHuman_GrabLedge 149, 199980 Choke_NextFrame 153,
  2BF4B0 DrawGun 196, 45AE70 cFlashlight_Update 196, 25CDC0 CalculateArcPoints 199, 1E9980 cHumanCollisionRoutine_NextFrame 231,
  3E57B0 231, 3BDA00 SphereSweptRay 245. cInterfaceModel_Render: k8/M20 at 43 words, many dead ends -> skipped.

## 00192800 cHuman_HandleRunningJumpOffLedge (1956 B) - MATCH 13:29 -> build/pending/p5/mw38_00192800.c (rj/final.c)
Progress (gd lines): 299 -> 235 -> 181 -> 113 -> 92 -> 71 -> 62 -> 53 -> 43 -> 34 -> 22 -> 18 -> 16 -> 3 -> 0 (~20 min).
Retail = prototype (human.cc 11899-12070) plus one extra copy in box Center (frame +16).
- Needs `#pragma inline_depth(8)` (without it the vector operators are emitted out of line).
- Stack slots are decided by where each temp is created; the fixes that put every slot right:
  - by-value `Normalized(V v)` (param built in place), `XY(v)` as a separate value-returning inline (its temp lands
    between op*'s and op+'s temps);
  - the n vector `V(-dir.y, dir.x, 0, 0)` as an ARGUMENT, declared as the first parameter so it is built after p
    (`IntersectPlane(n, p, out)` forwarding to `I2(p, n, out)`);
  - the plane-intersection body three inline levels below the call (I3 <- I25 <- I2 <- IntersectPlane): d, e and the
    out-of-line operator temps (cVector_opSub/opMul/opAdd/opAssign are real calls, as in the prototype) become deepest.
- `Center() { V r = (min + max) * 0.5f; return r; }` gives retail's extra copy; `IsEmpty() { return min.x > max.x; }`
  (unsigned char) gives `c.le.s; bc1f; li 1; move zero; andi`.
- Pointer-local orders fixed the addiu orders: op- `pd, pa, pb`; op* `pv` then `pd`; op+ `pd` only;
  Rotate `V r = v; V* p = &r; QRot(p, q); return *p;`; XY `V r = v; V* p = &r; p->z = 0; return *p;`;
  Normalize as a member with a dead `const void* xx = this;` (retail's dead `addiu v0,sp,416`).
- Inline Dot with `float ret = 0.0f;` (retail materialises a dead zero before each inline dot); first dot through
  `const V* pa = &delta;`.
- Max: `float r = 0.0f; asm { max.s r, a, b }`, called as MaxElement(v) with `float x = v.x, y = v.y, z = v.z` locals
  (forces x to load before the first max.s, as retail).
- destinationYAxis by member stores in order z, w, y, x (FPR colouring of the two zeros).
- Subclass test `{ int id = D_004EE6B8; if (gobj->mSubclassId != id) return; }` for `bne v1,a0` (field in v1).
- Message: P3L's MsgB/.dtors_drop idiom + QueueAction wrapper (mDestinationType = 1 sp-relative), queue flag 1.

## 003E8190 cInterfaceElement_DrawText (1592 B) - MATCH 13:47 -> build/pending/p5/mw38_003E8190.c (dt/final.c)
Progress (gd lines): 310 -> 283 -> 207 -> 160 -> 147 -> 130 -> 88 -> 77 -> 67 -> 57 -> 37 -> 18 -> 15 -> 2 -> 0 (~35 min).
Retail = prototype + the same extra Center copy as 192800. Same cVector idioms; the interface_element TU differs in:
- cMatrix is `float m[4][4]` (a `V r[4]` member with a V() ctor emits an empty array-ctor loop).
- V copy ctor `{ const void* xx = this; __int128 t; V* pd = this; const V* ps = &o; asm }` (dead `addiu this`);
  M copy ctor with the same dead xx; M operator= with the asm temps declared first (`__int128 a, b;` then pd/ps).
- MulT copies the scale into a local (`float k = s;` then `mfc1 t, k`): moves the 0.5f lui/mtc1 after the copy.
- op* `V r; const V* pv = &v; MulT(&r, pv, s)`; areaCenter through `0.5f * (a + b)` (free op forwarding to `v * s`);
  `boxCenter * -minScale` needs a separate helper with `V* pd = &r; const V* pv = &v;` (different creation order).
- Box tests: `if (!box->IsValid()) return;` (bool, no materialisation) and Dimensions via
  `unsigned char IsEmpty() { return min.x > max.x; }`.
- 16-float cMatrix ctor (each argument in its own FPR); the 3x4 SetOrientation copy written in order
  3x3 rows first, then the w column (m03, m13, m23) - fixes the store/load interleave.
- Translate: asm on `0x30(this)` with a dead `const void* xx = this;`.
- AppendView: `M* t = &TOP(); MulMM(t, &m);` (TOP address before the scale-matrix zeros); PopView
  `int n = depth; dirty = 1; depth = n - 1;`. gXLib = g_Video, depth D_00538C64, dirty D_00538C68.

## 00410E50 cSubtitleFont_Display - NOT matched, 88 gd lines (sb/s3.c + v/s3_d.c)
- Fresh rebuild from the prototype (GIF_VERTEX macro: line 623/627 is one macro per glyph corner). Structure,
  slots mostly, vis bool chain (`bool vis = a && b && c && d; if (vis)`), hoisted `iy - charH` all right.
- Blocker: retail keeps `addiu gif,gif,16` after each GIF register pair; mw38 folds `gif += 2` into the sd offsets.
  Tried: `*gif++`, GifAdd(unsigned long*&), pointer-to-pair struct, volatile stores, empty asm after the increment,
  char*/int/Q128 casts (stop folding only partly), pragmas opt_strength_reduction/propagation/lifetimes/
  loop_invariants/dead_assignments/unroll. None reproduce it. The prototype (older MW) also does not fold.
- Other: pos vectors should be allocated before both p results (retail pos1 320, pos2 304, p1 288, p2 272).

## 002BF4B0 GuiEquipmentModify_DrawGun (1504 B) - MATCH 13:58 -> build/pending/p5/mw38_002BF4B0.c (dg/dg_final.c)
Progress (gd lines): 136 -> 124 -> 90 -> 32 -> 2 -> 0 (~15 min). Single-function asm unit (0x1BFA90 ManRender is
already C). Copy-paste sibling of cInterfaceElement::DrawText: started from dt/final.c. TU differences:
- No dead `xx` in the V copy ctor, the M copy ctor or Translate (GuiEquipmentModify.cc has none of them).
- Retail added `boxCenter.w = 1.0f` and made boxCenter a NAMED `V boxCenter = box->Center();` (proto: cVector& to a temp).
- Widget rect read through `const float&` accessors (field addresses s1+52.. computed early, loaded later).
- op+ `V r; V* pd = &r; const V* pa = &a; const V* pb = &b; AddM(pd, pa, pb);` (fixes the areaCenter addiu order).
BZ's earlier wip (107) had most structure; the DrawText idioms closed it.

## 003BDA00 cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects - NOT matched, 25 gd lines (ss/s12.c; was 37 in s10.c)
Progress: 152 -> 163 -> 132 -> 96 -> 49 -> 42 -> 37 (exact size, all stack slots right).
- Base = sibling 0x3BD900 (collision_20.c): GCC-asm V copy ctor with dead `void* xx = this`, out-of-line cVector/cBox
  helpers (cVector_opAssign, IsZero, GetNormalized_void, GetZero, ctor_cVectorR, Dot, cBox_Empty/Include/Grow, opAdd).
- Iterator: `struct WrapIt { p; }` temp + `ConstIterator(const WrapIt&)` gives the sw/lw 484/480 temps; compare
  `operator== { cCollisionFace* b = o.p; return p == b; }` gives retail's load/xor order.
- Slot groups solved by inline depth: endPos through `AddW(a, b) { return a + b; }`; M*V through
  `Xf(m, v) { V r(v, 0L); V* p = &r; XfI(p, &m); return *p; }` (XfI wraps the asm); SetSpherePath(V path) ->
  SSP1 -> SSP2 (body) with SetDir()/CalcBBox() one level deeper, out-of-line copy ctor in the GetZero arm
  (`cVector_ctor_cVectorR(&V(), cVector_GetZero())`), op+ with pd/pa/pb pointer locals.
- Left: deltaTransform colour (retail a2, ours a1) and the branch-2 copy chain colours (inner p a1, return dst a0,
  outer src a3/dst v1/p a2); post-loop endPos copy scheduled around `sphereStartPos = unmodifiedStartPos`.
  Tried: Xf body forms (inline asm, pointer orders, tagged copies x9), delta ref placements/ptr/non-const,
  op- forms, copy-ctor body forms, SetSpherePath wrapper variants. Retail end is `return collisionFeature != 0`
  (the proto's division by unmodifiedSpherePathSquared was removed; the float load stays as a dead lwc1).
- Session 2 (15:15): per-site helpers found by search (ss/rs.py random, ss/cd.py coordinate descent): branch 1 via
  `XC3` = `XA3(m, v) { const M* pm = &m; V r(v, 0L); V* p = &r; XfI(p, pm); return *p; }` through a const-ref
  wrapper, inner branch-2 multiply the same, outer `XB4` = by-value wrapper around `{ V r(v, 0L); XfI(&r, &m);
  return r; }` -> delta now a2 and the inner chain matches (37 -> 25). Left: outer copy-in/return registers
  (retail returns through p) and the post-loop endPos block; every single-site change from s12 is worse.

## 0045AE70 cFlashlight_Update (1940 B) - MATCH 14:23 -> build/pending/p5/mw38_0045AE70.c (fl/final.c)
Progress (gd lines): 198 -> 133 -> 70 -> 56 -> 46 -> 34 -> 22 -> 19 -> 12 -> 5 -> 0 (~15 min). Single-function asm unit.
Retail = prototype + `cMatrix mat = matIn;` local copy (inf.bulMat = &mat), `mat.T = mat * V(0,-1.5,0,1)`, and the
equipment-type switch removed (GetEquipmentType call kept, result unused). Tunables are named globals in symbol_addrs
(FlashDist..FlashAcc, FlashMinInner/FlashSqueeze in bss); 0x497A00/0x497A08 (MaxRG/MaxB) as D_ externs.
- In-place xforms: `V off(...); XformM3(&off, &mat, &off); mat.R(3) = off;` and `{ const M* pm = inf.bulMat;
  XformM3(&pos, pm, &pos); }` with XformM3(d, m, s) parameter order (fixes address-register order).
- tBulletCollisionInfo ctor body `noDamage = 0; prevDist = 0.0f; subTarget = -1; scoreHit = 1; b2D(0x2D) = 1;`, then
  bulMat, noDamage = 1, shouldHitTarget, target, penetration, hitRadius, travelDist.
- Bool chain: `bool Bit()`, `bool HasSub() { return Bit() && mSub; }`, InSub as `bool r = false; if (HasSub() &&
  mSub[978]) r = true; return r;` (daddiu/nop without andi, as retail).
- Clamp with one dead zero: `float r = 0.0f; float l = lo; asm { max.s r, v, l; min.s r, r, hi }`.
- Iterators: FIter with copy ctor; Begin/End `FIter b; ctor(&b, RawB(l)); return b;` where RawB is an inline wrapper
  around the struct-returning `FWord std_list_deleter_voidPtr_begin_void_2(void*)` (puts the raw temps one pass deeper).
  Get(): `bool Same() { return p->id == id; } bool Valid() { return !p || Same(); }` -> retail xor/sltiu chain.
- op- pointer order `const V* pa; V* pd; const V* pb` (fixes both the camera and the loop subtract colouring).
- cLight::SetColor: `mColor = tRGBA(c)` (ctor from tRGB with default alpha 0) and `SetInv(V(c.r,c.g,c.b,0))` where
  SetInv has its own `float len = 0.0f` + asm (retail's dead zero lands before the colour loads; that also gives the
  8-byte loop-head nop).

## 001E9980 cHumanCollisionRoutine_NextFrame (1972 B) - MATCH 14:50 -> build/pending/p5/mw38_001E9980.c (cr/final.c)
Progress: 245 -> 161 -> 142 -> 127 -> 101 -> 92 -> 75 -> 16 -> 7 -> 5. Single-function asm unit.
Retail = prototype + offsets (+0x70 after pointMass), cModeSwitch history shift (2 Physical_CopyModeRecord calls + two
`int bits[1]` array-copy loops), reset cleared at the end, mode switch (case order written reversed: 0,12,5,9,10,11),
RootCollection_FindByKey + ActorPhys_AuxiliaryProbe on the sphere centre, `*(V*)(this+0x1E0) = 0`.
- cPointMass inlines: ResetMotion (sq zero force/accel, prev = pos, vel = 0), AddForce(V f) { force += f },
  `AddForce(ImpulseToForce(jump * mass, ts))` with `ImpulseToForce(V impulse, float ts) { const V* pv = &impulse;
  return *pv * (1.0f / ts); }` and op* `{ V r; MulT(&r, &v, s); return r; }`; op+= as AddM(&a, &a, &b).
- Integrate / IntegrateLimited (900 accel clamp) with out-of-line cVector_opSub/opMul/opAdd/opAssign/WSet1/WSet0/
  ctor_cVectorR (the explicit copies are out-of-line `cVector_ctor_cVectorR`), named `maxAccel = opMul(900, &dir)`.
- ratio: `float ts2; float ratio; if (prev != 0) ratio = ts/prev; else ratio = 1.0f; ts2 = ts*ts;` (f23/f24 and the
  CSE of the 1.0f from 1/ts into ratio).
- STACK: Integrate, IntegrateLimited and GetSphereCenter each wrapped TWO extra inline levels (X -> X2 -> X3 body):
  puts their temps below the op* temps (672/656) as retail; one level is not enough. (45 slot lines -> 0.)
- Centre: `&self->GetSphereCenter()` with a ONE-level if/return inline (shared result temp + per-arm `addiu a2`);
  wrapping GetSphereCenter itself defers the address to the jal delay slot. The bone-matrix temp goes deepest by
  wrapping only the bone part: `BonePos1() -> BonePos2() { return func_00133EC0(&GetBoneToWorldMatrix(skel, 0)); }`.
  Found with a micro test in t/h1.c (cc.py): isolate one construct in a 10-line file before grinding variants.

## 0025CDC0 cGrenade_CalculateArcPoints (1544 B) - NOT matched, 11 gd lines (ap/best.c = a14.c)
Progress: 183 -> 161 -> 156 -> 146 -> 95 -> 73 -> 47 -> 37 -> 33 -> 31 -> 25 (~1h). Single-function asm unit.
Retail = prototype + side vector: `D_004F8010 = Cross(fwd, V(0,0,1,1)); start = startPos + side*D_0048AFD8;
D_004F8010 *= D_0048AFA8/3`, an initial push_back of the start point, `V velocity = nPhysics_...(&start, &target,
gravity, angle, D_004F7FE0, 0)` (returns cVector; g_ThrowGravity is g_GameGravity.z, read early into `gravity`).
- Same cPointMass machinery as 1E9980: ctor inline with out-of-line cVector ctors (`cVector_ctor_cVectorR(&pos,
  cVector_ctor_float_float_float_float(&V(), 0,0,0,1))`...), n70 = 0, SetMass(1); ctor body wrapped 2 levels and
  Integrate wrapped 3 levels (temps below the operator temps, as retail).
- fwd: `GetNormalized() const { return NormalizedV(*this); }` with `NormalizedV(V v) { V* p = &v; p->Normalize();
  return *p; }` (by-value helper fixes both the slots and the copy registers); the velocity site needs a tagged
  copy ctor with a dead `xx = this` for the return (`return V(*p, 0)`): retail's dead `addiu v0,sp,480`, and its
  multiply through a separate `MulB(const V& v, float s) { V r; const V* pv = &v; V* pd = &r; ... }` (registers).
- Named `V vec = velocity * timeStep;` (proto local), `prevPos = start - vec`, goingUp through an inline
  `V Disp() const { return pos - prevPos; }` (gives retail's 288 -> 432 copy), PushBack with `const V* pv = &v`.
- Left (14): the Cross-copy/start block schedule (dead paddub position), the SetPosition copy source register, nPhysics arg
  order (retail a1 last), velocity normalise registers. Source-order and copy-ctor-form changes do not move them.
  ap/cd.py (coordinate descent over per-site forms) found `AddB(start, side*K)` with `V* pd = &a; const V* pa = &a;
  const V* pb = &b;` (fixes the SetPosition copy register AND the nPhysics arg order: 14 -> 11). Left: Cross-copy src
  register (retail v0, ours v1, which lets the global's lui hoist) and the gravity multiply dst/src order.
  ap/cd5.py: Cross returning through a tagged copy ctor WITH a dead `xx` (`return V(r, 0)`) fixes the Cross-copy
  colouring (11 -> 6 lines) but leaves the dead addiu (+2 instructions); every no-xx form stays at 11.
  ap/rs.py: random search over per-site helper forms (Cross, +=, *=, gravity multiply): nothing below 14. NB an
  operator call and a named function with the same body do not compile the same (operator form is better here).

## Skipped / not attempted further
- 0x199980 cHuman_Choke_NextFrame: fresh draft ck/c1.c (206; current callee names, B1's is ck/b1.c at 116 with stale
  names). Retail: first block GetNode + out-of-line cSkaAnimEndedMessage ctor/dtor, second block inline msgs (Fall
  style). Blockers: (1) the static cString48N init loop gets strength-reduced and its s[i] load CSE'd in our context
  (the same Init() in N2's cHuman_Fall draft compiles to retail's form; `opt_strength_reduction off` +
  `opt_propagation off` fix the loop but then cf's global reload/zero constants change), (2) RandRange keeps 2^31 in
  f20 and adds 1.0f after Libc_Rand (MW folds every C form tried), (3) this in s1 vs s3.
- 0x1A1C80 cHuman_GrabLedge: unit 0x1A1590-0x1A2470 with cHuman_Fall (5 words, arg schedule); GrabLedge has two
  AddRequest calls -> not started.
- UpperBodyLook_TargetQuat: unit with cAimComponent_NextFrame (11, unsolved ext pairs per N2).
- 0x3E57B0 (Pack, proto 828 B vs retail 1460 B), cInterfaceModel_Render (39-48: byte->float colour FPRs; forms in
  v/rc*.py, v/cdr.py, MW-asm conversion v/rm1.c all no gain), cSubtitleFont_Display (88, gif += 2 folding; retail
  also has `addiu v0,sp,308; swc1 0(v0)` unfolded stores and `move v1,v1` leftovers: some address-folding pass is off
  for this function, but `#pragma peephole off` is not it (adds dsll32/dsra32 everywhere: 127 lines)).

## Techniques that paid off this session (summary)
- Rebuild from the prototype listing + the DrawText/RunningJump idioms; check the dossier type layouts and named
  globals in symbol_addrs (Flash* tunables, g_NegFltMax, g_GameGravity...).
- Inline depth controls stack slots: wrap a body N extra levels to push its temps below others (1E9980, 25CDC0).
- Colouring/arg order is driven by inline structure, not statement order: by-value helper params
  (`GetNormalized() { return NormalizedV(*this); }`), separate per-site helpers (MulB, AddB), tagged copy ctors with a
  dead `xx` where retail has a dead addiu. Coordinate descent over per-site forms (ap/cd*.py, ss/cd.py) finds these.
- Micro tests (t/h1.c with cc.py) isolate one construct quickly (found the one-level if/return centre in 1E9980).
