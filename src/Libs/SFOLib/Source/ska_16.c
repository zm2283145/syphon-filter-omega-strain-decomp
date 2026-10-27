/*
 * Libs/SFOLib/Source/ska: 1 file, 003AE340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AE340 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Address of element i in an array of 32-byte elements. */
char* std_vector_cSkaPlaybackItem_opIndex(SkaVec* v, int i) {
    return v->data + (i << 5);
}
static inline void merge_flush_func_003AE340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE340 */
