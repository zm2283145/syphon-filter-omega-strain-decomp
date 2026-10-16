#include "types.h"

extern float func_003182E0(void* a0, float* a1, float* a2);
extern float func_003182C8(void* a0, float* a1);
extern float func_003182F0(void* a0, float* a1);

void func_003181D0(void* a0, float* out, float* f)
{
    float k = 8000.0f;
    register float lo asm("$f21") = 50.0f;
    float hi = 1000.0f;
    float r;

    if (*(unsigned short*)((char*)a0 + 0x2C) != 0) {
        *out = func_003182E0(a0, out, f);
        return;
    }
    if (*(unsigned short*)((char*)a0 + 0x2A) != 0) {
        *f = k / *f;
        r = func_003182C8(a0, f);
    } else {
        *f = k / *f;
        r = func_003182F0(a0, f);
    }
    *f = r;
    if (r < lo) *f = lo;
    if (hi < *f) *f = hi;
    *f = k / *f;
}
