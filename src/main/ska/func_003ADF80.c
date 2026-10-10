#include "types.h"
typedef struct { float prev; float max; unsigned char unitBounds; } D6Phase;
static inline float d6_clamp(float x, float lo, float hi) { asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }
static inline float d6_clampr(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
void AnimPhase_SetPrevious(D6Phase* p, float v)
{
    p->prev = v;
    if (p->unitBounds) {
        p->prev = d6_clamp(p->prev, 0.0f, 1.0f);
    } else {
        p->prev = d6_clampr(p->prev, 0.0f, p->max);
    }
}