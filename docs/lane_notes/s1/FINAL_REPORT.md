# S1 final report - ActorPhys_RunResponse 0x1E2180 (12016 B; ends 0x1E5070)
No match. Best draft build/agents/S1/ar_best.c: lab diff 954 -> 463 (sp-masked 411 -> 222); frame now 0x14D0 = retail;
all named-local slots 0x870..0x14D0 and the scalar spill region mostly right. Nothing staged.
Key findings: frame model (named > spilled temps > inline locals; memory-resident locals get 16-byte slots in the
less-optimised mode, RA spills packed words), pass-depth control via no-local wrappers, member operators materialise
`this`, `Q1D_L(&dst,&expr)` vs `AV(dst)=expr`, switch compare chain in reverse source order. Details, tools and next steps
in NOTES.md.
