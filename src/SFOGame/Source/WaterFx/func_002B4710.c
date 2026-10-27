#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& s) { V4* d = this; const V4* p = &s; __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(p) : "r"(d) : "memory"); }
} __attribute__((aligned(16)));
typedef struct Splash {
    float t;
    char pad4[0xC];
    V4 pos;
    float r20;
    float r24;
    int tex;
} Splash;
struct V4c {
    float x, y, z, w;
    V4c(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M44 { __int128 r[4]; };
extern "C" {
void SfxParticleEffect_eEffectName_cMatrixR(int id, M44* m);
}
static inline void UnitMtx(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void CP2(V4* d0, const V4* s) { V4* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void CP(V4* d, const V4* s) { __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(d) : "memory"); }

extern "C" void WaterFx_InitSplash(Splash* s, const V4* p, float size, float z)
{
    s->t = 5.0f;
    CP2(&s->pos, p);
    s->pos.z = z;
    float k = 2.5f * size;
    s->r20 = 0.15f * size;
    s->r24 = k - s->r20;
    M44 m;
    UnitMtx(&m);
    V4c v(s->pos.x, s->pos.y, s->pos.z - 0.25f * size, 1.0f);
    CP2((V4*)&m.r[3], (V4*)&v);
    if (size >= 2.0f) SfxParticleEffect_eEffectName_cMatrixR(0x11, &m);
    else SfxParticleEffect_eEffectName_cMatrixR(0x12, &m);
}
