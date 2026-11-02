# A2 final report (2026-11-02)

No function reached MATCH; nothing staged.

| function | addr | kind | best | draft |
|---|---|---|---|---|
| GridProcessDataPack | 0x2EE798 (2660 B) | gcc296 (gcc296g0 identical) | 3 words, exact size, DATA (both jump tables) MATCH | build/agents/A2/gp_best3.c |
| cMemMan_Init_int_uint_uint | 0x36B3B0 | mw38 | 7 lab lines (6 real; check_match DIFF at 0xa8,0xac,0xb0,0xb8) | build/agents/A2/mi2.c (k3 b_36B3B0.c is equivalent) |
| cMemMan_Init_void | 0x36B630 | mw38 | 24 lab lines, unchanged | docs/lane_notes/k3/drafts/mv0.c; blocked by missing symbol entries (see below) |

## GridProcessDataPack (written from scratch, 253 -> 3)
- Per-case block-local variables (one GCC pseudo per declaration): 253 -> 121.
- Case 5's first scan loop through the same pointer variable as the second loop: -> 74.
- First switch written as one `case N: fwd = X; break;` per value in numeric order: 74 -> 4. GCC 2.96 cross-jumps
  identical case bodies only AFTER global register allocation, so the source layout of duplicated bodies changes the
  allocation priorities. Here it pushes `fwd` below the hoisted loop constant 2: fwd lands in t0 with caller-save
  (sq/lq, frame 0xD0) and the constant in fp.
- Case 14 loop through a pointer local: -> 3.
- Left: 3 delay slots, where retail has a non-annulled bnez/bne and we get bnezl/bnel (0x3d4, 0x4cc, 0x698). gdb on cc1
  shows the cause: retail's RTL still had a jump-around-jump at reorg time (`beqz L; <insn>; b L2`), so the slot was
  filled from before an unconditional jump and relax_delay_slots then inverted the branch. Writing `return ret;` at the
  case 5 site reproduces the non-annulled bnez, but the slot gets `move v0,zero` instead of `lw v0,0x68(sp)`.

## cMemMan_Init_int_uint_uint
- The prototype line table shows the body after the init check is one statement:
  `mMemBin[bin].Init(bin, GuardAlloc(heapSize == 0 ? DEF : heapSize, file, line), heapSize, blockSize)`. mi2.c is written
  that way (inline cMemBin::Init and GuardAlloc{AllocGuard; MemAllocate}, `#pragma inline_depth(16)`). It still gives 7.
- Root cause isolated with a micro harness (flip.py, g/rr_*.c). The chain's `sll v0 / addu v1,v0` shape (retail Init_int)
  appears when the allocation's size argument value is still used after the cMemBin_Allocate call. Using the raw
  parameter afterwards, or another variable, does not change it. `if (p && size)` in the inline fixes the whole chain
  (3 lab lines; only the extra `beqz s1` is left). No form that emits no code has worked: an empty inline taking size,
  a dead store, an unused Init parameter, volatile or plain empty asm with "r"(size), or `(void)size`.
- Insensitive (all 7): the order of Init's parameters (24 permutations), call wrappers in any parameter order, forms of
  the index, return and if/ternary, and alternative return-value flows.

## cMemMan_Init_void: blocked by missing symbol entries (Known blocked "Mem_Init" is this function)
Retail references `D_1FF0000`, `D_59A980` and `D_59C980` (spimdisasm auto names, not in symbol_addrs). With
`D_0059A980`-style names check_match reports lo-reloc name mismatches, and with `D_59A980`-style names it reports
UNDEF. The prototype shows these are the linker symbols `_stack` (0x1FF0000) and `_end` (0x59A980), plus `_end + 0x2000`
(0x59C980). They need symbol entries (a config change for the coordinator) before any Init_void draft can be accepted.

## New techniques / tools
- build/agents/A2/pri2.sh FILE.c: prints the GCC 2.96 global-alloc order (";; N regs to allocate" from -dg), each
  pseudo's priority floor_log2(refs)*refs/live_length (-dl), and the hard reg it got. It explains s-register choices
  and caller-save choices directly.
- GCC 2.96: cross-jumping runs after register allocation. Writing duplicate switch bodies separately, one per case
  value, changes register allocation while producing the same final code layout.
- GCC 2.96 reorg: a non-annulled branch whose slot insn comes from the target, where ours is annulled, usually means
  retail had a jump-around-jump with an insn between the branch and the jump at reorg time.
- build/agents/A2/glab.py: lab.py for ee-gcc 2.96 (GOPT and GEXTRA env vars). flip.py, win.py, dis.sh: MW micro harness
  and window extraction.
