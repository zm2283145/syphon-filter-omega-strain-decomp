# k8 NOTES

## 003ED2E0 cInterfaceModel_Render
Best: build\agents\k8\work\dm1.c  (cdiff mw38 score 49; size 0x56c vs 0x570)
History: im6 (145, iterator design) -> im14_c16 (118, color ToRGBA float locals) -> mx_sep_b1 (76, cMatrix asm lq/sq copy ctor+operator= + Translate method) -> mo_o1 (67, operator= decl order `u_long128 reg0, reg1; const cMatrix* s=&o; cMatrix* d=this;`) -> mx2_x2 (57, ToRGBA c16 in FilterChildren, ToRGBA2 c13 in ActuallyDraw) -> dm1 (49, DrawMode `mode |= 1;` before cTexMan_SetActive call fixes delay slots).
Findings:
- cMatrix copy: separate-statement lq/sq asm (0023E890 style) in copy ctor (refThis form) and operator= (temps declared first) reproduces retail pipelined copies; the compiler schedules addiu between them.
- Retail has 2 dead `addiu v0,sp,0xF0` in the copy-out; mine has 1. Not found yet (tried Translate wrappers, refs, pm pointers, GetView by value).
- Color: retail cvt in-place, mul/store interleaved, K in f0. c16 (float locals) gets K f0 but extra cvt regs; c13 (direct args) gets op order but K in f2. Retail also reloads the ToRGBA temp (0xC4) from stack for the product; c13-style does that, c16 keeps in reg.
- Iterator slots: retail 148 begin-ret,144 begin-ctor,140 end-ret,13C end-ctor,138 begin tmp,134 end tmp; mine differ (begin/end interleaved).
- DrawMode fixed (dm1). Loop shape (while/for split) and nested inline begin()/end() wrappers do not change slots (all 49).

## Prior bests (other lanes)
0025FBB0 70 q07\work\best_0025FBB0.c; 001BB1D0 52 c110lg\work\best_001BB1D0.c; 00162080 178 p15gui\work\pr5best.c;
00151D30 450 p10npc\work\hm13.c; 001CB160 ~446 c113hg; 003870C0 439 c122hg; 0013FF40 516+ c29fr; 001D40E0 ~706 c109lg; 00414900 r02 h1 (9 lines mw).

## 0025FBB0 cVisionFxMan_ActivateFx
Best: build\agents\k8\work\gc_c.c (cdiff mw38 49; was 70 from q07). gb_d.c also 49.
Fixes 70->49: V4AC ctor floats by value (lui/mtc1 instead of pool lwc1); SetTrans as asm lq/sq `Copy_25FBB0(void* dst, QV* v)` with `V4A* tp=(V4A*)&mtx.r[3]` reused as SetPosition arg (CSE a2); MulVec(out,v,m) param order; `if (m->b2C != 0)` on first aux test.
Remaining: min/max coalescing x3 (retail result in const reg: `f5=1.0; c.lt f5,f0; bc1f; nop; b; nop; mov f5,f0`); ternaries give right branch shape but coalesce with x (score 90+). lw 0x190 reload before ambient copy; nop at 0x6ec; dead `mtc1 zero,f1` inside point SetColor; trailing nop.
Tried w/o gain: bool/signed char b2C/b2D (51-52), bitfield aux (57-65), unused float zero in SetColor (51), Fade_Value sibling form, macros, templates, refs.
MATCHED 17:33 -> build\pending\k8\mw38_0025FBB0.c (mw38/mw50/mw304 MATCH). Final fixes 49->0:
- Min/Max as `float r = a; if (a < b) r = a; else r = b;` / `float r = a; if (a > b) r = a; else r = b;` -> retail `bc1f; nop; b; nop; mov` with result coalesced into the constant's reg (the then-branch self-move gets deleted, leaving the b+nop).
- drop `volatile` on s->ambient test (removed reload + 0x6ec nop).
- dead `mtc1 $zero,$fN` = dead initializer: `float q = 0.0f; ... q = LenSq(&v); invMag = 1.0f/q;` in a point-only copy of SetColor (q coalesces with LenSq result reg f1). MW keeps dead initial assignments of later-reassigned locals.
- That also fixed andi/nop after `if (m->b2C)` (plain test, no `!= 0`).

## 003ED2E0 later sweeps (still 49)
- Color reg rotation: ~60 more variants (gA ctor-body direct stores 66-70; gB ints-first 63-64; gC float locals then pairwise 63-66; mini harness t20 with G(e) call context). Pairwise in-place cvt always gives K=f2, values f1/f0; retail K=f0. MW canonicalises const*var operand order (source order irrelevant). Sibling 003ECD60 uses a different (r,g,b,a) pattern so no template there.
- Iterator slots: gD-gI (begin/end return forms, loop forms, by-value params, node_ copy, ctor/inheritance) all 49 or worse; `return Iter(...)` elides the copy (size 0x55c).
## 003ED2E0 session 2 (k8 later): 49 -> 47 -> 43. BEST: build\agents\k8\work\dm4.c (rd/cdiff mw38 43)
- 47 (dm2): dead `__asm__ volatile("" : : "r"(this));` as 2nd stmt of the cMatrix asm copy ctor reproduces retail's duplicated dead `addiu v0,sp,0xF0` (and removes a stray nop).
- 43 (dm4): call FilterChildren / ActuallyDraw through plain `static inline void FCw(cInterfaceModel* self, const tRGBA& c) { cInterfaceModel_FilterChildren(self, c); }` wrappers -> fixes a0/a1 order (`daddu a0,s1` before `addiu a1,sp,X`) at both call sites. (Real source: inline member calls.)
- DrawText double nop (retail `beqz +4; daddu; jal DT; nop; nop; jal US; daddu`, size +4): reproduced only by inserting a real branch/asm/loop right before ActuallyDraw (or after it), or by DELETING code (DrawMode, SetFrame, ToRGBA2 product) -> looks like a size/complexity-dependent per-block filler choice. Zero-code splitters (labels, goto, if(0), do{}while(0), empty if, inline wrappers incl. DT inside wrappers) do not. Prototype (MW 2.4.1) has the same double nop.
- Colour: retail K=f0 with in-place cvt pairs; mechanism found: K's register is reused for the last product only when the product is written as `k *= x` (db_kk.c) but K then gets f3 (coloring order = higher vreg first; K must be created after the cvts). ~20 more forms tried (member ctor, int ctor, loops, by-value, packed wrappers): none better.
- Iterator slots: prototype confirms retail slots (begin sret 0x138, ctor 0x144; end sret 0x134, ctor 0x13C). Retail allocation order looks like [B-copy,B-r][E-copy,E-r][B-sret,E-sret]; ours [B-copy,E-copy][B-r,B-sret][E-r,E-sret]. Direct std calls / return-ctor forms worse (52-56).
- Later negatives (all on dm4, none < 43): explicit ctor-call forms (dy3), template cLList<T>/cLListIterator<T> (dtp), nested inline lb()/le() (dh), loop forms (direct-init / pre-declared / ==) (dl), by-value ctor/!= params (dv), list_iterator copy ctor / member std calls (dw, dmm), base-class iterator hierarchy (dt), inline_depth / auto_inline / defer_codegen pragmas (dp), deferred (after-Render) inline defs (dq, dzz), operator!= via cConstLListIterator conversion temp (dcv: c4=49 gets B-sret 0x138 right but adds a slot), conversion operator (dr), explicit cLListIterator temps in the for (dgx), empty asm barriers around AD (de: no effect on DT nop), product/cvt local orders + `k*=` forms (df, dg, du), tRGBA(tPackedRGBA) ctors (dcb), cascade forms (dtr).
- Deletion bisect (hk.py/hb.py): FP colouring and iterator slot order are unchanged by deleting FC, SF, DT, DM, SetupView, UnsetupView, else-branch, Push/Pop; ONLY removing the cascade block changes them (loop gets rotated). Slot order observation: ours allocates [inst][B-ret][E-ret][B-r B-sret][E-r E-sret]; retail [inst][B-ret B-r][E-ret E-r][B-sret E-sret] (prototype identical) -> sret temps of the std::list calls are allocated last in retail (they were inline-but-not-inlined template functions emitted out of line right after Render in the prototype: begin 3db630, end 3db610, ctor 3db620).
## 001BB1D0: check_match DIFF +888 (size 0xf64 vs 0xf80) for work\b1b.c; cdiff overstated earlier (retail relocs unmasked). Dropped.
## 00414900 Gui_Init (from r02 h1; unit gui_2 is mw38)
- rd.py (k8) = real-diff counter masking relocs: h1 plain mw38 35, size mode 20.
- Retail guard shape (beqz;nop;jal Alloc_Lock;addiu a0,9) appears in matched plain-mw38 funcs (path_7 cAIPathData_InitSystem etc.). Bisected path_7: the whole-function delay-slot policy (no fall-through fill, e.g. `bnez;nop` instead of `bnez;lui at`) flips ON only when the function has an MW asm block (`asm{.set reorder}`, `__asm__("nop")`, asm V4 copies; GCC empty `__asm__("")` does NOT count) inside a loop that also contains a nested loop. asm alone / nested loops alone / size / spills / pragmas don't flip it. Gui_Init has no loops -> not applicable; asm barrier at 7 positions no gain.
- Size-mode sweeps (alloc helper param forms, new-expression ternary/else, goto) no gain (best 19-20 real).

