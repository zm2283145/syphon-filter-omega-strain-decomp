# X2 final report (2026-11-02)

## Staged
- WeatherEmitter_Update 0x0039A000 (4356 B) = cParticleBox::NextFrame: **MATCH** (mw38, no UNDEF, no DATA),
  build/pending/x2/func_0039A000.c (source draft build/agents/X2/wu_match.c). Path 154 -> 0 lab lines from W1's
  wu_best.c; details in NOTES.md. Inline asm is VU0/lq/sq/FPU min/max/abs only (commented); no volatile-mode trigger
  needed (the function's GCC asm already puts it in that mode); no register pinning.

## New techniques
1. **Copy propagation of a clamp result**: with a GCC `__asm__ volatile` min/max helper, MW may propagate the asm's
   result variable into the clamped variable's later uses (the `v = r` copy stays as a dead `mov.s`, and the
   variable's saved register moves to r). Writing that one clamp as a plain non-volatile MW `asm { min.s r, a, b }`
   stops it: retail's `min.s f2,f22,f1; mov.s f22,f2`. It is per site; the other clamps stay GCC asm.
2. **MW schedules the instructions of a GCC asm string individually**: `"lq %0..; sq %0.."` can come out with
   other instructions between the lq and the sq. A by-value return of a `cVector&` from an inline whose asm uses a
   pointer local (`cVector& NormalizeR() { cVector* a = this; asm{...}; return *a; }`) makes the return copy reuse
   that pointer register (retail's `lq a1,0(a1)`).
3. Scratch FPR numbering in a float block follows named temporaries: `float dm, half, hr, one, zr` locals fixed the
   alpha block; a constant in a local (`float one = 1.0f`) changes which register holds it.
4. `alpha = expr; alpha = FMin(alpha, b)` (two statements) lets the helper's result register coalesce with the
   variable (retail `mtc1 zero,f22; mul.s f22..; min.s f22,f22,f4`); `alpha = FMin(expr, b)` does not.
5. Variable declaration position decides saved-FPR colours: declaring `alpha` inside the loop body and `bottomZ`
   at its use gave retail's f22/f23/f24 set.
6. A scaled random `RndS(range)` (`s * (rand / (1 + m))`) keeps `range * rnd` as a separate mul.s (not fused into
   madd/msub) with the range as the first operand.
7. Reading a call result's member into a block temporary (`{ float pz = f().z; v = pz + ...; }`) makes it the
   first add.s operand.
8. Per-site helper choice: the same Wrap with `const float&` centre at the x site only; a GCC-asm multiply helper
   (`int t; "=&r"(t) : pr, pa, "f"(s)`) at two `pos += v * s` sites; a pointer local for the minuend at one sub site.
