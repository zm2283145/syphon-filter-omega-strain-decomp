# k3 lane notes
Start: copies of l4 bests in work\b_*.c. Baselines (mw38): 370CC0 4, 38D720 7, 37B5C0 7, 37D9A0 8, 36B3B0 9, 385240 9, 37B330 109, 38B120 117, 385D40 md_5g, 3781B0 partial.
## Log
- 36B3B0: retail sll temp v0 vs ours v1; mw304 same as mw38. Unresolved.
- 37B330: 109 -> 86 (work\c5.c, exact size 0x28c). Levers: build fb2 with direct tex->hdr->width (not TexDispFB2 param copy) => width loaded once/CSE; SetDisplay BODY term order matters (MW inline substitutes args and evaluates per body expression tree; param order irrelevant). DISPLAY2 body order dy|dx|magh|dw|dh|magv with dx inlined as arg = 86. Remaining: prologue tex/alpha schedule, tail colouring magh2/magv/dh/dw.
- 37B5C0: SetDisplay body-term perms (720, locals form and inline-arg form), dw/dx expression forms, decl types: stays 7 (inline-arg form 9). Root cause: dx gets t1 / dw t0 (retail swapped) -> li 656 hoists above mult because t1 is free (anti-dep on t0 in retail).

## 18:21 37B330 69 -> 9 (work\c14.c)
- SetDispFB per-site inline body order; fb2 via locals: ta=(unsigned)(tex0&0x3fff) [then ta>>5 in call], tw/th/ps locals; order 'pm ta tw th ps dx fb2'.
- Tail: block locals magh2,magv(Max), dh, dw, dx2 (fresh isPal?656:636) with SetDisplayB default body order -> tail exact.
- Remaining: psm t4 vs t5 / pm t5 vs t4 colour swap -> lbu ishalf scheduling. Decl order, pm/smode forms: no effect.

- 18:46 37B330: c15.c = c14 with fb2 stored directly (no fb2 local), also 9. Tried hdr local, no-ps, sm local, types, random 11-item perms, fb body orders: none beat 9.
- 19:01 37B330 still 9: no-pm-local variant (c16.c, 18) gets psm t5/pm t4 right but alpha->v1 & early sched; SetPMode inline forms, al local, prologue perms (with/without pm): no gain. 37B5C0: block decl order (48), dx/dy placement grid (128), dxp/dyp locals perms: 7.

## 37B330 MATCH (19:20) build\pending\k3\mw38_0037B330.c (= work\c19.c, cleaned c17: single SetDisplay/SetDispFB inline, no fb2 local)
- c15 + move the PMODE store `*(0x12000000) = pm;` BEFORE `dx = isPal ? 656 : 636;` (store/local-assignment interleave grid, s0grid.py). 9 -> 0. Lever: interleave volatile stores with local assignments (position grid of each store among the prologue locals).


## 37D9A0 MATCH (19:33) build\pending\k3\mw38_0037D9A0.c (= work\cm11.c; callee cXViewport_Validate)
- Two copy sites need DIFFERENT copy forms. `V4 r = v` in MulMV keeps the combined asm ("=&r", lq+sq one string) via a tagged
  ctor `V4(const V4& s, int)` called as `V4 r(v, 0)`; the plain copy ctor (used for the return-value copy) becomes SPLIT asm:
  `__asm__ volatile("lq %0,0(%1)" : "=r"(q) : "r"(&s)); __asm__ volatile("sq %0,0(%1)" : : "r"(q), "r"(this) : "memory");`.
  Combined form colours value=src reg (retail `lq a0,0(a0)`), split form gives value!=dest (retail return copy). 8 -> 0.
## 38D720 MATCH (19:34) build\pending\k3\mw38_0038D720.c (= work\st_m.c; mw38+mw50 MATCH, mw304 DIFF)
- op= switched from split lq/sq asm to combined `"lq %0,0(%2); sq %0,0(%1)" : "=&r"(t) : "r"(this), "r"(&v)` AND SetTrans
  plain `m[3] = v;` (no y/d pointer locals). Grid op-form x SetTrans-form (stx.py, 72): only this pair = 0 (others 7+).