## 00414900 Gui_Init — MATCHED (build\pending\k8\mw38_00414900.c, mw38/mw50/mw304)
- Key: mw38 per-function delay-slot policy (fill beqz slot from fall-through vs. leave nop + fill jal slot,
  retargeting branches +4 with dead copies) is flipped by a `?:` whose condition is non-trivial (&&, call, deref)
  and whose result is *assigned* (to memory/var) or passed as call arg. Found by bisecting GuiGameScreen_onAdd (work\gg0.c, gg*.py):
  `o->f4C = (w && w->flags) ? w : 0;` -> RETAIL policy; `if (w && w->flags) o->f4C = w;` -> FILLED.
- Gui_Init: `if (!name || !*name) name = D;` -> `name = (name && *name) ? name : D;` took REAL 35 -> 0.
- Not every ternary triggers it: `f((name && *name) ? name : D)` alone did not; the self-assignment ternary did.

## Session 3 negatives (003ED2E0 stays 43 @ work\dm4.c; 001BB1D0 53 @ work\bb0.c)
- 003ED2E0 all >=43: cascade forms (dtr), noinline/dont_inline begin (dn: err/71), deferred inline defs after Render (dd 43, slots same),
  continue/while/do-while loop shapes (dc,dx2: 43..76), real inline std begin + inline_depth (dq2 157/136/62), ternary delay-slot policy (dpol: no flip),
  #pragma inline_bottom_up (dbu: no effect), by-value/RVO begin (drv: 52/43), template tlist<T> base (dtl 43/43/74),
  real generic_iterator<C> hierarchy w/ i_ member (dgi 50/60). mw50/mw304 also 43.
- Slot analysis: retail [P_B 148,R_B 144][P_E 140,R_E 13C][S_B 138,S_E 134] => R (cLListIterator) allocated with P (cConst) at call site, sret S temps last.
- 001BB1D0 bb0 (=c110lg best) REAL 53: msg/edge callee-saved swap (retail msg=s4, edge 0x3294=s2). Decl order/param variants (bb,bb2) worse (65-143).
- Session 3b: 001BB1D0 andi hunt (be/bf/bm/bn, bu_*, bv_*, bw_*, bx_*): enum eType (enumsalwaysint off) field/params, bitfield `unsigned mode:8`, inline IsTele(uchar/int) + IsMove(uchar) combos, int-returning accessor, casts, uchar local: NONE emit `lbu;andi 0xff` before the ==3 compare. Only an int->uchar inline-param conversion in the ELSE branch emits andi (u3/u4, 57); `signed char` field gives lb+andi (60). Best stays 52-53.
- 003ED2E0 (dy*, dz*, dp*, dq*): ToRGBA forms for block 2 have NO effect (all 43) -> its K=f3 is decided globally; block-1 forms (local orders, product locals, tRGBA*k, member assign) 45-166. Iterator: begin/end RVO, operator!= by-value/const-conv, nested lb()/le(), ctor(list_iterator by value): slots unchanged or worse.

