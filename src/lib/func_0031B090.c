#include "types.h"
void func_0031B090(float* k, float* a, int n)
{
    float tmp[20];
    float *p, *q, *t;
    int i, j;
    a[0] = 1.0f;
    if (n & 1) { q = a; p = tmp; } else { q = tmp; p = a; }
    for (i = 0; i < n; i++) {
        float ki = k[i];
        t = p; p = q; q = t;
        p[i + 1] = -ki;
        for (j = 1; j <= i; j++) p[j] = q[j] - ki * q[i + 1 - j];
    }
}