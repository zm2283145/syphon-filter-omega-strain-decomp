/*
 * main/human: range (2 files, 001907B0-001907F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_001907B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001907B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001907B0 */

/* merge_units: begin func_001907F0 */
#pragma push /* merge_units */
typedef struct Quat {
    float x, y, z, w;
} Quat;

extern float Math_Cos(float); /* Math_Cos */
extern float Math_Sin(float); /* Math_Sin */

/* Builds a quaternion from an axis (xyz) and angle (w). */
Quat* Quat_FromYaw(Quat* q, Quat* axisAngle) {
    float half = 0.5f * axisAngle->w;
    float c;
    float s;
    c = Math_Cos(half); /* cos */
    s = Math_Sin(half); /* sin */
    q->w = c;
    q->x = s * axisAngle->x;
    q->y = s * axisAngle->y;
    q->z = s * axisAngle->z;
    return q;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001907F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001907F0 */
