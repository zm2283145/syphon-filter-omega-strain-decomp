# P2L final report (2026-11-01)

## Staged
- cHumanCollisionRoutine_ctor 0x1EB990 (2084 B): build/pending/p2/mw38_001EB990.c (check_match mw38 MATCH,
  no UNDEF, no DATA lines, one function). Source draft: build/agents/P2L/hc_final.c.

## Best near miss
- cLedgeValidator_cSingleResult_Validate 0x1EDD10 (3716 B): build/agents/P2L/v17.c, check_match 111 words, exact size.
  Frame, every stack slot, the paddubs, the static probe array guard, the property test, the iterator temps and the
  float block all match. What remains is one register issue that repeats for each of the 7 rays: the address of the start-point temp (ps)
  is created when S is evaluated and holds a1 until the ctor call, whereas retail re-derives it just before the jal.
  The order-of-evaluation analysis is in NOTES.md: inline args are evaluated right to left, direct-call args left to
  right, temps are allocated pre-order, and the ray temp lies below all op locals. The only form found that keeps all
  of that is the comma/Addr wrapper.

## Ranked but not worked
- Transport_StartOfFrameUpdate (0.99 hash-regs, many out-of-line cQuatVec calls plus the matrix-to-quat asm from man_2.c).
- UpdateClimbingEdge (0.986), HandleMoveMessage<0>/<1>: the k8 bb4.c draft is now 52 words after renaming its
  callees and making the ActMsg dtor weak (P2L/hm2.c). The msg/edge s4/s2 swap is still open (all decl orders worse).
- Wrist IK functions, NextFrame, HandleJumpInit, Land: not started.

## Reusable findings
- MW stack-slot classes follow inline depth. Moving a temp one wrapper level deeper or shallower lands it in the
  retail slot. tools/slots.py compares the order in which stack offsets are first used.
- `slti $at` loop tests come from a goto loop with `i <= N-1` and `#pragma opt_unroll_loops off`.
- Placement new adds a null check, so use inline Init() members with `T* t = this;` instead.
- In a VU0 asm helper, local copies of the pointer operands (`const V* A = a;`) change the vreg creation order.
- A `.set noreorder` MW asm block shifts the scheduling of a following lq/sq copy.
- `&(rvalue)` compiles under MW C++.
- `extern "C" T f(args)` returning a struct puts the hidden return pointer in a0. It emulates a ctor call exactly in
  registers, but MW allocates the temp among the function temporaries.
