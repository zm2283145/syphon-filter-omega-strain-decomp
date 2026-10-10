#include "types.h"
typedef struct { int pad0; float a; float b; float rate; int pad10; float damp; } AC_t;
static inline float AC_Max(float a, float b) {
    float r;
    asm { max.s r, a, b }
    return r;
}
void AngleCurve_UpdateRate(AC_t* p, float dt, float k) {
    float d = p->b - p->a;
    while (1) {
        if (d > 3.1415927f) d += -6.2831855f;
        else if (d < -3.1415927f) d += 6.2831855f;
        else break;
    }
    p->rate = k * d;
    p->rate *= AC_Max(0.0f, 1.0f - p->damp * dt);
}