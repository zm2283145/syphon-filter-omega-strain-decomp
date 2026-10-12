#pragma cplusplus on
#include "types.h"
struct C0041C070 { float r, g, b, a; };
struct Q0041C070 { __int128 q; };
struct W0041C070 { char p[0x60]; C0041C070 c; char p70[8]; void* h; };
extern "C" void func_003D0810(void* h, C0041C070* c);
static inline void Set0041C070(C0041C070* d, const C0041C070& s) { d->r = s.r; d->g = s.g; d->b = s.b; d->a = s.a; }
extern "C" void func_0041C070(W0041C070* w, Q0041C070* in)
{
    Q0041C070 t = *in;
    Set0041C070(&w->c, *(C0041C070*)&t);
    if (w->h) func_003D0810(w->h, &w->c);
}
