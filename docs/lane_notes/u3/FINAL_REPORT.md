# U3 final report (2026-11-02)

Nothing staged (no full match).

## CameraCol_Sweep 0x20D680 (2136 B): new draft, 16 lab lines / 17 check_match words
- Best draft: build/agents/U3/cs_best16.c (= cs20.c). 534 instructions = retail, frame 0x7F0 and every stack slot
  identical to retail. Only the argument set-up scheduling of the two ColQuery_InitTransformedThunk calls differs
  (retail computes `addiu t2,e,48` / `lwc1 f12,0(e)` early and `lwc1 f16` last).
- Reconstructed semantics, types and every recipe step are in NOTES.md (draft history cs1 262 -> cs20 16).
- Reusable findings for this mode:
  1. Free `operator+/-(const V&, const V&)` instead of member operators: a member operator on a by-value temp leaves
     two dead `addiu` of the temp per site.
  2. Moving each VU0 asm into a pointer-taking inline (`Sum(a,b) { V c; SumA(&c,&a,&b); return c; }`) creates the
     asm's address vregs one pass later than the local, so the previous statement's return copy is coloured first
     (117 -> 70).
  3. When the FIRST operand is a by-value temporary, retail colours its address before the result local:
     `SumP(a,b) { const V* pa = &a; V c; SumA(&c, pa, &b); return c; }` at exactly those sites (70 -> 24).
  4. cVector::Zero() returning `const V&` plus a default-argument ctor `Sphere(float r = 0.0f, V o = ZeroR())`
     reproduces the static-zero copy into a param slot and the radius store after it.
  5. tools/workflow/mutate.py produced 0 variants on this C++ draft.

## WeatherEmitter_Update 0x39A000 (4356 B): recon only
- Retail section map with params, vcalls, loop structure and offsets is in NOTES.md, ready for a successor to
  write S0-S3 (0x39A000..0x39A458) first.
