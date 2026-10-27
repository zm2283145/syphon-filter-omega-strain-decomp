/*
 * SFOGame/Source/humanCollision: 1 file, 001EF410
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EF410 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern ObjVec* std_vector_imp_cCollisionEdgePtr_1_opAssign(ObjVec*, ObjVec*);

/* Array copy constructor: copy contents, then the owns-storage flag. */
ObjVec* cArray_cCollisionEdgePtr_opAssign(ObjVec* dst, ObjVec* src) {
    std_vector_imp_cCollisionEdgePtr_1_opAssign(dst, src);
    dst->owned = src->owned;
    return dst;
}
static inline void merge_flush_func_001EF410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF410 */
