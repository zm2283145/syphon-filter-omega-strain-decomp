# A1 final report (2026-11-02)

| Function | Addr | Size | Result | Draft |
|---|---|---|---|---|
| cSubtitleFont_Display | 00410E50 | 1712 | not matched; lab 105 -> **45**, check_match size mismatch (+383) -> **35 words at exact size** | build/agents/A1/sf_best45.c |
| SphereSweptRay AccountForMovement... | 003BDA00 | 1304 | not matched; **23 -> 20** check_match words (lab 23 -> 17) | build/agents/A1/ss_best20.c |

Nothing staged.

## cSubtitleFont_Display
- The GIF increment blocker is solved. Each increment is written as `gif = (unsigned long*)((int)gif + 16)` (macro `GIF_NEXT()`)
  and the function has `#pragma opt_lifetimes off`. Together they give retail's `sd 0(s2); sd 8(s2); addiu s2,s2,16` for all six pairs.
  - MW's IRO_PropagateSelfAssignments folds `x = x + c` (and `+=`/`++`) into later store offsets. The cast form is not a self-assignment,
    so it is not folded.
  - Without lifetimes off, the cast versions of gif get different registers. The scheduler then hoists stores above a
    copy-increment (`addiu a1,s2,16`), so retail's per-pair pattern is lost.
  - No other opt_* pragma reproduces it: all 63 `opt_*` names from the compiler binary were swept in a micro harness, and only
    opt_propagation off does, which hoists float constants on the whole function.
- Stack slots fixed: the projection moved into an inline `Project(const cVector& pos, int& sx, int& sy)`. p becomes an inline-body
  local, so the slots are pos1 320, pos2 304, p1 288, p2 272.
- Kern index written as `self->kernStride * idx`, for the mult operand order.
- Left: only the ~38-instruction prologue schedule before the loop (charH, texture, minx..maxy).
  - Every statement/declaration order and every pragma tried has a floor of 45.
  - In the prototype `.line` table, line 593 holds both charH and the texture fetch, which may hint at the original form.

## SphereSweptRay
- Outer modelSpace transform: `XBZ(const M& m, V v) { const V& w = v; return XAZ(m, w); }` with
  `XAZ: V r(v, 0L); XfI(&r, &m); V* p = &r; return *p;`.
- Left: retail shares one pointer register for the transform and the return copy, and has a `nop` after the `b` where ours has
  an extra `addiu`. The post-loop endPos block is unchanged.

## New techniques
- **Self-assignment folding:** to stop MW folding pointer increments into store offsets, write the increment as an int-cast
  assignment (`p = (T*)((int)p + 16)`) and add function-level `#pragma opt_lifetimes off`. Verify in a micro harness first (~0.03 s per variant).
- **Undocumented optimizer pragmas:** `strings mwccps2.exe | grep '^opt_'` lists 63 of them. The compiler's own strings name the passes
  (IRO_PropagateSelfAssignments, IRO_ExpressionPropagation), which helps work out which construct a pass rewrites.
- **Slot order (named locals before inline locals):** to put all the vectors of one kind (pos1, pos2) before the call results (p1, p2),
  move the result's local into an inline helper.
- **Reference in a by-value wrapper:** `XB(const M& m, V v) { const V& w = v; return XA(m, w); }` changes the copy source register.
