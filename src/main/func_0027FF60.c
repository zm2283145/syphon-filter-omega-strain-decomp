/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Vec3f* cEulerAngle_T_1_2_ctor_cEulerAngleTR(Vec3f* dst, Vec3f* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}

float cEulerAngle_T_1_2_Z_void(Vec3f* v) {
    return v->z;
}

float* cEulerAngle_T_1_2_Z_void_2(Vec3f* v) {
    return &v->z;
}

float cEulerAngle_T_1_2_Y_void(Vec3f* v) {
    return v->y;
}

float* cEulerAngle_T_1_2_Y_void_2(Vec3f* v) {
    return &v->y;
}
