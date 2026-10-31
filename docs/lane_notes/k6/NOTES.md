# k6 notes

Tools: dd.py (diff, `dd.py FILE mw38`), pd.py (proto disasm by regex/addr).
dd.py: `$env:DD_RWIN='8'` matches R-relocated lines within +-8 lines (index-based wildcarding otherwise gives
spurious reloc diffs after any size shift). Sweep scripts: sw*.py (string-replace variants, 3 workers).

| Addr | Function | Best | Draft | Status |
|---|---|---|---|---|
| 00219820 | cPathedGOBJ_ctor | MATCH | pending\k6\mw38_00219820.c | done (session 6, fptodp aliased) |
| 00180580 | QuaternionLERP UpdateVelocity | 17 | work\sq_a.c | open |
| 00131540 | PushWeaponCam | MATCH | pending\k6\mw38_00131540.c | done |
| 00405660 | Monster_ctor | 21 | work\base_405660.c | open |
| 00153870 | cNPC_Follow | MATCH | pending\k6\mw38_00153870.c | done (session 6, fptodp aliased) |
| 003DDFC0 | cScriptInterpreter_execute | 52 (DD_RWIN=8; 62 plain) | work\best_3DDFC0.c (sq4_n.c 64) | open |
| 00265B90 | cAirTaser_Shoot | MATCH | pending\k6\mw38_00265B90.c | done |
| 003EF660 | cInterfaceModel_ctor | MATCH | pending\k6\mw38_003EF660.c (work\best_3EF660.c = ym_d) | done (session 5) |
| 00230DE0 | Global_Shatter | 1003 | work\base_230DE0.c | open |
| 0022CB10 | cTargetManager_IsLosBlocked | MATCH | pending\k6\mw38_0022CB10.c | done (session 4) |

## 00219820
- Retail == proto byte-identical in the lens loop (t4/t3/a2/t2 colours, empty bnez delay slot).
- No gain: split NIEvent-style operator= (k2), with memory clobber (k3), mw50/mw304 (same 12).
- Live-across-loop hypothesis (value kept in a0) tested (k5): MW correctly uses s-reg -> dead end.
- Faithful draft work\pc3_g4.cpp = 18. Evidence: retail leaves the lens-loop back-edge bnez (0x2A0) delay slot as
  nop while ours fills it with the post-loop `addiu a0,s3,0xA4`, AND loop temps skip a0/a1 => physical a0/a1 look
  live around the whole loop in retail (phantom precoloured use, likely at the FloatToDouble jal). Not reproduced by:
  if/ternary/double temp/(double) cast/inline Small(double)/explicit SoftFloat_FloatToDouble+_dpfle calls (sw21l),
  goto/while/break/continue loop shapes, pv/d temps (sw21m2). Same phantom in 153870 and other lanes; unsolved.

## 00131540 MATCHED (pending\k6\mw38_00131540.c)
Key: faithful prototype member ops: operator-/operator+ { V result; VU0Subtract/VU0Add(result,*this,v); return result; } with static VU0* helpers; operator/ returns *this*(1/scale); copy ctor lq + MW asm{sq t,0(this)}; GetLength with float r=0 '+f' for dead mtc1 zero.
MW nop quirk: block after b+delay is 8-aligned, so stray nop diffs are consequences of earlier 1-insn diffs.


## 00265B90 MATCHED (pending\k6\mw38_00265B90.c) - techniques
- Placement new `new (cLightMan_AddLight(..)) TLight(args)` (inline `operator new(unsigned int, void*)`) gives the
  alloc-null-check shape: beqz v0 / copy to s0 / ctor body only when non-null.
- `__attribute__((aligned(8)))` on 12-byte RGB / int locals reproduces retail 8-byte stack slot rounding.
- Stack slot order: depth-0 named locals top-down, then temps, then inline locals by nesting depth; a local in an
  inline nested 3+ deep lands at the bottom.
