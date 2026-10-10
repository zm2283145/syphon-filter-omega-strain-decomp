#include "types.h"
extern float func_001207E8(float x, float y, int iy);
extern float Math_CosKernel(float x, float y);
extern int func_0011E950(float x, float* y);
float Math_Sin(float x)
{
    float y[2];
    float z = 0.0f;
    int n, ix;
    do { union { float value; int word; } gf_u; gf_u.value = x; ix = gf_u.word; } while (0); ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8) return func_001207E8(x, z, 0);
    n = func_0011E950(x, y);
    switch (n & 3) {
    case 0: return func_001207E8(y[0], y[1], 1);
    case 1: return Math_CosKernel(y[0], y[1]);
    case 2: return -func_001207E8(y[0], y[1], 1);
    default: return -Math_CosKernel(y[0], y[1]);
    }
}