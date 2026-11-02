# U1 final report (2026-11-02)

Staged (both MATCH with check_match -c mw38, no UNDEF):
- cHuman_HandleMoveMessage_cMoveMsgTemplateR 0x1BB1D0 (3956 B): build/pending/u1/mw38_001BB1D0.c
- cHuman_HandleMoveMessage_cMoveMsgTemplateR_2 0x1BC4B0 (4316 B): build/pending/u1/mw38_001BC4B0.c

Key fix: the msg/edge s4/s2 rotation came from a single inline call, `Translate(a, msg->Trans())`; passing `&a->mc`
to a context-pointer helper instead put every s-register in retail's order. Then: msg used as the parameter directly,
anchors declared flor/edge/ladd, simpler Free2, source-first delta copy, and a tagged Q ctor at the mode-4 site.
Source idioms used: the existing dead `if (0) Send(...)` frame-slot lines (commented), a tagged ctor `Q(const M44&, short)`.

Unchanged: cHuman_HandleDeath (6 lab), cHuman_NextFrame (8 lab), cHuman_HandleJumpInit (16 lab). Details in NOTES.md.
