#include "types.h"
typedef struct { char pad[0x324]; float a; float b; } S1CA7D0;
void func_001CA7D0(S1CA7D0* p, float a, float b)
{
    p->a = a;
    if (b <= 4.0f) {
        p->b = 0.0f;
    } else {
        p->b = b;
        p->b = b - -30.0f;
        p->b *= 0.018027762f;
        {
            float v = p->b;
            float lo = 0.0f;
            float hi = 1.0f;
            asm {
                max.s v, v, lo
                min.s v, v, hi
            }
            p->b = v;
        }
    }
}