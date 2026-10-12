#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
union V4_29A0 { float f[4]; __int128 q; };
struct E_29A0 { V4_29A0 p; V4_29A0 q; E_29A0() {} };
struct M_29A0 { E_29A0 e[2]; };
/* Two-element array of quad pairs built from four vectors (by pointer).
   The quad copies keep retail's unfolded addresses with the peephole off. */
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" M_29A0* func_001CF4C0(M_29A0* m, const V4_29A0* a, const V4_29A0* b, const V4_29A0* c, const V4_29A0* d)
{
    { E_29A0* e = m->e; E_29A0* end = m->e + 2; do { new (e) E_29A0; } while (++e != end); }
    E_29A0* e1 = &m->e[1];
    V4_29A0* q0 = &m->e[0].q;
    V4_29A0* p1 = &m->e[1].p;
    V4_29A0* q1 = &e1->q;
    m->e[0].p.q = a->q;
    q0->q = b->q;
    p1->q = c->q;
    q1->q = d->q;

    return m;
}
