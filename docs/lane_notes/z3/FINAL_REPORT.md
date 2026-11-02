# Z3 final report (2026-11-02)

## Results
| Function | Addr | Size | Result | Draft |
|---|---|---|---|---|
| cTexture_UploadBoth | 003BB360 | 692 | **MATCH**, staged `build/pending/z3/mw38_003BB360.c` | Z3/ub_final.c |
| UpperBodyLook_TargetQuat | 001DD1C0 | 1240 | **MATCH**, staged `build/pending/z3/mw38_001DD1C0.c` | Z3/ul_final.c |
| SphereSweptRay_DetectForCollision_AccountForMovement... | 003BDA00 | 1304 | unchanged, 23 words (p5l sweptray_s12.c = Z3/ss_s12.c) | - |
| cSubtitleFont_Display | 00410E50 | 1712 | unchanged, 105 lab / 426 vs 428 insns (p5l v/s3_d.c = Z3/sf_s3d.c) | - |
| GridProcessDataPack | 002EE798 | 2660 | not attempted (gcc296, no draft, no DWARF) | - |

## New techniques
- **Late two-statement shift (UploadBoth).** `c = clutAddr; ... c <<= 37;` with the shift statement placed after the
  `t |= texAddr` (not next to the assignment) makes the zero-extension and the shift share one register and fixes
  the colouring of the 64-bit mask constant around it. 9,922 one-statement local/order forms never got below 8 words;
  the late two-statement form matched in the first ~20 variants of a search (ubgen3.py).
- **Missing prototype mappings.** P1 map.tsv lists 0x1DD1C0 as "none". It is
  `nHumanIk::cAimComponent::CalculateTargetRotation_WorldSpace(const cMatrix&, const cSkeleton&) const` (prototype
  0x1D2CA0, found by grepping the prototype symbol table for the caller's class). Grep `objdump -t` of the prototype
  for the class name before treating a function as having no counterpart.
- **Reusing an inline from another function in the file.** The retail-only second half was humanIk_48.c's LookAt
  inline plus MtxToQuat. The transposed-rotation helper was copied from cParticleSpray_UpdateGravityVector (particle_7.c).
- **Choosing which argument is evaluated first (UpperBody).** To have GetMatrix evaluated before a temporary
  `V(0,0,1,0)` while the temporary stays a main-text temp:
  `RotR(const V& v, const cMatrix& m) { V& w = (V&)v; return w.Rot(Transposed(m)); }`, called as
  `RotR(V(0,0,1,0), xf->GetMatrix())`. Arguments are evaluated right to left, and the `V& w` reference local creates
  the temporary's address register early.
  `V(...).Rot(...)` evaluates the object first, and a by-value `V` parameter gets float stores instead of `sw zero`.
- **Struct-ctor temp for slots.** `Q(LookAt(...))`, with `struct Q : V { Q(const cMatrix&) { MtxToQuat } }`, puts the quat
  in the main-text temp region (0x1E0), where an inline `QFromM` put it among the inline locals.
- **Matrix copy ctor form controls a dead addiu.** In the less-optimised mode, the 4-quad copy as an MW
  `asm volatile { lq qa,0x0(&o); ... sq qa,0x0(this) }` (operands `&o`/`this` directly) removed a dead `addiu` that
  the GCC-asm copy ctor left (GCC `this`: 34 lines; GCC with `d`/`s` pointer locals: 11; MW form: 7).
- **SubtitleFont gif increments:** in a micro harness `#pragma opt_propagation off` (or optimization_level 1) keeps
  retail's one `addiu s2,s2,16` per GIF register pair. The MovieSubtitles.cc siblings use exactly those pragmas.
  On the whole function, though, propagation off hoists the float constants (239 lab lines). The cause is still open.

## Notes
- check_match and lab disagree on SphereSweptRay: one variant scores 19 lab lines but 35 check_match words.
  Judge by check_match.
- Details, dead ends and tools (vr.py, mk.py, ubgen*.py, ssgrid*.py, m/ micro harness) are in NOTES.md.
