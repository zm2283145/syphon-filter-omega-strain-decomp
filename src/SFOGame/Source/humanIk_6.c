/*
 * SFOGame/Source/humanIk: 9 files, 001CF090-001CF260
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CF090 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int* std_vector_imp_cXformNodePtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cXformNodePtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cXformNodePtr_1_begin(PtrVec* v) {
    return v->data;
}

int cArray_cXformNodePtr_ConstIterator_opMul(Word* w) {
    return w->value;
}

void cArray_cXformNodePtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cXformNodePtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End iterator of an array of 0x1D0-byte records. */
void std_vector_cBone_end(Elem1D0Iter* out, Vec1D0Array* v) {
    int count;
    Elem1D0* data;

    count = v->count;
    data = v->data;
    out->p = data + count;
}

Word* cArray_cBone_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_cBone_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_001CF090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF090 */

/* merge_units: begin func_001CF160 */
#pragma push /* merge_units */
#include "v4_asm_copy.h"
typedef struct { __int128 q; } V_F160;
typedef struct { int p; } It_F160;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0x3F]; V_F160 v90; char padA0[4]; int lA4[3]; } S_F160;
#if 0 /* merge_units */
extern void cArray_cXformNodePtr_Begin(It_F160* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void cArray_cXformNodePtr_End(It_F160* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


extern int cArray_cXformNodePtr_ConstIterator_opNe(It_F160* a, It_F160* b);
#if 0 /* merge_units */
extern void** cArray_cXformNodePtr_ConstIterator_opMul(It_F160* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) ((void * *)cArray_cXformNodePtr_ConstIterator_opMul((Word *)(a0))) /* merge_units */


extern void cXformNode_SetNeedsUpdate(void* p);
extern void cArray_cXformNodePtr_ConstIterator_opInc(It_F160* it);
#pragma opt_rotateloops off
void cXformNode_SetTranslation_ParentRelative(S_F160* o, V_F160* src)
{
    It_F160 b;
    It_F160 e;
    V4Copy(&o->v90, src);
    if (!o->a50) {
        It_F160* pe;
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
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
static inline void merge_flush_func_001CF160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF160 */

/* merge_units: begin func_001CF1F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; float m[12]; } Src1CF;
#if 0 /* merge_units */
extern void cMatrix_ctor_float_float_float_float_etc(Mtx44* m, float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
                      float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
#endif /* merge_units */
Mtx44* cMatrix_ctor_float_float_float_float_etc(Mtx44* m, float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33); /* merge_units */
#define cMatrix_ctor_float_float_float_float_etc(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) ((void)cMatrix_ctor_float_float_float_float_etc((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7), (a8), (a9), (a10), (a11), (a12), (a13), (a14), (a15), (a16))) /* merge_units */


/* Builds a 4x4 matrix from the 3x4 block at +0x60 of src, with (0, 0, 0, 1) as the last column. */
void cXformNode_GetRotationMatrix_ParentRelative(Mtx44* out, Src1CF* s)
{
    cMatrix_ctor_float_float_float_float_etc(out, s->m[0], s->m[1], s->m[2], s->m[3], s->m[4], s->m[5], s->m[6], s->m[7],
              s->m[8], s->m[9], s->m[10], s->m[11], 0.0f, 0.0f, 0.0f, 1.0f);
}
#undef cMatrix_ctor_float_float_float_float_etc /* merge_units */
static inline void merge_flush_func_001CF1F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF1F0 */

/* merge_units: begin func_001CF260 */
#pragma push /* merge_units */
/* Sets all 16 matrix elements (row-major) and returns the matrix. */
Mtx44* cMatrix_ctor_float_float_float_float_etc(Mtx44* m, float m00, float m01, float m02, float m03,
                     float m10, float m11, float m12, float m13,
                     float m20, float m21, float m22, float m23,
                     float m30, float m31, float m32, float m33)
{
    m->m[0][0] = m00; m->m[0][1] = m01; m->m[0][2] = m02; m->m[0][3] = m03;
    m->m[1][0] = m10; m->m[1][1] = m11; m->m[1][2] = m12; m->m[1][3] = m13;
    m->m[2][0] = m20; m->m[2][1] = m21; m->m[2][2] = m22; m->m[2][3] = m23;
    m->m[3][0] = m30; m->m[3][1] = m31; m->m[3][2] = m32; m->m[3][3] = m33;
    return m;
}
static inline void merge_flush_func_001CF260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF260 */

/* merge_units: begin func_001CF2D0 */
#pragma push /* merge_units */
#include "pp_quad_copy.h"
#include "vu0_ops.h"
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cMatrix_GetRotated(PPMtx* out, PPMtx* in, PPMtx* m) {
    PPMtx t;
    PPMtx* ps = &t;
    PPMtx* pd = &t;
    PP_COPY4(pd, in)
    VU0_MulRows33(ps, m);
    PP_COPY4(out, ps)
}
#pragma pop
static inline void merge_flush_func_001CF2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF2D0 */

/* merge_units: begin func_001CF380 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cMatrix_Translate(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x30(a)
        lqc2 vf2, 0x0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x30(a)
    }
    return a;
}
static inline void merge_flush_func_001CF380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF380 */

/* merge_units: begin func_001CF3A0 */
#pragma push /* merge_units */
#include "vu_byval.h"

#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
/* v is a by-value V4 (the ABI passes its address) */
V4 cVector_GetRotated(V4* vp, void* m) {
    VU_BYVAL(V4, vp, p)
    asm {
        lqc2 vf8, 0x0(p)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(p)
    }
    return *p;
}
#pragma pop
static inline void merge_flush_func_001CF3A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF3A0 */

/* merge_units: begin func_001CF3F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x90]; Vec4 v; } Obj90;
/* Copies the vector at +0x90 out. */
#pragma peephole off
void cXformNode_GetTranslation_ParentRelative(Vec4* out, Obj90* o) { *out = o->v; }
#pragma peephole reset
static inline void merge_flush_func_001CF3F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF3F0 */

/* merge_units: begin func_001CF400 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } B8V_1B28E0;
typedef struct { char pad[0x40]; float s; float inv; } B8S_1B28E0;
extern void cQuaternion_opMul_float(B8V_1B28E0* out, B8V_1B28E0* in, float s);
extern void cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(B8S_1B28E0* p, int a, B8V_1B28E0* b, int c, B8V_1B28E0* d);
void cHermiteSplineWithScaledDuration_cQuaternion_Reset_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(void* pv, int a, B8V_1B28E0* b, int c, B8V_1B28E0* d) {
    B8V_1B28E0 v1;
    B8V_1B28E0 v2;
    float s;
    float inv;
    B8S_1B28E0* p = (B8S_1B28E0*)pv;
    if (p) {
        s = ((B8S_1B28E0*)pv)->s;
        cQuaternion_opMul_float(&v1, b, s);
        cQuaternion_opMul_float(&v2, d, s);
        cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(p, a, &v1, c, &v2);
        p->s = s;
        inv = (s != 0.0f) ? 1.0f / s : 0.0f;
        p->inv = inv;
    }
}
static inline void merge_flush_func_001CF400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF400 */
