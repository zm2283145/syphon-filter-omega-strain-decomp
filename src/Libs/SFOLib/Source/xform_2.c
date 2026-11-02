/*
 * Libs/SFOLib/Source/xform: 12 files, 0036F010-0036F510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036F010 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void nMatrix_Multiply_NonTransposedMatrices(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf4, 0x0(c)
        lqc2 vf5, 0x10(c)
        lqc2 vf6, 0x20(c)
        lqc2 vf7, 0x30(c)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(a)
        sqc2 vf13, 0x10(a)
        sqc2 vf14, 0x20(a)
        sqc2 vf15, 0x30(a)
    }
}
static inline void merge_flush_func_0036F010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F010 */

/* merge_units: begin func_0036F090 */
#pragma push /* merge_units */
void func_0036F090(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf4, 0x0(c)
        lqc2 vf5, 0x10(c)
        lqc2 vf6, 0x20(c)
        lqc2 vf7, 0x30(c)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(a)
        sqc2 vf13, 0x10(a)
        sqc2 vf14, 0x20(a)
        sqc2 vf15, 0x30(a)
    }
}
static inline void merge_flush_func_0036F090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F090 */

/* merge_units: begin func_0036F110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
class T36F110 {
public:
    VPAD16(a) VPAD1(b)
    virtual void f4C(int);
    char pad[0x9C]; int aA0;
};
class A36F110 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d)
    virtual T36F110* f44();
};
extern "C" void cXformNode_RemoveChild(int key, A36F110* a, int arg);
void cXformNode_RemoveChild(int key, A36F110* a, int arg)
{
    T36F110* t = a ? a->f44() : 0;
    if (t && t->aA0 == key) t->f4C(arg);
}
static inline void merge_flush_func_0036F110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F110 */

/* merge_units: begin func_0036F190 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cXform_GetNode_void(void) {
    return 0;
}
static inline void merge_flush_func_0036F190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F190 */

/* merge_units: begin func_0036F1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
class D6XObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual D6XObj* getNode();
    virtual void attach(void* parent, int flags);
};
extern "C" void cXformNode_AddChild(void* self, D6XObj* child, int flags)
{
    D6XObj* n = child ? child->getNode() : 0;
    if (n) {
        n->attach(self, flags);
    }
}
static inline void merge_flush_func_0036F1A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F1A0 */

/* merge_units: begin func_0036F210 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
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
#if 0 /* merge_units */
void cArray_cXformNodePtr_Begin(It* it, void* c);
#endif /* merge_units */
void cArray_cXformNodePtr_Begin(void*, void*); /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_End(It* it, void* c);
#endif /* merge_units */
void cArray_cXformNodePtr_End(void*, void*); /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(It* a, It* b);
#endif /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(void*, void*); /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void** cArray_cXformNodePtr_ConstIterator_opMul(It* it);
#endif /* merge_units */
void** cArray_cXformNodePtr_ConstIterator_opMul(void*); /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) (cArray_cXformNodePtr_ConstIterator_opMul((void *)(a0))) /* merge_units */

void cXformNode_SetNeedsUpdate(void* p);
#if 0 /* merge_units */
void cArray_cXformNodePtr_ConstIterator_opInc(It* it);
#endif /* merge_units */
void cArray_cXformNodePtr_ConstIterator_opInc(void*); /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) (cArray_cXformNodePtr_ConstIterator_opInc((void *)(a0))) /* merge_units */

