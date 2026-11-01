# N4 final report (session 2026-11-01, 01:40 to about 04:45)

## Staged
- gunList_GunRender 0x3836B0 (4932 B): build/pending/n4/mw38_003836B0.c, staged 02:12. MATCH on mw38, mw50 and mw304,
  with no UNDEF and no DATA lines. The coordinator integrated it at 02:29 as
  src/Libs/SFOLib/Source/man/func_003836B0.c.

## Not matched (best drafts in build/agents/N4/)
- cMachine_NextFrame 0x167C40 (5572 B): mn/n19.c. 10 differing words, exact size, and the jtbl DATA .rodata 0x49C500 is MATCH.
  Down from 229 diff lines. The two remaining spots are both register-colouring issues:
  1. First viewport reset at 0xa40-0xa84: retail has index a2 and rect a3. Mine has index a2 and rect a1 (n19 form),
     or index a1 and rect a2 in the prototype/XLib-member form (mn/v_B.c). Retail behaves as if some vreg occupies a1,
     but no visible instruction uses a1.
  2. Quit box at site 1, 0xd74-0xd88: fe and msg are swapped between s4 and s5. Retail colours msg before fe.
  What did not fix them: every decl/init form at site 1 (65 exhaustive), 24 inline parameter orders, cross-sweeps of
  site 1 and site 2 decl orders, random placement of 7 locals across scopes (3000 tries), hoisting each function local,
  variable reuse, function-pointer variables, if/else forms, the `register` keyword, and whole-function mutation
  (tools/mut_gd.py: 15572 variants, best stayed at 10).
  Key finding: the site-1 colouring changes when unrelated later code is deleted (state 5, 6, 15/19, 20). So it
  depends on a whole-function allocation order, not on the local code. Details are in NOTES.md.
- XLib_ApplyContext 0x37C870 (4388 B): ac/ac_best421.c (418 lines) and ac/ac_a9_477.c. Parked. The VIF one-qword copy
  is still modelled as GCC asm. A plain C struct copy gives word-by-word copies with folded offsets (545 lines).
- XLib_DrawLensFlares 0x3781B0 (5388 B): surveyed only. lf/proto_l.s is the prototype disassembly with .line numbers;
  the prototype is identical to retail at the start. The body is a heavily scheduled 64-bit GS packet plus cMatrix/VU0
  inlines. I judged it out of reach in the time left.

## Reusable findings (MW mw38)
- A named local is a single vreg for all its uses: there is no web splitting, so reusing a variable moves registers.
- In small functions, locals are coloured in reverse declaration order (the last-declared local gets the lowest
  s-reg), and temporaries are coloured before named locals. In large functions the order is driven by something
  global (see above).
- For inline-function arguments, MW evaluates arguments that contain calls first, whatever the parameter order. A
  global passed directly as an argument is therefore loaded after the calls.
- Direct call arguments are evaluated left to right. Where retail evaluates a later argument first, the source had an
  explicit local (the cString `m` in NextFrame).
- XLib fields: D_00538C60 = g_Video+0xA70 (current viewport index) and D_00539170 = g_Video+0xF80 (full-screen rect).
  The viewport reset is an XLib member inline over these fields.
- GunRender levers are in NOTES.md (DWARF-ordered named locals, per-site copy forms with dead `xx` addius, and
  VAdd parameter order).

## Tools (build/agents/N4/tools)
- gd.py: aligned diff.
- vt.py: slot sweeps.
- greedy.py: per-site coordinate descent.
- mut_gd.py: gd-scored copy of tools/workflow/mutate.py, with optional /*MUTLO*/../*MUTHI*/ region markers.
- rdecl.py: random declaration placement.
- qregs.sh: prints the NextFrame quit-site-1 and viewport registers.
