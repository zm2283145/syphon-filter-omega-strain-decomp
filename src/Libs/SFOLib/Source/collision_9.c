/*
 * Libs/SFOLib/Source/collision: 1 file, 003BFFF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BFFF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Inserts count copies of *value at pos (vector insert). */
extern int std_vector_imp_cCollisionFace_insert(Vec112* v, Elem112* pos, int count, Elem112* value);

/* push_back: insert one element at the end. */
int func_003BFFF0(Vec112* v, Elem112* value) {
    return std_vector_imp_cCollisionFace_insert(v, &v->data[v->count], 1, value);
}
static inline void merge_flush_func_003BFFF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BFFF0 */
