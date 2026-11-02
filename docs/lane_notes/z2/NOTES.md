# Z2 NOTES (2026-11-02)

## cSkeleton_ResetBBoxContributors 0x290610 (588 B) / FrontEnd_SetNodeSpheres_363A80 0x363A80
- Start: Y2 rb_best9.c, 9 lab lines.
- Prototype: out-of-line accessors exist in proto (game.cc/human.cc): cSkeletonBBoxContribution::BoneIndex/ContributionPointRadius/
  ContributionPointOffset (returns const cVector&), cBone::GetSkeletonBBoxContribution, cBone_SkeletonBBoxContribution::Reset(float, cVector)
  (by-value cVector; the sp+96 copy is that param) and Clear(). Line 266 is likely
  `currBone.GetSkeletonBBoxContribution().Reset((*it)->ContributionPointRadius(), (*it)->ContributionPointOffset())`.
- Natural Reset(float, cVector-by-value) inline: 19-20 lab (loads folded, radius after the copy if the copy is volatile asm). Dropped.
- Tail form (inline T1..T4, ResetA/B/C helpers, copy helpers) never changes the colouring: only the three iterator reads do.
- Note: Y2's od metric hid one order diff (retail *C before idx); it is a colouring consequence.
- **5 lab (rb_best5.c)**: I via `(*it)` (operator*), R via `it.Get()` (`{ q = mIterator.p; return *q; }`), C via `(*it.base())`.
  Left: itR/*R = a2 vs retail a3, &offv a3 vs a2 (R chain is coloured before &offv; retail after).
- Get2 (`q` and `r` locals) puts itR=a3, &offv=a2 but *R/ *I/idx become t0/t1/a3: 7.
- **MATCH (both)**: build/agents/Z2/rb_match.c, sn_match.c; staged build/pending/z2/mw38_00290610.c, mw38_00363A80.c.
  Cure: the index read as a NAMED pointer local plus a plain int
  (`const T* pi = *it; int idx = pi->boneIndex;`) together with the radius read through an iterator accessor with an inline local
  (`Get() { q = mIterator.p; return *q; }`, optionally via a named `pr`). The named `pi` makes *I/idx coloured after *R, the
  Get() local makes the R chain coloured after &offv. 8 of 140 grid variants (z15.py) hit 0.

## cMemMan_Init_int_uint_uint 0x36B3B0 (end 0x36B630) - unchanged, 7 lab lines (1 is a lab artefact: unmasked `lbu v0,15512(at)`)
- Best draft still docs/lane_notes/k3/drafts/b_36B3B0.c (copy: Z2/mm_base.c). Harness: mm.py (+mm1..mm12.py).
- Residual: retail `sll v0,s0,7; addu v1,v0,s0; lui a2; ...; lui v0` vs ours `sll v1,s0,7; addu v1,v1,s0; lui v0; ...; lui a2`.
- Tried, all 7 (chain always starts in v1): separate `o = pool*sizeof` before the base (int/unsigned, base as local, reversed sum),
  explicit shift chain in one expression (8) and with five named temps (7), operator[] array wrapper `Bins()[pool]`, BinAt inlines
  computing the offset first, volatile base pointer (12), `D_00533CB0 + pool`, `pool*0x818`, unsigned/short casts,
  cMemBin_Allocate wrappers (param order dest-last, member Alloc, AllocP(pool,...)), file arg as local/&D[0]/string literal
  "mem.cc"/__FILE__, size as const&/local copy/!size/<=0, pool param types (unsigned 7, long/ulong 12, short 17, const local 14),
  pool as inline local (14), MemAllocate as a cMemMan member with mBins at +0x18 (73),
  less-optimised trigger inside the inline (no change; in the outer function 143).
- Sensitivity probe (mm8.py): removing the tag line, the init check, the guard, the size check or using pool 1 never changes the
  first-temp register (always v1), so it is not interference with the base `lui v0`. The k3/mv0.c Init_void draft does produce the
  retail Init_int shape (`sll v0; addu v1,v0`, `lui a2` first); there `size` is already in a1 (computed expression), unlike here.
- Next idea: find what in mv0.c's context makes the chain's first temp a fresh vreg (bisect mv0.c toward Init_int's body).
- g/ holds generated variant files (scratch, safe to delete).
