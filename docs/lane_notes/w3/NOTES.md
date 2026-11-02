# W3 notes (2026-11-02 night)

Tools: tools/vr.py (V3's variant runner, writes vv/), tools/dis.sh (compile + objdump one function). Spec files s*.py.

## 001914C0 cHuman_HandleJumpInit (4608 B) - best still 2 lab lines (V3 hj_best2.c, copy in W3/hj_best2.c)
- Prototype line table: the whole copy block (vt stores, field copies, lq/sq, QueueMessage, dtor) is ONE source line
  (human.cc 12196), i.e. one statement building a C++ temporary/copy (cCharActionMsg_Vector, cMessage::mDestinationType=4
  at +0x20). Prototype code is identical to retail.
- Key observation: with the vec copy as volatile asm (lq only / sq only / both, MW or GCC, operand or "m" operand,
  volatile+non-volatile mixes; s1.py) the block gets EXACTLY retail's shape (unfilled beqz slot, lui v0 first, two
  separate base regs, sp-relative `sb v0,1120(sp)`) except that `li v0,4; addiu a0; move a1,s0; move a2,zero` are scheduled
  after the lq (volatile asm is a full scheduling barrier) instead of before the copies; because a0-a2 are then not live
  during the copy, the copy uses a0-a3 instead of retail's t0-t3. Score 56-62 lab lines (glq/gboth best structural fit).
  => If retail's trigger is a volatile lq/sq, the call's argument moves must be generated BEFORE the copy in retail.
- Tried to get the arg moves generated early (s2.py, s7.py): copy+dest in an inline returning the pointer used as the call
  argument (59-63); C++ class chain with copy ctors (MB/MA/MV, member-init vec, asm/implicit/C copy ctors; s6.py: 56-64);
  inline Send wrappers binding (msg, self, 0, 4) as parameters before the body, wrapper around QueueMessage only, reference
  and pointer forms (s7.py: 58 or 269). None hoist the arg moves above the asm.
- Volatile-qualified accesses (source/dest of the 128-bit copy, single fields, vt stores; s3.py) are NOT block triggers
  (1170-byte unfilled form, 64).
- Mode interplay found: the draft's `asm { .set reorder }` in NAME_COPY puts the whole function in unfilled mode (1170);
  the instruction-emitting volatile asm in the copy block restores filled mode (1152). Without both: 1136/1138 and retail's
  `beqz; ...; b L; nop` loop shapes disappear (s4.py). A dead `if (0) { asm volatile { nop } }` changes nothing here (s5.py):
  the function already has volatile asm.
- Next idea: find why retail's arg moves precede the copy (maybe a by-value cMessage argument / temporary bound to a
  `const cMessage&` parameter of an inline QueueMessage wrapper whose other params are copied into locals first).

## 001E2180 ActorPhys_RunResponse (12016 B) - lab 371/116 -> 366/111 (ar_best111.c = ar2.c; base t2 ar_best.c)
Tools: tools/av.py base.c spec.py (substitution variants scored with T2's sec.py, sp and masked), specs a1..a12.py.
- (+2) 0x2C4C: `asm { nop }` (non-volatile) right before `goto tail;` after the r1 rotation block: the asm nop lands
  in the `b` delay slot and the inner ifs target the `b` (retail `sw zero,352(s1); b L; nop`, no jump threading).
  Empty MW/GCC asm (volatile or not, with memory clobber) and `.set reorder` there do nothing / worse. Owner idiom
  "explicit asm { nop } where retail has a real nop", commented.
- (+3) 0x2BB4: the rotation-target member address is taken in the condition:
  `char* o; if (bit && *((unsigned char*)(o = (char*)p + 0x7A0) + 2))` -> retail's `addiu v1,s5,0x7A0` in the
  beqz delay slot, reused for tq2 (prototype line 3256 = the condition line). Assigning o before the if: worse (117).
- 0x2C20 MaxZ (`l1100.z = max(f370, l1100.z)`): `float a = p->f370; float b = l1100.z;` gives retail's load order
  (+2 lines) but f1/f2 colours swap (112 vs 111 overall, not kept); 28 MaxZ helper forms give identical colours.
- 0x2A9C dead nop after `b; swc1` in the f394 if/else (prototype has no iB0 if/else here, retail added it): the
  nop is the remnant of a removed jump in this mode. Tried asm nops in then/else, ternary, swapped, goto, blocks,
  dead if(0)/empty ifs, value-copy forms (a2-a4): none (an asm nop at then-start reproduces it but adds a nop).
- 0x29E4 `swc1 ..; mov.s $f1,$f1` (store->load forwarding copy) in Tele_L tail: volatile emitting asm in that block
  gives the store-first order but a real reload instead of mov.s; empty asm with outputs: no change (a5).
- 0x2B68 dead `addiu v0,sp,&b` in ChildOff_L: Cp2X with `void* xx` in 4 positions, MW/GCC, a QQ_L copy-ctor
  temporary as the cQuatVec ctor argument (dead addiu appears but the copy sinks below the VV stores), 16 forms (a7/a8):
  no gain.
- 0x2684 Remap (mtc1 zero f4 early + mov.s f3,f4): 36 Remap/Clamp body forms and 4 call-site zero forms: no change.
