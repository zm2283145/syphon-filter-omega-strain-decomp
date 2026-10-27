/*
 * SFOGame/Source/humanIk: 6 files, 001CF260-001CF400
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CF260 */
#pragma push /* merge_units */
#include "types.h"

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
