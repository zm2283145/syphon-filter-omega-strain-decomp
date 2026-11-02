# Y2 final report (2026-11-02)

## cSkeleton_ResetBBoxContributors (0x290610, 588 B) and FrontEnd_SetNodeSpheres_363A80 (0x363A80, 588 B)
- No match. Best: **9 words by check_match, exact size** for BOTH (was 20 words, n2 rb_best.c).
  Drafts: build/agents/Y2/rb_best9.c, build/agents/Y2/sn_best9.c (same body, renamed).
- Retail instruction order in loop 2 is now reproduced exactly; the 9 words are a register rotation
  (itI/itR/&offv in {v1,a3,a2}). Details and negatives in NOTES.md.
- Prototype: early proto has ResetBBoxContributors at 0x27C1F0, byte-identical to retail (lines 264/266); no separate SetNodeSpheres.

## New techniques
1. This function is in MW's less-optimised mode: the approved `if (0) { asm volatile { nop } }` trigger makes the
   iterator stack round-trips appear without volatile, and loop 1 matches with an `asm volatile { lq; sq }` copy.
2. In that mode `*DataRef(&obj)` (address-of then deref through an inline) stays unfolded (`addiu; lw 0`) even before the asm,
   which earlier lanes could not get.
3. Volatile loads keep their source order relative to each other; making the data read volatile
   (`*(T* volatile*)&v->data`) puts it in retail's slot among the volatile iterator loads.
4. Computing the scaled index before the volatile data read (`int o = i*sizeof(T); *(T*)((char*)*pd + o)`) gives the
   data value v0 and the multiply v1, as in retail.
5. Order-distance metric (registers abstracted) + pattern classifier (build/agents/Y2/od.py, cls.py) separate scheduling
   from colouring when searching.

cVisionFxMan_DeactivateFx not started (time).
