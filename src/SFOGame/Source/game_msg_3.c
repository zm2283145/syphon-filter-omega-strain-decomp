/*
 * SFOGame/Source/game_msg: 1 file, 0020E420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020E420 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { char a; int b; } Proto_0020E420;
extern char D_004F53A0[];
extern void cEndLevelMsg_NetEndLevelCallback(void);

NETREG_BEGIN(cEndLevelMsg_InitNet, Proto_0020E420)
NETREG_FIELD(a, 1, 1)
NETREG_FIELD(b, 4, 1)
NETREG_END(D_004F53A0, cEndLevelMsg_NetEndLevelCallback)
static inline void merge_flush_func_0020E420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E420 */
