# Z3 notes (2026-11-02)

Tools: vr.py (template @HEAD@/@PRE@ variant runner over P4L lab), hd.sh (compile + first N insns), ubgen.py (UploadBoth head brute force).

## 003BB360 cTexture_UploadBoth (692 B)
- best: ub_c.c (k5 draft), check_match 8 words, lab 22 (14 of them are lui-mask artefacts of mine's absolute `at` offsets). Only the line-180 head differs (TEX0 TBP/CBP rewrite).
- retail head: `lui v1; ori a3,v1; li v1,0xffff; dsll v1; ld t1; dsll32 t0,a3; ori v1; dsll32 t2,a2; or v1,v1,t0; dsll32 a3,a1; pcpyld v1,zero,v1; dsrl32 t2; dsrl32 a3; dsll32 t2,t2,5; and t0,t1,v1; sd; ...; or t0,t0,a3; or t0,t0,t2; sd`.
- prototype identical; line 180 holds the whole head incl. both sd (one statement/inline). mask local in the later block is `unsigned long` (MW long = 64-bit; pcpyld appears for 64-bit constants with bit 63 set... both long and long long are 8 bytes in mw38).
- Without a register-held local the second write reloads tex01 (no store->load forwarding), so a local (or inline local) is needed.

## 00410E50 cSubtitleFont_Display (1712 B)
- best: sf_s3d.c (p5l v/s3_d.c) lab 105 (426 vs 428).
- Function-wide less-optimised trigger (`if (0) { asm volatile { nop } }`, or any volatile asm anywhere, incl. a div.s asm) gives retail's per-pair `addiu s2,s2,16` but breaks everything else (253): pos ctor stores fold, &p.y LICM hoist disappears, bools become daddiu. So retail is NOT in that mode; the unfolded gif increments need another cause.
- pragma sweep around the function: optimization_level 3 -> 84, opt_dead_assignments off -> 91, others same or worse. gif folding persists in all.
- gif forms: char*+16 (117), pair struct (117), GCC "+r" empty asm (153, mode), *gif++ (compile error in macro form).
- UploadBoth brute force (ubgen.py, 9922 forms: locals m/l/c/x/t subsets x decl orders x statement orders x late c/x) -> best 22 = baseline. ubgen2.py (inline SetA helpers: ref/ptr/member x param types x arg order x 10 bodies) -> best 28. Head stays at 8 words.

## 001DD1C0 UpperBodyLook_TargetQuat (1240 B) -> MATCH (ul_final.c), waiting for HOLD to stage
- Real identity: nHumanIk::cAimComponent::CalculateTargetRotation_WorldSpace(const cMatrix&, const cSkeleton&) const, prototype 0x1D2CA0 (P1 map.tsv missed it: "none"). First half identical to the prototype; second half = humanIk_48's LookAt inline + MtxToQuat.
- Progress 91 -> 71 -> 65 -> 63 -> 48 -> 34 -> 11 -> 7 -> 4 (4 = bnezl label artefacts) -> MATCH, ~50 min.
- Keys: `V(0,0,1,0)` temp rotated in place by a member `V& Rot(cMatrix m)` (by-value matrix param), reached through
  `RotR(const V& v, const cMatrix& m) { V& w = (V&)v; return w.Rot(Transposed(m)); }` so GetMatrix (inline, virtual
  UpdateTreeNode) is evaluated before the temp is constructed (argument evaluation right to left) and the temp stays a
  main-text temp (slot 0x1F0); `V& w` reference local creates the temp's address register early (t1).
- `Q(LookAt(...))` struct ctor (Q : V { Q(const cMatrix&) { MtxToQuat } }) puts the quat at 0x1E0 (main-text temp).
- Transposed: `cMatrix r(a); cMatrix& s = r; swaps on s; return s;` + matrix copy ctor as MW `asm volatile { lq/sq ... (&o) / (this) }` (removes the dead addiu that the GCC-asm copy ctor left; GCC form with `d = this` locals gave 11, `this` direct 34).
- Rot asm: GCC asm with one pointer operand `V* p = this` used for both lqc2 and sqc2, `return *p`.

## 003BB360 cTexture_UploadBoth -> MATCH (ub_final.c), waiting for HOLD to stage
- Fix: two-statement CBP shift with the shift statement placed LATE (after `t |= texAddr`):
  `unsigned long t; unsigned long c; c = clutAddr; t = tex01 & M; tex01 = t; t |= (unsigned long)texAddr; c <<= 37; t |= c; tex01 = t;`
  The zero-extension and the shift then share one register (t2) and the constant materialisation colours as retail.
  Found by ubgen3.py (two-statement c, all interleavings x decl orders) within the first ~20 variants; the one-statement
  search (9922 forms) never got below 8 words.

## 003BDA00 SphereSweptRay_DetectForCollision_AccountForMovement... (1304 B) - unchanged, 23 words (p5l sweptray_s12.c)
- Per-site MW-asm conversion of each V copy form: no gain (unused tags no effect; long tag 30, plain copy 59).
- New `double` tag for XA4's copy (MW asm with `const V* s = &o; V* d = this;`): lab 23 -> 19 but check_match 23 -> 35 words
  (ss_best19.c; lab's SequenceMatcher count and positional words disagree) - not an improvement.
- XA4 as `V r; V* p = &r; Set(v); XfI(p,&m); return *p/r` with 10 Set forms: 30-38 lab.
- Cluster 1 wants creation order src, p, dst, m (dst v1, p a2) plus the dead `addiu sp,240`; cluster 2 wants the return
  copy through p's register.

## 00410E50 cSubtitleFont_Display - gif increments, more
- Micro harness m/g0.c reproduces the folding (all 3 pairs folded into one `addiu s2,48`).
- In the micro, `#pragma opt_propagation off` (and optimization_level 1) keeps one `addiu s2,s2,16` per pair. On the whole
  function propagation off hoists the float constants (128.0f/16.0f/2.0f) into saved FPRs and costs 239; with any of 8 other
  pragmas added: >= 239 except optimization_level 3 (84, overrides it). Siblings in MovieSubtitles.cc do use
  opt_propagation off / optimization_level 1 per function, so a pragma split inside the function body (if MW allowed one)
  would be the natural explanation; no C form found.
- Typed gif locals (__int128*, struct pair*, char*, unsigned int) all fold in the micro.

## 002EE798 GridProcessDataPack - not attempted (triage only)
- ee-gcc2.96 (lib/medius neighbours in compiler_overrides.json) -> kind gcc296; no DWARF for it in the prototype
  (locals.tsv has none; proto 0x2D4438 is hash-regs 0.99 to retail); two jump tables, 2660 B, no draft on disk
  (k1's gp_typed_connection.c is gone). Not started for lack of time.
- ssgrid2.py: outer XB4 replaced by pointer-passing `XAp(V* p, m, v)` forms x 5 Set copy forms: best 30 words (vs 23).

## Staged (15:25, after HOLD cleared)
- build/pending/z3/mw38_003BB360.c (cTexture_UploadBoth) MATCH
- build/pending/z3/mw38_001DD1C0.c (UpperBodyLook_TargetQuat) MATCH
