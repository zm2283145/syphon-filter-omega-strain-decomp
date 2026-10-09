/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Vec4 component accessors. */
float* func_001CF5E0(Vec4* v) {
    return &v->z;
}

float* func_001CF5F0(Vec4* v) {
    return &v->y;
}

float* func_001CF600(Vec4* v) {
    return &v->x;
}

float* func_001CF610(Vec4* v) {
    return &v->w;
}

float func_001CF620(Vec4* v) {
    return v->z;
}

float func_001CF630(Vec4* v) {
    return v->y;
}

float func_001CF640(Vec4* v) {
    return v->x;
}

float func_001CF650(Vec4* v) {
    return v->w;
}
