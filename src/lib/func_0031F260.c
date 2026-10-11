#include "types.h"
void func_0031F260(float* buf, float* tmp, float ratio)
{
    int i, j;
    if (ratio == 1.0f) return;
    for (i = 0; i < 65; i++) {
        j = (int)(i * ratio);
        tmp[i] = buf[j];
        tmp[i] = (j < 65) ? buf[j] : buf[64];
    }
    for (i = 0; i < 65; i++) buf[i] = tmp[i];
}