/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Vec4 component accessors. */
float* cQuaternion_Z_void(Vec4* v) {
    return &v->z;
}

float* cQuaternion_Y_void(Vec4* v) {
    return &v->y;
}

float* cQuaternion_X_void(Vec4* v) {
    return &v->x;
}

float* cQuaternion_W_void(Vec4* v) {
    return &v->w;
}

float cQuaternion_Z_void_2(Vec4* v) {
    return v->z;
}

float cQuaternion_Y_void_2(Vec4* v) {
    return v->y;
}

float cQuaternion_X_void_2(Vec4* v) {
    return v->x;
}

float cQuaternion_W_void_2(Vec4* v) {
    return v->w;
}
