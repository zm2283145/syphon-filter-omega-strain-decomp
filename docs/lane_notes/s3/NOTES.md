# S3 notes (2026-11-02)

## 00280690 cPlayerCamera_UpdateMotion - STAGED (pc_match.c -> pending/s3/mw38_00280690.c), MATCH
- From M19 w/imp/pc_a1.c (7 lab; already in mode via GCC volatile copies). Remaining was the RotV output copy +
  VAdd colouring (copy dst/temp vs VAdd pointers swapped).
- Fix: VAdd asm operands in (r, a, b) order ("r"(r),"r"(a),"r"(b), sqc2 to %0) AND the call through one pass-through
  inline `VAdd1(r,a,b) { VAdd(r,a,b); }` -> 0. (Either change alone: 7-11; 5 operand orders x {0,1} wrapper grid.)

## 003C66B0 cCollisionProbe_SphereSweptRay_Reset_..._2 (2316 B) - MATCH (rs_clean.c), staged after HOLD clears
- Prototype Reset(...,cMatrix&,cVector&) 0x3B1940 (2276 B) is the same code in the same less-optimised mode (dead addiu,
  iterators through the stack). Retail diff vs proto: Reset_CommonCode's start/path args go through two extra 16-byte
  copies (retail: named V start/path locals, 1040/1024) and the frame has two dead holes (128 B in the named-local area
  between invRotTrans and start, 80 B in the temp area between the loop temps and the Origin temp).
- Written from scratch (rs1.c -> rs23.c): M/V copy ctor `void* xx = this` BEFORE the asm, operator= xx AFTER (as in
  func_003C61D0) -> retail's dead addiu; operator*= with `T* p = this;` single pointer for asm + `return *p` (ret copy
  reuses the asm pointer); `M operator*(a,b) { M r(a); return r *= b; }`; V*= through MulVA(p, &m) (matrix ptr created
  last); vertices plain `v = v * M`, normal `(n * T).Normalize()`; Point via PointW wrapper, Inverse via 3 wrappers
  (InverseWW->InverseW->Inverse->Inv2) so the low temp group order matches (t 144, Dir r 208, Point r 224, ...);
  dead `if (0) { M d0; M d1; d0 = d1; 5x V(path).Self(); }` placeholder gives both frame holes -> all slots = retail.
  Recip(x) inline for the inverse scale (1.0 in f0); rotTrans row 3 via CopyV2 two-level helper; loop test
  `operator==(a,b) { Face* q = b.p; return a.p == q; }` on the wrap iterator; tag copy via inline DoA(by-value tag).
- Remaining: Point/r-copy register colours (a2/v1/t0/a3), op4 (invTFFN = invRotTrans*scaleMat) copy regs shifted by
  one, tag slots 1512/1516 swapped (orig must be deeper than the param copy; Cat/CatW/DoW forms all fail), loop ret
  temps colour (normal ret must be t3; MulF fixes colours but moves the normal r slot), t5/t6 swap in the vertex
  address vs copy temp, missing `nop` after do_assign jal, one extra dead addiu in the tail (Origin().Self()).
- rs24 (76): vertex statements as `CopyR(face.vertices[i], face.vertices[i] * M)` (free `CopyR(V& d, const V& s) { d = s; }`,
  by-value result deferred) -> loop ret temps coloured like retail (normal ret t3), frame unchanged.
- rs25 (48): op4 as `SetM2(invTransform_ForFaceNormals, invRotTrans * scaleMat)` (two-level `SetM(M& d, const M& s) { d = s; }`)
  -> op4's r pointer gets a3 like retail. Left in op4: ret copy dst/op= src (retail v0/a1, ours a0/v0).
- Coordinate descent (cd.py + knobs1.py: 16 knobs, ~35 alternatives) finds no single-knob gain at rs23/rs24/rs25.
- Dead-addiu bookkeeping in the tail: ours has one extra dead on the Origin ret (592) and on the Direction r (208), retail
  has one extra on the Direction ret (576); `const V& o = Origin(); V start(o);` removes the extra instruction but moves
  the temp into the named area (frame breaks).
