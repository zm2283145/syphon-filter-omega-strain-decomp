#include "types.h"
typedef struct { float a; float b; unsigned char c; } S_1AE020;
static inline float clamp_1AE020(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
S_1AE020* func_001AE020(S_1AE020* s, unsigned char c, float x)
{
    float v;
    s->c = c;
    v = clamp_1AE020(x, 0.0f, 1.0f);
    s->b = v;
    s->a = v;
    return s;
}
