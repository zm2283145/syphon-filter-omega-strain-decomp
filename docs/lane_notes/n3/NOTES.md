# N3 notes (r215 session, 2026-11-01): big DWARF-rebuild targets

Tools: build/agents/N3/bd (byte diff vs ROM; CTX=n for context, -a full, RSIZE=0x.. to force retail size),
tools/var.py (substitution-variant batches, 2 parallel), tools/cl.sh (hunk addresses), pdis (prototype disasm by
mangled name/addr), tools/lines.py (proto .line table), dossier/ (tools/proto/dossier.py output).
"pos" = check_match differing words (positional), "seq" = bd sequence-diff lines.

## 001D1740 nIk_TwoLimbIK (4380 B) — start tl_best_tl.c 109 pos / 64 seq
Best: tl/t8.c (see below for current numbers).
- cosTargetAngle (lines 312/315 of ik.icc): split into `float cosTargetAngle = (...)/(...);` then
  `cosTargetAngle = CLAMP4_I(cosTargetAngle, -1.0f, 1.0f);` -> fixes whole float block (109 -> 91).
- SetRotationArc `return *this` -> `return cQuaternion(*this, 0)` with a tagged ctor whose body is the direct
  refThis/reg/s asm copy (not the CopyFrom wrapper): fixes 1D1A6C (91 -> 83).
- operator* return as `return cQuaternion(l0, (short)0)` (tagged direct copy ctor): copy dest materialised early
  like retail (83 pos/42 seq -> 81/26).
- MulTo param order (q1, cc, b) + pointer locals `const cQuaternion* B = b; const cQuaternion* C = cc;` used in the
  asm: delta materialised before this, delta in v1 (all GetRotated-on-local sites) (-> 79/20).
- ACJL uses GetInverseA0/GetInverseA = `return cQuaternion(s).Invert();` (two layers): Invert register reused
  for the return copy; but size 0x1114 (-2 instr) until the dead addius below exist.
- line 400 `new_pivotARot = new_pivotARot_parentRel.GetRotatedO(parentRot)` with MulO = old `return l0;` copy
  -> fixes 1D2140 cluster.
- Remaining (t8): retail has 3 dead `addiu v0,sp,<temp>`: after both jal cQuaternion_GetConjugate (992, 816; the
  temp is then GetRotated's delta) and after the Invert at line 408 (944, temp from GetInverse whose .Rotate is
  called). Line 408 still uses the old GetInverse (reload `addiu a0,336`) instead of reg reuse.
- Dead ends: member operator* (same code), operator* with pointer locals (worse), GetRotated forms
  (`*d * *this`, `delta * Ref()`, ...) globally worse; per-site GetRotated variants worse; extern GetConjugate
  decl variants (ref param, const return, member decl) no change; opt_dead_assignments pragma no effect.
- **MATCH 01:37** -> build/pending/n3/mw38_001D1740.c (acc/ copy). Last two fixes: `GetRotatedX` = GetRotated
  with a dead `{ const void* xx = &delta; }` at the two GetConjugate-call sites (retail's dead `addiu v0,sp,tmp`),
  and line 408 `GetInverseB(pivotARot).Rotate(...)` returning `cQuatR` (derived class whose converting ctor is the
  direct refThis copy: the constructor result gives the dead addiu, and `return cQuaternion(s).Invert()` reuses
  the Invert pointer).

## 001DBB20 InitWeaponSlotIkTargetTable (5532 B) — MATCH 01:40 -> pending/n3/mw38_001DBB20.c
- k4 b4.c (99) + identity as `static GetIdentity() { cQuaternion r(0); return r; }` with `cQuaternion(int)` = sqc2 vf0
  into this (fixes identity/return-temp stack slots: 99 -> 92), then TL's operator* (MulTo(q1,cc,b) + B/C pointer
  locals, SetMul) and PreMultiply/Rotate `*this = q * *this` -> 0. GCC copy ctors kept for cQuatVec/ET parts.

