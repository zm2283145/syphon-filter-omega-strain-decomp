#pragma cplusplus on
#include "types.h"

/* ska clip copies (siblings of cSkaAnim_ctor_cSkaAnimR_bool_bool_float_etc): rotate the source clip's quaternion by the euler
 * angles, flip the direction flags and set the playback sub-range - cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeR_etc from a frame range
 * normalised by the animation length, cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeNormalizedR_etc as a sub-range of the source clip's range
 * (mirrored when the clip runs backwards). */
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
static inline float Clamp01(float x) { float r = 0.0f; float hi = 1.0f; float lo = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float ClampLo(float x, float lo) { float r = 0.0f; float hi = 1.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
/* same clamps with the bounds declared in the other order (cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeNormalizedR_etc's register choice) */
static inline float Sat01(float x) { float r = 0.0f; float lo = 0.0f; float hi = 1.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float SatLo(float x, float lo) { float r = 0.0f; float hi = 1.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }

struct F2 {
    float a, b;
    F2() {}
    float Span() const { return b - a; }
    void Mirror() { F2 o = *this; a = 1.0f - o.b; b = 1.0f - o.a; }
    void Lerp(const F2& p) { float a0 = a; float s = b - a; a = a0 + s * p.a; b = a0 + s * p.b; }
    void Fix2() { a = Sat01(a); b = SatLo(b, a); }
    void Fix() { a = Clamp01(a); b = ClampLo(b, a); }
};
struct SkaAnim { int pad0; unsigned int count; int pad8; float dur; };
static inline float Length(SkaAnim* c) { return (float)c->count * c->dur; }
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
    SkaAnim* clip;
    unsigned char b28, b29;
    F2 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~SkaClip() { vt = (void*)D_004DFC30; }
};
extern "C" float Math_Sin(float);
extern "C" float Math_Cos(float);
extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeR_etc(SkaClip* self, SkaClip* src, bool a, bool b, float g, const float* range, const float* ang, int id, signed char s, unsigned char mode)
{
    float hx = 0.5f * ang[0];
    float hy = 0.5f * ang[1];
    float hz = 0.5f * ang[2];
    float cx = Math_Cos(hx);
    float cy = Math_Cos(hy);
    float cz = Math_Cos(hz);
    float sx = Math_Sin(hx);
    float sy = Math_Sin(hy);
    float sz = Math_Sin(hz);
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
    {
        F2 r;
        float n = Length(src->clip);
        if (n != 0.0f) {
            float lo = range[0];
            float inv = 1.0f / n;
            r.a = inv * lo;
            r.b = inv * range[1];
            r.Fix();
        } else {
            r.a = 0.0f;
            r.b = 1.0f;
        }
        self->r2c.a = r.a;
        self->r2c.b = r.b;
    }
    self->f34 = src->f34;
    self->f38 = src->f38 * g;
    self->f3c = self->f38 * Length(src->clip) * self->r2c.Span();
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

extern "C" SkaClip* cSkaAnim_ctor_cSkaAnimR_bool_bool_cSkaAnimPlaybackRangeNormalizedR_etc(SkaClip* self, SkaClip* src, bool a, bool b, float g, const float* range, const float* ang, int id, signed char s, unsigned char mode)
{
    float hx = 0.5f * ang[0];
    float hy = 0.5f * ang[1];
    float hz = 0.5f * ang[2];
    float cx = Math_Cos(hx);
    float cy = Math_Cos(hy);
    float cz = Math_Cos(hz);
    float sx = Math_Sin(hx);
    float sy = Math_Sin(hy);
    float sz = Math_Sin(hz);
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
    {
        F2 res;
        F2 t;
        F2 cur;
        const F2* pr;
        if (src->b28) {
            F2 x = *(const F2*)range;
            x.Mirror();
            x.Fix2();
            t = x;
            pr = &t;
        } else {
            pr = (const F2*)range;
        }
        cur = src->r2c;
        cur.Lerp(*pr);
        cur.Fix2();
        {
            const F2& c = cur; /* through a reference: retail copies cur via a pointer register */
            res = c;
            self->r2c.a = res.a;
            self->r2c.b = res.b;
        }
    }
    self->f34 = src->f34;
    self->f38 = src->f38 * g;
    self->f3c = src->f3c * g * ((const F2*)range)->Span();
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
