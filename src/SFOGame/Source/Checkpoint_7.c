/*
 * SFOGame/Source/Checkpoint: 1 file, 0022E240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022E240 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { int a; } Proto_0022E240;
extern char D_004F7958[];
extern void cRespawnMsg_RespawnMsgCallback(void);

NETREG_BEGIN(cRespawnMsg_InitNet, Proto_0022E240)
NETREG_FIELD(a, 4, 1)
NETREG_END(D_004F7958, cRespawnMsg_RespawnMsgCallback)
static inline void merge_flush_func_0022E240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022E240 */
