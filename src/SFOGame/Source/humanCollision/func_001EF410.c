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
