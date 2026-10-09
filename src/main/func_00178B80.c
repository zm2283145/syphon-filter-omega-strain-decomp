/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Build a Vec4 from an xyz vector and w. */
Vec4* Vec4_SetFromVec3W(Vec4* d, Vec4* xyz, float w) {
    d->x = xyz->x;
    d->y = xyz->y;
    d->z = xyz->z;
    d->w = w;
    return d;
}