- `a = b = c = 0.0f` stores c first.  `RGBA lc(c, 0.0f)` with inline ctor body r,g,b,a.
- `x || !Get()` reproduces a1=1/bnez/sltu/xori/bnez; `if (ok) return g; return 0;` with nested `if (g) { if (eq) ok = true; }`
  gives xor/sltiu/beqz without andi; operand order of the xor follows `IEq2(D, id){return b == a;}`.
- KEY: inline-callee pointer params get their own arg-like registers (a1/a2) computed EARLY only when the
  callee keeps the pointer in a local and copies via GCC lq "r"(s) + `asm { sq t, 0(this) }` in a nested inline
  (`pos.CopyFrom(s)` with `const __int128* s = &p` declared at the top of the Pt ctor). With plain `pos = p` the
  address folded to sp offsets.
- After registers matched, float store scheduling depended on the source statement order (sweep 8-store orders).
- LookAt(M*, V& dir, V up) passing `up` straight through (no `V* pu=&up` hack) fixed the arg setup order.
- `V lc2; lc2.w=0; lc2.z=c.b; float g=c.g; lc2.y=g; lc2.x=c.r;` fixed the f1/f2 swap (a named temp for one component).
- Callee names: check_match UNDEF lines -> decode jal targets from asm hex and use config\symbol_addrs.txt names.

## 00153870
- chk-form sweep (sw153q) stays at 20; remaining diffs are the a0/a1 phantom colouring shift.
- Phantom a0 regions: 0x24C-0x2BC (right after the GetMtx struct-return jalr, retptr passed in a0), 0x464-0x4A0
  (chk), and the empty nez s0 (if(!vis)) delay slot at 0x630 (retail does not hoist lui a0 although a0 is dead
  at the target 0x758 / join 0x800).
- fc_a.c (19): oid* mgr = g_TargetVisMgr; declared before chk and passed as the a0 arg makes chk colour a1 like
  retail (so retail has an a0-coalesced value live across the region), but our lui/addiu then sits at the def.
- No gain: member-function form (sw153r), const/after-chk/ternary/vis=true forms (sw153s/u), dir forms (sw153t),
  uninitialised mgr assigned in a separate if (chk) (sw153v: goes to an s-reg, 48), ~Mtx() {} (64, size fixed).

## 003DDFC0
- All five opt_* pragmas are required (dropping any -> 86..276).
- MemClear_DFC0 asm: remove the nop after `blez $v0` (size -8).
- `while(!done)` under these pragmas emits sltu/xori/bnez; goto loop (`goto test; top: {...} test: if (!done) goto top;`)
  gives retail beqz.
- CSE'd case 1 `{ int n = data*4; sp -= n; MemClear(sp, n); }` makes size == retail but n/dst land in a1/a0 (retail a0/a1).
- Remaining: global s-reg rotation (retVal s7 vs retail s2), case 0x40 s-regs, mov.s at 0x1D4, if/else join at
  0x58C-0x5A0, bne operand order at 0x12C8. No gain from done types/loop forms/retVal order/TypeId forms.

## 0022CB10
- t3.c (24): `e->pending = 1` right after Event_Construct (before vt store) beats other positions (sw22c; end=35).
- Retail materialises 1 early in v1 and stores pending after the b5C=2 store; not reproduced by pending=force/true,
  moving b5C, Insert by-value iterator/MapX::insert forms (sw22b/e), second-region reorders (sw22d).
- With DD_RWIN=8 t3.c scores 26. Pending moved after end.w (retail store position) = 37: retail materialises 1 and
  4 early but 1.0f and 2 late; single-statement move sweep of block 1 (sw22g, 144 variants) best is t3 again.
- No gain: Event_Construct(&ma)/temp type/member Construct()/inline wrapper (sw22h/i: retail fills the jal delay
  slot with ddiu a1 in block 1, ours with daddu a0), Touch()/vt order and Touch body forms (tail v0/v1 swap).

## 00405660 / 00180580
- 405660: retail keeps SUB pcpyld/sq in source order before the TYPE `or`s; MW hoists the ALU ops across asm{}.
- 405660 no gain: GCC __asm__ pcpyld helpers (volatile: size blow-up 90-140; non-volatile: identical 21, sw405g),
  SUB/TYPE statement order (sw405h), fused two-pcpyld asm / asm sq (sw405i, 62/21: MW schedules asm insns
  individually), nested kfrom forms (sw405j), volatile fields/stores (sw405k: no change at all).