- Lever: sweep copy-asm form (combined =&r / combined =r / split / CW asm) x copy call-site form jointly; singly they look dead.
## 19:40 negative results
- 37B5C0 (7): pragma sweep (lifetimes/strength/loop_inv/scheduling/unroll off = 7; others worse); block stmt perms x dx/dw
  forms (81, lfo.py); flag types uchar/bool/int/uint/char (125, lfty2.py): all >= 7.
- 370CC0 (4): q12 local (const/int/uint/long) at 12 placements (ddq.py): const=4, non-const moves li 12 to wrong preheader
  spot + recolours; DMATAG3 extra unused "r"(qwcnt) inputs (ddq2.py): 4 (insensitive).
- 38B120 (117): copy ctor x op= asm forms (49, lmc.py): all 117. mw50/mw304 also 117.
- 385240/36B3B0: no new levers found.
## k3 late negatives (19:40-20:10)
- 37B5C0: inline helpers PalX/MagW/Dec/PalY x perms (lfh.py) -> 7; dx/dy moved into prologue (lfd.py, 143) -> best 14.
- 385240: per-site copy-ctor forms via tagged ctor x masks (gbc.py, 343) -> 9.
- 370CC0: volatile/non-volatile mask on the 4 DMATAG3 asm stmts (ddv.py, 16) -> best 4 (masks keeping stmt0 volatile).
- Pragma sweep (pgs.py: 15 opt pragmas on/off + optimization_level 0-4) on 36B3B0/385240/370CC0 -> no gain (9/9/4).
- mw50/mw304 on 370CC0/37B5C0/36B3B0/385240 drafts -> same scores as mw38.
- 370CC0: qwcnt-12 forms (addrOff=12 first, hq local in loop/func, addrOff=12 assign, pv[] stores; hq.py) -> 20..89; DMATAG3 param types (8x4, qt.py) -> 4; or-asm operand/tie forms (5x5, of.py) -> 4. li fp,12 preheader position is insensitive to all.
- 37B5C0: deferred dw-1 (dw-1 at call, dw-=1/dw-- after dx/dy; dwv.py) -> 14; direct ternaries in SetDisplay -> 97; dx/dw types int/uint/short/ushort (tyv.py) -> 7.
- 385240: row-2 float locals in all 24 load orders x 3 store orders (+row0 locals) (gl.py) -> 21 (locals free the scheduler).

## Session 2 (10-31 03:54-)
- Old pending files (37B330/37D9A0/38D720) deleted (integrated R212).
## 370CC0 XLib_DrawDma MATCH (04:20) build\pending\k3\mw38_00370CC0.c (mw38/mw50/mw304)
- Proto has out-of-line DMATAG3__Fi10eDmaTagIDsi (dsll32 v0,a2; sll v1,a1,28; or; or) and cVU1Man::GetMSCAL member.
- Lever: DMATAG3 body as a CW `asm volatile { dsll32 dmatag, nxtaddr, 0; sll temp, tagid, 28; or dmatag, dmatag, temp; or dmatag, dmatag, qwcnt }`
  block instead of 4 GCC-style asm statements. CW asm blocks copy the inline's constant args (12, 3) into temps at inline entry,
  which moves the hoisted `li fp,12` / `li a1,3` to retail's preheader positions (same effect as `qwcnt = qwcnt; tagid = tagid;`).
  Non-volatile CW `asm {}` and plain `asm("...")` forms: 305.

### 38B120 cMan_GetLocal2ScreenMatrix: MATCH (session 2, 04:06) -> build\pending\k3\mw38_0038B120.c
- Key: prototype has out-of-line `__ct__7cMatrixFffffffffffffffff` and `__ct__7cMatrixFRC7cMatrixRC7cVector` (retail 14B160: 3x3 copy, then w column, then lq/sq m[3]=t).
  Stack temps: cVector t @0x40, cMatrix temp @0x50 -> scaleNOffsetMatrix(cMatrix(16 floats), cVector(...)). 117 -> 50.
- diagScaleX before diagScaleY (retail a1=D_00538258 loaded first). GetScale/GetOffset return `const cVector&` (50 -> 14).
- MatMul asm operand order (&d, &b, &a) fixes 2nd MatMul a0/v1 colouring (14 -> 4).
- `0.0625f / (float)D_00538258[i]` (redundant cast) flips f13/f14 colouring of the X division (4 -> MATCH). Validate -> cXViewport_Validate (symbol_addrs).

