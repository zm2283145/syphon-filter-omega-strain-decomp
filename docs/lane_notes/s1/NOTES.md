# S1 notes (2026-11-02) - ActorPhys_RunResponse 0x1E2180 (12016 B, ends 0x1E5070 - NOT 0x1E50A0)

Tools (build/agents/S1/):
- sec.py draft.c [-n] [-w HEX] [-s LO HI] [-o mine.s] [-q]: lab diff vs retail + per-window diff counts; -s prints the
  aligned side-by-side for retail offsets LO..HI (hex, relative to function start).
- slotmap.py draft.c [LO HI]: maps every retail sp offset to ours (sp-masked alignment); `**` = mismatched slot.
- runs.py file.s LO HI: slots in [LO,HI) descending with first-use code offset (shows named / main-temp / pass runs).
- grp.py draft.c: retail temp groups (G0 main-text temps, G1, G2 = pass-1 inline locals, G3 = pass 2) vs our slots.
- v.py base.c out.c old new [...]: literal substitution + diff (sp / nosp).
- m/mh.sh OPEQ BODY: micro harness (NOTE: base.c has no volatile asm in f, so it is NOT in the less-optimised mode).
- retail.s / retail_ann.s (retail disasm, calls annotated), proto.s (prototype 0x1D79D0 with .line).

## Function: ActorPhys_RunResponse = proto cHumanCollisionRoutine::NextFrame_FloorCollision (0x1D79D0, SCUS_973.97)
Params (retail regs): a0 this(s5), a1 eventReceiver (spill 0x1DC), f12 timeStep(f20), f13 2nd float (spill 0xDC),
a2 faceList(s4), a3 deltaPosFromTransport(s3), t0 velocityFromTransport (spill 0x1D8).
Retail IS in the less-optimised mode (b;nop;nop, duplicated `lw a0,300(sp)` loads, unoptimised loops). The draft
is already in mode through the volatile Q1_L/Q1D_L copies.

## Progress (lab diff, sp / nosp)
| draft | diff | nosp | change |
|---|---|---|---|
| ar0.c (= k8 ar_best.c) | 954 | 411 | baseline |
| ar1.c | 946 | 401 | drop the `opt_propagation off` / `opt_common_subs off` pragmas (mode makes them no-ops / slightly worse) |
| ar3.c | 946 | 401 | named scalar decl order `unsigned char moveAdj; int n, i; unsigned char hit;` first in the collision block |
| ar4.c | 1025 | 401 | NodePos blocks: `char* nd = m->p20 + 0x15C0; VV* pp = NodePos_L(nd);` -> frame 0x14D0 = retail |
| ar5.c | 624 | 409 | v860 written as temp `VV(0.0f, 0.0f, h, 0.0f)` in the SubV_L call -> 0x870..0x14D0 all slots right |

Per 0x400 window (ar5, sp): 0:32 400:21 800:53 c00:47 1000:54 1400:79 1800:84 1c00:41 2000:99 2400:37 2800:52 2c00:25

## Frame facts (retail)
- Scalar region 0xD0..0x1E0. 16-byte-aligned slots = memory-resident locals (mode): descending wasDC 1C0,
  moveAdj 1B0, numTimes 1A0, i 190, hit 180, NodePos node#1 170, pos#1 160, node#2 150, pos#2 140; then 6 packed
  RA-spill words 130 (&D_004E1D90 zero vec), 12C (GetTransform_WorldSpace(r1) result, ledge block), 128/124/120
  (cSkaAnimAnchor_GetPosition results), 11C (GetFace result `tri`); then 100 fb (CalcQueryHeight bool),
  F0 m50 (p->mdl+0x50 in the else branch); E0 = 128-bit spill of cQuatVec_Rotation result; D4/D8 floats, DC = f13.
- Model that fits both retail and ours: named locals (source order) > spilled temps > inline locals; spilled
  named locals get packed 4-byte slots, memory-resident ones 16-byte slots. So retail's fb, m50, tri, plc are NOT
  named locals of the main text (ours are); retail's node/pos pointers ARE named (now done in ar4).
- Top region: named locals 0x14C0..0xE10 in decl order; main-text temps 0xE00 (@0x150 = ScaleV return) down to
  0x690 (@0x2E40) in code order; G1 0x680/0x670 (@1D88, @2B48); G2 0x660..0x2F0 = one run in code order
  0x138..0x1E08 (pass 1); G3 0x280..0x1E0 (@1E3C..@2D2C, pass 2).
