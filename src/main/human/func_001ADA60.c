/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Copy xyz from src and set w. */
Vec4* Vec4_SetXYZ_W(Vec4* dst, Vec4* src, float w) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = w;
    return dst;
}
