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


void* cSkaAnimDataSample_Rotation(char* self) {
    return self + 48;
}

Vec4* cQuaternion_ctor_floatP(Vec4* dst, Vec4* src) {
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

extern float Libc_Cosf(float); /* Libc_Cosf */
extern float Libc_Sinf(float); /* Libc_Sinf */

/* Builds a quaternion from an axis (xyz) and angle (w). */
Quat* cQuaternion_ctor_cAxisAngleR(Quat* q, Quat* axisAngle) {
    float half = 0.5f * axisAngle->w;
    float c;
    float s;
    c = Libc_Cosf(half); /* cos */
    s = Libc_Sinf(half); /* sin */
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
