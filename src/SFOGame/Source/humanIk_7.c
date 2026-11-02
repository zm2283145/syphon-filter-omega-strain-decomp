/*
 * SFOGame/Source/humanIk: 12 files, 001CF4C0-001CFF30
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

/* merge_units: begin func_001CFAE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)

static inline void Q16b(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); }
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V_001CFAE0 {
    float x, y, z, w;
    V_001CFAE0& operator=(const V_001CFAE0& o) { void* xx = (void*)&o; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Plc { V_001CFAE0 rot, pos; };
struct Plc4 { V4 rot, pos; };
struct Mtx { V4 r0, r1, r2, r3; };

struct Elem { VPAD16(a) VPAD4(b) virtual void Sync(); char pad04[0xC]; Mtx m; unsigned char b50; };
extern "C" {
void cQuaternion_opAssign(V4*, V4*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(void*, float);
int func_0017D510(void*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(V4*, void*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame(void*, float);
int cSplinedMotion_cVector_IsTransitionInProgress(void*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_Evaluate(V4*, void*);
void cVector_opAssign(V4*, V4*);
}
struct QCtl {
    VPAD4(a) virtual void Begin(); virtual void End(); virtual void Step(float t, float u);
    char pad04[0xC];
    V4 prev;        /* 0x10 */
    V4 cur;         /* 0x20 */
    char pad30[0x10];
    V4 target;      /* 0x40 */
    char pad50[0x60];
    char filt[0x20];/* 0xB0 */
    void Update(float t, float u) {
        cQuaternion_opAssign(&prev, &cur);
        Begin();
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(filt, t);
        if (func_0017D510(this)) {
            V4 tmp;
            cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(&tmp, filt);
            cQuaternion_opAssign(&cur, &tmp);
            End();
        } else {
            cQuaternion_opAssign(&cur, &target);
        }
        Step(t, u);
    }
};
struct PCtl {
    VPAD4(a) virtual void Begin(); virtual void End(); virtual void Step(float t, float u);
    char pad04[0xC];
    V4 prev;        /* 0x10 */
    V4 cur;         /* 0x20 */
    char pad30[0x10];
    V4 target;      /* 0x40 */
    char pad50[0x60];
    char filt[0x20];/* 0xB0 */
    void Update(float t, float u) {
        cVector_opAssign(&prev, &cur);
        Begin();
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame(filt, t);
        if (cSplinedMotion_cVector_IsTransitionInProgress(this)) {
            V4 tmp;
            cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_Evaluate(&tmp, filt);
            cVector_opAssign(&cur, &tmp);
            End();
        } else {
            cVector_opAssign(&cur, &target);
        }
        Step(t, u);
    }
};

struct S {
    Plc4 base;          /* 0x00 */
    signed char idx;    /* 0x20 */
    char pad21[0xF];
    QCtl a;             /* 0x30 */
    PCtl b;             /* 0x100 */
};

extern "C" {
#if 0 /* merge_units */
Elem* std_vector_cBone_opIndex(void* arr, int index);
#endif /* merge_units */
Elem1D0* std_vector_cBone_opIndex(Vec1D0Array* v, int index); /* merge_units */
#define std_vector_cBone_opIndex(a0, a1) ((Elem *)std_vector_cBone_opIndex((Vec1D0Array *)(a0), (a1))) /* merge_units */

void cQuaternion_ctor_void(V_001CFAE0*);
void cQuaternion_VU0Multiply(V_001CFAE0*, V_001CFAE0*, V_001CFAE0*);
void cQuaternion_ctor_cQuaternionR(V_001CFAE0*, V_001CFAE0*);
void cIkTargetWithSplinedTransition_NextFrame(S* s, void* arr, float t, float u);
}
static inline Elem* GetElem(void* arr, const signed char& i) { return std_vector_cBone_opIndex(arr, i); }static inline Plc4* MtxToPlc(Mtx* m, Plc4* out) {
    Plc4* o = out;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(o)
        .set reorder
    }
    Q16(&out->pos, &m->r3);
    return out;
}

static inline void QRot(V_001CFAE0* v, V_001CFAE0* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3(V_001CFAE0* s, V_001CFAE0* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}

void cIkTargetWithSplinedTransition_NextFrame(S* s, void* arr, float t, float u)
{
    Plc4* src;
    if (s->idx != -1) {
        Plc p;
        void* d1; __int128 q1; __int128 q2; void* d2; const void* s2; const signed char* ip;
        d1 = &p.rot; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q1) : "r"(&s->base.rot), "r"(d1) : "memory");
        ip = &s->idx;
        d2 = &p.pos; s2 = &s->base.pos; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q2) : "r"(s2), "r"(d2) : "memory");
        Elem* e = GetElem(arr, *ip);
        if (e->b50) {
            e->Sync();
        }
        Plc4 pil;
        MtxToPlc(&e->m, &pil);
        Plc* pi = (Plc*)&pil;
        V_001CFAE0 r;
        V_001CFAE0 q;
        cQuaternion_ctor_void(&q);
        cQuaternion_VU0Multiply(&q, &pi->rot, &p.rot);
        cQuaternion_ctor_cQuaternionR(&r, &q);
        p.rot = r;
        QRot(&p.pos, &pi->rot);
        V_001CFAE0* pp = (V_001CFAE0*)&pil.pos;
        VAdd3(pp, &p.pos);
        src = (Plc4*)&p;
    } else {
        src = &s->base;
    }
    {
    const void* t2; void* e1; __int128 r1; void* e2; __int128 r2;
    e1 = &s->a.target; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(r1) : "r"(e1), "r"(&src->rot) : "memory");
    t2 = &src->pos; e2 = &s->b.target; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(r2) : "r"(e2), "r"(t2) : "memory");
    }
    s->a.Update(t, u);
    s->b.Update(t, u);
}
#undef std_vector_cBone_opIndex /* merge_units */
static inline void merge_flush_func_001CFAE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CFAE0 */

