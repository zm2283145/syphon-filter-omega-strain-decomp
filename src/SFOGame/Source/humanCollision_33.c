/*
 * SFOGame/Source/humanCollision: 1 file, 001ED7F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001ED7F0 */
#pragma push /* merge_units */
#include "types.h"

/* Stores the bitwise complement of *src into *dst (through stack temporaries); returns 0. */
int cBitArray_5_opCompl(int* dst, int* src)
{
    volatile int result;
    volatile int value;
    value = *src;
    result = ~value;
    *dst = result;
    return 0;
}
static inline void merge_flush_func_001ED7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED7F0 */