## Session 2 negatives (04:06-04:18)
- 36B3B0 (9): member-call cMemBin::Allocate forms, pool if/local/cast, bin local before/after size check, file-copy local,
  AllocGuard inline wrap/no block, non-static inline, static-member class, heap local, string literal file, param types (8 combos),
  statement orders, auto_inline/defer_codegen pragmas, mw50/mw304 -> all >= 9. Proto Init 0x35F8A0 is instruction-identical to retail
  (out-of-line Allocate__7cMemBinFUiPCci in proto). Residual: sll temp v1/v0 + lui v0(bins)/lui a2(file) order.
- 385240 (9): row-2 store orders (xyzw 13, Set4 21, SetRow 36, float locals 21); SetAxes/SetX/Y/ZAxis bodies from proto
  0x131900-0x131A40 (void/ref/flat) -> 35..50. Proto 0x378B40 identical to retail.
- 385D40 cMan_ManDMA: from l4 draft (work\md_5g.c, score 729, size 0xd88 vs 0xd90, frame 0x530 vs 0x540). `#pragma cplusplus on` no change;
  CW asm{div} 1100 (GCC asm div needed for LICM mode).

## Session 3 negatives (04:18-04:45)
- 385D40: rsw.py sweeps v1/v2 (uint casts on mix, mix as uint, unused proto locals source/dest/flagCount/patchCount2,
  asymmetric casts, PARTS[i].blends direct) -> all 729/nscore 264; vifCode3 local 265; (int)mix 731.
- 36B3B0: bins index forms (&pool[bins], bins+pool, char* offset forms, bins local) 9; file/line copy locals 9; bin ptr before
  size check 24; manual expansion 34; int size param 9; proto-shape (mh in block, nHeapSize int, void* return) 9..15.
- 37B5C0: SD macro forms (with/without uint casts) 105; SetDisplay inline-arg form 91; (kMagH+1)*width 8; k1 local 7;
  deferred dw-1 / dw-- after dx 14 (height load then goes to a0). Residual unchanged: dx t1/dw t0 (retail dx t0, dw t1).
- 385240: SetX/Y/ZAxis inlines with game_18 float-local bodies (all 3 rows, chain, orders) 29..48.

## Session 4: cMan_ManRender (0x3870C0, 10628 B) from prototype DWARF (user priority)
- Best draft: work\mr_t.c = 247 differing words (cdiff mw38, nscore 24). Progression 429 (mr_c) -> 413 (mr_d) -> 409 (mr_e)
  -> 407 (mr_f) -> 389 (mr_j) -> 384 (mr_l) -> 375 (mr_m) -> 361 (mr_n) -> 309 (mr_o) -> 296 (mr_p) -> 280 (mr_q) -> 259 (mr_r) -> 248 (mr_s) -> 247 (mr_t). No UNDEF expected (same callees as mr_d).
- Levers that worked (all register-colouring / evaluation-order):
  - `fov` local (proto DWARF fov f2), i2 counter for the sb Mul44 loop, M::Set4 member with `const V* pa = &a;` wrapper.
  - Rotate asm operands (sq v %0, this %1, lq v %2) + `static inline void Rot(V& v, const M& m) { m.Rotate(&v); }` wrapper.
  - MulTo34: `M r; const M* pb = &b; Mul44(&r, &a, pb);`. MulTo34r (shells): `const M* pa = &a; const M* pb = &b; Mul44(&r, pa, pb);`.
  - shells loop: `M* pp = &pal; Mul44(&q->e[c].m, pp, &qm);` (375 -> 361).
  - Mul3 asm operand order `: : "r"(d), "r"(&bb), "r"(a)` (361 -> 309, fixes both Mul3 sites 1fcc/21b4).
  - else-branch m34 default copy from D_00537DD0 with loop-local ints `for (int i...) for (int j...) m34[i][j] = src[i][j];` (309 -> 296).
  - Transposed sites: `static inline void To34b(float (*d)[4], const M& s) { To34(d, s); }` wrapper (296 -> 280).
  - blur loop direct form `M* d = &s->bh[0][k3]; RQ4(d, &sv[k3]); spr->pal[k3].m = sv[k3];` (280 -> 259 -> 248; 11e0-127c now matches).
  - si-loop trans source `RQ(&m.R(3), &s->attach[si].trans)` instead of the ATT cast macro (248 -> 247, fixes 1b74 addu order).
  - loc2 blur copy loop (`M* b0 = s->bh[0]; b0[k3] = sv[k3]`) -1 word but hoists bh (structurally non-retail; mr_j keeps retail shape).
