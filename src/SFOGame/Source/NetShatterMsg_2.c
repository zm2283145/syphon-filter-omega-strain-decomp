/*
 * SFOGame/Source/NetShatterMsg: 1 file, 00316860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00316860 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int b; } Proto_0020E420;
extern char D_0052ACB8[];
extern void cNetShatterMsg_NetShatterMsgCallback(void);

NETREG_BEGIN(cNetShatterMsg_InitNet, Proto_0020E420)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 4, 1)
NETREG_END(D_0052ACB8, cNetShatterMsg_NetShatterMsgCallback)
static inline void merge_flush_func_00316860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316860 */
