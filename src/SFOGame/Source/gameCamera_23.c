/*
 * SFOGame/Source/gameCamera: 5 files, 0017F9F0-00180110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017F9F0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 a; V4 b; } VP;

extern char D_004DA470[], D_004DA580[], D_004DAD90[], D_004DAD70[], D_004DA440[], D_004DA410[], D_004DA3E0[], D_004DA2F0[];
extern char g_IdentityMatrix[];
extern float D_0048A158, D_0048A160;
extern float D_004A3FC8;
extern signed char D_004E1D80;
extern VP D_00497F00;

void cGOBJ_ctor(void*, int, int, int*);
void cGOBJ_CreateXform(void*, void*, int);
void cCollisionRoutine_cBox_ctor(void*);
V4* cVector_GetZero(void);
void cVector_ctor_cVectorR(void*, V4*);
void cQuaternion_ctor_void(void*);
void cArray_cVector_ctor(void*);
V4 cVector_Get0001(void);
void func_0017F8B0(void*);
float func_0017F860(float);
V4 cQuaternion_GetIdentity(void);
void cQuaternion_ctor_cQuaternionR(void*, V4*);
V4 cQuaternion_GetZero(void);
void cSplinedMotion_cQuaternion_ctor(void*, V4*, V4*);
void cSplinedMotion_cVector_ctor(void*, V4*, V4*);
void cSplinedMotion_float_ctor_floatR_floatR(void*, float*, float*);
void cQuatVec_ctor_cQuaternionR_cVectorR(VP*, V4*, V4*);
void cQuatVec_ctor_cQuatVecR(VP*, VP*);
void cSplinedMotion_Scalar_ctor(void*);
void cCameraShake_cPulsedShakeMagnitude_ctor(void*);
void cSplinedMotion_Vector_ctor(void*);
void cCollisionModelList_ctor(void*, int*, int*);
void cActivationTracker_ctor(void*);

#define F(T, p, o) (*(T*)((char*)(p) + (o)))

static inline void Box_Init(char* b)
{
    F(void*, b, 0) = 0;
    F(float, b, 0x10) = 3.4028235e38f;
    F(float, b, 0x14) = 3.4028235e38f;
    F(float, b, 0x18) = 3.4028235e38f;
    F(float, b, 0x1C) = 1.0f;
    F(float, b, 0x20) = -3.4028235e38f;
    F(float, b, 0x24) = -3.4028235e38f;
    F(float, b, 0x28) = -3.4028235e38f;
    F(float, b, 0x2C) = 1.0f;
    F(int, b, 0x30) = 0;
    F(void*, b, 0x34) = 0;
}

static inline void GObj_Init(char* self, int a1)
{
    int z;
    z = 0;
    cGOBJ_ctor(self, a1, 9, &z);
}

static inline void GObj_Init2(char* self, int a1)
{
    GObj_Init(self, a1);
}

static inline void Rig_Init(char* m0)
{
    char* m = m0;
    V4 t0, t1, t2;
    cCollisionRoutine_cBox_ctor(m);
    F(void*, m, 0) = D_004DAD90;
    cVector_ctor_cVectorR(m + 0x10, cVector_GetZero());
    cQuaternion_ctor_void(m + 0x20);
    cArray_cVector_ctor(m + 0x30);
    t0 = cVector_Get0001();
    cVector_ctor_cVectorR(m + 0x40, &t0);
    t1 = cVector_Get0001();
    cVector_ctor_cVectorR(m + 0x50, &t1);
    F(unsigned char, m, 0x60) = 0;
    t2 = cVector_Get0001();
    cVector_ctor_cVectorR(m + 0x70, &t2);
    F(unsigned char, m, 0x80) = 0;
    func_0017F8B0(m + 0x90);
}

static inline void Fov_Init(char* m0)
{
    char* m = m0;
    V4 q, t;
    cCollisionRoutine_cBox_ctor(m);
    F(void*, m, 0) = D_004DAD70;
    F(unsigned char, m, 4) = 0;
    F(float, m, 8) = func_0017F860(D_004A3FC8);
    q = cQuaternion_GetIdentity();
    cQuaternion_ctor_cQuaternionR(m + 0x10, &q);
    F(int, m, 0x20) = 0;
    F(int, m, 0x24) = 0;
    t = cVector_Get0001();
    cVector_ctor_cVectorR(m + 0x30, &t);
    cVector_ctor_cVectorR(m + 0x40, cVector_GetZero());
}

static inline void QCurve_Init(char* m0, unsigned char on)
{
    char* m = m0;
    V4 q, r;
    q = cQuaternion_GetIdentity();
    r = cQuaternion_GetZero();
    cSplinedMotion_cQuaternion_ctor(m, &q, &r);
    F(void*, m, 0) = D_004DA440;
    F(unsigned char, m, 0xC0) = on;
}

static inline void VCurve_Init(char* m0)
{
    char* m = m0;
    V4 t;
    t = cVector_Get0001();
    cSplinedMotion_cVector_ctor(m, &t, cVector_GetZero());
    F(void*, m, 0) = D_004DA410;
}

static inline void V4Copy(V4* d, V4* s)
{
    __int128 t;
    __asm__ volatile("lq %0, 0(%1)" : "=r"(t) : "r"(s));
    __asm__ volatile("sq %0, 0(%1)" : : "r"(t), "r"(d) : "memory");
}

static inline void VPCopy(VP* d, VP* s)
{
    V4Copy(&d->a, &s->a);
    V4Copy(&d->b, &s->b);
}

static inline void Set4(V4* d, float x, float y, float z, float w)
{
    d->x = x;
    d->y = y;
    d->z = z;
    d->w = w;
}

static inline void Phys_Init(char* m0)
{
    char* m = m0;
    cSplinedMotion_float_ctor_floatR_floatR(m, &D_0048A158, &D_0048A160);
    F(void*, m, 0) = D_004DA3E0;
}

static inline void Track_Init(char* m0)
{
    char* m = m0;
    cSplinedMotion_Scalar_ctor(m);
    cCameraShake_cPulsedShakeMagnitude_ctor(m + 0x38);
    cSplinedMotion_Vector_ctor(m + 0x80);
}

static inline void Tgt_Init(char* m0)
{
    char* m = m0;
    int c, d;
    d = 0;
    c = 0;
    cCollisionModelList_ctor(m, &c, &d);
    F(void*, m, 0) = D_004DA2F0;
    F(int, m, 0x20) = 0;
    cVector_ctor_cVectorR(m + 0x30, cVector_GetZero());
    cActivationTracker_ctor(m + 0x40);
    F(int, m, 0x60) = 0;
}

static inline VP* PlacementIdentity(void)
{
    if (!D_004E1D80) {
        V4 q, o;
        q = cQuaternion_GetIdentity();
        o = cVector_Get0001();
        cQuatVec_ctor_cQuaternionR_cVectorR(&D_00497F00, &q, &o);
        D_004E1D80 = 1;
    }
    return &D_00497F00;
}

void* Camera_ConstructFov(char* self, int a1, float fov, int a2)
{
    int c, d;
    VP p;
    V4 idc;
    V4 id;

    GObj_Init2(self, a1);
    F(void*, self, 0) = D_004DA470;
    F(float, self, 0x60) = 0.5f * fov;
    F(int, self, 0x64) = 0;
    cGOBJ_CreateXform(self, g_IdentityMatrix, 0);
    F(int, self, 0x30) = 0;
    F(void*, self, 0) = D_004DA580;
    Rig_Init(self + 0x70);
    Box_Init(self + 0x130);
    Fov_Init(self + 0x170);
    Box_Init(self + 0x1C0);
    F(unsigned char, self, 0x200) = 0;
    F(unsigned char, self, 0x201) = 1;
    QCurve_Init(self + 0x210, 1);
    VCurve_Init(self + 0x2E0);
    VCurve_Init(self + 0x3A0);
    QCurve_Init(self + 0x460, 0);
    QCurve_Init(self + 0x530, 0);
    VCurve_Init(self + 0x600);
    VCurve_Init(self + 0x6C0);
    QCurve_Init(self + 0x780, 1);
    VCurve_Init(self + 0x850);
    VCurve_Init(self + 0x910);
    VCurve_Init(self + 0x9D0);
    Phys_Init(self + 0xA90);
    PlacementIdentity();
    cQuatVec_ctor_cQuatVecR(&p, &D_00497F00);
    { __int128 t2; V4* ss = &p.a; char* dd = self + 0xAD0; __int128 t1; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t1), "+r"(dd) : "r"(ss) : "memory"); __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t2) : "r"(self + 0xAE0), "r"(&p.b) : "memory"); }
    {
        V4* q1 = &id;
        asm { sqc2 vf0, 0x0(q1) }
    }
    { __int128 t1, t2; __asm__ volatile("lq %0, 0(%5); sq %0, 0(%4); lq %1, 0(%3); sq %1, 0(%2)" : "=&r"(t1), "=&r"(t2) : "r"(self + 0xAF0), "r"(&idc), "r"(&idc), "r"(&id) : "memory"); }
    Set4((V4*)(self + 0xB00), 0.0f, 0.0f, 0.0f, 1.0f);
    Set4((V4*)(self + 0xB10), 0.0f, 0.0f, 0.0f, 1.0f);
    Track_Init(self + 0xB20);
    F(unsigned char, self, 0xC60) = 0;
    F(unsigned char, self, 0xC62) = 0;
    F(float, self, 0xC64) = fov;
    F(float, self, 0xC68) = fov;
    Tgt_Init(self + 0xC70);
    F(int, self, 0xCE8) = a2;
    F(void*, self, 0x130) = self + 0xC70;
    F(void*, self, 0x164) = self + 0x70;
    F(int, self, 0x160) = 1;
    F(void*, self, 0x1C0) = self + 0xC70;
    F(void*, self, 0x1F4) = self + 0x170;
    F(int, self, 0x1F0) = 4;
    F(float, self, 0x4B0) = 15.0f;
    F(float, self, 0x580) = 15.0f;
    F(float, self, 0x650) = 15.0f;
    F(float, self, 0x710) = 15.0f;
    F(float, self, 0x7D0) = 15.0f;
    F(float, self, 0x8A0) = 15.0f;
    F(float, self, 0x960) = 15.0f;
    F(float, self, 0xA20) = 15.0f;
    F(float, self, 0xAA4) = 15.0f;
    F(int, self, 0xCE0) = 0;
    F(unsigned char, self, 0xCE4) = 0;
    return self;
}
static inline void merge_flush_func_0017F9F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F9F0 */

