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
void PtrVector_Resize(void* v, int n, int* fill);
void std_vector_cXformNodePtr_push_back(void* v, struct Xform** p);
M* Mtx_Transpose3x3(M* m);
int Mtx_IsTranslationZero(M* m);
V* func_00133EC0(M* m);
void Vec4_Assign(V* d, V* s);
V* Vec3_Negate(V* a);
V* Mtx_TransformByTranspose(V* a, M* b);
void Mtx_SetTranslation(M* m, V* v);
}
struct XVec { int cap; int size; struct Xform** data; };
struct Xform {
    virtual void v0(); virtual void SetWorld(M* m); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual Xform* GetNode(); virtual void v16(); virtual void Detach(int k); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0xC];
    M world;
    unsigned char dirty;
    char pad51[0x3F];
    V pos;
    Xform* parent;
    M GetWorld() { if (dirty) Update(); const M& w = world; return w; }
    XVec kids;
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
extern "C" void Xform_Attach(Xform* x, Xform* parent, int keep)
{
    Xform* p;
    Xform* self;
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
            M m = self->GetWorld();
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
