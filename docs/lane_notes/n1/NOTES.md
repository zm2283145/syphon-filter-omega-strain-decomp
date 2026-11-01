# N1 lane notes (2026-11-01, near-miss targets from k1/k2/k3)

Work dir: build/agents/N1/w3/ (ck.sh = check_match wrapper, dd.sh = instruction diff via d2.py).

| addr | name | kind | best draft | words | state |
|---|---|---|---|---|---|

## _sceMcFatCreateFile 002B9108 (gcc296g0) - 1 word, w3/mc_vO.c (= k1 draft)
- Diff: retail `beqz s6` + slot `addiu a1,sp,0x480` (from target, not annulled); ours `beqzl`.
- Root cause found with gdb on cc1 (w3/mc/g1-g3.gdb; cc1 has debug info, use `break mark_target_live_regs if target->fld[0].rtint == 287`):
  the scan up to the fallthrough gives a1 dead, but find_dead_or_set_registers then meets `(use (insn 289 a1=sp+0x490))`, emitted by
  update_block when fill_simple_delay_slots(1) moved insn 289 into the `jal _sceMcFatGetFreeClust` slot, and "registers set by the
  underlying insn are live" -> a1 live at fallthrough -> annul. For retail the USE must be absent/before the fallthrough insn, or 287's
  liveness was cached before the call slot was filled. Skipping all fill_simple USEs (gdb `return` in update_block) gives a third,
  different output (fallthrough `move a0,s7` in the slot), so it is not just "no USE".
- Tried (no gain): `int *pr=&ret` arg (6), `int u=unit` copy (1), cast call (1).
- Dropped after ~45 min. Next idea: get sched2 to put the a1 setter BEFORE `a0=s7` while a0=s7 stays out of the call slot.

## RemoteClientDisconnectEvent 002DEF70 (gcc296g0) - 4 words (5 incl. pad), w3/def_k1.c (= k2 draft)
- Diff: beq slots at 0xd4/0x134 (target .L2DF104 `move a1,s2`): retail takes `move a0,s1` from fallthrough, ours `move a1,s3/s2`.
- gdb (w3/scan.py, w3/stepf.py, T=448): mark_target_live_regs(448) says a0 live. Cause: the linear scan from bb 13 passes the
  callback `jalr v0` whose delay slot (filled in pass-1 fill_simple(1)) sets a0=sp AFTER the call clobber; CALL_INSN REG_DEAD notes
  are ignored in the scan, so a0 stays live through label .L2DF104; find_dead_or_set_registers stops at the next call (can_throw).
- So in retail the jalr slot must have been empty (a0=sp before the call, cleared by the call) when the beqs were filled, i.e. the
  jalr slot was filled later (pass 2), e.g. a CODE_LABEL/jump between `a0=&m` and the jalr in pass 1 that relax_delay_slots removed.
  No C shape for that found yet. Same family of problem as _sceMcFatCreateFile (USE/liveness at reorg time).
- Flags (-g, -O3, etc.) give no change (irrelevant anyway).
- Idea not yet tested: retail's beq slots look like a pass-1 `bne L_body; j L104; L_body:` (jump-around-jump) that
  relax_delay_slots inverted, but that still needs a0 dead at L104, so the jalr-slot timing is the real blocker.

## cMemMan_Init_int_uint_uint 0036B3B0 (mw38) - 9 words, w3/b_36B3B0.c (= k3)
## cMemMan_Init_void 0036B630 (mw38) - 24 words, w3/mv0.c (= k3)
- Observation: the pool*0x818 index block is mirrored between the two drafts: retail Init_int = `sll v0; addu v1,v0; lui a2; ...`
  and our Init_void draft produces exactly that; retail Init_void = `sll v1; addu v1,v1; lui v0; ...` and our Init_int draft
  produces that (as does the matched out-of-line cMemMan_Allocate 0x36B180). Swapping the inline forms between drafts (param-pool
  ternary vs local pool, int/uint size, pool locals, inline_depth pragma) does not flip either side (w3/mm/i_*.c 9-16, v_*.c 24).
- Init_void head: retail keeps the mHandle(0x814)=0 store after mHeapStartAddr; ours hoists it next to mUsed(0x810)=0. All 20
  placements of the mUsed/mHandle statements and a shared Init(handle,start,size,used) inline give identical code (scheduler-decided).
- More def findings: the USE(446) emitted when fill_simple(1) moves `a0=s1` into the slot of `jal RemoteClientDisconnects`
  also makes a0 live at L104 (find_dead_or_set_registers: "registers set by the underlying insn are live"), so BOTH the jalr slot
  and the target call's own slot must be unfilled (or USE-free) when the beqs are filled. gdb experiment w3/skip1.gdb (skip the
  pass-1 fill_simple(1), i.e. fill all call slots in pass 2) fixes exactly the two retail spots in def (a0 in both beq slots) but
  changes 3 other places (beql at 0x7c etc.), and in mc it puts `move a0,s7` in the beq slot -> retail is neither stock order nor
  "all calls late". Duplicated-tail C variants (w3/def/d1-d3.c: no cross-jumping in 2.96 -O2) 34-68. Dropped.