void std_vector_pod_int_resize(void* v, int n, int* fill);
#if 0 /* merge_units */
M* cMatrix_InvertRot(M* m);
#endif /* merge_units */
void* cMatrix_InvertRot(void*); /* merge_units */
#define cMatrix_InvertRot(a0) ((M *)cMatrix_InvertRot((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cMatrix_IsZeroTranslation(M* m);
#endif /* merge_units */
int cMatrix_IsZeroTranslation(void*); /* merge_units */
#define cMatrix_IsZeroTranslation(a0) (cMatrix_IsZeroTranslation((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V* func_00133EC0(M* m);
#endif /* merge_units */
void* func_00133EC0(void*); /* merge_units */
#define func_00133EC0(a0) ((V *)func_00133EC0((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cVector_ctor_cVectorR(V* d, V* s);
#endif /* merge_units */
void cVector_ctor_cVectorR(void*, void*); /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) (cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
V* cVector_NegateXYZ(V* a);
#endif /* merge_units */
void* cVector_NegateXYZ(void*); /* merge_units */
#define cVector_NegateXYZ(a0) ((V *)cVector_NegateXYZ((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V* cVector_Rotate_cMatrixR(V* a, M* b);
#endif /* merge_units */
void* cVector_Rotate_cMatrixR(void*, void*); /* merge_units */
#define cVector_Rotate_cMatrixR(a0, a1) ((V *)cVector_Rotate_cMatrixR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_SetTranslation(M* m, V* v);
#endif /* merge_units */
void cMatrix_SetTranslation(void*, void*); /* merge_units */
#define cMatrix_SetTranslation(a0, a1) (cMatrix_SetTranslation((void *)(a0), (void *)(a1))) /* merge_units */

}
struct XVec { int cap; int size; struct Xform** data; };
struct Xform {
    virtual void v0(); virtual void SetWorld(M* m); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0xC];
    M world;
    unsigned char dirty;
    char pad51[0x3F];
    V pos;
    Xform* parent;
    M GetWorld() { if (dirty) Update(); const M& w = world; return w; }
    XVec kids;
};
extern "C" void cXformNode_RemoveParent(Xform* x, int keep)
{
    Xform* p = x->parent;
    Xform* self = x;
    int fill;
    It b;
    It e;
    if (p) {
        M m = self->GetWorld();
        { void* xx = &p->kids.data; }
        self->parent = 0;
        {
            int i;
            int last = p->kids.size - 1;
            for (i = 0; i <= last; i++) {
                Xform** e = &p->kids.data[i];
                if (*e == self) {
                    *e = p->kids.data[last];
                    last--;
                }
            }
            fill = 0;
            std_vector_pod_int_resize(&p->kids, last + 1, &fill);
        }
        if (keep) {
            self->SetWorld(&m);
        } else if (!self->dirty) {
            It* pe;
            self->dirty = 1;
            cArray_cXformNodePtr_Begin(&b, &self->kids);
            cArray_cXformNodePtr_End(&e, &self->kids);
            pe = &e;
            while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
                cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
                cArray_cXformNodePtr_ConstIterator_opInc(&b);
            }
        }
    }
}
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opNe /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opInc /* merge_units */
#undef cMatrix_InvertRot /* merge_units */
#undef cMatrix_IsZeroTranslation /* merge_units */
#undef func_00133EC0 /* merge_units */
#undef cVector_ctor_cVectorR /* merge_units */
#undef cVector_NegateXYZ /* merge_units */
#undef cVector_Rotate_cMatrixR /* merge_units */
#undef cMatrix_SetTranslation /* merge_units */
static inline void merge_flush_func_0036F210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F210 */

