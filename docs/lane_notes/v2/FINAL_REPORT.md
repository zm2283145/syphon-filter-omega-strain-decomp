# V2 final report (2026-11-02)

Nothing staged. Both targets stay at their previous best.

| function | best draft | lab lines | what is left |
|---|---|---|---|
| XLib_DrawLensFlares 0x3781B0 | build/agents/V2/lf_best8.c (= docs/lane_notes/p1l/drafts/lf_best8.c) | 8 | alpha chain/uv colour swap in the cover sprite |
| cMan_ManDMA 0x385D40 | build/agents/V2/md_best11.c (= p1l md_best11.c) | 9 | hoisted faceBlend store position in the loop preheader |

## Findings (details in NOTES.md)
- ManDMA is compiled in MW's less-optimised mode, triggered by the volatile busy-wait asm. Without it the function changes by about 1,000 lines.
- The prototype line table supports best11's faceBlend position (line 5122 has no code, between the else-if and the first continue).
- Preheader hoist order (schedule-off dumps plus marker constants):
  - A def with a `continue` between it and its use is appended last.
  - A def at loop-body level joins the group of named-variable hoists, in source order.
  - A def after the pT3 continues joins the early group of CSE'd and inner-loop hoists, after the 0.0f constant.
  - Single-use outer-loop constants are hoisted in a non-source order.
  - Retail's position, before the pT0 blood-loop constant, cannot be reached by any def that dominates the use.
- A pragma sweep, mw50/mw304, a real member function, and dead `asm volatile` blocks at every position all leave ManDMA at 9.
- LensFlares colouring model:
  - Named locals are coloured before temps, each taking the lowest free register.
  - Retail needs uv coloured as a temp (after the scrH/2048 temps), with the alpha chain coalesced with ga.
  - Every form tried gives one or the other, not both. Exhaustive grids gave: named-chain world 34; uv-temp world 31 (528 variants).
- Pointer-taking / by-value / reordered-parameter inline helpers in the cover block give exactly the same colouring (the u3 pass
  effect did not appear here).

## New technique worth recording
- `ir.sh`: compile a draft with `#pragma schedule off` and dump a block, to see MW's pre-schedule (hoist) order.
- Unique 64-bit marker constants show the order in which MW's LICM hoists from each block. Duplicating the markers shows the
  CSE'd ordering.
- Use these to check whether a target hoist position can be reached at all before searching source forms.

## Memory
Nothing new to save.
