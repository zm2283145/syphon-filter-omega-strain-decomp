#include "types.h"
void func_0031F0A0(float* k, float* p)
{
    float tmp[16];
    float *q, *t;
    int i, j;
    q = tmp;
    p[0] = 1.0f;
    for (i = 0; i < 12; i++) {
        float ki = k[i];
        t = p; p = q; q = t;
        p[i + 1] = -ki;
        for (j = 1; j <= i; j++) p[j] = q[j] - ki * q[i + 1 - j];
    }
}