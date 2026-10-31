# k1 NOTES

## MATCHED
- UpdatePlayers 002D9438 -> build/pending/k1/gcc296g0_002D9438.c (from work/up_vc1.c).
  Key: retail's jump threading (f-path `b` straight to count<30 test, !f path `b` to the count<100 test)
  comes from writing the delay tests as two flat ifs instead of if/else:
  `if (f && d < 1500) continue; if (!f && d < 200) continue;`
  then `if (f && count < 30) A else if (f || count < 100) A else A` (identical arms, cross-jumped).
  The if(f){..}else{..} form (up0, all y*/z* variants) gives 14-23.

## rFft_vu4 00322FC0 (gcc296) — MATCHED (Session 8) build/pending/k1/gcc296_00322FC0.c (work/fq_0_0.c); history below
## (old) DIFF 1 insn (sra s0 / lwc1 f23 swap at 0x120), work/fc0.c
- sched2 trace (work/fc0_sched.txt): tie at prio 15. Deps into asm insns are cost 0 (insn_cost: recog<0 => LINK_COST_FREE),
  so sra cannot get prio 16. Volatile load 119 wins on dep count (6 vs 3 via volatile read chain).
- 16-way volatile sweep, addr placement, ((int)a-(int)b)>>3 form: none better. Non-volatile loads get folded by combine (lui at).

## _initSeq 0010C030 (gcc29) — work/is_l2.c score 21 (`do {} while (0);` after the d->h/d->w stores), is_v1.c 29
- Remaining: then-block must start with addiu v0,fp,0x540 (&m->img[8]) so reorg puts it in both bne/beq slots;
  ours puts sw/ld ra. Loop-note barrier splits the sched block; retail interleaves stores with li 0x180 (one block).
- Store order / volatile / size placement / p8 temp variants (is_l*, is_m*, is_n*, is_o*, is_p*) no better.

## _initRefImages 0010C2D8 (gcc29) — work/ir0.c score 52
- Retail does n*384 three times (mult x3, 384 in s2). CSE merges to one in all forms (inline expr, n/512*384,
  do-while barriers). Signed /512 -> branch converted to movn by jump1 before CSE. Not solved without asm.

## CalcCostFunc 00316ED8 — work/cc0.c score 37; retail toolchain differs.
## strcmp 00129218 — work/sc0.c score 19; retail needs pnor in a delay slot.
## NellyInvLog2 003236D8 / NellyLog2 00323660
- work/il0.c (c154nm form) ~30 lines; retail toolchain fingerprints not reproducible (addiu at,0;mtc1, hazard nops).
## md5Transform 004AE1C0 / SHSTransform 004B13D0 — hand-written asm patterns; not attempted beyond triage.
## GridProcessDataPack 002EE798 — work/gp_typed_connection.c score 338.
## Session 3 additions (k1)
- Dump tool: work/dump.py + work/wsl_gcc_dump.py. Env: OPTFLAGS (replaces -O2), DUMPFLAGS (default -dR),
  DUMPSUF (default sched2; e.g. rtl/cse/combine), DUMPTO=<abs path>. gcc29 needs `-fsched-verbose-5`.
- rFft: fc0 sra(151)/lwc1 f23(119) tie prio 15; 119 wins on forward-dep count (6 vs 3: volatile-read chain).
  Non-volatile rh (fc_x1/x2) puts sra first but combine folds address (lui at; lwc1 0x4000(at)). 24 orders x 16
  volatile masks, register-asm locals, memory clobbers, inline vu0_call, addr placement: none < 9.