/* merge_units: begin func_00180020 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Adds *delta to the floats at +0x04, +0x08, +0x10, +0x18 and +0x20. */
void cSplinedMotion_float_TeleportByDelta(char* self, float* delta) {
    *(float*)(self + 4) = *(float*)(self + 4) + *delta;
    *(float*)(self + 8) = *(float*)(self + 8) + *delta;
    *(float*)(self + 16) = *(float*)(self + 16) + *delta;
    *(float*)(self + 24) = *(float*)(self + 24) + *delta;
    *(float*)(self + 32) = *(float*)(self + 32) + *delta;
}

float cSplinedMotion_Scalar_InitPos(void) {
    return 0.0f;
}

float cSplinedMotion_Scalar_ZeroVel(void) {
    return 0.0f;
}
static inline void merge_flush_func_00180020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00180020 */

/* merge_units: begin func_001800A0 */
#pragma push /* merge_units */
V4 cSplinedMotion_Vector_InitPos(void) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        sqc2 vf0, 0x0(q1)
    }
    return l0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001800A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001800A0 */

/* merge_units: begin func_001800C0 */
#pragma push /* merge_units */
extern char D_004E1D88;
extern Vec4 D_004E1D90;
void cSplinedMotion_Vector_ZeroVel(Vec4* out) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    *out = D_004E1D90;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001800C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001800C0 */

/* merge_units: begin func_00180110 */
#pragma push /* merge_units */
/* Sets the float at +0x2C to 1.0f. */
void cSplinedMotion_Vector_FixUpResultOfSplineEvaluation(char* self) {
    *(float*)(self + 44) = 1.0f;
}
static inline void merge_flush_func_00180110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00180110 */
