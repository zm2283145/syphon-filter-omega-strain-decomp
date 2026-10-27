/*
 * SFOGame/Source/humanCollision: 1 file, 001ED8A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001ED8A0 */
#pragma push /* merge_units */
#include "types.h"

/* Writes the bitwise complement of *src to *dst; returns 0. */
int cBitArray_19_opCompl(int* dst, int* src) {
    volatile int inverted;
    volatile int value;
    value = *src;
    inverted = ~value;
    *dst = inverted;
    return 0;
}
static inline void merge_flush_func_001ED8A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED8A0 */
