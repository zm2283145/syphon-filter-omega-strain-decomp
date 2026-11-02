# S2 notes (2026-11-02)

Tools: sinit2c.py (symbolic execution of a straight-line sinit asm -> C; `sinit2c.py asm.s strings.data.s LO HI`),
lab.py (P4L lab copy; env LANG_=c++ and XFLAGS="..." pass extra compiler flags), m/cc.sh (micro harness: compile + objdump).

## 004D09A0 StaticInit_scriptUtils (3340 B) - STAGED (su5.c -> pending/s2/mw38_004D09A0.c), MATCH + DATA MATCH
- su1.c = sinit2c.py output, 58 lab lines. Every diff was the same thing: retail keeps a value in v1 (or a2) across
  calls to Array_SOBJ_getClassId / cNodeList_SOBJ_getClassId. Across the whole retail binary this happens only here.
- Cause: in the prototype both are `getClassId__Q224@unnamed@scriptUtils_cc@...` (anonymous namespace, local). MW
  records the register use of a **static** function defined earlier in the same file and uses it at call sites
  (micro test m/t1.c). Global, weak, `#pragma internal`, dont_inline inline functions and C++ mode do not do this.
  With `static` copies defined before the sinit: 0 diffs (su4.c).
- The static copies go into their own sections: `#pragma define_section IPA_ARRAY ".ipa_002690E0" ".ipa_002690E0"` and
  `__declspec(IPA_ARRAY) static int* Array_SOBJ_getClassId(void)` (MW keeps the IPA; `__attribute__((section))` and
  `#pragma section` don't work in this MW). The jal relocs are against the named local symbols.
- **Integration needs a linker rule** (coordinator): map the two sections NOLOAD at their real addresses, e.g. in
  config/extra.ld
  ```
  SECTIONS {
    .ipa_002690E0 0x002690E0 (NOLOAD) : { build/src/main/sinit/<file>.o(.ipa_002690E0) }
    .ipa_00269830 0x00269830 (NOLOAD) : { build/src/main/sinit/<file>.o(.ipa_00269830) }
  }
  ```
  (the link already uses --no-check-sections). Scratch test link of the object with such a script: all 835 words
  at 0x4D09A0 byte-identical to retail, 41 jal's resolve to 0x2690E0/0x269830. The real functions stay in
  scriptUtils_20.c / scriptUtils_25.c. Check elf_rebuild.py ignores the two NOLOAD sections.
- Strings: .data 0x4A82C8..0x4A84D8 (inside data/d_004A8290); "Add"/"Get" need `"\0\0"` padding (8-aligned literals).
- Splat currently has `[0x3D09A0, asm, sinit_4D09A0]`.

## 0037E780 XLib_Init (3816 B) - improved, not matched: xi_best109.c = 109 lab lines (k3 fx_ini.c was 221 lab / 279 words)
- Draft was already in mode (inlined GCC volatile Identity/operator=); trigger changes nothing, NV leaves the mode (689).
- Steps (lab): fx_ini 221 -> SetBGColor via `F2I(float) { int r = 0; float t; asm volatile { cvt.w.s t, f; mfc1 r, t } }`
  (retail tail: separate `mtc1 zero` per component, dead `move aN,zero` = the `r = 0`, and frameTime stored with
  mtc1+swc1 because a volatile asm is in the same block; OR-term order `b<<16 | r | g<<8 | K`) 213
  -> SetFogColor(self, float r, g, b) with `float fr = r * 256.0f` locals, colorf stores, then `color.x = F2I(fr)`
  (retail forwards the products to cvt.w.s), called as `{ float r = 0, g = 0, b = 0; SetFogColor(self, r, g, b); }` 183
  -> 16-byte align as an inline helper `Al16(p)` (fixes the hoisted -16 colour in the strip loop) 164
  -> isDirty through a member `SetDirty()` / `cXViewport* vp = &...; vp->isDirty = 1` (retail `addu v1,s5,v1` order) 144
  -> fbp as a named local before the SetBuffers call 135
  -> SetBuffers parameter order (random search + pairwise hill climb, sbperm.py/sbhill.py):
     (psm, fbmsk, fbp, zpsm, fbw, zbp, zmsk, fbh, half) 109.
- Remaining: SetBuffers fbp/fbw/fbh colours (t2/v0/a0 vs retail v0/t2/v1); fog block: retail keeps the three `0*256.0f`
  multiplies (mtc1 zero per component, 256.0 rematerialised 3x) - ours folds or CSEs; dimx zero loop has an extra nop;
  SetBGColor: retail uses f0 and f1 for the first two conversions, dead moves in a2/a2/a1; frame 0x150 vs ours 0x130
  (32 bytes missing above dimx - tRGBA named locals/temps make it worse); the b;nop;nop / trailing nops are 8-byte label
  alignment and fall into place once sizes match.
- No gain: by-value tRGBA SetFogColor/SetBGColor (224-264), RGBAQ macro/inline forms, statement-split F2I, mul operand
  orders, `float k` constant, gbScale forms, statement order inside SetBuffers (134-140).

## 0037C870 XLib_ApplyContext (4388 B) - surveyed
- n4's AddV4 sites are inline-asm lw/sw word copies (expressible in C, so not acceptable as is). Plain C
  `p[0] = c; *(W4*)(p + 1) = *(const W4*)q;` in all AddV4A..F: 521 lab (asm version 519) -> ac_cAddV4_521.c is the
  acceptable base. Trigger: no change (already in mode).
- Retail copy shape is two-register pipelined (lw a0; [sw code]; lw v1; sw a0; sw v1; lw a0; lw v1; sw; sw) with the
  source pointer kept in its own register. Micro tests (m/t10-t16): C/C++ struct copies of W4/int[4]/unions/nested
  structs give FPR lwc1/swc1 or one-register lw/sw; only small-element structs (char/short arrays) give MW's 2-register
  block-move loop. Not found yet: try a 20-byte struct copy (code + 4 words from a template) or a 2-iteration loop.

## 0039A000 WeatherEmitter_Update - not started (time).

## MW interprocedural register knowledge (general)
- MW reuses caller-saved registers across a call when the callee is a `static` function defined earlier in the same
  file. Retail scan (whole .text, jal + delay-slot def read after the call): among the 74 unmatched functions only
  StaticInit_scriptUtils shows it. Matched code has other instances (callees 0x1BEDC0, 0x1BF5A0, 0x400F20...).
