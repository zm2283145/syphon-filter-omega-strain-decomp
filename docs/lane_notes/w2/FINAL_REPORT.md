# W2 final report (2026-11-02)

## XLib_ApplyContext 0x37C870 (4,388 B): not matched, best 36 lab lines (was 521), exact size
- Draft: build/agents/W2/ac_best36.c (1097/1097 instructions; check_match about 35 differing words; 6 of the 36 lab
  lines are masking artefacts).
- **It cannot be staged as is:** the 16 one-quadword UNPACK copies (AddV4) are written as CW `asm volatile { .set noreorder;
  lw/sw ...; .set reorder }`. Evidence that the original was asm too: retail's two-register copy, with a materialised source pointer, occurs nowhere else in
  the retail .text. Micro tests show that no C or struct copy produces it (word arrays give FPR blocks, explicit pairs fold
  offsets). Only a volatile CW asm keeps the pointer in a register and the text in order. **This needs an owner decision.**
- New techniques:
  * `.set noreorder` / `.set reorder` inside a CW `asm volatile {}` stops MW scheduling C instructions into the block
    (without them MW interleaves C loads/ors between asm lines; GCC `__asm__ volatile` text is also split and scheduled).
  * MW CSEs a pointer local used by a non-volatile CW `asm { lq; sq }` copy with a later inline's pointer parameter
    (clipPrimTag); a GCC-asm copy keeps them separate.
  * An inline wrapper one level deeper (`Add32V2(v){ Add32V(v); }`) rotates three caller-saved colours (-7 lines).
  * Per-call-site greedy over generated helper forms (W2 gen.py/search.py/joint.py), about 0.1 s per variant.
- Remaining differences: a0/a1 swap at the first AddUnpack, and the uv-scale float block's schedule (retail starts with
  the gbScaleX chain; ours starts with uScl). Both resisted every variant tried (NOTES.md).

## XLib_Init 0x37E780: reviewed only, still at t3's 52 (docs/lane_notes/t3/drafts/xi_best52.c)
