#include "types.h"
void func_0031A960(float* in, float* out, int n, float x)
{
    float f = 1.0f;
    int i;
    for (i = 0; i <= n; i++) {
        *out++ = *in++ * f;
        f *= x;
    }
}
