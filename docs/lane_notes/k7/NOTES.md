# k7 lane notes

Tools: `cm.ps1` (check_match wrapper), `work\cdiff.py` (run from repo root; path args relative to root),
`work\var.py BASE.c NAME KIND spec.json` (string-replace variants, 3 parallel cdiff -q).

| ADDR | func | prior best | k7 state |
|---|---|---|---|
| 0022A8C0 | GetCollisionDist | p07col 23 diffs | work\gcd0.c score 30 (cdiff). Only v0/v1 swaps (rp=&r gets v0 in retail) + t9/a0 order before Post. |
| 0034EF10 | onWake | r191_game wake_count_pair.c 10w | |
| 0026C570 | cMap_ObjectiveSelected | r206_parent objective.c 21 | |
| 004073C0 | SKL_CompressSKL | p13xlib best 23 | |
| 00290610 | ResetBBoxContributors | 96 | |
| 0025F930 | DeactivateFx | l8 vf0.c 18 | |
| 002625B0 | cFireObj_ctor | r196 ref_result.c 27 | |
| 00336700 | cAgentData_ctor | r210_audio 70 | |
| 001DD6A0 | cAimComponent_NextFrame | l8 d6a.c 11 | |
| 00166840 | loadingThread | l8 lt3.c 5w | |

## MATCH 0026C570 cMap_ObjectiveSelected -> build\pending\k7\mw38_0026C570.c
From r206 objective.c (5). Keys: (1) `AbsF` with dead `float r = 0.0f;` before `asm { abs.s r, a }`
(that dead zero is the retail late `mtc1 zero,f2` next to `mtc1 v1,f2`); (2) member
`float V::Length() const { float r = 0.0f; const V* p = this; int t; asm {... qmfc2.ni t, vf4; mtc1 t, r} return r; }`
(form from matched map\func_0026E070.c) called inline: `V offset = Sub(...); float k = D * (20.0f + offset.Length());`.
Member operator- instead of Sub was worse (17).

## GetCollisionDist tried (no change, score 30)
operator* local decl order, asm operand order (ap/rp), MW asm-block operator*, Length local order,
operator- local order, copy-ctor forms (this/d/s locals), Q16 operand order / no memory clobber,
"r"(&r)/"m"(r) constraints, Mul helper, ctor-based operator* (`V r(a,s,0)`), mw50 (same 30).
Worse: `int/void* where` hoisted (35, s0/s1 swap), no peephole off (38), asm-block without noreorder (33).

## 002625B0 cFireObj_ctor (k7)
- base r196 ref_result.c = 27 (slots for add/mul temps swapped). fire-unit forms (from src fire\func_00261DF0.c: AddV/SubV/ScaleV helper inlines, ScaleR, operator*(a,s)->ScaleR, copy ctor asm block) + ScaleV `__int128 t = 0` (paddub) + expr `(max + min) * 0.5f` -> **24** (work\fo7.c): slots right; residual coloring of copy (retail src/data a0, dest a1, pv a2, pr v1; ours v1/a0/a1/a3).
- No gain: decl orders, member ops, refResult, by-value, volatile on/off grid, float-first operator* wrappers.


## 00336700 cAgentData_ctor (k7) 54 -> 42 (work\ad_best42.c)
- base r210 agent_owned_dtors.c (=work\ad0.c, 54). Gain: drop RA2 inline dtor, give Ach explicit
  `~Ach() { cArray_eRequirementState_dtor(&reqs, -1); }` (kills MW `beqz` null-check of inline member dtor, hoists s7 dtor arg).
- Retail facts (early proto locals: i=s4, j=s3, j=s0): i*16 IV (s0) + table ptr IV (s1), `addu v0,s0,s5` per inner iter,
  j*24 NOT strength-reduced, &tmp kept in fp and &tmp.reqs in s6 each iteration (not hoisted), dtor arg s7 hoisted, frame 0xC0.
- Ours: j*24 SR'd (s0+=0x18), &tmp rematerialised, frame 0xB0. All of these gave identical 42: ctor/Resize splits, `p=this`,
  named temp, AddA/Add wrapper inlines, exceptions on/off, opt_lifetimes on/off, Tbl At()/operator[]/Size().
- Natural (no asm barrier) i/j loops: 75-78 (MW folds `this+0xAA8+i*16` into a pointer IV); inline accessors/params are
  copy-propagated and don't stop it. `opt_strength_reduction off` worse (70/102).

## 0034EF10 onWake (k7) 11 (work\ow0.c) / 14 (ow_p0.c)
- Only loop-var coloring differs. EARLIER prototype (0x318390) disasm == our output exactly (count a0,data a1,i a2,nc a3);
  EARLY prototype == retail (a2,a3,t0,t1) with IDENTICAL locals list (data,info,numComplete,i,buf) -> source change is tiny
  or not visible in locals. All mw builds (b38..b103) and -O levels tried: none give t0/t1.
- Tried (all 14): Fill(buf[,fmt],info)/Fill(text,info) inlines, Count(info,state)/(ptr)/(int&)/(data,count) inlines (14-24),
  nested tVec size()/operator[] in cArray, decl order swap, implicit float->double promotion in sprintf (same code).

## SKL_CompressSKL 23 (work\skl0.c) — 3-reg rotation; per policy likely handwritten/excluded, parked.
## ResetBBoxContributors 67 (work\rb0.c) — large structural diffs, parked.

