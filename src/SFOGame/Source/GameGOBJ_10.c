/*
 * SFOGame/Source/GameGOBJ: 1 file, 00211820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00211820 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { short a; int b; int c; } Proto_00211820;
extern char D_004F5470[];
extern void cGOBJTriggerEventMsg_NetGOBJTriggerEventCallback(void);

NETREG_BEGIN(cGOBJTriggerEventMsg_InitNet, Proto_00211820)
NETREG_FIELD(a, 2, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(D_004F5470, cGOBJTriggerEventMsg_NetGOBJTriggerEventCallback)
static inline void merge_flush_func_00211820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211820 */
