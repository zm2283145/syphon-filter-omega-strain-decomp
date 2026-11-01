# P7L NOTES (session 2026-11-01): closing P1L's three near misses

Tools (tools/): vr.py (variant runner: VARS = {name: [(old,new),...]}; scores with N3 bd, or with P3L gd.py when
GD="ADDR SIZE" is set — sizes in hex), syms.py (undefined symbols of a draft vs config/symbol_addrs.txt).

## 00251920 cPickupMenu_AcceptChoices (3200 B) — MATCH mw38/mw50 -> build/pending/p7/mw38_00251920.c
Start: P1L pk_best20.c (20 lines, 798 vs 800 instrs). Four fixes, all in about 30 minutes:
- Retail's dead-looking `li a2,-1` in the prologue is GetPosition's DEFAULT ARGUMENT:
  `virtual cVector GetPosition(int bone = -1);` (a2 = third arg after the hidden return pointer and this).
- Kept cSafePtr(NULL) pointer: `hp = (H*)((char*)&h + 0); hp = (H*)((int)hp);` (two defs, so hp stays a NAMED
  local: not folded, and named locals are coloured after temps -> a3 like retail). A single-def `(H*)(int)&h` keeps
  the pointer too, but as a temp (coloured first -> v0, and the -1 constant moves to t1).
- `p->w20 = 0;` BEFORE `SafeNull(&p->h24);` (as in the matched siblings in pickup_menu.c) -> only spill slots left (14).
- g_WeaponDatabase copy as a temp: `static inline int DB() { int t = g_WeaponDatabase; return t; }`, `db = DB();`.
  The value is now held by an inline-body local, so its spill slot (0xE0) is allocated after all named locals,
  while the load stays at the top (line 483). Matches the proto DWARF, which has no db/inv locals.
- Then the named spill order = declaration order = proto DWARF order: hasLeftWpn before packHasWeapon (top),
  wasActive before given, ammoTaken/otherWpn before wpnName -> MATCH.

## 00385D40 cMan_ManDMA (3472 B) — NOT matched (best still P1L md_best11.c, 11 lines)
Tools: tools/ph.sh draft.c [-a] prints the loop preheader as a signature (spill slots in store order, s8/s7 = hoisted
0x10000002 / vifBlood, c32 = hoisted 0x20<<32, FB = faceBlend addiu). Retail: `144 s8 FB 1264 c32 896 528 912 880 544
496 512 464 ... 208 s7 192 944 928 176 160`; best11 has FB last; m0 (def after the mouthOff continue) `144 s8 c32 FB ...`.
- Position grid over EVERY statement boundary in the loop body (md_pos/res.txt, faceBlend declared at function scope):
  pt0 / else positions are not hoisted (def does not dominate the use); top-of-body B0/B1 and pt3 B10/B11 (before or
  between the pt3 continues) -> FB appended at the very end (best11 world); B2/B4 (after the top continues) -> FB right
  before vifBlood (s7), i.e. B2/B4 are visited AFTER pt3 (a unique constant put in B2's `+ 0x30000002` lands there too);
  B12 (after both pt3 continues, before the first if) -> in place after c32 (m0 world); B12b (from `dmaVif[0] =
  0x10000003` on) -> fully propagated (`ld 9200(a0)`, no slot). No position puts FB before c32.
- c32 comes from the pt0 blood while loop (uniquifying that constant moves the early c32). Loop forms of that loop
  (for/goto/`refCount--` forms) don't move it; a guarded do-while moves the inner hoist batch to the FRONT
  (before 144). Same for the else loop as a do-while (c32 + 160 first).
- `U64 inc = (U64)0x20 << 32;` before the pt0 while (m0 world): FB lands right after s8 like retail, but c32 is then
  no longer one global hoist (materialised several times late). Retail needs c32 created right after FB.
- Also tried: def in the `else if` condition via comma (-> before s7), `*faceBlend++` reads (not hoisted),
  `*(float*)faceBlend == 0.0f`, int-cast / two-def initialisers, combined/swapped/negated pt3 continues, pt3/else loop
  forms. Unique-marker stores per block are useless for ordering (the scheduler moves the `li` freely).
- More: switch(partType) form (code changes, same order), pt0 blood branch as `continue` instead of else, the pt0
  while body in an inline function, faceBlend via an inline helper with its own local (B10/B12): no order change.

## 003781B0 XLib_DrawLensFlares (5388 B) — NOT matched (best still P1L lf_best8.c, 8 lines)
Model (micro test t/ct.c + t/v2.py, confirmed): retail computes uv BEFORE the alpha word in the IR, so uv interferes
with ga (v0) and the sext of ga can reuse v0 in place (`dsll32 v0,v0`), leaving uv t2. Our uv expression is
sunk to its first use (store #5, after the alpha), so uv takes v0 and the chain gets t2. An `asm { nop }` right after
the uv declaration gives exactly retail's pattern in the micro test (sext v0<-v0, uv v1); so does
`U64 uv = dz ? UVE : 0;` (pinned behind a real branch, +2 instructions). In the real function any `asm {}` changes
the whole function (MW optimises functions with asm differently), so that is not usable even as a probe.
- Pure-C pin attempts (micro and real): two defs (`uv = a; uv |= b`), `uv += 0`/`^= 0`/`*1`/casts, const/register,
  struct/array member, do-while(0), labels/goto, if(1), identical ternary arms, dead stores to tw/th after uv, uv in
  the if condition via comma, named halves (hw/hh pin only the halves; the final OR still sinks) -> no pin.
- Sharing uv with the main sprite's uv store (function-wide multi-def -> not forwarded, sh1) DOES pin it: the sext
  becomes in place (v0) but the shift goes to t2 and scrH>>1 takes v0 (40 lines). Grid over uv's declaration
  position x shared store x cover position (tools/lfsh.py): 40 at best. Sharing rgba/xy words too: 112+.
- Alpha through an inline `AW(int a) { return (S64)a << 24; }` colours the chain v0 in place (created at a deeper
  inline pass) but moves 2048 to t2 and uv to a3 (40 lines; 120 cover declaration orders, best 38). Expression shape
  of the RGBA OR tree is canonicalised (no effect).
- tools/lfgrid.py (random structured grid: alpha form x uv form x corner form x 2048 literal/const x declaration
  order): 4566 variants on lf_best8 (best 8, all of them in the g-copy world), 3000 on the shared-uv base (best 36).
