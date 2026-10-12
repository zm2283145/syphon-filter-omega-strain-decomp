#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_F480 { float v; float s; Key_F480() {} };
struct Crv_F480 { Key_F480 k[2]; float dur; float inv; };
static inline Crv_F480* Init_F480(Crv_F480* c, float* a, float* b, float dur)
{
    float va = *a; float vs = *b * dur;
    { Key_F480* e = c->k; do { new (e) Key_F480; } while (++e != c->k + 2); }
    c->k[0].v = va;
    c->k[0].s = vs;
    c->k[1].v = va;
    c->k[1].s = vs;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
struct Phys_F480 { void* vt; float a; float b; float c; float d; int x14; Crv_F480 crv; Crv_F480* cur; int x34; };
extern "C" char D_004DA380[];
/* constructor: vtable, initial values from a/b, an inline constant curve (zero duration) */
#pragma push
#pragma opt_unroll_loops off
extern "C" Phys_F480* PhysicalBase_Construct(Phys_F480* p, float* a, float* b)
{
    p->vt = D_004DA380;
    p->a = *a;
    p->b = *a;
    p->c = *b;
    p->d = *a;
    p->x14 = 0;
    {
        Crv_F480* c = &p->crv;
        Init_F480(c, a, b, 0.0f);
    }
    p->cur = &p->crv;
    p->x34 = 0;
    return p;
}
#pragma pop
