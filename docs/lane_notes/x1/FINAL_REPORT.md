# X1 final report (2026-11-02)

## XLib_ApplyContext 0x0037C870 (4,388 B): MATCH (mw38), staged
- Source: build/agents/X1/XLib_ApplyContext.c, staged as build/pending/x1/func_0037C870.c.
- Keeps W2's owner-approved UNPACK copy blocks (`asm volatile { .set noreorder; lw/sw ...; .set reorder }`), commented.
- Three fixes on top of W2 ac_best36.c (36 lab lines):
  1. uv-scale float block: retail calls the inline accessors XLib::GetGuardBandScaleX/Y (non-inlined copies exist in
     the prototype ELF). `uvScale.x = 0.5f * self->GetGuardBandScaleX();` gives retail's schedule. 36 -> 10.
  2. a0/a1 swap at the first AddUnpack: at the preceding AddV4 site (0xF, &D_00537F30), advance the packet pointer through an inline
     temp (`Inc5b(){ u32* t = D_005381C8; D_005381C8 = t + 5; }`) and call that AddV4 through one more inline level.
     10 -> 6 (lab artefacts only).
  3. Two words lab could not see, because it masks lui immediates: retail builds the VIF code as `addr | n<<16`, then `| 0x6C000000`.
     UNPACK macro is now `((addr) | ((n) << 16) | 0x6C000000)` -> MATCH.

## XLib_Init 0x0037E780: not improved, still 52 lab lines (docs/lane_notes/t3/drafts/xi_best52.c)
- About 100 structural fog variants plus a 1,500-variant random hill climb did not go below 52. The alphaReg access forms gave
  exactly 52 every time (NOTES.md has the full list).
- Finding: retail's `nop` in the window is a scheduler stall, not a source nop. The pixenv `li 1` colours follow from
  where the second 256.0f `lui` is scheduled. So the whole window depends on the prepass order of the one-line fog inline.

## New techniques
- **Prototype accessor symbols:** list the prototype's small non-inlined member functions (`objdump -t | grep 4XLib`).
  A field read that resists every statement reordering may be an inline accessor such as GetGuardBandScaleX. Its body
  vregs are created a pass later, which changes the scheduler's order. This fixed a float block that had resisted
  all reorderings.
- **Window micro harness:** cut one basic block into a micro function, then score only that window (opcode plus FP
  registers) against retail. It takes about 0.1 s per variant (X1/m/mt.py, m/e5.py). Check first that the micro
  reproduces the full function's output.
- **Pointer advance per site:** advancing the packet pointer through an inline temp, plus one more wrapper level, rotates
  the colours of the next statement's temporaries.
- **lui immediates:** lab masks lui immediates, so constant OR order (`0x6C000000 | a | b` vs `a | b | 0x6C000000`) only
  shows in check_match. Run check_match as soon as lab reaches its artefact floor.
