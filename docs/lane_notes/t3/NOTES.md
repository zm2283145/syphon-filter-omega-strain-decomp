# T3 notes (2026-11-02)

Tools (build/agents/T3/): v.py (literal substitutions + lab score: `v.py base.c [-o out.c] [-v] old new ...`, env FUNC/LO/HI),
sbhill.py (SetBuffers parameter-order hill climb: swaps + insertions), bgperm*.py / bgsplit.py (SetBGColor OR-tree and
split-local searches), fogperm.py / fogsig.py / fogmix.py / fogsplit.py (fog block searches), deadpos.py (dead def at each
statement of the pixenv/fog window), m/cc.sh (micro harness). Lab = build/agents/S2/lab.py, range 0x37E780..0x37F668.

## 0037E780 XLib_Init (3816 B) - improved, not matched: xi_best52.c = 52 lab lines (S2 xi_best109.c was 109)
- Size now exact (954 = 954 instrs, check_match reports no size diff), frame 0x150 like retail.
- Steps (lab lines):
  1. fog products as `float fr = r; fr *= 256.0f;` (compound assignment gives retail's `mul.s f4,f4(zero),f0(256)` operand
     order; `r * 256.0f` and `256.0f * r` both give mul(256, r)) 109 -> 104.
  2. frame hole: `int h[8];` declared BEFORE `int dimx[16];` plus dead `if (0) { h[0] = 1; self->frame = h[1]; }` at the
     top: frame 0x130 -> 0x150, dimx stays at sp+0xF0 (declared after dimx it lands below and moves dimx) 104 -> 102.
  3. SetBGColor: separate converter `F2B(float f) { int r = 0; float t = f; asm volatile { cvt.w.s t, t; mfc1 r, t } }`
     (the `t = f` copy gives retail's f0/f1 pair and fixes the size to 954), then split into int locals with
     `int ib, ig, ir; ir = F2B(r); ig = F2B(g); ib = F2B(b);` and `(ib<<16) | (ir | (ig<<8)) | K` 102 -> 82.
     SetBGColor block now identical. (Exhaustive grids: 8 helper mixes x 6 decl x 6 assignment orders; the winners all
     have decl `ib` first-ish and assignment r,g,b with F2B on r.)
  4. SetBuffers: pass fbp as the expression `self->vram.frameBuffAddr[self->vram.currFrameBuf]` (no named local) and redo
     the parameter-order hill climb: (fbw, psm, fbmsk, zpsm, zbp, zmsk, fbh, fbp, half) 82 -> 52. SetBuffers block identical.
- Remaining (all in one 70-instruction window, retail 0x37EE80..0x37EFA4, plus ~6 lab masking artefacts on absolute
  hardware addresses `ld t3,4096(at)` / `sw v1,14368(at)` that are not real diffs):
  pixenv tme/abe/colClamp `li 1` colours (retail v1/a1/a0, ours a0/v1/a1); fog schedule: retail materialises the b zero
  (`mtc1 zero,$f2`) right after the r zero and the g zero late, ours the other way round; retail has 2 of the 3 dead
  `move a2,zero` before the first mul and `li a0,128` / `lui a1,256` / `ld a2,alpha` early; ours 128 in v0, 256a in v1,
  alpha in a0, last F2I result in a0; dimx loop pointer/count v1/v0 (ours a3/a1). Retail's `nop` after `mtc1 v0,$f0` is
  missing in ours, which is why ours needs an alignment nop before the loop and lacks retail's `li s1,3500; nop`.
- Tried in that window, all exactly 52 or worse: fog statement order (hill climb over all single moves), signature/arg
  orders and caller-local declaration styles (54 combos), per-component product forms x F2I/F2B (64 combos), split int
  locals for fog (288 combos), fog body written in main text, F2I non-volatile / GCC volatile / store-through helpers,
  setter inlines SetF/SetI, products as call arguments (57-67), `float fa`/`int ia` alpha locals (66-94), alphaReg moved
  (85-87), context chained assignment (56), function-scope fog locals (52-103), dimx loop forms incl. inline MemZ
  (52; nested 2-3 deep 58), pixenv `true`/`1U` constants, dead defs at every statement of the window (52 or +2 instrs, 81),
  named tRGBA locals for the hole (109+). mutate.py 3 min: 58 -> 40 words only by moving texClamp after alphaReg (store
  order then differs from retail; lab 59), so not a real direction.
- Reading: the window is insensitive to almost every source change, so the prepass schedule/colouring there is fixed by
  something not yet identified (micro m/t1.c shows MW in mode picks rotating registers for back-to-back constant stores, so
  colours follow the prepass schedule). Next ideas: find what makes retail's scheduler hoist the b zero above the g zero
  (e.g. a source shape where b's chain is longer or its zero vreg is created earlier, such as arguments evaluated
  right-to-left into real parameter vregs), and test whether the pixenv stores come from an inline/struct init.

## 0039A000 WeatherEmitter_Update (4356 B) = cParticleBox::NextFrame - surveyed, not started
- Identity: layout.txt/map.tsv place it in particle.cc between cParticleBox::Render (0x399080, matched in particle_8.c) and
  cParticleBox::RequestBlock (0x39B110). No better prototype counterpart: the only weather-named prototype symbols are
  cSnowEffect / SpecFxDefs (game code, elsewhere). Both prototypes have NextFrame__12cParticleBox... (early 0x38CBD0, 3012 B;
  earlier 0x37B6B0, 3048 B) vs retail 4356 B.
- Retail adds code the prototypes lack: two extra owner virtual calls (vtable +0xE4) at the start (center/size), a loop over
  the definition's children (count at def+0x180, 0xE0-byte entries at +0x190) calling GetEffectID__15cParticleSystemCFRC1
  (D_0053B540) and cLList_cParticleDefinitionPtr_opIndex (D_0053B544), particleCount/6 via 0x2AAAAAAB, Libc_Atan2f x2 and
  Libc_Tanf (FOV clamp to +-pi/2 with min.s/max.s), and 8 indirect calls total (proto 3). The rand/wind/AddChild core
  is still recognisable but reordered (retail 4 rand, wind x2, AddChild, 3 rand; proto 3+1 rand, wind x2, 2 rand, AddChild,
  4 rand). cParticleBox grew: definition at 0x100, owner at 0x104, floats at 0x110/0x120/0x124 (proto 0xF0/0xF4/...).
- Mode: retail is in the less-optimised mode (duplicated `addiu v0,sp,0x2E0`, separate pointer materialisations).
- Prototype locals (locals.tsv 20815-20840) give names/stack order for the shared part: mat 0x2E0, center 0x2D0,
  distanceFromOwner, size 0x2C0, sizeHalf 0x2B0, ownerYAxis 0x2A0, cappedParticleCount, i, piece, alpha, pos, windTurbulence,
  wind, wrapped, floorCollisionPos, child, deltaFromOwner. Retail frame is 0x400.
- Sibling sources for types/inlines: src/Libs/SFOLib/Source/particle_8.c (cParticleSpray_NextFrame, cParticleBox_Render:
  V/M quad-copy and VU0 helpers), particle_9.c, particle_5.c. A from-scratch rebuild of ~1100 instructions; not started.
