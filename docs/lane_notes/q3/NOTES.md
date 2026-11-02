# Q3 lane notes (session 2026-11-01 evening): larger non-human functions

Tools: g.sh DRAFT [kind] (P3L gd.py; FUNC/ADDR/SIZE env or cur.env), var.py BASE SPEC.py (VARS={name:[(old,new)]}),
rd.sh ADDR LEN (retail disasm), cd.py FILE [FUNC] (compile+disasm micro tests). A full check takes ~0.2 s.

## 003ED2E0 cInterfaceModel_Render (1388 B) - NOT matched, 39 gd lines (rn24_d.c from p5l)
- Prototype Render__15cInterfaceModelFv is hash-exact to retail. Only diff: FPR colouring of the two
  tRGBA(tPackedRGBA) conversions (retail k=f0, a=f2, b=f1; ours k=f2/f3, a=f1, b=f0) and the hazard nops it causes.
- Tried (all 39 or worse): 120 direct-assignment orders x 5 expression forms (74+), Set/U8 signatures
  (float/uchar/uint params, SetF forwarding, Set(const tPackedRGBA&)), conversions at the call site (62),
  reference/by-value FilterChildren/ActuallyDraw signatures, RenderInstance's matched ctor/ToF forms (129),
  17 pragmas on/off, mw304/mw50 (same), mw (149). P5L's rc/rc2/rc3 specs: best k5 = 38.

## 003BDA00 cCollisionProbe_SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects - NOT matched, 25 (p5l sweptray_s12.c)
- Outer branch-2 transform (XB4) grid: 9 copy-ctor tags x 6 decl orders x 3 return forms x 4 wrappers (648 variants,
  s7.py): best 33. `return *p` forms give retail's return-through-p copy but lose the by-value param copy-in.
- Post-loop endPos block: 7 operator= bodies x 8 endPos forms (s9.py): nothing below 25.

## 002A47E0 GuiEquipmentSetup_ctor (3004 B) - MATCH 20:52 -> build/pending/q3/mw38_002A47E0.c (ges_match.c)
- Fresh build from the matched sibling GuiScoresEquip_ctor (0x35D430, src/SFOGame/Source/GuiScoresEquip_4.c), which has
  the same AllocGuard camera, cSKM_GOBJ people loop, Install/FindAnim/Motion/Tail inlines. 221 -> 63 in ~1h.
- Needed: fx/msg (cSndFx/cPlaySoundMsg) declared in the main block right after mtx/tbl/req (stack 1104/656);
  `opt_loop_invariants` ON (the sibling's pragma set has it off): hoists the commander/'2' loop bases -> exact size;
  FindSex before SortParts; no g_GameState branch around FindAnim; string loop `if (done) c = 0; else c = src[j];`;
  `{ ModelT* m = people[i]; m->0x2DF4 = 0; }` then people[i]->0x2C71 = 1.
- Rotation copies: sibling-style helper with `__int128 q = 0` declared in the main-text block right after `V4CT r;`
  (q inside the helper = 143, q at block top = 132, q in that block = 63).
- Left (all in the init block 0x188-0x350): q gets t4 (retail t6) and the matrix-copy source t5 (retail t4), so
  paddub is scheduled first instead of at 0x22C. Tried: q placement (12 spots), M4Cp decl orders (14), deeper/
  shallower M4Cp, Q3E pointer orders x q positions (18), matrix store orders and 16-arg ctor (no effect).
- CLOSED (63 -> 0): the two rotation copies are separate helpers: obj_rot through `CpN` (no zero init), light_rot
  through `CpZ` (`__int128 q = 0; q = *s; *d = q;`), with `V4CT r` built in between. Zero-initialising both (149) or
  only obj_rot (2) is wrong. Lesson: when a quad temp's register (and the paddub position) is off, split shared
  copy helpers per site and try zero-init on each site separately.

## 00199980 cHuman_Choke_NextFrame (1448 B) - NOT matched, 65 gd lines (ck8.c; from B1's draft renamed via rename_map.tsv, was 116)
- RandRange blocker solved: `float m = 2147483648.0f; return lo + (hi - lo) * ((float)Libc_Rand() / (1.0f + m));`
  with `#pragma opt_common_subs off` in the function's push block (stops the 1.0f/0.0f hoists into f23/f20) and the
  call sites as `float lo; float hi = D_...; lo = hi / 2.0f; RandRange_L(lo, hi)` (lo/hi in f22/f21 as retail).
- cs off loses loop-invariant hoisting, so NAME_COPY takes `char* ckc_d = (dst);` before `ckc_s`, the post-loop
  terminator through `(dst)[i] = 0` (retail recomputes the base), and `ckc_c = 0; if (ckc_end) asm{.set reorder}
  else ckc_c = ckc_s[i];`.
- 78 -> 65: first-block `Rate_L r;` declared before `X_L x;` (slots 528/448 as retail); NAME_COPY with
  `char* ckc_s = (src);` BEFORE `char* ckc_d = (dst);` (src a0, dst v1 as retail).
- Left (65, size 356 vs 362 instrs): `this` in s0 (retail s1) with the Prio_L `on` / XInit px / sys temps in s1/s2
  (retail s0) throughout; Recip_L blocks miss retail's join nops and bc1t delay fill (6 instrs short); the AEvRun
  tail uses addiu sp temps where retail moves s1/s2. No gain: `Stun_L* a = p0` copies (3 forms), cs on with
  constant locals (166), 7 Recip_L forms, 24 first-block declaration orders.

## Not attempted this session
- cScriptInterpreter_execute 0x3DDFC0: k6 best_3DDFC0.c re-checked at 40 gd lines (s-reg rotation); not worked.
- WeatherEmitter_Update 0x39A000: proto mapping (cParticleBox::NextFrame, sim 0.628) is 998/1089 lines different
  (pcmp), so the prototype is not a usable base; skipped.
- XLib_Init (k3 fx_ini.c 279), cSubtitleFont_Display (p5l 88), XLib_ApplyContext: not touched.
