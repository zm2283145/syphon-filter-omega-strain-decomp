/*
 * main/game: range (3 files, 00132130-00132280)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

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
