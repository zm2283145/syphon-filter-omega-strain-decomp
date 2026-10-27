#pragma cplusplus on
#include "types.h"
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
void cMatrix_InvertRot(M_F920* m);
int cMatrix_IsZeroTranslation(M_F920* m);
V_F920* func_00133EC0(M_F920* m);
void cVector_ctor_cVectorR(V_F920* d, V_F920* s);
void cVector_NegateXYZ(V_F920* v);
void cVector_Rotate_cMatrixR(V_F920* v, M_F920* m);
void cMatrix_SetTranslation(M_F920* m, V_F920* v);
void cArray_cXformNodePtr_Begin(It_F920* it, void* c);
void cArray_cXformNodePtr_End(It_F920* it, void* c);
int cArray_cXformNodePtr_ConstIterator_opNe(It_F920* a, It_F920* b);
void** cArray_cXformNodePtr_ConstIterator_opMul(It_F920* it);
void cXformNode_SetNeedsUpdate(void* p);
void cArray_cXformNodePtr_ConstIterator_opInc(It_F920* it);
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


