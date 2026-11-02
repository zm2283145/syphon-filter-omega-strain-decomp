/*
 * SFOGame/Source/playerCamera: 6 files, 00280F20-00281220
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00280F20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "gated_vcall.h"

/* Run virtual slot 0x50 unless suppressed. */
DEFINE_GATED_VCALL(cPlayerCamera_CriticalUpdateMotion, GVc280F20, VPAD16(a) VPAD2(b))
static inline void merge_flush_func_00280F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280F20 */

/* merge_units: begin func_00280F60 */
#pragma push /* merge_units */
typedef struct Cam {
    char pad0[0xCF0];
    int cf0;
    int cf4;
    int cf8;
    char padCFC[8];
    int d04;
    int d08;
    char padD0C[4];
    float d10;
} Cam;
extern int cSplinedMotion_cQuaternion_IsTransitionInProgress(void);
extern void cGameCamera_NextFrame(Cam *c, float dt);
#pragma opt_propagation off
#pragma opt_common_subs off
void PlayerCamera_PreUpdate(Cam *c, float dt)
{
    float d;
    float k;
    float z;
    c->cf0 = c->cf4;
    c->cf4 = c->cf8;
    k = cSplinedMotion_cQuaternion_IsTransitionInProgress() ? 0.125f : -1.0f;
    if (k < 0.0f) {
        c->d10 -= dt;
    } else {
        c->d10 = k;
    }
    z = 0.0f;
    d = c->d10;
    if (d <= z) {
        int tmp;
        int *pt;
        c->d04 = 0;
        tmp = -1;
        pt = &tmp;
        c->d08 = *pt;
        c->d10 = z;
    }
    cGameCamera_NextFrame(c, dt);
}
static inline void merge_flush_func_00280F60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280F60 */

/* merge_units: begin func_00281030 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Run virtual slot 0x48 unless suppressed. */
DEFINE_GATED_VCALL(cPlayerCamera_CriticalNextFrame, GVc281030, VPAD16(a))
static inline void merge_flush_func_00281030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00281030 */

/* merge_units: begin func_00281070 */
#pragma push /* merge_units */
int cBitArray_9_ctor(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = a1 & 255;
    v0 = 0 + 1;
    cond = v1 != v0;
    v0 = 0 + -1;
    if (cond) goto L00281088;
    *(int*)(char*)a0 = v0;
    goto L00281090;
L00281088:;
    *(int*)(char*)a0 = 0;
L00281090:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_00281070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00281070 */

/* merge_units: begin func_002810A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { __int128 q[4];
    M& operator=(const M& o) { const void* s = &o; __int128 qa; __int128 qb; void* d = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct Flag { int v; };
extern "C" {
void Camera_ConstructFov(void*, int*, int, float);
#if 0 /* merge_units */
Flag* cBitArray_9_ctor(Flag*, int);
#endif /* merge_units */
#define cBitArray_9_ctor(a0, a1) ((Flag *)cBitArray_9_ctor((int)(a0), (a1))) /* merge_units */


V* cVector_GetZero(void);
void cVector_ctor_cVectorR(V*, V*);
extern char D_004DCDE0[];
extern float D_004A9328;
extern M g_IdentityMatrix;
}
struct R { int a, b, c, d; };
static inline const int* Id(const R* p) {
    int t;
    const int* r;
    if (p) r = &p->d;
    else { t = -1; r = &t; }
    return r;
}
struct Flags { Flag f[3]; void Init() { Flags* t = this; cBitArray_9_ctor(&t->f[0], 0); cBitArray_9_ctor(&t->f[1], 0); cBitArray_9_ctor(&t->f[2], 0); } };
struct Handle { int a; int id; void Init() { id = -1; a = 0; id = *Id(0); } };
static inline V VZero() { V t; __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(&t) : "memory"); return t; }
struct PlayerCamera {
    char* vtbl;
    char pad04[0x2C];
    int f30;
    char pad34[0xCF0 - 0x34];
    Flags flags;
    Handle h0;
    Handle h1;
    char padD0C[0x8];
    int fD14, fD18, fD1C, fD20;
    char padD24[0x1C];
    V vD40, vD50, vD60;
    float fD70;
    int fD74, fD78;
    char padD7C[4];
    unsigned char bD80, bD81;
    int fD84, fD88;
    char padD8C[4];
    V vD90;
    M mDA0;
};
extern "C" PlayerCamera* cPlayerCamera_ctor(PlayerCamera* self, int* k, float fov)
{
    Camera_ConstructFov(self, k, 0, fov);
    self->vtbl = D_004DCDE0;
    self->flags.Init();
    self->h0.Init();
    self->h1.Init();
    self->fD14 = 0;
    self->fD18 = 0;
    self->fD1C = 0;
    self->fD20 = 0;
    cVector_ctor_cVectorR(&self->vD40, cVector_GetZero());
    cVector_ctor_cVectorR(&self->vD50, cVector_GetZero());
    cVector_ctor_cVectorR(&self->vD60, cVector_GetZero());
    self->fD70 = D_004A9328;
    self->fD74 = 0;
    self->fD78 = 0;
    self->bD80 = 0;
    self->bD81 = 0;
    self->fD84 = 0;
    self->fD88 = 0;
    self->vD90 = VZero();
    self->mDA0 = g_IdentityMatrix;
    self->f30 = 2;
    return self;
}
#undef cBitArray_9_ctor /* merge_units */
static inline void merge_flush_func_002810A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002810A0 */

