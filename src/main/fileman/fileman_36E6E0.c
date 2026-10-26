/*
 * main/fileman: 9 files, 0036E6E0-0036ECF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036E6E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cXformNodePtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0036E6E0 */

/* merge_units: begin func_0036E7D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)
struct MP { __int128 q[4]; };
struct M {
    __int128 q[4];
    M() {}
    M(const MP& o) { *(MP*)this = o; }
    M& operator=(const M& o) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    M(const M& o) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
};
static inline void M4Mul(void* o, void* a, void* b) {
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf7, 0x30(a)
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
        sqc2 vf12, 0x0(o)
        sqc2 vf13, 0x10(o)
        sqc2 vf14, 0x20(o)
        sqc2 vf15, 0x30(o)
    }
}
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void GMul(void* o, void* a, void* b) {
    __asm__ volatile("lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); lqc2 $vf8, 0x0(%2); lqc2 $vf9, 0x10(%2); lqc2 $vf10, 0x20(%2); lqc2 $vf11, 0x30(%2); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w; vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w; vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w; sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline void GQS(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(qa), "=&r"(qb) : "r"(s), "r"(d) : "memory"); }
struct Obj {
    VPAD1(a) virtual void SetR(const M& m); VPAD16(b) VPAD2(c) virtual void Upd();
    char pad4[0xC]; MP mat; unsigned char f50;
};
extern "C" void cXformNode_Transform(Obj* o, MP* m);
void cXformNode_Transform(Obj* o, MP* m)
{
    M b;
    M a;
    if (o->f50) o->Upd();
    { MP* s = &o->mat; M* d = &a; GQS(d, s); }
    M* p = &a;
    M4Mul(p, m, p);
    b = *p;
    o->SetR(b);
}
#pragma pop /* merge_units */
/* merge_units: end func_0036E7D0 */

/* merge_units: begin func_0036E8F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

static inline void M3Mul(void* o, void* a, void* b) {
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        vmulax.xyz ACC, vf4, vf9x
        vmadday.xyz ACC, vf5, vf9y
        vmaddz.xyz vf9, vf6, vf9z
        vmulax.xyz ACC, vf4, vf10x
        vmadday.xyz ACC, vf5, vf10y
        vmaddz.xyz vf10, vf6, vf10z
        vmulax.xyz ACC, vf4, vf11x
        vmadday.xyz ACC, vf5, vf11y
        vmaddz.xyz vf11, vf6, vf11z
        sqc2 vf8, 0x0(o)
        sqc2 vf9, 0x10(o)
        sqc2 vf10, 0x20(o)
        sqc2 vf11, 0x30(o)
    }
}
static inline void GQ2M(void* a, void* b) {
    __asm__ volatile("lqc2 vf1, 0x0(%1); vadd.xyzw vf2, vf1, vf1; vaddw.xyz vf3, vf0, vf0w; vmulx.w vf8, vf0, vf0x; vmulx.w vf9, vf0, vf0x; vmuly.xyzw vf5, vf1, vf2y; vmulz.xyzw vf6, vf1, vf2z; vmulx.xyzw vf4, vf1, vf2x; vmulx.w vf10, vf0, vf0x; vsubay.x ACC, vf3, vf5y; vmsubz.x vf8, vf3, vf6z; vsubw.x vf9, vf5, vf6w; vaddw.x vf10, vf6, vf5w; vaddw.y vf8, vf4, vf6w; vsubax.y ACC, vf3, vf4x; vmsubz.y vf9, vf3, vf6z; vsubw.y vf10, vf6, vf4w; vsubw.z vf8, vf4, vf5w; vaddw.z vf9, vf5, vf4w; vsubax.z ACC, vf3, vf4x; vmsuby.z vf10, vf3, vf5y; sqc2 vf0, 0x30(%0); sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0)" : : "r"(a), "r"(b) : "memory");
}
static inline void GQX(void* d, void* s) { void* ss = s; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(ss) : "memory"); }
extern "C" void cXformNode_Rotate_cQuaternionR(Obj* o, void* q);
void cXformNode_Rotate_cQuaternionR(Obj* o, void* q)
{
    M b;
    M r;
    M a;
    GQ2M(&r, q);
    { void* xx = &r; }
    if (o->f50) o->Upd();
    GQX(&a, &o->mat);
    { void* xx = &a; }
    M* p = &a;
    M3Mul(p, &r, p);
    b = *p;
    o->SetR(b);
}
#pragma pop /* merge_units */
/* merge_units: end func_0036E8F0 */

