/*
 * Libs/SFOLib/Source/xform: 5 files, 0036F510-0036FB30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin fileman_36F510 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int count, int* value);

/* push_back on a pointer vector. */
int std_vector_cXformNodePtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_fileman_36F510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end fileman_36F510 */

/* merge_units: begin func_0036F530 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
static inline void G1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V& operator=(const V& o) { void* xx = this; G1(this, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4];
    M() {}
    M(const M& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); }
};
static inline void G4(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void G1(void* d, void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void GMV(void* o, void* m, void* v) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
typedef struct { int p; } It;
extern "C" {
void cArray_cXformNodePtr_Begin(It* it, void* c);
void cArray_cXformNodePtr_End(It* it, void* c);
int cArray_cXformNodePtr_ConstIterator_opNe(It* a, It* b);
void** cArray_cXformNodePtr_ConstIterator_opMul(It* it);
void cXformNode_SetNeedsUpdate(void* p);
void cArray_cXformNodePtr_ConstIterator_opInc(It* it);
M* cMatrix_InvertRot(M* m);
int cMatrix_IsZeroTranslation(M* m);
V* func_00133EC0(M* m);
void cVector_ctor_cVectorR(V* d, V* s);
V* cVector_NegateXYZ(V* a);
V* cVector_Rotate_cMatrixR(V* a, M* b);
void cMatrix_SetTranslation(M* m, V* v);
}
struct Xform {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0xC];
    M world;
    unsigned char dirty;
    char pad51[0x3F];
    V pos;
    Xform* parent;
    M GetWorld() { if (dirty) Update(); const M& w = world; return w; }
    int lA4[3];
};
extern "C" void cXformNode_SetTranslation(Xform* x, V* t)
{
    It b;
    It e;
    Xform* p = x->parent;
    if (p) {
        M m = p->GetWorld();
        V v;
        V tmp;
        v = *t;
        cMatrix_InvertRot(&m);
        if (!cMatrix_IsZeroTranslation(&m)) {
            cVector_ctor_cVectorR(&tmp, func_00133EC0(&m));
            cVector_NegateXYZ(&tmp);
            cVector_Rotate_cMatrixR(&tmp, &m);
            cMatrix_SetTranslation(&m, &tmp);
        }
        GMV(&v, &m, &v);
        { void* xx = &x->pos; }
        G1(&x->pos, &v);
    } else {
        { void* xx = &x->pos; }
        G1(&x->pos, t);
    }
    if (!x->dirty) {
        It* pe;
        x->dirty = 1;
        cArray_cXformNodePtr_Begin(&b, x->lA4);
        cArray_cXformNodePtr_End(&e, x->lA4);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}
static inline void merge_flush_func_0036F530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F530 */