- Ours (ar5): main temps OK down to 0x7F0; then retail G0 items @1B0C..@1BD4, @2170, @232C, @2550, @2590, @27A8,
  @280C, @2A44, @2B4C.. are inline locals in ours (they must be main-text temps); retail G2 is split over our
  passes 1/2/3 (e.g. ScaleV @138, SubR_L @294, @6C0, @71C, @8E8 are pass 2 in ours; @774, @848, @1110.. pass 3).
- `*d = f()` (assignment from a by-value call) defers f's body one pass (also with implicit operator=, with
  a member operator*, with `.To()` member on the temp, with Q1_L(&d, &f())); `VV x = f()` / `const VV& r = f()`
  keep it in pass 1 but then the result is a named slot. Retail has ScaleV's body in pass 1 AND its result in a
  main-text temp (0xE00): form not found yet.

## Session progress 2 (lab diff sp / nosp)
| draft | diff | nosp | change |
|---|---|---|---|
| x8..x15 | 627 | 409 | pass-depth regrouping (no code change): SubI wrapper (`static VV SubI(a,b){return a-b;}`) on every `VV x = a - b` init; SubtractTo_L one level deeper (SubtractTo0_L); LerpR_L / SubR2_L / MMR_L flattened (body copied, not forwarded); MMR2_L kept nested for the ladder-space l1140/l1110 sites |
| ar6.c | 623 | 409 | CtlUpd written in main text: `F14((VV*)&(NodeP_L(c) - AV(l10B0)))` with `struct P4` (asm copy ctor), `const P4& NodeP_L(c)` and `operator-(P4 a, const VV& b)` -> retail temps 0x7E0/0x7D0 exact |
| x22 | 591 | 365 | `if (both)` lerps use LerpVV_L (LerpV_L shape: V4 t; ctor_void; pa; pb; pt = &t) |
| ar7 | 601 | 375 | velocity via `const V4& PMVel_L(char* pm) { return *(V4*)(pm + 0x30); }` (retail keeps &p->0x310 in v1) |
| ar8 | 587 | 357 | 2nd floor probe: direct `cCollisionProbe_SphereSweptRay_Reset(&res, a2, 1.0f, 0.05f, 0.05f, 0.0f, 1.0f, &l10C0, (V4*)&VV(0,0,-15.5f,0), 0)` |
| ar9 | 576 | 346 | `float oldE0; float h;` (oldE0 first = f22 like proto prevFloorZ) |
| ar10 | 569 | 339 | f390 block: `float one, lim;` + ClampY_L |
| ar11 | 566 | 336 | dh else-branch: `float y = h + d1460.z; float r = p->f370; float fz = pp->z + a3->z; dh = (y - r) - fz;` |
| ar12 | 563 | 333 | `sum = W_L(r1) + W_L(r2)` (inline getter), both = Both2_L(sum, r0) with lazy `W_L(rt) > 0.0f` |
| ar13 | 551 | 318 | UM_L with `void* m = m0;` pointer copy |
| ar16 | 533 | 301 | ledge clamp: `if (d < p->f370) { float k = p->f370 / d; ...}`; `!(-v.y <= GetZv_L(v))` (z through an accessor so y loads first) in both ledge/ladder blocks |
| ar17 | 530 | 295 | operator- as a VV MEMBER (`VV operator-(const VV& b) const`) instead of a free function |
| ar18 | 525 | 285 | bone sites `VV l1050 = BoneTrans(...) - AV(l1070)` (no SubI); `((d1460 - AV(g1200)) - X).z` direct |
| ar19/ar20 | 487 | 243 | `Q1D_L(&dst, &(expr))` instead of `AV(dst) = expr` (member operator= materialises `this`): l10A0, pos11B0, l10D0, l10E0 sites (greedy.py) |
| ar21 | 478 | 235 | ChildOff_L takes `Phys_L* p` and builds `VV(0,0,-p->f394,1)` inside (late load); zero-quat copy via Cp2X (`ss = s; dd = d` order) |
| ar22 | 468 | 222 | switch cases ordered 5/1, 9, 11, 10/default (MW emits the compare chain in reverse source order: retail tests 10, 11, 9, 1, 5); l1080 lerp `Q1D_L(&l1080, &LerpVV_L(...))` |
| z3 | 524* | 222 | (*frame-only) plc as inline param `XfP_L(v, plc)` -> the 6 RA-spill words become one contiguous group |
| z5 = ar_best.c | 463 | 222 | z3 + fb as inline param evaluated early: `CQH2_L(p, ((p->flags >> 1) & 1) != 0, r0, &d1480, &hz, &hs)` -> fb slot 0x100 right, tri 0x11C right |

