# P5L final report (session 2026-11-01, 13:08-15:34)

## Staged (all `[mw38] ...: MATCH`, no UNDEF, no DATA lines; one function per file)
| file | function | size |
| --- | --- | --- |
| build/pending/p5/mw38_00192800.c | cHuman_HandleRunningJumpOffLedge | 1956 B |
| build/pending/p5/mw38_003E8190.c | cInterfaceElement_DrawText | 1592 B |
| build/pending/p5/mw38_002BF4B0.c | GuiEquipmentModify_DrawGun | 1504 B |
| build/pending/p5/mw38_0045AE70.c | cFlashlight_Update | 1940 B |
| build/pending/p5/mw38_001E9980.c | cHumanCollisionRoutine_NextFrame | 1972 B |
All five are single-function asm units in config/splat.yaml. Sources of record: rj/final.c, dt/final.c,
dg/dg_final.c, fl/final.c, cr/final.c. STATUS.md has a line for each.
Externs used for unnamed data: D_00497A00/D_00497A08 (flashlight MaxRG/MaxB tunables), D_004A03D0 (FindByKey key),
func_00133EC0 (unnamed callee, bone-matrix GetPosition).

## Near misses (drafts kept in build/agents/P5L/)
- 0025CDC0 cGrenade_CalculateArcPoints: 11 gd lines (ap/best.c). Left: one copy-source register in the Cross block
  (a tagged dead-xx return reaches 6 lines but adds 2 instructions) and the gravity multiply operand order.
- 003BDA00 SphereSweptRay_DetectForCollision_AccountForMovementOfCollidingObjects: 25 (ss/s12.c, was 37).
- 00410E50 cSubtitleFont_Display: 88 (v/s3_d.c); gif += 2 folding; unfolded stores suggest a disabled pass,
  neither peephole off nor propagation off reproduces it.
- 003ED2E0 cInterfaceModel_Render: 39 (v/rn24_d.c); byte->float colour FPR allocation.
- 00199980 cHuman_Choke_NextFrame: fresh draft ck/c1.c 206 (B1's ck/b1.c 116 with stale names); string-init loop
  strength reduction, RandRange constant, s-register order.
Not attempted beyond triage: cHuman_GrabLedge (unit with cHuman_Fall, 2 AddRequest calls), UpperBodyLook_TargetQuat
(unit with cAimComponent_NextFrame ext issue), 003E57B0 (proto 828 B vs retail 1460 B). P4L's unit left alone.

## Techniques (details in NOTES.md)
- Inline depth decides stack slots: wrap a body 2 extra levels to put its temps below the operator temps.
- Register colouring / argument-setup order follow inline structure, not statement order: by-value helper params,
  per-site helper functions with specific pointer-local orders (MulB, AddB), tagged copy ctors with a dead xx.
  Coordinate descent over per-site forms (ap/cd*.py, ss/cd.py) finds these mechanically.
- A one-level if/return inline shares one result temp across arms and computes its address per arm.
- Micro tests (t/h1.c + cc.py) isolate a construct in seconds.
