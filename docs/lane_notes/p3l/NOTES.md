# P3L lane notes (session 2026-11-01): NPC / path / collision / camera

Tools: tools/pcmp.py (retail ROM vs prototype normalised diff, for ranking), tools/pl.sh ADDR SIZE (prototype disasm
annotated with .line numbers), tools/gd.py (N4's aligned diff, `-A` prints all lines), tools/var.py (replacement-variant
batches scored by gd). Dossiers: dossier/ (tools/proto/dossier.py).

## Ranking (proto vs retail, pcmp normalised diff lines; most are relocation spellings)
- GridProcessDataPack 2 (but ee-gcc2.96 medius lib, 4 earlier lanes 342-647 -> skip unless time)
- cNPC_HandleMessage 53 (register-identical, only relocs + vtable slots +8)
- cPathRequest_Update 81 (register-identical, hash-exact)
- ColQuery (Reset_..._2) 151, cPlayerCamera_UpdateMotion 266, cMachine_NextFrame 392 (already 10 words), cNPC_UpdateMovement 489
- ColQuery_InitSweep 0x3C6FC0 and CameraCol_Sweep: no prototype counterpart.

## 00151D30 cNPC_HandleMessage (3540 B) - MATCH 12:06 -> build/pending/p3/mw38_00151D30.c (hm/final.c)
Progress (gd lines): 831 -> 555 -> 439 -> 53 -> 38 -> 30 -> 4 -> 0, about 1 h.
- Real C++ virtuals (padding `virtual void nvN();` up to the slot) for t9 jalr; vtable offsets from retail (+8 vs proto
  after slot 0x88). Slot names from the D_004D9380 table in npc_51.c: 0x88 GetControllerType, 0xA4 GetMoveMode (returns
  enum -> `== 0` gives the andi), 0xD4 SelectTravelMode(int,int) (int param -> lbu of the eMode), 0x148 GetTravelSpeed,
  0x158 ResumeMovement.
