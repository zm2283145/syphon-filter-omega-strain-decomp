# Y1 notes (kN format)

## cGameSound_PlaySound (0x1C8770, 1688 B)
- best draft: build/agents/Y1/ps_best7.c (= p2.c) -- 7 lab lines (6 words), EXACT size 0x698 (was 12 lines / size -0x10 in X3 ps_best12.c)
- fix: vagFile.mHogFile later uses written through a free inline accessor
  `static inline cHogFile* GH(const cFileMan& f) { return f.mHogFile; }` -> `GH(vagFile)`.
  The implicit struct copy reads its fields as `*(&src + off)` (inline-param form); an explicit `vagFile.mHogFile`
  is a direct stack-slot reference and never CSEs with it. Passing the object through an inline reference param
  gives the same tree, so the copy's `addiu s3,sp,0x308` is shared with both later uses and the 2 alignment nops return.
  (A member accessor `vagFile.Hog()` was worse (82), pointer local `vf->mHogFile` gives `lw 152(s3)`.)
- remaining: priority loop SR pointer / fx temp colour swap (retail SR=a2, fx=a1; ours SR=a1, fx=a2).
  Rule: named fx is coloured after the SR temp. An explicit named slot pointer `sl` (r1.c: `sl = self->slots; ...; sl++`)
  gives the right colours (5 lines) but starts at self+48 instead of self (offsets not folded).
  Passing &slots[i].fx to an inline (y3.c) also gives SR=a2 but folds all fx offsets (no fx temp).
- tried (all >= 7): fx decl position grid (function level), register, reference, const, accessor Slot(i), GetFx inline,
  slot pointer + &sl->fx, for/do-while, ++i, comparison orientation, IsVag/Pri helpers (lose SR in inner block), bank test split.

## func_003FD740 (0x3FD740, 768 B) -- MATCH, staged build/pending/y1/mw38_003FD740.c (draft gl_match.c)
- from X3 gl_best33.c (33) in four steps:
  1. continuation byte `b = (base + at)[i] & 0xFF;` (int b): retail's `andi 0xff` after the CSE'd lbu (33 -> 29).
  2. decoder local `q = base + at;` used for the null test and first byte only, loop keeps `(base + at)[i]`:
     MW's strength reduction then rebuilds the loop pointer from a fresh `p + pos` (retail's `addu v1,s2,s3; addiu a1,v1,1`),
     the first-byte branch keeps its empty delay slot, and q/c colour as retail (29 -> 12). Found by noticing
     `#pragma opt_common_subs off` fixed exactly this window (but broke constant sharing elsewhere); the named local
     gives the same effect locally with CSE on.
  3. decl-order grid (grid.py): n, q, v, c, i (12 -> 5); `v = ((1 << (6 - n)) - 1) & c;` operand order (-> 4);
     two-statement accumulate `v <<= 6; v += b & 0x3F;` gives retail's in-place sll (-> 7 with a b/SR swap).
  4. zero test as `if (!(base + at)[i])` (or `unsigned char b`) fixes the b/loop-pointer colours -> 0. check_match MATCH.
- dead trigger / less-optimised mode was NOT the answer (it removes strength reduction).

## PlaySound follow-up
- loop access-form grid (lgrid.py, 1296 combos of direct / inline-ref / accessor forms for the bank, handle and both
  priority reads, no named fx): all >= 24 (without a named fx the inner-block priority read loses strength reduction).
- loop moved into an inline `CheckPri()` (fx an inline-body local): still swapped (7).
- pragma toggles (opt_loop_invariants, opt_rotateloops, opt_strength_reduction(_strict), opt_pulloutconstants,
  opt_moveinvariantsinaddressexpr, opt_docrossconversionofinductionreference, ...): none fixes it.
- mutate.py ~40 min from p2.c: no improvement (6 words).
- next idea: find a form where the induction pointer is a named variable whose start folds to `self` (r1.c has the right
  colours but starts at self+48); or a micro harness of just this loop to search fx/SR colouring.
