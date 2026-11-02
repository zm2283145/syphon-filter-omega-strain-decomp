# W1 final report (2026-11-02)

Nothing staged (no full match).

## WeatherEmitter_Update 0x0039A000 (4356 B) = cParticleBox::NextFrame: first full draft
- Best draft: build/agents/W1/wu_best.c (= w14.c). **Lab 154 lines (nosp 151), check_match 153 words,
  1089 = 1089 instructions, frame 0x400 and every stack slot identical to retail.**
  Lab: `.venv/bin/python build/agents/P4L/tools/lab.py build/agents/W1/wu_best.c WeatherEmitter_Update 0x39A000 0x39B110`
- Full C reconstruction of the retail function (U3 section map plus the main-loop decode: blockType==1 placement, wrap
  tests with radius from the child definition, floor-collision AddChild with the identity matrix's row3, rand
  re-placement flags, child region A alpha with owner-motion compensation, region B distance alpha).
- Remaining: saved-FPR colouring around the FOV clamps (~40 lines), per-site vector copy register order (~45 lines),
  plus a few operand-order/scheduling spots. Details and dead ends in NOTES.md.

## Reusable findings
1. A 1-byte enum return (`#pragma enumsalwaysint off`, enum {NONE, NEW, OLD}) tested as `x == NONE` gives retail's
   `andi v1,v0,0xff; beqz v1; sb v0,slot(sp)` and packs the spill next to another spilled param (frame -16).
   `!x` gives `sb; lb` instead.
2. Inline helpers that take `const V&` and copy inside (`Unit`, `LenXY`) put the copy in the inline-body slot region;
   taking `V` by value makes it a main-text temp. This alone aligned every stack slot here.
3. `float m = 2147483648.0f; return s * ((float)rand() / (1.0f + m));` keeps retail's runtime `1.0f + 2^31` add
   (a literal expression is folded); passing the scale as an inline argument loads it before the call.
4. An identity-matrix ctor must be `asm volatile {}` for retail's re-materialised call arguments after it.
5. Splitting `(1 - |d|/h) * Max(...)` into `alpha = 1 - FAbs(..)/hr; alpha *= FMax(..)` reproduced retail's schedule.
