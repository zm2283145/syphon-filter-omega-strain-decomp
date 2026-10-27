#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 q; __asm__ ("lq %0, 0x0(%1)" : "=r"(q) : "r"(&o)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(this) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct W {
    float x, y, z, w;
    W() {}
    W& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" signed char D_004E1D88;
extern "C" V D_004E1D90;
static inline const V& GetZero() {
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
static inline V Zero() { V r; __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&r) : "memory"); return r; }
struct Base { char pad[0xA4]; } __attribute__((aligned(16)));
static inline void Fill(W* a, const V& z) { for (int i = 0; i <= 3; i++) a[i] = z; }
struct AnimRoot {
    char base[0xD0];
    float d0;
    V vE0;
    V vF0;
    float f100;
    W m110[4];
    int pad150[4];
    int f160;
    int f164;
};
extern "C" Base* cSkaAnimAnchor_TreeNodeData_ctor_void(Base* b);
extern "C" void cTreeNode_cSkaAnimAnchor_TreeNodeData_ctor(AnimRoot* d, Base* s);
static inline void InitB(AnimRoot* self) { Base t; cTreeNode_cSkaAnimAnchor_TreeNodeData_ctor(self, cSkaAnimAnchor_TreeNodeData_ctor_void(&t)); }
static inline void InitB2(AnimRoot* self) { InitB(self); }
extern "C" AnimRoot* cSkaAnimAnchor_ctor(AnimRoot* self)
{
    InitB2(self);
    self->d0 = 0.0f;
    V vt = Zero();
    self->vE0 = vt;
    self->vF0 = GetZero();
    self->f100 = 0.0f;
    {
        const V& z = GetZero();
        { W* p = self->m110; do { ++p; } while (p != self->m110 + 4); }
        Fill(self->m110, z);
    }
    self->f160 = 0;
    self->f164 = 0;
    return self;
}

