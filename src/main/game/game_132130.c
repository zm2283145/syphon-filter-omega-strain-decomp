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
extern float Math_Sin(float);
extern float Math_Cos(float);
Mtx_f4* Mtx_MakeAxisRotation(Mtx_f4* out, float x, float y, float z, float angle)
{
    float s, c, t;
    float sz, sy, sx, tzx, tyz, txy;
    s = Math_Sin(angle);
    c = Math_Cos(angle);
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


float Vec4_GetZ(char* self) {
    return *(float*)(self + 8);
}

float Vec4_GetY(char* self) {
    return *(float*)(self + 4);
}

float Vec4_GetX(char* self) {
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

extern void* Root_GetWorldPlacement(void* root);
extern void* Placement_GetQuat(void* placement);
extern void* Quat_ToMatrix(Mtx40* out, void* quat);
extern void* Placement_GetPosition(void* placement);
extern void Mtx_FromBasisAndPosition(void* out, void* basis, void* pos);

/* Builds the world matrix of obj's root placement into out. */
void Actor_GetRootWorldMatrix(void* out, RootP* obj) {
    Mtx40 rot;
    void* placement = Root_GetWorldPlacement(obj->root);
    void* basis = Quat_ToMatrix(&rot, Placement_GetQuat(placement));
    Mtx_FromBasisAndPosition(out, basis, Placement_GetPosition(placement));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00132280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00132280 */
