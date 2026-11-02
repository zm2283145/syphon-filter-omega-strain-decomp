# V3 final report (2026-11-02)

Nothing staged (no full match).

## cHuman_HandleJumpInit 0x1914C0 (4608 B): lab 16 -> 2 lines, check_match 3 words (0x6d4..0x6dc)
- Best draft: build/agents/V3/hj_best2.c. The case-21 message copy block now matches retail instruction for
  instruction except one extra `nop` (the trigger) where retail has an empty `beqz` delay slot.
- Recipe: MsgCopy_L = `asm volatile { nop }` first, `__int128*` pointers to both vec members, vt/field copies,
  then a plain C `*pd = *ps;` last. The C copy last lets the scheduler hoist the QueueMessage args (retail); the
  instruction-emitting volatile asm in the same basic block stops MW folding the quad-copy offsets and coalescing
  the copy base with a0 (retail's `addiu t1,s1,48 / addiu t2,t3,48 ... lq/sq` last), and also keeps the whole
  function in filled-slot mode without the old `asm { .set reorder }` barrier.
- Not acceptable as is: the trigger emits an instruction retail does not have. Zero-emission asms (empty MW/GCC
  asm, `.set reorder`, labels, empty asm with outputs, dead `if (0)` blocks) do not trigger the block-local mode.

- Follow-up (coordinator): count is equal (1152) with the nop present; MW never fills a delay slot with a
  volatile asm nop (two nops when it is first), `.set noreorder` wrapping loses the trigger, and moving the t3 base
  after the asm or the nop into other inlines/paths does not help. No match; details in NOTES.md "HJ follow-up".

## CameraCol_Sweep 0x20D680 (2136 B): still 16 lab lines (build/agents/V3/cs_best16.c = U3 cs20)
- Re-ran all 792 prototype interleavings on the current best (floor 16) and a new 2^11 per-argument
  "assignment expression" grid scored per call window; tried local pointer/float copies at three positions,
  49 forms of the 0.05f constants, inline wrappers in several parameter orders, MW/GCC and non-volatile M asm.
  Nothing beats 16. Details and the gen-order observations are in NOTES.md.

## New technique worth recording
- Block-local unoptimised mode trigger: an instruction-emitting volatile asm (even `asm volatile { nop }`) in the
  same basic block makes MW keep address computations in their own registers (no `lq 48(s1)` offset folding, no
  coalescing of an object's base with the call's a0) while still letting the pre-RA scheduler hoist later call
  arguments across the C code. Zero-emission volatile asms do not do this. Useful for locating retail's real trigger.
