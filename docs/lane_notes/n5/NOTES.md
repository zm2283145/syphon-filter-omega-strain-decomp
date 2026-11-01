# N5 notes (r215+ session 2, 2026-11-01): N3 near misses + big functions

Work dir build/agents/N5/s2/ (wd/, pi/, ...). Tools: s2/tools/vt (variant batches: prints check_match word
count "cm=", bd positional, bd seq), s2/tools/prune.py (N3's, own tmp path). N3's bd for byte diffs.

## 00440580 GuiWeaponDisplay_onRender (2388 B) — start N3 wd/c5.c 43 pos / 40 seq — MATCH 03:00
- Member op* `{ V4 r; const V4* p=this; MulT(&r,p,s); return r; }` (MulT = MW asm volatile, t=0 inside):
  fixes the whole rc 0.5f*(a+b) block + matrix-constant scheduling (43 -> 14).
- Center sum through a free `AddX(a,b)` whose VU0 add is a GCC `__asm__ volatile` with `"+r"(d)`: the asm
  "modifies" d, so the return copy re-derives &r (retail's late `addiu v1,sp,64`) and is scheduled after
  the scale set-up instead of right after the sqc2. Every other form (depth wrappers, by-value params,
  in-place ctor, non-volatile copies, MW asm copies) kept the copy hoisted or broke paddub/CSE.
- Return copies of op+/AddX as tagged ctor `V4(const V4&, short) { const V4* ps=&o; asm volatile { lq ps,
  0(ps); sq ps, 0(this) } }`: no dead `this` addiu, and the data register is the source pointer register
  (retail `lq v1,0(v1)` / `lq a0,0(a0)`) (14 -> 2).
- `m.Translate(c * -s)` -> `MulH(c, -s)` with GCC asm and `V4 r; V4* d=&r; const V4* p=&v; __int128 t=0;`
  (p materialised before paddub) -> MATCH. Unused MulS/MulD/Zero4 pruned. Final: s2/wd/wd_final.c.
- Observations: non-volatile asm anywhere in a copy lets MW delete the dead `t=0` (paddub) and CSE
  addresses; the lq/sq of asm copies are scheduled individually (MW asm blocks too).

## 0024B5D0 PlayerInput_Update (17792 B) — start N3 pi/p9.c 43 pos / 36 seq — best s2/pi/pi_best.c 32 / 26
- c.eq.s operand order (both sites): `unsigned char sq = (bool)b.f[5];` and `(s + i)[0xA4] = (bool)b.f[i];`
  (float->bool conversion gives retail's `c.eq.s $f1(x),$f0(0)`; `x != 0.0f` / `0.0f != x` both give the other order).
- case-8 bigWalk: Bounds8 sets `f = 1` only in the then-arm (else leaves it unset) and the caller does
  `bigWalk = (bool)w` -> single `li v0,1` after the join like retail (32). Retail then has `andi v0,v0,0xff`, ours
  `sltu v0,zero,v0`; every other conversion/type (uchar/short/bool refs, U8 helpers, (unsigned char)) folds the andi.
- Open (all tried, no gain): LimitManualAim — retail materialises the f14 1e-6 first (between the ZeroV address
  and the tgt lq); constants bound before the copy land before the ZeroV address instead (z1/a: 36-38), after it
  they stay after the copy; split lq/sq asm with the constant between: no change. spd: retail `mtc1 zero,$f30`
  (spd = 0) but `spd = 0.0f` lets MW drop it as redundant and recolour all floats (2000+); N3's `spd = mv.z` kept.
  H2b: retail order dead-addiu(&t), sub.s, &ang3, paddub; moving the dead `xx=&t` or `d` earlier drops the
  dead addiu. case-5 sum: retail loads d1.x,d0.x,d0.y,d1.y and stores x first; ~40 sum/temp forms tried.
  MkXf: retail `addiu a0,s0,48` before `move a1,s5`; member-call/struct-member/reference/const-ref forms no change.

## 001D02B0 cHumanIkRoutine_CalculateResultPose — unchanged 127 (pure register permutation)
- Every hunk is the same colouring permutation: retail gives the hoisted switch constants 4/3/2/1 t5..t2 and the
  stack addresses v1..a3, ours the opposite (constants v1..a2). Tried with no change at all: opt_* pragmas
  (rotateloops, loop_invariants, propagation, common_subs, lifetimes, strength_reduction, dead_code, level 3,
  unroll), Begin/End through extra wrapper levels or an EndP/DataP helper, switch as if-chain / int / uchar /
  local copy of src, volatile vs non-volatile on each of the 4 asms (16 combos).

## 001A0B30 cHuman_Land — rebuilt on N2's cHuman_Fall (fc1.c, 5 words) infrastructure: s2/ld/ld2.c, ld3.c
- ld2: extern static objects D_0049D100/120/140 (from D_0049E148) and D_0049D160 (D_0049E160) with guards
  D_004EEE20/28/30/38 and cString16N::Init (no .bss DATA), slot-64 GetHealthState (retail `lw t9,264(t9)`),
  IsDead as a flag with two compares. ld3 = ld2 + `opt_strength_reduction off` + `opt_rotateloops off`:
  the init loops then have retail's shape except the else-arm `s[i]` reload (cross-block CSE in ours).
- Blockers: retail frame 0x3A0 has two unreferenced holes (816..920 = 104 B after `it`, 496..624 = 128 B =
  2 cMsg) that look like the slots of a third, eliminated request block; unused locals, `if (0)`, inline
  constant conditions and `int useX = 0` all free their slots in our build. Retail places the else-branch
  cp3/cfd below the messages (temporaries). First AddRequest has Fall's exact argument schedule (the open
  Fall problem); the second has its own.
- Loop shape finding: Fall's cString16N::Init loops come out un-optimised (indexed, `b` to the test, reload)
  while the same code in Land is strength-reduced; adding/removing a plain store or call after the inits in
  Fall-derived tests flips it, so it is a heuristic of the surrounding code, not the loop source.

## 001A1590 cHuman_Fall (N2's fc1.c, 5 words) — not solved
- Wrapper parameter order (all 720 permutations of id/mode/cf/pg/m1/m2): no effect (all 5).
- `int* blend` declared at the use site instead of the top: same argument schedule, s0/s1 swapped (30).

## 0037E780 XLib_Init (k3 fx_ini.c, 339 seq) — not worked beyond a check
- The ResetGraph branch k3 listed is already right in fx_ini.c; first hunks are the gbScale/isDirty `li 1`
  colouring and the SetBuffers argument-load and zero-extension order. Permuting frame1's four OR terms: no
  permutation beats the original.