/* merge_units: begin fileman_36F390 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
static inline void G1_an_36F390(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V_an_36F390 { float x, y, z, w; V_an_36F390& operator=(const V_an_36F390& o) { void* xx = this; G1_an_36F390(this, &o); return *this; } } __attribute__((aligned(16)));
struct M_an_36F390 { V_an_36F390 r[4];
    M_an_36F390() {}
    M_an_36F390(const M_an_36F390& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); }
};
static inline void G1_an_36F390(void* d, void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
extern "C" {
#if 0 /* merge_units */
void cArray_cXformNodePtr_Begin(It* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_End(It* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(It* a, It* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void** cArray_cXformNodePtr_ConstIterator_opMul(It* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) (cArray_cXformNodePtr_ConstIterator_opMul((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_ConstIterator_opInc(It* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) (cArray_cXformNodePtr_ConstIterator_opInc((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void std_vector_cXformNodePtr_push_back(void* v, struct Xform_an_36F390** p);
#endif /* merge_units */
int std_vector_cXformNodePtr_push_back(PtrVec* v, int* value); /* merge_units */
#define std_vector_cXformNodePtr_push_back(a0, a1) ((void)std_vector_cXformNodePtr_push_back((PtrVec *)(a0), (int *)(a1))) /* merge_units */

#if 0 /* merge_units */
M_an_36F390* cMatrix_InvertRot(M_an_36F390* m);
#endif /* merge_units */
#define cMatrix_InvertRot(a0) ((M_an_36F390 *)cMatrix_InvertRot((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cMatrix_IsZeroTranslation(M_an_36F390* m);
#endif /* merge_units */
#define cMatrix_IsZeroTranslation(a0) (cMatrix_IsZeroTranslation((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_an_36F390* func_00133EC0(M_an_36F390* m);
#endif /* merge_units */
#define func_00133EC0(a0) ((V_an_36F390 *)func_00133EC0((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cVector_ctor_cVectorR(V_an_36F390* d, V_an_36F390* s);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) (cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
V_an_36F390* cVector_NegateXYZ(V_an_36F390* a);
#endif /* merge_units */
#define cVector_NegateXYZ(a0) ((V_an_36F390 *)cVector_NegateXYZ((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_an_36F390* cVector_Rotate_cMatrixR(V_an_36F390* a, M_an_36F390* b);
#endif /* merge_units */
#define cVector_Rotate_cMatrixR(a0, a1) ((V_an_36F390 *)cVector_Rotate_cMatrixR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_SetTranslation(M_an_36F390* m, V_an_36F390* v);
#endif /* merge_units */
#define cMatrix_SetTranslation(a0, a1) (cMatrix_SetTranslation((void *)(a0), (void *)(a1))) /* merge_units */

}
struct XVec_an_36F390 { int cap; int size; struct Xform_an_36F390** data; };
struct Xform_an_36F390 {
    virtual void v0(); virtual void SetWorld(M_an_36F390* m); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual Xform_an_36F390* GetNode(); virtual void v16(); virtual void Detach(int k); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0xC];
    M_an_36F390 world;
    unsigned char dirty;
    char pad51[0x3F];
    V_an_36F390 pos;
    Xform_an_36F390* parent;
    M_an_36F390 GetWorld() { if (dirty) Update(); const M_an_36F390& w = world; return w; }
    XVec_an_36F390 kids;
    void Invalidate() {
        It b;
        It e;
        if (!dirty) {
            It* pe;
            dirty = 1;
            cArray_cXformNodePtr_Begin(&b, &kids);
            cArray_cXformNodePtr_End(&e, &kids);
            pe = &e;
            while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
                cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
                cArray_cXformNodePtr_ConstIterator_opInc(&b);
            }
        }
    }
};
extern "C" void cXformNode_SetParent(Xform_an_36F390* x, Xform_an_36F390* parent, int keep)
{
    Xform_an_36F390* p;
    Xform_an_36F390* self;
    if (parent) {
        p = parent->GetNode();
    } else {
        p = 0;
    }
    self = x;
    if (self->parent != p) {
        if (self->parent) {
            self->Detach(1);
        }
        if (p) {
            M_an_36F390 m = self->GetWorld();
            self->parent = p;
            std_vector_cXformNodePtr_push_back(&p->kids, &self);
            if (keep) {
                self->SetWorld(&m);
            } else {
                self->Invalidate();
            }
        }
    }
}
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opNe /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opInc /* merge_units */
#undef std_vector_cXformNodePtr_push_back /* merge_units */
#undef cMatrix_InvertRot /* merge_units */
#undef cMatrix_IsZeroTranslation /* merge_units */
#undef func_00133EC0 /* merge_units */
#undef cVector_ctor_cVectorR /* merge_units */
#undef cVector_NegateXYZ /* merge_units */
#undef cVector_Rotate_cMatrixR /* merge_units */
#undef cMatrix_SetTranslation /* merge_units */
static inline void merge_flush_fileman_36F390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end fileman_36F390 */

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
static inline void G1_0036F530(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V_0036F530 { float x, y, z, w; V_0036F530& operator=(const V_0036F530& o) { void* xx = this; G1_0036F530(this, &o); return *this; } } __attribute__((aligned(16)));
struct M_0036F530 { V_0036F530 r[4];
    M_0036F530() {}
    M_0036F530(const M_0036F530& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); }
};
static inline void G1_0036F530(void* d, void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
extern "C" {
#if 0 /* merge_units */
void cArray_cXformNodePtr_Begin(It* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_End(It* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(It* a, It* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void** cArray_cXformNodePtr_ConstIterator_opMul(It* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) (cArray_cXformNodePtr_ConstIterator_opMul((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cArray_cXformNodePtr_ConstIterator_opInc(It* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) (cArray_cXformNodePtr_ConstIterator_opInc((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
M_0036F530* cMatrix_InvertRot(M_0036F530* m);
#endif /* merge_units */
#define cMatrix_InvertRot(a0) ((M_0036F530 *)cMatrix_InvertRot((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cMatrix_IsZeroTranslation(M_0036F530* m);
#endif /* merge_units */
#define cMatrix_IsZeroTranslation(a0) (cMatrix_IsZeroTranslation((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_0036F530* func_00133EC0(M_0036F530* m);
#endif /* merge_units */
#define func_00133EC0(a0) ((V_0036F530 *)func_00133EC0((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cVector_ctor_cVectorR(V_0036F530* d, V_0036F530* s);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) (cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
V_0036F530* cVector_NegateXYZ(V_0036F530* a);
#endif /* merge_units */
#define cVector_NegateXYZ(a0) ((V_0036F530 *)cVector_NegateXYZ((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
V_0036F530* cVector_Rotate_cMatrixR(V_0036F530* a, M_0036F530* b);
#endif /* merge_units */
#define cVector_Rotate_cMatrixR(a0, a1) ((V_0036F530 *)cVector_Rotate_cMatrixR((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cMatrix_SetTranslation(M_0036F530* m, V_0036F530* v);
#endif /* merge_units */
#define cMatrix_SetTranslation(a0, a1) (cMatrix_SetTranslation((void *)(a0), (void *)(a1))) /* merge_units */

}
struct Xform_0036F530 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0xC];
    M_0036F530 world;
    unsigned char dirty;
    char pad51[0x3F];
    V_0036F530 pos;
    Xform_0036F530* parent;
    M_0036F530 GetWorld() { if (dirty) Update(); const M_0036F530& w = world; return w; }
    int lA4[3];
};
extern "C" void cXformNode_SetTranslation(Xform_0036F530* x, V_0036F530* t)
{
    It b;
    It e;
    Xform_0036F530* p = x->parent;
    if (p) {
        M_0036F530 m = p->GetWorld();
        V_0036F530 v;
        V_0036F530 tmp;
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
        G1_0036F530(&x->pos, &v);
    } else {
        { void* xx = &x->pos; }
        G1_0036F530(&x->pos, t);
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
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opNe /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opInc /* merge_units */
#undef cMatrix_InvertRot /* merge_units */
#undef cMatrix_IsZeroTranslation /* merge_units */
#undef func_00133EC0 /* merge_units */
#undef cVector_ctor_cVectorR /* merge_units */
#undef cVector_NegateXYZ /* merge_units */
#undef cVector_Rotate_cMatrixR /* merge_units */
#undef cMatrix_SetTranslation /* merge_units */
static inline void merge_flush_func_0036F530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036F530 */

/* merge_units: begin func_0036F6E0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
void cArray_cXformNodePtr_End(It6F6E0* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(It6F6E0* a, It6F6E0* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((void *)(a0), (void *)(a1))) /* merge_units */


#if 0 /* merge_units */
void** cArray_cXformNodePtr_ConstIterator_opMul(It6F6E0* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) (cArray_cXformNodePtr_ConstIterator_opMul((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
void cArray_cXformNodePtr_ConstIterator_opInc(It6F6E0* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) (cArray_cXformNodePtr_ConstIterator_opInc((void *)(a0))) /* merge_units */


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
#define cMatrix_InvertRot(a0) ((void)cMatrix_InvertRot((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
int cMatrix_IsZeroTranslation(M_F920* m);
#endif /* merge_units */
#define cMatrix_IsZeroTranslation(a0) (cMatrix_IsZeroTranslation((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
V_F920* func_00133EC0(M_F920* m);
#endif /* merge_units */
#define func_00133EC0(a0) ((V_F920 *)func_00133EC0((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
void cVector_ctor_cVectorR(V_F920* d, V_F920* s);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) (cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */


#if 0 /* merge_units */
void cVector_NegateXYZ(V_F920* v);
#endif /* merge_units */
#define cVector_NegateXYZ(a0) ((void)cVector_NegateXYZ((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
void cVector_Rotate_cMatrixR(V_F920* v, M_F920* m);
#endif /* merge_units */
#define cVector_Rotate_cMatrixR(a0, a1) ((void)cVector_Rotate_cMatrixR((void *)(a0), (void *)(a1))) /* merge_units */


#if 0 /* merge_units */
void cMatrix_SetTranslation(M_F920* m, V_F920* v);
#endif /* merge_units */
#define cMatrix_SetTranslation(a0, a1) (cMatrix_SetTranslation((void *)(a0), (void *)(a1))) /* merge_units */


#if 0 /* merge_units */
void cArray_cXformNodePtr_Begin(It_F920* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
void cArray_cXformNodePtr_End(It_F920* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
int cArray_cXformNodePtr_ConstIterator_opNe(It_F920* a, It_F920* b);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opNe(a0, a1) (cArray_cXformNodePtr_ConstIterator_opNe((void *)(a0), (void *)(a1))) /* merge_units */


#if 0 /* merge_units */
void** cArray_cXformNodePtr_ConstIterator_opMul(It_F920* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) (cArray_cXformNodePtr_ConstIterator_opMul((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
void cArray_cXformNodePtr_ConstIterator_opInc(It_F920* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opInc(a0) (cArray_cXformNodePtr_ConstIterator_opInc((void *)(a0))) /* merge_units */


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
