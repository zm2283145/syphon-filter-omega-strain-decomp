/*
 * SFOGame/Source/GameGOBJ: 4 files, 002189E0-00218E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002189E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void VCopyN(void* d, const void* s) {
    __int128 t;
    asm { lq t, 0(s) }
    asm { sq t, 0(d) }
}
/* 16-byte lq/sq copy as GCC-style volatile asm (house idiom, c57da): MW keeps the
   later vcall receiver in a0 (`lw t9,0(a0)`) as retail does. */
static inline void VCopyFF(void* d, const void* s) {
    __int128 t;
    __asm__ volatile("lq %0,0(%2)\n sq %0,0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory");
}
struct Mtx { V4 r[4]; };
struct Plc { float m[3][4]; V4 pos; };
inline void* operator new(unsigned int, void* p) { return p; }
struct Src {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC]; Mtx xform; unsigned char dirty;
};typedef struct { char pad[0x10]; } Elem16;
struct Obj;
extern "C" {
#if 0 /* merge_units */
void PathObj_GetPoint(Obj* o, V4* out, int i);
#endif /* merge_units */
struct PathObj; /* merge_units */
struct V; /* merge_units */
void PathObj_GetPoint(PathObj* self, V* out, int idx); /* merge_units */
#define PathObj_GetPoint(a0, a1, a2) (PathObj_GetPoint((PathObj *)(a0), (V *)(a1), (a2))) /* merge_units */

void cMatrix_Copy_InvertRotTrans(Mtx* out, Mtx* in);
Elem16* func_002181C0(void* v, int i);
int func_002181D0(void* v);
void cPathedGOBJ_TransformAttached(Obj* o, Mtx m, int f);
void cPathedGOBJ_TeleportToPathPoint(Obj* self, int idx);
}
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void SetPlacement(Plc* p);
    char pad4[0x4C]; Src* src; char pad54[0xA4 - 0x54]; char vecA4[0xD0 - 0xA4]; int* pD0; char padD4[0xC]; float fE0;
};static inline Mtx* GetXform(Src* s) {
    if (s->dirty) s->Refresh();
    return &s->xform;
}
static inline void QToM(Mtx* m, Elem16* q) {
    asm {
        lqc2 vf1, 0x0(q)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(m)
        sqc2 vf8, 0x0(m)
        sqc2 vf9, 0x10(m)
        sqc2 vf10, 0x20(m)
    }
}
static inline void Mul(Mtx* po, Mtx* b, Mtx* a) {
    Mtx* pa = a; Mtx* pb = b;
    asm {
        lqc2 vf4, 0x0(pb)
        lqc2 vf5, 0x10(pb)
        lqc2 vf6, 0x20(pb)
        lqc2 vf7, 0x30(pb)
        lqc2 vf8, 0x0(pa)
        lqc2 vf9, 0x10(pa)
        lqc2 vf10, 0x20(pa)
        lqc2 vf11, 0x30(pa)
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
        sqc2 vf12, 0x0(po)
        sqc2 vf13, 0x10(po)
        sqc2 vf14, 0x20(po)
        sqc2 vf15, 0x30(po)
    }
}
static inline void MCopy(Mtx* d, Mtx* ss) { __int128 qa; __int128 qb; Mtx* s = ss; asm {
 lq qa, 0x0(s)
 lq qb, 0x10(s)
 sq qa, 0x0(d)
 lq qa, 0x20(s)
 sq qb, 0x10(d)
 lq qb, 0x30(s)
 sq qa, 0x20(d)
 sq qb, 0x30(d)
 } }
#pragma opt_common_subs off
void cPathedGOBJ_TeleportToPathPoint(Obj* self, int idx) {
    V4 oldPos;
    V4 pt;
    Mtx inv;
    Plc p;
    Mtx mat;
    Elem16* q;
    int i;
    { Src* s = self->src; if (s->dirty) s->Refresh(); VCopyFF(&oldPos, &s->xform.r[3]); }
    PathObj_GetPoint(self, &pt, idx);
    pt.w = 1.0f;
    cMatrix_Copy_InvertRotTrans(&inv, GetXform(self->src));
    i = idx;
    if (idx < 0) i = 0;
    if (i < func_002181D0(self->vecA4)) q = func_002181C0(self->vecA4, i);
    else q = func_002181C0(self->vecA4, func_002181D0(self->vecA4) - 1);
    QToM(&mat, q);
    p.m[0][0] = mat.r[0].x; p.m[0][1] = mat.r[0].y; p.m[0][2] = mat.r[0].z;
    p.m[1][0] = mat.r[1].x; p.m[1][1] = mat.r[1].y; p.m[1][2] = mat.r[1].z;
    p.m[2][0] = mat.r[2].x; p.m[2][1] = mat.r[2].y; p.m[2][2] = mat.r[2].z;
    p.m[0][3] = mat.r[0].w; p.m[1][3] = mat.r[1].w; p.m[2][3] = mat.r[2].w;
    VCopyN(&p.pos, &pt);
    self->SetPlacement(&p);
    { Mtx m; Mtx t; Mul(&t, (Mtx*)&p, &inv); MCopy(&m, &t); cPathedGOBJ_TransformAttached(self, m, 1); }
    *self->pD0 = idx;
    self->fE0 = 1.0f;
}
#undef PathObj_GetPoint /* merge_units */
static inline void merge_flush_func_002189E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002189E0 */

