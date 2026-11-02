# Q2 final report (2026-11-01)

Staged (both consumed by the coordinator):
- Global_Shatter 0x230DE0 (4224 B): build/pending/q2/mw38_00230DE0.c (src: Q2/gs_match.c)
- cHuman_Fall 0x1A1590 (1776 B, unit start; GrabLedge split off): build/pending/q2/mw38_001A1590.c (src: Q2/fc_match.c)

Improved, not matched:
| Function | Before | After | Draft |
|---|---|---|---|
| cHuman_HandleJumpInit 0x1914C0 | lab 22 | lab 16 (only the case-21 msg->vec copy left) | Q2/hj_best16.c |
| cMachine_NextFrame 0x167C40 | gd 10 (cm 22 words) | gd 10 (cm 10 words); quit site 1 is now a pure fe/msg s4/s5 swap | Q2/mn_best10.c |
| cHuman_GrabLedge 0x1A1C80 | not started | gd 215, structure complete | Q2/gl3.c |

Unchanged: DetectForAndHandleCollisionWithOtherHumans (2 words), cGrenade_CalculateArcPoints (11 gd),
PlayerInput_Update (32), cAimComponent_NextFrame (not attempted beyond notes).

Techniques found (details in NOTES.md):
1. Return-by-value one level below the frame owner (Global_Shatter): `V GetNormalizedR() const { V r; return
   NormalizedInto(r); }` with `NormalizedInto(V& r) { r = *this; ...; return *p; }`. The local's slot stays at the
   outer level while the copy pointers are created a pass later, which swaps the copy colours.
2. AddRequest argument order (Fall, also HandleJumpInit's X3/X4): declare the message args as `const T&` and
   pass the message objects themselves; build the playback-group pointer as a named local inside a wrapper that
   takes the blend pointer (`void* pg = b + 1;`). The same recipe should fix cHuman_Land's first AddRequest (n5).
3. Inline args are evaluated right to left (cMachine): putting fe after msg in the inline's parameter list
   loads fe before the GetQuitMessage call.
4. DetectFor: a GCC-style `__asm__(".set reorder; mtc1 $0, %0" : "=f"(r))` is a free-floating zero (MW-style
   asm and plain GCC asm are barriers / noreorder); it gets the first zero early, but the k22 lui colour is still wrong (6 words).