/* merge_units: begin func_001CFF30 */
#pragma push /* merge_units */
/* Address of element index of a 0x1D0-byte record array. */
Elem1D0* std_vector_cBone_opIndex(Vec1D0Array* v, int index) {
    Elem1D0* data;

    data = v->data;
    return data + index;
}
static inline void merge_flush_func_001CFF30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CFF30 */

/* merge_units: begin func_001CFF50 */
#pragma push /* merge_units */
/* cHumanIkRoutine_ApplyGunRecoil_cQuaternionR_float: apply a pending recoil kick to the aim
 * quaternion: a randomised pitch about the yaw-rotated X axis, then a small
 * random roll about Y; clears the kick. */
#pragma cplusplus on
#pragma inline_depth(8)
struct M_001CFF50;
extern "C" {
void cMatrix_Set_ColumnMajorForm(M_001CFF50* m, float, float, float, float, float, float, float, float, float);
int Libc_Rand(void);
float SIN(float);
float COS(float);
float Libc_Sinf(float);
float Libc_Cosf(float);
}
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V_001CFF50 {
    float x, y, z, w;
    V_001CFF50() {}
    V_001CFF50(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V_001CFF50(const V_001CFF50& o) { V_001CFF50* d = this; const V_001CFF50* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V_001CFF50& operator=(const V_001CFF50& o) { V_001CFF50* d = this; const V_001CFF50* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M_001CFF50 {
    float m[4][4];
    M_001CFF50(float a, float b, float c, float d, float e, float f, float g, float h, float i) { cMatrix_Set_ColumnMajorForm(this, a, b, c, d, e, f, g, h, i); }
} __attribute__((aligned(16)));
struct AA {
    float x, y, z, angle;
    AA(const V_001CFF50& a, float ang) { x = a.x; y = a.y; z = a.z; angle = ang; }
};
struct QA : V_001CFF50 {
    QA(const AA& a) { float h = 0.5f * a.angle; float c = Libc_Cosf(h); float s = Libc_Sinf(h); w = c; x = s * a.x; y = s * a.y; z = s * a.z; }
};
struct Aim { char p0[0x324]; float kick; };
extern "C" unsigned char cHumanIkRoutine_ApplyGunRecoil_cQuaternionR_float(Aim* self, V_001CFF50* q);
/* VU0 macro ops have no C equivalent (asm). */
static inline void Apply33(V_001CFF50* out, const V_001CFF50* v, const M_001CFF50* m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(out), "r"(m), "r"(v) : "memory"); }
static inline void QMul(V_001CFF50* o, const V_001CFF50* b, const V_001CFF50* c) {
    __asm__ volatile("lqc2 vf1, 0x0(%1)\n lqc2 vf2, 0x0(%2)\n vmul.xyzw vf3, vf1, vf2\n vopmula.xyz ACC, vf1, vf2\n vmaddaw.xyz ACC, vf1, vf2w\n vmaddaw.xyz ACC, vf2, vf1w\n vopmsub.xyz vf4, vf2, vf1\n vsubaz.w ACC, vf3, vf3z\n vmsubay.w ACC, vf0, vf3y\n vmsubx.w vf4, vf0, vf3x\n sqc2 vf4, 0x0(%0)" : : "r"(o), "r"(b), "r"(c) : "memory");
}
static inline V_001CFF50 operator*(V_001CFF50 v, const M_001CFF50& m) { V_001CFF50* p = &v; Apply33(p, p, &m); return *p; }
static inline V_001CFF50 operator*(const V_001CFF50& a, const V_001CFF50& b) { V_001CFF50 r; QMul(&r, &a, &b); return r; }
static inline float Rand01() { return (float)Libc_Rand() / 2147483648.0f; }
/* k: retail keeps the span in a saved register across Libc_Rand. */
static inline float Rnd(float span, float lo) { float k = span; float r = Rand01(); float t = k * r; return t + lo; }
static inline float Around(float c, float span, float lo) { float t = Rnd(span, lo); return t + c; }
unsigned char cHumanIkRoutine_ApplyGunRecoil_cQuaternionR_float(Aim* self, V_001CFF50* q)
{
    unsigned char r = 0;
    if (self->kick > 0.0f) {
        V_001CFF50 q1;
        float pitch = self->kick * Around(0.0964294448f, 0.014835299f, -0.0074176495f);
        float yaw = Rnd(0.69813168f, -0.17453292f);
        float s = SIN(yaw);
        float c = COS(yaw);
        M_001CFF50 m(c, 0.0f, s, 0.0f, 1.0f, 0.0f, -s, 0.0f, c);
        V_001CFF50 axis = V_001CFF50(1.0f, 0.0f, 0.0f, 0.0f) * m;
        QA qa1(AA(axis, pitch));
        { const V_001CFF50& t = qa1; q1 = t; }
        QA qa2(AA(V_001CFF50(0.0f, 1.0f, 0.0f, 0.0f), Rnd(0.0445058979f, -0.022252949f)));
        q1 = q1 * qa2;
        *q = *q * q1;
        r = 1;
        self->kick = 0.0f;
    }
    return r;
}
static inline void merge_flush_func_001CFF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CFF50 */