- Negatives: Abs/fog forms at 0x8b0 and fog expression orders (4fc); Xform/X1/X2/operator* forms at c0c; Mul44 global perms (420+);
  RQ4 perms; XformInPlace perms; To44/T1/To44b and To34 `int i,j` / function-scope i,j; QCopy decl/init permutations (nstd fixes the
  10d8 sw/daddu schedule but swaps ss/t regs at all 5 QCopy sites); blurTransparency local; per-site Mul44 perms at the si-loop MulTo34
  (1d24 copy temps t0/a3 in retail) and t44 temps; QuatToMtx gcc/CW/local forms (no change); shells loop shapes (continue, t outside,
  c++ post, explicit i/j loop) and qm/pe/pd/pq temps.
- Residual: shells block 0x2518-0x28e0 (~100 words, loop-invariant addresses coloured v0=0x310,v1=0x210,a0=0x450 in retail vs
  v0=0x210,a1=0x310,t0=0x450 ours -> scratch a1/a2 vs v1/a0, and 28d8 delay-slot fill), c0c Xform lq order, 0x8b0 abs/mov.s,
  1d24 copy temps, 10d8 schedule, 0x11e0-0x127c blur copies.
- WSL: mutate.py runs (`/root/k3w`, -j 2) gave no improvements on mr_d/mr_k/mr_n within their windows.
- Also no gain (mr_s/mr_t): fog f = D_70 + D_80/pos.y (same 248, f1/f2 still swapped; split forms worse), i70 temp forms at 10a8,
  MW-style asm Mul44 (identical output to gcc asm), MulTo34 with local To44 copy / wrapper depths (Mw1-3, To44w, MT2/MT3), ATT macro
  replacements elsewhere, To34b inside MulTo34, X1/V copy-ctor/Inverse/Translate variants, Mul44R reference perms. mutate.py on mr_s (mut7): none.
- Also no gain: j declaration placement, inlining To34 as block-local loops, Transposed copy forms (worse, 335+).
- Session 5 (05:00-06:40): NEW BEST work\mr_u.c = 246 (nscore 24): fog line via inline
  `static inline float FogF(float y, float b, float n) { return b + n / y; }` called FogF(pos.y, D_00538370, D_00538380)
  (inserted after `extern float D_00538370;` by closing/reopening extern "C"). Other arg orders/n/y+b 246 nscore 26; ref params,
  function-scope `fogging` decl, param-reuse forms 246..254.
- Session 5 no gain: qm placement in shells (h1-h6 247), Xform wrapper forms (X1 direct 255, XA/XB arg orders same), shells Mul44
  forms (removing pp 261), MulTo34r forms, 10 Abs forms (register, separate init, "=f" asm, in-place AbsI, t temp, no kk), Translate
  forms, Mul44 asm operand-order perms (278-344), RQ4 operand-order perms (384-481), per-site RQ4B (swapped a/b) masks (246..262).
- Session 5 mutate.py on small near misses (-j 1, WSL /root/k3w): 37B5C0 (start 7) none; 385240 (start 10) and 36B3B0 (start 4)
  ran 90 min: see final status below.
- Session 5 (06:40-07:20): NEW BEST work\mr_w.c = 243 (nscore 26; mutate count 234). Lever: derived copy wrapper for the Xform
  arg: `struct VX : V { VX(const V& o) { V* d = this; void* xx = this; const V* s = &o; RQ(d, s); } };`
  `X1(VX v, const M& m) { V* p = &v; const M* pm = &m; XformInPlace(p, pm); return *p; }`, X2 { return X1(v,m); },
  Xform { return X2(v,m); }. (mr_v.c = 245 is the simpler VX ctor variant.)