- 180580: address-materialisation order in the second QMul copy chain; retail gives the QMul operand vregs the low
  registers (v1/a1/a2) and the copy-chain vregs the high ones, ours the reverse. No gain from QMul asm operand
  permutations with/without pointer locals (sw180c), QMul as member operator* (sw180d), copy-asm operand orders (sw180e).

- 180580 also no gain: MW asm{} QMul (sw180f = 17, same pattern), copy mechanisms plain C/MW asm (sw180g 19-85),
  top-level statement forms (sw180h; `V deltaRot(...)` = 17), Mul body variants (sw180i; SetP3 = 17),
  QMul operand perms x copy-asm orders combined (sw180j, 85 variants; best 17).
- 3DDFC0 0x58C join: retail does not thread the then-branch `b` through the loop-entry `b test` and leaves
  `addiu a0,-1; nop` in the else. Not reproduced by goto/for/while-break loop shapes, ternary/pre-init/!v/if-goto
  forms (sw3dd_a, best 64) or inline TypeOf() helpers (sw3dd_b, 66-69).
- 3DDFC0 0x12C8 bne operand order: no change from operand swaps, local str/d temps, ScDepth/IsDepth inline forms (sw3dd_c/d/e); direct self->mDepth reorders the regs (70).

## Session 3 (R212+) negatives
- 219820: varargs runtime-call decls (sw21v) 17; mw (3.0.3) 121, mw304 12; member-function PathObj::Ctor form 86
  (s2/s3 swap, no phantom); explicit SoftFloat_FloatToDouble ternary / double temp = 12, if-forms 25, 0.01f 172,
  (double)0.01f 30 (swk.py + spec_w1.py). swk.py = generic sweep runner (spec: BASE, ADDR, PREFIX, V, RWIN, KIND).
- 180580: pragma sweep on sq_a (spec_p1): opt_common_subs off 23, peephole off 20, both 33, always_inline /
  opt_propagation off 17. Faithful rewrite using the matched sibling func_00180120.c helper forms (MW asm{} copy ctor,
  VU0Multiply, member operator*, its pragmas) fq_a = 71, pragma variants 70-113 (spec_fq). sq_a stays best.
- 405660: MW rejects `<<`/`|` on __int128 ("illegal data size"); a plain (u128) cast emits nothing. pcpyld must be asm.
- 219820: hoisted eps (const double / static const / block const / const float) all 12 (spec_h1); non-const eps
  144/149 (goes to an s-reg). Phantom a0/a1 (retail keeps _dpfle a0/a1 live across loop back edge) not reproduced.
- cdis.py = compile + disassemble helper for any file.
- 153870: spec_m2/m3 variants and mw50/mw304 no gain over 17 (DD_RWIN=8); phantom a0 unresolved.
- 3EF660 progress: block-scoped `for (int i...)` loops 355 -> 306 (b2); face loop as
  `if (n > 0) { int i = 0; do {...} while (++i < n); }` -> 296 (b3; loop inline instead of outlined guard). Plain
  for-loops get an outlined guard/preheader at the function end under MW; if+do-while inlines it.
- 3EF660 no gain: decl-order perms, Cp3 copy forms (struct copy/ordered temps/faceRaw in loop, e6/e9 306-450),
  manually unrolled pack (e7 440+, keep the j-loop), inline string-skip helper / dropping parent store, recursion or
  texture block (g1/g2), buf/q/size decl+alloc forms (g3). Real ctor form (c1) gives 274 but symbol is
  __ct__10Self_EF660..., not deliverable as cInterfaceModel_ctor.
- 3EF660 remaining: s-reg permutation (retail buffer s0, this s1, parent s2, size s3, buf s4, i s5, fileman s6; ours
  parent s0, cursor s1, this s2), face-loop guard slt/beqz vs our blez, Cp3 load order 0,4,8.