- Message temporaries: n4's MsgB idiom (weak .dtors_drop dtors), derived ctors set vt; cAINodeMsg sets mDestinationType=2
  in its ctor; cCharActionMsg's `mDestinationType = 1` comes from a call-site wrapper `QueueAction(const cCharActionMsg&, g)`
  (retail addresses that store and the Queue arg sp-relative, not via the ctor's this register).
- The function is in MW's GCC-asm mode (a GCC `__asm__` lq for the cVector copy): bool pairs, `||` compare chains.
  `mActiveFlag && mEnabled && !mStreamingFlag` as ONE inline bool expression gives the top block.
- `lb; andi 0xff` id tests: signed 1-byte enum (has a -1 member) compared as `(unsigned char)msg.id == N`.
- Name tests: `cMessage_Name(&m) == *(cMessageName*)D_x` with a member operator== (call before global load).
- StopLookAt: `int i = lookWith;` then `currentLookAt[i]` in both nested ifs (address CSE'd with folded offsets).
- Vector copy: `cVector* dp = d; const cVector* sp = s;` then lq/sq GCC asm (fixed 26 lines at three ctor sites).
- `float Heading(const cVector& d)` helper for the atan2 address materialisation; `cNode* node = 0;` declared first in case 6.
- Last two: `{ cPathNavigator* pn = self->pathNavigator; pn->nodeIndex = msg.data; }` and `!self->IsLink(msg.data)`
  (inline `bool IsLink(int t) { return pathLinkType == t; }`) for load order vs beq operand order.

## 00162080 cPathRequest_Update (4780 B) - MATCH 12:32 -> build/pending/p3/mw38_00162080.c (pr/final.c)
Progress (gd lines): 473 -> 260 -> 203 -> 186 -> 146 -> 142 -> 114 -> 31 -> 21 -> 15 -> 7 -> 2, about 1.5 h.
- Whole function in GCC-asm mode (lq/sq + VU0 vsub/length asm). `#pragma inline_depth(8)` is required (copy ctor ->
  CopyV was emitted out of line at depth 3).
- Statics: cellPoolIndex D_004EA798, cellPool D_004EA7B0, nodeRequest D_004ED9F0 (one extern struct, fields by offset;
  check_match resolves sym+addend), destinationNodeList D_004EE010, losRequestMode D_004ED9D0, @29170 D_00489FF8.
- cSafePtr::Get = `IsValid() ? ptr : 0`, IsValid = `!ptr || ptr->mObjectId == id` with cObjectId::operator== (xor/sltiu).
- Queue target `g->mController == 0 ? g : g->mController` (bnez order); cNodeRequest_Update `!= 0` for the andi.
- `self->IsDestGroup(node->groupIndex)` / `IsDestNode(cell->nodeIndex)` / `IsStartNode(...)` members (arg loaded first,
  member compared as lhs) for load order + bne operands.
- `cell->Cost()` inline accessor for costFromStart -> loaded before the GetLoc call into $f20 (fixed frame size and
  all stack offsets, 114 -> 31). Same trick `cell->Cost2()` (nodeIndex accessor) in the destination-list loop.
- Request reset as cPathSystemRequest::Reset(g, 2) with the id ternary two inline levels deeper (cObjectId temp slot).
- far distance through `nodeRequest.SetDist(g_LevelFarDistance)` (float colour order vs the picker copy).
- operator-= asm in a static SubB one level deeper (delta copy pointers created first); Length(cVector v) asm three
  levels deep (Len1->Len2->Len3) for copy dst/src/asm colours.
- Remaining 2: at the second Length (0xfc0) ours has a dead duplicate `addiu v0,sp,256`, retail instead has a `nop`
  before the link-loop latch (0x101c). Not fixed by: statement permutations (119), continue/inverted ifs, setters,
  Dist/Sub2 wrappers, wrapper depth 1-5, cVector dtors, pragmas (loop_invariants off changes a lot).
- FIX for the last 2 (found by a 150-variant helper grid, pr/gen_hdr.py): operator- with its vsub asm in a separate
  static helper `SubC(&r, &a, &b)` (one inline level deeper). With that, any Length depth >= 1 (or the direct copy-ctor
  form with Length depth 0) matches; the dead `addiu` and the missing latch nop were both a colouring side effect of
  operator-'s asm pointers being created at the same depth as the copy pointers.
- Lesson: when a near miss is stuck on helper-shaped differences, grid the helper definitions (copy ctor form x
  operator form x wrapper depth) instead of mutating the function body.

## 0014BFF0 cNPC_UpdateMovement (4724 B) - MATCH 13:05 -> build/pending/p3/mw38_0014BFF0.c (um/final.c)
Progress (gd lines): 332 -> 273 -> 244 -> 202 -> 186 -> 147 -> 121 -> 107 -> 98 -> 84 -> 63 -> 48 -> 45 -> 38 -> 32 -> 26 -> 20 -> 13 -> 1 -> 0 (about 1.3 h).
- Retail = prototype (npc.cc lines 5611-5980) with a rewrite of lines ~5617-5671: the multiplayer transport loop moved
  inside `if (mGobj->flags3210 bit22)`, then UpdateGobjBeingTransported unconditionally and a terrain-active check
  through func_0014D460/450/410; the else branch is `!prev || GetMatrix().Z() <= floorZ` -> static cPlane (guard
  D_004EA3A8, object D_004EA3C0, record D_004EA3B0) + NotifyInInactiveTerrain(=NpcAi_GroundActor(gobj, forced, 1, z)),
  else `GetState()==3` -> NpcPath_SetHeight(pn, 3.0f + z). Also an added weapon branch
  `(IsAiming() && IsTargetVisible()) || (cWeapon_GetEquipmentType(mWeapon) == 1 && TargetPositionValid())`.
  Retail cHuman offsets differ from the proto (some -0x20, some +0x10): always take them from retail.
- Levers that worked: real C++ virtuals (cGOBJ 0xC0/0xE8/0xF4/0xF8/0x108, cNPC 0xA4..0xB4/0xD8); cMatrix accessors
  `T()`, `R1()`, `Z()`, `HeadingZ()`, `ToNet(cNetHuman&)` (keep the temp's base address in a register, offsets in the
  loads); pn->PathHeading(); named `cCharActionMsg_DestinationParams msg(...)` locals (DWARF has them) with explicit
  `msg.mDestinationType = 1; QueueMessage(&msg, gobj, 1)`; the params as a nested struct whose ctor stores through
  `tDestParams* p = this`; cPlaySoundMsg size 0x1C0 built with a trivial ctor + direct cPlaySoundMsg_ctor_cSndFxR call;
  `IsZero` (MW asm block from npc_36.c) with `int r`; Normalize/LengthSq asm one level deeper (static helper with a
  pointer local); member `operator-` (-21 lines); `angleTarget` declared before deltaAngle (DWARF order);
  `prev != inActiveSector` operand order; volatile D_005721A8 + `GetClientIndex(int conn)` param keeps retail's
  dead m_nConnectionIndex load; `InActive(&npcInfo, &id)` wrapper (id evaluated first, s0).
- Final steps (45 -> 0): `self->mGobj->ObjId()` accessor in the IsInActiveTerrain call (loads inActiveSector before
  the call); GetClientIndex as `if (MP) idx = GetMyIndex(conn); else idx = 0;` (retail's `b`); `mGobj->IsLocal()`
  accessor; `pn->NextNode()` / `GetGobj()` accessors (resetZ and first-load colours); NotifyTerrain(int forced) with
  `unsigned char f = forced;` and NpcAi_GroundActor(cGOBJ*, unsigned char, int, float) (one andi into a1);
  `SS(int m)` returning `const tSecondaryState&` (base register + field offset in the load).
- KEY RULE (new): named locals (including inline locals/params) are coloured AFTER temporaries. Where retail gives a
  bool-materialisation result the later register, the other operand must be a temporary: IsAiming
  `mGobj->ikRoutine ? IsAimingMode(mGobj->ikRoutine) : false` (CSE'd temp instead of a named `ik`, -11), and IsDying
  `IsDS(mGobj->GetState())` with an `unsigned short` parameter (the uchar->ushort conversion makes a temporary, -12).
- The last instruction (retail `lw a1, m_nConnectionIndex`, a seemingly dead load) is the 2nd argument of
  `NetGetMyClientIndex(int* clientIndex, int connectionIndex)`, loaded before the conditionals: declare the real
  two-argument signature.

## 00167C40 cMachine_NextFrame (5572 B) - NOT matched, still 10 gd lines (mn/n19_d.c)
- Start: n4's draft n19.c (10 words, exact size). Remaining: viewport site-1 rect pointer a1 vs retail a3 (6 lines)
  + quit-box scheduling (4 lines).
- Quit box through inline `PushQ(FrontEnd* fe, char* title, char* msg, int resetID)` (fe as inline param) fixes the
  fe/msg s4/s5 colours, but then fe's `lui at` comes after the GetQuitMessage jalr (retail: in its delay slot) and the
  trailing nop at 0xd9c is missing. Net still 10.
- Tried with no gain: XLibT member viewport forms (nb/nc), all 24 declaration orders of the named quit locals (original
  trmf best), direct msg-arg / title-first forms (h1/h2 = 10, h3 = 14).
- Next idea: make fe a temporary evaluated before the GetQuitMessage call (e.g. a fe-returning accessor called first)
  while keeping the PushQ colours; for the viewport, look for a call form that creates an extra a-register neighbour.
