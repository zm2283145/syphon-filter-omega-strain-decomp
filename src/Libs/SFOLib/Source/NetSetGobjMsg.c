/*
 * Libs/SFOLib/Source/NetSetGobjMsg: 1 file, 00431B10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00431B10 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; int c; } Proto_00211820;
extern char D_00582748[];
extern void cNetSetGobjMsg_NetSetGobjMsgCallback(void);

NETREG_BEGIN(cNetSetGobjMsg_InitNet, Proto_00211820)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_FIELD(c, 4, 1)
NETREG_END(D_00582748, cNetSetGobjMsg_NetSetGobjMsgCallback)
static inline void merge_flush_func_00431B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00431B10 */