## FireObj (002625B0) update — 24 -> 21
- Best: work\fo9.c (= v_fo7_a0b0d3.c). Copy ctor form:
  `cVector(const cVector& o) { __int128 t; const cVector* ps = &o; cVector* pd = this; asm volatile { lq t, 0(ps); sq t, 0(pd) } }`
  Explicit `pd = this` declared after `ps` fixes ps/t (a0) colors.
- Residual: coloring permutation ours pd v1/pa a1/pr a2 vs retail pd a1/pa a2/pr v1.
- No gain (21 or worse): ScaleR/operator* forms, by-value, operator= forms, 0.5f*(...), named temps (47), ScaleV decl orders (fo_s10..s12).

## GetCollisionDist — still 30
- gcd_s9 (copy-ctor/operator= variants): best 30, others 33-40.
- gcd_s10 (virtual Post call forms: subclass cast, reference, inline wrapper, member wrapper, void* cast): all 30.

## Segment update (17:00-18:00)
- cdiff orientation: LEFT = ours, RIGHT = retail (header `len(ours) len(retail)`).
- ResetBBoxContributors 0x00290610: 67 -> 24. Best: work\rb_best24.c (= v_rb4_w1.c).
  - Loop 1 fully matches with QCopy as TWO separate noreorder regions (lq region, sq region):
    plain asm 31 -> noreorder around sq only 27 -> both separate 25.
  - Loop 2 explicit body (idx, r, QCopy to local offv, currBone, dtor, opNew, ctor w/ copy) = 24.
  - Remaining loop-2 diffs: retail unfolded `addiu v0,s1,0x20; lw v0,0(v0)` data load; retail sq dest
    is separately materialized addiu a2,sp,0x60; retail hoists li a1,-1 before lq; lq/sq separated by sll;
    colors (idx t0, radius ptr a3, off ptr v1->a0).
  - No gain: CopyRet, copy-ctor forms, by-value param inline Reset (76-80), __int128 C copy, GCC asm
    (volatile/non), #pragma peephole off, data-access forms x2-x6.
- MW asm findings: noreorder region keeps operands unfolded and is a load-scheduling barrier;
  plain MW asm / non-volatile GCC asm get peephole-folded; volatile GCC asm blocks folding of later loads
  in the block but turns function-wide float zero stores into `sw zero` (bad).
- Prior segment sweeps: FireObj fo_s13-s16/m/n/q/x all >=21; GCD h1-h7/s11 + compiler sweep stuck 30;
  onWake ow_s20/s21 stuck 11 (pragma-free v_ow0_r2.c = 11).
- Proto early ELF has out-of-line cVector inlines: copy ctor 0x131A90 / op= 0x132050 are plain lq/sq
  (move v0,a0); Normalize 0x131AA0 VU0 form.

## Segment update (ResetBBox 24->22, AgentData 42->38)
- ResetBBoxContributors (0x290610): best 22 = work\rb_best22.c. Loop 2 uses QCopy2 form D
  (`asm { lq t,0(s) / .set noreorder / sq t,0(d) / .set reorder }`) and orders
  idx, r, `cBone** pd = DataRef(&boneList)`, copy offset to local, `cBone& currBone=(*pd)[idx]`.
  Remaining: retail loop 2 has unfolded lq src, data `lw 0(v0)` before lq, sq through separate
  `addiu a2,sp,0x60` with sll between lq/sq. `#pragma peephole off` reproduces loop 2 but breaks
  bool compares (andi 0xFF) -> retail has peephole ON. Sweeps with no gain: statement permutations (39),
  operator= forms, plain struct copy, L4/S4 inlines, GCC asm forms, Reset2/3/4 inlines.
- cAgentData_ctor (0x336700): best 38 = work\ad_best38.c. Gain from Tbl `RowDef& operator[](int)` +
  `D_00532A70[i][j].n` (table IV in s1 like retail). Unsigned operator[] stops j*24 strength reduction
  (retail-like sll/addu/sll) but loses s7/s1 layout (50).
  Remaining: retail keeps &tmp in fp and &tmp.reqs in s6 computed per inner iteration (ctor+ResizeActual),
  separate from the hoisted s7 (&tmp.reqs for dtor). MW always folds/CSEs our addresses into s7.
  Tried with no change (38): explicit this/reqs locals in Ach ctor, POD RA2 + explicit calls, base-class
  VBase split, Init/Reset helper inlines, named temp, AddAch inline helper, auto_inline + out-of-class ctors,
  empty asm barriers on the pointers (MW ignores them for &local). Placement new keeps pointer in a reg
  but adds null checks (64). Pragmas: opt_loop_invariants off 42, propagation off 54, others worse.

## Segment update (late, k7) - no score changes
- onWake (11): early proto (SCUS_973.97, ==retail) vs earlier proto (SCUS_972.64) onWake disasm are IDENTICAL except loop regs:
  earlier total/data/i/nc = a0/a1/a2/a3, retail = a2/a3/t0/t1 -> exactly a0,a1 blocked by 2 invisible vregs.
  Explicit `const cArray* r=&info` / `const cArray& r=info` local creates an UNFOLDED `addiu v0,sp,0x50` vreg (14), not a blocker.
  q1-q6 / w1-w6 (size() in cond, ref/ptr locals, inline ref param copies) 11-18.