## 0017A640 cGameCamera_UpdateMotion — gc1.c 93 pos / 83 seq (check_match words; k8's "85" was another metric)
- g1: Pt's `V r(*v)` -> tagged ctor via CopyFrom wrapper (`V r(*v, 0)`) -> 87.
- g2: XW calls XformPtQ which passes `&p->rot` straight to QRot (q created one inline level deeper) -> 75/65.
  Model that worked: vregs are created per inline-depth pass (deeper = later) and coloured in reverse creation order
  (latest-created gets v0/v1/a0...). Move an address one wrapper level deeper/shallower to change its colour.
- Tried no gain: copy-ctor/op= form grids (MW asm/CopyFrom), hit/pp placement in block 2, AddV3 decl orders.

## 0039B7B0 cParticleShatter_Render (5048 B) — MATCH 02:03 -> pending/n3/mw38_0039B7B0.c
- k5 n6.c: placeholder callees renamed (tools/calls.py maps every jal reloc to the retail target/name).
- function-scope `static V col(1,1,1,1)` -> externs D_0053BB28 (guard, signed char) / D_0053BB30 with the init
  written out; `float f = 1.0f;` declared BEFORE `D_0053BB28 = 1` gives retail's v0=1/v1=1.0f (118 -> 111).
- operator+ = `{ return AddQ(a, b); }`, AddQ binds `pa = &a` then calls AddS(&r, pa, b) which declares rp/pb:
  fixes the AddH/Xform-return colour block in all 6 vertex blocks (111 -> 34).
- `m.t = e->pos` through 4 pass-through inline levels (SetT4..SetT1): 34 -> 27 (3 levels) -> 0 (4 levels).
- General rule confirmed again: vregs created breadth-first by inline depth, reverse creation order = colour order
  (latest-created gets v0, then v1, a0...). Push an address later by adding wrapper levels; earlier by binding it
  in an outer inline.

