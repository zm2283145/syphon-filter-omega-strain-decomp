# R2 final report (2026-11-01 evening) - less-optimised mode survey of the near misses

Staged: 1
- 003DDFC0 cScriptInterpreter_execute (4996 B) -> build/pending/r2/mw38_003DDFC0.c. check_match: function MATCH,
  DATA .rodata 0x004BD510 size 0x250 MATCH, no UNDEF. Uses the dead `if (0) { asm volatile { nop } }` mode trigger
  (commented, pending owner review like cHuman_Land), `extern char D_004BD4C0[]` for the shared "scriptManager.cc"
  literal and `"%d\0\0"` for an 8-aligned literal. Schedule() declared with its DWARF parameter order (float before args).

Key question answered (details and numbers in NOTES.md):
- All seven asm-heavy drafts (LensFlares, ManDMA, cMachine_NextFrame, ArcPoints, SweptRay, Render, PlayerInput)
  already compile in the mode (the trigger changes nothing), and retail is in the mode for all of them (the same
  draft with the mode off is 10x-100x worse). Their leftover diffs are in-mode colouring/scheduling, not a wrong mode.
- cScriptInterpreter_execute was the exception: no volatile asm, retail in mode. Trigger + dropping k6's opt pragmas
  + six small colouring fixes -> MATCH.
- Per-asm volatility: only the quadword copy asms must stay volatile; no block gained from being made non-volatile.

Unchanged near misses: LensFlares 8, ManDMA 9, cMachine_NextFrame 14, ArcPoints 14 (lead: a dead def before
`V start` gives retail's colouring at +2 instructions -> 7), SweptRay 23, Render 34, PlayerInput 35.
