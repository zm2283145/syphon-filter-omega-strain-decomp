/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Vec4* Vec4_SetZ(Vec4* v, float z) {
    v->z = z;
    return v;
}
