# N5 final report (session 2, 2026-11-01, 02:48-04:10)

(The r113 session's report is now FINAL_REPORT_r113.md.) Work is in build/agents/N5/s2/. Notes are in NOTES.md.

## Staged: 1 function
| Function | Addr | Size | File |
|---|---|---|---|
| GuiWeaponDisplay_onRender | 0x440580 | 2388 B | build/pending/n5/mw38_00440580.c (copy in acc/; source s2/wd/wd_final.c) |

- check_match: MATCH, no UNDEF, no DATA lines.
- The final check ran with no HOLD present. Logged in STATUS.md.
- Callees: GuiWidget_onRender, XLib_ClearZBuffer, gunList_GunRender. Globals: g_Video, D_00538C64, D_00538C68.
- All inline asm is EE/VU0 lq/sq/lqc2/vmul and similar.

How it got from N3's c5.c (43 words) to MATCH:
1. The member `operator*` goes through `MulT(&r, p, s)`, an MW `asm volatile` with `t=0` inside. This fixes the
   0.5f*(a+b) block and the matrix-constant scheduling (43 -> 14).
2. The box-centre sum goes through a free `AddX`. Its VU0 add is a GCC `__asm__ volatile` with the destination as
   `"+r"(d)`. Because the asm "writes" d, the return copy recomputes &r late, as retail does. That puts the copy
   after the scale set-up instead of right after the sqc2.
3. The op+/AddX return copies are a tagged ctor `V4(const V4&, short) { const V4* ps=&o; asm volatile { lq ps,
   0(ps); sq ps, 0(this) } }`. This gives no dead `this` addiu, and the source pointer register is the data
   register, matching retail's `lq v1,0(v1)` (14 -> 2).
4. `c * -s` goes through `MulH`, a GCC asm with d/p bound before `t=0` -> MATCH.

## Improved, not staged
- **PlayerInput_Update 0x24B5D0: 43 -> 32 words (exact size), s2/pi/pi_best.c.**
  - Float->bool conversions `(bool)b.f[i]` fix both c.eq.s operand-order sites.
  - Bounds8 sets the flag only in the then-arm, and the caller does `bigWalk = (bool)w`. This gives retail's
    single `li 1` after the join (ours then has `sltu` where retail has `andi`).
  - Still open, each tried extensively (see NOTES): the LimitManualAim f14 constant, `spd = 0` (MW drops it as
    redundant and recolours all floats), the H2b dead-addiu order, the case-5 sum loads, the case-6 `hi` load
    order, and the MkXf a0/a1 order.
- **cHuman_Land 0x1A0B30: s2/ld/ld2.c / ld3.c.** A rebuild on N2's cHuman_Fall (fc1.c) infrastructure:
  - extern statics and guards, so there are no DATA lines;
  - the right vtable slot;
  - retail-shaped init loops (with two opt pragmas).

  Still far: the frame has two unexplained holes (104 B and 128 B) in retail. The first AddRequest also shares
  Fall's unsolved argument schedule.

## No progress
- CalculateResultPose: still 127. The remaining difference is one register permutation of the hoisted switch
  constants versus the stack addresses.
- XLib_Init: checked only.
- cHuman_Fall (5): all 720 wrapper parameter orders give the same 5.

## Findings worth reusing
- **Making a copy happen late.** When retail recomputes an address that our build CSEs, write the producing asm
  with that pointer as a `"+r"` operand. MW then treats it as clobbered and recomputes it at the next use, and the
  scheduler places that use later.
- **Matching the lq/sq data register.** A copy ctor whose MW asm uses the source pointer variable as the 128-bit
  data register (`lq ps,0(ps); sq ps,0(this)`) reproduces retail copies whose data register equals the address
  register. It also has no dead `this` addiu.
- **Non-volatile asm costs more than scheduling.** A non-volatile asm copy schedules freely, but MW then also
  deletes dead `t=0` paddubs and CSEs addresses. Volatile copies keep both, but their lq is hoisted right after
  the producing store.
- **c.eq.s order.** Float->bool conversion `(bool)f` gives `c.eq.s $x,$zero`. `f != 0.0f` and `0.0f != f` both
  give the reverse.
- **Retail `li 1; andi 0xff`** comes from returning a `bool` variable as unsigned char (cNIEventBase_UpdatePos:
  `bool ok = true; return ok;`). This only holds at a real function return; through an inline it folds.
- **Dead code does not keep stack slots.** Unused locals and dead blocks (`if (0)`, constant inline conditions,
  `int x = 0; if (x)`) lose their stack slots in mw38. Retail holes therefore need another explanation.

## Tools
- s2/tools/vt: variant batches. Prints the check_match word count ("cm="), the bd positional count and the bd
  sequence count. Needs ~/sfos-env.sh, which the wrapper sources.
- s2/tools/prune.py: N3's prune with its own temp file.
- s2/ld/fperm.py: wrapper-parameter permutation search.
