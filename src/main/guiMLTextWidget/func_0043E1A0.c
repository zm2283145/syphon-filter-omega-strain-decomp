#pragma cplusplus on
#include "types.h"
struct C0043E1A0 { float r, g, b, a; };
struct Q0043E1A0 { __int128 q; };
struct W0043E1A0 { char p[0x48]; void* h; char p4C[4]; C0043E1A0 c; };
extern "C" void func_003D0810(void* h, C0043E1A0* c);
static inline void Set0043E1A0(C0043E1A0* d, const C0043E1A0& s) { d->r = s.r; d->g = s.g; d->b = s.b; d->a = s.a; }
extern "C" void func_0043E1A0(W0043E1A0* w, Q0043E1A0* in)
{
    Q0043E1A0 t = *in;
    Set0043E1A0(&w->c, *(C0043E1A0*)&t);
    if (w->h) func_003D0810(w->h, &w->c);
}