/* merge_units: begin func_00281220 */
#pragma push /* merge_units */
// cEulerAngle_T<0,1,2>::cEulerAngle_T(const cMatrix&) (playerCamera.cc); twin of 001BD590. Rotation matrices are built by inline axis/angle
// constructors (enum tag selects the axis) so no by-value return temporaries are created.
#pragma cplusplus on
#pragma inline_depth(8)

extern unsigned char D_004A9340[16];
static inline void G1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void G4(void* d, const void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct V_00281220 { float x, y, z, w; V_00281220(const V_00281220& o) { const void* s = &o; void* d = this; G1(d, s); } } __attribute__((aligned(16)));
struct M_00281220;
extern "C" {
float Libc_Atan2f(float y, float x);
float SIN(float);
float COS(float);
void cMatrix_Set_ColumnMajorForm(M_00281220* m, float, float, float, float, float, float, float, float, float);
}
static inline void MulRot(M_00281220* out, const M_00281220* m, const M_00281220* rot)
{
    asm volatile {
        lqc2 vf8, 0x0(rot)
        lqc2 vf9, 0x10(rot)
        lqc2 vf10, 0x20(rot)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddz.xyzw vf12, vf6, vf8z
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddz.xyzw vf13, vf6, vf9z
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddz.xyzw vf14, vf6, vf10z
        vmove.xyzw vf15, vf7
        sqc2 vf12, 0x0(out)
        sqc2 vf13, 0x10(out)
        sqc2 vf14, 0x20(out)
        sqc2 vf15, 0x30(out)
    }
}
struct M_00281220 {
    float m[4][4];
    enum YT { Y_AXIS }; enum ZT { Z_AXIS };
    M_00281220(YT, float a) { float s = SIN(a); float c = COS(a); cMatrix_Set_ColumnMajorForm(this, c, 0.0f, s, 0.0f, 1.0f, 0.0f, -s, 0.0f, c); }
    M_00281220(ZT, float a) { float s = SIN(a); float c = COS(a); cMatrix_Set_ColumnMajorForm(this, c, -s, 0.0f, s, c, 0.0f, 0.0f, 0.0f, 1.0f); }
    M_00281220(const M_00281220& o) { M_00281220* d = this; __int128 qa, qb; const M_00281220* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    M_00281220& operator*=(const M_00281220& r) { MulRot(this, this, &r); return *this; }
    M_00281220 operator*(const M_00281220& o) const { return M_00281220(*this) *= o; }
} __attribute__((aligned(16)));
struct E { float x, y, z; unsigned int pad; };

static inline float Sq(float v) { return v * v; }
static inline float Sqrt(float x) { float r = 0.0f; asm { sqrt.s r, x } return r; }

extern "C" E* cEulerAngle_T_1_2_ctor_cMatrixR_2(E* self, const M_00281220& rotMatrix)
{
    float angle1;
    float angle2;
    V_00281220 axis0(*(const V_00281220*)rotMatrix.m[0]);
    angle2 = Libc_Atan2f(-axis0.y, axis0.x);
    if (D_004A9340[0]) angle2 = -angle2;
    angle1 = Libc_Atan2f(axis0.z, Sqrt(Sq(axis0.x) + Sq(axis0.y)));
    if (D_004A9340[0]) angle1 = -angle1;
    {
        M_00281220 reverse21Matrix = M_00281220(M_00281220::Y_AXIS, -angle1) * M_00281220(M_00281220::Z_AXIS, -angle2);
        M_00281220 reversedMatrix = reverse21Matrix * rotMatrix;
        V_00281220 axis1(*(const V_00281220*)reversedMatrix.m[1]);
        float a = Libc_Atan2f(-axis1.z, axis1.y);
        if (D_004A9340[0]) a = -a;
        self->x = a;
    }
    self->y = angle1;
    self->z = angle2;
    return self;
}
static inline void merge_flush_func_00281220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00281220 */
