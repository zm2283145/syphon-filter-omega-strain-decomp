/*
 * Libs/SFOLib/Source/ska: 1 file, 003B2C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B2C50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma always_inline on
extern "C" char D_004DFC50[];
extern void * const D_004DFC30[];
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); }
    V operator*(const V& b) const {
        V c; V* d = &c; const V* l = this; const V* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V Unit() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
struct F2 { float a, b; F2() {} };
struct ClipBase {
    void* vt;
    signed char b4;
    V v10;
    ClipBase() {}
    ~ClipBase() { vt = D_004DFC50; }
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
    ~SkaClip() { vt = (void*)D_004DFC30; }
};
extern "C" float Libc_Fmodf(float x, float y);
extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimR_eModifier(SkaClip* self, const SkaClip* o, unsigned char mode)
{
    V u(Unit());
    self->vt = D_004DFC50;
    self->b4 = o->b4;
    self->v10 = u * o->v10;
    self->vt = (void*)D_004DFC30;
    self->f20 = o->f20;
    self->clip = o->clip;
    self->b28 = o->b28;
    self->b29 = o->b29;
    self->r2c.a = o->r2c.a;
    self->r2c.b = o->r2c.b;
    self->f34 = o->f34;
    self->f38 = o->f38;
    self->f3c = o->f3c;
    self->f40 = o->f40;
    self->b44 = o->b44;
    self->b45 = o->b45;
    self->b46 = o->b46;
    switch (mode) {
    case 0:
        break;
    case 1:
        self->b28 = !o->b28;
        break;
    case 2:
        self->b29 = !o->b29;
        break;
    case 3:
        self->b29 = !o->b29;
        self->f34 = Libc_Fmodf(0.5f + o->f34, 1.0f);
        break;
    }
    return self;
}
static inline void merge_flush_func_003B2C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2C50 */
