# U2 notes (2026-11-02)

## 0025CDC0 cGrenade_CalculateArcPoints (1544 B) - MATCH, staged build/pending/u2/mw38_0025CDC0.c (draft ap2.c)
- From p5l arcpoints_best.c (lab 14 / 17 words). Fix: VU0 multiply helper takes SOURCE before DESTINATION,
  `MulT(const V* p, V* d, float s)`, called `MulT(&v, &r, s)`. Inline args are evaluated right to left, so &dest is
  created (and scheduled) before &src: fixes both the Cross-copy cluster (dead paddub position, copy source v0) and
  the g_GameGravity `addiu` order. 14 -> 3 lab (the 3 are lwc1/lqc2 masking artefacts) -> check_match MATCH.
  Gravity site alone with the swapped helper: 14 -> 12; all MulT sites swapped: 3.
- Lesson: for "extra early vreg that emits no code" problems, look at the parameter order of the inline helpers
  (dest/src pointer creation order), not at dead defs.

## 003781B0 XLib_DrawLensFlares (5388 B) - not matched, still 8 (p1l lf_best8.c)
- Retail has NOTHING extra in the window: same instruction count (1347 = 1347); the only nop is the `bnez s2; nop`
  delay slot of the `i == 0` test, which ours also has. So no approved idiom (`asm { nop }`, dead block) applies:
  `asm { nop }` after uv adds 36 instructions (kills cross-block constant CSE), dead `if (0) { asm volatile { nop } }`,
  `if (0) { uv = 0; }`, empty GCC asm with "+r"(uv) / "memory": all 8 (empty asm ignored).
- `asm { .set reorder }` right after uv pins uv first but un-interleaves the block (36); before uv: 8; later: 19-59.
- Sprite helper `Spr(vif, rgba, uv, xy0, xy1)` all 24 param orders: 54-94 (the bnez delay slot gets filled).
  Cover block as inline with uv as a by-value parameter, 24 orders: all exactly 8 (params forwarded).
  RGBA(r,g,b,a) inline variants: 14-17 at the cover site; both sites 141+.

## 00385D40 cMan_ManDMA (3472 B) - not matched, still 9 lab (p1l md_best11.c)
- Remaining = only the hoisted faceBlend (`addiu a0,9200; sw 1264`) position in the loop preheader (retail 3rd, after
  the pt0 [1]/[0] constants and before c32; ours last).
- Tried (all 9): faceBlend through inline helpers that copy the argument into a local pointer (FBa/FBb/FBc), a
  `cMan* me = self` copy, GCC `"memory"` barrier after the def, `"memory"` clobber on the busy-wait div asm.
  Def before the `for` (function-scope variable): 97; before the busy-wait while: 24 (slot order changes).
- Reading: retail's hoist order puts FB between pt0's then-part constants and pt0's blood-loop c32, a place no def of
  faceBlend can dominate; the prototype is hash-exact, so the source order is fixed. Not a new-rule problem.

## 00167C40 cMachine_NextFrame (5572 B) - not matched, still 14 lab / 10 words (q2 mn_best10.c)
- Viewport (ResetViewportA, rect a3 / index a2 in retail, ours a1/a2's neighbours): SW(...) helpers with every
  parameter order (Viewport*/XLibT*/index/rect) fold the rect reference to the global (+2 instrs, 26); statement
  orders, `const tRECT* pr` copy, field-wise copy helpers CpR/CpR2 (dest/src orders), `tRECT* w = &v->win`: all 14.
  A function-scope `const tRECT* rr` assigned at the site: index a1, rect a2 (17). Retail behaves as if a1 were
  blocked in that block; the cause is not found.
- fe/msg (s5/s4 in retail): local copies of fe / msg / title inside PQP: 14 or 21 (msg copy rotates s1..s5).

## 0037E780 XLib_Init (3816 B) - not matched, still 52 lab (t3 xi_best52.c)
- SetFogColor: all 24 orders of (self, r, g, b) -> exactly 52 (params are forwarded; the arguments are constants).
- pixenv via an inline setter `SetPix(tPixelEnv* p, <21 params>)` (forward, reversed, pointer last, int/unsigned): 52.
- fog through `tFogEnv*` (member-like): 52; with `tFogEnv* f = &self->fog` local: 73 (base pointer t1 = s5+336);
  literal zeros: 86; XLib* local copies: 52.
- Retail's trunc/mfc1 tail is identical; the extra alignment nops (ours before the dimx loop, retail after
  `li s1,3500`) follow from the missing `nop` after `mtc1 v0,$f0`, i.e. from the prepass schedule of the
  fog constants. Still unexplained.
- (later) fog colour setters with right-to-left args: SetI/SetIr for `color` (0x80 created first): 62, size 952
  (the three conversions get batched, retail interleaves them r,g,b with the stores); SetF/SetFr for colorf: 52.
- NextFrame quit site grid (mnq.py): fe/msg as named locals (none/fe/msg/both, both decl orders) x all 24 PQX parameter
  orders = 120 variants: best 14 (48 variants), none better.
