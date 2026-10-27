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




