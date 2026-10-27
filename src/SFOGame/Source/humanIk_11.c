/*
 * SFOGame/Source/humanIk: 9 files, 001CF4C0-001CFA90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CF4C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
union V4_29A0 { float f[4]; __int128 q; };
struct E_29A0 { V4_29A0 p; V4_29A0 q; E_29A0() {} };
struct M_29A0 { E_29A0 e[2]; };
/* Two-element array of quad pairs built from four vectors (by pointer).
   The quad copies keep retail's unfolded addresses with the peephole off. */
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" M_29A0* cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(M_29A0* m, const V4_29A0* a, const V4_29A0* b, const V4_29A0* c, const V4_29A0* d)
{
    { E_29A0* e = m->e; E_29A0* end = m->e + 2; do { new (e) E_29A0; } while (++e != end); }
    E_29A0* e1 = &m->e[1];
    V4_29A0* q0 = &m->e[0].q;
    V4_29A0* p1 = &m->e[1].p;
    V4_29A0* q1 = &e1->q;
    m->e[0].p.q = a->q;
    q0->q = b->q;
    p1->q = c->q;
    q1->q = d->q;

    return m;
}
static inline void merge_flush_func_001CF4C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF4C0 */

/* merge_units: begin func_001CF520 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

/* Reset the timer from the definition's +0x40 value. */
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Restart(TimedRef* self) {
    self->timer = self->def->unk40;
}
static inline void merge_flush_func_001CF520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF520 */

/* merge_units: begin func_001CF530 */
#pragma push /* merge_units */
#include "vu0_scale_eq.h"
typedef struct { VSESeg a; VSESeg b; float dur; float rate; } C_F530;
#pragma push
#pragma peephole off
#pragma opt_propagation off
void cHermiteSplineWithScaledDuration_cQuaternion_Reset_float(C_F530* c, float t) {
    float k; float r;
    k = t * c->rate;
    { VSESeg* s = &c->a; VU0_ScaleEq(&s->v, k); }
    { VSESeg* s = &c->b; VU0_ScaleEq(&s->v, k); }
    c->dur = t;
    r = 0.0f; if (t != 0.0f) r = 1.0f / t; else asm { .set reorder } c->rate = r;
}
#pragma pop
static inline void merge_flush_func_001CF530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF530 */

/* merge_units: begin func_001CF5B0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4 cQuaternion_GetConjugate(V4 v) {
    V4* p = &v;
    asm {
        
        lqc2 vf1, 0x0(p)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(p)
        
    }
    return *p;
}
#pragma pop
static inline void merge_flush_func_001CF5B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF5B0 */

/* merge_units: begin func_001CF5E0 */
#pragma push /* merge_units */
/* Vec4 component accessors. */
float* cQuaternion_Z_void(Vec4* v) {
    return &v->z;
}

float* cQuaternion_Y_void(Vec4* v) {
    return &v->y;
}

float* cQuaternion_X_void(Vec4* v) {
    return &v->x;
}

float* cQuaternion_W_void(Vec4* v) {
    return &v->w;
}

float cQuaternion_Z_void_2(Vec4* v) {
    return v->z;
}

float cQuaternion_Y_void_2(Vec4* v) {
    return v->y;
}

float cQuaternion_X_void_2(Vec4* v) {
    return v->x;
}

float cQuaternion_W_void_2(Vec4* v) {
    return v->w;
}
static inline void merge_flush_func_001CF5E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF5E0 */

/* merge_units: begin func_001CF660 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
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
static inline void merge_flush_func_001CF660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF660 */

/* merge_units: begin func_001CFA20 */
#pragma push /* merge_units */
#pragma push
#pragma opt_common_subs off
V4 cQuaternion_opMul_cQuaternionR(V4* b, V4* c) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(q1)
    }
    return l0;
}
#pragma pop
static inline void merge_flush_func_001CFA20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CFA20 */

/* merge_units: begin func_001CFA70 */
#pragma push /* merge_units */
V4* cQuaternion_Conjugate(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(a)
    }
    return a;
}
static inline void merge_flush_func_001CFA70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CFA70 */

/* merge_units: begin func_001CFA90 */
#pragma push /* merge_units */
typedef struct { char pad[0xE4]; float a; char pad2[0x1B4 - 0xE8]; float b; } CFA90_t;
int cIkTargetWithSplinedTransition_HasTransitionEnded(CFA90_t* p) {
    return p->a == 0.0f && p->b == 0.0f;
}
static inline void merge_flush_func_001CFA90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CFA90 */
