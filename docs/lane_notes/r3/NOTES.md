# R3 notes (2026-11-01 night)

Tools: t.sh (lab diff for cHuman_NextFrame 0x1B1710-0x1B2670, full + `-n` sp-masked), var.py (literal substitutions).
Note: the function ends at 0x1B2670 (0xF60 bytes), not 0x1B2650.

## 0018A950 cHuman_HandleDeath - 21 -> 6 lab (hd_best6.c = ta2.c; check_match 8 words, one cluster)
- Base R1 hd_best21.c. Keys:
  1. Drop the function-level `#pragma opt_common_subs off` (R1 said it was needed, 28 without): with CSE on,
     `px = &x` is value-numbered to the checkpoint ctor's `this` register, which gives retail's `move s0,s3`
     in TailC (same mechanism as q4's Land `move s3,s2`). The dead nop after `b` in the next RateF follows.
  2. Checkpoints as a C++ class with Land's ctor `XC() { XC* t = this; t->kind = 0; ctor(t->pairs); ctor(t->tail); }`
     and `void AddC(int i, unsigned char id, void* a, unsigned char k) { Pair_L* p = &pairs[i]; p->id = id; p->a = a; kind = k; }`
     (the andi happens inside the inline after p, which gives retail's pp/id colours).
  3. TailC: `x.AddC(4, k0, actor, 1); unsigned char one = 1; px = &x; px->AddC(5, k1, actor, one); px->AddC(6, k1, actor, one);`
     (literal 1 first, then `one`: k0' a0 / one v1 like retail) -> TailC exact.
  4. TailA (old P56_L): `XC x; ... x.AddC(5, k1, actor, 1); unsigned char one = 1; px = &x; px->AddC(6, k1, actor, one);`
     -> P56 cluster exact. NmI_L uses the plain NAME_COPY3 loop (no `.set reorder`) under CSE-on.
- Remaining (6 lab): InstNR_L computes `an` (s3 = &actor->sys.anim, two addiu) BEFORE the
  cSkaPlaybackGroupId ctor in retail; ours after. Hoisting it (tb1.c, 11) fixes the schedule but rotates
  s-regs (an s0 / GetInstruction s3 / GetAnimCheckpoints s1 vs retail s3/s1/s0). Tried: an as inline param
  (tc1-3, 10-11), 42 decl/assign orders (g7, g8: named getter locals worse 17), comma/py/sy forms (td1-6, 11-15).
  Also: An_L getter shapes (te/tf 1-5), getter wrappers GI_L/GC_L/GD_L/Req_L (th1-3, ti1-3: GC_L wrapper fixes
  GetInstruction s1 but an/GetAC stay swapped, 10), y ctor inside the call args via YI_L (tk1-2, 15), an declared and
  set in TailA at 3 points x 5 decl positions (g9, 21-25), px kept live (tj1-2, worse).
- Next idea: find what makes MW colour `an` last among the three s-regs while computed early (retail an does not
  reuse px's s0 although px is dead; maybe an's IR def precedes the ckpt ctor and is rematerialised after it).

## 001B1710 cHuman_NextFrame - in progress
- Best: nf_best18.c (= nf14.c, 18 lab, check_match 17 words). First draft nf1.c was 154.
- Later steps: Blend body pushed one pass deeper via `Blend(...) { Blend0(...); }` (frame now exact: p > q > v);
  `{ unsigned char v = self->b33A5; Net* n = self->net; n->b35 = v; }`; flashlight compare
  `if (FlashOn(self) != NetFlash(self))` with `NetFlash(H* a) { Net* n = a->net; return n->flash; }` (432-variant
  grid g4; a pointer local inside a tiny getter is what shifts the colours).
- Retail is in the less-optimised mode naturally: the vector Length() GCC `__asm__ volatile` (VU0 vsqrt) is in the
  body, so no dead trigger is needed. Prototype 0x1A9540 (SCUS_973.97) is much closer than p8l thought: the
  multiplayer front part is already there (lines 1957-2073); retail changes: gun-hand block uses calls
  (LerpAndNormalize/Vec4_Lerp/Math_Clampf), Actor_UpdateAnimationState instead of Motion_NextFrame, Actor_Ignite
  for effect 0, fireCount++ moved after the loop with a GlowDown else, WeaponPickup test inverted, flags bits 30/31.
- Steps that worked:
  - messages as C++ classes (MsgB/MsgI/MsgBool/MsgInt with human_17's weak .dtors_drop dtors) and an inline
    `Post(const MsgB& m, to, p) { ((MsgB&)m).kind = 1; Queue((void*)&m, to, p); }` (the kind store goes via sp);
    MsgBool as a temporary in Post (154 -> ~120).
  - Compare colouring: `int nhp = (int)net->hp; if ((int)health != nhp)` and `{ unsigned char w = net->b35; if (b33A5 != w) b33A5 = w; }`.
  - NetBit inline with a local: `bool r = (flags & m) != 0; return r;` keeps retail's sltu + the dead nop placement.
  - `{ Net* n = self->net; n->b35 = self->b33A5; }`, `Net* n = self->net; if (n) { n->time = ...` (s0).
  - Point copy via pointer: `V p = v; V* t = &p; t->w = 1.0f; return *t;` (t0 pointer like retail).
  - Gun block as inline `Att::Blend(const V& q, const V& p, float dt)` called
    `self->att->Blend(cMan_GetGun2ndHandOrient(man), Point(cMan_GetGun2ndHand(man)), timeStep)` with `void* man`
    local: right-to-left arg evaluation gives retail's hand-then-orient order and frame order orient > hand.
    opAssign declared taking `const V&` so the Lerp results are temps. Shape() passed as `const V&` temp.
  - LerpAndNormalize declared (const V&, const V&, float) (scheduling of mov.s f12 into the delay slot).
  - `{ void* man = self->man; cFlashlight_Update(flash, dt, cMan_GetGunBarrelMatrix(man, 7)); }` (a1 before a0).
  - Hdl(H* a) ctor: `obj = a; serial = -1; int m; serial = *(a ? &a->serial : (m = -1, &m));` gives retail's
    temp-only-in-the-else-arm sequence (sw -1 to 0x33C, addiu v0,sp,0x33C, lw).
- Remaining (nf14 = nf_best18.c): FxHdl::IsValid base/obj colours (2 sites x5), Dying r a2 (4), IsHuman ctrl v0 +
  `move a0,v0` (5). Further negatives on nf14: FxHdl grids g2 (54: return/ok types, Get forms, SameNV order) and
  g5 (45: this/obj pointer locals, Eff accessor, EffGet), forced obj->serial-first order (z1/z3 fix the load order
  but not the colours), IsValid folded into Get (za/zb, worse); Dying grid g3 (54) and pointer-local/StanceOf
  forms (dy1-4); IsHuman: inline member wrapper, getter locals, dead `if (0)` uses (dc1-3), dd1-4.
- Older remaining list (nf11): flashlight compare colours/operand order (~12), FxHdl::IsValid base/obj colours in the
  particle loop (2x6), Dying r in a2 (4), IsHuman in loop ctrl in v0 + `move a0,v0` (6), Point local p frame
  slot below q/v (6 sp), `net->b35 = b33A5` load order (2), reloc artefact lw -24016(at) (1, lab masking only).
- Tried without effect: IsHuman variants (param copy, getter, ref param, local copy); FxHdl variants (field
  serial, swapped SameNV, local obj, operator[] (worse, 61), wrappers); Dying variants (order, nested ifs,
  wrapper FireDmg/Attacker inline); pass-through wrappers on Point/GetGun2ndHand (no frame change); Point by
  value (worse); P class ctor (worse); function-scope named locals collisionModelList/i/pctOn (no change).
- mutate.py on nf14 (mut2.c): 7004 variants, best 17 words (no gain).
