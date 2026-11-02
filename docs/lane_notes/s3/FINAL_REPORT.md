# S3 final report (2026-11-02)

## Staged (strict MATCH, mw38)
| Function | Addr | Size | File |
|---|---|---|---|
| cPlayerCamera_UpdateMotion | 0x280690 | 2188 B | build/pending/s3/mw38_00280690.c (from pc_match.c) |
| cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2 | 0x3C66B0 | 2316 B | build/pending/s3/mw38_003C66B0.c (from rs_clean.c) |

The 0x3C66B0 asm unit also holds ColQuery_InitSweep (0x3C6FC0); Reset_2's boundaries are 16-byte aligned, so it is
staged alone (the integrator splits the unit).

## Not attempted / not matched
- ColQuery_InitSweep 0x3C6FC0: shares Reset_2's prologue, transforms and tail (same named start/path locals, plus
  path.x/z *= 1/path.y), adds a tanf(0.5*fov) scale-matrix branch, two VU0 SetUnit()s and a call to func_003BF760 with
  a by-value matrix. rs_clean.c's helpers are the right starting point. Not drafted.
- CameraCol_Sweep 0x20D680, func_003E57B0, GridProcessDataPack: not attempted (time went into Reset_2).

## Lessons (details in NOTES.md)
- In MW's less-optimised mode, routing a copy through a by-value pass-through inline (`CopyOf(v) { return v; }`)
  creates its temps one pass later: it moves register colours without changing stack slots (fixed three clusters).
- Frame holes in the mode can be reproduced with a dead `if (0) { named locals; temporaries; }` block.
- STL iterator tags: pointer iterators are random_access; slicing a random_access_iterator_tag() temp into a
  forward_iterator_tag by-value argument of an extern call gives the lbu/sb/lb copy, with the arg slot allocated first.
- cPlayerCamera_UpdateMotion: asm operand order (r, a, b) plus one pass-through wrapper fixed the last colouring swap.
