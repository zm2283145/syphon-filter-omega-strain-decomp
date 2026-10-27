#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_F3E0 { float v; float s; Key_F3E0() {} };
struct Crv_F3E0 { Key_F3E0 k[2]; float dur; float inv; };
/* constant curve: both keys = (*a, *b * dur), store duration and its inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_F3E0* cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(Crv_F3E0* c, float* a, float* b, float dur)
{
    float va = *a; float vs = *b * dur;
    { Key_F3E0* e = c->k; do { new (e) Key_F3E0; } while (++e != c->k + 2); }
    c->k[0].v = va;
    c->k[0].s = vs;
    c->k[1].v = va;
    c->k[1].s = vs;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
