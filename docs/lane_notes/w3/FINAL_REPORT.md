# W3 final report (2026-11-02 night)

No match staged.

## cHuman_HandleJumpInit (0x001914C0): unchanged at 2 lab lines (V3 hj_best2.c; copy at build/agents/W3/hj_best2.c)
- The prototype `.line` table puts the whole copy block (vt stores, field copies, lq/sq, QueueMessage, dtor) on one
  source line (human.cc 12196), so the original is a single statement building a cCharActionMsg_Vector copy
  (mDestinationType = 4 at +0x20). The prototype code is identical to retail.
- With the vec copy as an instruction-emitting volatile asm (lq only, sq only, both, MW or GCC, register or "m"
  operand, volatile/non-volatile mixes), the block takes retail's shape exactly: unfilled beqz slot, lui v0 first,
  separate base registers, sp-relative `sb v0,1120(sp)`. The one difference is that the volatile asm is a full
  scheduling barrier, so the call-argument set-up (`li v0,4; addiu a0; move a1,s0; move a2,zero`) comes after the
  lq instead of before the copies, and the copy then uses a0-a3 instead of t0-t3 (56-62 lab lines).
  So if retail's trigger is the volatile lq/sq, retail must set up the call arguments before the copy. None of the
  forms tried does that: inline make-and-return, a C++ copy-ctor class chain, Send wrappers that bind
  (msg, self, 0, 4) first, a QueueMessage wrapper.
- Volatile-qualified memory accesses are not block triggers. The draft's `asm { .set reorder }` in NAME_COPY switches
  the whole function to unfilled mode (1170 B), and the emitting volatile asm in the copy block switches it back (1152 B).
  The dead `if (0)` trigger has no effect here.

## ActorPhys_RunResponse (0x001E2180): 371/116 -> 366/111 lab lines (sp / sp masked)
Best draft: build/agents/W3/ar_best111.c. It keeps all call targets and is 3002 instructions (retail 3004).
- An `asm { nop }` before `goto tail` reproduces retail's `sw; b L; nop` with the inner ifs targeting the `b`
  (owner idiom: a real retail nop).
- The rotation-target member address is assigned inside the if condition, `(o = (char*)p + 0x7A0)`, which gives
  retail's delay-slot `addiu` and its reuse.
- Sites tried without gain are listed in NOTES.md: MaxZ colours, the f394 dead nop, the Tele_L mov.s, the ChildOff
  dead addiu, and Remap.

## New technique / observations
- When retail computes a member address in a short-circuit condition's delay slot and reuses it in the body,
  assign the pointer inside the condition: `if (a && *((T*)(o = base + off) + k))`.
- An `asm { nop }` placed just before a `goto`/`b` lands in that branch's delay slot and stops MW from threading jumps
  through the block. This gives retail's "inner ifs target the b; nop" shape without changing the instruction count.
- A volatile asm lq/sq copy that has an output operand is a full scheduling barrier. This tells apart a block whose
  call arguments are set up before an asm trigger from one that has no barrier at all (HandleJumpInit).
