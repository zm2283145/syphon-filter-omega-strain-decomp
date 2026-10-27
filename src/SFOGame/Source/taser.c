/*
 * SFOGame/Source/taser: 1 file, 002629C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002629C0 */
#pragma push /* merge_units */
#include "types.h"
extern int D_004F8354;
extern void** D_004F8358;
extern void cAirTaser_Render(void* p);
#pragma push
#pragma opt_strength_reduction off
void cAirTaser_RenderAll(void)
{
    int i;
    for (i = 0; i < D_004F8354; i++) cAirTaser_Render(D_004F8358[i]);
}
#pragma pop
static inline void merge_flush_func_002629C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002629C0 */
