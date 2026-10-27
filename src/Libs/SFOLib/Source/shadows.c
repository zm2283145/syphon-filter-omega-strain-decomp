/*
 * Libs/SFOLib/Source/shadows: 2 files, 003D2970-003D2B20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D2970 */
#pragma push /* merge_units */
static inline float FABS(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern float Libc_Tanf(float x);
void BuildProjection(float m[4][4], float* lo, float* hi, float fov, float x0, float x1, float y0, float y1, float zn, float zf, float aspect, float ay, float depth)
{
    float ta = Libc_Tanf(fov);
    float tb = Libc_Tanf(fov);
    float h;
    float w;
    m[0][0] = (2.0f * zn) / (aspect * ((2.0f * zn) * ta));
    m[1][0] = 0.0f;
    m[2][0] = 0.0f;
    m[3][0] = 0.0f;
    m[0][1] = 0.0f;
    m[1][1] = (2.0f * zn) / (ay * ((2.0f * zn) * tb));
    m[2][1] = 0.0f;
    m[3][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][2] = 0.0f;
    m[2][2] = (zf + zn) / (zf - zn);
    m[3][2] = -(2.0f * zf * zn) / (zf - zn);
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 1.0f;
    m[3][3] = 0.0f;
    w = FABS(x1 - x0); h = FABS(y1 - y0);
    lo[0] = 0.5f * w;
    lo[1] = 0.5f * -h;
    lo[2] = -64.0f;
    lo[3] = 1.0f;
    hi[0] = 0.5f * w;
    hi[1] = 0.5f * h;
    hi[2] = 64.0f;
    hi[3] = 0.0f;
    if (depth > 0.0f) {
        lo[2] = 0.0f;
        hi[2] = 128.0f * depth;
    }
}
static inline void merge_flush_func_003D2970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D2970 */

/* merge_units: begin func_003D2B20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies and the VU0 unit-matrix fill as GCC-style volatile asm; the unused xx keeps retail's dead addiu */
static inline void UnitMtx_2B20(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
struct V2B20 { float x, y, z, w; } __attribute__((aligned(16)));
struct M2B20 { V2B20 r[3]; V2B20 t; };
extern "C" {
extern signed char D_004E1DA0;
extern signed char D_004E1DA8;
extern V2B20 D_00497F20;
extern V2B20 D_00497F30;
V2B20* cVector_ctor_float_float_float_float(V2B20* v, float x, float y, float z, float w);
float cVector_Z_void(V2B20* v);
float Math_Fabs(float f);
void cVector_GetNormalized_void(V2B20* out, V2B20* v);
void cVector_Cross(V2B20* out, V2B20* a, V2B20* b);
V2B20* cVector_Normalize_void(V2B20* v);
V2B20* cVector_ctor_cVectorR(V2B20* d, V2B20* s);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M2B20* m, V2B20* a, V2B20* b, V2B20* c, V2B20* t);
void cMatrix_InvertRot(M2B20* m);
int cMatrix_IsZeroTranslation(M2B20* m);
V2B20* func_00133EC0(M2B20* m);
void cVector_NegateXYZ(V2B20* v);
void cVector_Rotate_cMatrixR(V2B20* v, M2B20* m);
void cMatrix_SetTranslation(M2B20* m, V2B20* v);
}
static inline V2B20& XAxis()
{
    if (!D_004E1DA0) {
        cVector_ctor_float_float_float_float(&D_00497F20, 1.0f, 0.0f, 0.0f, 0.0f);
        D_004E1DA0 = 1;
    }
    return D_00497F20;
}
static inline V2B20& ZAxis()
{
    if (!D_004E1DA8) {
        cVector_ctor_float_float_float_float(&D_00497F30, 0.0f, 0.0f, 1.0f, 0.0f);
        D_004E1DA8 = 1;
    }
    return D_00497F30;
}
extern "C" void BuildLookatMatrix(V2B20* pos, V2B20* dir, M2B20* m)
{
    UnitMtx_2B20(m);
    V2B20 f;
    V2B20 r;
    V2B20 u;
    V2B20 c;
    V2B20 w;
    XAxis();
    ZAxis();
    V2B20* up = Math_Fabs(cVector_Z_void(dir)) < 0.70700002f ? &D_00497F30 : &D_00497F20;
    cVector_GetNormalized_void(&f, dir);
    cVector_Cross(&c, dir, up);
    cVector_ctor_cVectorR(&r, cVector_Normalize_void(&c));
    cVector_Cross(&u, &r, &f);
    cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &r, &f, &u, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    {
        void* xx = &m->t; /* dead on purpose: retail keeps this addiu */
        __int128 q;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(&m->t), "r"(pos) : "memory");
    }
    cMatrix_InvertRot(m);
    if (!cMatrix_IsZeroTranslation(m)) {
        V2B20 t;
        cVector_ctor_cVectorR(&t, func_00133EC0(m));
        cVector_NegateXYZ(&t);
        cVector_Rotate_cMatrixR(&t, m);
        cMatrix_SetTranslation(m, &t);
    }
}
static inline void merge_flush_func_003D2B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D2B20 */
