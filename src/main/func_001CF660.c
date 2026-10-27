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
void cVector_GetNormalized_void(V* out, V* v);
void cVector_Cross(V* out, V* a, V* b);
int cVector_IsZeroXYZ(V* v);
V* cVector_Normalize_void(V* v);
V* cVector_ctor_cVectorR(V* d, V* s);
V* cVector_ctor_float_float_float_float(V* out, float x, float y, float z, float w);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, V* a, V* b, V* c, V* t);
void cMatrix_MakeLookAtMatrix_cVectorR(M* m, V* a);
void cMatrix_SetUnit(M* m);
void cMatrix_SetXAxis(M* m, V* v);
void cMatrix_SetYAxis(M* m, V* v);
void cMatrix_SetZAxis(M* m, V* v);
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
    cVector_Cross(&c, dir, up);
    if (!cVector_IsZeroXYZ(&c)) {
        V f;
        V r;
        V u;
        V w;
        cVector_GetNormalized_void(&f, dir);
        cVector_ctor_cVectorR(&r, cVector_Normalize_void(&c));
        cVector_Cross(&u, &r, &f);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &r, &f, &u, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(dir)) {
        cMatrix_MakeLookAtMatrix_cVectorR(m, dir);
    } else {
        cMatrix_SetUnit(m);
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
            cMatrix_SetXAxis(&m, &r2);
            cMatrix_SetYAxis(&m, &r1);
            cMatrix_SetZAxis(&m, &n);
        }
    }
    *out = m;
}
