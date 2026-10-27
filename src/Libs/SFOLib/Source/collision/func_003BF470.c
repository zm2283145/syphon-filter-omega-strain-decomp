#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void QF470(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
typedef struct { signed char hit; char pad[0xF]; V4 a; V4 b; V4 c; V4 d; V4 e; V4 f; } LosResult;
typedef struct { signed char hit; char pad[0xF]; V4 p; V4 n; V4 t; V4 r; V4 q; } LosHit;
extern void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(LosResult* r, void* x, V4* a, V4* b, int k, float f0, float f1, float f2, float f3, float f4);
void Los_CombineResult(LosResult* r, LosHit* h, void* x)
{
    cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(r, x, &h->q, &h->r, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    r->hit = h->hit;
    QF470(&r->a, &h->p);
    { void* xx = &r->b; }
    QF470(&r->b, &h->p);
    { void* xx = &r->c; }
    QF470(&r->c, &h->p);
    { void* xx = &r->d; }
    QF470(&r->d, &h->n);
    { void* xx = &r->e; }
    QF470(&r->e, &h->n);
    QF470(&r->f, &h->t);
}
