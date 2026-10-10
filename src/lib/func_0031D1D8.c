#include "types.h"
extern float func_00121B00(float);
extern float D_004E1BE8;
extern float D_004E1CF4;int func_0031D1D8(float x)
{
    float t;
    float y;
    if (!(x > 8.0f)) x = 8.0f;
    if (x > 160.0f) y = 160.0f; else y = x;
    t = (D_004E1BE8 - func_00121B00(y)) * D_004E1CF4;
    return (int)(t > 0.0f ? t + 0.5f : t - 0.5f);
}