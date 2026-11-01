# P4L final report (2026-11-01)

## Result
- Nothing staged. Transport_StartOfFrameUpdate matches, but its asm unit (0x1E7110-0x1E8760) also holds
  DetectForAndHandleCollisionWithOtherHumans, and a stageable file must match both. DetectForAndHandle is a 10-word near miss.
- **cHumanCollisionRoutine_Transport_StartOfFrameUpdate 0x1E7110 (3628 B): check_match MATCH**
  (build/agents/P4L/best/transport_match.c, = t_match.c). It has no UNDEF symbols.
- **cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans 0x1E7F40 (2072 B): 10 words, exact size**
  (best/detectfor_best.c, = d11.c). Both functions together, in retail order:
  best/unit_1E7110_best.c (Transport MATCH, DetectFor 10 words). Once DetectFor matches, this file can be staged
  as build/pending/p4/mw38_001E7110.c.
- Not started: UpdateClimbingEdge, the wrist IK pair, HandleJumpInit, cHuman_NextFrame.

## DetectFor: what remains
Retail keeps the first `float r = 0.0f` of the min.s helper (`mtc1 zero,$f21`) and loads 22.0f into $f2 above the
first min.s. Ours drops that zero store and loads 22.0f afterwards. Every other instruction, register and stack slot
matches. The things tried are listed in NOTES.md (49 asm-flavour combinations, declaration orders, wrappers, GCC-asm forms).

## Reusable findings
1. **MW38 inline pass model (verified).** The frame is laid out as: named locals, then temps created in the main
   text (this includes the return variables of calls written in the main text, by-value temps and constructor
   temporaries), then inline-body locals grouped by expansion pass. Pass k+1 expands the calls made inside bodies
   expanded at pass k. A by-value-returning call in **argument position** is deferred one pass. Reference-returning
   calls and object expressions (`f().m()`) are not deferred. Pass-through wrappers
   (`static T M1(a,b){ return M2(a,b); }`) therefore move a local into retail's pass group. With this, all 49 stack
   slots of 0x1E7110 were placed exactly (exp/e2.c is the minimal demonstration).
2. **s-register colouring is global.** Only materialising `&ip->rot` in a local (as retail keeps it across calls)
   fixed all callee-saved colours. Member chains (`prev.Inverse().RotM(curr).TransM(curr)`) keep `this` in an s-reg.
3. **The return-copy source register is decided by where its pointer is created.**
   `V Sc(V& r,...){ __int128 t=0; V* d=&r; const V* p=&v; asm{...} return *d; }` reuses the asm pointer for the copy.
   A tagged ctor with a dead `void* xx = this` reproduces the dead addiu that some return copies leave.
4. **Struct-returning extern "C" for iterator helpers.** Writing `LIt std_list_cActiveListItemPtr_generic_iterator_1_ctor(cLLNode*)`
   inside an inline LBegin() places the iterator temps exactly like retail.
5. **min.s as `asm volatile { .set reorder; min.s r, a, b }` with (b, a) parameter order.** A noreorder asm block
   right after a uchar assignment leaves a redundant second `andi`.
6. Unexplained `nop`s inside a draft are often alignment padding of branch targets. They appear once the
   instruction count before them matches.

## Files
- NOTES.md: per-function history.
- tools/: lab.py (`-n` masks sp offsets), try.sh, smap.py (pairs stack slots through an sp-insensitive alignment;
  `-x` for any function), var.py (substitution batches with spec*.py), mkunit.py (merges both drafts into one unit file), dis.sh.
