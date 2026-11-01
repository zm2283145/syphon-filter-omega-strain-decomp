# P2L notes (2026-11-01): large human / collision / IK functions

Tools: tools/lab.py (mw38 compile + rough diff vs ROM, `-v` diff, `-s` op-order summary for Validate),
tools/var.py (substitution variant batches). "cm" = check_match differing words.

## Ranking (P1 map similarity to prototype)
Validate 1.0 hash-exact; Transport_StartOfFrameUpdate 0.99 hash-regs; UpdateClimbingEdge 0.986;
HandleMoveMessage<0> 0.98; HandleMoveMessage<1> 0.964; CalculateRightWrist(=UpperBody_HandRotation) 0.95;
LeftWrist 0.936; HandleJumpInit 0.925; cHumanCollisionRoutine_ctor 0.905; NextFrame 0.864; Land 0.834.

## 001EDD10 cLedgeValidator_cSingleResult_Validate (3716 B) — best v17.c, cm 111 (lab 58)
Structure fully matched (frame 0xA10, all slots, paddubs, property test, loop, iterator temps, float block).
Keys found:
- 7 static rays = externs D_004F4FF8 (guard) / D_004F5000[7] / D_004F4FE8 (dtor record), explicit guard with
  __construct_array(probe, cCollisionProbe_Ray_defctor, cCollisionProbe_Ray_dtor, 0x70, 7) + __register_global_object(0, func_001EEBB0, D_004F4FE8).
- Ops (MW-only mode, no GCC asm anywhere): op* = `V r; MulT(&r, &v, s); return r;` with MulT MW asm volatile and
  `__int128 t = 0` (gives retail's paddub; absent when the operand is a register, as in retail); op+ =
  `V r; const V* p = &a; AddM(&r, p, &b); return V(r, (short)0);` (tagged copy `lq ps,0(ps)`); neg/cross same tagged form.
- Retail evaluates the ctor args S then D (direct-call order) but the 7 copy temps are allocated pre-order
  (S highest .. D lowest) and the ray temp is below ALL op locals (deepest class). Inline call args are evaluated
  right-to-left, direct call args left-to-right. Only working emulation: comma
  `{ const V* ps,*pd; (ps = Addr(S), pd = Addr(D), SetP2(probe[i], *ps, *pd)); }` with the ray as a local of SetP
  (depth 2). `&(S)` also compiles.
- `float sz = start.z; float pz = point.z; if (sz - k - pz <= D_004A03B0)` fixes FP regs; `k` non-const (f20 save).
- face test `Has(p,0x80) || Has(p,0)` with `unsigned char Has(...) { return p[0] & m; }` gives `andi 0xff; ...; andi v0,zero,0xff`.
- Iterator `Begin/End { ConstIterator t(...); return t; }` gives the 2564/2560 temps; `operator== { return o.p == p; }`
  + `!=` as `!(o == *this)` gives retail's load/xor order.
Remaining (7x identical, ~8 words each): ps (address of the S temp) is defined at S evaluation and holds a1 until
the ctor call; retail re-derives `addiu a1,sp,2480` right before jal, so the add3 return-copy source is a1 in
retail and v1 in ours. Tried: Addr nesting depth, `&(S)`, reversed-param inlines (SetPR, V::Probe member trick,
builder object), by-value params, struct-return ctor declaration (v18: perfect registers but ray temp lands among
function temporaries -> slots off), depth-2 buffer with direct call (v4/v20: buffer pointer kept in s4),
opt_defineargorder / opt_classresults / inline_bottom_up pragmas, GCC-mode no-op asm.
Next idea: a construct that makes a direct call allocate its class temp late (the original is a C++ ctor temp
`probe[0] = cCollisionProbe_Ray(S, D)`), or a way to make MW rematerialise ps.

## 001EB990 cHumanCollisionRoutine_ctor (2084 B) — MATCH 12:35 -> build/pending/p2/mw38_001EB990.c (hc_final.c)
Rebuilt from retail asm (retail layout differs from the prototype before 0x370: +0x50..+0x70 shifts).
Keys:
- Member sub-objects as inline `Init()` members with `T* t = this;` (keeps the sub-object pointer in a register
  like retail: splined motion at +0xA0 in s1, cCollisionFace at +0x100/+0x170, the two DeltaPos functions).
- Placement new adds a null check: use Init() instead.
- Stack slots = depth classes: pm vector temps through SetVF1->SetVF0 (`cVector_ctor_cVectorR(d, cVector_ctor_float_float_float_float(&V(), ...))`),
  static identity through Ident()->Ident0() (q/v locals one level deeper), DeltaPos vectors as `t->n = V(...)` inside Fl/Le::Init
  called from DPM::Init. With these the slot first-use order equals retail exactly (tools/slots.py).
- `slti at` loop tests: goto loop with `if (i <= N - 1) goto loop;` (bone_2.c idiom) + `#pragma opt_unroll_loops off`.
- Loop/copy colouring: fill loops as inline Init members (counter created at depth 1 after the copy vregs); zero fill
  `Init(void* const& z)` keeps 0 in a1; `cArray_FixedSize<int,10>`-like states fill `Init(const unsigned char& v)`
  re-reads D_0048A990 each pass; cQuatVec fill `CpT(&rot) {pd; t; ps}` + V::operator= for pos.
- Plane (0xF0): `Init(V p, const V& n)` called as `Init(UnitQ(), V(0,0,1,0))`; UnitQ = `sqc2 vf0` in a
  `.set noreorder` MW asm volatile + `return *p` (fixes the lq position); Dot via a wrapper whose asm operands are
  local copies `const V* A = a; const V* B = b;` (fixes the n/p addiu order); floats `float x,y,z,k; k = Dot; z=..; y=..; x=..; d = -k`.
- Vtable at +0xA0 is D_004DA3E0 (0x4E0000-23584), not ...4E0.