/* merge_units: begin func_0036F6E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
static inline void QC(void* s, void* d) {
    __int128 qa, qb;
    asm {
        .set noreorder
        .set reorder
        lq qa, 0x0(s)
        lq qb, 0x10(s)
        sq qa, 0x0(d)
        lq qa, 0x20(s)
        sq qb, 0x10(d)
        lq qb, 0x30(s)
        sq qa, 0x20(d)
        sq qb, 0x30(d)
    }
}
typedef struct { float m[4][4]; } __attribute__((aligned(16))) M6F6E0;
typedef struct { int p; } It6F6E0;
class X6F6E0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0xC];
    M6F6E0 world;
    unsigned char dirty;
    char pad51[0xF];
    float r[3][4];
    char pad90[0x10];
    X6F6E0* parent;
    int list[3];
};
extern "C" {
#if 0 /* merge_units */
void cArray_cXformNodePtr_Begin(It6F6E0* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((It *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_End(It6F6E0* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((It *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(It6F6E0* a, It6F6E0* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((It *)(a0), (It *)(a1))) /* merge_units */

#if 0 /* merge_units */
void** cArray_cXformNodePtr_ConstIterator_opMul(It6F6E0* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) (cArray_cXformNodePtr_ConstIterator_opMul((It *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_ConstIterator_opInc(It6F6E0* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) (cArray_cXformNodePtr_ConstIterator_opInc((It *)(a0))) /* merge_units */

}
static inline void MulRot(M6F6E0* out, M6F6E0* m, M6F6E0* rot)
{
    asm {
        lqc2 vf8, 0x0(rot)
        lqc2 vf9, 0x10(rot)
        lqc2 vf10, 0x20(rot)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddz.xyzw vf12, vf6, vf8z
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddz.xyzw vf13, vf6, vf9z
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddz.xyzw vf14, vf6, vf10z
        vmove.xyzw vf15, vf7
        sqc2 vf12, 0x0(out)
        sqc2 vf13, 0x10(out)
        sqc2 vf14, 0x20(out)
        sqc2 vf15, 0x30(out)
    }
}
static inline void Transpose(M6F6E0* m)
{
    float t;
    t = m->m[0][1]; m->m[0][1] = m->m[1][0]; m->m[1][0] = t;
    t = m->m[0][2]; m->m[0][2] = m->m[2][0]; m->m[2][0] = t;
    t = m->m[1][2]; m->m[1][2] = m->m[2][1]; m->m[2][1] = t;
}
static inline void Set(X6F6E0* x, M6F6E0* s)
{
    x->r[0][0] = s->m[0][0]; x->r[0][1] = s->m[0][1]; x->r[0][2] = s->m[0][2];
    x->r[1][0] = s->m[1][0]; x->r[1][1] = s->m[1][1]; x->r[1][2] = s->m[1][2];
    x->r[2][0] = s->m[2][0]; x->r[2][1] = s->m[2][1]; x->r[2][2] = s->m[2][2];
    x->r[0][3] = s->m[0][3]; x->r[1][3] = s->m[1][3]; x->r[2][3] = s->m[2][3];
}
#pragma opt_common_subs off
#pragma opt_rotateloops off
extern "C" void cXformNode_SetRotationMatrix(X6F6E0* self, M6F6E0* rot)
{
    X6F6E0* p = self->parent;
    if (p) {
        M6F6E0 m;
        if (p->dirty) p->Update();
        QC(&p->world, &m);
        { float t, u, v;
        t = m.m[0][1]; m.m[0][1] = m.m[1][0]; m.m[1][0] = t;
        u = m.m[0][2]; m.m[0][2] = m.m[2][0]; m.m[2][0] = u;
        v = m.m[1][2]; m.m[1][2] = m.m[2][1]; m.m[2][1] = v; }
        MulRot(&m, &m, rot);
        Set(self, &m);
    } else {
        Set(self, rot);
    }
    if (!self->dirty) {
        It6F6E0 b;
        It6F6E0 e;
        It6F6E0* pe;
        self->dirty = 1;
        cArray_cXformNodePtr_Begin(&b, self->list);
        cArray_cXformNodePtr_End(&e, self->list);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opNe /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opInc /* merge_units */
static inline void merge_flush_func_0036F6E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F6E0 */

/* merge_units: begin func_0036F920 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void QR_F920(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void MM_F920(void* d, void* a, void* b) { __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
typedef struct { __int128 q[4]; } M_F920;
typedef struct { __int128 q; } V_F920;
typedef struct { int p; } It_F920;
class XV_F920 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
};
typedef struct Xform_F920 {
    void* vt; char pad4[0xC];
    M_F920 world;
    unsigned char dirty; char pad51[0xF];
    M_F920 local;
    struct Xform_F920* parent;
    int lA4[3];
} Xform_F920;
extern "C" {
#if 0 /* merge_units */
void cMatrix_InvertRot(M_F920* m);
#endif /* merge_units */
#define cMatrix_InvertRot(a0) ((void)cMatrix_InvertRot((M *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cMatrix_IsZeroTranslation(M_F920* m);
#endif /* merge_units */
#define cMatrix_IsZeroTranslation(a0) (cMatrix_IsZeroTranslation((M *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_F920* func_00133EC0(M_F920* m);
#endif /* merge_units */
#define func_00133EC0(a0) ((V_F920 *)func_00133EC0((M *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cVector_ctor_cVectorR(V_F920* d, V_F920* s);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) (cVector_ctor_cVectorR((V *)(a0), (V *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cVector_NegateXYZ(V_F920* v);
#endif /* merge_units */
#define cVector_NegateXYZ(a0) ((void)cVector_NegateXYZ((V *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cVector_Rotate_cMatrixR(V_F920* v, M_F920* m);
#endif /* merge_units */
#define cVector_Rotate_cMatrixR(a0, a1) ((void)cVector_Rotate_cMatrixR((V *)(a0), (M *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_SetTranslation(M_F920* m, V_F920* v);
#endif /* merge_units */
#define cMatrix_SetTranslation(a0, a1) (cMatrix_SetTranslation((M *)(a0), (V *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_Begin(It_F920* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((It *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_End(It_F920* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((It *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(It_F920* a, It_F920* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((It *)(a0), (It *)(a1))) /* merge_units */

#if 0 /* merge_units */
void** cArray_cXformNodePtr_ConstIterator_opMul(It_F920* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) (cArray_cXformNodePtr_ConstIterator_opMul((It *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_ConstIterator_opInc(It_F920* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) (cArray_cXformNodePtr_ConstIterator_opInc((It *)(a0))) /* merge_units */

}

#pragma opt_rotateloops off

extern "C" void cXformNode_SetMatrix(Xform_F920* x, M_F920* w)
{
    It_F920 b;
    It_F920 e;
    Xform_F920* par = x->parent;
    if (par) {
        M_F920 inv;
        if (par->dirty) ((XV_F920*)par)->Refresh();
        {
            /* declaration order sets the copy registers */
            void* s = &par->world;
            void* d = &inv;
            __int128 qa;
            __int128 qb;
            __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
        cMatrix_InvertRot(&inv);
        if (!cMatrix_IsZeroTranslation(&inv)) {
            V_F920 t;
            cVector_ctor_cVectorR(&t, func_00133EC0(&inv));
            cVector_NegateXYZ(&t);
            cVector_Rotate_cMatrixR(&t, &inv);
            cMatrix_SetTranslation(&inv, &t);
        }
        MM_F920(&inv, &inv, w);
        {
            void* xx = &x->local; /* dead on purpose: retail keeps this addiu */
        }
        QR_F920(&x->local, &inv);
    } else {
        void* xx = &x->local; /* dead on purpose: retail keeps this addiu */
        QR_F920(&x->local, w);
    }
    if (!x->dirty) {
        It_F920* pe;
        x->dirty = 1;
        cArray_cXformNodePtr_Begin(&b, x->lA4);
        cArray_cXformNodePtr_End(&e, x->lA4);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}
#undef cMatrix_InvertRot /* merge_units */
#undef cMatrix_IsZeroTranslation /* merge_units */
#undef func_00133EC0 /* merge_units */
#undef cVector_ctor_cVectorR /* merge_units */
#undef cVector_NegateXYZ /* merge_units */
#undef cVector_Rotate_cMatrixR /* merge_units */
#undef cMatrix_SetTranslation /* merge_units */
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opNe /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opInc /* merge_units */
static inline void merge_flush_func_0036F920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F920 */

/* merge_units: begin func_0036FB30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(cArray_cXformNodePtr_dtor, std_vector_imp_cXformNodePtr_1_dtor)
static inline void merge_flush_func_0036FB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FB30 */