- AgentData (38): ref-local forms (Ach& t=tmp, RA2& r=*this, const Ach& y=x in push_back) all 38.
- ResetBBox (22): volatile GCC asm lq/sq (any GCC asm WITH operands) gives retail-like unfolded loop-2 addresses
  (`addiu v0,v0,0x10; lq`, separate `addiu a0,sp,0x60` for sq) BUT turns loop-1 float zero stores into `sw zero` (34).
  Empty GCC asm (no operands) has no effect. C-level __int128 copy schedules lq/sll/sq like retail but folds addrs and
  hoists pd (36). Peephole off + int-returning compares still 60. *pd deref before copy (a2) 40.

## Segment update (k7, ~18:45) - GetCollisionDist 30 -> 28
- `work\gcd_best28.c` (=gcdw.c): drop `#pragma peephole off` (retail is peephole ON: fixes vtable `lw t9,0(s1)`),
  copy ctor `V(const V& o) { Q16(this, &o); }` (no `V* d=this` local - that local was what forced peephole off to fix the cLosResult init region),
  operator* now pure MW asm with `.set noreorder` (no GCC asm needed for mfc1 of a float param).
- Remaining 28 = v0/v1 swaps only: retail colours the result-temp address (rp) before the operand chain in both operator* and operator-.
  Insensitive to: decl order, asm operand order, member vs free operators, bullet_2-style OpM/OpS helpers, `t=0` "+r" forms, Q16 forms, opt pragmas.
- `sqc2 vf1, r` (MW asm direct stack-memory operand) scores 23 (`work\gcd23.c`) but is structurally wrong (sp-relative store, no addiu) - not a real lead.
- onWake: GuiOmegaStrain_5-style `(int)l.data + i*sizeof` indexing, size()-in-condition, inline helpers (CountComplete/Percent/Count), operator[]/size() body variants, int operator[] + SR off: all 11-14. Note: direct loop forms reproduce the *earlier proto* colouring exactly (total/data/i/num = a0..a3).

## Segment update (k7, ~19:00) - final sweeps
- ResetBBox loop 2: replacing QCopy2 with QCopy (lq also in noreorder) reproduces retail's unfolded
  `addiu v1,v1,0x10; lq a0,0(v1)` (v_rb_best22_qa.c, score 25 vs 22 best). Remaining blocker: retail
  materialises &offv twice (a2 for the sq, s0 for the ctor arg); MW CSEs every form tried
  (pointer locals, CopyRet/Reconstruct inlines, derived-ctor `this`, &offv.x, nested ctor inlines,
  const float& param) -> always 25. Plain struct copy 36; by-value inline param creates a 2nd copy (50+).
- FireObj: 21 robust to ScaleV local order, GCC-asm OpM2-style (pa,pr,s) operands, bullet_2 V4 copy-ctor (24),
  result-first ScaleR / by-value param / tagged-ctor RVO forms (30-62). Retail colours the result ptr
  before the operand copy-dest; same root cause as GCD's rp-vs-operand v0/v1 swaps.
- onWake: pre-loop `char* pb = buf` / `fmt` pointers go to s-regs (25-39), so the two a0/a1 blockers
  are not sprintf-arg vregs held across the loop.

