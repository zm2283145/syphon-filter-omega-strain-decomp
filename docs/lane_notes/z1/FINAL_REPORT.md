# Lane Z1 final report (2026-11-02)

## Staged
| function | addr | size | file |
|---|---|---|---|
| cGameSound_PlaySound | 0x1C8770 | 1688 B | build/pending/z1/mw38_001C8770.c (check_match MATCH; draft Z1/ps_match.c) |

## Not matched
| function | best | draft |
|---|---|---|
| XLib_DisplayLastFrame 0x37B5C0 | 7 lab lines (unchanged) | docs/lane_notes/k3/drafts/b_37B5C0.c (= Z1/xl0.c) |

## New techniques
- **Named iteration pointer that starts at the object base:** when retail's strength-reduced loop pointer and a derived
  element pointer come out with swapped colours, a named iteration pointer (coloured after the derived named pointer)
  fixes the colours; start it at the object itself (`char* sl = (char*)self`, fx = `sl + 0x50`) instead of at the
  array (`self->slots`) so the array offset stays folded into the accesses. Initialise it in the for-init after the
  counter (`for (i = 0, sl = ...; ...)`) to get retail's `move a3,zero; move a2,s2` order. (PlaySound 7 -> 0.)
- **Loop micro harness:** the PlaySound swap reproduced in a micro function containing only the guard, loop and two
  calls; scoring only the loop window (Z1/score.sh, grid1.py) made the 1296-form access grid take ~4 min.
- **If-converted values have their own colour class (DisplayLastFrame):** a ternary or if/else that MW turns into
  `li; li; movz` is coloured after all named single-def locals, whatever its declaration position; a two-def named
  local that is not if-converted is coloured first. A local struct whose address is never taken is scalar-replaced.