- _initRefImages: RTL expand has 3 separate n*384 mults (each with own li 384); cse1 canonicalises uses of the
  later product regs to the first (records equivalence even though the parallel w/ clobbers can't be rewritten),
  then they die. Inline-function UNCACHED, k=384 var, fold-variants: all 52/57. Retail needs 3 products to be in
  different EBBs at cse1/cse2 time (gcse skips mult parallels) -- source construct not found.
- _initSeq: reorg analysis => retail sched2 order of then-block is 325(addiu 0x540),125(sw h),131(li 0x180),
  128(sw w),133(mult),617(sw 0x44) -- bne non-annulled slot takes first insn 325, beq steals it from fallthrough.
  Our dep graph gives prio(128)=65 > prio(131)=63 and prio(617)=64 > prio(133)=62 so no tie-break reorders it.
  Barrier models: `p8=&img[8]; d->h=h; do{}while(0); size; d->w=w;` reproduces head (325,125,131,128) but the
  p8 spill store lands before the barrier. Declaring p3..p8 at top fixes spill-slot order (slots follow regno).
  Best right-size now work/is_g_ABSHWP.c 28 (is_r1.c 29); is_l2 21 still wrong size (0x2ac).
- Late k1 (19:00-19:20): _initRefImages: every kind/flag (-O1/-O3/-Os/-fno-gcse/-fno-rerun-cse...) still 1 product mult;
  user labels, loop notes, asm volatile("") / asm with operands between products, volatile ptrs: CSE still merges.
  _initSeq: loop notes at the START of a basic block are skipped by haifa (head skips notes) -> no barrier there;
  asm("") at block start makes 325 first but blocks reorg delay fill (nop). rFft: non-volatile rh via pointer vars
  (y1-y4) all 24 (combine folds lui/ori into address).
- _initSeq key insight: retail then-block order (325 | 125,131 | 128,133 | 617) is EXACTLY what haifa produces if
  325 (p8=fp+0x540) is a full barrier (cycle0 alone; then mem-unit conflicts give 125,131 / 128,133 / 617).
  Our gcc29 can't make the first insn of a block a barrier: get_block_head_tail skips leading notes, so a
  do{}while(0) at the then-block head is ignored; asm volatile("") at head works for sched but blocks reorg
  (bne slot becomes nop). Unknown what retail source construct gives a head-barrier.
## Session 4 (k1, 03:54-) _initSeq progress
- Best now work/is_x_AHWSQP.c score 12, right size 0x2a8: `register MpegImg *t asm("$2")`, then-block
  `t=&m->img[8]; d->h=h; d->w=w; size=...; p3..p7; __asm__("" : "=r"(p8) : "0"(t));` (non-volatile copy).
  Volatile copy (is_q1) 14; hard-reg input trick via regmove took 28->14. No-asm floor 17 (is_t1.c).
- Memory deps: a1 set multiple times => init_alias_analysis can't separate a1 stores from sp spill slots; the
  d->h/d->w stores carry output deps to all 6 p8..p3 spill stores (prio 65, 9 fwd deps).
- Retail cycle reconstruction: t1 [127(v0=fp+0x540) + invisible E], t2 [sw h, li], t3 [sw w, mult], t4 [583 sw 0x44,
  s1] ... => stores must depend on an invisible insn E issued at t1 that reorg can skip (USE-like).
  is_e1/e2 (`asm("":"+r"(d))` at then-block head) = 16 and everything from 0xdc on matches retail exactly, but
  d->a2, store order w/h, and asm insn blocks reorg (stop_search_p) => asm E can never fully match. volatile = 27.
- Failed: loop-note barrier (reload puts 583 right after 127 so stores dep on 583), asm with "m"(d->h)/"m"(d->w)
  inputs (grid_y, all 24), arrays, addressable locals, barrier after stores.
- Loop-note barrier with separate t/p8 (grid_b.py, grid_z.py): `t=&img[8]; d->h=h; do{}while(0); size; d->w=w; p8=t;`
  no-asm = 15 (is_b1p.c; CSE merges t into p8 so spill store lands before barrier); `t=&img[8]; do{}while(0); ...`
  + asm copy = 13 (is_b6h; loop note right after 125 keeps reorg slots correct!). A L + perms(HWSQP): best 12.
- Reorg theory for E: fill_slots_from_thread skips (and deletes, own thread) insns that redundant_insn() finds
  already computed before the branch. E = e.g. a re-load `lw v1,0(a1)` (d->w) would be redundant on both paths,
  occupy the memory unit at t1 and give sw w an anti dep -> exact retail order. No natural C found that keeps
  such a dead re-load alive to sched2 (flow deletes it). Stopping _initSeq here.

### Session 4 (cont.) — _initRefImages MATCHED (build\pending\k1\gcc29_0010C2D8.c)
- Key 1 (CSE): identical n*384 products get CSE'd to one mult (size 0xd8). Writing each as
  `a = n * 384; a += (int)y;` (modify the product pseudo in place) keeps 3 mults -> size 0xe0.
- Key 2 (regalloc): with `int n = w*h/512;` as the declaration initializer, sched1 hoists the `li -1`
  (slt temp of the signed /512) so it lives 28 insns -> lowest local-alloc priority -> s2 (retail s0). Score 19.
  Computing `n = w * h / 512;` as a statement AFTER *p0 = ... (any of 117 placements) -> MATCH.
- Final form: six UNCACHED head stores, then n, then a/b/c, then *p6..*p8 = UNCACHED(a/b/c).
- Generators: grid_ir2.py (19), grid_ir4.py (match grid). Lesson: statement position of a
  division init can change sched1 live lengths -> local-alloc priorities; grid it.
- Session 5 (05:15-): gcc 2.95 pass order (toplev.c): reload -> reload_cse_regs (deletes reg no-op sets; turns
  REG_FUNCTION_VALUE_P no-op sets into USE) -> try_split -> flow2 -> prologue -> sched2 -> jump2 (JUMP_NOOP_MOVES,
  find_equiv_reg redundant moves) -> dbr. USE insns cost an issue slot in haifa and are invisible in final.
  combine.c distribute_notes emits `(use (reg R))` right after a CODE_LABEL when a REG_DEAD note's register lost
  its last use (e.g. `h = (h + mbh) - mbh;` in the then-block -> use a0 at block head). Verified mechanism, but
  E needs prio>=65 with no dep on 325; USE(R) only gets high prio via anti-dep from a later set of R, and the only
  high-prio setter is 325 itself (v0) -> doesn't fit. Copies of d / inline setters / h copies: all 17 (CSE removes).

### Session 6 (k1, 05:20-) findings
- rFft_vu4: still 9 (work/fc0.c). gcc296 sched2 dump (needs -fsched-verbose=5): sra(151) and lwc1 f23(119) both prio 15, issue same cycle t=18;
  119 wins on INSN_DEPEND count (6 vs 3). gcc296 haifa semantics: dep cost into asm/unrecognized = 0, anti/output cost = 0;
  rank_for_schedule = prio, class vs last_scheduled (no-link/cost1 > anti > data), #depends, luid. Tried register-asm bases (fr1/2/4 -> 24),
  empty-asm-hidden bases (fr5-7 -> 23-26, asm costs an issue slot), volatile D_004E1D40 (fv1 -> 39), 128-combo grid (grid_fr.py, best 9).
  Conclusion: swap is forced with our dep graph; retail must have an extra invisible insn/dep. Other compiler kinds much worse (gcc29 111, gcc296g0 86).
- Re-triage: md5Transform = hand asm (s-regs in leaf, pref, sq saves); CalcCostFunc madd.s/adda.s/bnel+hazard nops = other toolchain;
  NellyLog2 dli macro + li.s via $at = other toolchain. GridProcessDataPack 342-647 diffs across 4 lanes -> skip.
- _initSeq theory: retail needs an extra insn E at then-block head in sched2 which later vanishes. reorg redundant_insn deletes a thread insn
  identical to one before the branch (e.g. lw v1,0(a1) = d->w) when own_thread, but rejects insns with REG_UNUSED notes, so E's dest must be live.

### Session 7 (k1, 05:50-) _initSeq -> score 4 (work/is_at_hw_aTWHSP.c)
- Then-block `__asm__("" : "+r"(h), "+r"(w)); t=&m->img[8]; d->w=w; d->h=h; size=...; p8=t; p3..p7` = score 4
  (store order w-then-h in source matters: h/w order 8). Schedule is retail's exactly; only diff: asm (prio 66,
  stores 65+1) issues before 125 (v0=fp+0x540, prio 65) at t1, and reorg stop_search_p stops at ANY asm insn
  -> bne slot nop, beq slot ld ra. Pinned t (`register MpegImg *t asm("$2")`) variants also 4.
