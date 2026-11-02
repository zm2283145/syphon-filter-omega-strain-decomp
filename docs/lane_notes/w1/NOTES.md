# W1 notes (2026-11-02)

## 0039A000 WeatherEmitter_Update = cParticleBox::NextFrame (4356 B)
- Lab: `.venv/bin/python build/agents/P4L/tools/lab.py <draft> WeatherEmitter_Update 0x39A000 0x39B110 [-v]`
- w1.c: first full draft from the retail map (U3 section map + own decoding of the main loop). 1072 vs 1089 instrs, lab diff 446.
- w2: identity cMatrix ctor must be `asm volatile {}` (retail re-moves the args after it, system spilled) 446 -> 421.
- w5: Rnd as `float m = 2147483648.0f; ... / (1.0f + m)` (not folded in this mode), and scaled `RndS(size.x)` for x/y
  (retail loads size.x before the call) -> 373.
- w6: `Up()` accessor returning `const cVector&` (retail `addiu v0,v0,16`), operator= order xx,d,s with "=r".
- w7: blockType = 1-byte enum (`#pragma enumsalwaysint off`, enum {NONE,NEW,OLD}) returned by RequestBlock, tested as
  `blockType == BLOCK_NONE` -> retail `andi; beqz; sb v0,219(sp)` and the frame shrinks to 0x400. 224.
- w9: LenXY/LenYZ/Unit take `const cVector&` and copy inside (temps become inline-body locals): ALL stack slots = retail. 189 (nosp 187).
- w10: randZ written as one expression `bottomZ + (topZ - bottomZ) * Rnd() - 0.5f * (topZ - bottomZ)` (call evaluated
  first, range CSE'd for `pos.z += topZ - bottomZ`) -> 164.
- w11: region A takes `float n = self->near; float f = self->far;` locals (retail loads each once) -> 155.
- w12: alpha: `float hr = 0.5f * range; float zr = ...; alpha = 1.0f - FAbs(dist - m) / hr; alpha *= FMax(zr * zr, 1.0f);`
  -> exact instruction order there; 149 lab (nosp 147).
- w13: region A distance reuses the S0 variable `distanceFromOwner` (proto has two locals of that name; retail keeps both
  in f20). This moves elapsedTime to retail's f25. Score unchanged (other FP colours shift), kept because it is retail's shape.
- w14 = wu_best.c: the wind-block type test is `self->type == 0` (retail's extra `andi`; the other type tests are `!type`).
  **1089 = 1089 instructions, frame 0x400, every stack slot = retail. Lab 154 (nosp 151); check_match 153 words.**
  With saved FP regs masked: 114; with FP saved + GPR scratch masked: 69.

### Remaining diff (wu_best.c)
1. Saved-FPR colouring (~40 lines): retail pitch f20, top f22, bottom f21, mid f20, topZ f24, bottomZ f23, alpha f22,
   radius f20; ours shifted by one. Cause found: retail keeps the clamp result in the variable's register
   (`max.s f1,f22,f0; mov.s f22,f1`, `min.s f2,f22,f1; mov.s f22,f2`); ours coalesces the last helper's r into later
   uses and leaves a dead `mov.s f2,f20`. Micro harness m/t3.c: none of "+f", MW asm, volatile MW asm, pointer helper,
   macro-with-temp forms gives retail's pattern; `#pragma opt_propagation/opt_lifetimes/opt_dead_assignments off` no effect.
2. Scratch GPR order in the vector copies (~45 lines): sites need different copy idioms (retail orders: center/Length temp
   s,xx,d; ownerMotion xx,s,d; operator= and size/ownerYAxis xx,d,s). A single copy ctor form loses elsewhere; needs
   per-site copy helpers (one-level-deeper copy inlines, as in p6l/p8l).
3. topZ/bottomZ `add.s` operand order (retail pos.z first; MW canonicalises ours to product first in every form tried).
4. Wrap loads (retail pos.x, center.x, sizeHalf.x; ours center first), GetTurbulence(cVector) arg setup vs the
   windTurbulence sq, the S0 ownerMotion sub registers, scratch FPR numbering in the alpha block.
### Tried without gain
Param order permutations; float local hoisting; copy ctor variants (5); clamp shapes (nested, split decls);
Wrap parameter orders (4); topZ compound/reversed forms.
### Next ideas
Per-site copy helpers (CopyA/CopyB with different pointer-local order) at each lq/sq site; investigate the clamp
coalescing in a micro harness that also has a vcall between the clamp and the uses (retail top lives across E4 calls).
