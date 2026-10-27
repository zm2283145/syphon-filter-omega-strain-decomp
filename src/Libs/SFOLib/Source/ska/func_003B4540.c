#pragma cplusplus on
#include "types.h"
extern "C" char D_004DFC50[];
extern void * const D_004DFC30[];
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V Unit() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
struct ClipHdr { int f0; unsigned int n4; int f8; float fC; void* p10; };
struct SkaClip {
    void* vt;
    unsigned char b4;
    V v10;
    int f20;
    ClipHdr* clip;
    unsigned char b28, b29;
    float f2c, f30, f34, f38;
    float f3c;
    int f40;
    unsigned char b44, b45, b46;
};
extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimDataR(SkaClip* self, ClipHdr* c)
{
    V t = Unit();
    self->vt = D_004DFC50;
    self->b4 = 0;
    self->v10 = t;
    self->vt = (void*)D_004DFC30;
    self->f20 = 0;
    self->clip = c;
    self->b28 = 0;
    self->b29 = 0;
    self->f2c = 0.0f;
    self->f30 = 1.0f;
    self->f34 = 0.0f;
    self->f38 = 1.0f;
    { ClipHdr* h = self->clip; self->f3c = (float)h->n4 * h->fC; }
    self->f40 = -1;
    self->b44 = 0;
    self->b45 = c->p10 != 0;
    self->b46 = 0;
    return self;
}


