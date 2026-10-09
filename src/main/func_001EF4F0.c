/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int func_001C5370(ObjVec*, ObjVec*);

/* Array copy constructor: copy contents, then the owns-storage flag. */
ObjVec* func_001EF4F0(ObjVec* dst, ObjVec* src) {
    func_001C5370(dst, src);
    dst->owned = src->owned;
    return dst;
}
