# N4 lane notes (session 2026-11-01, big-function rebuilds from the prototype)

Target picked: gunList_GunRender 0x3836B0 (4932 B), man.cc - same CU as matched gunList_LoadGunHog and
cMan_ManRender (k3 mr_ze.c 5 words) which share the push/fog/SetModelContext prologue.
Prototype: early 0x377010 (4852 B), register-identical except the texture-batch inline (retail adds the
`n < 512 && (n == 0 || last != id)` check, same as tx_queue in matched man_8.c cMan_ManRequestTextures).
Work dir: build/agents/N4/gr/ (proto.s, proto_l.s = proto disasm with .line numbers, retail.s, g*.c drafts,
t_*.c/py variant templates). Tools: N4/tools/gd.py (aligned diff, `-m` dumps stack offsets), vt.py (slot sweeps).

## gunList_GunRender 0x3836B0
- Best draft: gr/g15.c = 7 differing words (check_match: DIFF at 0x70c,0x714,0x71c,0x754,0x760,0x76c (+1)), exact size.
- Progression (gd diff lines): 338 -> 275 -> 157 (temp layout) -> 123 -> 114 -> 110 -> 96 -> 89 -> 79 -> 74 -> 51 -> 37 -> 32 -> 26 -> 7.
- Levers that worked:
  - Stack layout = DWARF: named locals in decl order (gunPos 3F0, ambiant 3E0, l2s 3A0, rhandMat 360, lights 320,
    lights2 2E0, offset 2D0); `V ambiant = a + b` and `M lights2 = gunLocation * lights` as copy-inits (no return temp);
    lights product as `MulTo34(NxM&, a, b) { M r; const M* pa = &a; Mul44(&r, pa, &b); d = r; }` (depth-1 temp only);
    Transposed = `M a; return M(cMatrix_Transpose(cMatrix_ctor_cMatrixR(&a, &m)))` with M(const M*) calling the
    out-of-line copy ctor.
  - gunLocation identity test: inline `bool IsIdentity()` returning one 16-term `&&` chain (gives retail's 16 materialised bools).
  - Per-site copy forms (dead addius): M copy ctor `void* xx = this; RQ4(this,&o)`, operator= `const void* yy = &o; RQ4`,
    Transposed-result assigns `As(o) { const void* yy = &o; void* xx = this; RQ4 }`, global/rhandMat copies `xx` form,
    `SetT(v) { void* xx = &R(3); RQ(&R(3), &v); }` for the zero translation, Translate with `void* xx = this`,
    BoneRM operator= with `void* xx = this`.
  - Parts loop: `gunList* p = (gunList*)((j << 4) + ((theLOD << 7) + (u32)self));` then `p->gunParts[0][0].part`
    (retail folds 0x2C0 into the loads), tag as `(qwc + 0x30000000) + ((U64)(u32)part << 32)`.
  - FogF inline from k3 (`b + n / y` with b a local).
- Remaining (7 words): the ambient block 0x70c-0x77c: a0/a1 swapped twice - VAdd (retail &r=a0, D_00537D80=a1) and
  the ambiant copy-init/assign pair (retail &ambiant src of `header.ambiant =` is a1, dest of the ctor a0).
- Tried without gain: VAdd param orders, GCC asm operand permutations (6), pointer-local orders in operator+,
  V copy-ctor / operator= body variants (16 combos).
- STAGED 02:12: build/pending/n4/mw38_003836B0.c (gr/gr_final.c), MATCH on mw38/mw50/mw304, no UNDEF/DATA. (integrated by coordinator 02:29)
- Final lever for the last 7 words: VU0 add helper with parameter order `VAdd(const V* a, V* p, const V* b)` called `VAdd(this, &r, &o)`.

## XLib_ApplyContext 0x37C870 (4388 B) - parked
- Best drafts: ac/ac_a9_477.c (uniform helpers, 477 gd diff lines), ac/ac_best421.c (per-site AddV4 forms from tools/greedy.py, 421; 1115 instrs vs 1100).
- Prototype 0x370650 is instruction-identical to retail apart from li/addiu spelling and the texture-batch inline (retail adds the
  `n < 512 && (n == 0 || last != id)` check), so the source is the prototype source; DWARF locals in ac/ (see N4 notes below).
- Reconstructed: VIF helpers (Add32 `p = PTR; PTR = p + 1; *p = v`, first site with the value copied first), one-qword UNPACK
  `AddV4(addr, src)` (code + 4 words with lw/sw pairs; retail's first `lw` precedes the code store, so modelled as one GCC asm),
  variable `AddUnpack(addr, src, qwc)` with the aligned lq/sq-or-lw/sw CW asm loop (retail marks its `addi` as handwritten),
  RestoreFrameEnv = matched XLib_RestoreFrameEnv body (xlib_10.c), GS reg packet (SendGSRegs), the flush block (same as
  XLib_SetModelContext's tail but with 8-byte `*p++` stores), tex batch AddTID from man_8.c.
- Remaining: register colouring/scheduling around every AddV4 (retail keeps C statements after the copy and loads PTR after
  computing code/src at some sites but before at others), VifCopy temp colouring (retail t=v0,u=v1,n=a2,d=a0,s=a3), uv-scale
  float block order (retail CSEs 1.0f in a GPR), shadow-loop code constant 0x6C010000 CSE'd across AddV4s (GCC asm volatile
  with "memory" blocks that).
- Tried: GCC vs CW asm volatile/non-volatile, clobber variants, decl orders, operand orders, volatile PTR, direct operands.
- Next idea: find an asm form that does not block constant CSE but is a barrier for the following C statements (maybe a CW
  `asm {}` block with explicit `.set` directives), then redo the per-site greedy.

## XLib_DrawLensFlares 0x3781B0 (5388 B) - surveyed only
- Prototype 0x36C020 identical to retail except tex batch inline and cvt/trunc spelling. Contains the same flush block plus a
  dense GS sprite packet (u64/u128 math, pcpyld, many scheduled stores) - judged hard (cf. k3's XLib_Init 279 words).

## cMachine_NextFrame 0x167C40 (5572 B) - in progress
- Best draft: mn/n19.c = 10 differing words (gd), exact size, jtbl DATA .rodata 0x49C500 MATCH.
- Progression: 229 -> 94 -> 73 -> 63 -> 53 -> 39 -> 36 -> 34 -> 28 -> 24 -> 23 -> 22 -> 18 -> 14 -> 13 -> 10.
- Prototype 0x174090 differs from retail only by retail-added calls (App_BindIopRpc, FrontEnd canvas/loading screen,
  LobbyUpdate else-branch, func_002C7CB0 wait loop) - read those straight from the retail asm.
- Levers: state tests as `(unsigned char)g_GameState == N` (lbu; the 6-way test CSEs to lb+andi), SetGameState inline
  (prev = state; state = s), DivTime inline copied from matched gameFrontEnd.c, GetTicks from machine_6.c,
  cMemBin_GetTotalFreeMem returns U64 (gives retail's pcpyld/daddu), cDME_Quit/GetQuitTitle/GetQuitMessage called through
  a function-pointer cast `((int(*)())cDME_Quit)()` (lui/addiu/jalr), message temporaries as C++ classes with weak
  `.dtors_drop` dtors (decals_2.c idiom): cGameSoundMsg/cStartLevelMsg with inline ctor (keeps `this` in s1),
  pause message via a weak-dtor class temp built by `cPauseMusicMsg_ctor2(&cPauseMusicMsg(), on)` (no s1, retail slot order),
  `step = (0 > step) ? 0 : step;` for retail's `b`-over-nothing, vtable slots start at 0 (MW 8-byte header).
- More levers (n13-n19): `*(unsigned char*)&g_GameState == 16` for the last test (stops the lb CSE with the swap),
  `{ Opts* o = g_OptionsRecord; D_00533CA0 = 3; D_005383C0 = ...o->scale; }` at the memman site, switch written on the
  offset `switch ((unsigned char)g_PrevGameState - 7)` with cases 0..5 (MW emits addiu instead of addi), MaxConnects test
  `int n = D_005723F0; if (D_0048A028 - 1 == n)`, constants from inlines with two returns (`unsigned short R1()` for the
  reset id, `unsigned char B3()` for `g_IsMultiplayer ? D_005721C0 : 1`) give retail's daddiu, per-site quit-box inlines
  (site 2 decl order title,resetID,fe,msg; site 1 title,resetID,msg,fe), first viewport reset with the index read into a local.
- Remaining (10 words): first ResetViewport rect pointer a1 (retail a3: some vreg holds a1 across the block in retail),
  first quit box fe/msg s4/s5 swapped. Immune so far to decl orders, inits at use, copies, member wrappers, block decls.
- 03:00-03:45 session: viewport block is really an XLib member inline over g_Video fields (D_00538C60 = g_Video+0xA70 curVp,
  D_00539170 = g_Video+0xF80 full rect); `void ResetVpB() { const tRECT& r = full; Viewport* v = &vp[curVp]; ... }` gives the
  prototype colouring (index a1, rect a2) = retail site 2, but retail site 1 is shifted to a2/a3 (an a1 neighbour that no
  visible instruction uses). Drafts mn/v_B.c (13 lines) and mn/n19.c (10 lines) are equivalent otherwise.
- Quit site 1 colouring has two attractors: (fe s1, resetID s2, title s3) or (resetID s1, title s2, fe s4, msg s5); retail
  wants msg s4/fe s5. Immune to: 24 inline-param orders (MW evaluates call args first for inlines -> fe load after the call),
  dead initialisers (`char* msg = 0`), copy variables, helper inlines for fe/msg, time/fstep/gameSound/gui decl placement.
  A direct `cGameFrontEnd_PushMessageBox(D_004FFC04, ...)` loads fe after the calls (s0 pattern) - retail had fe in a variable.
- Region-restricted mutation search (tools/mut_gd.py, gd-scored, /*MUTLO*/../*MUTHI*/ markers) on mn/m_base.c.
- 03:15-03:45: MW allocation facts learned (small standalone experiments, /tmp only):
  * a named local is ONE vreg for all its uses (no web splitting): reusing a variable (e.g. gameSound for msg) moves registers.
  * in small functions the colouring order is reverse declaration order (last-declared local gets the lowest s-reg);
    temporaries are coloured before named locals.
  * in NextFrame the quit-site-1 colouring is NOT local: deleting unrelated state blocks (state 5, 6, 15/19 incl. quit
    site 2, state 20 with eolFlags) flips it, so the order depends on whole-function vreg numbering/priority.
  * `register` keyword has no effect; dead initialisers and copies are dropped before allocation.
  * tools/qregs.sh prints quit-site-1/viewport-1 registers of a draft; tools/rdecl.py random decl placement (3000 tries,
    best 13 on the B family); whole-function mutate (tools/mut_gd.py, gd-scored) on n19 running.
- XLib_ApplyContext: plain C AddV4 (`p[0]=code; *(W4*)(p+1)=*src`) copies word-by-word with folded offsets (545 lines),
  so retail's lw/sw-pair copy through a materialised src pointer is still asm-modelled.
- XLib_DrawLensFlares: proto (lf/proto_l.s with .line) is identical to retail at the start (same calls, same frame 0x3A0);
  DWARF locals list in P1 data. ~1340 proto lines with many cMatrix/VU0 inlines and a 64-bit GS packet; not drafted.
