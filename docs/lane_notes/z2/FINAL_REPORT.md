# Z2 final report (2026-11-02)

## cSkeleton_ResetBBoxContributors (0x290610, 588 B) and FrontEnd_SetNodeSpheres_363A80 (0x363A80, 588 B): MATCH (both)
- Drafts: build/agents/Z2/rb_match.c, build/agents/Z2/sn_match.c (same body; check_match MATCH, no UNDEF/DATA lines).
- Staged: build/pending/z2/mw38_00290610.c, build/pending/z2/mw38_00363A80.c.
- From Y2's 9-word draft, the last register rotation was fixed by the form of the iterator reads in loop 2:
  ```
  const cSkeletonBBoxContribution* pi = *currContribution;     // named pointer local
  int idx = pi->boneIndex;                                      // plain int, not const int&
  const cSkeletonBBoxContribution* pr = currContribution.Get(); // Get() { q = mIterator.p; return *q; }
  float r = pr->radius;
  const cVector* src = &(*currContribution.base())->offset;
  ```
  Unused helpers were removed; the volatile iterator member, the volatile data-pointer read and the VA lq/sq asm are commented.

## cMemMan_Init_int_uint_uint (0x36B3B0): no change, 7 lab lines (6 real)
- About 70 more variants (see NOTES.md) leave the first temp of the pool*0x818 chain in v1. Not interference with the base address.
  Next: bisect k3's Init_void draft (mv0.c), which gives the retail Init_int chain shape.

## New techniques
1. **Named-local vs accessor-local colouring (z15 grid):** when values from several reads of one iterator come out in rotated
   registers, change how each read is written: a named pointer local (`T* pi = *it;`), an accessor with an inline local
   (`Get() { q = p; return *q; }`), or a direct `*it.base()`. Each form moves that read's temporaries to a different point in the
   colouring order. Instruction order stays the same. 8 of 140 combinations matched; declaration order, the copy-helper form and the
   tail form had no effect.
2. Y2's od.py order metric hides colour-driven order changes (`lw R,0(R)` lines look equal). Use the full register signature of
   the window (Z2/run.py `sig`/`group`) to tell variants apart.
3. Prototype out-of-line accessors for this area (proto 0x1A78F0..0x1A79D0): BoneIndex, ContributionPointRadius,
   ContributionPointOffset (const cVector&), GetSkeletonBBoxContribution, cBone_SkeletonBBoxContribution::Reset(float, cVector)
   and Clear. The natural Reset(float, cVector by value) inline scored 19-20 in this mode, so it was not used.