## cMan_GetGunBarrelMatrix 00385240 (mw38) - 7 words, w3/t_g5.c (= k3)
- Proto 0x378B40 (hash-exact): locals gunMat_WorldSpace 0x50, x 0x40, y 0x30, z 0x20; line table (w3/../tools/lines.py) shows one
  statement per row: 5710-5712 x/y/z = rows 0-2, 5714 row0<-z, 5715 row1<-x, 5716 row2<-y, 5718 return. Proto out-of-line
  SetXAxis/SetYAxis/SetZAxis (0x131A40/0x131A10/0x1319E0) return cMatrix&, body loads w,z,y,x (f1,f2,f3,f0) = retail row2 regs.
- Tried: 24 SetZAxis load orders (best yzwx 7; wzyx 9 gets the retail load order but z-row/y-row colours swapped), 24x5 joint
  row0-decl x SetZAxis orders (7), 24x2 row0 store orders (all 7), 48 combinations of proto-style SetXA/SetYA/SetZA/SetAx/Row()=
  forms (13-39). Residual = FP colouring of z.w/z.y and y.w/y.y (f3/f5/f1 rotation). Dropped.

## XLib_DisplayLastFrame 0037B5C0 (mw38) - 7 words, w3/b_37B5C0.c (= k3)
- Proto 0x36F3A0 hash-exact; line table: everything from dh/dw/dx/dy to the DISPLAY2 store is ONE source line (1955), i.e. a
  macro or a single statement with all expressions as arguments; DWARF locals are only dispBuffAddr, isInterlace, isPal, isPscan,
  kPScanOffX, xpos, ypos, kMagH (no dx/dw locals). But every inline-argument / partial-locals mix (40 variants, w3/xl/) scores
  24-108, worse than the k3 all-locals draft (7). Residual: dx/dw colour t1/t0 (retail t0/t1) -> `li 656` hoists above the mult.

## cMan_ManRender 003870C0 (mw38) - 5 (2 real) words, w3/mr_ze.c (= k3)
- Residual `sll a1,a1,4` (&q->e[c]) before As's first `lq s0,0(t1)`. Tried: PB* pe=&q->e[c] before/after As (83/87),
  `q->e + c` (27), named M* dm (19), split `int c7 = c*7` + `(char*)q->e + c7*16` at 3 positions x 4 forms (12 before As;
  5 after As/SetQ0 = unchanged), `M tq` temp for As (53), &pal direct (42). Note: c7 before As moves sll3/subu earlier and the
  sll4 still precedes lq s0 -> the tie is not decided by IR order of the address computation.

## Not attempted (time): NetIRequestCreateRemoteNamedObject 2E2250 and NetIInitialize 2DF290 (k2 drafts are not in
docs/lane_notes; they would have to be rebuilt from asm first; E2250 is the same reorg-liveness family as def/mc),
cGenerator_NetSpawn 21E0C0 (k2 exhausted ~150 variants of the a3/t5 key/src colouring).
- GunBarrel extra (late): row0/row1/row2 setter inline-depth grid (SetXR/SX1-3 x SetRow/SR1-2 x SetZAxis/SZ1-3, 48 variants)
  and row0 Set/SetR/Set4/Set4R forms: best stays 7 (w3/gb/d_*.c, f_*.c).

## Tools (w3/)
- ck.sh FILE KIND: check_match with the CW dirs. dd.sh FILE KIND FUNC [ctx]: instruction diff (d2.py). score.sh: diff count only.
- reorgtrace.py (WATCH=uids): gdb-python trace of reorg (fill_simple/eager/relax, mark_target_live_regs results, update_block).
- scan.py / stepf.py / fdsr.py (T=uid): trace the current_live_regs scan, step find_dead_or_set_registers, for one target uid.
- skip1.gdb: skip pass-1 fill_simple_delay_slots(1) (all call slots filled in pass 2) - diagnostic only.
- ../tools/lines.py LO HI: DWARF1 .line dump of the early prototype (k2's lines.py with the Linux path).
Usage: cc1 = .tools/eegcc/ee-gcc2.96/lib/gcc-lib/ee/2.96-ee-001003-1/cc1 (has debug info); preprocess with
`ee-gcc -O2 -w -G0 -E x.c -o x.i`, then `gdb -batch -x tool --args $CC1 x.i -quiet -O2 -G0 -w -o x.s`; insn uids from `-dd` dump.
