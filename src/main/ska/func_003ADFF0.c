#include "types.h"
typedef struct { char pad[0x20]; float a; float b; int pad28; int c; unsigned char d; unsigned char e; } XDFF0;
static inline float clamp_DFF0(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
#pragma opt_propagation off
void AnimGroup_ResetInactive(XDFF0* t) {
    float v = clamp_DFF0(0.0f, 0.0f, 1.0f);
    t->b = v;
    t->a = v;
    t->c = 0;
    t->d = 0;
    t->e = 0;
}
