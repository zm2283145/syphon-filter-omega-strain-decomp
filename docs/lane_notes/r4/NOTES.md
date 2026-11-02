# R4 notes (2026-11-01 late night)

Tools: grid.py (base.c outdir FUNC lo hi variants.py; VARIANTS = [(name, [(old,new),...])]; lab score, 2 jobs).
Variant definitions are v*.py (HandleDeath) and w*.py (NextFrame); outputs in g*/ and n*/.

## 001B1710 cHuman_NextFrame - 18 -> 8 lab (nf_best8.c; check_match 7 words: 0x874,0x884,0x888,0x9a8,0x9ac,0x9b4 +1)
- FIXED the FxHdl::IsValid cluster (both particle-loop sites):
  `inline int FxHdl::IsValid() { unsigned char ok = 1; if (!((obj != 0) ^ 1)) { int os = *(int*)((char*)obj + 0xC); if (!SameNV(os, serial)) ok = 0; } return ok; }`
  Two parts: (1) the null test written inline instead of `IsNullNV(obj)`: the inline's named parameter p was
  coloured after the temps (p3l rule), which put obj in a0 and base in v1; inline, obj is a temp (v1) and base
  `this` a0 like retail (w1 grid: 18 -> 12). (2) R3's z1 `int os = obj->serial;` nested-if form then fixes the load
  order (obj->serial before serial) (w2: 12 -> 8). Other compare forms (SameR/const-ref/DiffR/`!=`) stay 12-18.
- Remaining:
  1. Dying r in the loop (`self->remote && self->b326A && !Dying(self)`): retail a2, ours a0 (4 lines).
  2. Loop IsHuman: retail `lw v0,88(s1) ... jalr t9; move a0,v0`, ours `lw a0,88(s1) ... nop` (5 lines).
     This sequence is UNIQUE in the whole retail binary (searched all `lw v0,N(sX); beqz v0; lw t9,0(v0); ...
     jalr t9; move a0,v0`), and the prototype 0x1A9540 has it too (line 2143) while its Damage block has no Dying
     test, so it is independent of cluster 1.
  3. lw -24016(at): lab masking artefact only (check_match shows 6+1 words).
- Tried without effect on clusters 1-2 (all stay 8): Dying forms at the loop site only (IsDS(unsigned short/uchar/int),
  bool/uchar/int r, int/ushort stance, wrapper) (w3, 14); Damage-block shapes (src inline/pre-declared, nested if,
  `bool d = Dying(self)`) (w4); replacing the Damage block body entirely (w5: r stays a0, so r's colour does not
  depend on code after it); 13 IsHuman forms (CSE `a->ctrl && a->ctrl->IsHuman()`, const-ref param, pointer
  locals, `(char*)p + 0`, getter CtlOf, extra wrapper depth, reference) (w6); wrapping the loop / iteration /
  fire body / Dying block / IsHuman block in inline functions (w7); remote/b326A getters incl. pointer-local
  getters (w8, 35 combos).
- Next idea: both clusters avoid a0 in retail. Look for a value that is in a0 in IR around the loop's fire branch
  (e.g. something that MW keeps live but later removes), or a different class for the loop-site controller
  (cGobjController derived class, static_cast) that creates a copy for `this`.

## 0018A950 cHuman_HandleDeath - unchanged, 6 lab (R3 hd_best6.c; check_match 8 words)
- Retail InstNR: an (s3) computed before the cSkaPlaybackGroupId ctor, GetInstruction s1 (= ps's register),
  GetAnimCheckpoints s0 (= TailA's x/px register). Every hoisted form gives an s0 / GAC s1 / GI s3 (11 lab).
  The prototype (0x187080, HandleDeath__6cHuman..., 0x1884a0) has exactly retail's code and colours.
- Grids on the hoisted form, all 11 (or worse): 6 an forms x 7 declaration positions incl. Install_L's
  `Sys_L* sys = &a->sys; Anim_L* an = &sys->anim;` (v1, 49 variants); dead pre-ctor uses for CSE (removed, v3);
  An_L wrappers 1-6 deep x 3 styles (v4); C++ Y object with inline ctor, ctor wrappers, an returned from a
  ctor wrapper (v5); an inside the ctor's argument list / wrapper params (v6); named md/pp/g0 getter locals in all
  orders (v7: best 13 with `signed char md`); AnimM::InstNR member function with this = an (v8); stores moved
  into InstNR around an (v11); sel as reference/macro (v12); GI/GC/GD wrapper depth grid 4x4x3 (v13: GC wrapper
  10 = GI fixed, an/GAC still swapped); no named an, CSE spelling (v14: 10, folded offsets); const/register/
  reference an (v15).
- Diagnostics (v9, v10): an gets s3 only when its definition comes straight after a call AND no call lies between
  the definition and GetAnim (non-hoisted form, or no y ctor with the ps stores moved before the checkpoint ctor).
  Any store between the previous call and an's def, or a call between def and use, gives s0. In those s3 cases
  the first an->model load is also folded to lw 12020(s2), so retail (unfolded lw 0(s3) + s3) fits neither
  group. Looks like a Chaitin simplify-order effect (an significant vs trivially colourable), but no source
  lever found.
- Next idea: something outside InstNR that lowers an's degree by one (a vreg in TailA/HandleDeath live across this
  region in ours but not in retail), e.g. look at s4/s6/s7 users around 0x18BC00-0x18BEC0.
