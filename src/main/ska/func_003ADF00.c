#include "types.h"
typedef struct {
    float start;
    float cur;
    unsigned char clamp01;
} AnimPhase_3ADF00;
static inline float clamp_3ADF00(float x, float lo, float hi) {
    asm {
        max.s lo, x, lo
        min.s lo, lo, hi
    }
    return lo;
}
void AnimPhase_SetCurrent(AnimPhase_3ADF00* p, float t) {
    p->cur = t;
    if (p->clamp01)
        p->cur = clamp_3ADF00(p->cur, 0.0f, 1.0f);
    else
        p->cur = clamp_3ADF00(p->cur, p->start, 1.0f);
}