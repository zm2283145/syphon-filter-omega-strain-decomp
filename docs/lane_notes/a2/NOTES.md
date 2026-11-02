# A2 NOTES (2026-11-02)

## cMemMan_Init_int_uint_uint 0x36B3B0 (0x274) - 7 lab lines (6 real; 1 lab artefact lbu 15512)
- Cleaner equivalent draft mi2.c: proto line table shows Init(int,uint,uint) body is ONE statement (line 1429 spanning 1430):
  `D_00533CB0[bin].Init(bin, GuardAlloc(heapSize == 0 ? 0xA00000 : heapSize, file, 0x598), heapSize, blockSize);`
  with inline cMemBin::Init and GuardAlloc { AllocGuard g; return MemAllocate(0,...); } (needs #pragma inline_depth(16)). Same 7.
- ROOT CAUSE FOUND (micro harness flip.py/h*.c): the chain shape depends on whether the inline's `size` is live AFTER the
  cMemBin_Allocate call. Any post-call use of size (e.g. `if (p && size)` tag, `return size ? p : 0`, `if (n == 0) memFull = 0`)
  gives retail's `sll v0; addu v1,v0; lui a2; ...; lui v0` exactly. In the real draft `if (p && size) tag` -> 3 lab lines
  (chain fixed; only the extra `beqz s1` remains). No code-free use found yet (empty inline Track(p,size), size=size,
  dead local, `(void)size`, GCC asm "" "r"(size), dead store all leave it unchanged = liveness removed before RA).
- Insensitive (all 7): Init param order (24 perms), call wrappers AR(...) in any param order, b/f/size locals, bins local,
  p init, idx forms, return-structure variants except those changing CFG.
- Pre-schedule (#pragma schedule off) chain is identical in all variants; the difference is in RA/scheduling.

## GridProcessDataPack 0x2EE798 (2660 B, gcc296; gcc296g0 identical) - 3 words, gp_best3.c (exact size, DATA jtbl MATCH)
- Written from scratch (no prototype). Structs from medius_2ED940/2EE4C8 siblings; case 7 is GridSetChannelInfo's body inlined.
- 253 -> 121: per-case block-local variables (GCC 2.96 gives each declaration its own pseudo; shared function-scope
  p/g/e changed every case's s-register choice).
- 121 -> 74: case 5's first scan loop through the same pointer variable as the second loop (`ee = &net->ents[i]`).
- 74 -> 4: FIRST SWITCH WRITTEN AS ONE `case N: fwd = X; break;` PER VALUE IN NUMERIC ORDER. GCC cross-jumps the identical
  bodies only after register allocation, so at global-alloc time fwd has many refs/long life and drops below the loop's
  hoisted constant 2 -> fwd gets t0 with caller-save (sq/lq around the call, frame 0xD0), constant 2 gets fp.
  Grouped labels (`case 0: case 1: ...`) give fwd a callee-saved register and the frame is 16 B short.
- Tooling: build/agents/A2/pri2.sh FILE.c prints GCC 2.96 global-alloc order (";; N regs to allocate" from -dg),
  priority floor_log2(refs)*refs/live_length from -dl, and the hard reg each pseudo got. glab.py = lab.py for ee-gcc 2.96.
- 4 -> 3: case 14 loop through a pointer local `c = &net->ents[i]` (fixes addu operand order).
- Left (3 words, all reorg delay-slot annulment): retail uses non-likely bnez/bne with the slot insn taken from the
  branch target where we get bnezl/bnel: case 5 `x58 != 0` (0x3d4), case 8 `x58` check (0x4cc), case 14 loop bne (0x698).
  In all three the fall-through starts with a jal. Tried: callee prototypes (void/int/K&R), if/else/goto/return forms,
  case 14 loop forms (while, nested, found-code after loop): no change or worse.
- Reorg mechanism (gdb on cc1 with docs/lane_notes/n1/tools/reorgtrace.py + mtlr2.py): ours fills each of the 3 slots in
  pass-1 fill_eager from the target and must annul because mark_target_live_regs on the fall-through scans from a far
  block head (b=33 / b=84) and the REG_DEAD regs stay "pending" (no CODE_LABEL before the jal). Retail's pattern is what
  reorg makes from a jump-around-jump that survives to reorg: `beqz L_x; <insn>; b L_y; BARRIER; L_x:` -> the b's slot
  takes <insn> from before, relax_delay_slots inverts to a non-annulled `bnez L_y [insn]`.
  PROOF: `if (net->x58 != 0) return ret;` at the case 5 site gives a non-annulled bnez, but with `move v0,zero` in the
  slot (GCC knows ret == 0 there); retail has `lw v0,0x68(sp)`. So retail had a ret load between the branch and the jump
  at reorg time. No C form found yet that keeps ret unknown there (volatile ret: 39). Same family as n1's
  _sceMcFatCreateFile / RemoteClientDisconnectEvent.

## cMemMan_Init_void 0x36B630 - 24 lab lines (k3 mv0.c unchanged); BLOCKED for staging by symbols
- Retail references D_1FF0000 / D_59A980 / D_59C980 (spimdisasm auto names, no entries in config/symbol_addrs.txt).
  check_match: with D_0059A980-style names -> "(lo D_0059A980)" reloc mismatches; with D_59A980-style names -> UNDEF.
  Proto (SCUS_973.97) shows these are the linker symbols `_stack` (0x1FF0000) and `_end` (0x59A980 in retail), the
  second one being `_end + 0x2000` (proto: _end+0x5A80 / _end+0x7A80, retail 0x59A980 / 0x59C980). Needs symbol entries
  (config edit, coordinator) before any Init_void draft can pass the acceptance rules.
- Chain-shape mirror with Init_int confirmed (the T2/T6 harness in flip.py); alloc-body variants flip TC only together
  with CFG changes (`p = size == 0 ? 0 : Alloc(...)` gives v1-form but a different lui order, 36).
