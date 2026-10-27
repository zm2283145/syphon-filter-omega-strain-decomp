/*
 * lib/libgcc: 12 files, 00121860-00121B00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin libgcc_121860 */
#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern float func_00121648(float x, float y);
float scalbnf(float x, int n)
{
    const float huge = 1.0e+30, tiny = 1.0e-30;
    int k, ix;
    unsigned int hx;
    GET_FLOAT_WORD(ix, x);
    hx = ix & 0x7fffffff;
    k = hx >> 23;
    if (hx < 0x00800000L) return x;
    k = k + n;
    if (k > 0xff) return huge * func_00121648(huge, x);
    if (k > 0) { SET_FLOAT_WORD(x, (ix & 0x807fffff) | (k << 23)); return x; }
    if (n > 50000) return huge * func_00121648(huge, x);
    else return tiny * func_00121648(tiny, x);
}
/* merge_units: end libgcc_121860 */

/* merge_units: begin func_00121928 */
extern float Math_SinKernel(float x, float y, int iy);
extern float Math_CosKernel(float x, float y);
extern int Math_RemPio2(float x, float* y);
float Libc_Sinf(float x)
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
extern float Math_TanKernel(float x, float y, int k);
float Libc_Tanf(float x) { float y[2], z = 0.0f; int n, ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix <= 0x3f490fda) return Math_TanKernel(x, z, 1); else { n = Math_RemPio2(x, y); return Math_TanKernel(y[0], y[1], 1 - ((n & 1) << 1)); } }
/* merge_units: end func_00121A10 */

/* merge_units: begin func_00121A88 */
extern int Math_AcosKernel(float);

int Math_Acos(float f12) {
    return Math_AcosKernel(f12);
}
/* merge_units: end func_00121A88 */

/* merge_units: begin func_00121AA0 */
extern int Math_AsinfImpl(float);

int Libc_Asinf(float f12) {
    return Math_AsinfImpl(f12);
}
/* merge_units: end func_00121AA0 */

/* merge_units: begin func_00121AB8 */
extern int Math_Atan2Kernel(float, float);

int Libc_Atan2f(float f12, float f13) {
    return Math_Atan2Kernel(f12, f13);
}
/* merge_units: end func_00121AB8 */

/* merge_units: begin func_00121AD0 */
extern int func_0011D980(float);

int Libc_Expf(float f12) {
    return func_0011D980(f12);
}
/* merge_units: end func_00121AD0 */

/* merge_units: begin libgcc_121AE8 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Math_FModImpl();                                  

void Libc_Fmodf(void) {
    Math_FModImpl();
}
/* merge_units: end libgcc_121AE8 */

/* merge_units: begin func_00121B00 */
extern int func_0011DDA8(float);

int Libc_Logf(float f12) {
    return func_0011DDA8(f12);
}
/* merge_units: end func_00121B00 */

/* merge_units: begin func_00121B18 */
extern int func_0011E088(float);

int Libc_Log10f(float f12) {
    return func_0011E088(f12);
}
/* merge_units: end func_00121B18 */

/* merge_units: begin func_00121B30 */
extern int Math_PowfKernel(float, float);

int Libc_Powf(float f12, float f13) {
    return Math_PowfKernel(f12, f13);
}
/* merge_units: end func_00121B30 */

/* merge_units: begin func_00121B48 */
extern int Math_Sqrtf(float);

int Libc_Sqrtf(float f12) {
    return Math_Sqrtf(f12);
}
/* merge_units: end func_00121B48 */
