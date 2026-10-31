#pragma cplusplus on
typedef unsigned char u8;
#pragma always_inline on
#pragma inline_depth(8)

struct V;
extern "C" {
void cGOBJ_UpdateMotion(void*, float);
V* CameraCol_Sweep(void*, V*);
void Camera_UpdateZoom(void*, void*, float);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_NextFrame(void*, float);
int cSplinedMotion_float_IsTransitionInProgress(void*);
float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Evaluate(void*);
void cSplinedMotion_cQuaternion_RestartTransition(void*, float);
void std_vector_deleter_cVector_clear(void*);
float Libc_Atanf(float);
float Libc_Tanf(float);
V* cVector_Rotate_cMatrixR(void*, void*);
void cCollisionSystem_cBox_NextFrame(void*, void*, float);
void* cQuatVec_Invert(void*);
void cSplinedMotion_float_NextFrame(void*, float, float);
V* cVector_ctor_cVectorR(V*, const V*);
void cVector_opAssign(void*, const void*);
void cVector_Copy_WSet1(V*, const V*);
void cSplinedMotion_cVector_RestartTransition(void*, float);
void cSplinedMotion_cVector_SetTargetVal(void*, V*);
void* cQuatVec_ctor_cQuatVecR(void*, const void*);
void cSplinedMotion_cVector_NextFrame(void*, float, float);
void* cVector_ctor_float_float_float_float(void*, float, float, float, float);
void cQuaternion_opAssign(void*, const void*);
void cSplinedMotion_cVector_ResetCurrValAndResetCurrVelocity(void*, V*, V*);
void cArray_cVector_PushBackActual(void*, V*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_Evaluate(V*, void*);
int cSplinedMotion_cVector_IsTransitionInProgress(void*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame(void*, float);
char* cHermiteSpline_cVector_ControlPoint(void*, int);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(V*, void*);
int func_0017D510(void*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(void*, float);
float nGameUnits_Sec(float);
void* cMatrix_ctor_cEulerAngleTR(void*, void*);
void* cEulerAngle_T_1_2_ctor_float_float_float(void*, float, float, float);
int RAND(void);
float cCameraShake_cPulsedShakeMagnitude_GetCurrVal(void*);
float* cSplinedMotion_float_GetCurrVal(void*);
void cCameraShake_cPulsedShakeMagnitude_NextFrame(void*, float, float);
extern float D_0048A170;
extern float D_0048A178;
}

static inline void Cp(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { float m[4][4]; } __attribute__((aligned(16)));
struct M4 { float m[4][4]; } __attribute__((aligned(16)));
struct Plc { V rot; V pos; } __attribute__((aligned(16)));

static inline void ScaleEq(V* v, float k) { int t; asm { .set noreorder
    lqc2 vf1, 0x0(v)
    mfc1 t, k
    qmtc2.ni t, vf2
    vmulx.xyzw vf1, vf1, vf2x
    sqc2 vf1, 0x0(v)
    .set reorder } }
static inline V Scaled(const V& a_, float k) { V r; int t; V* rp = &r; const V* a = &a_; asm { .set noreorder
    lqc2 vf1, 0x0(a)
    mfc1 t, k
    qmtc2.ni t, vf2
    vmulx.xyzw vf1, vf1, vf2x
    sqc2 vf1, 0x0(rp)
    .set reorder } return r; }
static inline void Add3(V* d, const V* s) { asm {
    lqc2 vf1, 0x0(d)
    lqc2 vf2, 0x0(s)
    vadd.xyz vf1, vf1, vf2
    sqc2 vf1, 0x0(d) } }
static inline void SubP(V* rp, const V* a, const V* b) { __asm__ volatile ("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" :  : "r"(a), "r"(b), "r"(rp) : "memory"); }
static inline V Sub2(const V& a, const V& b) { V r; const V* ap; const V* bp; V* rp; ap = &a; bp = &b; rp = &r; SubP(rp, ap, bp); return r; }
static inline void QMulP(V* rp, const V* q, const V* p) { __asm__ volatile ("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%2)" :  : "r"(q), "r"(p), "r"(rp) : "memory"); }
static inline V QMul2(const V& q, const V& p) { V r; const V* pp; const V* qp; V* rp; qp = &q; pp = &p; rp = &r; QMulP(rp, qp, pp); return r; }
static inline V SubV(const V& a_, const V& b_) { V r; V* rp = &r; const V* a = &a_; const V* b = &b_; __asm__ volatile ("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" :  : "r"(a), "r"(b), "r"(rp) : "memory"); return r; }
static inline V Neg(const V& a_) { V r; V* rp = &r; const V* a = &a_; asm {
    lqc2 vf1, 0x0(a)
    vmulax.xyzw ACC, vf0, vf0x
    vmsubw.xyzw vf1, vf1, vf0w
    sqc2 vf1, 0x0(rp) } return r; }
static inline float Dot3(const V& a, const V& b) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&a), "r"(&b) : "memory"); return r; }
static inline V QMul(const V& q_, const V& p_) { V r; V* rp = &r; const V* q = &q_; const V* p = &p_; __asm__ volatile ("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%2)" :  : "r"(q), "r"(p), "r"(rp) : "memory"); return r; }
static inline void QRot(V* v, const V* q) { asm {
    lqc2 vf1, 0x0(v)
    vmove.w vf6, vf1
    vmr32.w vf1, vf0
    lqc2 vf2, 0x0(q)
    vmove.w vf3, vf2
    vsub.xyz vf3, vf0, vf2
    vmul.xyzw vf4, vf2, vf1
    vopmula.xyz ACC, vf2, vf1
    vmaddaw.xyz ACC, vf1, vf2w
    vopmsub.xyz vf5, vf1, vf2
    vsubaz.w ACC, vf4, vf4z
    vmsubay.w ACC, vf0, vf4y
    vmsubx.w vf5, vf0, vf4x
    vopmula.xyz ACC, vf5, vf3
    vmaddaw.xyz ACC, vf5, vf3w
    vmaddaw.xyz ACC, vf3, vf5w
    vopmsub.xyz vf6, vf3, vf5
    sqc2 vf6, 0x0(v) } }
static inline M QToM(const V& q_) { M m; M* mp = &m; const V* q = &q_; asm {
    lqc2 vf1, 0x0(q)
    vadd.xyzw vf2, vf1, vf1
    vaddw.xyz vf3, vf0, vf0w
    vmulx.w vf8, vf0, vf0x
    vmulx.w vf9, vf0, vf0x
    vmuly.xyzw vf5, vf1, vf2y
    vmulz.xyzw vf6, vf1, vf2z
    vmulx.xyzw vf4, vf1, vf2x
    vmulx.w vf10, vf0, vf0x
    vsubay.x ACC, vf3, vf5y
    vmsubz.x vf8, vf3, vf6z
    vsubw.x vf9, vf5, vf6w
    vaddw.x vf10, vf6, vf5w
    vaddw.y vf8, vf4, vf6w
    vsubax.y ACC, vf3, vf4x
    vmsubz.y vf9, vf3, vf6z
    vsubw.y vf10, vf6, vf4w
    vsubw.z vf8, vf4, vf5w
    vaddw.z vf9, vf5, vf4w
    vsubax.z ACC, vf3, vf4x
    vmsuby.z vf10, vf3, vf5y
    sqc2 vf0, 0x30(mp)
    sqc2 vf8, 0x0(mp)
    sqc2 vf9, 0x10(mp)
    sqc2 vf10, 0x20(mp) } return m; }
static inline void QToMp(M* mp, const V* q) { asm {
    lqc2 vf1, 0x0(q)
    vadd.xyzw vf2, vf1, vf1
    vaddw.xyz vf3, vf0, vf0w
    vmulx.w vf8, vf0, vf0x
    vmulx.w vf9, vf0, vf0x
    vmuly.xyzw vf5, vf1, vf2y
    vmulz.xyzw vf6, vf1, vf2z
    vmulx.xyzw vf4, vf1, vf2x
    vmulx.w vf10, vf0, vf0x
    vsubay.x ACC, vf3, vf5y
    vmsubz.x vf8, vf3, vf6z
    vsubw.x vf9, vf5, vf6w
    vaddw.x vf10, vf6, vf5w
    vaddw.y vf8, vf4, vf6w
    vsubax.y ACC, vf3, vf4x
    vmsubz.y vf9, vf3, vf6z
    vsubw.y vf10, vf6, vf4w
    vsubw.z vf8, vf4, vf5w
    vaddw.z vf9, vf5, vf4w
    vsubax.z ACC, vf3, vf4x
    vmsuby.z vf10, vf3, vf5y
    sqc2 vf0, 0x30(mp)
    sqc2 vf8, 0x0(mp)
    sqc2 vf9, 0x10(mp)
    sqc2 vf10, 0x20(mp) } }
static inline void MulRot(V* v, const M4* m) { asm {
    lqc2 vf8, 0x0(v)
    lqc2 vf4, 0x0(m)
    lqc2 vf5, 0x10(m)
    lqc2 vf6, 0x20(m)
    vmulax.xyz ACC, vf4, vf8x
    vmadday.xyz ACC, vf5, vf8y
    vmaddz.xyz vf8, vf6, vf8z
    sqc2 vf8, 0x0(v) } }
static inline float ClampA(float x, float lo, float hi) { float r = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float ClampC(float lo, float hi, float x) { float r = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float ClampE(float x_, float lo_, float hi) { float lo = lo_; float x = x_; float r = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float ClampB(float x, float hi, float lo) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2; min.s %0, %0, %3" : "+f"(r) : "f"(x), "f"(lo), "f"(hi)); return r; }
static inline float ClampM(float x, float lo, float hi) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2; min.s %0, %0, %3" : "+f"(r) : "f"(x), "f"(lo), "f"(hi)); return r; }
static inline float ClampN(float hi, float x, float lo) { float r = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }

static inline V Pt(const V& v_) { const V* v; v = &v_; V r(*v); V* p = &r; p->w = 1.0f; return *p; }
static inline V MulV(const V* a_, float k) { V r; int tt; V* d = &r; const V* a = a_; asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 tt, k
        qmtc2.ni tt, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    } return r; }
static inline void XformPt(V* v_, Plc* p)
{
    const V* q; V* v; q = &p->rot; v = v_;
    QRot(v, q);
    float* pw = &v->w;
    float w = *pw;
    if (1.0f == w) {
        Add3(v, &p->pos);
    } else {
        V tq = MulV(&p->pos, w);
        Add3(v, &tq);
        float* pw2 = &v->w; *pw2 = tq.w;
    }
}
static inline V PtW(const V& v) { return Pt(v); }
static inline void XW(V* v, Plc* p) { XformPt(v, p); }
static inline V NegW(const V& a) { return Neg(a); }
static inline V AddV(const V& a, const V& b) { V w(a); Add3(&w, &b); return w; }
static inline V AddW(const V& a, const V& b) { return AddV(a, b); }
static inline void Neg3(V* out, const V& a_) { V r; const V* a; V* rp; a = &a_; rp = &r; asm {
    lqc2 vf1, 0x0(a)
    vmulax.xyzw ACC, vf0, vf0x
    vmsubw.xyzw vf1, vf1, vf0w
    sqc2 vf1, 0x0(rp) } *out = r; }
static inline void NegP2(V* out, const V& a) { Neg3(out, a); }
static inline void AddV3(V* out, const V& a, const V& b) { V w(a); const V* bp = &b; V* wp = &w; Add3(wp, bp); *out = *wp; }
static inline void AddP2(V* out, const V& a, const V& b) { AddV3(out, a, b); }
static inline void ToWorld(V* out, char* t, Plc* p, const V& in)
{
    V r(PtW(in));
    V* rp = &r;
    XW(rp, p);
    {
        V o(*(V*)(t + 0xBC0));
        Add3(rp, &o);
    }
    *out = *rp;
}
static inline void Inv4(Plc* inv, Plc* p) { Plc a; cQuatVec_ctor_cQuatVecR(inv, cQuatVec_Invert(cQuatVec_ctor_cQuatVecR(&a, p))); }
static inline void Inv5(Plc* inv, Plc* p) { Inv4(inv, p); }
static inline void Inv3(Plc* inv, Plc* p) { Inv5(inv, p); }
static inline void Inv2(Plc* inv, Plc* p) { Inv3(inv, p); }
static inline void Inv1(Plc* inv, Plc* p) { Inv2(inv, p); }
static inline V MulVTo_(const V* a_, float k) { return MulV(a_, k); }
static inline void MulVTo(V* out, const V* a_, float k_) { V r; int tt; V* d = &r; const V* a = a_; float k = k_; asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 tt, k
        qmtc2.ni tt, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    } *out = *d; }
static inline void XformPtL(V* v_, Plc* p)
{
    V* v = v_;
    QRot(v, &p->rot);
    float* pw = &v->w;
    float w = *pw;
    if (1.0f == w) {
        Add3(v, &p->pos);
    } else {
        V tq;
        MulVTo(&tq, &p->pos, w);
        Add3(v, &tq);
        float* pw2 = &v->w; *pw2 = tq.w;
    }
}
static inline void XL3(V* v, Plc* p) { XformPtL(v, p); }
static inline void XL2(V* v, Plc* p) { XL3(v, p); }
static inline void ToLocal(V* out, char* t, Plc* p, const V& in)
{
    V r;
    V n;
    V o;
    Plc inv;
    Plc* ip;
    Inv1(&inv, p);
    ip = &inv;
    o = *(V*)(t + 0xBC0);
    V* op = &o;
    V* np = &n;
    NegP2(np, *op);
    AddP2(&r, in, n);
    V* rp = &r;
    XL2(rp, &inv);
    *out = *rp;
}
typedef void (*VF1)(void*);
typedef void (*VF2)(void*, float, float);
typedef V (*VF3)(void*);
struct Obj {
    virtual void s08();
    virtual void s0C(void*);
    virtual void s10(void*);
    virtual V s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20(float, float);
    virtual void s24(); virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44(); virtual void s48();
    virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58();
};
#define O(c) ((Obj*)(c))


static inline void QStep(char* c, float dt, float inv)
{
    cQuaternion_opAssign(c + 0x10, c + 0x20);
    O(c)->s18();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(c + 0xB0, dt);
    if (func_0017D510(c)) {
        V q;
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(&q, c + 0xB0);
        cQuaternion_opAssign(c + 0x20, &q);
        O(c)->s1C();
    } else {
        cQuaternion_opAssign(c + 0x20, c + 0x40);
    }
    O(c)->s20(dt, inv);
}
static inline void VStep(char* c, float dt, float inv)
{
    cVector_opAssign(c + 0x10, c + 0x20);
    O(c)->s18();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame(c + 0xB0, dt);
    if (cSplinedMotion_cVector_IsTransitionInProgress(c)) {
        V q;
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_Evaluate(&q, c + 0xB0);
        cVector_opAssign(c + 0x20, &q);
        O(c)->s1C();
    } else {
        cVector_opAssign(c + 0x20, c + 0x40);
    }
    O(c)->s20(dt, inv);
}
static inline void Reset(char* c)
{
    *(V*)(c + 0x10) = *(V*)(c + 0x20) = *(V*)(c + 0x40);
    *(V*)(c + 0x30) = O(c)->s14();
}
static inline void Retime(char* c, float d_)
{
    float d = d_;
    float k;
    float r;
    if (d < 0.0f) return;
    k = d * *(float*)(c + 0x44);
    ScaleEq((V*)(cHermiteSpline_cVector_ControlPoint(c, 0) + 0x10), k);
    ScaleEq((V*)(cHermiteSpline_cVector_ControlPoint(c, 1) + 0x10), k);
    *(float*)(c + 0x40) = d;
    r = 0.0f; if (r != d) r = 1.0f / d; else asm { .set reorder } *(float*)(c + 0x44) = r;
    *(float*)(c + 0x54) = *(float*)(*(char**)(c + 0x50) + 0x40);
}
static inline void RetimeS(char* c, float d_)
{
    float d = d_;
    float k;
    float r;
    if (d < 0.0f) return;
    k = d * *(float*)(c + 0x2C);
    *(float*)(c + 0x1C) *= k;
    *(float*)(c + 0x24) *= k;
    *(float*)(c + 0x28) = d;
    r = 0.0f; if (r != d) r = 1.0f / d; else asm { .set reorder } *(float*)(c + 0x2C) = r;
    *(float*)(c + 0x34) = *(float*)(*(char**)(c + 0x30) + 0x10);
}
static inline void Reset1(char* c) { Reset(c); }
static inline u8 HitU(char* s) { return *(u8*)(s + 0x60); }
static inline bool Hit(char* s) { return *(u8*)(s + 0x60); }
static inline void RetimeMax(char* c, float d_) { float d = d_; if (*(float*)(c + 0x54) <= d) Retime(c, d); }
static inline u8 IsZ(float f) { return f == 0.0f; }
static inline bool NBS(u8 b) { return !(b != 0); }

static inline void Shake5(char* t)
{
        float s = *cSplinedMotion_float_GetCurrVal(t + 0xB20) + cCameraShake_cPulsedShakeMagnitude_GetCurrVal(t + 0xB58);
        if (s > 0.0f) {
            V a;
            V q;
            M m;
            V e;
            V p;
            void* qp = cVector_ctor_float_float_float_float(&q, 0.0f, s, 0.0f, 0.0f);
            cVector_ctor_cVectorR(&a, cVector_Rotate_cMatrixR(qp, cMatrix_ctor_cEulerAngleTR(&m, cEulerAngle_T_1_2_ctor_float_float_float(&e, (float)RAND(), 0.0f, (float)RAND()))));
            cVector_Copy_WSet1(&p, &a);
            cSplinedMotion_cVector_SetTargetVal(t + 0xBA0, &p);
        }
}
static inline void Shake6(char* t) { Shake5(t); }
static inline void Shake4(char* t) { Shake6(t); }
static inline void Shake3(char* t) { Shake4(t); }
static inline void Shake2(char* t) { Shake3(t); }
static inline void Shake1(char* t) { Shake2(t); }
static inline void QS5(char* c, float dt, float inv) { QStep(c, dt, inv); }
static inline void QS4(char* c, float dt, float inv) { QS5(c, dt, inv); }
static inline void QS3(char* c, float dt, float inv) { QS4(c, dt, inv); }
static inline void QS2(char* c, float dt, float inv) { QS3(c, dt, inv); }
static inline void QS1(char* c, float dt, float inv) { QS2(c, dt, inv); }
static inline void VS5(char* c, float dt, float inv) { VStep(c, dt, inv); }
static inline void VS4(char* c, float dt, float inv) { VS5(c, dt, inv); }
static inline void VS3(char* c, float dt, float inv) { VS4(c, dt, inv); }
static inline void VS2(char* c, float dt, float inv) { VS3(c, dt, inv); }
static inline void VS1(char* c, float dt, float inv) { VS2(c, dt, inv); }
#define F(o) (*(float*)(t + (o)))
#define VV(o) (*(V*)(t + (o)))
#define PP(o) (*(Plc*)(t + (o)))
#define B(o) (*(u8*)(t + (o)))

static inline V QMul4(const V& q, const V& p) { return QMul2(q, p); }
static inline V QMul3(const V& q, const V& p) { return QMul4(q, p); }
static inline void G1b(V* g_, V* d_, V* s_, V* e_) { V* s; V* d; V* g; V* e; g = g_; d = d_; s = s_; e = e_; *d = *g; *e = *s; }
static inline void G1(char* t)
{
    V g(QMul3(VV(0xAD0), VV(0x7A0)));
    G1b(&g, &VV(0x250), &VV(0xAE0), &VV(0x320));
}

static inline void UpOf2(V* up, V* q) { M m; QToMp(&m, q); V* r = (V*)&m; r++; *up = *r; }
static inline void UpOf1(V* up, V* q) { UpOf2(up, q); }
static inline void UpOfS(char* s, V* q) { M m; QToMp(&m, q); V* r = (V*)&m; r++; V* up = (V*)(s + 0x10); *up = *r; }
static inline void ColSet(char* s2_, V* rot_, V* pos_, V* c_) { char* s2 = s2_; V* rot; V* c; V* pos; rot = rot_; pos = pos_; c = c_; UpOfS(s2, rot); *(V*)(s2 + 0x20) = *rot; *(V*)(s2 + 0x40) = *c; *(V*)(s2 + 0x50) = *pos; }
static inline void Toward(char* t, V* lp, V* a)
{
    V d0 = Sub2(*lp, *a);
    V d1 = Sub2(*lp, VV(0xAF0));
    if (!(Dot3(d0, d1) <= 0.0f && F(0xAF4) != 0.0f)) Retime(t + 0x8B0, 0.067f);
    else Retime(t + 0x8B0, 0.5f);
}
static inline void Cur5(char* t, V* lp) { V cur = O(t + 0x910)->s14(); cSplinedMotion_cVector_ResetCurrValAndResetCurrVelocity(t + 0x910, lp, &cur); }
static inline void Cur6(char* t, V* lp) { Cur5(t, lp); }
static inline void Cur4(char* t, V* lp) { Cur6(t, lp); }
static inline void Cur3(char* t, V* lp) { Cur4(t, lp); }
static inline void Cur2(char* t, V* lp) { Cur3(t, lp); }
static inline void Cur1(char* t, V* lp) { Cur2(t, lp); }
static inline V RotBy(const V& v, M4* w) { V o(v); V* op = &o; MulRot(op, w); return *op; }
static inline void AddT(M4* d, const V* s) { __asm__ volatile ("lqc2 $vf1, 0x30(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x30(%0)" :  : "r"(d), "r"(s) : "memory"); }
static inline void AddRot(M4* w, const V& v) { V oo(RotBy(v, w)); AddT(w, &oo); }
static inline void Fill(M4* w, char* t)
{
    M m;
    const V* q = &VV(0x230);
    V* pp = (V*)(t + 0x300);
    QToMp(&m, q);
    w->m[0][0] = ((M4*)&m)->m[0][0]; w->m[0][1] = ((M4*)&m)->m[0][1]; w->m[0][2] = ((M4*)&m)->m[0][2];
    w->m[1][0] = ((M4*)&m)->m[1][0]; w->m[1][1] = ((M4*)&m)->m[1][1]; w->m[1][2] = ((M4*)&m)->m[1][2];
    w->m[2][0] = ((M4*)&m)->m[2][0]; w->m[2][1] = ((M4*)&m)->m[2][1]; w->m[2][2] = ((M4*)&m)->m[2][2];
    w->m[0][3] = ((M4*)&m)->m[0][3]; w->m[1][3] = ((M4*)&m)->m[1][3]; w->m[2][3] = ((M4*)&m)->m[2][3];
    V* dp = (V*)w->m[3];
    *dp = *pp;
    AddRot(w, VV(0x9F0));
    {
        V b(VV(0xBC0));
        M4* wp = w;
        V* bp = &b;
        AddT(wp, bp);
    }
}
#define XX_UNUSED
extern "C" void cGameCamera_UpdateMotion(char* t_, float dt_)
{
    char* t = t_;
    char* x;
    char* s2;
    bool moving;
    float dt = dt_;
    float inv;
    V c1;
    V c0;

    if (dt == 0.0f || !B(0x200)) return;
    inv = 1.0f / dt;
    cSplinedMotion_float_NextFrame(t + 0xB20, dt, inv);
    cCameraShake_cPulsedShakeMagnitude_NextFrame(t + 0xB58, dt, inv);
    Shake1(t);

    cSplinedMotion_cVector_RestartTransition(t + 0xBA0, nGameUnits_Sec(0.01f));
    cSplinedMotion_cVector_NextFrame(t + 0xBA0, dt, inv);
    if (B(0x201)) {
        cSplinedMotion_cQuaternion_RestartTransition(t + 0x210, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x2E0, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x3A0, 0.0f);
        cSplinedMotion_cQuaternion_RestartTransition(t + 0x460, 0.0f);
        cSplinedMotion_cQuaternion_RestartTransition(t + 0x530, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x600, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x6C0, 0.0f);
        cSplinedMotion_cQuaternion_RestartTransition(t + 0x780, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x850, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x910, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x9D0, 0.0f);
    }
    QS1(t + 0x460, dt, inv);
    VV(0x570) = VV(0x480);
    QS1(t + 0x530, dt, inv);
    Retime(t + 0x660, 0.15f);
    VS1(t + 0x600, dt, inv);
    VV(0x700) = VV(0x620);
    Retime(t + 0x720, 0.15f);
    VS1(t + 0x6C0, dt, inv);
    QS1(t + 0x780, dt, inv);
    G1(t);
    if (!B(0xC61)) VV(0x3E0) = VV(0x320);
    QS1(t + 0x210, dt, inv);
    VS1(t + 0x2E0, dt, inv);
    VS1(t + 0x3A0, dt, inv);

    s2 = *(char**)(t + 0x164);
    moving = NBS(IsZ(F(0x9C4)));
    if (B(0xC60)) {
        char* a0 = *(char**)(t + 0x130);
        Plc pl;
        O(a0)->s10(t + 0x3C0);
        V* pp = (V*)(t + 0x300);
        pl.rot = VV(0x230);
        pl.pos = *pp;
        ToWorld(&c0, t, &pl, VV(0xAF0));
        ToWorld(&c1, t, &pl, VV(0x930));
        ColSet(s2, &pl.rot, &pl.pos, &VV(0x3C0));
        std_vector_deleter_cVector_clear(s2 + 0x30);
        cArray_cVector_PushBackActual(s2 + 0x30, &c0);
        cArray_cVector_PushBackActual(s2 + 0x30, &c1);
        cCollisionSystem_cBox_NextFrame(t + 0x130, t, dt);
    }
    if (B(0xC60)) {
        V hit(*CameraCol_Sweep(s2, &c0));
        Plc pl;
        V lp;
        V* pp = (V*)(t + 0x300);
        pl.rot = VV(0x230);
        pl.pos = *pp;
        ToLocal(&lp, t, &pl, hit);
        if (HitU(s2) == 0) {
            if (moving) RetimeMax(t + 0x8B0, 0.067f);
            else Retime(t + 0x8B0, 0.5f);
        } else if (moving) {
            Toward(t, &lp, &VV(0x890));
        } else {
            Toward(t, &lp, &VV(0x870));
        }
        VV(0x890) = lp;
    } else {
        VV(0x890) = VV(0xAF0);
    }
    VS1(t + 0x850, dt, inv);
    VV(0x950) = VV(0x870);
    VS1(t + 0x910, dt, inv);
    if (B(0xC60)) {
        Plc pl;
        V w;
        V up;
        V hit;
        V lp;
        u8 col;
        V* pp = (V*)(t + 0x300);
        pl.rot = VV(0x230);
        pl.pos = *pp;
        ToWorld(&w, t, &pl, VV(0x930));
        UpOf2(&up, &pl.rot);
        hit =  *CameraCol_Sweep(s2, &w);
        ToLocal(&lp, t, &pl, hit);
        col = HitU(s2);
        Retime(t + 0xA30, 0.067f);
        if (col) {
            Cur1(t, &lp);
        }
        V* dst = &VV(0xA10);
        *dst = lp;
    } else {
        VV(0xA10) = VV(0x930);
    }
    VS1(t + 0x9D0, dt, inv);
    if (B(0x201)) {
        Reset1(t + 0x210);
        Reset1(t + 0x2E0);
        Reset1(t + 0x3A0);
        Reset1(t + 0x460);
        Reset1(t + 0x530);
        Reset1(t + 0x600);
        Reset1(t + 0x6C0);
        Reset1(t + 0x780);
        Reset1(t + 0x850);
        Reset1(t + 0x910);
        Reset1(t + 0x9D0);
        B(0x201) = 0;
    }
    {
        M4 w;
        Fill(&w, t);
        {
            char* x2 = *(char**)(t + 0x50);
            O(x2)->s0C(&w);
        }
        VV(0xB10) = *(V*)w.m[3];
    }
    {
        float d = F(0xC68) - F(0xC64);
        d = ClampC(-D_0048A170, D_0048A170, d);
        float e = D_0048A178 * (d * dt);
        float a = F(0xC64) + e;
        F(0xC64) = ClampM(a, 0.00017453292f, 3.1414182f);
        F(0xC68) = F(0xC64);
    }
    {
        float lim = 1.1170107f;
        float fov = F(0xC64);
        float f;
        u8 z = HitU(t + 0x114);
        if (fov < lim) {
            x = *(char**)(t + 0x50);
            if (*(u8*)(x + 0x50)) O(x)->s58();
            Camera_UpdateZoom(t + 0x170, x + 0x10, F(0xC64));
            cCollisionSystem_cBox_NextFrame(t + 0x1C0, t, dt);
            f = F(0x178);
        } else {
            f = fov;
        }
        float k = 0.15f;
        F(0xAA0) = 1.0f / (1.0f / Libc_Tanf(0.5f * f));
        RetimeS(t + 0xA90, k);
    }
    F(0xA94) = F(0xA98);
    O(t + 0xA90)->s18();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_NextFrame(t + 0xAC0, dt);
    if (cSplinedMotion_float_IsTransitionInProgress(t + 0xA90)) {
        F(0xA98) = cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Evaluate(t + 0xAC0);
        O(t + 0xA90)->s1C();
    } else {
        F(0xA98) = F(0xAA0);
    }
    O(t + 0xA90)->s20(dt, inv);
    F(0x60) = 0.5f * (2.0f * Libc_Atanf(1.0f / (1.0f / F(0xA98))));
    cGOBJ_UpdateMotion(t, dt);
}
