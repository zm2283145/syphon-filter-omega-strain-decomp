# A1 notes (2026-11-02)

Tools: pv.sh (pragma variants on sf0.c), m/ micro harness (hd.sh, t.py, mbf.py), sf_tmpl.c + mk.py/bf.py/cd.py (per-site gif increment forms).

## 00410E50 cSubtitleFont_Display (1712 B)
- start: Z3 sf_s3d.c = sf0.c, lab 105.
- Sibling pragmas: neighbours 0x410C20 LoadINI (opt_propagation off) and 0x411500 cMatrix_opMul (peephole/propagation/common_subs off) need
  propagation off, tiny ones need optimization_level 1 etc. On Display, whole-function: level 3 = 84, prop off = 239, prop+LICM off 296,
  prop+CSE off 320, level 1 = 458, level 2 = 457. Float constants (128/16/1.0f, 1.0f<<32 RGBAQ) hoist into FPRs/stack under prop off.
- Micro (m/g.c): INT-CAST increments `gif = (unsigned long*)((int)gif + 16)` stop folding of the NEXT pair; pattern (cast, cast, plain)
  for the three pairs gives exactly retail's `sd 0; sd 8; addiu s2,s2,16` x3 in the micro loop.
- Full function: per-site forms A0..B2 (cast=1): (1,1,0,0,0,0) = 84 (vertex 1 exact; its last increment folds into vertex 2).
- KEY FIX (gif): every increment written as a cast `gif = (unsigned long*)((int)gif + 16)` (not a self-assignment, so MW's
  IRO_PropagateSelfAssignments does not fold it) PLUS function-level `#pragma opt_lifetimes off` (keeps all gif versions in s2,
  so the scheduler cannot hoist stores above a copy-increment). Micro and full function: all 6 pairs exactly retail.
- Slots fix: screen projection moved into an inline `Project(const cVector& pos, int& sx, int& sy)` (p becomes an inline-body
  local -> pos1 320, pos2 304, p1 288, p2 272 as retail). 105 -> 93 alone.
- kern index `self->kernStride * idx` (mult operand order).
- Result: sflt.c 56, then prologue assignment order (miny first) sf45.c = 45 (sf_best.c). Only the prologue schedule differs.
- opt_dead_assignments off on top: 43/41 but adds an andi in the bool chain.
- Clean best draft: sf_best45.c (GIF_NEXT() macro + opt_lifetimes off + Project inline + miny-first prologue order):
  lab 45 at exact size (428/428), check_match 35 words (was size mismatch, +383). ALL remaining lines are the ~38-insn
  prologue before the loop (charH / texture / minx..maxy schedule; retail starts with the two lbu of charH and puts
  `sub.s f20 = iy - charH` mid-block, ours puts the texture chain first and the LICM'd sub last).
- Prologue tried: 8 statement forms (tex local, cast forms, operand orders) - no change; greedy + 4 random-restart swap
  searches over the 8 prologue assignment orders: floor 45 (miny first); declaration order has no effect under
  lifetimes off; all 63 opt_* pragmas + peephole/schedule on top: only opt_dead_assignments off helps (43/41) but adds an
  andi in the vis bool chain. A named `top = iy - charH` local right after charH moves the charH chain early (48) but
  recolours FPRs - suggests retail's hoisted temp sits right after charH in the IR.
- Prototype .line: line 593 holds BOTH the charH lbu/mult/cvt and the texture fetch (one source line), 594 imageW, 595 imageH,
  598-601 minx..maxy (the LICM'd addiu s7/s8 land on 601).
- Next idea: find the one-line 593 form (inline accessor returning charH while fetching the texture? texture fetch as an
  argument?), or a statement that makes the `iy - charH` temp appear right after charH without a named local.

## 003BDA00 SphereSweptRay AccountForMovement (1304 B)
- start p5l/Z3 ss_s12.c = ss0.c: 23 words.
- New outer (modelSpace) helper: `XAZ(m, const V& v) { V r(v, 0L); XfI(&r, &m); V* p = &r; return *p; }` wrapped as
  `XBZ(const M& m, V v) { const V& w = v; return XAZ(m, w); }` -> 20 words (ss_best20.c), lab 17. The `const V& w = v`
  reference in the by-value wrapper fixes the r-copy src register (a3). 42 of 96 tag/wrapper/return variants tie at 20.
- Left: r-copy dst / transform pointer swapped (retail dst v1, p a2 shared by transform AND return copy), the extra
  `addiu v1,sp,240` vs retail's `nop` after `b`, and the post-loop endPos block (unchanged).
- p-before-transform bodies (`V* p = &r; XfI(p,&m); return *p;`) x 4 wrappers x 8 tags: 24-36 (worse).