/* merge_units: begin func_00218C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

struct cQuaternion {
    float x, y, z, w;
    cQuaternion() {}
} __attribute__((aligned(16)));

struct cMatrix {
    float m[16];
    cMatrix() {}
    cMatrix(const cQuaternion& q)
    {
        cMatrix* m = this;
        const cQuaternion* qp = &q;
        __asm__(
            "lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x;"
            "vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x;"
            "vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w;"
            "vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w;"
            "vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y;"
            "sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)"
            : : "r"(m), "r"(qp) : "memory");
    }
} __attribute__((aligned(16)));

extern "C" {
float func_001E50E0(const cQuaternion* a, const cQuaternion* b);
cQuaternion cQuaternion_opSub(const cQuaternion* q);
cQuaternion LerpAndNormalize(const cQuaternion* a, const cQuaternion* b, float t);
}

static inline cQuaternion Interp(const cQuaternion& q0, const cQuaternion& q1, float t)
{
    if (func_001E50E0(&q0, &q1) >= 0.0f) return LerpAndNormalize(&q0, &q1, t);
    return LerpAndNormalize(&q0, &cQuaternion_opSub(&q1), t);
}

struct cArray {
    int mUnk;
    volatile int mCount;
    cQuaternion* volatile mData;
    int mCap;
    int Size() const { return mCount; }
    const cQuaternion& Get(int i) const
    {
        if (i < 0) i = 0;
        int n = mCount;
        if (i < n) { int o = i * (int)sizeof(cQuaternion); return *(const cQuaternion*)((const char*)mData + o); }
        i = n - 1;
        int o = i * (int)sizeof(cQuaternion);
        return *(const cQuaternion*)((const char*)mData + o);
    }
};

struct cGOBJ {
    VPAD8(a) VPAD1(b)
    virtual cMatrix GetRot();
};

struct cPathedGOBJ {
    char pad0[0x50];
    cGOBJ* mGob;
    char pad54[0x50];
    cArray mPathQuats;
};

#pragma opt_propagation off
extern "C" cMatrix cPathedGOBJ_GetAdjustedRot(cPathedGOBJ* self, int fromPoint, int toPoint, float currFraction)
{
    if (self->mPathQuats.Size()) {
        const cQuaternion& a = self->mPathQuats.Get(toPoint);
        const cQuaternion& b = self->mPathQuats.Get(fromPoint);
        cQuaternion currQuat = Interp(a, b, currFraction);
        return cMatrix(currQuat);
    }
    return self->mGob->GetRot();
}
static inline void merge_flush_func_00218C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00218C80 */

/* merge_units: begin func_00218E30 */
#pragma push /* merge_units */
typedef struct Src40 {
    char pad[0x10];
    float m[12];
} Src40;

extern void cMatrix_ctor_float_float_float_float_etc(void*, float, float, float, float, float, float, float, float,
                          float, float, float, float, float, float, float, float);

/* Forwards a 3x4 transform from src (+0x10) to cMatrix_ctor_float_float_float_float_etc with (0, 0, 0, 1) appended. */
void cXform_GetRotationMatrix_ParentRelative(void* self, Src40* src) {
    cMatrix_ctor_float_float_float_float_etc(self, src->m[0], src->m[1], src->m[2], src->m[3], src->m[4], src->m[5], src->m[6], src->m[7],
                  src->m[8], src->m[9], src->m[10], src->m[11], 0.0f, 0.0f, 0.0f, 1.0f);
}
static inline void merge_flush_func_00218E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00218E30 */

/* merge_units: begin func_00218EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
class Obj_00218EA0 : public ObjB {
public:
    char pad4[0x3C];
    V m40;
    unsigned char b50;
};
struct Holder { char pad[0x50]; Obj_00218EA0* p50; };
struct PathObj { char pad[0x6C]; Holder* p6C; char pad70[0x24]; Vec v94; };
extern "C" {
V* std_vector_cVector_opIndex(Vec* v, int i);
int func_00219060(Vec* v);
V* cVector_ctor_cVectorR(V* d, V* s);
V* cVector_Transform_cMatrixR(V* v, M* m);
}
static inline V* At(Vec* v, int i) {
    if (i < 0) i = 0;
    if (i < func_00219060(v)) return std_vector_cVector_opIndex(v, i);
    return std_vector_cVector_opIndex(v, func_00219060(v) - 1);
}
/* Tf is wrapped once more (Tf2) so its temp lands below Add's result on the stack */
static inline void Tf(V* t2, V* p, M* m) { V t; cVector_ctor_cVectorR(t2, cVector_Transform_cMatrixR(cVector_ctor_cVectorR(&t, p), m)); }
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
        Obj_00218EA0* o = self->p6C->p50;
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
static inline void merge_flush_func_00218EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00218EA0 */
