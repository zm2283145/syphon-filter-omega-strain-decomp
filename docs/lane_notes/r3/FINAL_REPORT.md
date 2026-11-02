# R3 final report (2026-11-01 night)

Nothing staged: neither target reached a full match. Both are much closer than before.

## 0x1B1710 cHuman_NextFrame (3936 B): new draft, 154 -> 18 lab (check_match: 17 words)
- Best draft: build/agents/R3/nf_best18.c. The function ends at 0x1B2670, not 0x1B2650.
- No mode trigger is needed. The body inlines a GCC `__asm__ volatile` (the VU0 vsqrt Length() used for the 0x3538
  flag), so the function is already in the less-optimised mode, like retail.
- The prototype (0x1A9540, SCUS_973.97) is a close template. The multiplayer front part is already in it (lines
  1957-2073). Retail changes: the gun-hand block uses calls, Actor_UpdateAnimationState, Actor_Ignite for effect 0,
  fireCount++ moved after the loop, flag bits 30/31.
- The frame matches exactly, and so does every instruction outside three register-colouring clusters (no
  sp-offset diffs left):
  1. FxHdl::IsValid inside the particle loop, two sites, 2x5 words. Retail colours base a0 / obj v1; ours v1 / a0.
     About 110 helper and call-site variants (grids g2, g5) did not change it.
  2. `!Dying(self)` result: retail a2, ours a0. 54 variants tried (g3).
  3. IsHuman in the loop: retail keeps ctrl in v0 plus `move a0,v0`; ours loads a0 directly. About 20 variants tried.
- The techniques that worked are in NOTES.md. The two useful new ones:
  - MW evaluates call arguments right to left. An inline `Att::Blend(orient, Point(hand), dt)` reproduced
    retail's hand-then-orient order and its frame order. Pushing Blend's body one pass deeper
    (`Blend(){ Blend0(); }`) put the Point local above the Lerp temps.
  - A pointer local inside a tiny getter (`NetFlash(H* a) { Net* n = a->net; return n->flash; }`) shifted
    the colours of a compare into retail's. Found with a 432-variant grid.
- Another useful form: `obj = a; serial = -1; int m; serial = *(a ? &a->serial : (m = -1, &m));` reproduces the
  safe-pointer ctor that writes its -1 temporary only in the else branch.

## 0x18A950 cHuman_HandleDeath (7240 B): 21 -> 6 lab (check_match: 8 words, one cluster)
- Best draft: build/agents/R3/hd_best6.c, built on R1's hd_best21.c.
- The px copy (`move s0,s3`) and the dead nop after `b` in RateF came from two changes together:
  - Remove the function's `#pragma opt_common_subs off`. With CSE on, `px = &x` is value-numbered to the
    checkpoint constructor's `this` register. This is the same mechanism as q4's Land `move s3,s2`.
  - Write the checkpoints as a C++ class with Land's constructor (`XC* t = this; ...`) and an `AddC(int i,
    unsigned char id, void* a, unsigned char k)` member.
- TailC: `x.AddC(4, k0, actor, 1); unsigned char one = 1; px = &x; px->AddC(5, k1, actor, one); px->AddC(6, ...)`.
  It now matches exactly. TailA (the old P56) uses the same form and also matches. NmI_L uses the plain
  NAME_COPY3 loop.
- Remaining: InstNR_L computes `an` before the cSkaPlaybackGroupId ctor in retail. Moving it there (tb1.c, 11)
  fixes the schedule but rotates the s-registers: ours an/GetInstruction/GetAnimCheckpoints = s0/s3/s1, retail
  s3/s1/s0. About 70 variants tried (g7, g8, g9, tc*, td*, te*, th*, ti*, tj*).

## Files
- mutate.py on nf14: 7004 variants, no gain.
- NOTES.md (kN format), nf_best18.c, hd_best6.c. Tools: t.sh and var.py.
- The g*/ directories hold the variant grids. key.txt in each maps variant to form.
