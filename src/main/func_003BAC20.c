#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies written as GCC-style volatile asm; the unused xx reproduces retail's dead addiu.
   The copy ctor splits lq and sq into two asm statements so the destination address is formed after the lq (as retail). */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float e) { x = a; y = b; z = c; w = e; }
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(q) : "r"(&o) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(this) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { __int128 q[4];
    M& operator=(const M& o) { void* xx = this; const void* s = &o; __int128 qa; __int128 qb; void* d = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct MN { __int128 q[4];
    MN& operator=(const M& o) { const void* s = &o; void* d = this; __int128 qa; __int128 qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct SkelNode {
    char pad00[0xC0];
    int fC0;
    MN mD0;
    M m110;
    unsigned char b150, b151; float f154; V v160; float f170;
    V v180, v190, v1A0, v1B0, v1C0;
};
extern "C" {
extern M D_0055C9F0;
extern signed char D_004E1D88;
extern V D_004E1D90;
void Xform_Construct(SkelNode* x);
}
static inline const V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D88 = 1;
        D_004E1D90.x = 0.0f;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
static inline V QZero()
{
    V t;
    __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&t) : "memory");
    return t;
}
extern "C" SkelNode* SkelNode_Construct(SkelNode* d)
{
    Xform_Construct(d);
    d->fC0 = 0;
    d->mD0 = D_0055C9F0;
    d->m110 = D_0055C9F0;
    d->b150 = 0;
    d->b151 = 1;
    d->f154 = 0.0f;
    d->v160 = Zero();
    d->f170 = 0.0f;
    d->v180 = Zero();
    d->v190 = V(0.0f, 0.0f, 0.0f, 0.0f);
    d->v1A0 = QZero();
    d->v1B0 = Zero();
    d->v1C0 = QZero();
    return d;
}

