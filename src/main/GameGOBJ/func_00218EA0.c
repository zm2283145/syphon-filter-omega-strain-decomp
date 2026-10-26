#pragma cplusplus on
#include "types.h"
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
struct M { V r[4]; M() {} M(const M& o); };
static inline V Add(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return r;
}
struct Vec { int pad; };
class ObjB {
public:
    virtual void f08(); virtual void f0C(); virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1C(); virtual void f20(); virtual void f24();
    virtual void f28(); virtual M GetMatrix(); virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3C(); virtual void f40(); virtual void f44();
    virtual void f48(); virtual void f4C(); virtual void f50(); virtual void f54(); virtual void Update();
};
class Obj : public ObjB {
public:
    char pad4[0x3C];
    V m40;
    unsigned char b50;
};
struct Holder { char pad[0x50]; Obj* p50; };
struct PathObj { char pad[0x6C]; Holder* p6C; char pad70[0x24]; Vec v94; };
extern "C" {
V* std_vector_cVector_opIndex(Vec* v, int i);
int func_00219060(Vec* v);
V* Vec4_Assign(V* d, V* s);
V* Mtx_Multiply4(V* v, M* m);
}
static inline V* At(Vec* v, int i) {
    if (i < 0) i = 0;
    if (i < func_00219060(v)) return std_vector_cVector_opIndex(v, i);
    return std_vector_cVector_opIndex(v, func_00219060(v) - 1);
}
/* Tf is wrapped once more (Tf2) so its temp lands below Add's result on the stack */
static inline void Tf(V* t2, V* p, M* m) { V t; Vec4_Assign(t2, Mtx_Multiply4(Vec4_Assign(&t, p), m)); }
static inline void Tf2(V* t2, V* p, M* m) { Tf(t2, p, m); }
static inline V Calc2(V* p, M* m, const V& pos) {
    V t2;
    Tf2(&t2, p, m);
    { void* xx = &t2; /* dead on purpose: retail keeps this addiu */ }
    V* pt = &t2;
    return Add(*pt, pos);
}
extern "C" void PathObj_GetPoint(PathObj* self, V* out, int idx)
{
    if (self->p6C) {
        Obj* o = self->p6C->p50;
        if (o->b50) o->Update();
        V pos;
        { const V* ps = &o->m40; V* pp = &pos; QC(pp, ps); }
        M m = o->GetMatrix();
        V r2 = Calc2(At(&self->v94, idx), &m, pos);
        QC(out, &r2);
        out->w = 1.0f;
    } else {
        QC(out, At(&self->v94, idx));
    }
}
