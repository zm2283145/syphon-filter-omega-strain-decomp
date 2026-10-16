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

struct SB7 { float x, y, z; int pad; QV7 c; QV7 e; };

extern "C" SB7* func_001D7CE0(SB7* d, const SB7* s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
    d->c = s->c;
    d->e = s->e;
    return d;
}