- Proven impossible with an asm E: E must block stores (else stores tie 125 at 65 and win on dep count 9 vs 6),
  so prio(E) >= 66 > prio(125). Barriers after T / asm with "r"(t) input / clobbers of s0-s5: 15-115.
- reorg skips USE/CLOBBER insns (fill_slots_from_thread), so a CLOBBER of s6/s7/a1 at block head would match.
  Tried union/struct constructor (`hu = (UI){h}`, `register UI hu asm("$22") = {h}`): CLOBBER is on a temp pseudo
  and flow deletes it (dead pseudo clobber) -> 13-26. __complex__ hard-reg vars: 52+. No source found.

### Session 8 (k1, 06:00-) rFft_vu4 MATCHED (build\pending\k1\gcc296_00322FC0.c)
- Non-volatile `rh = ((float*)K)[n>>1]` gets folded by COMBINE (3-insn: K set + addu + load -> lui at/addu/lwc1 0x4000(at));
  volatile mems survive (init_recog_no_volatile) but volatile reads chain anti-deps -> sra/lwc1 tie lost (score 9).
- Fold blocker: precomputed pointers `p = (float*)K + (n>>1);` with K also used by `r0 = *(float*)K`. can_combine_p rejects
  if DEST used between succ and i3 (fp_* grid, score 13-21: load order r0,i0,rh,ih by luid tie in sched1).
