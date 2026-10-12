#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_5010b { float v; float s; Key_5010b() {} };
struct Crv_5010b { Key_5010b k[2]; float dur; float inv; };
/* rebuild a two-key segment in place, keeping its duration */
#pragma push
#pragma opt_unroll_loops off
static inline Crv_5010b* Init_5010b(Crv_5010b* c, float* v0, float* s0, float* v1, float* s1, float dur)
{
    float vs0; float vs1;
    vs1 = *s1 * dur; vs0 = *s0 * dur;
    { Key_5010b* e = c->k; do { new (e) Key_5010b; } while (++e != c->k + 2); }
    c->k[0].v = *v0;
    c->k[0].s = vs0;
    c->k[1].v = *v1;
    c->k[1].s = vs1;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
extern "C" void func_00365010(Crv_5010b* c, float* v0, float* s0, float* v1, float* s1)
{
    if (c) Init_5010b(c, v0, s0, v1, s1, c->dur);
}
#pragma pop
