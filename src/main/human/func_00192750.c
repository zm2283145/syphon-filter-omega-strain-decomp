#include "types.h"
typedef struct { float lo; float hi; unsigned char flag; } R_2750;
static inline float fmax_2750(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float fmin_2750(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline float Clamp_2750(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
/* set a [lo,hi] range and clamp it into [0,1] (flag: clamp both independently) */
R_2750* func_00192750(R_2750* r, float lo, float hi, unsigned char flag)
{
    r->lo = lo;
    r->hi = hi;
    r->flag = flag;
    if (r->flag) r->hi = Clamp_2750(r->hi, 0.0f, 1.0f); else r->hi = Clamp_2750(r->hi, r->lo, 1.0f);
    if (r->flag) r->lo = Clamp_2750(r->lo, 0.0f, 1.0f); else r->lo = Clamp_2750(r->lo, 0.0f, r->hi);
    return r;
}
