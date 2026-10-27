/*
 * Libs/SFOLib/Source/NetTerrainActivation: 1 file, 00431E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00431E00 */
#pragma push /* merge_units */
#include "types.h"
#include "net_register_type.h"

typedef struct { short a; short b; } Proto_0020E420;
extern char D_00582758[];
extern void cNetTerrainActivation_NetTerrainActivationCallback(void);

NETREG_BEGIN(cNetTerrainActivation_InitNet, Proto_0020E420)
NETREG_FIELD(b, 2, 1)
NETREG_FIELD(a, 2, 1)
NETREG_END(D_00582758, cNetTerrainActivation_NetTerrainActivationCallback)
static inline void merge_flush_func_00431E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00431E00 */
