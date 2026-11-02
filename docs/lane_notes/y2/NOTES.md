# Y2 NOTES (2026-11-02): cSkeleton_ResetBBoxContributors 0x290610 / FrontEnd_SetNodeSpheres_363A80 0x363A80

## cSkeleton_ResetBBoxContributors (588 B) — best 17 lab lines (was 23 lab / 20 words in n2 rb_best.c)
- Prototype 0x27C1F0 (SCUS_973.97) is byte-identical to retail. Lines: 264 = `currBone = boneList[(*it)->boneIndex]`, 266 = radius+offset copy+dtor+new+ctor.
- KEY: retail is in the less-optimised mode. Adding `if (0) { asm volatile { nop } }` makes non-volatile iterators keep
  retail's sw/lw stack round-trips (volatile members no longer needed); loop 1 matches fully with an `asm volatile { lq; sq }` copy (VA).
- With the trigger, `cBone** pd = DataRef(&boneList); ... *pd` read BEFORE the copy stays UNFOLDED (`addiu v0,s1,32; lw 0(v0)`),
  which n2/X3 could not get. But the scheduler then puts the data chain first instead of 3rd.
- Remaining = loop-2 pre-lq scheduling order: retail itI, itR, &data, itC, &offv, lw data, li a1, s0, *I, *R, *C, idx, lwc1, +16, lq.
- BREAKTHROUGH (v15): volatile iterator member (WrapC `const T** volatile p`) + volatile data read
  (`cBone* data = *DataRefV(&self->boneList)`, DataRefV returns `cBone* volatile*`) + order idx, r, src=&it->offset, data, VA copy
  gives retail's exact loop-2 instruction ORDER (od=0, g/v15C_ddd_v1_IRCDX.c, 19 lab). Left: register colouring only.
  Scheduler model: volatile loads keep source order among themselves; MW pairs ALU/LS ops.
- v18: data access as `AtI(&boneList, idx)` = `{ int o = i*(int)sizeof(cBone); return *(cBone*)((char*)*DataRefV(v) + o); }`
  (offset computed BEFORE the volatile data load) gives retail's data=v0 / mult=v1 / lq=a0 colouring: 10-11 lab (g/v18_ccd_i_IRCDX.c).
  Left: it-load/deref registers (retail itI v1, itR a3, itC a0, &o a2, *I t0).
- v21: `const int& idx = (*it.base())->boneIndex;` + `float r = (*it)->radius;` + src/data/VA as v18 -> **9 lab lines, od 0**
  (g/v21_cac_i2r0c0x0i.c). Left: rotation itI/itR/&o in {v1,a3,a2} (ours a2,v1,a3), *R a2 vs a3.

## Result (end of lane)
- Best draft: build/agents/Y2/rb_best9.c (ResetBBox) and sn_best9.c (same body, FrontEnd_SetNodeSpheres_363A80):
  **9 words by check_match (6 shown +3), exact size, 9 lab lines, both functions.** (n2 rb_best.c was 20 words.)
- Loop 2 body of the draft:
  ```
  const int& idx = (*currContribution.base())->boneIndex;
  float r = (*currContribution)->radius;
  const cVector* src = &(*currContribution.base())->offset;
  cBone& currBone = AtI(&self->boneList, idx);   // AtI: int o = i*sizeof; return *(cBone*)((char*)*DataRefV(v) + o);
  cVector offv; VA(&offv, src); cVector& off = offv;   // VA = asm volatile { lq; sq }
  ```
  plus `if (0) { asm volatile { nop } }` trigger at function top, WrapC iterator member `volatile`, loop 1 copy VA.
  `#pragma opt_rotateloops off` no longer needed.
- Remaining 9: register rotation in the pre-lq block. Retail itI=v1, itR=a3, &offv(sq)=a2, *R=a3; ours itI=a2, itR=v1, &offv=a3, *R=a2.
  Order of every instruction already matches.
- Tried with no change (all 9-11): per-site accessor forms (9 forms x 3 sites, incl. depth-0 `mIterator.p`, RefL/RefLL/StarL depth 2-3),
  idx/radius as refs/pointers/assignments, VA arg order (src,dst), `cVector* pdst=&offv` at 5 positions (11), trigger inside loop/blocks,
  volatile WrapB, opt_rotateloops on/off, `(cVector*)` pointer copy for off.
- Scheduling findings: (1) in trigger mode, an address-of + deref (`*DataRef(&v)`) stays unfolded even before the volatile asm;
  (2) volatile loads keep source order among themselves — that is what puts retail's data load between itC and &offv;
  (3) MW orders the pre-asm block as an ALU/LS pairing; non-volatile loads float to the top (data chain first) regardless of source order;
  (4) computing the index scale `i*sizeof` BEFORE the volatile data read gives retail's data=v0 / mult=v1 colouring.
- Next idea: 2^n grid over which of itI/itR/itC is read through the volatile member vs a non-volatile copy (only the order of the
  three must stay); try `const cVector&` src via a separate inline taking (dst, src) by reference; u1-style per-site toggles on VA.
