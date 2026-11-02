# S2 final report (2026-11-02)

Staged: 1
- StaticInit_scriptUtils 0x4D09A0 (3340 B) -> build/pending/s2/mw38_004D09A0.c. check_match: MATCH, DATA .data 0x004A82C8
  size 0x210 MATCH. **Integration needs a linker rule**: the file defines static copies of Array_SOBJ_getClassId (0x2690E0)
  and cNodeList_SOBJ_getClassId (0x269830) in sections `.ipa_002690E0` / `.ipa_00269830`; map them NOLOAD at those
  addresses (see NOTES.md). Reason: in scriptUtils.cc these are anonymous-namespace (static) functions, and MW keeps v1/a2
  live across calls to a static callee defined earlier in the same file. A scratch link with that rule gives all 835 words
  byte-identical to retail. Splat entry is currently `[0x3D09A0, asm, sinit_4D09A0]`.

Improved, not matched
- XLib_Init 0x37E780: 221 -> 109 lab lines (build/agents/S2/xi_best109.c; check_match size 0xEE0 vs 0xEF0). Keys: volatile
  asm F2I helper with `int r = 0` for SetBGColor/SetFogColor, Al16 inline, isDirty via member/pointer, fbp local, SetBuffers
  parameter order search.
- XLib_ApplyContext 0x37C870: plain-C AddV4 base at 521 (acceptable form; the asm copies were 519). Retail copy shape not
  reproduced yet.
- WeatherEmitter_Update: not started.

Tools: sinit2c.py (sinit asm -> C), lab.py (lab with LANG_/XFLAGS), sbperm.py/sbhill.py (parameter-order search), m/cc.sh.
