#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* Mtx_LookAt: orthonormal frame along dir, using `up` as the reference axis
 * unless dir is (nearly) parallel to it (|dot| >= limit), then ref's z row,
 * then ref's x row (with the rows rotated so the frame stays right-handed). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct M {
    VP r[4];
    M& operator=(const M& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" {
void Vec4_NormalizeXYZ_132060(V* out, V* v);
void Vec4_Cross(V* out, V* a, V* b);
int Vec4_IsZeroXYZ(V* v);
V* Vec4_NormalizeXYZInPlace(V* v);
V* Vec4_Assign(V* d, V* s);
V* Vec4_Set(V* out, float x, float y, float z, float w);
void Mtx_FromRowsAndTranslation(M* m, V* a, V* b, V* c, V* t);
void Mtx_FrameFromAxis(M* m, V* a);
void Mtx_SetIdentity(M* m);
void Mtx_SetRow0(M* m, V* v);
void Mtx_SetRow1(M* m, V* v);
void Mtx_SetRow2(M* m, V* v);
void Mtx_LookAt(M* out, V* dir, V* up, M* ref, float limit);
}
static inline void Normalize(V* v) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(v) : "memory"); }
static inline float Dot(const V* a, const V* b)
{
    int t;
    float r = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%3); lqc2 vf2, 0x0(%2); vmul.xyzw vf3, vf1, vf2; mtsah $0, 6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddz.w vf4, vf0, vf3z; qmfc2.ni %1, vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(b), "r"(a) : "memory");
    return r;
}
static inline float AbsDot(const V* a, const V* b) { float x = Dot(a, b); float r = 0.0f; asm { abs.s r, x } return r; }
static inline void NegV(V* r, const V* a) { __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a) : "memory"); }
static inline V operator-(const V& a) { V r; NegV(&r, &a); return r; }
static inline V Unit(const V& v) { V t = v; V* p = &t; Normalize(p); return *p; }
static inline void LookFrame(M* m, V* dir, V* up)
{
    V c;
    Vec4_Cross(&c, dir, up);
    if (!Vec4_IsZeroXYZ(&c)) {
        V f;
        V r;
        V u;
        V w;
        Vec4_NormalizeXYZ_132060(&f, dir);
        Vec4_Assign(&r, Vec4_NormalizeXYZInPlace(&c));
        Vec4_Cross(&u, &r, &f);
        Mtx_FromRowsAndTranslation(m, &r, &f, &u, Vec4_Set(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!Vec4_IsZeroXYZ(dir)) {
        Mtx_FrameFromAxis(m, dir);
    } else {
        Mtx_SetIdentity(m);
    }
}

static inline void Frame(M* m, V* dir, V* up) { LookFrame(m, dir, up); }
void Mtx_LookAt(M* out, V* dir, V* up, M* ref, float limit)
{
    M m;
    V d = Unit(*dir);
    V* pd = &d;
    if (AbsDot(pd, up) < limit) {
        Frame(&m, dir, up);
    } else if (AbsDot(&d, (V*)&ref->r[2]) < limit) {
        Frame(&m, &d, (V*)&ref->r[2]);
    } else {
        Frame(&m, &d, (V*)&ref->r[0]);
        {
            V r0 = *(V*)&m.r[0];
            V r1 = *(V*)&m.r[1];
            V r2 = *(V*)&m.r[2];
            V n = -r0;
            Mtx_SetRow0(&m, &r2);
            Mtx_SetRow1(&m, &r1);
            Mtx_SetRow2(&m, &n);
        }
    }
    *out = m;
}