- MW colouring (micro-tests rt*.cpp): by default params get s-regs in reverse param order (last param s0). Heavily
  used / high-degree values (e.g. 3 RMWs through a pointer, or one value with >=4 temp computations) are coloured
  first. Matches the recovered PPC MWCC rule (github stephenjayakar/melee-mwcc-register-skill allocator-rules.md):
  simplify scans vreg ids ascending removing degree<K nodes onto a stack head, so low-degree nodes colour in reverse
  id order; high-degree nodes are removed by min spill_cost/degree (cost = loop weight*(2*uses+defs), ties -> highest
  id) and colour first.
- 22CB10 24 -> 8 (work\best_22CB10.c): (1) site-1 Insert hint as comma expr `Insert(it1, map, (end1 = self->end, &end1), Key(..))`
  puts &end1 (a2) before a0 like retail (18); (2) site 2 `{ void* en = self->end; e->pending = 1; Insert(it2, map, (end2 = en, &end2), ..) }`
  fixes v0/v1 + sw order (12); (3) `{ void* vt = D_004D91C0; HS2* hs = &mr.res.s; mr.vt = vt; hs->Touch(); }` fixes the
  vt/0x170 colouring (8). Remaining: Event_Construct a0/a1 order at 0x2A8 (site 1 only) and site-1 pending=1 / b5C=2
  constant placement (retail: 1 early in v1, sb pending last; 2 materialised late). No gain from: pending position sweep,
  pending=force, bool/signed pending, __restrict e, direct ma. stores, b5C position, local temps (block-scope decls add +8 size),
  Event_Construct(m = &ma)/ty temp forms, HIt by-value hint wrapper (54-126).
- 3EF660: b3 = 274 with DD_RWIN=8 (296 plain). Block-scoped `{ int n = ReadI(cursor); }` per section (k1): 278-284.
  Micro-tests: retail-like param colouring (b s0, a s1, d s2, c s3) only when c (fileman) is not used at function end.
- 405660: scheduling flags (-O3,p etc.) no help; S16/char[16]/ulong[2] field types for masks: identical 21.

### 22CB10 8 -> 7 (session 3)
- best_22CB10.c now = site-1 order `vt, b5C=2, f24, f28, res, start, end, pl, cl, f58, pending=1, start.w, end.w, Send`.
  Constant colours then match retail (4->a2, 1->v1 hoisted, 0.0->f0, 1.0f->v0 late). Remaining: Event_Construct
  a0/a1 swap at 0x2A8/0x2B0, `li 2`+`sb b5C` early (retail late after sw f58), `sb pending` before the swc1s.
- m-> stores keep source order. Writing retail store order exactly (work\x1_a.c) gives wrong constant colours (19).
  Constant hoisting depends on statement order (pre-RA height scheduling?) - not modelled.
- Negatives: all 120 orders of tail stmts (x2, best 12); bool b5C (invalid, stores 1); `ma.` everywhere (20+);
  __restrict on e/m/self (no change); extra locals k1/k2/one (spill force); inline setter helpers (x9, all 19).

### Phantom a0/a1 SOLVED via k7's soft-float helper-state trick (session 3, ~05:20)
- k7 found (k7\NOTES.md "KEY TECHNIQUE"): an IMPLICIT soft-float helper call that takes only FPR args (fptodp, f12)
  inherits the previous helper's GPR arg regs as "uses", so they look live from earlier code up to that call.
  Reproduce with a weak stub before the target, in the discarded section:
    #pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
    __declspec(weak) __declspec(DROPDTOR) int k6_ctx(double a, double b) { return a >= b; }    // a0+a1 phantom
    __declspec(weak) __declspec(DROPDTOR) float k6_ctx(unsigned long a) { return (float)a; }   // a0 phantom
  The float->double conversion MUST be implicit (explicit SoftFloat_FloatToDouble() calls are unaffected).
- 219820: work\pc3_g4.cpp (faithful draft, 18) + `>=` stub = check_match MATCH (work\M_219820_fptodp.cpp).
- 153870: f_m1.c with `(double)distance > 6.0` + `(float)u64` stub = 4, then V(const V&, float) ctor with
  `V* t = this;` declared before `const V* s = &v;` = MATCH (work\M_153870_fptodp.c).
