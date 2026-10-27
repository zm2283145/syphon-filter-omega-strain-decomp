/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

Vec4* cVector_SetW(Vec4* v, float w) {
    v->w = w;
    return v;
}
