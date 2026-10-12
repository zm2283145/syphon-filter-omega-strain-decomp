#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_4A20b { float v; float s; Key_4A20b() {} };
struct Crv_4A20b { Key_4A20b k[2]; float dur; float inv; };
/* two-key curve: keys (*v0, *s0 * dur) and (*v1, *s1 * dur), duration and inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_4A20b* func_00364A20(Crv_4A20b* c, float* v0, float* s0, float* v1, float* s1, float dur)
{
    float vs0; float vs1;
    vs1 = *s1 * dur; vs0 = *s0 * dur;
    { Key_4A20b* e = c->k; do { new (e) Key_4A20b; } while (++e != c->k + 2); }
    c->k[0].v = *v0;
    c->k[0].s = vs0;
    c->k[1].v = *v1;
    c->k[1].s = vs1;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
