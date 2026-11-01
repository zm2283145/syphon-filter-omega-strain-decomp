# P3L final report (2026-11-01)

## Staged (strict MATCH on mw38 and mw50; no UNDEF other than allowed)
| Function | Addr | Size | File |
|---|---|---|---|
| cNPC_HandleMessage | 0x151D30 | 3540 B | build/pending/p3/mw38_00151D30.c |
| cPathRequest_Update | 0x162080 | 4780 B | build/pending/p3/mw38_00162080.c |
| cNPC_UpdateMovement | 0x14BFF0 | 4724 B | build/pending/p3/mw38_0014BFF0.c |
Total: 13,044 B. STATUS.md lines appended at 12:06, 12:32, 13:05.

## Not matched
- cMachine_NextFrame 0x167C40: still 10 gd lines after the time-box (mn/n19_d.c is the best draft). Quit-box colours are
  fixed through an inline PushQ helper; what remains is fe load scheduling plus the viewport a1/a3 pointer (see NOTES.md).
- ColQuery_InitSweep + cCollisionProbe_SphereSweptRay_Reset_2 unit: InitSweep has no prototype; Reset_2 frame is 240 B
  larger than the prototype's and is heavy matrix inlines. Not attempted.
- CameraCol_Sweep 0x20D680: no prototype counterpart (+824 B vs nearest). Not attempted.
- cPlayerCamera_UpdateMotion 0x280690: prototype substantially different. Not attempted.
- GridProcessDataPack 0x2EE798: ee-gcc2.96 Medius library; earlier lanes reached 342-647 diffs. Skipped.

## Reusable lessons (details in NOTES.md)
- Named locals (including inline params/locals) are coloured after temporaries; use CSE'd temporaries or conversions
  to move a value to a later register.
- When stuck on helper-shaped differences, grid the helper definitions (tools/var.py) instead of mutating the body.
- A seemingly dead load can be an argument of a real multi-argument signature (NetGetMyClientIndex(int*, int)).
- Tools: tools/pcmp.py, pl.sh, gd.py (-A), var.py.
