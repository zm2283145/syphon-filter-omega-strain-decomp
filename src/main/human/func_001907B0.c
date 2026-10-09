/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

void* func_001907B0(char* self) {
    return self + 48;
}

Vec4* func_001907C0(Vec4* dst, Vec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}
