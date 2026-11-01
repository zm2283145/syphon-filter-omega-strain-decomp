# P1L NOTES (session 2026-11-01, render/XLib/particle/script/GUI targets)

Tools: N3's bd (`../N3/bd file.c FUNC [kind] [-a]`, CTX=, RSIZE=), N3 var.py (variant grids), N3 calls.py
(jal reloc -> retail target/name), tools/lprune.py (greedy line pruning keeping MATCH, own tmp file).

## Ranking (map.tsv early_sim, prototype vs retail)
hash-exact 1.0: cMan_ManDMA, cInterfaceModel_ActuallyDraw, cParticleSpline_NextFrame.
0.995 XLib_ApplyContext, 0.994 cScriptInterpreter_execute, 0.993 XLib_DrawLensFlares,
0.963 cPickupMenu_AcceptChoices, 0.941 XLib_Init, 0.935 GuiEquipmentSetup_ctor, 0.628 WeatherEmitter_Update.

## 003A0540 cParticleSpline_NextFrame (2392 B) — MATCH 12:01 -> build/pending/p1/mw38_003A0540.c
- Start: k5 nf_q.c = 12 words but with 12 UNDEF mangled callees: BF2's calls sit beyond inline_depth(6)
  (and IR1 / GetNormalizedI calls), so MW called the inline member wrappers out of line. Raising the depth
  breaks everything (+347), so the out-of-line calls are real.
- Fix UNDEF: write those calls as direct extern "C" calls at the same spot. Locals that would need the
  (non-inlined) default ctor use raw aligned storage `struct VS { float f[4]; }` and casts; don't bind a
  reference to it (holds the pointer in s0). Struct-return GetInverseRot declared as
  `void cMatrix_GetInverseRot(cMatrix* ret, const cMatrix* self)` (same ABI) to avoid a matrix copy.
  -> 12 words, no UNDEF.
- Site 2 (`splineDelta = SubT(...)`, cross) colours: line table shows retail creates the cross's vregs
  (D v0, a v1, o a0) last at both sites; ours had the deeper return-copy vregs last. Copy/op= body forms and
  return-copy flavours: no effect. Fix: cross pointers bound one inline level deeper, keeping the return temp:
  `Cr3(b) { cVector r; CrIn(r, *this, b); cVector& rr = r; return rr; }` with
  `CrIn(cVector& r, const cVector& s, const cVector& b) { o=&r; a=&s; pb=&b; asm }`, plus a site-2 SubT2
  returning `cVector(r, (unsigned char)0)` and an explicit op= (AsX) -> MATCH mw38/mw50/mw304.

## 003ED880 cInterfaceModel_ActuallyDraw (2772 B) — MATCH -> build/pending/p1/mw38_003ED880.c
- New draft from the prototype (hash-exact) + .line table + DWARF locals (unkickedPolys, scratchColor, scratchUv, f).
  Infrastructure = decals.c (Begin/Emit/EndStrip, G struct over D_00539210) with Emit2 for the untextured path
  (D_005381F8 = 2LL<<32). Needs `#pragma inline_depth(8)` (as the interface_model unit).
- Lines: 756 recomputes scratchColor = SPR / scratchUv = scratchColor + mRgbSz; 773 = EndStrip() (its dead
  `if (!...)` block explains the empty lines 774-787); 788 `unkickedPolys = 1` (hoisted into the preheader).
- Prologue: Prim() before Mode() gives retail's regs. UV loop: `const cUv& uv = mUv[i]` + tUV ctor (no reloads).
- Colour loop (last 22 words): every single-assignment form (ctor args, inline helpers at any depth, int locals,
  pragmas) gives identical code because MW forwards the cvts into the products. Fix: named locals
  `float a = (int)c.a; ...` then REASSIGNED `a = K * a * filterColor.a; ...` and `*scratchColor = tRGBA(r,g,b,a)`:
  multi-def locals are not forwarded, so all four cvts precede the products (distinct f9..f6 like retail). -> MATCH.

