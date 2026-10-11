#include "types.h"
extern float D_0048A2A8;
extern float D_0048A2B0;
float func_00188D30(void* self, int n)
{
    int k = n & 3;
    if (k == 0) return D_0048A2A8;
    if (k == 1 || k == 2) return D_0048A2B0;
    return 1.0f;
}
