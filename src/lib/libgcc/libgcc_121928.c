/*
 * lib/libgcc: 6 files, 00121928-00121AD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00121928 */
#include "types.h"
extern float Math_SinKernel(float x, float y, int iy);
extern float Math_CosKernel(float x, float y);
extern int Math_RemPio2(float x, float* y);
float Math_Sin(float x)
{
    float y[2];
    float z = 0.0f;
    int n, ix;
    do { union { float value; int word; } gf_u; gf_u.value = x; ix = gf_u.word; } while (0); ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8) return Math_SinKernel(x, z, 0);
    n = Math_RemPio2(x, y);
    switch (n & 3) {
    case 0: return Math_SinKernel(y[0], y[1], 1);
    case 1: return Math_CosKernel(y[0], y[1]);
    case 2: return -Math_SinKernel(y[0], y[1], 1);
    default: return -Math_CosKernel(y[0], y[1]);
    }
}
/* merge_units: end func_00121928 */

/* merge_units: begin func_00121A10 */
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
extern float Math_TanKernel(float x, float y, int k);
float Math_Tan(float x) { float y[2], z = 0.0f; int n, ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix <= 0x3f490fda) return Math_TanKernel(x, z, 1); else { n = Math_RemPio2(x, y); return Math_TanKernel(y[0], y[1], 1 - ((n & 1) << 1)); } }
/* merge_units: end func_00121A10 */

/* merge_units: begin func_00121A88 */
extern int Math_AcosKernel(float);

int Math_Acos(float f12) {
    return Math_AcosKernel(f12);
}
/* merge_units: end func_00121A88 */

/* merge_units: begin func_00121AA0 */
extern int Math_AsinfImpl(float);

int Math_Asinf(float f12) {
    return Math_AsinfImpl(f12);
}
/* merge_units: end func_00121AA0 */

/* merge_units: begin func_00121AB8 */
extern int Math_Atan2Kernel(float, float);

int Math_Atan2f(float f12, float f13) {
    return Math_Atan2Kernel(f12, f13);
}
/* merge_units: end func_00121AB8 */

/* merge_units: begin func_00121AD0 */
extern int func_0011D980(float);

int func_00121AD0(float f12) {
    return func_0011D980(f12);
}
/* merge_units: end func_00121AD0 */
