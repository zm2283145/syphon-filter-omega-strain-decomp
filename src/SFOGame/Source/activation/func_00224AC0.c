#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V;
static inline void SubV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V operator-(const V& o) const {
        V r;
        SubV(&r, this, &o);
        return r;
    }
    float Dot(const V& o) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 0x6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Box {
    V mn; V mx;
    bool IsEmpty() const { return mn.x > mx.x; }
    V Size() const { return IsEmpty() ? V(0.0f, 0.0f, 0.0f, 0.0f) : mx - mn; }
};
static inline float Dot(const V& a, const V& b) { const V& aa = a; return aa.Dot(b); }
static inline int InBox(const V* p, const Box* b) {
    const V* hi = &b->mx;
    int r;
    asm {
        .set noreorder
        lqc2 vf2, 0(p)
        lqc2 vf1, 0(b)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(hi)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}
struct GObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual const Box* GetBounds();
    char pad04[0x45];
    unsigned char x49;
    char pad4A[2];
    int x4C;
    bool Own();
};
struct LPVec { int count; int cap; GObj** data; };
struct LItP { GObj** p; };
struct LIt {
    LItP q;
    bool operator==(const LIt& o) const { GObj** b = o.q.p; return q.p == b; }
    bool operator!=(const LIt& o) const { return !(*this == o); }
    GObj*& operator*() const { return *q.p; }
    LIt& operator++() { q.p++; return *this; }
};
struct Self { char pad[0x1F4]; LPVec list; };
extern "C" {
extern GObj** std_vector_imp_cGOBJPtr_1_end_void_2(LPVec* v);
extern LIt std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR_2(LPVec* self, GObj** const& src);
extern LIt std_vector_cGOBJPtr_begin(LPVec* v);
extern LIt cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(const LIt& s);
extern int D_004EE780;
GObj* nActivation_FindBestSectorInActivation(const V* p, Self* self);
}
static inline void EndO(LIt* o, LPVec* v) { o->q.p = std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR_2(v, std_vector_imp_cGOBJPtr_1_end_void_2(v)).q.p; }
static inline LIt FirstI(LPVec* v) { return cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(std_vector_cGOBJPtr_begin(v)); }
inline bool GObj::Own() { int d = D_004EE780; return x4C == d; }
GObj* nActivation_FindBestSectorInActivation(const V* p, Self* self)
{
    GObj* found = 0;
    if (self) {
        float best = 0.0f;
        LPVec* v = &self->list;
        LIt cur;
        LIt last;
        EndO(&last, v);
        for (cur = FirstI(v); cur != last; ++cur) {
            GObj* o = *cur;
            if (o && o->x49 == 1 && o->Own()) {
                const Box* b = o->GetBounds();
                if ((unsigned char)InBox(p, b)) {
                    float d = Dot(b->Size(), b->Size());
                    if (!(d <= best)) {
                        best = d;
                        found = o;
                    }
                }
            }
        }
    }
    return found;
}
