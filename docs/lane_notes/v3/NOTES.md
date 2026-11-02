# V3 notes (2026-11-02)

Tools (build/agents/V3/tools/): vr.py (named substitution variants; spec FN=(name,lo,hi)), cd.py, dis.sh (compile + objdump
one function), win.py (CameraCol: compact arg-setup windows of both thunk calls; `retail`, or a draft, `-ns` = schedule off),
perm.py (all 792 int/float interleavings of the thunk prototype), cx.py / cx2.py (2^11 "assignment-expression" masks per
thunk argument, whole-function and per-call-window scores).

## 001914C0 cHuman_HandleJumpInit (4608 B) - lab 16 -> 2 (hj_best2.c), check_match 3 words (0x6d4..0x6dc)
- Best draft: hj_best2.c. Recipe (case-21 message copy, MsgCopy_L):
  `asm volatile { nop }` as the FIRST statement of MsgCopy_L, then `__int128* pd = (__int128*)&pc->vec; const __int128* ps = ...;`,
  the vt/field copies, and a plain C `*pd = *ps;` LAST.
  * The C-level 128-bit copy last gives retail's hoisted QueueMessage args and t0 field temp, but alone it folds
    (`lq v1,48(s1)`) and coalesces the copy base with a0 (31 lines; unfilled mode without the `.set reorder`).
  * An instruction-EMITTING volatile asm in the same basic block switches that block to the unoptimised pattern:
    base kept in t3, `addiu t1,s1,48 / addiu t2,t3,48` early, lq/sq last = retail exactly, and the whole function
    stays in filled mode (no `.set reorder` barrier needed). Works with MW `asm volatile { nop }`, GCC `__asm__ volatile("nop")`,
    `mtc1 zero`, `move z,zero`. Zero-emission asms (empty MW/GCC asm, `.set reorder`, labels, empty asm with outputs, dead
    `if (0)` blocks) do NOT trigger it (they give the 1170-byte unfilled mode, or 31 lines with the reorder barrier).
- Remaining (2 lab lines): retail `beqz s2; nop; lui v0; addiu t3`, ours `beqz s2; addiu t3 (filled); nop(asm); lui v0`.
  The asm nop is one extra instruction where retail has the empty delay slot. Placing the asm before `Msg_L copy;`
  gives `beqz; nop; nop; lui v0; addiu t3` (5 lines). Tried: nop at every statement of MsgCopy_L and of the if body,
  in IsActive_L, `.set noreorder` wrapped, volatile split lq at each position (13+), copy-last forms (MW/GCC, volatile
  or not, "+r" pointers: non-volatile GCC asm is folded like C).
- Not acceptable as is (the asm nop is not in retail). Next idea: a real retail instruction of that block that can
  legitimately be asm (only the vec lq/sq) emitted volatile without becoming a barrier for the arg hoisting.

## 0020D680 CameraCol_Sweep (2136 B) - unchanged at 16 lab lines (cs_best16.c = U3 cs20)
- Remaining: arg set-up scheduling of both ColQuery_InitTransformedThunk calls (see win.py; retail call 1
  `cA t1 f14 t2 f15 a2 a1 L12 cB a3 t0 f13 L16 |a0`, call 2 `cA t1 f14 a0 f15 a2 a1 L12 L16 cB a3 f13 t0 |t2`).
- Gen order (schedule off) of ours: t1 (M temp), the three float constants f13,f14,f15 (always hoisted, in
  parameter order), then a0 a1 a2 a3 t0 f12 f16 t2 in parameter order. Args written as assignment expressions
  (`(x = e.radius)`, `*(sc = &e.scale)`) are generated before the constants/after them ("complex first").
- Tried, no gain (all >= 16): all 792 int/float prototype interleavings on cs20 (perm.py; floor 16, many ties);
  2^11 assignment-expression masks per argument, whole-function and per-call-window scoring (cx.py/cx2.py: the
  plain form is best for both windows); local pointer copies of e / &e.scale / &e.radius at loop top, before the if
  and inside the if (scale pointer moves `addiu t2` before the M asm: 18-20); named float locals r1/r2 at top / before
  the if / in the if (16-49); 49 forms of the two 0.05f constants (literal, inline fn, static const, cast, double,
  local: identical unless a local, which hoists f13 above the M asm: 32-34); inline wrappers taking the constant,
  e, scale or radius as parameters in several orders (32-42: the wrapper shares one `lui` between constants);
  M ctor asm without "memory", non-volatile, as MW `asm {}` / `asm volatile {}` (identical 16).
- Observation for a successor: with `float k = 0.05f` as f13 (loc_lit) call 2's f12/f16 land exactly where retail
  has them, i.e. retail looks like f13's constant is generated late (after the e loads) while f14/f15 are hoisted.
  No C form found that makes one literal float argument non-hoisted.

### HJ follow-up (coordinator questions, 2026-11-02 evening)
- (1) hj_best2.c has 1152 instructions = retail: the asm nop takes the place of retail's empty-slot nop, so the residue is
  only the order (ours `beqz; addiu t3; nop(asm); lui v0`, retail `beqz; nop; lui v0; addiu t3`). check_match: 3 words.
- Filler rule (observed): MW fills the beqz slot only from the FIRST scheduled instruction of the fall-through, when
  that register is dead at the target: addiu t3 (pc) is taken; lui v0 is not (retail; pos2 variant); a volatile asm nop
  is never taken (it inserts its own nop -> two nops, +1 instruction, 5 lab lines: h_*/hp_*/hd_*/fi_* in sh17.py).
- (2) t3 base after the asm: pointer assigned after the nop at the if head, nop in a separate inline called first,
  MW vs GCC `__asm__ volatile("nop")`, with/without "memory": all give the two-nop form (5 lines; 10 with the reorder
  barrier). Passing `&copy` straight to MsgCopy_L loses the t3 base (sp-relative stores, 16 lines). Nop in IsActive_L's
  return path or between the condition and `if (ok)`: 22-30 (trigger is not in the block).
- (3) `.set noreorder` wrapping (`asm { .set noreorder } asm volatile { nop } asm { .set reorder }`, one MW block with
  the directives, GCC `".set noreorder; nop; .set reorder"`): the block-local trigger is lost (31 lines with the
  reorder barrier, 1170-byte unfilled mode without it).
- Trigger later in the block (pos2: after the first vt store) keeps retail's unfilled slot and `lui v0; addiu t3`
  start, but the asm nop then is a real extra instruction (1154).
- Conclusion: with an asm nop as the trigger no position matches; retail's trigger must be an instruction retail
  really has. In this block only the vec lq/sq qualifies, and as a volatile asm it blocks the arg hoisting (56-65).