## Segment update (k7, ~19:10) - last probes
- loadingThread (l8 lt3.c, 7 by k7 cdiff): literal-1 / param-type / `short on` / C++ bool / loop forms 7-51; const-1 v1 vs a1 coalescing is the same phantom-interference class as onWake. No gain.
- DeactivateFx (l8 vf0.c, 25 by k7 cdiff): triple mfc1 not reproduced by loop-unroll (`for i<3 (&igamma.r)[i]=(int)v` 23-30), float-param Set/ctor (25-30), distinct float temps/tRGBA temp (25-32). Backend merges mfc1 copies in every form.
- GCD: asm local-order matrix (gcd_s90) all 28; `sqc2 vf1, r` 26 but sp-relative (known wrong).
- FireObj: retail colors per scale region are result=v1, copy-dest=a1, operand=a2 (both regions); ours copy-dest=v1, operand=a1, result=a2. ScaleR/operator+ shapes (fo_s90) 21-41. No gain.
- ResetBBox (rb_av6.c, 33): typed one-line `asm volatile { lq t, 0(ps); sq t, 0(pd) }` with pointer locals (cVector* types) DOES
  un-CSE `&offv` (retail's a2/s0 pair appears: `addiu a2,sp,0x60` + `addiu s0,sp,0x60`). void* params or noreorder lines -> CSE'd again.
  Side effects kill it: (1) function-wide float-zero stores in GetZero become `sw zero` (peephole; `#pragma peephole off` restores swc1 but 65),
  (2) volatile asm is a load barrier so `*pd` (retail: early, unfolded) lands after the sq; moving `*pd` before the copy folds to `lw 0x20(s1)` (39).
  Pragma matrix, GetZero float forms (VSet/register/const/chained), split lq/sq volatile combos: 32-97. Best stays 22.

- GCD gcd_s91: MW asm volatile on operator*/-/Length -> all 28. gcd_s92: RVO ctor (asm into this) -> 47. GCD stays 28 (gcd_best28.c).

## Session 3 (k7, 03:54-) - near-miss probes (post R212)
- DeactivateFx triple mfc1: scanned all matched + unmatched asm for cvt.w.s followed by >=2 mfc1 of same FPR:
  only hit in the whole game is DeactivateFx (0025F930) -> no template. Tried chained assigns, inline F2I, int local,
  opt_propagation off, tFRGBA->tIRGBA ctor, unsigned/long/short casts, asm cvt (MW parses as IR, identical), union,
  mw304/mw50: never 1 cvt + 3 mfc1. `#pragma opt_common_subs off` gives cvt+mfc1 per use but whole fn 86 (k_vf1.c).
  Float schedule variants a1-a8 (k const, g/og order, temps, og*=): 25. 128.0 const load early in retail unresolved.
- AimComponent ext pattern (corrected): retail ext's the `!= -1` compare sites AND the immediately-following use
  (lb reload), for both lookAt(+0x80) and jointInfo(+0x10). Non-ext sites 0x64, 0x528 (b1), DE078 (b3).
  With peephole off, enum fields (int-size -> lw; enumsalwaysint off 1-byte still ext), plain char, casts, int local,
  ptr math, (signed char)uchar all still ext. peephole on + asm{nop} doesn't keep ext. No gain.
- FireObj b1-b7, c1-c4 (by-value operator*/ScaleR/ScaleV, direct ScaleV, decl orders, copy inside ScaleR): 21.
  Retail temps: AddV res 0x80 -> copy 0xB0 -> ScaleV(pr=0x70,pa=0xB0) -> copy 0x70->0xC0 -> mCenter.
- onWake d1-h5 + template cArray (ow_t1.c): ref element, ptr param, by-value, unsigned i, while, Pct inlined into
  sprintf args, member/static CountRequirements, out-param forms: all >= 11.
- loadingThread: retail v1 = const 1 shared by ActivateHost and PressX (daddu a1,v1), show in a2.
  ActivateHost(...,1) i1/j1 9 (const coalesces to a1); j2 7; separate `one`/show2 (j3/j5/j6) 15 (materialised per call).
- AgentData: minimal inline-ctor loop tests (tb*.c) — MW always strength-reduces/IVs the element pointer and
  hoists &tmp.reqs (addiu s0,sp,0x74) out of the loop even with opt_propagation off / `this` copies in ctors;
  retail recomputes &tmp/&tmp.reqs per iteration in fp/s6 and computes j*24 each iteration. Not reproduced.
- Tool: work\kdis.py <c> [mw38|mw304|mw50] compiles + disassembles every function (for quick shape probes).

### Session 3 addendum (k7, 04:00-05:10) - onWake/loadingThread "a0/a1 avoidance"
- onWake: Oct-2003 proto (0x318390, disassembled with work\pdis.py <elf> <hexaddr> <hexsize>) is EXACTLY our mw38 output
  (DWARF: nc=$a3, i=$a2); Jan-2004 proto (0x329BA0) is hash-identical to retail (nc=$t1, i=$t0). Same locals in both.
  So the only retail difference is the loop colours shifted by two registers: ours count/data/i/nc = a0/a1/a2/a3,
  retail = a2/a3/t0/t1 (as if two phantom vregs in a0/a1 were live across the loop).
- work\ow_p3.c (direct prototype shape, int size(), operator[](unsigned)) = 14, ONLY those colour diffs. Unsigned size 29,
  signed index -> strength reduced 20. Still 14 with: every loop form (p1-p9, q1-q8, register r1-r5), nested vector /
  template cArray (n1-n3, t2, t3), inline wrappers (w1,w3-w5), dead compares, implicit float->double (ow_f1), extra unused
  params (ow_f2/f3), empty asm blocks, decl-order/for-scope changes, every documented + hidden pragma found in the mw38
  binary (coalesceregisters, opt_defineargorder, opt_marknonregtemps, opt_rotateloops, opt_dead_assignments, ...; sp_owg/
  sp_owh/sp_owi.json), -g/-sym, -O3/-O4,s/-opt level variants, and compilers mw38/mw50/mw304/mw/3.0b52 (14) and
  3.0.1 b44..b103 (23-25, different colours a1/a0/a2/a3 and `lui v0` instead of retail `lui at`).
- Harness td.c t4: a REAL call after the loop taking (..,..,count,data,i,nc) as args 3-6 gives exactly retail's colours
  (MW arg-position preference). Inline calls give no preference. Retail has no such call, so cause unknown.
- loadingThread (7, v_k_lt3_j2.c): same phenomenon. Proto keeps the literal `1` coalesced in a1 for both ActivateHost and
  ActivatePressX (useString=v1) = our i1/j1 form (9). Retail keeps const 1 in v1 (daddu a1,v1 in each delay slot) and
  useString in a2, i.e. a1 blocked again. Here even the Jan proto has the "old" colouring, so the change happened after Jan 2004.
- cdiff.py now honours OPTFLAGS for MW (patched run_limited); OPTLAST=1 puts them after -O4,p.

### Session 4 (k7, 04:35-05:30) - near-miss re-probes, no new matches
- loadingThread (7): PressX(...,1) with int/short/char show 9-15; unused params (void*/2 params/int, sp_lty) 7/9;
  show logic wrapped in static inline (lti_i1..i5: 0/2/hud+on/on params, int return) 16-60; dead locals before/at show
  (sp_ltd, 24 forms) 7-15. Dead calls to a real 6-arg fn (if(0), const/int dbg, 0&&, while(0), if(1){}else, goto skip,
  sizeof test; work\tdx.c) give NO arg-position preference - they're removed before regalloc (only a live call shifts colours).
- FireObj (21, fo9.c): diffs are only the colours of 3 addiu sp temps in each scale block (retail pa=a2, pr=v1, copy-dst=a1;
  ours dst=v1, pr=a2, pa=a1). By-value ScaleV/ScaleR 54-62; copy-ctor w/o pd / int t / inline_depth 8: 24-29;
  HermiteSpline idiom from gameCamera_5.c (member op*, GCC copy-ctor, no pa local) 21-41; GCC-style __asm__ ScaleV 21-29;
  operator forms 21-35; mw50/mw304 21. NB: MW GCC-style asm needs `;` separators (not \n); `#pragma cplusplus on` = C++.
- AimComponent: correct score for ac0.c (= k_d6a.c renamed cAimComponent_NextFrame) is 11, not 57. Pragma matrix on top of
  propagation/common_subs/peephole off (sp_acp: strength_reduction, loop_invariants, dead_code, lifetimes, unroll,
  optimizewithasm, register_coloring, classresults, global_optimizer, opt_level 1-3, ...) 11-541; peephole on 70.
  Other lanes (l8, c01, nmA, p04hum, c147nm) already exhausted the ext forms; only lb-asm drafts reach 2.

## Session 5 (deadline 09:30)
### KEY TECHNIQUE: MW carries soft-float helper state between functions of a unit
- In mw38, once an EARLIER function in the same file has had codegen with an implicit soft-float/64-bit
  runtime helper call, later IMPLICIT helper calls (compiler-generated: fptodp from float->double vararg
  promotion, _f_ulltof from (float)u64, ...) act as if the previous helper's GPR argument registers are
  live from the preceding call up to the helper call ("phantom a0/a1"). Allocation then skips them.
  Shift = GPR args of the earlier helper: 2-arg (dpadd, dpdiv, _dpflt/_dpfge compares, __divdi3) -> a0,a1 blocked;
  1-arg (litodp, dptofp, _f_ulltof) -> a0 blocked; fptodp (float in f12) -> none.
  Explicit calls to declared functions (SoftFloat_FloatToDouble(x), _f_ulltof(x)) are NOT affected: write the
  implicit conversion instead. Dead code / sizeof / if(0) / unreferenced inlines do not set the state; a
  real emitted function does (an unreferenced static is still emitted).
- Reproduce with a weak stub placed before the target, in the discarded section:
    #pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
    __declspec(weak) __declspec(DROPDTOR) int k7_ctx(double a, double b) { return a >= b; }
  `>=` emits _dpfge, one of the few helper names that resolve in symbol_addrs (also _dpfgt/_dpfle/_dpfne,
  _f_ulltof, memcpy). dpadd/dpflt/fptodp/litodp do NOT resolve -> UNDEF. MW rejects file-scope
  __asm__("x = y") aliases and asm("name") declarator labels in this mode.
- Likely fixes the "phantom a0/a1" near misses in other lanes whenever the target has an implicit helper call.
### MATCH 00166840 loadingThread -> build\pending\k7\mw38_00166840.c (work\lt_m1.c)
- From v_k_lt3_j2.c: _f_ulltof(x) -> implicit (float)(u64)x in both places, _dpfge stub before it, and
  cHudLoading_ActivatePressX(D_004EE500, 1) (retail passes the const-1 reg v1, not show).
### 0034EF10 onWake: compiles to MATCH, blocked only by UNDEF fptodp
- work\ow_MATCH_needs_fptodp_alias.c (= ow_m4.c): _dpfge stub + implicit float->double vararg promotion.
  The only remaining check_match line is `UNDEF fptodp: called as a function`. Needs a config/extra.ld alias
  `fptodp = 0x0011BD70;` (SoftFloat_FloatToDouble), like the existing __dl__FPv entry. Explicit-call forms
  (incl. fake extra int args) score 40. Not placed in pending (rule: no UNDEF).
- Other candidates (FireObj, GCD, ResetBBox, AgentData, DeactivateFx, AimComponent, SKL) have no helper
  calls; stubs leave their scores unchanged (GCD 28, AD 38, AC 11, SKL 23 rechecked).

## Session 5 addendum
- memcpy-call stubs, empty/float/loop stubs, and `#pragma opt_classresults on/off` on GCD: no score change (only implicit-helper state carries).
- Other unmatched functions whose retail code calls implicit helpers (possible beneficiaries of the same-unit stub technique):
  0x167C40 cMachine_NextFrame (_f_ulltof, resolves -> best bet), 0x219820 cPathedGOBJ_ctor (k6; its "a0/a1 avoidance in loops
  unexplained" = this effect; told k6), 0x153870 cNPC_Follow_cMessageR, 0x15C390 cNode_ctor_cPopulationR_int,
  0x3DDFC0 cScriptInterpreter_execute, 0x1B1710 cHuman_NextFrame, 0x278460 CreateSphereNormals. All but cMachine_NextFrame
  call fptodp/dpadd/litodp, so they need extra.ld aliases (fptodp=0x11BD70 SoftFloat_FloatToDouble, dpadd=0x11C1A8 SoftFloat_DoubleAdd).
- FireObj/GCD colouring: retail colours the result pointer (&r of the scale op) with the LOWEST free reg (FireObj pr=v1, GCD rp=v0)
  and the operand pointer / copy dest after it; ours reverse. Insensitive to: decl order of pr/pa/t/k (24 perms), member vs free
  operators (15 combos, work\combo_fo.py), cMap_ctor member-operator idiom (32/29), direct-param asm operands, inline_depth 4-10,
  named temp `cVector c = ...` forms, Mid()/Half() helpers. Copy-ctor decl order DOES flip copy src/dst colours (c4) but not pr/pa.

## Session 6 (deadline 09:30)
- loadingThread: build\pending\k7\ was empty but HEAD (R213) still lacks loadingThread in src (machine_3.c only
  `extern char loadingThread`). Re-verified work\lt_m1.c = MATCH and RE-PLACED build\pending\k7\mw38_00166840.c.
- fptodp naming: mwccps2.exe carries helper triples (fptodp / _f_ftod / _dflt_f_ftod); none are in symbol_addrs,
  so onWake still needs extra.ld `fptodp = 0x0011BD70;`.
### SKL_CompressSKL 0x004073C0: 23 -> 16 (work\skl_best16.c = skl2.c)
- Residual was pure register rotation in the two inlined FindPart/FindTex regions; count reg vs hoisted consts.
- Region 1 (FindPart on skl->q20) now MATCHES via a separate inline FindPart1: `unsigned int i = 0;` at decl +
  `for (; ...)`, named `__int128* t = D_005609B0;` after m/k, and PEq1 with a named `long long m1 = -1;`
  (`return r == m1`). Named inline locals get colored above the LICM-hoisted count load.
- Region 2 (outer loop, 13 diff lines): retail partbase a3, -1 a2, texbase a1, count a0; ours count a3,
  partbase a2, -1 a1, texbase a0 (count must move from highest to lowest). Named t inside the outer loop is NOT
  hoisted (size +0x18); named m1 IS hoisted but lands lowest (39). Insensitive: goto-form loops, named n for count
  (before/after/in-test), `*(base+i)`, `-1LL`, if/return, compare reversal, `i = 0` at decl, mw50/b52/mw304,
  pragmas dead_code/dead_assignments/unroll/vectorize/strength_reduction_strict. Worse: function-scope pk/m1/tk
  (40-43), common_subs off (102), loop_invariants off (110), peephole off, optimize_for_size, all 3.0.1 builds (270+).

### Session 6 addendum: SKL region-2 colouring (best still work\skl_best16.c = 16, 13 real lines + 3 pad nops)
- The diff is purely hoisted-value colouring: retail colours the LICM'd count first (count < texbase < -1 < partbase),
  ours colours it last (texbase < -1 < partbase < count). Same discrepancy reproduces in region 1 with a plain
  FindPart (retail count v1,-1 a0,partbase a1; ours -1 v1,partbase a0,count a1), so it is intrinsic to one loop's
  LICM ordering, not loop nesting. Region 1 only matches because named inline t/m1 (late class) sit above the count.
- Loop syntax is irrelevant (for/while/goto/++i/continue forms identical); lifetimes on/off doesn't change the
  constant/count order; propagation/strength_reduction/rotateloops/lifetimes must all stay off.
- Manual region-2 loops: `for (j=0;j<n;j++) if (eq) { part = j; goto f1; } part = -1; f1:` with block-scoped j
  reproduces retail's inline-return branch shape (bne;nop;b;nop) exactly (skl9.c, 28). Plain `goto f1` with
  part as the index gives beq (skl4/skl6/skl8).
- Count-holder experiments on skl9: single function-scope n spanning both loops -> n coloured before the v1 temp
  (n=v1, temps a0); separate n1/n2 or n used in only one loop -> coloured after m/k (t0/t1); block-scoped n ->
  late class; reusing dead `sex` -> same as n1/n2 (22). None land between temps and constants like retail.
- Count spellings (*&X, (&X)[0], casts, +0, X>i), inline count params (t1-t4: 19-23), Monster::FindPart-style
  body `PEq(PAnd(mask,keys[i]),PAnd(mask,key))` (w1 20, swaps m/k), struct/this forms (w2/w3 21).
- C++ mode works: `#pragma cplusplus on` + `extern "C" {}` with PEq/PEq1 returning bool = 16 (sklcpp2.c). A real
  `struct Monster` with inline member FindPart/FindTex (sklcpp3.c, 24) changes the order (-1 a0, &g a1, count a2,
  texbase a3) because parts[i] becomes (&g+i*16)+0x2C10; named t in members is not hoisted (60+).

### Session 7 (k7, 06:20-07:40) - no new matches
- loadingThread was integrated (build\integrated\lanes_r213\k7_mw38_00166840.c, identical) -> pending copy deleted.
- onWake: held copy `build\agents\k7\held\mw38_0034EF10.c` (check_match: MATCH + only `UNDEF fptodp`).
  Fix needed: add `fptodp = 0x0011BD70;` (= SoftFloat_FloatToDouble) to config/extra.ld, then it is a full match.
- AimComponent (11): retail has lb+dsll32/dsra32 ext only at the `!= -1` compare sites. No other retail function has lb+ext.
  peephole off -> ext after EVERY signed-char lb (bitfields, volatile/const, casts, template operator[], const-ref params; also mw304/mw50);
  peephole on -> no ext after any lb (char locals, asm barriers, .set reorder, common_subs off). `#pragma peephole` inside a body is ignored.
  Proto signature: NextFrame__Q28nHumanIk13cAimComponentFfRC7cMatrixRC9cSkeletonRC40cArray_FixedSize<Q28nHumanIk7cBoneIk,21> (0xc30).
- DeactivateFx (25): triple `cvt+mfc1` impossible: every form (pragmas, int locals, C++ ctors, GCC `=f` asm, CSE chains) and every
  compiler in D:\Claude\cw_builds gives 1 cvt + 1 mfc1; memory-reload forms give 3 cvt + 3 mfc1.
- Hidden opt_* pragma matrix (52 pragmas from mwccps2.exe strings, on/off at file top): SKL/AimComponent/DeactivateFx never improve.
- Compiler sweep (all 10 cw_builds) on gcd_best28/fo9: only b38/b50/b52 stay at 28/21, all 3.0.1 builds 72-267.
- GCD (28): mw304 compile of our source reproduces OUR colours, while the proto (= retail colours) differs -> source-shape difference,
  not compiler. Tried, no gain: named product/ref/ptr locals at call site, `where` declared first (35, s0/s1 swap: confirms
  LATER-declared vars get LOWER regs), ctor-based operator*/- (RVO, 39-47), `return *rp`, split asm blocks (rp after vmul: 29;
  operator- split 23 but structurally wrong), float-first operator*, wrappers, NIEvent-style member GCC-asm operator* (+r t=0),
  copy-ctor forms k1-k5 (31-44). Harness (work\hx*.c): rp colour is insensitive to operator*/accessor forms; copy-ctor form changes it.
- FireObj (21): copy-ctor forms (GCC asm k1/k2, Q16, decl swap, asm without volatile) 24-37; ScaleV/ScaleR decl/arg orders 21.
- Colouring pattern common to GCD/FireObj/SKL: retail = ours with ONE virtual rotated from the highest to the lowest register
  (GCD/FO: result-temp address rp; SKL region 2: the inner-loop count load). MW seems to colour the latest-created virtual first
  (lowest reg); in retail that virtual is created after the LICM-hoisted table/temp virtuals. No C form found that delays it
  (SKL `unsigned n = D_0055DE60` local: first -> t1 (20), after m/k -> unchanged 16).

### Session 8 (k7) - near-miss probes
- **cAgentData_ctor 38 -> 28 (work\ad_best28.c)**: add `~RA2() {}` (empty inline dtor on the member class) while keeping
  the explicit `~Ach() { cArray_eRequirementState_dtor(&reqs, -1); }`. This gives retail's frame 0xC0, fp=&tmp held per
  iteration (Reset a0 / insert a3) and s7=&tmp.reqs hoisted for the dtor. Remaining 28: (1) MW strength-reduces j*24
  (retail recomputes sll/addu/sll each iteration); (2) retail ctor/Resize `this` is a separate per-iteration s6
  (`addiu s6,sp,0xA4`) while ours CSEs it with the hoisted s7.
  - Byte-offset indexing `(RowDef*)((char*)data + j*sizeof(RowDef))` (unsigned multiply) kills the SR and gives retail's
    exact j*24 sequence, but frees one s-reg -> fp unused, frame 0xB0, score 42 (v_ad_best28_f1.c). `j*24` (int) is SR'd (28).
  - The s6/s7 split is unreproduced. Harnesses hth4-hth12 (nested loops, inline/out-of-line member ctor+dtor, Resize
    method, templates, placement new, exceptions on, `(char*)this+4`, ref/ptr locals, asm-laundered `this`, named local,
    goto loop, for/while forms, opt_lifetimes on/off) always CSE ctor-this with the dtor arg and hoist it to the outer
    preheader. Proto (early 0x315AF0, == retail) calls out-of-line `__ct__41cArray<..>Fv`/`__dt__41cArray<..>Fv`; with the
    implicit ~tAchievement the member dtor is called out-of-line (no null check). Untested only: real mangled member
    ctor/dtor (needs extra.ld aliases, so not usable).
  - Removing the loop's `__asm__("" : "+r"(s))` barrier: 99 (it does matter here).

### Session 8 addendum (k7, final; no new matches)
- loadingThread integrated in R213 (pending copy removed). onWake still held (work\ow_MATCH_needs_fptodp_alias.c / held\mw38_0034EF10.c):
  MATCH except `UNDEF fptodp`; needs config/extra.ld `fptodp = 0x0011BD70;`. Explicit-call forms all fail (40); resolving helper
  names usable for same-unit stubs: _dpfle, _dpfge, _dpfgt, _dpfne, _f_ulltof, _fpadd_parts.
- ResetBBox (22): by-value Reconstruct helper 88; hidden-pragma matrix (sp_hidcpp tags, ~90 hidden opt_* pragmas) no change.
  Proto dossier: only named locals are the 4 iterators + `cBone& currBone` ($v0); ctor is __ct__30cBone_SkeletonBBoxContributionFf7cVector
  (float, cVector by value). Blocker unchanged: retail materialises &offv twice (a2 sq / s0 ctor arg).
- AgentData (28): `__asm__("" : "+r"(s), "+r"(j))` (v_ad_best28_j2.c, 42) gives retail's exact per-iteration j*24, but ctor-this is
  still CSE'd/hoisted with the dtor-this (s6) and fp/s7 roles swap. off+s address forms 42; dropping s barrier / self->mAch[i] 62-99;
  named `Ach t` 42/51; `this` copy in RA2 42; splitting RA2 default ctor from ResizeActual inside Ach ctor 39 (j2) / 33 (base28).
  Proto disasm (MW 2.4.1) == retail; mw50/mw304 +110; mw size 0x3a0.
- FireObj (21): inline-depth wrappers 21-30; ScaleR forms 21-41; GCC-asm ScaleV either order 21 (=&r int t 29); bullet_4 copy-ctor
  (asm lq + C `*d=t`) 21-28; other copy idioms 21-49; -O3,p / -opt nopeephole / schedule 21, -O4,s 58, -O2 196.
- GCD (28): GCC-asm operator*/operator- (gcd_j1-j6; correct syntax is `$vf1` and `;` separators) all 28; bullet-style lq-asm +
  C store copy ctor/operator= (sp_gcdk k1-k6) 41-45; -O3,p 28, -O4,s 39.
- SKL (16): count-local variants 16/20 (count must move from a3 to a0; >100 variants across sp_skl1..31 exhausted).
- AimComponent (11 by cdiff; check_match: size 0xc48 vs 0xc30 = 3 extra dsll32/dsra32 pairs): eBone as 1-byte enum with
  enumsalwaysint off 11; `#pragma cplusplus on` + extern "C" -> 0xee0. c112hg/c123hg reach 2 only with `lb` inline asm
  (transcribed ordinary code -> not allowed). NB ac0.c callee names are stale (func_001DD1C0 = UpperBodyLook_TargetQuat,
  func_001D1100 = cQuaternion_IsZeroXYZ, Vec4_GetX/Y/Z = cQuaternion_X/Y/Z_void) - rename before any reuse.
- DeactivateFx (25): exhausted (triple mfc1 of one cvt.w.s not reproducible).
- ResetBBox by-value lead (work\rb_byval29.c, 29): loop 2 as `cBone& currBone = (*DataRef(..))[idx]; ResetC(&currBone.contrib, r, (*cc)->offset);`
  with `static inline void ResetC(cBone_SkeletonBBoxContribution* s, float r, cVector off) { const cVector* po = &off; dtor; new; ctor(cVector_ctor_cVectorR(&t, po), r) }`
  and cVector given `cVector(){}` + `cVector(const cVector& o){ V4Copy(this,&o); }`. Matches the prototype (only named local `cBone& currBone`)
  and gives retail's frame (s2 saved, po held in s0). Without `po` the address is rematerialised (frame -0x10, 75). Remaining = same
  two blockers: `&off` CSE'd (sq via s0, retail separate a2) and `*pd` folded to `lw 0x20(s1)`. asm-volatile copy ctor un-CSEs
  (sq a2) but again turns GetZero swc1 into `sw zero` (49). POD/C-copy ctor forms 37-38, named pd no effect, call-order forms 28-31.
- SKL: count via inline NPart()/NTex() (value, named local, pointer), `*&D`, reversed compare: all 16; break-form loop 37.
- FO: ScaleR local order/direct-address/by-value, operator* by-value/aliased ref, split sum temp, ScaleR call direct: 21-64, no gain (colour rotation at 0x150-0x1C8 persists).

## Session 9 (k7, 13:28-, deadline 21:30, post R214)
### MATCH 0013E1B0 cScene_Render (0xAF0) -> build\pending\k7\mw38_0013E1B0.c (work\sr24.c)
Prototype DWARF rebuild, 465 -> 0. Key tricks (reusable):
- `#pragma bool on` only around Eq/IsActive/IsAAL inlines; pattern `bool r=false; if(c) r=true; return r;` -> daddiu w/o andi.
- `CI(g){ return g->mClassID & 0xFF; }` (signed char) -> lb; andi.
- asm F2I `{ int r=0; float t; asm{cvt.w.s t,f; mfc1 r,t} return r; }` -> blocks 256.0f CSE, dead daddu zeros.
- non-const local `float k=1.0f/255.0f;` stays in an FP reg.
- Eq: `cGOBJ** q=b.p; return a.p==q;` fixes load order.
- Last 8 words (loop-top reg rotation a1/v1/a0) fixed by `cGOBJ** pp = gobjItr.p; gobj = *pp;` (temp for iterator load).

### GuiWeaponDisplay_onRender 0x00440580: 122 -> 87 (work\wd_best87.c; base = r185_game\base.c)
- Fix 1 (122->102): M4MUL GCC asm input operand order `"r"(o), "r"(b), "r"(a)` (template %1=b,%2=a) -> both 4x4 multiplies' a/b pointer colours match.
- Fix 2 (102->87): V4::operator+ MW-asm pointer decl order `V4 r; V4* d=&r; const V4* p=this; const V4* q=&o;`.
- Remaining: (a) Center: retail schedules sum-dest addiu before q addiu, and the 0x40->0xD0 copy AFTER paddub/lui/mtc1 of the scale (ours before);
  temp slots: retail first scale result 0xA0, area sum 0x90, second scale 0x80 (ours 0x90/0x80/0xA0); (b) viewport/area pointer colours 0xbc-0x110 and f1/f2 swap;
  (c) matrix-constant ctor scheduling 0x30c-0x360; (d) tail copy colours 0x75c-0x7a4 (retail c=a3,R3=t0,tr=a1,r=a2; ours reversed pairs).
- Tried no gain: non-volatile copy ctor (code shrinks, 350+), copy of *this inside operator* (size+0x20), free by-value operator* (187), const-ref free operator* (91),
  MW-asm block Multiply (tie), Copy/operator= operand swaps (tie), other operator+ decl orders (91/101).
- Next idea: same "reverse operand/decl order" heuristic on Sub/Neg/Translate/scale asm operands and the M4 Copy (one at a time), then the temp-slot ordering.

### Session 9 status of older near misses (unchanged): SKL_CompressSKL 16 (skl_best16.c), cFireObj_ctor 21 (fo9.c), ResetBBoxContributors 22 (rb_best22.c),
DeactivateFx 25 (k_vf0.c), GetCollisionDist 28 (gcd_best28.c), cAgentData_ctor 28 (ad_best28.c), CheckBulletCollisions 29 (bc2.c), cAimComponent_NextFrame 11 (ac0.c).
Untried idea for FireObj/GCD colour rotations: the operand-order / pointer-temp tricks that fixed cScene_Render and GuiWeaponDisplay (`T* pp = x; use *pp`, asm operand reorder).