- BOTH are blocked only by `UNDEF fptodp: called as a function` - MW emits the runtime name fptodp, which is not in
  config\symbol_addrs.txt / config\extra.ld. Adding `fptodp = 0x0011BD70; /* SoftFloat_FloatToDouble, MW libcall */`
  to config\extra.ld (as with __dl__FPv) would unlock both (and k7's onWake). Not delivered to pending per rules.
- 3DDFC0: implicit vararg promotion + stubs = 64 (no change). 22CB10/180580/405660/3EF660/230DE0 have no helpers.
- 22CB10 x9-xe: inline setter helpers, inline Fill(params), Event_Construct arg forms, dead-branch forms,
  inline/derived ctor forms: no gain (7). 240 random site-1 permutations: best 16.

### 22CB10 session 3 (06:00-07:05): site-1 arg order (cluster a) root cause found, not yet deliverable
- Root cause: retail's site-1 block does NOT contain `addiu s6,sp,0x2F0` (m = &ma) at schedule time, so
  `daddu a0,s6` is ready at cycle 0 and goes before `addiu a1`. (The addiu is in the bnez delay slot.)
- `if (!force && (m = &ma)) {` (m/ma declared before `force = 1`) = retail exactly at site 1, but leaves one extra
  `beqz s6` (MW can't prove &ma != 0) -> 24 by offsets (work\alt_22CB10_beqz.c; only beqz + b5C cluster remain).
- `asm { .set reorder }` right after `RayMsg* m = &ma;` also fixes site 1 (work\alt_22CB10_barrier.c) but the
  svc reload `lw a0,0xA8(sp)` then lands mid-block (22-28). Barrier after Event_Construct as well: still late.
- No gain: folded comma conditions (`(m=&ma,1)`, `,true`, `,1==1`, sizeof...) = 7 (front-end folds, m def back in block);
  `m=&ma, !force` forms materialise sltu/xori (23); empty if/goto/do-while(0) forms fold (7); real loops 29;
  derived RayMsg2 ctor+dtor 29-35; m=&ma before `force = 1` spills force to the stack (109).
- `.set noreorder` asm blocks change size (0x6d0) and are useless. b5C/pending position sweep (xj, 155) best 8;
  start.w/end.w position sweep (xk) 12; constant locals (xf) 25.
- 22CB10 (07:00): inline RayMsg ctor form (work\alt_22CB10_ctor.c: `RayMsg ma(self,&out,0,posA,dir,a,b,4,2); RayMsg* m=&ma;
  e->pending=1;`, ctor body m=this/Event_Construct/field-order stores/start.w/end.w) = 11 and needs NO opt_propagation
  pragma; store order is exactly retail, remaining = site-1 arg order (2) + li 1/li 2 register swap (retail 1->v1
  hoisted, 2->v0 late; ours 2->v1 hoisted, 1->v0). `RayMsg* m=&ma` must precede pending (else 19).
  No gain: ctor arg/const forms (yg), Event_Construct forms in ctor (yh), trailing stmt forms (yi/yq/yo), pragma sweep
  (yj), base-class + init-list ctor (yk 33+), m2 aliases (yl), b5C position in ctor (yp), copy mechanisms (yr),
  `pending = force` (110), types of b5C/pending/f58 (yc), random store permutations (yd, 22+). The same ctor in the
  else branch gives 16 (extra addiu &mb), so the else site keeps explicit stores.

## 22CB10 MATCHED (session 4): constant rematerialisation
- Final form is the inline-ctor form (alt_22CB10_ctor.c) plus two changes:
  1. In the ctor, `char b2 = bb;` comes first and is stored later with `m->b5C = b2;`. That makes a constant vreg
     live across the Event ctor call, so the RA rematerialises it (`li v0, 2` just before its use, in a free
     register) instead of the prepass hoisting it. The type matters: `char` gives addiu, `unsigned char` gives
     daddiu, and `int`/`short` blow up the size.
  2. Call `cMessage_ctor_cMessageNameR(m, D_005435A0)` directly. A `void* t = D_005435A0;` temp in the ctor
     reverses the a0/a1 setup order.
- General trick: when retail shows a constant `li` sunk late into a reused register while other constants are
  hoisted, assign the constant to a local before an intervening call and use it after the call.
- The asm jal names are outdated; use the symbol_addrs names: cTargetManager_FindGobj, cSystemContainer_GetSystem,
  LosProvider_SeedRegion, cMessage_ctor_cMessageNameR, std_list_deleter_LosReqElem_insert,
  cAreaEffect_LOS_Obscured, cLosResult_ctor_cLosResultR.

## Session 5 (R212+, 06:00-) negatives / progress
- 219820/153870: fptodp workarounds dead. Explicit SoftFloat_FloatToDouble call instead of implicit conversion = 18
  (changes colouring); MW rejects `__asm__("label")` decl renaming; #define leaves `fptodp` in the object. Only the
  config\extra.ld alias `fptodp = 0x0011BD70;` unlocks them.
- 180580 stays 17: VX ctor x Mul body x QMul pointer-local combos (zl), deltaRot/projectedRot forms (zo 21-45),
  Mul body/arg forms (zq/zr 17-30), dead-variable placement (zs/zt), phantom helper stubs (zu, no effect),
  V copy-ctor asm forms (zI 17-38).
- 405660 stays 21: LOD signature forms (zm), constant placement (zn/zp, 21-177), phantom stubs (zv), SUB/TYPE
  expression forms (zw), GCC asm SUB (zx: volatile 94, non-volatile 21).
- 3DDFC0 64 -> 52 (best_3DDFC0.c = sq4_n.c + `static inline void MemClear_DFC0(void* dst, short n)`): the short
  param makes a late sign-extended vreg that colours a0 (n in a0, dst a1 like retail) with one CSE'd sll (v1).
  Leftover there: extra dsll32/dsra32 and subu uses v1 (retail: single `sll a0,s0,2` used by both).
  `char n` = same 52; `(short)n` at the call site = 52; unsigned short 58; int/long/u64/pointer/register/const 64;
  `MemClear(sp, data*4)` forms 61 (sll not CSE'd).
- 3DDFC0 case 0x40 s-regs: declaration order of newf/g/numArgs/saveIP irrelevant (zD, all 59 with saveIP hoisted).
- 3DDFC0 0x58C join: ternary/inline TypeId/IsA forms (zE/zF/zG/zH) keep the join `b test` unchained like retail but
  MW then fills the beqz delay slot with `addiu a0,-1` (57). Plain if/else forms chain both arms (52).- 3DDFC0 no gain (zI-zT, all from best_3DDFC0.c): case-0x12 local retVal 160-164; prototype-only locals
  (unused saveStackPtr, funcNum=data) 52; moving num into case 0x12 62; retVal temp/copy forms 52 (coalesced);
  loop shapes do-while/for/while(1)/while(!done) 57-58; op/data fetch without ip 59-63; volatile done/saveBP 82-90;
  extra retVal uses in case 0x3B 54/115 (retVal stays s7). Colouring: ours i,newf,num,f,this,null_ptr,saveIP,retVal
  vs retail i,newf,retVal,f,this,num,null_ptr,saveIP,oldFunc. retVal (uninitialised, live from entry) colours last.
- 3EF660 296 -> 231 (best_3EF660.c = b5): face loop `{ int i = 0; if (i < n) do {...} while (++i < n); }` gives
  retail's inline `slt at,zero,n; beqz` guard + nop (243); Cp3 stores `fd[2]=z; fd[0]=x; fd[1]=y;` fixes the
  0,4,8 load order (231) but stores come out z,x,y (retail x,y,z). FP colouring rule seen: loads are emitted
  f2,f1,f0 and the first-stored temp gets f0, so loads x,y,z + stores x,y,z not yet reproducible
  (zX/zY/zZ: decl orders, t[3], V3 fields, for-k, interleaved decls, __restrict: 237-243; struct copy 434-594).
- 3EF660 neutral (231 each): param copies/`register`/void* parent/ctor-form/late `cur`/`me` copies after the buf
  alloc (y3), inline MAlloc/MFree helpers (y4), block-scoped n per loop or `self->n66 = n = ReadI()` (y0, 231-234),
  buf alloc forms (zU: alloc in block 433, p alloc 427, size=-(buf-p) 278). Remaining ~200 lines are the s-reg
  permutation: ours buf s0 (coloured first), cursor s1, this s2, p s3, n s4; retail cursor s0, this s1,
  parent/n/q s2, p/size s3, buf s4. Diagnostics (y2): removing the dealloc, the memcpy use, the parent store, or the
  alloc call itself leaves buf/parent in s0 - the buf-first colouring is not use-count driven.

- 3EF660 more neutrals (from best_3EF660.c, all 231 unless noted): separate var for 2nd p web (`p2`) 274 (p2 colours
  first, s0), separate 1st web 274, separate 3rd web 231 (y5); early dummy inits 231, `p = buf = Alloc` 398 (y6);
  buf/p/n/size decl-order perms incl. top-of-function 231 (y7); `self->parent = parent` position (y8: 232-238, 267
  when moved after the buf alloc); dropped weak stubs before the function (y9, all 231); empty GCC `__asm__ volatile("")`
  uses of cursor/self/buf (ya: 231, MW drops them).
- 3EF660 colouring order clarified (y8_f): ours colours buf FIRST (s0), then cursor s1, this s2, p s3, n/size s4,
  i s5, arg s6; parent is coloured late and just takes the lowest free reg (s0, shared with buf; s3 when it
  overlaps buf). Retail order: cursor s0, this s1, n/q/parent s2, p/size s3, buf s4, i s5, arg s6. So the only
  real difference is buf's priority (too high in ours). Not use-count driven (y2), not declaration driven (y7).
- 230DE0 checked again: base is raw m2c (size 0x990 vs retail 0x1080, stack 0x2D0 vs 0xB80, inlined VU0 matrix
  copies missing). Needs a full rewrite; not attempted this session.
- 180580: Mul with reversed params `Mul2(VX b, const V& a)` / pointer forms / hoisted Conj temp (yb): 17-34, the
  &m->rot vs copy-dest register swap is unaffected by argument evaluation order.
- 3DDFC0 MemClear cluster (yc-yf, all from best_3DDFC0.c): int/unsigned/signed-char params, swapped (n, dst) param
  order, local copies inside the inline, no-op conversions (Id(), n*1, +n, (unsigned), n|n, n>>0) all 61-65; with an
  int param dst is coloured a0 and n a1 (retail: n a0, dst a1). Two separate `data << 2` (yc_e) gives n a0/dst a1 but
  the sll is not CSE'd (61). `(n, n)` forces a stack spill. signed char = 52 like short.
- 180580: QMul as member `V::operator*(const V&) const` (inline in-class or out-of-class, for projectedRot and/or
  inside Mul) = identical 17 (yg). Second-section diff is scheduler order of the addiu sp+0x50/sp+0xA0 pointers.
- 3EF660 231 -> 228 (yy_a, now work\best_3EF660.c; b5 kept as b5_3EF660.c): drop `size`, use `p = (char*)(p - buf);
  if (p) { ... Allocate(0, (int)p ...); memcpy(self->a88, buf, (int)p); p = self->a88; ...` -> retail's in-place
  `subu s3,s3,buf`. Neutral/worse: `p -= (int)buf; size = (int)p` 274, size decl moves 231, `p = buf = Alloc` /
  `buf = p = Alloc` / alloc into p 386-414, parent store positions on the new base 228-259. q still s4 (retail s2,
  shared with parent/n): the remaining cluster is the param colouring (retail cursor s0, this s1, parent s2).
- 3EF660 MATCHED (session 5): 228 -> 222 -> 206 -> 28 -> 6 -> 0. Keys, in order:
  1. Face copy (C++ mode!): `typedef struct { int v[3]; } A3; struct FR { A3 xyz, uv, rgb; }; fr.xyz = src->xyz; ...`
     with `int* pu = fr.uv.v; int* pr = fr.rgb.v;` before the copies. In `#pragma cplusplus on` a struct copy of
     `{int x,y,z}` / `{float x,y,z}` is SCALARIZED (lw/sw per word or kept in regs); a struct with an ARRAY member
     `{int v[3]}` is copied with retail's lwc1 f2,f1,f0 / swc1 block (C mode does it for any 12-byte struct).
  2. Temp v0/v1 swaps after ReadI: write some reads explicitly `n = *(int*)*cursor; *cursor += 4;` (n66, n6C, n6E)
     instead of the inline ReadI.
  3. THE s-reg permutation (buf coloured first): allocate buf through an inline wrapper
     `static inline char* AllocB(int size, int line) { char* r; { AllocGuard g; r = Allocate(0,size,file,line); } return r; }`
     -> 206 -> 28. Colouring priority depends on how the vreg is born (inline result temp vs direct assign).
  4. Size block: `p -= (int)buf;` (not `p = (char*)(p - buf)`) -> in-place subu, last 6 lines gone.
- 405660 (session 5): .set noreorder inside MW asm{} pcpyld helpers (xh/xi) and fused pcpyld+sq asm: 45-94, worse than 21. Scratch cleaned from work\ (kept M_*, best*, base_*, alt_22CB10_*, sq_a, sq4_n, t3, b2-b5_3EF660, pc3_g4, f_m1).

## Session 6 (R214 list) — final state
- DELIVERED: 00219820 cPathedGOBJ_ctor (pending\k6\mw38_00219820.c), 00153870 cNPC_Follow_cMessageR (pending\k6\mw38_00153870.c).
- 00230DE0 Global_Shatter (4212 B): reconstructed from proto DWARF + disasm, raw m2c 1003 -> **12 differing words**.
  Best draft: work\g_230DE0.c (size 0x1074 = retail). Key idioms (score path 140->130->120->111->95->84->77->54->40->24->12):
  - `V* p = &r; ...; return *p;` in inline vector ops (ApplySelf `operator*(M,V)`, GetNormalized); ScaleV wants `V* p=&r` + `return r`.
  - operator/ owns its own `V r` (not delegating to operator*) -> inline-temp stack order matches retail.
  - Cross: `static V Cross(a,b)` + **friend** `operator^(const V&, const V&)` returning Cross(a,b) (40->12 with neg below).
  - Unary minus via `static void VU0Neg(V& o, const V& i)` asm helper; `V operator-() const { V t; VU0Neg(t,*this); return t; }` (40->24).
  - M copy ctor as GCC asm with `M* d=this;` declared before temps and `const M* s=&o` after (decl order drives asm reg choice).
  - SetUnit as GCC asm with "+r"(m) (prevents CSE of &mat); Min as `"=f"` GCC asm min.s; `GetType()` inline getter for cross-branch CSE.
  Remaining 12 words:
  (a) 0x28C `(GetPos()-GetPos()).GetNormalized()` copy chain 1C0->520->200: retail colours copy-1 dest a0 (early) and copy-2 dest v1 (late); mine reversed.
      friend `operator-(const V&,const V&)` (v_s2) gets the order right but swaps a0/v1 through the whole sub+copy (15). Tried: GetNormalized forms n1-n7/c4-c7, V copy-ctor forms c1-c3, Sub helper s1/s3, VU0Subtract operand reorder f1/f5, p in friend f2/f3 — none better.
  (b) 0xF18 sound msg: mine CSEs &msg (sp+0x630) into s0, retail rematerialises `addiu a0,sp,0x630` 3x. (c) 0xF90 retail has an extra nop before g_IsMultiplayer check.
  Next idea: friend operator- + swapping the VU0Subtract asm operand roles only for vecOut/vecIn0; for (b)/(c) try putting the sound block in its own `{}`/if scope or making cPlaySoundMsg ctor/QueueMessage take refs via a non-inline wrapper.
- 00180580 QuaternionLERP UpdateVelocity: 17 (work\sq_a.c), unchanged. 00405660 Monster_ctor: 21 (work\base_405660.c), unchanged.
  003DDFC0 cScriptInterpreter_execute: 52 (work\best_3DDFC0.c, DD_RWIN=8), unchanged.
