/*
 * SFOGame/Source/humanCollision: 1 file, 001ED7B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001ED7B0 */
#pragma push /* merge_units */
#include "types.h"
int cBitArray_5_opEq(int* a, int* b)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}
static inline void merge_flush_func_001ED7B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED7B0 */