- Winning order: `addr=...; r0=*(float*)K; i0=*(float*)K2; p=K+(n>>1); q=K2+(n>>1); rh=*p; ih=*q;` (all non-volatile).
  K/K2 die at the p/q adds, so r0/i0 loads get INSN_REG_WEIGHT +1 vs rh/ih 0 -> sched1 puts rh,ih first -> MATCH.
  Generator: work/grid_fq.py (fq_0_0.c). Lesson: when a tie is decided by luid in sched1, move the last use of an
  address reg to change reg weights.

### Session 9 (k1, 07:00-) _initSeq still 4
- Struct-constructor CLOBBER idea is dead: the (clobber (mem:BLK)) survives cse..lreg but reload deletes ALL
  CLOBBER insns at its end (reload1.c ~1142) -> cs1/cs2 = 21.
- Asm after the barrier (lpd/lpe/lpf) = 28 (t spilled/reloaded, +2 insns).
- `asm("" : "+r"(w) : "r"(t))` between the stores (xa1/2/4) = 25: reorg delay slots now retail
  (bne slot addiu v0,fp,0x540; beq slot addiu) but spill sw v0,0x44(sp) lands right after 125, before stores.
  Adding `MpegImg *p8 = 0;` (xb*) = 40: p8 gets s3 instead of being spilled.
- grid_is.py: 200 variants (8 asm forms x 5 orders x positions 1-5), best 4 (same diff as best).
- Priority argument: any E that precedes the stores has prio >= 66 > prio(125)=65 so it issues before 125;
  alternative t1={127,131},t2={134,128} needs prio(128) <= 62, not achieved. Reload USEs (reload.c 3841)
  only for unsubstituted spills; use_variable only -O0; noop-move removal needs equiv in same block.
