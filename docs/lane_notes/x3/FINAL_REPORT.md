# Lane X3 final report (2026-11-02)

## Staged (build/pending/x3/, check_match MATCH under BRIEF_COMMON rules)
| function | addr | size | file | notes |
|---|---|---|---|---|
| func_003C0020 (cCollisionFace unit normal) | 0x3C0020 | 352 B | mw38_003C0020.c | no UNDEF, no data |
| ActorPhys_SelectEdgeRequest | 0x1E1600 | 908 B | mw38_001E1600.c | + `.rodata 0x004A0440 size 0x54` (both switch jump tables) DATA MATCH; message dtors weak + ALLOC_GUARD_DTOR (.dtors_drop) |

## Not matched (best drafts in build/agents/X3/)
| function | best | draft |
|---|---|---|
| cGameSound_PlaySound 0x1C8770 | 12 lab lines, size 0x690 vs 0x6A0 | ps_best12.c |
| func_003FD740 0x3FD740 | 33 lab lines | gl_best33.c |
| FrontEnd_SetNodeSpheres_363A80 0x363A80 | 23 lab lines at exact size with n2's rb_best.c (21 with wrong size: sn_best21.c) | docs/lane_notes/n2/drafts/rb_best.c |

FrontEnd_SetNodeSpheres_363A80 is a byte-identical clone of cSkeleton_ResetBBoxContributors (0x290610),
so one fix matches both.

## New techniques
- **GCC-style volatile asm for VU0 ops makes later copies keep retail's recomputed addresses.** An address
  (copy source, dead `xx` destination) is recomputed instead of CSE'd only when a GCC `__asm__ volatile` comes
  earlier in the same block. The first copy in func_003C0020 needed the vsub itself as a GCC volatile asm.
- **Named result local gets the next named slot.** `cVector n = (...).Normalize(); unitNormal = n;` with
  Normalize returning `cVector&` reproduced retail's 0x80 -> 0x90 -> member copy chain.
- **Unused pointer local keeps a recomputed address.** `cVector* a = this;` in an inline whose asm uses
  `"r"(this)` keeps retail's second `addiu` (removing it costs one line).
- **One function-level variable for all branch results.** PlaySound uses one `cSndFx* plSndFx` for all three
  AddToPlaylist results, as the prototype's local list shows. That took it from 88 to 32 lines.
  - Also declare at function level the locals the prototype lists there (here vagFlag/lipsFlag), and
    assign them only in the branch: 21 -> 12.
- **Inline depth moves colouring order.** Writing the cSafePtr validity test in the function body, not in a
  `Get()` inline, moved gobj's s-register behind bank's.
- **Accessor `operator[]` sets `addu` operand order.** An `operator[]` on an array wrapper gives retail's
  `addu idx,base` order where plain indexing gives `addu base,idx` (SelectEdge, PlaySound bank handles).
- **Message objects with `T* s = this`.** In the inline constructor this keeps &msg in an s-register for the
  Queue and dtor calls. A GCC volatile lq/sq copy inside makes the Queue argument be recomputed, as in retail.
- **mw38 implicit struct copies.**
  - A `char[128]` member gives retail's 2-byte, count-64 loop.
  - A 16-byte struct member is copied through FPRs (`lwc1`/`swc1`); flatten it to keep `lw`/`sw`.
  - A named union member is copied by address, but also as a float.
- **Order of `case` bodies follows source order; DATA checks cover the jump tables.** Write the `case` bodies in
  retail's code order. check_match validates the jump tables when the file defines them.
- **Lab tooling.**
  - `build/agents/X3/sbs.sh` gives a side-by-side retail/mine view.
  - `opdiff.sh` gives a register-normalised structural diff.
  - `regmap.py` gives retail -> mine s-register usage counts, which isolates colouring problems quickly.