- Session 5 no gain on mr_w: 10a8 cvt temp forms (11, all 246+), QCopy per-site decl perms, M copy-ctor bodies, MX derived return
  for To44, To44/To44b return forms, MulTo34 taking m34 (251+), MulMM man_2.c-style perms, 30 file-level pragmas (ignored or worse),
  Abs gcc-asm constraint forms/wrappers (243+), V::operator= bodies (243+), 2nd Xform site lhs/rhs forms (243+), shells loop
  qm/pp/pd/t decl forms (243+). Remaining residuals are pure register-colouring: shells loop invariants (retail t1/t0/a0/v1/v0,
  scratch a1), MulTo34 copy temps (14dc/1874/1d24 swapped), 2nd Xform site c54, Abs f5/f4 mov.s, 10a8 cvt t0, Translate 1ebc.
- Session 6 (DWARF-guided, 06:50-): mr_x 240 -> NEW BEST work\mr_z4.c = 205 (nscore 18; last 3 diff lines are retail nop padding).
  Levers: (1) `MulP3(M* d, M* p, M& b) { Mul44(d, p, &b); }` for the shells Mul44 (219); (2) `TrH(M* m, const V& v) { m->Translate(v); }`
  in the bone j-loop (209); (3) semantic: cMan_ManDMA takes a 5th arg (t0) = blurTransparency; blur loop is
  `int lv = (u32)(0.1f*(float)(level*(5-h))); spr->i70 = lv + 0x47000000; ...; pk = cMan_ManDMA(s, pk, lod, a3, lv);` (205).
  DWARF (P1 early locals): modifier = cBoneRenderMatrices{cMatrix bone (=bones 0x1020); cMatrixNxM lights (=m34 0x1060)};
  gun blocks rhandMat/gunMat/offset (=res/m/v); loop block j(gun idx) aGun rhandMat gunMat {i offset} i; shells SPAD2 t6 rhandMat 0x770
  found t5 k t4. work\mr_proto.s (proto disasm) is register-identical to retail in shells/blur regions.
- Session 6 no gain (mv143-mv163): Mul44 asm operand perms in MulTo34, To44 return forms / char-tagged return ctors (RQ4 operand
  perms, this/xx/s orders), uninit this / named To44b temp for ManDMAShells, MulP3/MulP4 elsewhere, To34/To44b/tail helpers in shells,
  MulTo34 by-value a / arg-order swap (MulS) / decl-order helpers (ShH 12 perms 211+), operator* returning M (size grows 0x2a04),
  BL variants, qm assign / R(3) helper wrappers (b3 207), R(3) assignment forms. mutate.py mutZ1-Z3 superseded; mutZ4 on mr_z4 running.
  Residual: MulTo34 sites 14dc/1874/1d24 (copy temps vs Mul44 operand regs swapped) and shells-loop invariant colouring 2578-28ec.
- Session 6b (07:28-07:52): INLINE-DEPTH / SPLIT-ASM levers take ManRender 205 -> NEW BEST work\mr_zb.c = 33 (nscore 5; size 0x2984;
  last 3 diff lines are retail nop padding, so 30 real words). Theory: CW colours higher-numbered (later-created, deeper-inlined)
  vregs first -> lower regs. Steps: (1) MW1..MW4 wrappers (`MW1(d,a,b){Mul44(d,a,b);}` ...) and MulTo34 = `{ M r; MW2(&r,&a,&b);
  To34(d,r); }` (163); (2) To44 returns `M(r,(char)0)` via ctor `M(const M& o, char) { void* xx = this; RQ4(this, &o); }` (127,
  MulTo34 sites 14d0/1868/1d18 now match); (3) shells: new `ShR` = MulTo34r body with MW1 instead of Mul44 (123); (4) shells qm.R(3)
  via `SetP2(qm,pos)` (SetP2->SetP->m.R(3)=p) (69); (5) Xform: `X1 { V* p = &v; XW1(p, &m); return *p; }` with XW1 wrapping
  XformInPlace (59); (6) SPLIT ASM: VX ctor = `const V* s=&o; __int128 t; asm("lq %0,0(%1)":"=r"(t):"r"(s)); void* xx=this;
  SQ1(this,t);` with SQ1 = asm sq (41; c20-ca4 Xform region fully matched); (7) shells pos store via split asm
  `SetQ0(m,p){ lq tt,(&p); SQa(&m.R(3),tt); } SetQ(m,p){SetQ0(m,p);}` (33).
  Residual (mr_zb): only shells-loop hoisted invariants 4D0/7A0/450/490 get a3/a0/t1/t0, retail t1/t0/a0/a3 (pairs swapped), plus
  one sll/lq order at 2644. No gain: To44 copy-ctor depth (RQW1/RQW2/split LQ4+SQ4), MQ/To44c/ShR2 depth combos, ShR wrappers
  ShW1-3/ShP/ShQ (94+), qm helper forms QM3/QM5/QMz, split asm on qm operator= (80+). mutate mutZb on mr_zb running (seed 2020).