## Session 3c (k8)
- **andi idiom found**: MW keeps `lbu; andi 0xff` before a uchar `==K` compare when an `asm volatile` block (e.g. lq/sq vector copy) precedes the compare in the same block. Minimal repro (work\an_t3 vs t2): `cVector d = c;` via asm-copy ctor before `if (s->m == 2)` -> andi; plain __int128 copy -> no andi. Source: matched cHuman_JumpLaunchApplyForce (func_001A2470.c) found via andiscan.py.
- 001BB1D0: delta copy `{ V* dp=&delta; RQ3(dp,&D_004E1D90); }` (asm lq/sq, src operand first) -> andi appears, delta copy order matches. HeadingOfT (copy r0 then `__asm__ volatile("" : : "r"(&m))`) at the IsRot site fixes the duplicated dead `addiu v0,sp,0x310`. `Msg* msg = msg0;` after flor decl. Now REAL 43, size 0xf74 (=retail minus 3 pad nops): best = work\bb2.c.
- 001BB1D0 remaining: msg/edge s4<->s2 swap (~30 lines; retail moves a1->s4 in prologue), extra nop after AllFree's `daddiu v1,1`, missing nop after Lanes jal at 0x2e4, a0/a1 swap in HeadingOfT r0 copy at 0xb9c, Q(m) ctor src/dst addiu order at 0x8a0. Negatives: all 24 perms of edge/ladd/flor/msg decls (elfm best), msg as param/reference (87), Act* copy (57/86), Q ctor operand orders, r0 copy forms.
- andiscan.py: 12 asm fns have lbu+andi; matched ones: func_00389FA0, func_0038E100, func_001A2470.
- 0013FF40: work\fw0.c (c29fr best) REAL 545; missing Euler->matrix + VU0 3x3*4x4 region (retail 0x698-0x7fc) and transform at 0x918.
- 00151D30: p10npc hm13.c gives REAL 575 under my rdn (size 0xd30 vs 0xde0).
- **001BB1D0 update -> REAL 38, best = work\bb4.c** (size 0xf74 = retail minus pad). Steps from bb2: (a) Free2 as `bool r=false; bool f=Free(a->flor); if (f && Free(a->edge)) r=true;` removes the stray nop after `daddiu v1,1` but adds an andi at 0x3c (net +2); (b) HeadingOfT r0 copy as `V r0; { V* dp=&r0; RQ(dp, m.m[0]); }` + dead asm use of &m fixes the a0/a1 swap at 0xb9c. NB the "missing nop after Lanes jal" listed above was an alignment artifact; it matches.
- Block-scoped pointer temp `{ V* dp=&x; RQ(dp,src); }` changes MW's temp register choice for asm lq/sq copies (fixed both delta copy and r0 copy).
- 001BB1D0 still open: andi-vs-nop at 0x3c/0x64 (no Free2/HasParent/FreeI form gives neither), Q(m) ctor addiu order at 0x8a0 (block/ptr/asm-dummy variants no effect), msg/edge s4<->s2 swap. Swap negatives: msg as param (ptr/ref, with/without Act copy, all 6 anchor perms) rotates regs (msg gets s0/s1); msg copy placed after init/delta; asm dummy uses of msg/edge; const/two-step decls. Prototype says anchors are `cSkaAnimAnchor&` locals floor,ledge,ladder and msg is `const cMoveMsg_Template&`, returns unsigned char.
- 003ED2E0 (dm4, REAL 43/45 depending on scorer run): prototype Render__15cInterfaceModelFv is hash-exact (same 1388 bytes). Remaining: FP scheduling in the two tPackedRGBA->tRGBA conversions (retail cvt-in-place + mul/swc interleaved a,b,g,r using only f0-f2; ours batches cvts into f3-f5), begin/end iterator temp slot swap (0x138/0x13C vs 0x140/0x144), extra nop after jal DrawText before label 0x2a0. Negatives: 13 ToRGBA forms (member assigns a..r / r..a, ctor-then-*k, int temps, local k, float-temps-then-mul, sibling 003ECD60's tRGBA(const tPackedRGBA&) ctor + `k * ToF()` forms: all 55-205); begin()/end() return forms (48-58); DrawText return types/wrappers/else/asm barrier: no change.
- 001BB1D0 late negatives: unsigned char return, `Root&` anchor locals (both no change, 38); `Msg* msg = msg0;` before AllFree (80-103, gets prologue a1 move but msg in s0); 12 more Free2 forms (40-56); placing msg copy after init/delta (39-108).

## 0013FF40 cWeapon_FireIfReady (k8, fw series) — best fw25c.c REAL 185 (from 545)
- fw6: Shot = dossier cBulletInit (0xF0) w/ cCollisionFace (0x70, cVec v[3]); ctor zeroes owner/tgt/hitTerrain/def, particleId=-1.
- fw10d: inline-asm MulV (vf4-7 rows, vmula/vmadd chain); V16{float x,y,z,w; V16(){}} aligned(16) kills byte-copy for by-value returns.
- fw11b/15d/18b: uchar callee params (f64 quiet, HeldItem_Discharge, IsReadyToFire, RecordShotStats) remove andi 0xff; uchar fields -> lbu/sb.
- fw13b: stack buffers sized from dossier (cSndFx 0x190, cPlaySoundMsg 0x1C0), dtor sub-offsets 0x48/0xE4.
- fw16c: `float z=0.0f;` stored later -> mtc1/swc1 not sw zero.
- fw17b: SlotUsed(){return !SlotEmpty();} bool inline -> sltu/xori/andi.
- fw20a: `Ev ev; Ev* p=&ev;` keeps msg address in s-reg like retail.
- fw23b/24a: `Shot* t=this;` in inline ctor gives t0-relative stores; fold face ctor into Shot ctor with manual do{v+=0x10;}while(v!=f+0x30) loop (nested ctor w/ t=this gets outlined).
- fw25c: `if (!self->xCC[hand])` instead of `== 0.0f` (-1).
- Remaining: frame 0x730 vs 0x720 (kind==5 Ev should sit at 0x1B0, snd at 0x6D0; -0x20 shift below msg), face-loop regs, Shot field store order 0x400-0x440, s0/s1 swap in 2nd message, size 0xe04 vs 0xe00.
- Negatives: ZP/NegI wrapper members, init-list ctor, out-of-line ctors, SendNoise helper (262), Shot& alias (322), C++ msg classes (235), int->uchar fired (+1), Ev decl reorder (0).
### 0013FF40 update (20:09) — fw37b.c REAL 19 (size 0xdfc vs 0xe00 = retail trailing nop pad)
- fw27f: Shot stores reordered to dmg first, range before scale (-7).
- fw29: KEY: dossier-sized message objects. Reload/out-of-ammo msgs are 0x30 (Ev2) not 0x40 -> whole lower frame aligned (178->102).
- fw28/30: MW places address-taken locals of *inlined* functions after all direct locals, in inline-expansion order. Wrapping kind==5/mid noise Ev, Projectile LaunchAt(V16 temp), SendReload/SendOut into static inline helpers reproduced retail Ev at 0x1B0 / V16 0x1A0 / Ev2s 0x130/0x100 (102->93).
- fw31/32: snd is char[0x24] (frame 0x720 exact).
- fw33c: tracer `if (f && IsMul(c,f))` with `static inline bool IsMul(a,b){return !(a%b);}` gives sltu/xori/beqz.
- fw35: final vt store before dtor via `ev.vt=` (sp-relative in delay slot) while other accesses via p; fCC(VObj*, uchar); rate as if/else (store in delay slot); AiSound_SendFireNoise(Ev*, void* pos, float, float, int) param order = evaluation order (actor load before 1.0f); uchar return + uchar fired (85->36).
- fw36/37: `def->x5C > 1` (slti $at + speculative x5C-1 in delay slot); Actor_AddShotShake has 2nd float arg def->xA4; `VObj* c = ...; unsigned char pl = 0;` order; separate `Act* b` for dual muzzle flash (36->19).
- Remaining 19: small-region top locals (FxReq x2, none) 8 bytes high (ours 16-aligned start 0x700, retail 0x6F8/0x708/0x718) — unused locals are dropped, int[3]/char[12] same, double/aligned(8)/size16 moves them to big region; SendOut s0/s1 swap (v vs p) — param/ev/p/order variants all neutral.
- fw43c (REAL 8, best): a function-scope address-taken dummy `int spare; int* sparep = &spare;` reserves the 4-byte top slot retail has at 0x71C (never accessed) -> small-region locals (FxReq x2, none) land exactly. Only diff left: SendOut s0/s1 swap (retail v=slot->id in s0, &ev in s1); tried param int v, decl orders, late `p=&ev`, ev-only (v gets s0 but &ev rematerialized), C++ OutMsg ctor classes, IsPlayer inline, const v — all neutral/worse. Plus retail trailing pad nop (0xdfc vs 0xe00).
- Small-region allocation insight: locals <16 bytes sit at frame top allocated top-down in reverse declaration order; >=16 bytes or aligned(8) types go to the big region; unused locals are dropped but address-taken dead locals keep a slot.
- 0013FF40 final negatives (fw44/fw45, all REAL 8-13): nested OutSend(Ev2*,int,Wpn*) helper (13); &ev in Send/dtor (8); p decl after Construct (13); register v; p assigned in call arg; int* q temp; pl as int (9)/bool; nested if(pl) if(!D); c-before-pl order; Slot* s copy. s0/s1 swap unresolved; best stays fw43c.c.
- 001BB1D0 final negatives: register/const msg, msg via early m1 copy (all 38); all 24 perms of PRE-DECLARED edge/ladd/flor/msg with assignments after AllFree (82-207; elfm=38); msg assigned before AllFree w/ predecl (88); &msg0 taken (177).
- 0013FF40 more negatives: SendOut returning v; v used in dtor arg; empty-asm uses of v (1-3x, before/after Send): no change (8); all 30 mixed p/&ev use-site combos: 8 (13 when only Construct uses p); dead pad store (17).
- 0013FF40: const int& v local (14), const int& param (15), Wpn* w copy (8). Stop: best fw43c REAL 8.

### Session 2026-10-31 (k8)
- 0013FF40: fw50.c = fw43c with real symbol_addrs names (cnames.py maps our relocs to retail jal/hi-lo targets; renm.py rewrites a draft). Official check_match: zero UNDEF, only s0/s1 swap block + pad. mw50 same (8), mw304 14.
- Swap analysis: coloring looks priority-based (refs vs live-range length), not decl-order. fw58L1 (p=&ev defined at top of SendOut before pl computed) gives retail v=s0/p=s1 but hoists addiu to 0xcf4 (119). Reusing pl variable as v (fw62Q1-3): v/pl gets s1, p s0 (24). Shared function-scope p for reload+out msgs (fw63S1): p still s0. Doubled v store: +1 insn. Sibling ReloadThrow form (no p) rematerializes &e. Negatives fw51-fw61: e[1] array, Ev2& ref, inline helper params, use-count variants, dead early defs, accessor inlines — all 8/13. Micro tests outside fw50 rematerialize &ev (not representative).
- 0013FF40 fw64T1.c REAL 7 / score 116 (best by REAL): SendOutX inline, `p=&ev` assigned after pl computed but before `if (pl && !g_IsMultiplayer)` -> correct v=s0/p=s1 but addiu s1 lands in d24 delay slot (beqz s0) not d38. fw50.c (REAL 8) stays the safer reference. Negatives fw64T2 (p inside if(pl): 15), T4 (comma in cond: 23), fw65 decl/assign orders (8), fw66 v copy chains (8), fw67 labels/goto/do-while (8), fw68 asm barriers (8), fw69 extra v stores, fw70 ptr-typed v/int-typed p (8), fw71 pragmas opt_propagation/dead_assignments/lifetimes/strength_reduction off (8), opt_common_subs off (101), opt_loop_invariants off (12), fw72 v as param/nested block (8). Same lw s0/addiu s1/daddu a0,s1 idiom appears in unmatched cNPC_HandleMessage (00151D30) — no matched reference.
- 00162080 cPathRequest_Update (draft name NpcRoute_Search): pr0.c REAL 189 (0x126c vs 0x12b0); p15gui pr5best.c ~178. Deferred (too far).
- 003ED2E0: dm5e/dm5f — ctor `tRGBA(const tPackedRGBA& c){int ia=c.a,ib=c.b,ig=c.g,ir=c.r; a=k*ia; b=..; g=..; r=..;}` reproduces retail structure (all 4 lbu hoisted, in-place a,b,g,r stores) but REAL 60 vs dm4 45: k colored f2/f3 instead of f0, values f1/f0 instead of f2/f1. dm6 (local k placement, operand order): 60. dm7: ints declared r..a (70), float temps / 4-int-param ctor (60), r..a body (77). dm5d direct `a=k*(float)(int)c.a` (no hoist, 72).
- 0013FF40 fw73-fw77 (04:30-05:00): prototype cNPC_HandleMessage shows the same lw s0/addiu s1 idiom with the message as an unnamed TEMPORARY (no local in DWARF). Temporary forms `SendTo(self, OutMsg(slot->id))` / `Post(OutMsg(v), ctl)` / base-class inline ctor / BaseInit helper: v correctly gets s0 but &temp is rematerialized sp-relative (13). `OutMsg* t=this` inside ctor or `Ev2* m=m0` copy: reg kept but swap again (8). Placement new (null check, 24). Pointer from inline return `Self(&ev)` / `MakeOut(&ev,v)` / `Ctor(&ev,n)` before/after v: 8-13, p always wins s0. => p (pointer) beats v for s0 regardless of creation order; only interference with pl (T1) prevents it.
- 001BB1D0 (05:00): msg used directly as param (bp P1-P3): msg gets s0, a s1 (88-111). `#pragma opt_rebuildlogicals off` no effect on andi (38); `return a && b` Free2/AllFree forms 45.

### Session 2026-11-01 (k8) — user-directed DWARF rebuilds of largest unmatched
- Bests: 0018A950 cHuman_HandleDeath work\pG.c +16 (score 22; was in14 +19); 001E2180 ActorPhys_RunResponse work\ar3b.c REAL 1006 (+1592); 0017A640 cGameCamera_UpdateMotion work\gc1.c REAL 85; 0024B5D0 PlayerInput_Update work\pi5.c REAL 1554 (clean, no UNDEF).
- Tools: cdw.py (WSL port of cdiff, aligned diff ~1.7 s: `.venv/bin/python build/agents/k8/cdw.py FILE.c mw38 FUNC | grep '^\*\*'`), lay.py (DWARF/stack layout dump of our build vs prototype), mut.py --bodies A,B (mutate inline bodies too).
- 0018A950: TailA `NmI_L(&tmp, D_0049DBC0)` helper for NAME_COPY (src reg v1, +18, nmG); P56_L `pp->a = actor; pp->id = id;` (store a before id) gives retail id=v1/pp=a0 (+16, pG) but stores then scheduled a-first (retail id-first). Negatives: P56 decl orders, no-pp, pp init, uns id, PairSet/XSetR/XSetQR/XSetP forms (+16..+26, some +545). InstNR `an` before ctor (in1/inA-C: an param, decl first, init decl) all +22 (schedule right, regs rotated an=s0 vs s3); TailC tcA-tcP (shared px refs, TC2 helper) never give retail `daddu s0,s3` (+19 or +320).
- 001E2180: extra 0x10 frame is a scalar spill slot in 0xD0-0x1F0 (a1 spill 0x1EC vs 0x1DC), not v860; inlining v860 (ar4b) grows temps by 0x10 instead. Retail temp slots allocated top-down in expression tree order (opSub result 0x8C0, GetTransformed 0x8B0, matrix 0x870, literal 0x860). Deprioritized.
- 0024B5D0 PlayerInput_Update (06:30, score = cnt.sh differing words): pi5 1554 -> ppA 900 -> qiA 844 -> qtB 744 -> r6C 650 -> rNC 493 -> rQA 478 -> rRA 477 -> **rWB 473 (= work\PI_best.c)**. Techniques that paid: FabsZ (`float r=0.0f; asm{abs.s r,x}`) wherever retail has hoisted `mtc1 $zero` before abs.s (case 6/7); ternary arm order picks the preloaded else-value (`>` with swapped arms); bool-from-float `u8 h = f != 0.0f` (c.eq/bc1f/addiu 1/daddu 0); temp-then-assign `{u8 h=0; if(..) h=1; var=h;}` produces retail's trailing `andi sX,aY,0xFF`; `int` instead of u8 removes andi when passed to int params; `SF(0x120) = MAX(0.0f, SF(0x120) -= dt)`; V4::Cp (volatile asm lq/sq with "r" in) where retail materializes `addiu rX,base,off; sq 0(rX)`; arg-order matching by hoisting args to locals in an inline (MakeTI3); goggle/scope via 5-arg cHud_SetScope + char* GetGoggleEntry. NEW (rQA): a *named* local consumed by the Cp asm keeps float constant stores as `mtc1 $zero; swc1` (temporaries / C-level copies get folded to `sw $zero`) -> SetThrow `PV(s,0xD0).Cp(t)` (-15). rRA: Set split as paddub-asm + Cp (SetB) gives retail register assignment for the H2 V4c Set (-1); stores still sw zero (temporary), named local fixes mtc1 but lands at wrong stack slot (named locals always placed above Box80 m; retail temp at 0x6D0 below it). rWB: case 5 `spd = Max(..); spd = Math_MinF(1.0f, spd); mv.x = clampY + d1.x + d0.x;` (-4; spd in f30 like retail).
- PI negatives: mv sum splits, `char ng` forms, IsWeaponAimed param types, empty-asm copies, Set reg-order variants, zero-float locals, non-volatile paddub, V4f ctor via ptr/const& (rQC 498 / rQD loads rodata), opaque mtc1-asm zero (MW still folds to sw zero), LimitManualAim wrappers / const locals (retail order f14,f12,f15,f13 unsolved), DriftV2 p/q decl orders and comma-expr call orders (p gets s0 instead of a1, retail treats vE8 temp addr as constant; `Ev40 m = vE8()` fixes reg but adds 0x40 copy).
- Unsolved PI clusters: 0x1C68/0x1CF4 Set reg order, 0x2350 LimitManualAim constant order, 0x27F0 V4c temp mtc1, 0x2CDC FlatSub, 0x3AB4 DriftV2 p register / SendXf ep s0 vs s5, 0x130/0x140 and 0x160/0x170 spill slots, 0x3E9C `char ng`.
- 0018A950 pG (22): mut_pG ~80 min no gain. pHA-pHH (TailC chain from XInit return, TailB-shaped TailC with direct x.pairs[4] + px for 5/6): 38-54, worse. Retail TailC: XInit inner px=s3, separate px var=s0 copy after k0 dies; ours coalesces.
- 0024B5D0 (06:45) rWB 473 -> rZE 465 -> s2D 459 -> s4C 449 -> s5D 448 -> s6A 439 -> s7A 435 -> s9A 432 -> saC 414 -> scE 408 -> **seB 402 (= work\PI_best.c = s8.c)**. Paid: idle block `SF(4)+=dt; float lim=D_004FFB98; if(!(SF(4)<=lim))` (local copy of global forces reload, -8); `clampY=ClampG(cy,-1,1)` gcc volatile asm keeps const loads in arg order (-6); init order rot.x,rot.y,quiet,rot.z.. (-10); `((int(*)[4])(inv+8))[sl][0]` (addu order); **real prototype signatures from build\agents\P1\map.tsv col 6** -> bool params (cPlayerControls_HandleReloadButtonPress(char*,bool,char*), UpdateTarget(char*,char*,char*,bool,bool,float)) remove andi; cVector_VU0Scale(V4*,V4*,float) arg order (-18); inline bool wrappers `Pk98(p){return PI(p,0x98);}` / `NotAB(s){return !SB(0xAB);}` force sltu/xori materialization before branch (-9,-6); `(unsigned char)call()` gives retail andi after jal (-6). Negatives: GateOk return forms (0x9D0 `daddiu v0,zero,1`), other Clampf->ClampG, slot struct forms, H2 SetX(paddub then temp V4c/V4 t in any store order) 506.

### PlayerInput_Update 402 -> 371 (06:52)
- shA 391: `AbsMax(a,b){return FabsZ(a)>FabsZ(b)?a:b;}` inline for case 7/6 abs-select.
- siA 381: `AbsMaxR(b,a)` same body, call `AbsMaxR(z.x,d.x)` -> retail load order.
- sjA/sjB 379: case 7 `mv.y=0; mv.z=0;` order; `x=AbsMaxR(clampY,x)`.
- skB: outer `Min0(a){float r=0; float z=0; asm{min.s r,a,z}}` / Max0 fixes mtc1 order + nops but exposed ev sign-ext (382).
- smA 381: `if (0.0f != b.f[8])` fixes c.eq.s operand order.
- soA 371 (PI_best.c): `int ev;` and compare/pass as `(signed char)ev` -> removes dsll32/dsra32 after `ev=-1` (signed char local emitted sign-ext on every def; int + cast at use matches retail).
- Negatives: SetX paddub+V4 temp (506), signed char/char/const/(signed char)-1/0xFF/~0 for ev (381-391).

### PlayerInput_Update 371 -> 282 (07:06, work\PI_best.c = xQ.c lineage)
- spA 355: SendCas_ takes `unsigned char* b` and derefs inside (by-value global byte hoisted its load before the ctor).
- sqA/srA 351/339: `char* gs = PP(hud,0x6A4); GuiGameScreen_ShowInteract(gs, GetString(..),1,0)` -> gs in s-reg before the GetString call (retail).
- srC 338: `if (w0)` (c.eq.s x,zero) vs `w0 != 0.0f` (c.eq.s zero,x).
- ssA 337: `ang2 = SB(0x2C) ? 3.1415927f - ang2 : ang2;` (self-assign ternary = retail b over empty else).
- ssD 330: `float t=0.0f; float z=t;` shared zero (mtc1; mov.s), `z != clampY` operand order.
- stA 324: SendObj int param (no andi). svB/swI 322/307: `bool InR(float)` inline with `bool r=0`; bool returns avoid sltu in && chains; `bool BitArray_Test(char*,int)` decl.
- swA 312: IsZero4B copy with `bool r` used only in quiet expressions.
- syC 303: `At2Y(x,y){float b=y; float a=x; return Libc_Atan2f(a,b);}` local decl order sets arg load order.
- u23 302: Cp0..Cp5 clamp permutation inline (case 2 lookY = Cp3 (lo,hi,v)).
- wG 301: case 5 `mv.z=0; mv.y=d1.y+d0.y; mv.x=clampY+d1.x+d0.x;`.
- xD 289: `t += 0x10; hgt = BoundsW(t);` in case 5 AND case 8 (retail reuses s5 = t+0x10).
- xJ 282: FlatSub via `CpN` asm with "=r"(q) (no early-clobber) -> lq v1,0(v1) reuse like retail.
- xQ 282: IsZero4N (extra `nop` after `ori r,zero,1`) for case 8 `!IsZero4N(&f4)` aligns code (score-neutral, kept).
- Negatives: case 5 mv temps/inline Add2 (301-311), bigWalk=true/(bool)1/inline bool/int (case 8 retail `addiu 1; andi 0xFF` unsolved), FlatSub CpN arg/operand orders (282-296), case 6 MinfR/MinV/MinW/MinX for d.x/z.x load order (282-284), Do180 by-value forms, LookOff SetS/SetT, LMA wrappers.

## PlayerInput_Update 282 -> 244 (DWARF rebuild lane, cont.)
- yE 273: inline Sq(); case 8 scale = Sq(Sq(n)) + 0.3f*(1-Sq(2n-1)) (retail n^4; mul.s f3,f3,f3 reuse).
- yP 270: MulK via named locals (float x=a; float y=b; return x*y) flips operand regs.
- yX 268: CpD/CpE asm lq/sq copies with "r"(d) first -> dst address computed first.
- zg 262: quiet = (unsigned char)CheckState(...) && lookY != 0.0f -> retail andi + daddiu1/nop/andi.
- Pdqs 251 / Q1 248: Set/SetX local decl order dst,q,src gives retail coloring (src=v0,dst=a0,q=v1).
- U1 244 (= work\PI_best.c): TgtPos PV(s,0xD0).Cp(*t).
- Negatives: fire-block bool/CFG variants F1-F9, Ga-Ge (247); MakeTI id/tp temps (Ma/Mc/Md 244 no change); bigWalk forms; V4c ctor orders; case 6 Minf orders.

### PlayerInput_Update 244 -> 223 (proto-pdis driven)
- Generated full proto disasm: `pdis.py 0024B5D0 <abs path>` -> dossier\0024B5D0.pdis (dossier .txt truncates at 700 lines).
- AP19 237: LMA constant args as named float locals `e2,k1,e1,k2` (order matters; 24 perms + subsets tried, 237 best).
- C0 230: **wrong arg counts** from proto mangled names: IsWeaponAimed__...CFv takes only this; FigureThrowAngle__8cGrenadeFf takes only float. Removing bogus args = -7.
- F2 227: `canFire = !(t != 0) || IWA(a);` (IWA inline: sec ? IsWeaponAimed(sec) : 0) reproduces sltu/xori/bnez + fp=1 delay slot exactly.
- J5 225: 180-turn copy `V4 t; t.Cp(*ls);` (Cp asm) gives separate v1 dst addr like retail.
- K1 223: DetectForAndHandle180Turn decl `(char* this, float, V4*, char*, char*)` (true C++ order, this first) instead of float-first.
- Negatives: by-value V4/CV params (763/724, frame -0x10), fire `int t` join temp (232), CanF inline (926, frame -0x10), fa/NotAB forms (227 same), ng types (230-235), opMul/GetFOV true-order decls (223-225), LMA locals hoisted/const (230-366).
- Remaining: spill-slot order (retail ok 0x130/ref 0x140/hasSel h 0x150/ammo 0x160/canFire 0x170 vs ours by first use), 180-turn arg move order (retail a1,a0,a2,f12,a3), ClampG const regs, 0x2400 F20 store order, LMA f14 first.

### PlayerInput_Update 223 -> 196 -> 153 (session 2026-11-01 late, work\PI_best.c = work\D4.c)
- Z9 196: inline-depth controls spill-slot/stack order (locals inside nested inlines are allocated after outer ones); proto `&&`/`||` expression shapes; const-ref inline param for temporaries.
- ZE 195: keep `int cls` but compare as `((unsigned char)cls)` at every later use.
- XA 178: push `+0x30` into the inline: `MkXf(ep,id,dd){ cMatrix_ctor_cMatrixR_cVectorR(p + 0x30, id, &tm); }` (pointer offset inside callee changes regalloc/schedule, -17).
- YD 177: fire block `cCharActionMsg_dtor(&e, 0)` instead of `(ep, 0)` (vtable store schedule).
- A1 (-8): asm input operands get registers in DESCENDING order (last operand = lowest reg) -> reorder Cp2 operand list to match retail.
- A2 (-5) tail loop store form; A4 (-10) `(float)sq` with `unsigned char sq` gives retail unsigned cvt without andi (U2F(unsigned int) added andi).
- D4 153: `static inline unsigned char NZq(float f){return f != 0.0f;}` for `sq = NZq(b.f[5])`.
- G1.c (160) has the retail-shaped mv sum at 0x23e8 (`mv.x = clampY + z2.x + z1.x; mv.y = yaw + z2.y + z1.y;`) but removes 4 insns while ours is still 3 short at H2 (0x27f0) + 1 near 0x2830-0x29d0 -> net worse until H2 fixed.
- H2 (unsolved): retail cEulerAngle(0,0,hgt-h2) stores x/y via `mtc1 zero f1; mtc1 zero f0; nop; swc1; swc1` after the paddub. Ours folds to `sw $zero`; `const float&` ctor gives swc1 but values come from rodata lwc1; non-volatile paddub lets stores sink below it; nested inline temps land at 0x280.
- case 8 `bigWalk = 1` retail `addiu v0,zero,1; andi v0,0xFF` (proto identical): NOT reproduced by inline uchar/bool/int returns, BoundsB/C/D out-param inlines, bool local, true/(bool)1/!0, merged if/else `ok=1` (R1-RH, all 153 or worse).
- Negatives: commuted operands are canonicalized by MW (`a != 0` vs `0 != a`, `s+i` vs `i+s`); MakeTI3 TIc/TId wrappers; SetX/LookOff operand/decl orders, cam.Set; mv-sum G2-G4/H1-H5; V4c ctor store orders; SArr struct; NZ forms.
- Remaining D4 clusters: 9d0, 1c78 (DetectFor180 order), 1cf4 + LookOff 2f74/2fa4/2fd4/320c (SetX src materialized after dst), 2268/2290 ClampG, 2350/2380 LMA const order, 2408 mv sum, 2548 (30-x operand regs swapped), 264c (mtc1 zero f30 vs lwc1), 27f0 H2, 29e0 fp/s5 swap, 2b38, 2c88 (andi), 2ce0, 32b8/32f8, 3b18 SendXf a0, 416c MakeTI3, 41ac QueueMessage a1, 4268 f[5] reg, 44e4/44f4 loop c.eq/addu order.

## PlayerInput_Update 153 -> 146 -> 141 -> 139 -> 137 (session 3, prototype-DWARF lane)
Best: work\PI_best.c (= work\L8.c) **137** differing words (incl. ~20-30 same-TU `jal func_000000` reloc noise).
- S6 146: case 6/7 `float d = 1.5707964f - ang; float v = 0.1f + 30.0f * d * dt;` (named sub-expression local changes constant reg assignment; fixes 0x2548 cluster).
- X4 141: split H2 into two depth-1 inlines H2a(a,hgt)->h2 and H2b(ang3, hgt-h2) so H2b's named `V4 t` lands at retail slot 0x6D0 and gets `mtc1 zero; swc1` stores.
  MW rule: depth-1 inline named locals are allocated at inline entry (before its temps, regardless of block scope), temps in creation order, all from a shared downward allocator (0x6xx-0x7xx); depth-2 inline locals/temps go to the low area (0x280/0x290). Named-local float-const stores = mtc1+swc1, temps fold to `sw zero`.
- Y6 139: H2b body declares `src`, `dst`, `q` in that order, paddub asm volatile, `t.z=d; t.x=0; t.y=0;`, `q = *(const long128*)&t; *dst = q;`.
- L8 137: case 5 moveVec: inline `Set3(mv, clampY + d1.x + d0.x, d0.y + d1.y, 0.0f)` (Set3 assigns x,y,z) - fixes load order of the y-sum operands.
- Negatives: bigWalk `addiu 1; andi 0xff` (proto: characterTargetZRotationWasSet = true after GetZRotationFrom*Axis) still unsolved: `++`/`+=1` (145, loads), `&local != 0` (forces local to stack 926 / sltu 142), inline bool SetH (927), true/(bool)1/!0/inline returns (earlier). Set3 with z first/y first, Set2, named mx (137-140); V4c ctor 650.
- Remaining clusters (L8): 1c78 DetectFor180 order, ClampG 2268/2290, LMA 2350/2380, 2408 mv-sum regs, 2b38 moveVec store order (retail stores x then y), 2c88 bigWalk andi, 2ce4 copy reg order, LookOff SetX 2f74/2fa4/2fdc/3214, 3b18, MakeTI3 4138/4168, 41b0.

### PI 137 -> 132 (session 3, DWARF-priority)
- S4 136: FlatSub = `VC t = SubC(a,b); V4* p=(V4*)&t; p->z=0.0f; CpN(&out,p);` (named copy -> copy-ctor into 0x6B0 slot; pointer write matches retail store).
- T5 134 / Y6 132 (= work\PI_best.c): asm paddub copy helpers allocate regs by *local declaration order* (1st a0, 2nd v1, 3rd v0) and materialize in decl order; asm operand order irrelevant. Per-site helper variants: SetX (dst,q,src) for case 11 & 1/2/3/9/10, SetX3 (src,q,dst) for case 7 and 6. Uniform change is worse.
- HF 133: mv-sum `{float tx,ty; tx=clampY+z2.x; ty=yaw+z2.y; tx+=z1.x; ty+=z1.y; mv.x=tx; mv.y=ty;}` fixes schedule exactly, but result lands in tx reg not z1-load reg (net -1). rx/ry variants HX/HY 135, HZ 142.
- Negatives: bigWalk andi (proto `characterTargetZRotationWasSet` uchar) via ++/+=1 145, &hgt!=0 926, &d0!=0 142, inline SetH 927. FlatSub a0/v0 swap unsolved (P1,S5-SB,Q5-Q8,R1-R4). LookOff q-reg at 2fdc/3214 unsolved (Z1-Z3,W1-W4).
- HandleDeath pG 22: P56_L id-first (pQ1) 27 (schedule fixes but a0/v1 swap), decl-order variants pR4-6 27, `an` hoist before PlaybackGroupId ctor pQ2 28, TailC px-chain pR1/pR3 49, pR2 24. mutate 45min from 22: no gain.
- **PI 132 -> 125** (work\PI_best.c = kY1): (1) kU1 128: in the fire block, `QueueMessage(e.c, o, 0)` instead of the `char* ep = e.c` alias -> retail sets a1 (o) before a0 (the stack address). (2) kY1 125: MakeTI3 passes `{ V4* tp = &tgt; cTargetInfo_ctor(ep + 0x30, ..., tp, pw); }` -> fixes a0/t0/f12 materialization order and the jal delay slot (mov.s f12). Both: argument-materialization order depends on whether a stack address arg is a direct `&local`/`arr` expression or a named pointer.
- Negatives: MkXf named tp/mp (127/149), e.c into MkXf/MakeTI3 (128/139), Minf/MinfR/MinX helper forms at the 32b8/32f8 min.s loads (132-135), `V4 z, d` decl swap 135, H2b src/dst/q decl perms 128-130, H2b `q=*src` 125-127.
- **PI 125 -> 111** (work\PI_best.c = kjsdq): (1) kd1 121: Do180 passes `{ V4* tp = &t; DetectForAndHandle180Turn(s, dt, tp, a, c); }` -> a0 then f12 then a1 (named-pointer arg trick again). (2) ki4 119: cases 6/7 `{ V4* dp = &d; *dp = ls; }` instead of `d = ls;` after LookOff3 -> ls-copy dst gets a1. (3) kjsdq 111: with ki4, those two sites use a SetX with decl order src,dst,q (=SetX2/LookOff2) -> dst a0, q v1.
- Negatives (all >=111): H2b `q=*src`/named src variants 125-130; case-0/11/1-10 LookOff SetX perms 114-118 (1cf4/2f74/2fa4 still a0-after-v0); Set3 operand/order variants in case 5 (2b38) 121-130; bigWalk=1 andi (2c88) via casts/inline returns: no effect (constant folded); FlatSub/IsZero4N pointer variants (2cfc) no effect; lookY clamp consts (2268/2290) 111-116; LMA decl perms (2350) 112-126; mv-sum (2408) 112-123. mutate.py on PI: metric starts at 2159 (broken for this function), stopped.
- **PI 111 -> 101** (work\PI_best.c = kj00): (1) kr1 109: case-6 lo uses a named `{ float dx = d.x; lo = FabsZ(Min0(Minf(Minf(dx, z.x), -b.f[11]))); }` -> fixes 32b8 load order (same for hi at 32f8: 137-139; MaxfR 110). (2) kzd 103: case 0/11 LookOff sites use SetXZ = *declare without init, then assign*: `long128* dst; long128 q; const long128* src; src = &o; dst = d;` -> fixes the a0/v0 order at 1cf4/2f74/2fa4 (init-in-declaration vs later assignment changes materialization order!). (3) kj00 101: same split-decl form (V4::SetZ) for `ang3.SetZ(ExpressAngle(...))` in H2b.
- Negatives (>=101): split-decl on H2b paddub block / on LookOffP sites (12 perms) 101-111; H2b with subtraction moved inside 101-106; MkXf named-ptr kw/kx 109-126; LookOff `long128 q = 0` 109+; bigWalk `int w=0; w++` forms give daddu+addiu (115-116).
- **PI 101 -> 94** (work\PI_best.c = kzb0): lookY clamp constants (2268/2290). (1) kwb0 100: Cp3 site uses `{ float lo = -1.0f; float hi = 1.0f; Cp3(lo, hi, v) }`. (2) kya3 97: Clampf site uses `{ float v = -z0.x - m; float lo = -1.0f; float hi = 1.0f; lookY = Clampf(v, lo, hi); }` (value temp FIRST, then named lo/hi -> sequential lui/mtc1 v0,v0). (3) kzb0 94: Cp3 site same shape `{ float v = m - z0.x; float lo...; float hi...; Cp3(lo, hi, v); }`. Rule: whether the -1/+1 consts share v0 or interleave v0/v1 depends on named-local vs literal and on declaration position of the value temp.
- Negatives (>=94): case-5 Set3 add/store order variants (2b38) 101-106; mv-sum named temps (2408) 97-103; LMA split-decl assignment perms 101-116, hoisting LMA consts above tgt.Cp 109/238; FlatSub/IsZero4N f4 a0/v0 (2cfc) 101-110; MkXf a0 (3b18) 101-118; H2b src-before-sub.s (27f0) 101-108; bigWalk const forms all fold (101). HandleDeath: InstNR `an` hoist fixes 13fc schedule but shifts s-regs (28); XSetQR split-decl/PairSet inline variants 24-42; TailC px-chain variants 24-53.

### PI late negatives (all >= 94; best still PI_best.c = kzb0 94)
- NOTE: in cdw dumps the RIGHT column is retail (left = ours, func_000000 relocs).
- 3b18 MkXf (retail: a0=p+0x30 before a1=id): named mp/i temps, split decl, param reorder, Mtx*/Mtx& GetUnit types, e.c+0x30 at call site -> all 94 (order unchanged) or worse (kM6 111, kN0 111).
- 2b38 case-5 Set3 (retail loads C70,C80,C84,C74 and computes x-add before y-add): operand permutations, named x/y temps, +=, direct member stores -> 94..100, never fixes.
- gc1 AddV3 decl-order/split-decl variants: 85..243 (no gain).
- 2408 mv-sum: kW6 '{ float x, y; x = clampY + z2.x; y = yaw + z2.y; x += z1.x; y += z1.y; mv.x = x; mv.y = y; }' = 95: removes the spurious F20/F24 stores and re-aligns addresses (instruction count now correct), but leaves f1/f2 swapped (CE4->f2, D00->f1 vs retail f1/f2). 15 further decl/order permutations: 95..108. Promising lead for next session: combine kW6 with something that swaps f1/f2 coloring.
- pG (cHuman_HandleDeath 22) P56_L at 1348 (retail: andi v1; addiu a0,sp,59C; sw v1,0(a0); addiu v0,1; sw s2,4(a0)): id-first via pp gives the right order but swaps a0/v1 (27); id-first without pointer (x->pairs[5].id/.a, or SP_L helper) fixes the 136c px block but folds the address to sp-relative (23). 30 variants total, best still 22. mutate.py on pGm.c: 4220 variants, best 22 (no gain).

### Session end (DWARF-rebuild priority) - best drafts in work\
- 0024B5D0 PlayerInput_Update: work\PI_best.c (=kzb0.c) 94 diff words (from 196 at session start; ~45 are reloc noise past 0x4130). Lead: work\PI_lead_kW6_95.c (95, fixes 2408 instruction count).
- 0018A950 cHuman_HandleDeath: work\pG.c 22
- 0017A640 cGameCamera_UpdateMotion: work\gc1.c 85
- 001E2180 ActorPhys_RunResponse: work\ar_best.c 970
- No new full matches; build\pending\k8 empty.
- 2408 follow-up: qa4 '{ float x, y, t; x = clampY + z2.x; y = yaw + z2.y; t = z1.x; x += t; y += z1.y; mv.x = x; mv.y = y; }' = 94 with correct instr count; y1 now in f1 like retail, but retail writes each sum into the z1 operand reg (add.s f2,f3,f2 / f0,f1,f0) while ours writes into x1/y1. 13 more permutations 94..104.
- gc1 (85) 8dc/a14 ToWorld clusters (retail a0=Pt r@2F0, a1=q@700, a2=ToWorld r@600; ours a1/a2/a0): Pt/XformPt/ToWorld split-decl + order variants all 85; dropping inline-wrapper layers (XformPt direct 155, Pt direct 138) or V r; r=PtW() (212) is much worse - inline nesting depth matters.
- Housekeeping: a case-insensitive PowerShell wildcard (gC?.c / gB*.c) also deleted old gb*.c / gc?.c intermediates, including gc1.c. I rebuilt gc1.c from gwh.c by restoring ToWorld's 'V* rp = &r;'. It re-verifies at 85. Use -cmatch for future cleanups.

### Session 13:28-21:30 (R214 list) - wrap-up; no new full matches, build\pending\k8 empty
- 0013FF40 cWeapon_FireIfReady: work\fw50.c 7 words (check_match). Remaining: p(=&ev) always gets s0 and `lw v` is scheduled first; retail has v=s0, p=s1. Tried fwF-fwI (SendOut as inline with int v param / caller local / const; param order; asm volatile "" barriers on p with r/+r; volatile load): all 7-8. mut.py on fwM.c (bodies SendOut,SlotUsed,SlotEmpty) ran about 15 min with no gain and was stopped. Next idea: change which object's address is live across the call (e.g. pass &ev via a struct member or a second temporary) so p is created before v.
- 001B0F20 cHuman_GetTransform_ForCameraTracking body (func_001B0F30): work\gt_best8.c 8 words (cdw). It needs a config symbol split at 1B0F30 before it can be delivered. Remaining: the Add2 block at 0x274 has wrong VU0 copy-block register coloring (retail dst=a2, tmp=a1, pa=a3, pr=a0, pb=v1; computes pr before pb). gA00 (no barrier, 9; file deleted, = gt_best8 without the asm{.set at} barrier after pa) has the right schedule shape but wrong colors. Tried the gJ grid (inline AddW/ScaleW/ScaleVW wrappers, best 8) and gK0-7 (taser_15-style Add2P(pr,pa,pb) with by-value args, decl/constraint order: 13-16). Next idea: address-of order in the caller expression (build the pos sum in separate statements).
- 001A1590 cHuman_Fall: work\fa0.c (nmI's draft) 19 words; fb/fc/fs0 variants gave no gain.
- 0018A950 cHuman_HandleDeath: work\pG.c 22. MW asm{} in TailA/P56 breaks scheduling; pN1 27. Three clusters remain (1348 P56 store order, 13fc an/s3 hoist, 1744 TailC a0/a1/v0).
- 001E2180 ActorPhys_RunResponse: work\ar_best.c 970. Frame 0x14E0 vs 0x14D0. The 0xD4-0x1EC scalar region has 23 slots in both but packs differently (retail 212,216,220,224q,240,256b,284,...; ours 212,216,220,224q,244,248,...). Next idea: reorder scalar locals to match the DWARF declaration order.
- 0017A640 cGameCamera_UpdateMotion: work\gc1.c 85, unchanged (VU0 copy-block coloring, same systemic issue as GetTransform).
- 001BB1D0 HandleMoveMessage: work\bb4.c 36-38, unchanged. Re-reviewed (other lanes' near misses DeactivateFx, NextFrame, CheckBulletCollisions): all heavily explored, skipped.
- NEW 001A0B30 cHuman_Land (2232 bytes, previously only raw m2c by c8fr): work\ld1.c, first DWARF/proto-guided draft, 292 diff lines. dossier\001A0B30.txt/.pdis/.r (compact retail asm) generated.
  - Structure is fully mapped: virtual GetHealthState (vtable +0x108; retail cHuman vtable 0x4DA690) returning 3/2 -> return; Land anim with 4 static cString16N (D_0049E148 x3, D_0049E160) and a 0x30A0==0 branch (0.35f, else 0.2f); two AddRequest blocks (checkpoints 0x25-0x28, blend from Find, then blend326C with instr var s6=0); else branch uses cSkaAnimCheckpoints_ctor_void/cSkaSystem_PlayAnimation(...,3,...)/dtor(-1) plus physics b9C0/b11; tail is HandleFootstepEvent(2,1), RandN(31)+70, AllocGuard cMemMan_Allocate(0,0x14,D_0049D8D0,0x2433) and nCallback_SetCallback.
  - Known fixes needed:
    - The virtual is at slot 65, not 66 (ours 0x10C): remove one dummy virtual.
    - The IsDead test must be two beq compares into a bool (not the sltiu range form). Try `s == 3 || s == 2` written as if/else assigning a flag.
    - Frame 0x2D0 vs 0x3A0 (it at 0x398; cp1 0x2D0; cp2 0x270; msgs 0x1B0/0x170/0x130/0xF0; cp3 0x90; cfd 0xE0).
    - The cString16N init loop shape differs from Fall's ctor (retail keeps the ended flag in a3 and indexes s[i] via addu). Copy the exact ctor from a matched user of cString16N statics.
- Tools: lab.py (compile+disasm any file with mw38).
