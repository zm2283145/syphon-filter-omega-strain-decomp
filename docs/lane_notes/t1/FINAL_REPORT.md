# T1 final report (2026-11-02)

## Staged (strict MATCH, mw38)
| Function | Addr | Size | File |
|---|---|---|---|
| ColQuery_InitSweep | 0x3C6FC0 | 2228 B | build/pending/t1/mw38_003C6FC0.c (from T1/is_clean.c) |

The function sits alone in asm/2C6FC0.s and its boundaries are 16-byte aligned. Built from the matched Reset_2 source
(0x3C66B0). Owner review: it uses the pending dead-block idiom. A commented `if (0) { iterators; 3 matrix products }`
reproduces retail's unreferenced frame holes, the same family as Reset_2's placeholder block. Details are in NOTES.md.

## Not matched
- func_003E57B0 (DestinationParams::Pack): the best C-only draft is T1/dp_best105_c.c (105 lab lines). T1/dp_best90.c reaches 90
  lab lines with volatile `lwc1` asm accessors, which the rules do not allow. Key finding: retail's dead `move rX,zero`,
  repeated dsll32/dsra32 / andi pairs and unfolded addresses come from a basic-block-local effect of a preceding volatile
  asm with an output operand. The trigger in retail's affected blocks is still unknown.
- CameraCol_Sweep: recon only (structure in NOTES.md), not drafted.

## Lessons
- Frame holes in the less-optimised mode can be matched as dead-block placeholders per slot class: small iterators go to
  the frame top, `x = a * b` gives one main-level return temp plus one depth-1 `r`.
- A 3-operand VU0 multiply `Mul(d, a, b)` covers both pre- and post-multiplication into a member matrix with no copies.
- An address that retail computes early and loads late (`addiu v0,a0,4` ... `lwc1 f12,0(v0)`) came from a 3-level
  by-value float pass-through ending in `{ const float* p = &v.y; return *p; }`. With one level it is early but in the wrong register.
- S3's `MulCopy` (CopyOfM) pass fixed an a1/a2/a3 rotation in ret-copy blocks here too.
