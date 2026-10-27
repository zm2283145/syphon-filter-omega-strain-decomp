/*
 * SFOGame/Source/NetScoreMsg: 1 file, 00316550
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00316550 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int b; int c; } Proto_00316550;
extern char D_0052ACA8[];
extern void cNetScoreMsg_ScoreMsgCallback(void);

NETREG_BEGIN(cNetScoreMsg_InitNet, Proto_00316550)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(D_0052ACA8, cNetScoreMsg_ScoreMsgCallback)
static inline void merge_flush_func_00316550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316550 */
