#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_3810b { float v; float s; Key_3810b() {} };
struct Crv_3810b { Key_3810b k[2]; float dur; float inv; };
/* constant curve: both keys = (*a, *b * dur), store duration and its inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_3810b* func_00363810(Crv_3810b* c, float* a, float* b, float dur)
{
    float va = *a; float vs = *b * dur;
    { Key_3810b* e = c->k; do { new (e) Key_3810b; } while (++e != c->k + 2); }
    c->k[0].v = va;
    c->k[0].s = vs;
    c->k[1].v = va;
    c->k[1].s = vs;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
