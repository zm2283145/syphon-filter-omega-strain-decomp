/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int std_vector_pod_int_ctor(ObjVec*, ObjVec*);

/* Array copy constructor: copy contents, then the owns-storage flag. */
ObjVec* cEdgeGroup_ctor_cEdgeGroupR(ObjVec* dst, ObjVec* src) {
    std_vector_pod_int_ctor(dst, src);
    dst->owned = src->owned;
    return dst;
}
