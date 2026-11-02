# V1 notes (2026-11-02)

Tools: lab1.sh (HD lab, 0x18A950-0x18C598, ~0.2 s), lab2.sh (NF lab, 0x1B1710-0x1B2670), dis.sh (compile + objdump one
function with the lab flags), m/mrun.py (micro: TailA_L compiled as a standalone `micro()`, prints an/GI/GAC regs),
m/full_sig.py (same signature on the full HD + lab score), ks.py (exhaustive knob search on HD), nfsig.py (NF Dying-r /
loop-IsHuman register signature + lab).

## 0018A950 cHuman_HandleDeath
- best draft: unchanged, r3 hd_best6.c (lab 6, check_match 8 words). Hoisted form (an before the y ctor) = h1.c, lab 11.
- Remaining: retail computes an before the cSkaPlaybackGroupId ctor; doing so rotates an s0 / GAC s1 / GI s3
  (retail an s3 / GI s1 / GAC s0).
- New facts:
  * The TailA_L inline compiled alone (m/hd_best6_mi.c, m/h1_mi.c) reproduces the rotation exactly, so the cause is
    inside TailA/InstNR plus actor's liveness, not the rest of HandleDeath.
  * Micro deletions (m/v4..v7): the rotation needs an if/else DIAMOND inside `if (out)` after the hoisted an. Any
    diamond does it (if/else, ternary, inline XF helper, `if (out)` as condition, arms without an, arms without a
    call). Without the diamond the hoisted an gets retail's order (an last), but in the full function px then splits
    from x (`move s1,s0`, t_nob5.c 188 because the code changes).
  * If actor is dead after TailA (micro noAim; full m/f2 "allgone") the hoisted an is coloured AFTER GI/GAC (it takes
    s2). So the order depends on an's interference degree (Chaitin simplify/optimistic push), not on creation order.
    R4's "one interfering vreg too many" model is consistent with this. The f98/f9C stores and the ckpt ctor are not
    that vreg (m/f3), and nothing besides actor is live across TailA.
  * e1/e2 as C++ temporaries in the call (e1.c: `struct EvT { EvT() { ctor } __declspec(weak) __declspec(EVD) ~EvT() { dtor(this,-1); } }`,
    `.dtors_drop` section, AddRequest declared with `const EvT&`) reproduce retail's ctor order (752 then 688), slots and
    reverse dtor order exactly: probably the natural source form. Colours unchanged (e1nh.c 6, e1.c 11).
- Tried (all >= 11): ks.py full grid of 2,400 combos = an form (5) x y as C call / `PG y(-1)` object (2) x diamond
  form (4) x events named / temporaries (2) x InstNR signature (a,ps,sel)/(a,ps)/(a,sel,ps) x getter base sel/ps x px
  form in TailA (3) -> best 11 (128 combos tie). InstNR taking `Sys_L*` (this = sys, an = &s->anim, 6 forms, m/v3),
  an declared/assigned in TailA and passed down (m/v2: an s1, px splits, 25).
- Next idea: find the extra neighbour of the hoisted an. Candidates are the y-ctor argument vregs (&y, -1) before
  they are coalesced into a0/a1, which a non-hoisted an never overlaps. Something that makes MW create those as
  precoloured registers instead of vregs (e.g. y ctor called through a member/inline whose `this` is already a
  register value) might lower the degree. Alternatively a form where actor's register is reused (not live) across
  InstNR in the IR but still s2 afterwards.

## 001B1710 cHuman_NextFrame
- best draft: unchanged, r4 nf_best8.c (lab 8, check_match 7 words).
- Tried (all 8): Dying / IsHuman as inline member functions of H (memDying/memIH/memBoth); dead
  `if (0) { asm volatile { nop } }` at 8 positions in the fire block and inside Dying/IsHC (nfb2);
  `bool dy = Dying(self)` named with dead `if (0)` uses after the Hdl section (nfb3: 10, dead uses do NOT extend
  liveness, they are dropped before RA); micro (m/m1.c, m2.c) of the prototype-shaped fire block: 9 IsHuman forms,
  base-class / multiple-inheritance / virtual-base `this` conversions: only a non-zero base offset breaks the a0
  coalescing (`addiu a0,v1,4`), never a plain `move a0,v0`.
- Removal bisection (nfb1: src, Damage, IsHuman block, Set args, Dying, SetIntensity, Ignite) never produces the
  retail pattern, as expected: retail needs an EXTRA value in a0 (and a1 for Dying's r) across those points.