- Session 6c (07:52-08:05): ManRender 33 -> NEW BEST work\mr_ze.c = 5 (nscore 5; 3 of the 5 lines are retail nop padding, so
  2 real words). Steps: (1) `M& As(const M& o) { void* xx = this; const M* s = &o; RQW2(this, s); return *this; }` with shells
  `M qm; qm.As(M(&s->q[t].quat));` (mr_zc 30); (2) As uses RQ4t (RQ4 with `__int128& a, b` reference outputs) via RT2->RT1->RQ4t,
  temps declared in As (mr_zd 16); (3) ShR body `{ M r; const M* pb = &b; MW1(&r, &a, pb); To34(d, r); }` (no pa local -> 450=a0),
  plus shells call `SetQ0(qm, pos)` with SetQ0's store as an inline asm sq (`"r"(tt), "r"(&m.R(3))`) -> 7A0=t0/490=a3 (mr_ze 5).
  Tool: work\inv.py prints the hoisted-invariant register map ($sp offsets -> regs) for drafts, which makes the colouring sweeps quick to read.
  Residual: one sll/lq scheduling swap at 2644 (`sll a1,a1,4` for &q->e[c] is placed before As's first `lq s0,0(t1)`).
  No gain: empty/comment asm uses (ignored), split Mul44 (LA/MB) wrappers, ShR arg-order/by-value forms, MulP3 depth/forms,
  &q->e[c] forms (pe/plus/cast/unsigned c), SetQ wrapper inline. mutate mutZe on mr_ze running (seed 4040).
- Session 6d (08:05-08:35): mr_ze (5 = 2 real words) still best. No gain mv206-mv239: SetQ0 single-asm/non-volatile forms, RQ4t
  internal orders (asm text order is kept verbatim), split Mul44 in MulP3, c*7 index forms (canonicalized), compiler struct copies
  (MV/Q4/__int128: 86+), named pd/rd/pe placement (19-25), As local/copy forms, "m"-constraint RQ4t (446), direct asm in loop body
  (69+), QuatToMtx store order / split stores, dummy asm inputs (dup insns), combined As+SetQ0 asm (16), directive asm.
  DIAGNOSIS: As's first lq is GATED by the last insn (sqc2) of the preceding QuatToMtx asm{} (latency-type dependency between
  consecutive asm statements); ours lands it 1 slot late (after sll). Trailing vnop in QuatToMtx -> lq unblocked (slot 3, worse);
  `.set reorder`/`.set at`/`.set noat`/`.set macro` asm after QuatToMtx -> gate removed, lq first (11-14); labels/comments/""
  ignored (5). Root cause of the 1-slot difference unknown (cycle model / hidden IR). Tool work\rep.py: score + LQ/SLL order +
  invariant regs per file. mutate mutZe (seed 4040) and mutZf (seed 777) stayed at 2 words.
  (08:35-09:10) also no gain: RQ4t non-volatile/no-memory copies for As (5), Mul44 operand-order perms for MulP3 (5).
  Evidence suggests lq0 IS ready at 2644 (c7 probe) so the residual is scheduler priority/tie-break between sll4 (c*112 for
  MulP3 dest) and As lq0, not gating. Mutates mutZe/mutZf (2 words) killed at 09:10 with no improvement.
