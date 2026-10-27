/*
 * SFOGame/Source/playerCamera: 3 files, 0027FF60-00280040
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027FF60 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0027FF60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027FF60 */

/* merge_units: begin func_0027FFC0 */
#pragma push /* merge_units */
float nSFOMath_ExpressAngleAsValueBetweenNegAndPos180_float(float a) {
    for (;;) {
        if (a > 3.1415927f) {
            a += -6.2831855f;
        } else if (a < -3.1415927f) {
            a += 6.2831855f;
        } else {
            return a;
        }
    }
}
static inline void merge_flush_func_0027FFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027FFC0 */

/* merge_units: begin func_00280040 */
#pragma push /* merge_units */
float cEulerAngle_T_1_2_X_void(char* self) {
    return *(float*)(self + 0);
}

void* cEulerAngle_T_1_2_X_void_2(void* self) {
    return self;
}

void* cEulerAngle_T_1_2_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_00280040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280040 */
