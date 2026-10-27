/*
 * SFOGame/Source/gameSound_msg: 1 file, 0020E950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020E950 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { int a; int pad; int b[4]; int c; char d; } Proto_0020E950;
extern char D_004F53E0[];
extern void cStopSoundMsg_NetStopSoundMsgCallback(void);

NETREG_BEGIN(cStopSoundMsg_InitNet, Proto_0020E950)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 0x10, 1)
NETREG_FIELD(c, 4, 1)
NETREG_FIELD(d, 1, 1)
NETREG_END(D_004F53E0, cStopSoundMsg_NetStopSoundMsgCallback)
static inline void merge_flush_func_0020E950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E950 */
