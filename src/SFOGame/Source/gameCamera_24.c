/*
 * SFOGame/Source/gameCamera: 10 files, 0017F9F0-001802D0
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

/* merge_units: begin func_00180120 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma opt_common_subs off
#pragma peephole off

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct cQuaternion {
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(const cQuaternion& source) { cQuaternion* refThis = this; const cQuaternion* ps = &source; asm { lq ps, 0(ps); sq ps, 0(refThis) } }
    cQuaternion& operator=(const cQuaternion& source) { cQuaternion* refThis = this; const cQuaternion* ps = &source; { u_long128 reg; asm { lq reg, 0(ps); sq reg, 0(refThis) } } return *refThis; }
    static void VU0Multiply(cQuaternion* result, const cQuaternion* quat0, const cQuaternion* quat1)
    {
        asm {
            lqc2 vf1, 0x0(quat0)
            lqc2 vf2, 0x0(quat1)
            vmul.xyzw vf3, vf1, vf2
            vopmula.xyz ACC, vf1, vf2
            vmaddaw.xyz ACC, vf1, vf2w
            vmaddaw.xyz ACC, vf2, vf1w
            vopmsub.xyz vf4, vf2, vf1
            vsubaz.w ACC, vf3, vf3z
            vmsubay.w ACC, vf0, vf3y
            vmsubx.w vf4, vf0, vf3x
            sqc2 vf4, 0x0(result)
        }
    }
    cQuaternion operator*(const cQuaternion& quaternion) const { cQuaternion result; VU0Multiply(&result, this, &quaternion); return result; }
} __attribute__((aligned(16)));
struct cHermiteSplineControlPoint { cQuaternion mPosition; cQuaternion mTangent; };
struct cControlPoints { cHermiteSplineControlPoint a[2]; cHermiteSplineControlPoint& operator[](int i) { return a[i]; } };
struct cSplinedMotion_QuaternionLERP {
    void* vtable; char pad4[0xC];
    cQuaternion prev;
    cQuaternion curr;
    cQuaternion vel;
    cQuaternion target;
    float damp;
    cControlPoints mControlPoints; /* spline at 0x60 */
    void TeleportByDelta(const cQuaternion& delta);
};
inline void cSplinedMotion_QuaternionLERP::TeleportByDelta(const cQuaternion& delta)
{
    prev = delta * prev;
    curr = delta * curr;
    target = delta * target;
    { cQuaternion& p = mControlPoints[0].mPosition; p = delta * p; }
    { cQuaternion& p = mControlPoints[1].mPosition; p = delta * p; }
}
extern "C" void cSplinedMotion_QuaternionLERP_1_TeleportByDelta(cSplinedMotion_QuaternionLERP* o, const cQuaternion& d) { o->TeleportByDelta(d); }
static inline void merge_flush_func_00180120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00180120 */

/* merge_units: begin func_001802D0 */
#pragma push /* merge_units */
#include "zero_quad_store.h"

#pragma push
#pragma opt_common_subs off
V4 cSplinedMotion_QuaternionLERP_1_InitPos(void) {
    V4 l0;
    V4* q1;
    q1 = &l0;
    asm {
        sqc2 vf0, 0x0(q1)
    }
    return l0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001802D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001802D0 */

/* merge_units: begin func_001802F0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
ZERO_QUAD_STORE(cSplinedMotion_QuaternionLERP_1_ZeroVel)
#pragma opt_common_subs reset
#pragma opt_propagation reset
static inline void merge_flush_func_001802F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001802F0 */

/* merge_units: begin func_00180310 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

/* lq/sq quad copies and VU0 dot/negate/scale as GCC-style volatile asm; the unused xx locals keep retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct VX : V { VX() {} VX(const VX& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
static inline VX ZeroX() { VX z; __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&z) : "memory"); return z; }
static inline float Dot(const V* a, const V* b)
{
    int r;
    float ret = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah $0, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddaz.w ACC, vf0, vf3z; vmaddw.w vf4, vf0, vf3w; qmfc2.ni %1, vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(ret), "=&r"(r) : "r"(a), "r"(b) : "memory");
    return ret;
}
static inline void Neg1(V* v) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(v) : "memory"); }
static inline void Neg(V* d, const V* s) { __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(s) : "memory"); }
static inline void ScaleTo(V* d, const V* v, float k)
{
    int t;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(d), "r"(v), "f"(k) : "memory");
}
static inline void ScaleTo2(V* d, const V* v, float k) { ScaleTo(d, v, k); }
static inline V Scaled(const V& v, float k)
{
    V r;
    ScaleTo2(&r, &v, k);
    return r;
}

static inline void Asg(V* d, const V& s) { *d = s; }
struct Spline {
    char pad0[0x20];
    V a;
    V b;
    float t;
    void Set(const V& na, const V& nb) { V* p = &a; V* q = &a; *q = na; Asg(p + 1, nb); }
};

static inline void SetSc(Spline* s, const V& a, const V& z, float t) { s->Set(a, Scaled(z, t)); }
struct VY : V { VY() {} VY(const VY& o) { V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
static inline VY ZeroY() { VY z; __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&z) : "memory"); return z; }
static inline VY ZeroWY() { return ZeroY(); }
struct Ref { char pad0[0x40]; float f40; };

struct Cam310 {
    char pad0[0x20];
    V p20;
    V p30;
    V p40;
    char pad50[0x10];
    Spline sp;
    Ref* ref;
    float fB4;
    char padB8[8];
    unsigned char bC0;
};

extern "C" {
void cHermiteSplineWithScaledDuration_float_dtor(void* p, int f);
void* opNew_uint_voidP(int size, void* p);
void cHermiteSplineWithScaledDuration_cQuaternion_ctor(void* p, V* a, V* b, V* c, V* d, float t);
}

extern "C" void cSplinedMotion_QuaternionLERP_1_UpdateSplinePoints(Cam310* c)
{
    Ref* r = c->ref; bool go = 0; float f = r->f40; bool eq = c->fB4 == f; if (eq && !(c->sp.t <= 0.0f)) go = 1;
    if (go) {
        if (c->bC0) {
            V* p = &c->p40;
            if (Dot(p, &c->p20) < 0.0f)
                Neg1(p);
        }
        VX z = ZeroX();
        cHermiteSplineWithScaledDuration_float_dtor(&c->sp, -1);
        void* p = opNew_uint_voidP(0x50, &c->sp);
        if (p)
            cHermiteSplineWithScaledDuration_cQuaternion_ctor(p, &c->p20, &c->p30, &c->p40, &z, c->sp.t);
    } else {
        bool zf = c->fB4 == 0.0f;
        if ((zf != 0) ^ 1) {
            if (c->bC0) {
                const V* pa = &c->sp.a;
                if (Dot(&c->p40, pa) < 0.0f)
                    Neg(&c->p40, &c->p40);
            }
            VY z = ZeroWY();
            __int128 tt = 0; /* dead paddub */
            SetSc(&c->sp, c->p40, z, c->sp.t);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00180310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00180310 */

/* merge_units: begin func_00180550 */
#pragma push /* merge_units */
void cSplinedMotion_QuaternionLERP_1_FixUpResultOfSplineEvaluation(V4* a) {
    char* pv1 = (char*)a + 0x20;
    asm {
        lqc2 vf1, 0x0(pv1)
        vmul.xyzw vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddaz.w ACC, vf0, vf2z
        vmaddw.w vf3, vf0, vf2w
        vrsqrt Q, vf0w, vf3w
        vwaitq 
        vmulq.xyzw vf4, vf1, Q
        sqc2 vf4, 0x0(pv1)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00180550(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00180550 */
