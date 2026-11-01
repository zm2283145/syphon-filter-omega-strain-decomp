# N3 final report (r215 session, 2026-11-01, ~6 h)

## Matched and staged (all MATCH, no UNDEF, staged to build/pending/n3, logged in STATUS.md)
| Function | Addr | Size | Draft (acc/) |
|---|---|---|---|
| nIk_TwoLimbIK | 0x1D1740 | 4380 B | acc/mw38_001D1740.c (tl/tl_match.c) |
| cDrawAndHolsterWeapon_ActionManager_InitWeaponSlotIkTargetTable | 0x1DBB20 | 5532 B | acc/mw38_001DBB20.c (ib/ib_match.c) |
| cParticleShatter_Render | 0x39B7B0 | 5048 B | acc/mw38_0039B7B0.c (ps/ps_match.c) |
| cGameCamera_UpdateMotion | 0x17A640 | 8472 B | acc/mw38_0017A640.c (gc/gc_match.c) |
As of 02:43, pending/n3 is empty and the four files are untracked under src/: the coordinator is integrating them
while HOLD is set.

## Key techniques (details in NOTES.md)
- **Inline-depth allocation model.** MW creates virtual registers breadth-first by inline depth, in source order
  within a depth, and colours them in reverse creation order. To create an address computation later, add
  pass-through inline wrappers. To create it earlier, bind it to a pointer local in an outer inline. Stack slots of
  inline locals follow the same depth order.
- **Dead `addiu vX,sp,N`.** Write `{ const void* xx = &obj; }` (precedent: humanCollision_13.c).
- **Tagged direct-form copy constructors.** `T(const T&, short)` with refThis/reg locals and lq/sq asm, used for
  return paths. An explicit ctor call leaves retail's dead `this` addiu.
- **Prototype-ELF locals** (names and types only) gave the real helper shapes: GetConjugate,
  Rotate = `*this = q * *this`, `CLAMP_LOW` = `max.s`, and `return cQuaternion(s).Invert()`.
- **Function-scope statics.** Use extern guard and storage symbols plus explicit init code (in ps), to avoid an
  unlinkable .bss DATA line.

## Near misses (not staged)
- **GuiWeaponDisplay_onRender 0x440580: wd/c5.c, 43 pos / 40 seq, exact size** (alternative wd/x6.c: 41 / 33).
  - Remaining: the Center sum copy scheduling at 0x5F0, and the 0.5f*(a+b) copy/op* colours at 0x854.
  - The matrix-constant scheduling at 0x88C-0x8E0 follows from the 0x854 block.
- **PlayerInput_Update 0x24B5D0: pi/p9.c, 43 pos / 36 seq, exact size.** Open hunks:
  - LimitManualAim constant order.
  - `spd = 0` float colouring.
  - Case-5 Set3 scheduling.
  - Case-8 bigWalk: retail has a single `li 1; andi` after the join.
  - MkXf argument order.
  - c.eq.s operand order.
- **cHumanIkRoutine_CalculateResultPose 0x1D02B0: unchanged at 127 (r215/r0.c).** Dropped: the hoisted
  switch-constant colours did not respond to anything tried.

## Tools (build/agents/N3)
| Tool | Purpose |
|---|---|
| chk.sh | check_match wrapper |
| bd / tools/bd.py | byte diff vs ROM; LEFT = retail, RIGHT = mine |
| tools/var.py | substitution-variant batches, J=2 |
| tools/cl.sh | hunk list |
| tools/calls.py | jal reloc to symbol |
| tools/prune.py | removes unused static inlines while keeping MATCH |
| pdis, tools/lines.py, lab | prototype disassembly, .line table, compile-and-objdump |
