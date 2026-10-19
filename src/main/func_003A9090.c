/* ModelCtx_ComputeCentroid: weighted mean of the node positions (sibling of ModelCtx_ComputeBounds, ModelCtx_ComputeBounds.c) */
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
struct MNode : XV { char pad4[0xC]; M m; unsigned char dirty; char pad51[0x150 - 0x51]; Sph sph; float weight; char pad[0x1D0 - 0x174]; };
struct NIt { MNode* p; NIt() {} NIt(const NIt& o) : p(o.p) {} };
struct NVec; struct NIt;
extern "C" {
MNode* func_001D7B10(NVec* v);
MNode* func_001D7AD0(NVec* v);
void func_001D7B00(NIt* out, NVec* v, MNode* const& p);
void Ptr_Identity(V* v);
V* Vec4_Copy(V* d, const V* s);
void Mtx_Multiply4(V* v, M* m);
V* func_00133EC0(M* m);
void func_00132000(V* d, float x, float y, float z, float w);
void Sphere_FromCenter(V* d, const V* c, const V* r);
void Box_ExtendXYZ(Box* b, const V* v);
void Vec4_Add(V* d, const V* a, const V* b);
}
static inline void Mk(NIt* r, NVec* v, MNode* p) { MNode* const& q = p; func_001D7B00(r, v, q); }
struct NVec {
    int x0;
    NIt begin() { NIt r; Mk(&r, this, func_001D7B10(this)); return r; }
    NIt end() { NIt r; Mk(&r, this, func_001D7AD0(this)); return r; }
};
static inline bool operator==(const NIt& a, const NIt& b) { MNode* y = b.p; MNode* x = a.p; return x == y; }
static inline bool operator!=(const NIt& a, const NIt& b) { return !(a == b); }
struct Ctx { char pad[0x18]; NVec nodes; char pad1C[0x34]; V cent; };
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void AddV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
// 128-bit sq zero store (quadword clear), not expressible in C
static inline void QZero(V* p) { __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(p) : "memory"); }
static inline V Scaled(const V& v, float k) { V r; ScaleV(&r, &v, k); return r; }
static inline void AddTo(V& d, V o) { AddV(&d, &d, &o); }
extern "C" void ModelCtx_ComputeCentroid(Ctx* c);
void ModelCtx_ComputeCentroid(Ctx* c)
{
    NIt it; NIt e;
    float total;
    QZero(&c->cent);
    it = c->nodes.begin();
    e = c->nodes.end();
    total = 0.0f;
    while (it != e) {
        MNode* n = it.p;
        if (n->dirty) n->Refresh();
        const V& pos = n->m.r[3];
        const float& w = it.p->weight;
        if (w != 0.0f) {
            AddTo(c->cent, Scaled(pos, w));
            total += w;
        }
        it.p++;
    }
    if (total != 0.0f) ScaleV(&c->cent, &c->cent, 1.0f / total);
    c->cent.w = 1.0f;
}
