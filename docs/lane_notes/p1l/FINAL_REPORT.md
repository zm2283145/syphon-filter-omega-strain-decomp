# P1L final report (2026-11-01)

## Staged (MATCH on mw38/mw50/mw304, no UNDEF, no DATA)
Both have already been integrated by the coordinator: build/pending/p1 is empty, and the functions are now in
src/.../particle/func_003A0540.c and src/.../interface_model/func_003ED880.c.
- 003A0540  cParticleSpline_NextFrame (2392 B)
- 003ED880  cInterfaceModel_ActuallyDraw (2772 B)

## Near misses (not staged; all at exact size or within 2 instructions)
| function | best draft | gd diff lines | what is left |
|---|---|---|---|
| XLib_DrawLensFlares 0x3781B0 (5388 B) | build/agents/P1L/lf_best8.c | 8 | one colour swap in the cover sprite: retail keeps the alpha word `(S64)ga << 24` in v0 and uv in t2, ours swaps them |
| cMan_ManDMA 0x385D40 (3472 B) | build/agents/P1L/md_best11.c | 11 | position of the hoisted `faceBlend` store in the loop preheader (retail third, ours last) |
| cPickupMenu_AcceptChoices 0x251920 (3200 B) | build/agents/P1L/pk_best20.c | 20 (798 vs 800 instrs) | the cSafePtr(NULL) temp is read through a kept pointer in retail (4 lines); spill-slot order, because the g_WeaponDatabase copy is a temp in retail but a named local in ours (16 lines) |
| cScriptInterpreter_execute 0x3DDFC0 (4996 B) | k6's best_3DDFC0.c (unchanged) | 40 | retVal is coloured s7 instead of s2, and the other s-registers rotate with it |

The LensFlares and AcceptChoices drafts are new this session. LensFlares went from 225 to 8 lines.
AcceptChoices went from 225 to 20 (the last 7 lines came from a mutation run), reusing the sound and safe-pointer patterns from the matched pickup_menu
siblings in src. For ManDMA, the prologue was fixed by the top declaration order PARTS, backclip, partCount, bloodParts.

## Not attempted
- XLib_ApplyContext: N4 parked it at 421 lines.
- XLib_Init, GuiEquipmentSetup_ctor and WeatherEmitter_Update: retail diverges from the prototype
  (psim 0.51 to 0.88), and a large ctor would have to be rebuilt from retail alone.

## MW findings worth reusing (details in NOTES.md)
- **Stack layout of inline locals follows breadth-first inline expansion.** Depth-1 inline locals are allocated
  first, then depth 2, and so on. A wrapper inline moves a group of locals deeper. This gave DrawLensFlares the
  exact frame layout, and it is why AcceptChoices' first EffectMsg sits in an inline.
- **Spill slots of named locals follow declaration order.** The s-register colouring is also driven by declaration
  order. A 700-order random grid fixed AcceptChoices' weapon/slot/entry registers. Grids are cheap at ~0.3 s per compile.
- **Copy propagation.** `p = &obj` is propagated into sp-relative stores. `p = (T*)((char*)&obj + 0)` keeps p in a
  register, without needing the `opt_propagation off` pragma that the matched siblings use.
- **Inline asm.** Functions using GCC `__asm__` with `&local` operands are not inlined. MW `asm { }` blocks with
  pointer locals are. `.set noreorder` removes the mfc1→qmtc2 hazard nop.
- **Virtual calls.** Make them real virtuals (dummy virtuals before them; the MW vtable has an 8-byte header and the
  vptr is at offset 0) to get `lw t9 / jalr t9`.
- **Struct returns.** A class with a user-defined copy ctor is built in place, with no lq/sq copy.
- **Evaluation order.** Inline call arguments are evaluated right to left. Message classes whose ctor takes arguments
  load those arguments before the cMessage ctor call. An inline operator wrapper evaluates the right operand before the
  inner call; call the extern "C" function directly when you need left-to-right order.
- **GS words.** The vram/TBP term is the right operand of its OR in retail.

## Tools (build/agents/P1L/tools)
- lcmp.py: compiles a draft with -g and diffs each named local's register or stack slot against the
  prototype DWARF. For hash-exact functions this gives a per-variable target.
- mut_lf.py: N4's mut_gd with MUTFUNC=<inline helper>, which mutates a helper's body while scoring the parent function.
- p1dis.py, gdw.py, dlocals.py, regmap.py, sdiff.py, lprune.py, psim.py.
- Grid generators used for the searches: lf/grid/gen*.py, pk/grid*.py, sc2/gen.py.

## Memory
Nothing new to save.
