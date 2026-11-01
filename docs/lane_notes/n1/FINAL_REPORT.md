# N1 final report (2026-11-01, lane N1: near misses in lib / netcode / XLib / cMan)

Result: no new matches staged. Nothing was put in build/pending/n1 and nothing was added to STATUS.md.
Per-function details are in build/agents/N1/NOTES.md and the scratch files are in build/agents/N1/w3/.

| target | words (start -> best) | outcome |
|---|---|---|
| _sceMcFatCreateFile 2B9108 | 1 -> 1 | root cause found in cc1 reorg (see below); no C lever found |
| RemoteClientDisconnectEvent 2DEF70 | 4 -> 4 | root cause found in cc1 reorg; no C lever found |
| NetIRequestCreateRemoteNamedObject 2E2250 | 4 | not attempted (draft not in docs/lane_notes; same reorg family) |
| cMan_ManRender 3870C0 | 5 (2 real) -> same | 12 address-form variants, no gain |
| cMan_GetGunBarrelMatrix 385240 | 7 -> 7 | proto lines/locals used; about 300 variants, plateau at 7 |
| XLib_DisplayLastFrame 37B5C0 | 7 -> 7 | proto line table shows a single-line DISPLAY2 statement; inline-argument forms are worse (24+) |
| NetIInitialize 2DF290 | 8 | not attempted (no draft) |
| cGenerator_NetSpawn 21E0C0 | 9 | not attempted (k2 exhausted it) |
| cMemMan_Init_int_uint_uint 36B3B0 | 9 -> 9 | finding about the mirrored index block, no gain |
| cMemMan_Init_void 36B630 | 24 -> 24 | the store order is set by the scheduler; 20 statement orders are identical |

## Main findings
1. The gcc296g0 near misses (mc, def, and by k2's description also E2250) are reorg liveness problems, not C ordering
   problems. They were traced with gdb on the unstripped ee-gcc 2.96 cc1, which has debug info:
   - mc: `mark_target_live_regs(fallthrough)` finds a1 live because `find_dead_or_set_registers` meets the
     `(use (insn a1=sp+0x490))` that update_block emitted. That USE appeared when fill_simple(1) moved the a1 setup into the
     slot of `jal _sceMcFatGetFreeClust`. So the target insn goes into an annulled slot (`beqzl`).
   - def: a0 is live at .L2DF104 for two reasons. (a) The linear scan passes the callback `jalr`, whose slot sets a0=sp after
     the call clobber, and the scan ignores the REG_DEAD notes of CALL_INSNs. (b) The USE of the a0 setup moved into the
     `jal RemoteClientDisconnects` slot. The fdsr scan also stops at the first call (can_throw).
   - In the gdb experiment that fills all call slots in reorg pass 2 instead of pass 1, def gets exactly the two retail beq
     slots but 3 other places change, and mc changes the other way. So retail is neither the stock fill order nor "all calls
     late". Something in the original RTL at dbr time, which we cannot see, differs. No C shape that reproduces it was found.
2. cMemMan: the pool*0x818 index block is mirrored. Retail Init_int has the register pattern that our Init_void draft
   produces, and retail Init_void has the pattern that our Init_int draft produces. Swapping the inline forms between the two
   drafts does not flip either one.
3. Prototype facts (names and types only):
   - GetGunBarrelMatrix has locals gunMat_WorldSpace/x/y/z at 0x50/0x40/0x30/0x20, and each row assignment is one statement.
   - The proto has out-of-line SetX/Y/ZAxis that return cMatrix&.
   - In DisplayLastFrame, everything from dh to the DISPLAY2 store sits on one source line, and the only DWARF locals are
     dispBuffAddr, isInterlace, isPal, isPscan, kPScanOffX, xpos, ypos and kMagH.

## Next ideas
- mc/def/E2250: find a source construct that leaves a jump or label in the RTL at reorg pass 1 which relax_delay_slots then
  removes. A label before the check helps E2250 (k2's address-taken label diagnostic), but for mc/def the blocker is call-slot
  USE liveness, which a label does not clear. Before trying C forms, check them in gdb with w3/reorgtrace.py and fdsr.py.
- ManRender: the sll4/lq tie is not decided by the IR order of the address computation (moving c*7 earlier keeps sll4 first).
  Next, perturb the length of the MulP3 asm dependency chain.

## Tools left in build/agents/N1/w3/
ck.sh, dd.sh, score.sh, reorgtrace.py, scan.py, stepf.py, fdsr.py, mtlr2.py, skip1.gdb, plus ../tools/lines.py
(DWARF .line dump of the early prototype). NOTES.md has the usage.