- Session 7 (13:28-21:30, R214 list). 385240 cMan_GetGunBarrelMatrix 9 -> 7 (6 real words) in work\t_g5.c via SZ1/SetZAxis float
  locals (mutGB1 seed 11 running, no gain so far). 36B3B0 Init_int_uint_uint: AllocMM-style inline (pool as inline local) = 16,
  worse; still 9.
  **MATCH 0x38CD90 gunList_LoadGunHog (1940 B) -> build\pending\k3\mw38_0038CD90.c** (work\lgh_match.c), DWARF rebuild in ~1h:
  180 (lgh0) -> 165 (QMove locals `int n; u_long128 t; void* s; void* d;`) -> 121 (QMove(d0,s0,int n): count is the PARAM,
  so `24` is bound before the GetBlock call) -> 43 (locals EXACTLY in prototype DWARF order: partCount,sklFound,bonesFound,
  blocks,blockName,ext,j - gives the j=s0/ext=s1/blockName=s2/partCount=s3 colouring) -> 40 (bbox: `cVector* mn = &b->min;
  QCopy1(mn,&t1)`) -> 25 (`found = 0;` BEFORE `fullPartName = ...` and before `fullPartText[14]='1'`) -> 6 (gunBones union
  NAMED `union U {...} u;` and copied as `dst.u = src.u` -> loads-first lwc1x4/swc1x4 via (idx<<5)+self pointer) -> MATCH
  (`{ cQuaternion* o = &self->gunBulletOffset.orient; QCopy1(o, &self->gunBonesOffsets[part].orient); }`).
  XLib_Init 0x37E780 (3816 B) DWARF rebuild: xi1 381 -> xi2.c 339 (SetBuffers inline) -> fv_l1.c 291 (SetFogColor(self,r,g,b)
  inline called with a float LOCAL `z=0` so mul.s stays runtime; constant args fold at front end) -> fx_ini.c 279 (BEST raw;
  `const tRGBA&` param from `tRGBA c={0,0,0,1}`); fx_val.c 285 (by-value tRGBA, gives retail frame 0x150; ours 0x130 otherwise);
  fy_cref4.c 260 raw but constants come from rodata. Remaining diff: fog/pixenv block EE68-EF84 (retail: each nonzero pixenv
  const own reg, 3 dead `daddu a2,zero,zero`, three separate mtc1 zero * separately-materialized 256.0 with no CSE, cvt results
  forwarded not reloaded, alphaBlendModes[0] ld interleaved), gbScale reg order (~0x19c), ResetGraph extra `b` (~0x21C),
  SetBuffers packing order (0x37c-0x46c). No gain: int/u_char/long/short params, param modification, static const scale,
  tRGBA ctor/temps, float locals, static/local pixenv struct copies (374+), SetPixEnv inline, auto_inline/non-inline
  SetFogColor (339), literal forms 0*256/(float)0/0/255 (339). Best next idea: fix SetBuffers order and ResetGraph branch first
  (bigger word counts), then try fog as a cVector/tRGBA member function with `this` temp. Tool: work\adiff.py aligned diff.
  385240: mutGB1 (seed 11, ~45 min) no gain, killed; still 7 (t_g5.c). cMemMan_Init_void 0x36B630: nmH draft copied to
  work\mv0.c = 24 (mHandle=0 store hoisted vs after mStart; pool*0x818 temp reg order) - not worked further.
  Surveyed, not started: XLib_ApplyContext 0x37C870 (dos\0037C870.txt, never attempted; proto disasm uses inline qword copy
  loop for vif data), gunList_GunRender 0x3836B0 (dos\003836B0.txt, same CU as LoadGunHog - best next big target; reuse
  lgh_match.c types + gunRenderSPAD/manStaticData layouts from dossier).
  WRAP-UP STATE (best drafts, work\): ManRender mr_ze.c 5 (2 real words, sll/lq sched swap at 2644); 385240 t_g5.c 7;
  37B5C0 b_37B5C0.c 7; 36B3B0 b_36B3B0.c 9; XLib_Init fx_ini.c 279; cMemMan_Init_void mv0.c 24. All k3w mutates killed.
  Lessons: union struct copy = 4 loads then 4 stores (plain float struct copy is interleaved memberwise); taking the dest
  address into a named local flips asm-copy dest/temp regs (a1/a2 or a0/a1); DWARF local order is gold for s-reg colouring.