/* merge_units: begin func_0036EA70 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

extern "C" void cXformNode_Rotate_cMatrixR(Obj* o, MP* m);
void cXformNode_Rotate_cMatrixR(Obj* o, MP* m)
{
    M b;
    M a;
    if (o->f50) o->Upd();
    { MP* s = &o->mat; M* d = &a; GQS(d, s); }
    M* p = &a;
    M3Mul(p, m, p);
    b = *p;
    o->SetR(b);
}
#pragma pop /* merge_units */
/* merge_units: end func_0036EA70 */

/* merge_units: begin func_0036EB80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
static inline void QEB80(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ QEB80(this, &o); }
    V& operator+=(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Xform {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void SetPos(V p); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0x3C];
    V pos;
    unsigned char dirty;
    V GetPos() { if (dirty) Update(); const V& p = pos; return p; }
};
extern "C" void Xform_Translate(Xform* x, const V* d)
{
    x->SetPos(x->GetPos() += *d);
}
#pragma pop /* merge_units */
/* merge_units: end func_0036EB80 */

/* merge_units: begin func_0036EC10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cXformNode_GetMatrix_ParentRelative(char* self) {
    return self + 96;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036EC10 */

/* merge_units: begin func_0036EC20 */
#pragma push /* merge_units */
#include "q4_asm_copy.h"
typedef struct { __int128 q[4]; } M36EC20;
typedef struct { int p; } It36EC20;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0xF]; M36EC20 m60; char padA0[4]; int lA4[3]; } S36EC20;
extern void cArray_cXformNodePtr_Begin(It36EC20* it, void* c);
extern void cArray_cXformNodePtr_End(It36EC20* it, void* c);
extern int cArray_cXformNodePtr_ConstIterator_opNe(It36EC20* a, It36EC20* b);
extern void** cArray_cXformNodePtr_ConstIterator_opMul(It36EC20* it);
extern void cXformNode_SetNeedsUpdate(void* p);
extern void cArray_cXformNodePtr_ConstIterator_opInc(It36EC20* it);

#pragma opt_rotateloops off

void cXformNode_SetMatrix_ParentRelative(S36EC20* o, M36EC20* src)
{
    It36EC20 b;
    It36EC20 e;
    M36EC20* d = &o->m60;
    Q4Copy(d, src);
    if (!o->a50) {
        It36EC20* pe;
        o->a50 = 1;
        cArray_cXformNodePtr_Begin(&b, o->lA4);
        cArray_cXformNodePtr_End(&e, o->lA4);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}
#pragma opt_rotateloops reset
#pragma peephole reset
#pragma pop /* merge_units */
/* merge_units: end func_0036EC20 */

/* merge_units: begin func_0036ECD0 */
#pragma push /* merge_units */
void* cXformNode_GetNode_void(void* self) {
    return self;
}

void* cXformNode_GetNode_void_2(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036ECD0 */

/* merge_units: begin func_0036ECF0 */
#pragma push /* merge_units */
typedef struct { char pad0[0x50]; unsigned char dirty; char pad1[0x4F]; void* parent; } XfNode;
extern void Xform_EvalAncestors(void* p);
extern void Xform_ComputeWorld(XfNode* x);
void Xform_RefreshDirty(XfNode* x)
{
    if (x->dirty) {
        if (x->parent) {
            Xform_EvalAncestors(x->parent);
        }
        Xform_ComputeWorld(x);
        x->dirty = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0036ECF0 */
