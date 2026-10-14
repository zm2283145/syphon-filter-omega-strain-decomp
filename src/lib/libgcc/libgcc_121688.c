#include "types.h"
typedef union { float value; unsigned int word; } ieee_float_shape_type;
extern float Math_CosKernel(float x, float y);
extern float Math_SinKernel(float x, float y, int iy);
extern int Math_RemPio2(float x, float* y);
float Math_Cos(float x) {
    float y[2], z = 0.0f;
    int n, ix;
    do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8) return Math_CosKernel(x, z);
    else if (!1) return x - x;
    else {
        n = Math_RemPio2(x, y);
        switch (n & 3) {
        case 0: return Math_CosKernel(y[0], y[1]);
        case 1: return -Math_SinKernel(y[0], y[1], 1);
        case 2: return -Math_CosKernel(y[0], y[1]);
        default: return Math_SinKernel(y[0], y[1], 1);
        }
    }
}