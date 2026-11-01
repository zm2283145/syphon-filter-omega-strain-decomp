# P7L final report (2026-11-01)

## Staged
- 00251920 cPickupMenu_AcceptChoices (3200 B): MATCH on mw38 and mw50, no UNDEF, no DATA; every callee is in
  config/symbol_addrs.txt; no asm. Staged as build/pending/p7/mw38_00251920.c. The coordinator has already integrated
  it (src/SFOGame/Source/pickup_menu/func_00251920.c). The draft is kept as build/agents/P7L/pk_match.c.
  (The STATUS.md line says 21:15, which is UTC; the other lanes write local time.)

## Not matched (the drafts are unchanged from P1L's)
| function | best | what is left |
|---|---|---|
| XLib_DrawLensFlares 0x3781B0 | P1L/lf_best8.c, 8 lines | uv/alpha colour swap. Cause found (see below), but no pure-C fix |
| cMan_ManDMA 0x385D40 | P1L/md_best11.c, 11 lines | position of the faceBlend hoist. No source position or form reproduces retail's order |

## How AcceptChoices closed (20 -> 0 lines)
1. Retail's dead-looking `li a2,-1` in the prologue is a default argument: `virtual cVector GetPosition(int bone = -1);`.
2. The kept cSafePtr(NULL) pointer: `hp = (H*)((char*)&h + 0); hp = (H*)((int)hp);`. With two defs, hp stays a named
   local, which is coloured after temps, so it gets a3. A single `(H*)(int)&h` keeps the pointer as a temp in v0.
3. `p->w20 = 0;` moved before the SafeNull, as in the matched siblings.
4. The g_WeaponDatabase copy as an inline-body local: `static inline int DB() { int t = g_WeaponDatabase; return t; }`.
   Its spill slot is now allocated after all named locals (0xE0) while the load stays at the top. The proto DWARF has
   no db or inv locals either.
5. Named spill order follows declaration order, so the declarations follow the proto DWARF order: hasLeftWpn before
   packHasWeapon, wasActive before given, ammoTaken/otherWpn before wpnName.

## Findings on the other two
- **LensFlares.** Retail computes uv before the alpha word in the IR. uv then interferes with ga (v0), and the
  sign-extension reuses v0 in place. MW sinks our single-def uv to its first use. A micro test proves the model:
  `asm { nop }` or a real-branch ternary after uv gives retail's colours. No pure-C construct pins uv.
  - Sharing the uv variable with the main sprite's uv store does pin it (function-wide multi-def), but that recolours
    the shift and scrH, giving 40 lines.
  - An inline `AW()` for `(S64)a << 24` colours the chain v0, but moves the 2048 constant and uv (38–40 lines).
  - Random structured grids: 4566 variants on lf_best8 and 3000 on the shared-uv base found nothing better than 8.
- **ManDMA.** tools/ph.sh prints the preheader as a hoist signature.
  - A grid over every statement position in the loop body shows four regimes:
    - B0/B1/B10/B11 put the hoist at the end.
    - B2/B4 put it just before vifBlood.
    - B12 (after the pt3 continues) puts it in place, after the pt0 while loop's c32 constant.
    - B12b gets fully propagated.
  - Retail needs faceBlend between the pt0-entry constants and the pt0 while loop's hoist. No valid block is visited
    there.
  - Changing the loop forms only moves the inner batches to the front (do-while) or leaves them in place.
  - Details are in NOTES.md.

## Tools (build/agents/P7L/tools)
- vr.py: variant runner. VARS lists replacement pairs, and each variant is scored with N3 bd, or with P3L gd.py when
  GD="ADDR SIZE" is set (sizes in hex).
- ph.sh / p1dis_func.sh: ManDMA preheader signature and per-function disassembly.
- mt.py: micro-test runner (template + variants) that reports the alpha-chain registers.
- lfgrid.py, lfsh.py, lfperm.py, lfvars.py: LensFlares grids. posgrid.py: ManDMA def-position grid.
- syms.py: undefined symbols of a draft checked against config/symbol_addrs.txt.

## Memory
Nothing new to save.
