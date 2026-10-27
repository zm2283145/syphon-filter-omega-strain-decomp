/*
 * SFOGame/Source/NIEvent: 2 files, 0023E180-0023E3D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023E180 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    V operator-(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
} __attribute__((aligned(16)));
struct Mtx {
    V r0, r1, r2, t;
    Mtx() {}
    Mtx(const Mtx& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
};
static inline V Cross(const V& a, const V& b) { V r; V* rp = &r; const V* ap = &a; const V* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vopmula.xyz $ACC, $vf1, $vf2; vopmsub.xyz $vf3, $vf2, $vf1; vsubw.w $vf3, $vf0, $vf0w; sqc2 $vf3, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
static inline V& Unit(V& v) { V* p = &v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return v; }
struct Sub {
    VPAD1(a)
    virtual void SetMtx(Mtx* m);
    VPAD16(b) VPAD2(c)
    virtual void Sync();
    char pad4[0xC];
    Mtx m;
    unsigned char f50;
};
struct Obj { char pad[0x50]; Sub* sub; };
extern "C" {
extern char g_CameraObject[];
int func_00159570(void*);
Obj** cLList_cCAMERA_GOBJPtr_Front(void*);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(Mtx* m, V* a, V* b, V* c, V* t);
Mtx cNIEventBase_ParentXform(void* node);
}
static inline Obj* GetCam() { return func_00159570(g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) : 0; }
static inline const V& SubPos(Sub* o) { if (o->f50) o->Sync(); return o->m.t; }

struct Ev_3E180 { char pad[0x94]; void* node; char pad98[0xE0 - 0x98]; V pos; };
static inline void MulM(V* v, Mtx* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline V Xform0(const V& p, Mtx& m0) { V t = p; Mtx* mp = &m0; V* tp = &t; MulM(tp, mp); return *tp; }
static inline V Xform(const V& p, Mtx m) { return Xform0(p, m); }
extern "C" Mtx cNIEventBase_MakeFacingMat(Ev_3E180* ev)
{
    Obj* c = GetCam();
    if (c) {
        V cam = SubPos(c->sub);
        V me;
        if (ev->node) me = Xform(ev->pos, cNIEventBase_ParentXform(ev->node));
        else me = ev->pos;
        V dir = cam - me;
        Unit(dir);
        V up(0.0f, 0.0f, 1.0f, 0.0f);
        V right = Cross(dir, up);
        up = Cross(right, dir);
        Mtx m;
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(&m, &right, &dir, &up, &me);
        return m;
    }
}
static inline void merge_flush_func_0023E180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E180 */

/* merge_units: begin func_0023E3D0 */
#pragma push /* merge_units */
/* Recursive time-scale propagation: the original's recursive inline expanded four levels,
   leaving out-of-line size()/operator[] template clones at each level. */
#pragma cplusplus on
struct Obj_0023E3D0;
struct Vec { int cap; int n; Obj_0023E3D0** p; };
struct Obj_0023E3D0 { char pad[0x9C]; Vec v; char padA8[0x134 - 0xA8]; float f134; };
extern "C" {
Obj_0023E3D0*** std_vector_pod_int_data(Vec*);
int std_vector_pod_int_size(Vec*);
int std_vector_imp_cNIEventBasePtr_1_size(Vec*);
int std_vector_cNIEventBasePtr_size(Vec*);
int cArray_cNIEventBasePtr_Size(Vec*);
Obj_0023E3D0** std_vector_imp_cNIEventBasePtr_1_opIndex(Vec*, int);
Obj_0023E3D0** std_vector_cNIEventBasePtr_opIndex(Vec*, int);
Obj_0023E3D0** cArray_cNIEventBasePtr_opIndex(Vec*, int);
void cNIEventBase_SetSpeed(Obj_0023E3D0* o, float t);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void cNIEventBase_SetSpeed(Obj_0023E3D0* o, float t)
{
    o->f134 = t;
    for (int i = 0; i < o->v.n; i++) {
        Obj_0023E3D0* a = (*std_vector_pod_int_data(&o->v))[i];
        a->f134 = t;
        for (int j = 0; j < std_vector_pod_int_size(&a->v); j++) {
            Obj_0023E3D0* b = *std_vector_imp_cNIEventBasePtr_1_opIndex(&a->v, j);
            b->f134 = t;
            for (int k = 0; k < std_vector_imp_cNIEventBasePtr_1_size(&b->v); k++) {
                Obj_0023E3D0* c = *std_vector_cNIEventBasePtr_opIndex(&b->v, k);
                c->f134 = t;
                for (int l = 0; l < std_vector_cNIEventBasePtr_size(&c->v); l++) {
                    Obj_0023E3D0* d = *cArray_cNIEventBasePtr_opIndex(&c->v, l);
                    d->f134 = t;
                    for (int m = 0; m < cArray_cNIEventBasePtr_Size(&d->v); m++)
                        cNIEventBase_SetSpeed(*cArray_cNIEventBasePtr_opIndex(&d->v, m), t);
                }
            }
        }
    }
}

#pragma pop
static inline void merge_flush_func_0023E3D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023E3D0 */
