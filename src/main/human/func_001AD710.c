#pragma cplusplus on
#include "types.h"

/* 16-byte member with an inline lq/sq assignment (gcc-style asm keeps the copy unfolded). */
struct QV7 {
    float x, y, z, w;
    QV7& operator=(const QV7& o)
    {
        const QV7* src = &o;
        QV7* dst = this;
        __int128 t;
        __asm__ volatile("lq %0,0(%1)" : "=r"(t) : "r"(src));
        __asm__ volatile("sq %0,0(%1)" : : "r"(t), "r"(dst) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct SA7 { int a; int b; int pad[2]; QV7 c; QV7 e; };

extern "C" SA7* cInteractParams_ctor_cInteractParamsR(SA7* d, const SA7* s)
{
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->e = s->e;
    return d;
}

