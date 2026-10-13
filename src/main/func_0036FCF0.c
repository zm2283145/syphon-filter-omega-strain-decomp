#pragma cplusplus on
#include "types.h"
/* 64-byte lq/sq copy as GCC-style volatile asm; the unused `xx` reproduces retail's dead addiu */
struct M4 { __int128 r[4]; };
static inline void GQR(void* d, const void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
extern "C" {
extern char D_004DF6A0[];
extern char D_004DF640[];
}
struct R { int a, b, c; unsigned char own; };
extern "C" R* func_0036FCD0(R* r);
struct XBase {
    void* vt;
    char pad04[0xC];
    M4 m;
    unsigned char dirty;
};
struct X : XBase {
    M4 w;
    int a0;
    R rel;
};
extern "C" X* func_0036FCF0(X* x0, M4* m)
{
    R* r;
    X* x = x0;
    M4* d2; M4* d;
    x->vt = D_004DF6A0;
    d = &x->m; GQR(d, m);
    x->dirty = 1;
    x->vt = D_004DF640;
    void* xx = &x->w; /* dead on purpose: retail keeps this addiu */
    d2 = &x->w; GQR(d2, m);
    x->a0 = 0;
    r = &x->rel; func_0036FCD0(r); r->own = 1;
    return x;
}

