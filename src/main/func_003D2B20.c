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
V2B20* func_00132000(V2B20* v, float x, float y, float z, float w);
float Vec4_GetZ(V2B20* v);
float Math_Fabs(float f);
void Vec4_NormalizeXYZ_132060(V2B20* out, V2B20* v);
void Vec4_Cross(V2B20* out, V2B20* a, V2B20* b);
V2B20* Vec4_NormalizeXYZInPlace(V2B20* v);
V2B20* Vec4_Assign(V2B20* d, V2B20* s);
void Mtx_FromRowsAndTranslation(M2B20* m, V2B20* a, V2B20* b, V2B20* c, V2B20* t);
void Mtx_Transpose3x3(M2B20* m);
int Mtx_IsTranslationZero(M2B20* m);
V2B20* func_00133EC0(M2B20* m);
void Vec3_Negate(V2B20* v);
void Mtx_TransformByTranspose(V2B20* v, M2B20* m);
void Mtx_SetTranslation(M2B20* m, V2B20* v);
}
static inline V2B20& XAxis()
{
    if (!D_004E1DA0) {
        func_00132000(&D_00497F20, 1.0f, 0.0f, 0.0f, 0.0f);
        D_004E1DA0 = 1;
    }
    return D_00497F20;
}
static inline V2B20& ZAxis()
{
    if (!D_004E1DA8) {
        func_00132000(&D_00497F30, 0.0f, 0.0f, 1.0f, 0.0f);
        D_004E1DA8 = 1;
    }
    return D_00497F30;
}
extern "C" void Shadow_LookAt(V2B20* pos, V2B20* dir, M2B20* m)
{
    UnitMtx_2B20(m);
    V2B20 f;
    V2B20 r;
    V2B20 u;
    V2B20 c;
    V2B20 w;
    XAxis();
    ZAxis();
    V2B20* up = Math_Fabs(Vec4_GetZ(dir)) < 0.70700002f ? &D_00497F30 : &D_00497F20;
    Vec4_NormalizeXYZ_132060(&f, dir);
    Vec4_Cross(&c, dir, up);
    Vec4_Assign(&r, Vec4_NormalizeXYZInPlace(&c));
    Vec4_Cross(&u, &r, &f);
    Mtx_FromRowsAndTranslation(m, &r, &f, &u, func_00132000(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    {
        void* xx = &m->t; /* dead on purpose: retail keeps this addiu */
        __int128 q;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(&m->t), "r"(pos) : "memory");
    }
    Mtx_Transpose3x3(m);
    if (!Mtx_IsTranslationZero(m)) {
        V2B20 t;
        Vec4_Assign(&t, func_00133EC0(m));
        Vec3_Negate(&t);
        Mtx_TransformByTranspose(&t, m);
        Mtx_SetTranslation(m, &t);
    }
}
