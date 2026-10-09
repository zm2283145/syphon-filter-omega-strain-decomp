/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Vec3f* func_0027FF60(Vec3f* dst, Vec3f* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}

float func_0027FF80(Vec3f* v) {
    return v->z;
}

float* func_0027FF90(Vec3f* v) {
    return &v->z;
}

float func_0027FFA0(Vec3f* v) {
    return v->y;
}

float* func_0027FFB0(Vec3f* v) {
    return &v->y;
}
