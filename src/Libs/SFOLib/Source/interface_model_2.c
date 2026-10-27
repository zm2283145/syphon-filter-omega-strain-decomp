/*
 * Libs/SFOLib/Source/interface_model: 4 files, 003ED040-003ED240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ED040 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z; } Vec3_003ED040;
extern float Libc_Cosf(float a);
extern float Libc_Sinf(float a);
/* Build a rotation matrix from Euler angles (x, y, z). */
Mtx44* cMatrix_ctor_cEulerAngleTR_2(Mtx44* m, Vec3_003ED040* angles)
{
    /* declaration order chosen to reproduce the original register allocation */
    float z;
    float cy;
    float czcx;
    float sx;
    float cx;
    float sy;
    float czsx;
    float szsx;
    float sz;
    float y;
    float x;
    float szcx;
    float cz;
    x = angles->x;
    y = angles->y;
    z = angles->z;
    cx = Libc_Cosf(x);
    sx = Libc_Sinf(x);
    cy = Libc_Cosf(y);
    sy = Libc_Sinf(y);
    cz = Libc_Cosf(z);
    sz = Libc_Sinf(z);
    czsx = cz * sx;
    szsx = sz * sx;
    szcx = sz * cx;
    czcx = cz * cx;
    m->m[0][0] = cz * cy;
    m->m[0][1] = sz * cy;
    m->m[0][2] = -sy;
    m->m[1][0] = czsx * sy - szcx;
    m->m[1][1] = czcx + szsx * sy;
    m->m[1][2] = cy * sx;
    m->m[2][0] = szsx + czcx * sy;
    m->m[2][1] = szcx * sy - czsx;
    m->m[2][2] = cy * cx;
    m->m[0][3] = 0.0f;
    m->m[1][3] = 0.0f;
    m->m[2][3] = 0.0f;
    m->m[3][0] = 0.0f;
    m->m[3][1] = 0.0f;
    m->m[3][2] = 0.0f;
    m->m[3][3] = 1.0f;
    return m;
}
static inline void merge_flush_func_003ED040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED040 */

/* merge_units: begin func_003ED170 */
#pragma push /* merge_units */
#include "vu0_ops.h"
int cEulerAngle_T_1_2_IsZero(void* v) {
    return VU0_IsZero3(v);
}
static inline void merge_flush_func_003ED170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED170 */

/* merge_units: begin func_003ED1B0 */
#pragma push /* merge_units */
typedef struct { __int128 r[4]; } M_D1B0;
typedef struct { char pad[0xA74]; int top; char flag; char pad2[7]; M_D1B0 m[8]; } S_D1B0;
void XLib_AppendView(S_D1B0* s, M_D1B0* b) {
    M_D1B0* t = &s->m[s->top];
    asm {
        lqc2 vf4, 0x0(t)
        lqc2 vf5, 0x10(t)
        lqc2 vf6, 0x20(t)
        lqc2 vf7, 0x30(t)
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
        sqc2 vf12, 0x0(t)
        sqc2 vf13, 0x10(t)
        sqc2 vf14, 0x20(t)
        sqc2 vf15, 0x30(t)
    }
    s->flag = 1;
}
static inline void merge_flush_func_003ED1B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED1B0 */

/* merge_units: begin func_003ED240 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

void cXViewport_SetPersp(Unk3ED240* self) {
    self->unk106 = 1;
    self->unk104 = 0;
}
static inline void merge_flush_func_003ED240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED240 */
