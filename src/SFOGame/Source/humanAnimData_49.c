/*
 * SFOGame/Source/humanAnimData: 1 file, 001F44B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F44B0 */
#pragma push /* merge_units */
#include "types.h"

extern void std_list_cSkaBlendSequenceItemPtr_ctor(void* self);

#pragma optimization_level 1
/* Calls std_list_cSkaBlendSequenceItemPtr_ctor on self and returns self (unit built at -O1). */
void* cLList_cSkaBlendSequenceItemPtr_ctor(void* self)
{
    std_list_cSkaBlendSequenceItemPtr_ctor(self);
    return self;
}
#pragma optimization_level reset
static inline void merge_flush_func_001F44B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F44B0 */
