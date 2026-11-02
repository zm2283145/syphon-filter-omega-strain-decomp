# V1 final report (2026-11-02)

Nothing staged.

- cHuman_HandleDeath (0x18A950): unchanged at 6 lab / 8 words, best draft docs/lane_notes/r3/drafts/hd_best6.c
  (copy: build/agents/V1/hd_best6.c). Hoisted form build/agents/V1/h1.c (11) and natural-temporaries form
  build/agents/V1/e1.c (11, slots/order exact, colours rotated).
- cHuman_NextFrame (0x1B1710): unchanged at 8 lab / 7 words, best draft docs/lane_notes/r4/drafts/nf_best8.c.

New findings (details in NOTES.md):
1. HandleDeath's rotation is reproduced by TailA_L alone (micro harness ~0.2 s). It appears only when an if/else
   diamond follows the hoisted `an` inside `if (out)`, and it disappears when actor is dead after TailA, so the colour
   order is degree-driven (Chaitin optimistic colouring): the hoisted an has one interfering vreg too many.
2. cSkaAnimEndedMessage e1/e2 written as C++ temporaries in the AddRequest call (weak `.dtors_drop` dtor) give retail's
   ctor/dtor order and stack slots exactly; likely the original source shape.
3. Dead `if (0) { use(x); }` blocks do not extend a value's live range (they are removed before register allocation),
   so they cannot be used to add interference.
4. A 2,400-combo knob grid over InstNR/TailA forms (ks.py) found nothing below 11 for the hoisted form.