## 003DDFC0 cScriptInterpreter_execute (4996 B) — best sc_best215.c = 215 positional / 120 seq (from k6 best_3DDFC0.c 321 / 132)
- Register-normalised diff of k6's draft: only ~5 structural differences (MemClear short-param sign-extend,
  one `move a3,s1` slot, the known 0x58C `nop; b; nop` join, bne operand order at 0x12C8); everything else is
  s-register colouring (retail retVal s2/mine s7, funcNum s5/s2, newf fp/s5, saveIP s7/s0 ...). tools/regmap.py
  lists retail->mine s-reg pairs per region.
- DWARF: case 0x12 has its own `retVal` ($v0) - giving it one moves the outer retVal to s2 (e1.c 293 pos).
- Loop-level declarations: `val1` declared LAST (op, fval1, data, fval2, num, val2, ptr, val1) -> 215 pos (p00).
  26 of 40 random orders give 215; rest 231/293.
- With that, MW keeps `done` in s8 and spills retVal (retail: done on stack 0xC0, retVal s2). `volatile done`
  changes size (+8). Pragma sweep on p00: removing any of k6's five or adding propagation/dead_assignments: worse.
- DWARF case-local orders for 0x3E (args first) and 0x40 (funcNum local): no change.
- Next idea: find which variable's priority makes MW spill done instead of retVal (use counts?): e.g. extra
  uses of retVal (retail may `return retVal` from inside case 2?), or done tested in more places.

## 00385D40 cMan_ManDMA (3472 B) — best md_best11.c: exact size, 11 gd lines (faceBlend hoist only)
- Fresh draft from the prototype (hash-exact) + line table + DWARF locals. 805 -> 13 gd lines in ~40 minutes.
- NEW TOOL tools/lcmp.py draft.c FUNC PROTO_ADDR: compiles the draft with `-g` (MW emits DWARF1 like the
  prototype), dumps the function's locals with locations (tools/dlocals.py, P1's dwarf1.py) and diffs them
  against build/agents/P1/early/locals.tsv. For hash-exact functions this gives the exact register/stack slot
  of every named local in retail = a per-variable target. Unused locals are omitted by mw38 but listed by
  the proto compiler (shown as $v0), so ignore those rows.
