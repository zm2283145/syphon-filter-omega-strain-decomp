/*
 * SFOGame/Source/humanCollision: 1 file, 001EB960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EB960 */
#pragma push /* merge_units */
#include "types.h"
#include "humanCollision_types.h"

/* Mask constructor: all bits set when all == 1, else none. */
HumanColMask* cBitArray_5_ctor_bool(HumanColMask* m, unsigned char all) {
    if (all == 1) {
        m->bits = -1;
    } else {
        m->bits = 0;
    }
    return m;
}
static inline void merge_flush_func_001EB960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB960 */
