# W2 notes (2026-11-02)

## XLib_ApplyContext 0x37C870 (4388 B, 1097 instrs)
- Best draft: s2 base copied to ac0.c = 521 lab lines (plain C, acceptable). n4 asm-AddV4 draft n4_421.c = 519 lab (1115 instrs).
- Tooling: lab.py (copy of P4L lab with -o dump to scratch ret.txt/mine.txt), hunks.py (hunk list), m/cc.sh micro harness.
- Finding: the AddV4 copy shape (`lw a,0(q); sw c,0(p); lw c',4(q); sw a,4(p); sw c',8(p); lw; lw; sw; sw`, two registers,
  pointer q materialised with addiu) occurs NOWHERE else in retail (whole-.text scan: 16 sites, all in ApplyContext).
- Micro tests (m/t1..t11), all MW38 -O4,p:
  * struct copies of every 4-byte-element kind (u32/int/long/void* arrays, nested 2-element arrays) use FPR lwc1/swc1
    blocks (groups of up to 4, or per sub-array); u64/packed u64/double/__int128 give ld+sdr/sdl or lq/sq; char/short
    arrays give a looped lb/lh pair copy. No struct copy gives GPR pairs.
  * explicit C pairs (`a=q[0]; b=q[1]; p[1]=a; p[2]=b; ...`) give the right pair shape but always fold offsets
    (4336(a0)) and keep the loads after the code store; loops over 2 iterations are unrolled and folded too.
  * a non-volatile CW `asm {}` copy is optimised like C (offsets folded too).
  * a CW `asm volatile {}` copy keeps q materialised (`addiu a3,a0,4336`) and emits the text as written, reusing c as
    the second temp when written `lw c, 4(q)`: exactly retail's shape.
  => retail's AddV4 is a volatile asm block in the original. Not acceptable under BRIEF rules without owner approval.
- Also: if-then blocks end with a `nop` (less-optimised mode), matching the prototype line table (nop on the `}` line).
- a1.c (ac0 + CW asm volatile AddV4): 612 lab, 1115 instrs; the asm changes the uv-scale (0x2000) block a lot.
- Decision: parked; moved to XLib_Init (higher chance of a stageable match).

### ApplyContext progress with a volatile-asm AddV4 (needs owner approval; 12:10)
- KEY: `.set noreorder` / `.set reorder` inside the CW `asm volatile {}` copy keeps MW from scheduling C instructions
  into the block (without it, C loads/ors are scheduled between the asm's lines; GCC `__asm__ volatile` text is
  scheduled the same way). a4.c: 521 -> 317, instruction count 1095.
- gen.py/search.py: per-site greedy over 24 AddV4 forms (order of `c`/`q`/`p` statements x position of `u32 a;`)
  -> a5.c 147. Winners: q,c,p order with `a` declared second (form 9) or first (8).
- VifCopy temps declared `u32 u, t;` -> 129; AddUnpack `qwc *= 4` (named lqwc coalesces into t0 like the prototype
  DWARF says) -> exact 1097 instrs; VifCopy parameter order (n, d, s) -> 100 (au.py grid); code word via Add32V
  (value copied first) -> 79; `const void* s = src;` first in AddUnpack -> 74 (a9.c).
- V::operator= copy temp `"=&r"` (early clobber) -> 70; joint form search sites 6/7 -> 52 (b2.c).
- clipPrimTag copy as non-volatile CW `asm { lq t, 0(s); sq t, 0(d) }` with `void* d = &clipPrimTag; const void* s =
  &D_00493330;` -> 43: MW then CSEs d with the AddV4's q (a1), like retail. (Native `__int128` assignment folds
  addresses: 61; GCC asm RQ keeps d separate: 52.)
- AddUnpack's code word through one more inline level (`Add32V2(v) { Add32V(v); }`) -> 36 (b5.c = ac_best36.c).
  Depth 3 or copying v again: no further change.
- BEST: ac_best36.c = 36 lab lines, 1097/1097 instrs, check_match ~35 words (DIFF at 0x184.. +29).
  6 of the 36 lab lines are masking artefacts (`sw v1,R(v0)` after a `lui v0`, `ld t3,4096(at)`).
  Real remaining:
  * AddUnpack site 1 (0x37C9F0..): retail P-reload temp a1 / code a0; ours a0 / a1 (4 lines).
  * uv-scale block (flags & 0x2000, retail 0x37CEC0..0x37CF40): retail schedules the gbScaleX chain first, then vScl,
    then uScl (DWARF: uScl $f4, vScl $f2); ours starts with uScl's buffWidth load (uScl in f5). Immune to: uScl/vScl
    statement order, declaration placement (top/end/in-block/initialised), (int) casts, int->float implicit, split
    convert/divide, all single statement moves of the 10 uv statements (uvp.py hill climb), plain-C AddV4 at that site.
- Tried without effect: AddUnpack Add32 forms (6), VifCopy wrapper (61), lqwc assignment after the AddV4 (63),
  AddV4 wrapper at site 1.
- STATUS: not stageable under BRIEF rules (AddV4 = CW `asm volatile` lw/sw copy with `.set noreorder`). Evidence
  that the original is asm: the shape exists nowhere else in retail; no C or struct copy reproduces it (micro tests above).

## XLib_Init 0x37E780 - reviewed only
- t3 xi_best52.c re-measured: 52 lab lines, 954/954. Prototype window (pixenv/fog/dimx, proto lines 355-395) is
  instruction-identical to retail; line 387 is `alphaReg = XLib::alphaBlendModes[...]`, all fog code is ONE source line
  (391: an inline call), dthe/frameEnvChanged share line 395 (an inline). Not worked further (time).