## gc continued — best gc/g7.c 38 pos / 28 seq
- g4 (59): Toward's second Sub2 -> Sub2B whose rp/ap/bp are set inside a deeper SubQ helper.
- g5 (43): Dot3 call in Toward through one pass-through wrapper (DotW1).
- g7 (38): block 2 `pl.rot = VV(0x230); pl.pos = *pp;` moved into SP1(pl, t) (pp declared inside).
- Remaining: ToLocal (two calls, same 3 hunks: retail creation order n-dest, r-src, wp, w-dest, in-src, bp; every
  AddV3/Neg3 reshuffle either keeps it or moves w's stack slot) and Fill (pp/dp/VV colours, 3 hunks).

## GuiWeaponDisplay_onRender — best wd/b5.c 65 pos / 66 seq (from 85)
- `M4 m; M4* mp = &m; M4::Copy(mp, &Top());` (m's address created first -> t0) 85 -> 77.
- `const V4* r3 = &m.R(3);` right after it and `V4 t = *r3;` later -> 76.
- area reads (pw/ph/px/py, a.x, a.y stores) moved into RA1/RA2 (two inline levels) -> 65.
- Remaining: Center copy (retail copy of the sum has no dead `this` addiu and is scheduled after paddub; ours is a
  constructor copy with a dead addiu), stack slots 144/160 swapped between Center's scaled temp and rc's temps,
  matrix-constant ctor scheduling 0x880-0x8E0, tail copy colours 0xCDC (wrapping `tr.R(3) = c` deeper reorders but
  breaks data/src coalescing).
- **MATCH 02:15** -> pending/n3/mw38_0017A640.c. Final steps from g7 (38): Fill `*dp = *pp` via ST2/ST1 (dp computed
  inside, two levels) + `V* pp` declared before `const V* q` (pp t0, q v1) -> 32; Neg3's `*out = r` replaced by an
  explicit asm copy in Neg3's own body (r-src created at Neg3's depth) -> 28; AddV3 `Add3(wp, &b)` (b's address
  created inside Add3) -> 16; ToLocal `NegP2(&n, *op)` without the np local (n's address created at the copy) -> 0.
  Unused helpers pruned with tools/prune.py.
- wd c3 (60 pos / 57 seq): `a.z = 200+t.z; b.z = ...;` before `a.w = 0; b.w = 0;` (float const colours) -> 61;
  free `operator*(float, const V4&)` = `{ return v * s; }` (forward to the member) -> stack slots 160/144/128 right
  for Center/rc temps -> 60. Class copy-ctor body forms (GCC/MW asm, decl orders) make no difference at all;
  only the inline depth of a copy changes code.

## 0024B5D0 PlayerInput_Update (17792 B) — best pi/p5.c 72 pos / 44 seq (exact size), from k8 PI_lead_kW6_95.c
(check_match words were ~1860 before because kW6 was 2 instructions short.)
- H2b: `{ const void* xx = &t; } q = *src;` restores retail's dead addiu -> size exact, 83 pos.
- `(s + i)[0xA4] = ...` -> 82; H2b tail `{ const void* xx = &t; } { const long128* s2 = (const long128*)&t; q = *s2; }` -> 81.
- mv-sum (2408): `{ float x, y; x = clampY + z2.x; mv.x = x + z1.x; y = yaw + z2.y; mv.y = y + z1.y; }` -> 74.
- case 5 `unsigned char q1, q2, q3` declared/zeroed in reverse (q3,q2,q1 / q3=0;q2=0;q1=0) -> 72.
- Open: GateOk (retail daddiu: unsigned char result without andi), case-8 bigWalk (`li 1; andi` after the join of
  the two GetZRotationFrom*Axis calls), spd = 0 after ZeroM (constant changes global float colouring), case-5 Set3
  sum scheduling, LimitManualAim float-arg constant order, c.eq.s operand order in the 24-flag loop.
- PI p9 (43 pos / 36 seq): case-8 `hgt = BoundsW8(t, w); bigWalk = w;` with Bounds8 setting `f = 1` in both
  if/else arms (int&) -> 46 (positional drop is mostly re-alignment; retail still has one `li 1; andi` after the
  join, ours duplicates `li` into both arms); GateOk as `unsigned char` with if/return -> daddiu like retail (45);
  FlatSub `VC t = ...; V4* o = &out; V4* p = ...; CpN(o, p);` + IsZero4N through a one-level wrapper -> 43.

## GuiWeaponDisplay_onRender — final best wd/c5.c 43 pos / 40 seq (02:40)
- c4 (57): from mutate m_c3 (register keywords stripped): `1.0f != e->f54` / `0.0f != e->f54` compare operand
  order, r3 placed after `RA2(e, w, h, a);`.
- c5 (43): tail `M4 r = tr;` -> `M4 r; { M4* rp = &r; const M4* sp = &tr; M4::Copy(rp, sp); }` (dst then src
  addresses bound at depth 1, before the preceding `tr.R(3) = c` copy) fixes the 0xCDC-0xD24 colours (-14).
  Binding sp before rp is worse (53); binding only rp gives 56.
- Remaining (all scheduling/colour): Center copy at 0x5F0-0x620 (sum copy src scheduled before paddub in retail);
  rc 0.5f*(a+b) at 0x854-0x870 — retail creation order: p (op* src) earliest, copy dst, copy src, d (op* dest)
  latest; ours has the op+ return-copy src latest. Moving d into a deeper helper (free op* -> MulW -> MulD) gets the
  colours but swaps stack slots 128/144 (x6, 41 pos / 33 seq — kept as wd/x6.c, alternative base);
  matrix-constant (1,-1) mtc1 scheduling 0x88C-0x8E0 follows from the rc block.

## 001D02B0 cHumanIkRoutine_CalculateResultPose — dropped at 127 (r215/r0.c)
- Hoisted switch float constants' colour order did not move under anything tried (macro at depth 0, GetRot forms,
  declaration orders). Over 90 minutes with no progress, so dropped.