- Levers, in order of effect:
  * `refDataQwc <<= 4; refDataRef += refDataQwc;` (line 5302 is an in-place shift) instead of
    `refDataRef += refDataQwc << 4`: 844 -> 188 (whole-function allocation cascade).
  * loop0 / else-loop: `sourceQwc = refSource->qwc; ... sourceQwc <<= 4; refSourceRef += sourceQwc;`
    (MW splits the live range: qwc temp + shifted value in two registers); else-loop counter is an int
    `refCount = patchCount; while (refCount > 0)` (coalesced with patchCount, gives bgtz) -> exact size.
  * scratchpad through an inline helper whose local holds the pointer:
    `static inline manRenderSPAD* SpadP() { manRenderSPAD* SPAD = (manRenderSPAD*)0x70000000; return SPAD; }`
    -> `lui a2,0x7000; addu; ld 0xA50(a3)` like retail (a plain constant pointer uses `lui at`): 159 -> 38.
  * `U64* faceBlend = (U64*)self->faceBlends;` as the FIRST statement of the partType==3 block (before the
    continues), first read `*faceBlend`, the other three via `*(U64*)&self->faceBlends[2/4/6]` -> spilled named
    local at 0x4F0 like retail.
  * else-block: dead `source = hands[lr].source; dest = hands[lr].dest;` after leftRight, direct
    `hands[leftRight].source * patchCount * 48` reads in the blend sums -> blends lw + two dsll32/dsrl32 (13).
  * busy-wait `7/7` divide: MW folds C division, so it is a GCC asm `div %1, %2; nop; nop; mflo %0`
    (MW's GCC-asm parser needs `;` separators and the 2-operand div).
- Remaining 13 lines: prologue `addu v1` vs retail `addu v0` (PARTS temp) and the hoisted faceBlend store is
  scheduled last in the preheader (retail: third, right after `ori fp,a3,2`). Initialiser spellings, block
  placement (top/mid/after continues), enclosing-else declaration: no help (enclosing else 26).
- faceBlend hoist order (13:00): retail's hoisted `addiu v0,a0,0x23F0; sw v0,0x4F0(sp)` sits right after `ori fp,a3,2`;
  ours lands last (gets a2 because in the IR it is appended after all expression hoists). Micro tests (md/t/l1,l2):
  MW hoists invariant *expressions* in source order but appends hoisted *named-variable assignments* at the end
  of the preheader (fs1: a def before the loop lands first instead). Tried without success: every statement
  position in the block (w00-w08), declaration position (dl_*), function/loop-body scope, enclosing else,
  nested ifs instead of continue (n1/n2), const/direct-init/void*/integer-cast/inline-helper initialisers,
  dead flagCount/patchCount assignments, PARTS spellings (prologue addu v1/v0 unchanged). Assigning after the
  mouthOff continue (m_*) hoists faceBlend early (propagated) but reorders other hoists (100 lines).
- check_match counts 92 positional words for md_best13.c because the preheader shift misaligns the rest.

## Script (cont.) — DWARF locals comparison (tools/lcmp.py ... 3CC590 -l)
- All 12 common-name location mismatches are one shift: retVal coloured last (s7) instead of s2, so funcNum,
  numArgs, structIndex, nonLocal take s2 (retail s5), saveIP s0/s6 (retail s7), newf s5 (fp), g fp (s0).
- Removing the draft-only named locals (ip, num, code, p, v/off, t/stk) does not move retVal (m1.c).
- Without `opt_lifetimes off`, val1/ptr move to caller-saved regs (retail keeps val1 s1), so that pragma looks real.
- Model (Chaitin with optimistic colouring): ours needs one more optimistic candidate than retail, and picks
  retVal; the cause is still unknown.

## 003781B0 XLib_DrawLensFlares (5388 B) — best lf_best8.c (lf/cb1.c): exact size, 8 gd lines (one colour swap)
- Fresh C++ draft from proto line table (lf_bylines.txt) + DWARF locals. 225 -> 42 gd lines.
- Callees: cMatrix opMul returns by value (hidden ret ptr); copy ctor = cMatrix_ctor_cMatrixR, default = ctor_void,
  op= = cMatrix_opAssign, all as inline members calling the extern "C" names. Nested product written
  `m = cMatrix_opMul_cMatrixR(&cMatrix_opMul_cMatrixR(&proj, &flip), &view)` (an inline operator* wrapper evaluates
  the view address before the inner call).
- Inline asm functions using GCC `__asm__` with &local operands are NOT inlined by MW; MW `asm { }` blocks with
  pointer locals (Spline's CrIn style) are. Return `*o` (the asm pointer) so the copy reads through the same vreg.
- STACK ORDER = MW inlines breadth-first (worklist): locals of depth-1 inlines get allocated first, then depth-2,...
  Retail order arg(816) r(800) t(784) m(720) proj t2 t1 t3 dir col -> LensMatrix wrapper -> LensImpl (depth 3),
  transform via Xf() wrapper (depth 2), DrawFlares behind two wrappers (depth 3), pscl operator* at depth 1.
  `#pragma inline_depth(8)` needed for that nesting.
- fov block: `const float k = 0.015625f;` used for both sizeScl products (separate literals schedule differently).
- FRAME/TEX0 words: vram term is the RIGHT operand of its OR: `((fbw << 16) | vram) | psm<<24 | ...`.
- Cover block: named x1/x0/sy/y0/y1 locals (x1 = sx + 2048 first); uv halves as (S64)(int).
- pscl (scl * invw): MW `asm { .set noreorder; ... mfc1 q, s; qmtc2.ni q, vf2; ... .set reorder }` (no hazard nop,
  like the repo's other VU0 scale helpers), declaration order r, a, q, o -> pscl block exact (33 lines left).
- RGBA words: the SCE macro form `r | g<<8 | b<<16 | a<<24` compiles the same as the hand-reordered tree.
- Cover block (last 22 lines): decl order uv, sx, sy, x0, x1, y0, y1 (random search over 60 orders) and a named
  `S64 g = ga;` used as `(g << 24)` puts the sign-extension first like retail (27 -> 22). Left: retail keeps g in v0
  (in-place dsll32/dsra32/dsll) and uv in t2; ours swaps them (uv v0, g t2), and retail computes x1 = sx + 2048 right
  after sx (t4) while ours computes it after x0. Tried: g at every position, g types (long/U64, split def), uv as
  temp/inline helper/outer-scope local, corner expressions inline (15 combos), cover block as an inline helper
  (much worse), RGBAQ inline helper, rgba local first.
- 22 -> 8: cover corners WITHOUT sx/sy locals: `int x0 = 2048 - (self->scrW >> 1); int x1 = (self->scrW >> 1) + 2048;
  int y0 = ...; int y1 = ...;` (decl order uv, g, x0, x1, y0, y1).
- Last 8 lines = one colour swap: retail keeps the alpha word chain in v0 (`dsll32 v0,v0; dsra32 v0,v0; dsll v0,v0,24`)
  and uv in t2; ours gives uv v0 and the chain t2. Insensitive to: uv declaration scope/position/multi-def/spelling,
  g position/type/dup-defs, ga init placement, an int-returning dazzle inline, RGBAQ inline helpers (int/S64/U64
  params), corners as separate constants. A NAMED shifted value (`S64 g = (S64)ga << 24;` or `g <<= 24`) does give the
  chain v0 but recolours the rest (2048 constant t2, uv a3 -> 50 lines; 100-order grid with/without sx/sy best 34).

## ManDMA (cont., 13:50)
- Prologue `addu v1` -> `addu v0` fixed by the top declaration order PARTS, backclip, partCount, bloodParts
  (24-order grid; md/pp/p02.c = md_best11.c). Only the hoisted faceBlend store position remains (11 lines).
- faceBlend worlds (14:05): (a) def before the mouthOff continue (best11, o1) = real named variable, hoisted
  `addiu a2,a0,0x23F0; sw 0x4F0` appended at the END of the preheader (11 lines). (b) def after the mouthOff continue
  (md/m0.c) = hoisted mid-preheader with v0 like retail, but the 36 / 0x1000404<<32 hoists move late (98 lines).
  (c) def in the dmaVif block (m3) = fully forwarded into `ld a3,0x23F0(a0)`, no stack slot (866 instrs, 22 lines).
  Retail = (a)'s hoist order with faceBlend inserted third. Mutation runs: best11 base (no gain), m0 base (running).
- LensFlares cover, exhaustive searches (fast: ~0.3 s per compile): named-alpha world with uv first and all 560 valid
  orders of g/sx/sy/x0/x1/y0/y1 (best 33), plus a named `c = 2048` (all 2176 orders, best 38); 300-variant random grid
  over alpha form x uv form x sx/sy x order (best 14). N4 mutation (6000 variants on the DrawFlares body) no gain.
  cb1 (8 lines) stays best. Model that fits most observations: hoisted temps first, then named locals in reverse
  declaration order, then other temps; single-def copy/cast inits (`S64 g = ga`) are forwarded (not named).
  Retail needs the alpha chain coloured before uv AND uv after the scrH-load/2048 temps - no source form found.

## 00251920 cPickupMenu_AcceptChoices (3200 B) — best pk_best20.c: 20 gd lines (798 vs 800 instrs), new draft
- Retail = proto 0x237E60 (DWARF + line table) with a few changes: cHuman fields +4 (weapon 0x3524, inventory 0x3528,
  armor 0x339C/0x33A0), cSndFx layout (+384 int, +388 short, +390 byte), first sound is EffectMsg_WrapRequest (+flag 1)
  instead of cPlaySoundMsg, the ammo branch keeps `taken` (no RemoveAmmo/AddAmmo else-branch), goggles check after AddWeapon,
  cWeapon_EqualizeDualWieldAmmo at the end, multiplayer message with NetGetMyClientIndex(&idx, D_005721A8).
- Reused from the matched siblings in src/SFOGame/Source/pickup_menu.c (PrevWeapon/Next/Prev): the stack cSndFx
  construction + EffectMsg block, and pickup_menu_2.c (Draw): Handle_Get (safe-pointer movz pattern), Item/Slot/Owner layouts.
- Levers so far: human->GetPosition() as a REAL virtual call (46 dummy virtuals before it; MW vtable has an 8-byte
  header, vptr at offset 0) -> `lw t9; jalr t9`; cVector with a user-defined copy ctor so the struct return is built in
  place (no lq/sq temp); the first EffectMsg inside an inline (PlaySnd) so its slot (0x150) is allocated last;
  declarations in DWARF order with humanPos declared at its init; bools as init-forms so MW forwards them (they are
  absent from the proto DWARF: dual/unlocked/dropped/dualDrop are temps).
- Open: (1) the matched siblings use `#pragma opt_propagation off` for the sound block; without it the sound ctor is
  wrong (~30 lines), with it the bool/register parts get worse (best 136, p136.c). (2) weapon/entry colour swap
  (retail weapon s1, entry s3; ours s3/s1) - not fixed by any declaration order (900 orders tried). (3) the
  g_WeaponDatabase copy is a spill TEMP in retail (slot 0xE0 after the named spills) but a named local in ours.
- 124 -> 94 (15:30): sound pointer kept out of copy propagation WITHOUT the pragma by `p = (Act*)((char*)&sound + 0);`
  (plain `p = &sound` is propagated into sp-relative stores); the cSafePtr(NULL) temp in an inline (SafeNull) so its
  slot (0xA88) comes after newArmor/newInitialArmor; second virtual call made real (116 dummy virtuals, slot 0x1D8);
  armor stores through one temp (chained `a = b = x` stores right-to-left); message ctors with arguments
  (InvMsgCtor(id, ammo, human), NetMsgCtor(pack, idx)) as inlines so their argument loads precede the cMessage ctor call.
- Remaining ~94: mostly the weapon(s1)/entry(s3) colour swap (it also moves initialArmor, the kind-5 id and the
  multiplayer idx/pack registers), spill-slot order (db must be a temp), the D_005721A8 load placement, one
  `taken = entry->id` delay-slot fill.
- 94 -> 27 (15:50): (a) declaration order is the s-register lever: entry and slot declared BEFORE inv at the top
  (`finished, db, entry, packHasWeapon, slot, inv` / then `isHolsterWpn, sameWpn, pb, pa, hasLeftWpn`) fixes the
  weapon s1 / slot s2 / entry s3 colouring (700-order random grid); (b) `packHasWeapon = sameWpn = false;`,
  `entry->id > -1` / `curWpn > -1` (slti/bnez, not bltz); (c) the multiplayer client index as an inline argument
  `GetIdx(D_005721A8)` (`g_IsMultiplayer ? MyIdx(net) : 0`) so D_005721A8 is loaded before the test;
  (d) `taken = entry->id;` BEFORE `wpnName = GetString(dbEntry->name);` (fills the call delay slot like retail).
- Last 27: 6 = the cSafePtr(NULL) temp is loaded through a kept pointer in retail (`addiu a3,sp,0xA88 ... lw v0,0(a3)`),
  ours folds the address; 21 = spill-slot order. FINDING: MW assigns spill slots of named locals in DECLARATION order
  (finished 0x140, then the next declared spilled variable, ...). Retail order is finished, hasLeftWpn, packHasWeapon,
  wasActive, given, ammoTaken, otherWpn, wpnName, and only then the g_WeaponDatabase copy (0xE0) -> in retail that copy
  is a temp, not a named local, but it is loaded at the top (proto line 483). No source form found for that
  (init/const/ref/removed variable all tried).
- 27 -> 20 (15:28): N4 mutation tool (7346 variants) reordered declarations: entry after packHasWeapon, sameWpn after
  pa, oldClipAmmo/wasActive declared after given and `wasActive = ...` after `taken = given = -1` (spill order),
  `ammoTaken` declared after wpnName's neighbours. Left: db spill slot (temp in retail), hasLeftWpn/wasActive/
  ammoTaken/otherWpn/wpnName slots shifted by it, SafeNull pointer (4 lines).
