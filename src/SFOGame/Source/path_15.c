/*
 * SFOGame/Source/path: 1 file, 0015FF90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015FF90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Calls two helpers with the same arguments.
 */

#include "types.h"
#include "path_types.h"

extern int cPathNavigator_ResolvePathAfterTeleport(void* a0, int a1);
extern void cPathNavigator_SetNodeIndex(void* a0, int a1);

void cPathNavigator_AdjustPathForTeleport(void* a0, int a1) {
    cPathNavigator_ResolvePathAfterTeleport(a0, a1);
    cPathNavigator_SetNodeIndex(a0, a1);
}
static inline void merge_flush_func_0015FF90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015FF90 */
