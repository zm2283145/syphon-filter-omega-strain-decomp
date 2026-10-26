#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Box { V mn; V mx; };
class XV {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
};
struct Sph { unsigned char on; unsigned char local; char pad2[2]; float r; char pad8[8]; V c; };
struct MNode : XV { char pad4[0xC]; M m; unsigned char dirty; char pad51[0x150 - 0x51]; Sph sph; char pad[0x1D0 - 0x170]; };
struct NIt { MNode* p; NIt() {} NIt(const NIt& o) : p(o.p) {} };
struct NVec; struct NIt;
extern "C" {
MNode* std_vector_imp_cBone_begin(NVec* v);
MNode* std_vector_imp_cBone_end(NVec* v);
void std_vector_cBone_pointer2iterator(NIt* out, NVec* v, MNode* const& p);
void Ptr_Identity(V* v);
V* Vec4_Copy(V* d, const V* s);
void Mtx_Multiply4(V* v, M* m);
V* func_00133EC0(M* m);
void Vec4_Set(V* d, float x, float y, float z, float w);
void Sphere_FromCenter(V* d, const V* c, const V* r);
void Box_ExtendXYZ(Box* b, const V* v);
void Vec4_Add(V* d, const V* a, const V* b);
}
static inline void Mk(NIt* r, NVec* v, MNode* p) { MNode* const& q = p; std_vector_cBone_pointer2iterator(r, v, q); }
struct NVec {
    int x0;
    NIt begin() { NIt r; Mk(&r, this, std_vector_imp_cBone_begin(this)); return r; }
    NIt end() { NIt r; Mk(&r, this, std_vector_imp_cBone_end(this)); return r; }
};
static inline bool operator==(const NIt& a, const NIt& b) { MNode* y = b.p; MNode* x = a.p; return x == y; }
static inline bool operator!=(const NIt& a, const NIt& b) { return !(a == b); }
struct Ctx { char pad[0x18]; NVec nodes; char pad1C[0x14]; Box box; };
extern "C" void ModelCtx_ComputeBounds(Ctx* c);
void ModelCtx_ComputeBounds(Ctx* c)
{
    NIt it; NIt e;
    V lo(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    c->box.mn = lo;
    V hi(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    c->box.mx = hi;
    it = c->nodes.begin();
    e = c->nodes.end();
    while (it != e) {
        MNode* n = it.p;
        if (n->dirty) n->Refresh();
        M* m = &n->m;
        Sph* s = &it.p->sph;
        if (s->on) {
            V p;
            Ptr_Identity(&p);
            if (!s->local) Mtx_Multiply4(Vec4_Copy(&p, &s->c), m);
            else Vec4_Copy(&p, func_00133EC0(m));
            float r = s->r;
            if (r > 0.0f) {
                V rv; Vec4_Set(&rv, r, r, r, 0.0f);
                V a; Sphere_FromCenter(&a, &p, &rv);
                Box_ExtendXYZ(&c->box, &a);
                V b; Vec4_Add(&b, &p, &rv);
                Box_ExtendXYZ(&c->box, &b);
            } else {
                Box_ExtendXYZ(&c->box, &p);
            }
        }
        it.p++;
    }
}
