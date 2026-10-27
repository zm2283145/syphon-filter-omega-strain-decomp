#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma always_inline on
extern "C" char D_004DFC50[];
extern void * const D_004DFC30[];
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V operator*(const V& b) const {
        V c; V* d = &c; const V* l = this; const V* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
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
extern "C" float Libc_Sinf(float);
extern "C" float Libc_Cosf(float);
extern "C" float Libc_Fmodf(float, float);
extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimR_bool_bool_float_etc(SkaClip* self, SkaClip* src, bool a, bool b, float f, float g, const float* ang, int id, signed char s, unsigned char mode)
{
    float hx = 0.5f * ang[0];
    float hy = 0.5f * ang[1];
    float hz = 0.5f * ang[2];
    float cx = Libc_Cosf(hx);
    float cy = Libc_Cosf(hy);
    float cz = Libc_Cosf(hz);
    float sx = Libc_Sinf(hx);
    float sy = Libc_Sinf(hy);
    float sz = Libc_Sinf(hz);
    V q;
    q.w = cx * (cy * cz) - sx * (sy * sz);
    q.x = sx * (cy * cz) - cx * (sy * sz);
    q.y = cx * (sy * cz) + sx * (cy * sz);
    q.z = cx * (cy * sz) + sx * (sy * cz);
    self->vt = D_004DFC50;
    self->b4 = src->b4;
    {
        V t = q * src->v10;
        self->v10 = t;
    }
    self->vt = (void*)D_004DFC30;
    self->f20 = src->f20;
    self->clip = src->clip;
    self->b28 = (src->b28 && !a) || (!src->b28 && a);
    self->b29 = (src->b29 && !b) || (!src->b29 && b);
    self->r2c.a = src->r2c.a;
    self->r2c.b = src->r2c.b;
    self->f34 = Libc_Fmodf(src->f34 + (src->b28 ? 1.0f - f : f), 1.0f);
    self->f38 = src->f38 * g;
    self->f3c = src->f3c * g * (src->r2c.b - src->r2c.a);
    self->f40 = id;
    self->b44 = s;
    self->b45 = src->b45;
    self->b46 = src->b46;
    switch (mode) {
    case 0:
        break;
    case 1:
        self->b45 = 1;
        break;
    default:
        break;
    }
    return self;
}