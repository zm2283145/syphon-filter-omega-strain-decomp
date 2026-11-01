# P4L notes (2026-11-01): prototype-guided human functions (from P2L's ranking)

Tools (tools/): lab.py (P2L's, + `-n` masks sp offsets), try.sh (diff counts), smap.py (pairs retail/mine sp
slots through an sp-insensitive alignment; `-m` lists my frame), slots.py (P2L), dis.sh, annot.py (proto disasm + .line).

## MW38 inline pass model (verified on 001E7110, exp/e2.c)
- Frame: named locals (decl order, top) > temps created in the main text (incl. return vars of calls whose call
  expression is in main text, by-value temps, ctor temps like `MtxQ(rot)`) > inline-body locals/temps grouped by
  expansion PASS (pass 1 first), source order inside a pass.
- Pass k+1 expands the calls found in bodies expanded at pass k (`W(){ return A(); }` puts A one pass deeper).
- A by-value-returning call in ARGUMENT position of another inline call is deferred one pass (`*p = A()` -> A at
  pass 2; `A(A())` inner at pass 2). Reference-returning calls and object expressions (`f().m()`) are NOT deferred.
- `V x = f()` (init from by-value) is not deferred (RVO into x). `V x(refcall())` calls the user copy ctor.
- So: add pass-through wrappers (`static T M1(a,b){ return M2(a,b); }`) to push a local to retail's pass group.
- vreg colouring follows the same creation order (latest created -> v0/v1/a0 ...).
- s-register colouring is global (Chaitin-like): t33 had params s3..s0/temps s4; materialising `&ip->rot` in a
  local of the transform inline (`const V* q = &ip->rot;`, as retail keeps it in s5/s0 across calls) fixed all
  callee-saved colours (t36, 125 nosp words). Member chains `prev.Inverse().RotM(curr).TransM(curr)` keep `this`
  in an s-reg like retail.

## 001E7110 cHumanCollisionRoutine_Transport_StartOfFrameUpdate (3628 B)
Prototype = retail except field offsets (+0x4C..0x60 before 0x370, anim sys coll +0x70 -> +0xB0); sibling
Transport_EndOfFrameUpdate (humanCollision_17.c) gives types, MtxToPlc asm, GCC-asm mode (dead `void* xx = this`).
Progress: t1 771 -> t32 (all 49 stack slots right) -> t36 (s-regs right) 139 words (lab metric).
- Coordinator: asm unit 0x1E7110-0x1E8760 = Transport_StartOfFrameUpdate + DetectForAndHandleCollisionWithOtherHumans
  (0x1E7F40, 2072 B); a match must be ONE file with both, retail order. Both are P4L's.
- **MATCH** (function alone) 2026-11-01: t_match.c. Keys after slots: Inv2 `V r; GCopy(&r,&q); V* p=&r; ConjM(p);
  return V(*p, 0);` (tagged ctor with dead `void* xx = this`), op*(V,float) `{ V r; return Sc(r, v, s); }` with
  Sc `{ __int128 t = 0; V* d = &r; const V* p = &v; asm{...} return *d; }`, V copy ctor as MW `asm volatile` with
  pd/ps locals, PlcC::operator= rot copy via GCC asm with `V* pd = &rot` first, TB `p->rot = r` (V::operator=),
  VAdd3 via VAdd3S(s, d) wrapper with `const V* ss = s`, `V* pr = &transform.rot; NormM(pr); SetTransform(.., (PlcC*)pr)`
  (retail reuses a1), Yaw float locals `yz, xz`, ZRotFromX locals `b = x.x; a = x.y`.
  Still needed: DetectForAndHandleCollisionWithOtherHumans (same asm unit) in the same file.

## 001E7F40 cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans (2072 B) - same unit as 1E7110
Retail differs a lot from the prototype (adds float timeStep param: rate = min(1, 15*dt), rateHuman = min(1, 22*dt),
player-loop ledge-anchor weight test, IsActive-dependent scale arg). Types/inlines reused from humanCollision_27.c
(DetectForAndHandleCollisionWithHuman, matched). d9.c: frame/slots right after: iterators as struct-returning extern "C"
(`LIt generic_iterator_1_ctor(cLLNode*)`, `DelIt deleter_begin(void*)`) inside LBegin()/LEnd() + converting ctor,
TB box transform one wrapper deeper (TB->TB1->TB0), cMessage 0x50 bytes, OnLedge(cSkaSystem*) returning bool,
IsHuman via IsHumanB/IsHumanU (gives retail's double andi). Left (lab nosp 11): isPlayerHuman andi count + float
constant scheduling (22.0f loaded before first min.s in retail).
- d11.c (best, check_match 10 words, exact size 518): min via `MinF2(float b, float a) { float r = 0.0f;
  asm volatile { .set reorder; min.s r, a, b } return r; }` called `MinF2(15.0f * timeStep, 1.0f)` - this also
  fixes the isPlayerHuman andi count (noreorder asm right after keeps a redundant andi). Remaining: retail keeps
  `mtc1 zero,$f21` (first r = 0) and hoists `lui/mtc1 22.0f` into $f2 above the first min.s; ours drops the first
  zero store and loads 22.0f after. Tried: all 49 combinations of noreorder/reorder/volatile per call (spec40),
  decl orders, local-var asm, wrappers. Next idea: a min form whose r is read (in/out) so r = 0 survives, or a
  GCC-asm variant that keeps both zeros without serialising.
- best/unit_1E7110_best.c = both functions in one file (Transport MATCH, DetectFor 10 words). NOT staged.
- mutate.py ~12 min on d11.c (self-terminating via timeout 800): no improvement from 10 words.
