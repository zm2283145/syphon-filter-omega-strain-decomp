# Q1 final report (2026-11-01)

Nothing staged. No target reached MATCH.

| Target | Best draft | Lab lines | Notes |
|---|---|---|---|
| cHuman_HandleJumpInit 0x1914C0 | best/hj_best.c (= P8L) | 22 | new facts on "unfilled mode" and the case-21 copy, see NOTES |
| cHuman_HandleMoveMessage<1> 0x1BC4B0 | best/hm1_best.c | 33 (check_match +46) | new draft: retail <1> = retail <0> + tail; tail matches; residual identical to <0> |
| cHuman_HandleMoveMessage<0> 0x1BB1D0 | p2l hm2.c | 33 (+46) | unchanged; any fix carries over to <1> |
| cHuman_HandleDeath 0x18A950 | k8 pG.c | 21 | looked only |
| cHuman_NextFrame 0x1B1710 | - | - | not attempted |

Key findings
1. HandleJumpInit "unfilled mode" (no delay-slot filling anywhere) is not caused by C-level 128-bit copies
   as such. The trigger is a C-level 128-bit copy of msg->vec plus the later asm copy
   `QCp1_L(self->jump.plc.p, &msg->vec)`. An `asm { .set reorder }` right after that jump copy restores
   filled mode (best/hj_ccopy37.c, 37 lines). With the C copy last, the case-21 block takes retail's shape,
   but MW folds the copy offsets and merges pc with the call's a0.
2. MW parses and optimizes non-volatile asm (both GCC-style `__asm__` and MW `asm {}`) like C, so offsets
   are folded. Only `asm volatile` keeps retail's pointer-register operands, and `asm volatile` blocks the
   pre-RA hoisting of the QueueMessage arguments (64 lines). In retail both happen at once; no form found does that.
3. HandleMoveMessage<1> differs from <0> only by its tail, plus ctrl in s1. The <0> draft plus that tail gives
   exactly <0>'s residual: msg/edge s4<->s2 swap, one andi, one addiu order. Mapping tables for
   declaration order and colour are in NOTES.

Tools in build/agents/Q1: l.sh/hj.sh/hm1.sh/hd.sh (lab diffs), fill.sh (counts unfilled delay slots),
linebis.py (delete each statement and report fill mode), grid1-3.py, rdis.py, m/mc.sh (micro compile).
