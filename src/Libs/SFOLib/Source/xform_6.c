/*
 * Libs/SFOLib/Source/xform: 9 files, 0036FCF0-00370070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036FCF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* 64-byte lq/sq copy as GCC-style volatile asm; the unused `xx` reproduces retail's dead addiu */
struct M4 { __int128 r[4]; };
static inline void GQR(void* d, const void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
extern "C" {
extern char D_004DF6A0[];
extern char D_004DF640[];
}
struct R { int a, b, c; unsigned char own; };
extern "C" R* std_vector_cXformNodePtr_ctor(R* r);
struct XBase {
    void* vt;
    char pad04[0xC];
    M4 m;
    unsigned char dirty;
};
struct X : XBase {
    M4 w;
    int a0;
    R rel;
};
extern "C" X* cXformNode_ctor_cMatrixR(X* x0, M4* m)
{
    R* r;
    X* x = x0;
    M4* d2; M4* d;
    x->vt = D_004DF6A0;
    d = &x->m; GQR(d, m);
    x->dirty = 1;
    x->vt = D_004DF640;
    void* xx = &x->w; /* dead on purpose: retail keeps this addiu */
    d2 = &x->w; GQR(d2, m);
    x->a0 = 0;
    r = &x->rel; std_vector_cXformNodePtr_ctor(r); r->own = 1;
    return x;
}
static inline void merge_flush_func_0036FCF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FCF0 */

/* merge_units: begin func_0036FDA0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern M4 g_IdentityMatrix;
}
extern "C" X* cXformNode_ctor_void(X* x0)
{
    R* r;
    X* x = x0;
    const M4* s2;
    M4* d2;
    const M4* s;
    M4* d;
    x->vt = D_004DF6A0;
    s = &g_IdentityMatrix; d = &x->m; GQR(d, s);
    x->dirty = 1;
    x->vt = D_004DF640;
    void* xx = &x->w; /* dead on purpose: retail keeps this addiu */
    s2 = &g_IdentityMatrix; d2 = &x->w; GQR(d2, s2);
    x->a0 = 0;
    r = &x->rel; std_vector_cXformNodePtr_ctor(r); r->own = 1;
    return x;
}
static inline void merge_flush_func_0036FDA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FDA0 */

/* merge_units: begin func_0036FE60 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_36FE60;
typedef struct { V4_36FE60 r[4]; } M_36FE60;
static inline M_36FE60* QuatToMtx_36FE60(M_36FE60* a, V4_36FE60* b)
{
    asm {
        lqc2 vf1, 0x0(b)
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
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
    return a;
}
static inline void MulRot_36FE60(M_36FE60* s, M_36FE60* d, M_36FE60* r)
{
    asm {
        lqc2 vf4, 0x0(r)
        lqc2 vf5, 0x10(r)
        lqc2 vf6, 0x20(r)
        lqc2 vf8, 0x0(s)
        lqc2 vf9, 0x10(s)
        lqc2 vf10, 0x20(s)
        lqc2 vf11, 0x30(s)
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
        sqc2 vf8, 0x0(d)
        sqc2 vf9, 0x10(d)
        sqc2 vf10, 0x20(d)
        sqc2 vf11, 0x30(d)
    }
}
#pragma opt_common_subs off
void cXform_Rotate_cQuaternionR(V4_36FE60* a, V4_36FE60* q)
{
    M_36FE60 rot;
    QuatToMtx_36FE60(&rot, q);
    MulRot_36FE60((M_36FE60*)(a + 1), (M_36FE60*)(a + 1), &rot);
}
static inline void merge_flush_func_0036FE60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FE60 */

/* merge_units: begin func_0036FF40 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cXform_Rotate_cMatrixR(V4* a, V4* b) {
    char* pv1 = (char*)a + 0x10;
    asm {
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf8, 0x0(pv1)
        lqc2 vf9, 0x10(pv1)
        lqc2 vf10, 0x20(pv1)
        lqc2 vf11, 0x30(pv1)
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
        sqc2 vf8, 0x0(pv1)
        sqc2 vf9, 0x10(pv1)
        sqc2 vf10, 0x20(pv1)
        sqc2 vf11, 0x30(pv1)
    }
}
static inline void merge_flush_func_0036FF40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FF40 */

/* merge_units: begin func_0036FFB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Obj370000 virtual (vtable D_004DF6A0 slot 8).
 */

#include "loose03_types.h"

/* Address of the object's 3x4 matrix. */
Mtx34* cXform_GetMatrix_ParentRelative(Obj370000* self) {
    return &self->mtx;
}
static inline void merge_flush_func_0036FFB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FFB0 */

/* merge_units: begin func_0036FFC0 */
#pragma push /* merge_units */
#pragma peephole off
typedef struct { char pad[0x40]; Vec4 v; } S;
/* Copies the vector at +0x40 of src into dst. */
void cXform_GetTranslation_ParentRelative(Vec4* dst, S* src) { *dst = src->v; }
static inline void merge_flush_func_0036FFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FFC0 */

/* merge_units: begin func_0036FFD0 */
#pragma push /* merge_units */
typedef struct { __int128 q[4]; } M36FFD0;
typedef struct { char pad[0x10]; M36FFD0 m; } S36FFD0;
#pragma peephole off
void cXform_SetMatrix_ParentRelative(S36FFD0* dst, M36FFD0* src)
{
    M36FFD0* d = &dst->m;
    __int128 qa, qb;
    qa = src->q[0]; qb = src->q[1];
    d->q[0] = qa; qa = src->q[2];
    d->q[1] = qb; qb = src->q[3];
    d->q[2] = qa;
    d->q[3] = qb;
}
#pragma peephole reset
static inline void merge_flush_func_0036FFD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036FFD0 */

/* merge_units: begin func_00370000 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Obj370000 virtual (vtable D_004DF6A0 slot 12).
 */


/* Copy a 3x4 matrix into self->mtx (xyz of each row first, then the w column). */
void cXform_SetRotationMatrix_ParentRelative(Obj370000* self, Mtx34* src) {
    self->mtx.m[0][0] = src->m[0][0];
    self->mtx.m[0][1] = src->m[0][1];
    self->mtx.m[0][2] = src->m[0][2];
    self->mtx.m[1][0] = src->m[1][0];
    self->mtx.m[1][1] = src->m[1][1];
    self->mtx.m[1][2] = src->m[1][2];
    self->mtx.m[2][0] = src->m[2][0];
    self->mtx.m[2][1] = src->m[2][1];
    self->mtx.m[2][2] = src->m[2][2];
    self->mtx.m[0][3] = src->m[0][3];
    self->mtx.m[1][3] = src->m[1][3];
    self->mtx.m[2][3] = src->m[2][3];
}
static inline void merge_flush_func_00370000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00370000 */

/* merge_units: begin func_00370070 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct { char pad[0x40]; Q v; } Obj40;

/* Copies a quadword into the object's field at +0x40. */
void cXform_SetTranslation_ParentRelative(Obj40* obj, Q* v)
{
    obj->v = *v;
}
static inline void merge_flush_func_00370070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00370070 */