## Current state (ar_best.c): lab 463 / nosp 222, frame 0x14D0 = retail, 118 mismatched sp slots
Per 0x400 (sp): 0:17 400:17 800:24 c00:32 1000:29 1400:55 1800:48 1c00:38 2000:98 2400:37 2800:44 2c00:24
Per 0x400 (nosp): 0:5 400:3 800:13 c00:12 1000:7 1400:19 1800:14 1c00:12 2000:78 2400:29 2800:18 2c00:12

## Remaining (by area, retail offsets)
- Scalar region: m50 (retail 0xF0, an inline local after fb) is still a named local at 0x170 in ours; z6.c makes it an
  inline param (`F90_L(AV(l10D0), p->mdl->m50, r0, h)`) -> scalar slots almost right (7 left: plc/GetPos spills are then
  allocated after the inline params instead of before) but the temp region shifts (482). Retail spill order:
  130 ZeroF, 12C plc, 128/124/120 GetPosition results, 11C tri, then inline locals 100 fb, F0 m50.
- Temp region 0x1E0..0x7E0 (~100 slots): see grp.py/runs.py. Retail G2 (0x660..0x2F0) is one pass in code order;
  ours still has extra items in the pass before it (CtlUpd op- t @1B14 stays there whatever form; Grav_L/Water_L
  locals @1B78/@1BDC/@1BB4 and RayQInit org @1E10 must move one pass deeper; @1E44 RayRun, @1EFC T270, @214C
  ScaleToR, @2444/@2508 PlaneH temps, @29A4, @2C20 QSub, @2D1C ChildOff must go to G3) and retail main-text temps
  @2170 @232C @2550 @2590 @27A8 @280C @2A44 @2B4C.. are inline locals in ours.
- Code (nosp) hot spots: 0x2040-0x2120 floor force block (`top` gets f2 not f1; v/lim scheduling: retail hoists the
  g_GameGravity.z load to the block start, as in the prototype lines 2991/2994), 0x2300-0x2700 k8's floor-normal /
  slope block (named float constants c015/n025/..., Remap_L; prototype differs here - toe logic), 0x16E8 VV(0,0,h,0)
  temp stores vs m50 order, 0x1A00 IsZero4 address reg (a1 in retail/proto), 0x0900 pos11B0 copy vs UM_L m colours,
  0x0564 hasSum andi placement + extra nop after both's daddiu.
- Tried without gain: decl order of off/hi/top; `top` as expression; lim as separate statement; Both forms
  (direct/inline/bool expr); pos11B0 copy helper grid; UM_L MW-asm forms; TgtPos_L / M50_L::Mul for m50 (frame
  breaks: by-value return adds a copy); SubP4/SubQ_L wrappers for CtlUpd (extra copy).
## Model notes (verified on this function)
- `*d = f()` defers f's body one pass; `VV x = f()` does not; inline wrapper `SubI(a,b){return a-b;}` pushes op-'s
  local one pass deeper; an inline with NO locals adds no slots itself (harness m/ with `VV::Sub`/`VV::Sub2`).
- Member functions (operator-, operator=) materialise `this` early in this mode: `Q1D_L(&dst, &expr)` beats
  `AV(dst) = expr` wherever retail computes the source address first.
- Reference-returning inline accessor (`const V4& PMVel_L(pm)`) keeps the address in a register like retail.
- Declaration order of plain float locals did not change colours here; creation order (first def) does.
## Next idea
1. Take z6.c's F90_L for m50 and then re-group the temp region pass by pass with grp.py (target retail G0/G2/G3).
2. Floor force block: try writing lim's `5.0f * g_GameGravity.z` before v (prototype line order 2991/2994 is
   interleaved by the scheduler; ours never hoists the load).
3. Rewrite the 0x2300-0x2700 slope block from the retail asm (k8's named float constants look like workarounds).
