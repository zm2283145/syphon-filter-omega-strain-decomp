# Z1 notes (kN format)

## cGameSound_PlaySound (0x1C8770, 1688 B) -- MATCH, staged build/pending/z1/mw38_001C8770.c (draft Z1/ps_match.c)
- from Y1 ps_best7.c (7 lab lines, priority-loop SR/fx a1/a2 swap).
- micro harness (m0.c: just the bank-4 guard + loop + two calls) reproduces the swap; score.sh diffs the loop window.
- grid1.py: 6^4 access forms (direct / via named fx / member accessor / free const& inline) for bank, handle and both
  priority reads, with named fx: all 6 (swap unchanged). The colour order is fixed by "SR temp before named fx".
- cure: a named iteration pointer that starts at `self` (not self->slots), with fx derived from it at +0x50:
  `char* sl; for (i = 0, sl = (char*)self; i < 50; i++, sl += sizeof(cGameSoundSlot)) { cSndFx* fx = (cSndFx*)(sl + 0x50); ...`
  The named pointer is coloured after fx (retail a2/a1) and, because it starts at self, the +0x50 stays folded into
  the accesses (Y1 r1.c started at self->slots = self+48). Initialising sl in the for-init after `i = 0` gives retail's
  `move a3,zero; move a2,s2` order (initialising it before the loop swaps the two moves).

## XLib_DisplayLastFrame (0x37B5C0, 428 B) -- not matched, best still 7 lab lines / 7 check_match words (k3 b_37B5C0.c = Z1/xl0.c)
- residual: retail dh=a3, dx=t0 (li 656 after the mult), dw=t1; ours dw=t0, dx=t1 (li 656 hoisted above the mult).
- prototype is hash-exact to retail; the whole dh/dw/dx/dy computation and the GS_DISPLAY1 store are ONE source line (1955)
  and DWARF lists no dx/dy/dw/dh locals, so the original is one statement (inline call or macro).
- findings on the colouring:
  * dx's declaration position NEVER matters (24 decl orders x 3 if/else/ternary forms, two uses of dx, `dx += xpos`,
    function-top declaration, out-param inline, inline-body local): the if-converted (movz) value is not the named
    local; it is always coloured after the named single-def locals dw/dh.
  * dw vs dh: reverse declaration order (later-declared gets the lower register), as the k4/n3 model says.
  * dx as a non-if-converted inline-body local (`r = 656; if (!p) r = 636;`) IS coloured first (gets a3), so
    if-conversion is what demotes it; retail has the movz, so retail's dw must be in a class coloured after the movz web
    (a temp, not a named local), yet computed before the dy branch.
  * every temp form of dw tried (inline argument, inline call result as argument, -1 inside the inline, CSE)
    forward-substitutes the computation to its use in the OR chain (after the dy branch): 14-96.
- tried, all >= 7: SetDisplay parameter order (720, locals and all-args), all-args with copy bodies (720, 34) and
  copy-subset bodies (65 x 2, >= 39), inline depth 0..3 for each of dh/dw/dx/dy (256), local/arg/inline-arg/inline-local
  per field (256), width/height read forms direct / free const& inline / member (243), local types (256), const/register,
  dx statement forms (if/else, default+if, x2 two-statement, `+= xpos`), dw/dh split and algebraic forms, k1/width named
  locals at every position, store/SetDisplay wrapper levels (W2), out-param inlines (72), local struct (scalar-replaced!)
  field order x assignment order (144: 10-14), SCE-style macro with u_int casts (7 with locals), kMagH/xpos statement
  forms (32), nested block declarations, random function-level declaration orders (500), mutate.py 65 min (no gain).
- next idea: find a C form whose dw value is an unnamed temp evaluated before the dy branch (e.g. a by-value inline whose
  body evaluates its arguments in a fixed order without forward substitution), or a dx form that is if-converted but
  keeps the named-local colour class.
