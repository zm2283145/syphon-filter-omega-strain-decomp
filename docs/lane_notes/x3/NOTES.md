# X3 notes (kN format)

## func_003C0020 (0x3C0020, 352 B) -- MATCH
- best draft: build/agents/X3/func_003C0020.c (check_match MATCH)
- cCollisionFace unit normal: n = normalize(((v1-v0)^(v2-v0)) * sign(face.x)); no prototype counterpart.
- keys: VU0 ops one inline level deeper with GCC `__asm__ volatile` (not MW asm) -> MW drops address CSE after them
  (sub#1 copy needed a volatile asm before it in the block); helper param order from grid; operator* as a
  *member* (`(e1^e2) * s`), MulV with `u_long128 t = 0` (paddub) + "+r"(t); Normalize returns cVector& with GCC asm
  on "r"(this) plus an unused `cVector* a = this` (needed); named local `cVector n = (...).Normalize(); unitNormal = n;`
  (n takes the third named slot 0x90); plain copy ctor `"=r"(t) : "r"(this), "r"(&source)` for the n copy order.

## func_003FD740 (0x3FD740, 768 B) -- 33 lab lines (best build/agents/X3/gl14a.c / gl13b.c)
- UTF-8 -> local charset converter on an SSO std::string (globalization). Decoder as inline
  `Utf8Decode(unsigned* ch, int* len, const uchar* p)` with `*ch = 0` first (the delay-slot `move v0,zero`),
  out-params, error paths `return;`; `if (n <= 0) { if (n == 0) break; pos -= n; } else {...}`; ternary
  `page ? page[w & 0xFF] : 0xFF`; `(unsigned char)(c + 0x20)`; string zero-init through
  `String* o = (String*)((char*)&out + 0)`; decl orders found by grids (main: ch,out,pos,p,n,len; decoder: n,i,v,q,c).
- left: retail recomputes `p+pos` (addu s2,s3) for the continuation-loop pointer (no global CSE), first
  ascii branch delay slot unfilled, `andi 0xff` re-truncation of the continuation byte, i/v and c register swap.
- tried: dead MW trigger (unrotates loops, worse), dead GCC asm (no effect), base/at params, base[at+i], p[i].

## ActorPhys_SelectEdgeRequest (0x1E1600, 908 B) -- MATCH (+ .rodata 0x4A0440 jtbls MATCH)
- best draft: build/agents/X3/ActorPhys_SelectEdgeRequest.c
- retail successor of proto TriggerResponseIfLedgeFound (0x1D6D80 early proto): best-priority (float +0x74,
  init -FLT_MAX) instead of first-found; two switches (jtbls). Keys: dead MW trigger (less-optimised mode),
  message ctors with `T* s = this` (keeps &msg in an s-reg), GCC volatile lq/sq for the ActorAction dest copy
  (makes the Queue arg recompute `addiu a0,sp,0xC0`), cArray9::operator[] accessor (gives `addu idx,base`
  order), cFoundLedgeMsg(const cBitArray&) reading chunk before the base ctor, CharAction locals
  `cGOBJ** o = results.owner; int sub = ...;`, climb-failed flag set after the message block, decl order
  float,best,report,climbFailed,foundTypes,i (grid). Message dtors weak + ALLOC_GUARD_DTOR (.dtors_drop).

## cGameSound_PlaySound (0x1C8770, 1688 B) -- 12 lab lines, size 0x690 vs 0x6A0 (best build/agents/X3/ps_best12.c)
- built from retail + early proto PlaySound (0x1BED90). Keys: one function-level `cSndFx* plSndFx` for all three
  AddToPlaylist results (as in the proto local list; 88 -> 32 lines: MW colours one variable for all webs),
  implicit cFileMan copy (char[128] gives retail's 2-byte loop; stream handle flattened to 3 ints + byte, a
  cFSHandle struct member copies as a float block), cSndFx retail layout mPriority 0x180 / mPlayListIndex 0x184,
  init order bank, sndID, gobj, vol, pan; hog test `if (!(hogA && (!hogA || GBI != -1))) { if (hogB) {...} } else flag=1`;
  cBankArr::operator[] for `idx + base` order; messages as derived structs with weak .dtors_drop dtors.
- left: gobj/bank s4/s3 swapped (independent of decl/init order), priority loop a1/a2 swap, vagFile.mHogFile
  address CSE'd in retail's implicit copy (`addiu s3,sp,0x308; lw 0(s3)`; ours folds `lw 0x308(sp)`; a hog
  pointer local is CSE'd only with later uses), last-path schedule of `lui t1`.
- tried: wrapper inline with value params (worse), Get forms, union/wrapper/by-value hog types, explicit operator=.
- UPDATE 12 lines (ps_best12.c): (a) cSafePtr validity written in the function body instead of the Get() inline
  (`{ unsigned char v = !sndFx.mRefGobj.obj || Eq(...); gobj = v ? sndFx.mRefGobj.obj : 0; }`) moves gobj's
  colour from first to after bank (32 -> 21); (b) vagFlag/lipsFlag declared at function top as in the proto
  local list (`unsigned char vagFlag; unsigned char lipsFlag; int bank; ...`) and only assigned 0 in the VAG
  block (21 -> 12). Remaining 12: priority-loop a1/a2 (SR pointer vs &fx) swap, and the vagFile.mHogFile
  address (retail `addiu s3,sp,0x308` shared by the implicit copy and the two later uses; ours folds the copy's
  read) which also costs the two alignment nops -> size 0x690 vs 0x6A0. Micro tests (micro/m1*.c, m2*.c): no
  form found where mw38 shares an implicit struct copy's field address with later explicit uses (anonymous /
  named union, reference args, pointer locals, user operator=, trigger). check_match word counts are useless
  until the size matches, so mutate.py was not effective here.

## FrontEnd_SetNodeSpheres_363A80 (0x363A80, 588 B) -- clone of cSkeleton_ResetBBoxContributors (0x290610)
- byte-identical code apart from branch targets (same callees, same D_004E1D88/D_004E1D90 guard), so one
  solution matches both. n2's rb_best.c (docs/lane_notes/n2/drafts) gives 23 lab lines at exact size here.
- tried: dead trigger (no effect), non-volatile MW / C copies (21 lines but size -0x14, offsets folded), split
  volatile lq / plain sq, reading bone data before the copy, `(T*)((char*)&x + 0)` pointers, empty volatile
  asm at loop-body start. Finding: the unfolded-address pattern only applies to code *after* an
  instruction-emitting volatile asm in the block, and such an asm is a scheduling barrier for loads, so
  retail's "data load early, lq late, all unfolded" order is not reachable with any form tried.

## func_003FD740 -- no further gain (grid of decoder local/param orders on gl14a: all >= 33; char-param
  helpers, manual inlining of the decoder with gotos: worse).
