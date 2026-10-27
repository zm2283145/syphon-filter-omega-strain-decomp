/*
 * SFOGame/Source/game: 8 files, 00131F70-00132130
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00131F70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

/* Sets matrix row 2. */
Mtx34* cMatrix_SetZAxis(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[2].x = x;
    m->row[2].y = y;
    m->row[2].z = z;
    m->row[2].w = w;
    return m;
}

/* Sets matrix row 1. */
Mtx34* cMatrix_SetYAxis(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[1].x = x;
    m->row[1].y = y;
    m->row[1].z = z;
    m->row[1].w = w;
    return m;
}

/* Sets matrix row 0. */
Mtx34* cMatrix_SetXAxis(Mtx34* m, Float4* v) {
    float w = v->w, z = v->z, y = v->y, x = v->x;

    m->row[0].x = x;
    m->row[0].y = y;
    m->row[0].z = z;
    m->row[0].w = w;
    return m;
}

Vec4* cVector_ctor_float_float_float_float(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

Vec4* cVector_ctor_cVectorR(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}
static inline void merge_flush_func_00131F70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00131F70 */

/* merge_units: begin func_00132030 */
#pragma push /* merge_units */
#include "vu0_ops.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cVector_Normalize_void(V4* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq 
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132030 */

/* merge_units: begin func_00132060 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4 cVector_GetNormalized_void(V4 v) {
    V4* p = &v;
    asm {
        lqc2 vf1, 0x0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(p)
    }
    return *p;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132060 */

/* merge_units: begin func_001320B0 */
#pragma push /* merge_units */
int cVector_IsZeroXYZ(void* v) {
    return VU0_IsZero3(v);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001320B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001320B0 */

/* merge_units: begin func_001320F0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_common_subs off
V4 cVector_Cross(V4* b, V4* c) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        vsubw.w vf3, vf0, vf0w
        sqc2 vf3, 0x0(q1)
    }
    return l0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001320F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001320F0 */

/* merge_units: begin func_00132130 */
#pragma push /* merge_units */
typedef struct { float m[4][4]; } Mtx_f4;
extern float Libc_Sinf(float);
extern float Libc_Cosf(float);
Mtx_f4* cMatrix_SetWithAxisAngle(Mtx_f4* out, float x, float y, float z, float angle)
{
    float s, c, t;
    float sz, sy, sx, tzx, tyz, txy;
    s = Libc_Sinf(angle);
    c = Libc_Cosf(angle);
    t = 1.0f - c;
    txy = t * x * y;
    tyz = t * y * z;
    tzx = t * z * x;
    sx = s * x;
    sy = s * y;
    sz = s * z;
    out->m[0][0] = c + t * (x * x);
    out->m[0][1] = txy + sz;
    out->m[0][2] = tzx - sy;
    out->m[1][0] = txy - sz;
    out->m[1][1] = c + t * (y * y);
    out->m[1][2] = tyz + sx;
    out->m[2][0] = tzx + sy;
    out->m[2][1] = tyz - sx;
    out->m[2][2] = c + t * (z * z);
    out->m[0][3] = 0.0f;
    out->m[1][3] = 0.0f;
    out->m[2][3] = 0.0f;
    out->m[3][0] = 0.0f;
    out->m[3][1] = 0.0f;
    out->m[3][2] = 0.0f;
    out->m[3][3] = 1.0f;
    return out;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132130 */

/* merge_units: begin func_00132250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


float cVector_Z_void(char* self) {
    return *(float*)(self + 8);
}

float cVector_Y_void(char* self) {
    return *(float*)(self + 4);
}

float cVector_X_void(char* self) {
    return *(float*)(self + 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132250 */

/* merge_units: begin func_00132280 */
#pragma push /* merge_units */
typedef struct Mtx40 {
    float m[16];
} __attribute__((aligned(16))) Mtx40;

typedef struct RootP {
    char pad0000[0x3290];
    void* root; /* 0x3290 */
} RootP;

extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* root);
extern void* cQuatVec_Rotation(void* placement);
extern void* cMatrix_ctor_cQuaternionR(Mtx40* out, void* quat);
extern void* cQuatVec_Translation(void* placement);
extern void cMatrix_Set_cMatrixR_cVectorR(void* out, void* basis, void* pos);

/* Builds the world matrix of obj's root placement into out. */
void cHuman_GetTransform_ForFloorTravel(void* out, RootP* obj) {
    Mtx40 rot;
    void* placement = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(obj->root);
    void* basis = cMatrix_ctor_cQuaternionR(&rot, cQuatVec_Rotation(placement));
    cMatrix_Set_cMatrixR_cVectorR(out, basis, cQuatVec_Translation(placement));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132280 */