- **_initSeq MATCHED (build\pending\k1\gcc29_0010C030.c)**: replace the head asm with `h = (h + q) - q;` where `int q;`
  is an extra, never-assigned local declared AFTER t. Combine folds the expression to h; q's REG_DEAD note has no
  remaining reference, so distribute_notes emits `(use (reg q))` right after the then-label. q has only the USE, gets no
  hard reg, and reload converts it in place to `(use (mem sp+0x48))`. In sched2 that USE reads memory, so it orders
  the stores (anti dep, prio 66) and occupies t1 with 125, but reorg skips USE insns, so 125 is stolen into both delay slots.
  Using p8 itself (u3) = 3: the slot order put the real p8 at 0x48; a separate higher-regno q keeps p8 at 0x44 (0x48 is padding).
  General trick: an invisible E in sched2 is `(use (spilled pseudo))` from combine via `x = (x + q) - q` with uninit q.

### Session 10 (k1, 13:28-21:30, R214 list)
- **viBufGetTs 003F45C0 MATCHED (build\pending\k1\mw38_003F45C0.c, mw38/mw50/mw304).** Source = Sony ezmpeg sample
  vibuf.c (public copy: github historicalsource/kelly-slaters-pro-surfer KS/SRC/HWOSPS2/ps2_movie_vibuf.c). Retail
  version differs from that SDK 2.1 copy only in that bp/fp/ifc/d4madr_next/datasize are assigned AFTER WaitSema
  (only d4madr/ipubp/isEnd initialised at declaration) -> score 3; IsPtsInRegion returning `u_int` (instead of int)
  makes the compare land in t0 (slt t0/beqz t0) instead of slt at -> MATCH. Asm unit 2F45A0 still begins with
  cAnimator_SetFrame (0x18 + 8 pad): needs a config split at 0x2F45C0 for integration.
- Lesson: search historicalsource game repos for SCE sample sources (vibuf.c, ldimage.c, ...) before guessing.
- **_sceMcFatCreateFile 002B9108 (gcc296g0, 0x5C8) NEAR MISS, score 1 (1 differing word): build\agents\k1\work\mc\vO.c.**
  Built from ShadowDecomp's matched libmc2 version, re-mapped to our callees/externs. Idioms that mattered: `int isdir = mode & 0x20`,
  uninitialised `n` in `parent.length - n >= 0x14`, `i = isdir ? 2 : 1; free += n > ret;`, `ent.cluster = isdir ? clust : -1`,
  `__builtin_memcpy(ent.name, q+1, 32)`, entries written through a walking `p` over D_00513DC0, and
  `extern const char D_004AC1B0[]/D_004AC1B8[] __attribute__((aligned(4)))` for "."/".." (fixed the year `sh 0xE` sched2 slot, 3 -> 1).
  Remaining diff @0x130: we emit `beql s6,zero` (annulled slot) vs retail `beqz s6`; slot = `addiu a1,sp,0x480` copied from target
  (isdir -> _sceMcFatGetFreeClust branch). Cause (reorg fill_eager_delay_slots, EQ prob 3999 -> fallthrough tried first, then
  target with annul if a1 in opposite_needed): gdb on ee-gcc 2.96 cc1 (unstripped; mark_target_live_regs @0x081d23e4) shows
  live(uid 287 fallthrough) = {2,3,5,7,16,17,18,21,22,23,29,30} -> a1 live -> annul. find_basic_block is unlimited (scans to
  BARRIER/function start), REG_DEAD only takes effect at next CODE_LABEL. Tried: __builtin_expect (8/10), isdir>0 (blezl, 1),
  D_00513DC0[0]. writes (3), else-if/nested-if/if(ret)/goto-skip (all 1), combined ret check (8), goto-out forms (43/32).
  Best next idea: finish the gdb trace (g.gdb: call mark_target_live_regs on every insn between uid 1369 and 287; the per-insn
  call loop was very slow, cap it) to find which insn leaves a1 live, then add a CODE_LABEL (loop/label structure) after the
  GetFreeEntrySize call, or change arg setup so a1 is dead at the fallthrough, without changing code.
- strcmp: newlib r5900 strcmp.S hand asm -> skip. longReverse/SHAtoByte/md5Encode hand asm; md5Transform/SHSTransform/
  CalcCostFunc/Nelly infeasible; KM_GetSoftwareID exhausted.
