# X2 notes (2026-11-02)

## 0039A000 WeatherEmitter_Update = cParticleBox::NextFrame (4356 B) — MATCH
- Function: WeatherEmitter_Update. Best draft: build/agents/X2/wu_match.c (= final.c). check_match mw38: MATCH,
  no UNDEF, no DATA. Started from W1 wu_best.c (lab 154).
- Lab: `.venv/bin/python build/agents/P4L/tools/lab.py <draft> WeatherEmitter_Update 0x39A000 0x39B110`
- Tools here: sbs.sh (side by side retail/mine by instruction index), try_.py (variant + lab from python),
  srch.py/gen.py (per-site copy ctor greedy over the xt.c template), ae.py (+= / * per-site forms, no gain),
  c*/g1/h1/d*/z*/w*/al*/rz* scripts (the grids below), m/ micro harness (t2.c, e*.py).

### Path (lab lines)
- 154 -> 143: clamp via reference helpers moved pitch/bottom to retail's registers (later superseded).
- 139: predeclared bottomZ (later superseded).
- 118: per-site copy ctor (srch.py): center = `const cVector* s = &o; void* xx = this; lq/sq` (tag CopySrcFirst);
  the Unit() input copies = `void* xx = this; CpP(this, &o)` (one level deeper, tag CopyNested).
- 89: Unit returns `v.NormalizeR()` (Normalize returning `*a` by reference). The return copy reuses the Normalize
  pointer register, and MW schedules the lq and sq of a GCC asm string apart (it schedules the instructions of an
  `__asm__ volatile` string individually). MulW at the Unit sites: `const void* xx = &a; OpMZ3(&r, &a, s)` with
  the asm inputs listed pa, pr.
- 83: ownerMotion via SubP (`const cVector* p = &a;` before OpS).
- 77: **top's last clamp as a plain MW asm `asm { min.s r, a, b }` (non-volatile)** with the other clamps unchanged
  (`top = FMax(top, t); top = HMin(top, HALF_PI);`). With the GCC-asm helper the copy `top = r` was propagated into
  the later uses of top (they read r's register, the copy stays dead); with the MW asm it is not.
- 65: alpha declared in the loop (`float alpha = 0.0f;`), not at function top -> alpha/topZ registers.
- 55: bottomZ declaration back at its use (no predeclaration) -> all saved FPRs = retail.
- 53: `{ float pz = self->owner->GetPosition().z; topZ = pz + mid * (top / HALF_PI); }` (same for bottomZ):
  retail's add.s operand order (pos.z first).
- 46: x wrap test `WrapX(float& p, const float& c, float h)` (retail loads p first), y keeps `Wrap(float&, float, float)`.
- 28 -> 21: alpha block: `float dm = d - m; float half = 0.5f; float hr = half * range; float one = 1.0f;
  float zr = ...; alpha = one - FAbs(dm) / hr; alpha *= FMax(zr * zr, 1.0f);` (scratch FPR numbering).
- 17: region B: `alpha = def->alpha * (...); alpha = FMin(alpha, def->alpha);` (r coalesces with alpha).
- 10/8: `pos += MulG(*localWind, ...)` and `pos += MulG(ownerMotion, 0.5f)`: GCC asm multiply with
  `int t; "=&r"(t) : "r"(pr), "r"(pa), "f"(s)` (retail's scratch order there).
- 0: randZ `pos.z = bottomZ + RndS(topZ - bottomZ) - 0.5f * (topZ - bottomZ);` (scaled random: range is the
  first mul operand and the product is not fused into madd).

### Dead ends (this function)
- Every GCC-asm clamp shape (by-ref helper, pointer helper, "+f", memory clobber, empty "+f" asm after) keeps the
  copy propagation on top. Declaration order changes do not affect it.
- ae.py per-site += / * forms (96 += forms x 30 * forms): no gain; the fix was the GCC-asm multiply (MulG).
