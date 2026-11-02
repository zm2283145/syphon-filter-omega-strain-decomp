# X1 notes (2026-11-02)

## XLib_ApplyContext 0x37C870 (4388 B)
- Start: W2 ac_best36.c (36 lab lines).
- FOUND (uv-scale block): the prototype ELF has `GetGuardBandScaleX__4XLibCFv` / `GetGuardBandScaleY__4XLibCFv` (0x14-byte
  accessors). Writing `uvScale.x = 0.5f * self->GetGuardBandScaleX();` (inline member returning gbScaleX[gbScaleNum])
  fixes the whole float block schedule (inline-body vregs are created a pass later -> retail's order). ac2.c: 36 -> 10.
  Found with a micro harness (m/u1.c + m/mt.py window scorer, m/e5.py inline-accessor grid).
- AddUnpack site-1 a0/a1 swap: fixed by advancing the packet pointer through an inline temp at that one AddV4 site
  (`Inc5b(){ u32* t = D_005381C8; D_005381C8 = t + 5; }`, AddV4_I) and calling it through one more inline level (AddV4_W).
  Grid s1.py (increment form x AddUnpack code-word form x wrapper). -> lab 6 (artefacts only).
- check_match then showed 2 words: lab masks lui immediates, retail ORs `addr | n<<16` first and 0x6C000000 last.
  UNPACK macro reordered to `((addr) | ((n) << 16) | 0x6C000000)` -> MATCH (all sites still fine).
- MATCHED: build/agents/X1/XLib_ApplyContext.c, staged build/pending/x1/func_0037C870.c.

## XLib_Init 0x37E780 (3816 B) - not improved: 52 lab lines (docs/lane_notes/t3/drafts/xi_best52.c = X1/xi.c)
- function: XLib_Init; best draft: t3 xi_best52.c (unchanged); remaining: the pixenv/fog/dimx window (retail 0x37EE80..).
- Analysis: retail's `nop` after `mtc1 v0,$f0` is a scheduler stall nop, not a source nop: the dead F2I `move a2,zero`
  (source-later) are scheduled before it and `sd alpha` (source-earlier) after it. The `li 1` colours follow from where
  the 256.0f K2 `lui` lands relative to abe's store (retail after `sw 268`, ours before, so K2 takes a0 and pushes
  colClamp off a0). So everything hangs on the prepass schedule order of the fog block.
- Tried (all exactly 52 or worse; harness fg.py + f1..f6.py, fhc.py):
  * fog call styles: direct constants (86), extra wrapper inline (62, 920 instrs), tRGB struct arg (74), parameter
    types int/uchar (69-128), C casts instead of F2I asm (76-85, no dead moves), memory re-read forms (69-128);
  * ctor/assignment forms with tRGBA/tIRGBA-like ctor structs (120-152); split colorf/color sub-inlines (52);
    per-component Mul256 / SetC helpers (52-80);
  * F2I variants: init late, t declared first, GCC asm, split asm, in-place (52-64);
  * random hill climb (fhc.py, 1500 variants: product form x product order x colorf/color store order x F2I/F2B/F2I2 per
    component x caller decl order x parameter order): never below 52;
  * alphaReg as array element / inline getter / inline setter: 52 (fully invariant).
  * `asm { nop }` after the colorf.g store gives 45 (xi_nop45_NOTACCEPTABLE.c) but it is a fake barrier (retail's nop is a
    stall), not usable.
- Prototype facts: tIRGBA::operator=(const tRGBA&) exists (x128 conversion, not used here); tRGBA(const tRGB&, float),
  tRGBA(ffff); GetGuardBandScaleX/Y; alphaBlendModes__4XLib at proto 0x481050 (index 0 = D_004BC1B0).
- Next idea: find the source shape of the fog line that makes b's zero argument materialise second (e.g. a tRGB/tRGBA
  built from a member or global, or an inline taking `const tRGB&` that copies into float locals in order r, b, g).
