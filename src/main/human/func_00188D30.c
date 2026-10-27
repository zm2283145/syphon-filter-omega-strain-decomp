#include "types.h"
const float D_0048A2A8[2] = { 0.3f, 0.0f };
const float D_0048A2B0[2] = { 0.5f, 0.0f };
float cHuman_GetSubTargetAimAdjust(void* self, int n)
{
    int k = n & 3;
    if (k == 0) return (*(float*)D_0048A2A8);
    if (k == 1 || k == 2) return (*(float*)D_0048A2B0);
    return 1.0f;
}
