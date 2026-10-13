#include "types.h"

extern void Object_AttachTransform(void* self, float* m, int a, int b);
extern void func_003CDF20(void* self);

void func_00394850(void* self, float* m, int a, int b)
{
    int r = m[0] == 1.0f && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f &&
            m[4] == 0.0f && m[5] == 1.0f && m[6] == 0.0f && m[7] == 0.0f &&
            m[8] == 0.0f && m[9] == 0.0f && m[10] == 1.0f && m[11] == 0.0f &&
            m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f && m[15] == 1.0f;
    if (!r) Object_AttachTransform(self, m, a, b);
    else func_003CDF20(self);
}

