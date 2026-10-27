/*
 * Libs/SFOLib/Source/ska: 2 files, 003B3A10-003B3B20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B3A10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
struct Qt {
    float x, y, z, w;
    Qt() {}
    Qt(const Qt& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); }
    Qt operator*(const Qt& b) const {
        Qt c; Qt* d = &c; const Qt* l = this; const Qt* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
    Qt& operator=(const Qt& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline Qt Ident() { Qt a; __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(&a) : "memory"); return a; }
extern "C" char D_004DFC50[];
extern "C" char D_004DFC30[];
struct T {
    void* vt; signed char b4; char pad5[11]; Qt q;
    int f20, f24; unsigned char f28, f29; char pad2a[2];
    float f2c, f30, f34, f38, f3c; int f40; unsigned char f44, f45, f46;
};
extern "C" T* cSkaAnim_ctor_cSkaAnimR_int_eAxisOfMotion(T* d, T* s, int a2, unsigned char a3);
T* cSkaAnim_ctor_cSkaAnimR_int_eAxisOfMotion(T* d, T* s, int a2, unsigned char a3)
{
    Qt b(Ident());
    d->vt = D_004DFC50;
    d->b4 = s->b4;
    d->q = b * s->q;
    d->vt = D_004DFC30;
    d->f20 = s->f20; d->f24 = s->f24; d->f28 = s->f28; d->f29 = s->f29;
    d->f2c = s->f2c; d->f30 = s->f30; d->f34 = s->f34; d->f38 = s->f38; d->f3c = s->f3c;
    d->f40 = a2; d->f44 = a3; d->f45 = s->f45; d->f46 = s->f46;
    return d;
}
static inline void merge_flush_func_003B3A10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B3A10 */

/* merge_units: begin func_003B3B20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

#if 0 /* merge_units */
extern void * const D_004DFC30[];
#endif /* merge_units */
#define D_004DFC30 ((void * const*)&D_004DFC30) /* merge_units */

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
extern "C" int cSkaAnimationSet_GetNodeId(NMap* m, void* name);
extern "C" SkaClip** cArray_cSkaNodePtr_opIndex(int* reg, int idx);
extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimR_eModifier_cEulerAngleTR_eAxisOfMotion(SkaClip* d, void* c, int a, int b, int e);
extern "C" SkaClip* cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(SkaClip* self, void* name, NMap* m, int a, int b, int e)
{
    SkaClip* c;
    Base(self, 0, Unit());
    self->vt = (void*)D_004DFC30;
    self->clip = 0;
    self->r2c.a = 0.0f;
    self->r2c.b = 1.0f;
    c = *cArray_cSkaNodePtr_opIndex(&m->reg, cSkaAnimationSet_GetNodeId(m, name));
    if (!((Item*)c)->b4) {
        SkaClip t;
        cSkaAnim_ctor_cSkaAnimR_eModifier_cEulerAngleTR_eAxisOfMotion(&t, c, a, b, e);
        *self = t;
    }
    return self;
}
#undef D_004DFC30 /* merge_units */
static inline void merge_flush_func_003B3B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B3B20 */
