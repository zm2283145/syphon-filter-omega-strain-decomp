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
