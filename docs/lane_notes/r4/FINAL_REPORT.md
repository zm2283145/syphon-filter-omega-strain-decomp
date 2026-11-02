# R4 final report (2026-11-01 late night)

Nothing staged: neither target reached a full match.

## 0x1B1710 cHuman_NextFrame (3936 B): 18 -> 8 lab (check_match 17 -> 7 words)
- Best draft: build/agents/R4/nf_best8.c (R3's nf_best18.c with one changed line).
- The FxHdl::IsValid cluster is fixed at both particle-loop sites:
  `if (!((obj != 0) ^ 1)) { int os = *(int*)((char*)obj + 0xC); if (!SameNV(os, serial)) ok = 0; }`
  - With the null test written inline, obj is a temporary instead of the named parameter of IsNullNV. This applies
    p3l's rule (named locals and parameters are coloured after temporaries) and gives retail's base a0 / obj v1.
  - R3's nested `int os` then fixes the load order.
- Two clusters remain:
  1. Dying r: retail a2, ours a0.
  2. Loop IsHuman: retail `lw v0` then `move a0,v0`. This sequence is unique in the retail binary, and it is also
     in the prototype.
  About 90 further variants did not change either cluster: Dying, Damage block, IsHuman forms, inline wrappers
  and getters.

## 0x18A950 cHuman_HandleDeath (7240 B): unchanged at 6 lab (R3 hd_best6.c, 8 words)
- About 200 hoisted variants all keep the s-register rotation (an s0 / GAC s1 / GI s3):
  - forms and declaration positions of an (incl. Install_L's form)
  - An_L wrapper depths
  - C++ Y object, ctor wrappers, an in the ctor's argument list
  - InstNR as a member function with this = an
  - named getter locals
  - getter wrapper depth grid
  - CSE spellings, and const, reference and register an
- Diagnostic finding: an gets s3 only when its definition directly follows a call and no call lies between the
  definition and its first use. Retail matches neither case. Details and the next idea are in NOTES.md.

## Files
- build/agents/R4/NOTES.md (kN format)
- build/agents/R4/nf_best8.c
- build/agents/R4/grid.py (generic substitution-grid runner)
- v*.py and w*.py variant definitions; outputs in g*/ and n*/
