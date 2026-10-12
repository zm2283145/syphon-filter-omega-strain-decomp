/* Curve_ComputeRates: rate = (b - a) * k; rate *= max(0, 1 - damp * dt). Hand-matched (auto1 family seed).
 * The empty `.set noreorder/.set reorder` asm blocks are scheduling barriers that reproduce retail instruction order. */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x10]; V4 a; V4 b; V4 rate; char pad40[0x10]; float damp; } CR_t;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline float CR_Max(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
void Curve_ComputeRates(CR_t* c, float dt, float k) {
    V4 u; V4 t; V4 s; V4 d; V4* q;
    {
        V4* q = &d; V4* x = &c->b; V4* y;
        asm { .set noreorder; .set reorder }
        y = &c->a;
        asm { lqc2 vf1, 0x0(x); lqc2 vf2, 0x0(y); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(q) }
    }
    {
        __int128 tt = 0; V4* p; V4* ss = &d; V4* dd = &t;
        *dd = *ss; p = &t; q = &s;
        asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, k; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
    }
    {
        V4* d2; V4* ss; V4* d1 = &u;
        asm { .set noreorder; .set reorder }
        *d1 = *q; ss = &u; d2 = &c->rate; *d2 = *ss;
    }
    {
        float f = CR_Max(0.0f, 1.0f - c->damp * dt); __int128 tt = 0; V4* q = &c->rate; V4* p = &c->rate;
        asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, f; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
    }
}
#pragma pop
