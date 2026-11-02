# U3 notes (2026-11-02)

Tools (build/agents/U3/tools/): t.sh (lab normal|nosp), vr.py (named substitution variants, -s prints sp first-use
order retail/mine), cd.py (coordinate descent over knob alternatives), slots.py; m/ = micro harness (m/cc.sh file FUNC).
Lab range CameraCol_Sweep: 0x20D680..0x20DED8.

## 0020D680 CameraCol_Sweep (2136 B) - in progress
- Function: const V& CameraCol_Sweep(CameraCol* self, const V& target). self+0x04 collection (Arr*), +0x10 ext,
  +0x20 rot quat, +0x40/+0x50 base points, +0x60 hit byte, +0x70 result, +0xB0. Local 1-entry SphereList
  (count 0x7A0, items 0x7B0, Sphere = {radius, V offset, bool useOffset, bool useTransform, V scale} 0x40).
  Probe = cCollisionProbe_SphereSweptRay (0x1E0; hit at 0, path 0x80, start 0xF0, bytes 0x110/0x118).
  Thunk signatures from Reset_2: (probe, faceList, radius, .05, .05, 0, radius, start, path, acc=0[, M rot, V scale]).
- Draft history (lab normal diff): cs1 262 -> cs3 167 (op*(float) as `V r(*this,s); return r;` frame 0x7F0)
  -> cs8 (int stores for the static zero) -> cs9 133 (Sphere default ctor `Sphere(float r = 0.0f, V o = Zero())`:
  zero temp slot 0x190 and radius store after the copy) -> cs12 127 (free operator+/operator- = no dead `this`
  addiu pairs; 534 instrs = retail; ALL stack slots = retail) -> cs13 117 (Diff ptr decl order a,c,b)
  -> cs15 70 (asm of Sum/Diff moved into a pointer-taking inline SumA/DiffA: the asm vregs are created one pass
  later than the local, so the previous statement's return copy is coloured first, as in retail) -> cs16 69 (NegA).
- Slot recipe: Scale(v,s){return v*s;} wrapper for the Sphere ctor arg (pass C), Neg wrapper for unary minus (pass B),
  ZeroW() for the ternary else, free op+/op-.
- cs18 24: per-site `AddP/SubP` (Sum/Diff variant `const V* pa = &a; V c; SumA(&c, pa, &b);`) at every site whose
  FIRST operand is a by-value temporary (ternary, start, from-outer, both hit diffs, loop-2 p). Retail colours
  such a temp's address before the result local (a3 vs a2). Named first operands keep plain operator+.
- cs19 22: InitTransformedThunk declared (probe, faceList, start, path, acc, 5 floats, rot, scale) (ABI-identical;
  only evaluation order changes). Exhaustive 792 int/float interleavings: 22 is the floor.
- cs20 = cs_best16.c **16 lab lines, check_match 17 words, 534 instrs, frame and every slot = retail**:
  cVector::Zero() returns `const V&` (ZeroR) and the Sphere default ctor is `Sphere(float r = 0.0f, V o = ZeroR())`.
- Remaining (only): both InitTransformedThunk arg setups are scheduled differently: retail computes `addiu t2,e,48`
  and `lwc1 f12,0(e)` early and `lwc1 f16` last; ours puts all e-based args at the end. Tried (no gain): wrappers
  for the call (w1-w3), M by named local / MQ() by-value helper (adds instrs), e via pointer/ref copies, float local
  for radius, list.items[i] direct, all float/int parameter interleavings.
  Next ideas: different Sphere layout access (e.g. scale passed as `V` by value? radius via member accessor of a
  base class), the real call may be a cCollisionProbe member inline with default args; try `#pragma` scheduling? no.

## 0039A000 WeatherEmitter_Update = cParticleBox::NextFrame (4356 B) - recon only (no draft)
Retail section map (asm/29A000.s; params a0 self->s5, a1 system->sp+0xDC, a2 matrix->s0, a3 localWind->s6,
f12 elapsedTime->f25; frame 0x400, s0-s7/fp + f20-f26 saved):
- 0x39A054 `if (!self->owner(0x104)) return;` (-> 0x39B0B8 epilogue). Identity cMatrix default ctor at sp+0x3C0
  (sqc2 vf0 / qmfc2 / pcpyud / pexcw idiom), then cParticleBase_NextFrame(self, system, matrix, elapsed, localWind).
- 0x39A0A0 `center = matrix.row3` (0x3B0); owner->vcall(+0xE4)(&tmp 0x2D0) [returns V by hidden ptr = owner
  position]; deltaFromOwner = center - tmp (local 0x1B0 -> 0x2E0); distanceFromOwner = |delta| (f20, VU0 vsqrt
  length, mtc1 zero first). Second +0xE4 call (0x2C0): v = pos - self->vF0 (0x1A0 -> 0x3A0 named = owner motion);
  third +0xE4 call (0x2B0): self->vF0 = pos.
- 0x39A1A0 loop i(s0) < definition(0x100)->numChildren(0x180): child = &def->child[i] (0xE0 each at +0x190);
  id = GetEffectID__15cParticleSystemCFRC1(D_0053B540, child); pp = cLList_cParticleDefinitionPtr_opIndex(D_0053B544, id);
  if (*pp && (*pp)->f0C == 0) { fp = *pp; s7 = self->f6C / 6; break; }  (s7/fp start 0; loop in `b cond` form,
  BB-end nops).
- 0x39A250 block = cParticleBox_RequestBlock(self, distanceFromOwner, &self->f6C); sb to sp+0xDB; if (!(u8)block) return.
- 0x39A26C size = self->vE0 (0x390), sizeHalf = size * 0.5f (V*float GCC idiom with paddub zero; 0x190 -> 0x380);
  owner->vcall(+0xE8)(&mat 0x270) [matrix by hidden ptr]; ownerYAxis = mat.row1 (0x370 / 0x180 copies);
  s4 = (int)((float)self->f6C * self->f120); |ownerYAxis| -> f13; Libc_Atan2f(yAxis.z(0x378), len);
  Libc_Tanf(self->f124); fov clamps with max.s/min.s against +-pi/2 (0x3FC90FDB) -> f22/f21;
  two more +0xE4 calls (0x260, 0x250) build f24/f23 = pos.y + 0.5*(f110+f10C) * clamp/(pi/2); f23 = max(f23, 0x3B8-0x388).
- 0x39A454..0x39B0B0 main loop s3 = 0..s4: piece s2 = (self->h(0x108) && h->owner == self) ? h->data + s3*32 : 0;
  if (!piece) continue; if blockType(sp+0xDB) == 1: 3 Libc_Rand placements (0x4F000000 = 2^31 divisor), else
  wrap tests; wind: cWind_GetTurbulence_cVectorR / _float_float_float (0x39A83C/874); floor collision ->
  cParticle_AddChild (0x39AA94); then 3-4 Libc_Rand; second region (0x39AC4C..) with a +0xE4 vcall, Libc_Atan2f
  (0x39AD9C) and another +0xE4 vcall at 0x39AEF4 (per-piece fov test).
- Next step for a successor: write sections S0-S3 first (they are prototype-independent and short), measuring
  with lab.py on 0x39A000..0x39A458 (function will not compile-match beyond that until the loop exists; use a
  stub loop body). Types: cParticleBox layout from types.txt shifted (+0x10 from definition on: definition 0x100,
  owner 0x104, pieceBlockPtr 0x108, near.. 0x10C.., halfFov 0x124?); particle_8.c (Render) has the V4/OpM/OpS idioms
  for this file (MW asm `OpM` vs GCC `OpMZ` with paddub zero).
