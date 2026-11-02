# Q4 final report (2026-11-01 night)

Staged (both check_match MATCH, no UNDEF, no DATA):
- build/pending/q4/mw38_001A0B30.c  cHuman_Land 0x1A0B30 (2232 B)   (source: build/agents/Q4/ld_match.c)
- build/pending/q4/mw38_001A1C80.c  cHuman_GrabLedge 0x1A1C80 (2032 B) (source: build/agents/Q4/gl_match.c)

Not solved: cHuman_HandleJumpInit 0x1914C0 stays at Q2's hj_best16.c (16 lab lines, case-21 copy block).

Key finding (applies beyond these functions): retail Land and GrabLedge are compiled in MW's less-optimised
mode, which any volatile asm in the function selects (MW `asm volatile {}` or GCC `__asm__ volatile`;
non-volatile asm does not). Signs: cString/name-copy loops not strength-reduced, checkpoint `this` kept in its
own s-register (`move s3,s2`), CSE'd addresses recomputed, `b; nop` branches, RandRange's n kept as an int
across Libc_Rand. The trigger works from inside an `if (0)` block, where it emits nothing, and in that mode a
dead block also keeps its stack slots. That reproduced Land's two unreferenced frame holes, which n5 could not
get.

Reviewer flag: both staged files use `if (0) { asm volatile { nop } }`, an asm that emits no instruction and
only selects the compiler mode (commented in the source). In Land, the dead block around it also holds the
third request block that gives the frame holes. If the coordinator rejects this under the inline-asm rule, the
alternatives are a live volatile asm, which adds an instruction or blocks the cvt.w.s scheduling, or leaving
both functions unmatched.

Details, tried lists and next ideas: build/agents/Q4/NOTES.md.