- rs26/rs27 (40): Point builds r through a by-value helper: `V CopyOf(const V& v) { return v; }`, `V r(CopyOf(v));`
  (deferred, so the copy temps are created late) + V copy ctor `void* xx = this;` before `__int128 q;` -> whole
  Point/rotTrans/prologue block matches. Same trick on Direction (`V r(CopyOf(v))`) fixes the instruction count
  (579) but recolours the tail (55; descent 49).
- Left at rs27 (40 lab lines; the `lw s0` line is a lab masking artefact): op4 ret-copy dst vs op= src (v0/a1 vs a0/v0),
  tag slots, vertex address t6 vs copy temp t5 (v0->v1, v1->v2), tail (Origin/start copy regs t0/t2, dead addiu count).
- rs29 (22): op4 as `invTransform_ForFaceNormals = Mul4e(invRotTrans, scaleMat)` with
  `M Mul4e(a, b) { M r(CopyOfM(a)); return r *= b; }` (CopyOfM by-value helper) -> op4 block matches (SetM2 not needed).
- rs30 (10 lab / +63 check_match because of the extra instruction): vertices as
  `CopyR(face.vertices[i], MulVX(face.vertices[i], M))`, `MulVX(v, m) { V r(v); r *= m; return CopyOf(r); }` -> the
  next-vertex address / copy temp t5-t6 swap is gone.
- rs31 (= hn/t027, 579 instr, check_match 10 words): `V start(CopyOf(Origin()));` instead of `Origin().Self()` fixes the
  instruction count. Left: tag slots 1512/1516 swapped (3 words), tail start-copy dst t1 vs retail t2 / *= pointer t2 vs
  t1 and one dead addiu on the Direction r (208) where retail has it on the Direction ret (576) (7 words).
- General lesson (this function): in the less-optimised mode, routing a copy through a by-value inline helper
  (`CopyOf(v)` returning v) creates the copy temps one pass later, which moves their colours without changing slots;
  this fixed three separate clusters (Point, op4, vertex statements).
- rs32: Direction's r built with a tagged copy ctor without the dead `xx` (`V r(v, (short)0)`) and returned through a
  ctor with two dead defs (`return V(*p, 'x')`, `V(const V&, char) { void* xx = this; void* yy = this; asm }`) -> dead
  addiu counts in the tail = retail (208 x3, 576 x4).
- rs33 = rs_best.c (check_match 3 words, lab 4 lines incl. one masking artefact): `V start; start = Origin();`
  (default-construct then operator=) fixes the start/path colours. ONLY the iterator-tag slots remain:
  retail `lbu 1512 -> sb 1516 -> lb a3,1516` (copy slot allocated before the source), ours 1516 -> 1512.
- Tag search (all fail, source slot always allocated first): DoA/Choose/int2type chains (56 by-value/by-ref x
  temp/named/Cat/CatN combinations, ic/), named outer locals (copies fold), user copy ctors (pass by pointer),
  Cat(T t){return t;} / Mk() forms (copy goes to a third slot, lb from an unwritten slot - looks like an MW elision
  quirk; ie/, if/, ih/ show the `ret slot first` allocation we need but with the wrong copy target).
  Next idea: a form where the by-value param is constructed in place from the temp and the RETURN copies it into
  a caller-allocated return slot (if/1t has the slot order right: ret 1516 allocated before the temp 1512).
- FINAL (rs_clean.c, MATCH): the tag slots came from the real MSL semantics: a pointer iterator's category is
  random_access_iterator_tag, sliced to do_assign's forward_iterator_tag. With the POD tag hierarchy
  (input <- forward <- bidirectional <- random_access) and a DIRECT extern call
  `do_assign(v, first, last, random_access_iterator_tag())` MW builds the derived temp (1512) and copies its base part
  into the argument slot (1516, allocated first) -> retail's lbu/sb/lb. The DoA by-value wrapper is not needed.
  The dead `if (0) { asm volatile }` trigger is not needed either (GCC volatile copies already select the mode).
