#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" char D_004DFC50[];
extern void * const D_004DFC30[];
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V Unit() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
struct F2 { float a, b; F2() {} };
struct ClipBase {
    void* vt;
    signed char b4;
    V v10;
    ClipBase() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ClipBase() { vt = D_004DFC50; }
    ClipBase& operator=(const ClipBase& o) { b4 = o.b4; v10 = o.v10; return *this; }
};
struct SkaClip : ClipBase {
    int f20;
    void* clip;
    unsigned char b28, b29;
    F2 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SkaClip() { vt = (void*)D_004DFC30; }
};
static inline void Base(SkaClip* s, signed char b, V v) { s->vt = D_004DFC50; s->b4 = b; s->v10 = v; }
struct Item { void* vt; unsigned char b4; };
struct NMap { char pad[0x34]; int reg; };
extern "C" int NodeNameMap_Find(NMap* m, void* name);
extern "C" SkaClip** Registry_At(int* reg, int idx);
extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeNormalizedR_etc(SkaClip* d, void* c, int a, int b, float f, int e, int g, int h, signed char s1, signed char s2);
extern "C" SkaClip* cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_2(SkaClip* self, void* name, NMap* m, int a, int b, int e, int g, int h, float f, signed char s1, signed char s2)
{
    SkaClip* c;
    Base(self, 0, Unit());
    self->vt = (void*)D_004DFC30;
    self->clip = 0;
    self->r2c.a = 0.0f;
    self->r2c.b = 1.0f;
    c = *Registry_At(&m->reg, NodeNameMap_Find(m, name));
    if (!((Item*)c)->b4) {
        SkaClip t;
        cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeNormalizedR_etc(&t, c, a, b, f, e, g, h, s1, s2);
        *self = t;
    }
    return self;
}
