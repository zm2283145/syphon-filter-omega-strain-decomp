/*
 * SFOGame/Source/humanIk: 1 file, 001D40E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D40E0 */
#pragma push /* merge_units */
/* nHumanIk::cHumanIkRoutine::CalculateRightWristTargetRot_Local(cQuaternion&, eMode, const cVector&, const cVector&, const cQuaternion&, const cQuaternion&) (humanIk.cc) */
/* Inline asm is used only for EE/VU0 instructions C cannot express: 128-bit lq/sq quadword copies, VU0 macro-mode
   quaternion ops (lqc2/sqc2/vmul/vopmula/...), cfc2 flag tests, abs.s and the MtxToQuat sequence. No register pinning. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V(const V& o, short) { const V* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(this) } }
    V(const V& o, int) { const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(this) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct cMatrix { float m[4][4]; } __attribute__((aligned(16)));
struct cEuler { float x, y, z, w; cEuler(float ax, float ay, float az) : x(ax), y(ay), z(az) {} } __attribute__((aligned(16)));

extern "C" {
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(cMatrix* m, float, float, float, float, float, float, float, float, float);
cMatrix* cMatrix_ctor_void(cMatrix*);
cMatrix* cMatrix_ctor_cMatrixR(cMatrix*, const cMatrix*);
V cVector_GetNormalized_void(const V*);
float cVector_Dot(const V*, const V*);
float Math_Fabs(float);
void cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(cMatrix*, const V*, const V*);
const V* func_001D3AC0(const cMatrix*);
const V* cMatrix_GetXAxis(const cMatrix*);
V* cVector_ctor_void(V*);
void func_001D3A90(const cMatrix*, V*, V*, V*);
V func_001D3A60(const V*);
void cMatrix_SetAxes(cMatrix*, const V*, const V*, const V*);
extern cMatrix g_IdentityMatrix;
}
static inline void MtxToQuat(const cMatrix* m, V* out) {
    const cMatrix* mp = m;
    V* op = out;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(mp)
        lqc2 vf2, 0x10(mp)
        lqc2 vf3, 0x20(mp)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(op)
        .set reorder
    }
}

static inline void QMulT(V* o, const V* b, const V* c) {
    const V* pb = c; V* pd = o; const V* pa = b;
    asm volatile {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(pd)
    }
}
static inline void SubT(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline V operator-(const V& a, const V& b) { V r; SubT(&r, &a, &b); return r; }
static inline V operator*(const V& a, const V& b) { V r; QMulT(&r, &a, &b); return V(r, (short)0); }
static inline V QLerpN(const V& a, const V& b, float t)
{
    V r;
    const V* q = &b;
    V* d = &r;
    const V* p = &a;
    int tt;
    asm volatile {
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(q)
        mfc1 tt, t
        qmtc2.ni tt, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        vmul.xyzw vf5, vf4, vf4
        vmulax.w ACC, vf0, vf5x
        vmadday.w ACC, vf0, vf5y
        vmaddaz.w ACC, vf0, vf5z
        vmaddw.w vf6, vf0, vf5w
        vrsqrt Q, vf0w, vf6w
        vwaitq
        vmulq.xyzw vf7, vf4, Q
        sqc2 vf7, 0x0(d)
    }
    return r;
}
static inline void QLerpO(V* o, const V& a, const V& b, float t)
{
    const V* q = &b;
    const V* p = &a;
    V* d = o;
    int tt;
    asm volatile {
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(q)
        mfc1 tt, t
        qmtc2.ni tt, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        vmul.xyzw vf5, vf4, vf4
        vmulax.w ACC, vf0, vf5x
        vmadday.w ACC, vf0, vf5y
        vmaddaz.w ACC, vf0, vf5z
        vmaddw.w vf6, vf0, vf5w
        vrsqrt Q, vf0w, vf6w
        vwaitq
        vmulq.xyzw vf7, vf4, Q
        sqc2 vf7, 0x0(d)
    }
}
static inline V QLerp1(const V& a, const V& b, float t) { V r; V* pr = &r; QLerpO(pr, a, b, t); return r; }
static inline V Identity() { V r; V* p = &r; asm volatile { sqc2 vf0, 0x0(p) } return V(r, (short)0); }
static inline V Identity1() { return Identity(); }
static inline V& Conjugate(V& q) { asm volatile { lqc2 vf1, 0x0(&q); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(&q) } return q; }
static inline V& Negate(V& q) { V* p = &q; asm volatile { lqc2 vf1, 0x0(p); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(p) } return q; }
static inline V Inverse(const V& q) { V r(q); return Conjugate(r); }
static inline V Inverse1(const V& q) { return Inverse(q); }
static inline bool IsNeg(const V& q) { const float* pw = &q.w; return *pw < 0.0f; }
static inline bool IsNeg1(const V& q) { return IsNeg(q); }
static inline bool IsNeg2(const V& q) { return IsNeg1(q); }
static inline bool IsNeg3(const V& q) { return IsNeg2(q); }
static inline bool IsNearIdentity(const V& x) { const V* qq = &x; float d = 1.0f - qq->w; float r = 0.0f; asm { abs.s r, d } return r <= 1e-7f; }
static inline void SameHemisphere(V& q, const V& ref)
{
    V* p = &q;
    const V* r = &ref;
    int f;
    asm volatile {
        .set noreorder
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(r)
        vmul.xyzw vf3, vf1, vf2
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf5, vf1, vf0w
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x10
        beql f, zero, L9
        nop
        sqc2 vf5, 0x0(p)
    L9:
        .set reorder
    }
}

struct cMatrixE : cMatrix { cMatrixE(const cEuler& e); };
struct Q : V { Q(const cMatrix& m) { MtxToQuat(&m, this); } };
inline cMatrixE::cMatrixE(const cEuler& e)
{
    float ey = e.y; float ex = e.x; float ez = e.z;
    float cy = COS(ey);
    float sy = SIN(ey);
    float cx = COS(ex);
    float sx = SIN(ex);
    float cz = COS(ez);
    float sz = SIN(ez);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    cMatrix_Set_ColumnMajorForm(this, czcy - szsy * sx, -sz * cx, czsy + szcy * sx, szcy + czsy * sx, cz * cx, szsy - czcy * sx, -cx * sy, sx, cx * cy);
}
static inline V QFromM(const cMatrix& m) { V q; MtxToQuat(&m, &q); return q; }

struct cMatrixC : cMatrix {
    cMatrixC() { cMatrix_ctor_void(this); }
    cMatrixC(const cMatrixC& o) { cMatrix_ctor_cMatrixR(this, &o); }
};
static inline void PreMul0(V& q, const V& a) { V t = a * q; { V* pd = &q; const V* ps = &t; __int128 x; asm volatile { lq x, 0(ps); sq x, 0(pd) } } }
static inline void PreMul(V& q, const V& a) { PreMul0(q, a); }
static inline cMatrixC LookAt(const V& aimDir, const V& up)
{
    cMatrixC m;
    V n = cVector_GetNormalized_void(&aimDir);
    if (Math_Fabs(cVector_Dot(&n, &up)) < 0.9999985f) {
        cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(&m, &aimDir, &up);
    } else {
        const V* z = func_001D3AC0(&g_IdentityMatrix);
        if (Math_Fabs(cVector_Dot(&n, z)) < 0.9999985f) {
            cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(&m, &n, z);
        } else {
            cMatrix_MakeLookAtMatrix_cVectorR_cVectorR(&m, &n, cMatrix_GetXAxis(&g_IdentityMatrix));
            V ax, ay, az;
            cVector_ctor_void(&ax);
            cVector_ctor_void(&ay);
            cVector_ctor_void(&az);
            func_001D3A90(&m, &ax, &ay, &az);
            V nx = func_001D3A60(&ax);
            cMatrix_SetAxes(&m, &az, &ay, &nx);
        }
    }
    return m;
}
static inline cMatrixC LookAt1(const V& d, const V& u) { return LookAt(d, u); }
static inline cMatrixC LookAt2(const V& d, const V& u) { return LookAt1(d, u); }
static inline cMatrixC LookAt3(const V& d, const V& u) { return LookAt2(d, u); }
static inline cMatrixC LookAt4(const V& d, const V& u) { return LookAt3(d, u); }
struct cPose { char pad0[0x10]; V rot; V pos; const V& Pos() const { return pos; } const V& Rot() const { return rot; } };
struct cBoneIk {
    char pad0[0x20];
    V jointRef;
    char pad30[0x10];
    V ikAnimLocal;
    V ikAnimRot;
    V ikAnimPos;
    char pad70[0x50];
    cBoneIk* parent;
    char padC4[0xC];
    cPose limbPose;
    const cPose& LimbPose() const { return limbPose; }
    cBoneIk* const& Parent() const { return parent; }
    const V& JointRef() const { return jointRef; }
};
struct cHandTarget { char pad0[0x50]; V rot; const V& Rot() const { return rot; } };
struct cHumanIkRoutine {
    char pad0[0x250];
    V gunRecoil;
    char pad260[0x660 - 0x260];
    cHandTarget h660;
    const cHandTarget& H660() const { return h660; }
};
extern "C" cBoneIk D_004F46B0;
extern "C" signed char D_004F47C0;
extern "C" signed char D_004F47C8;
extern "C" V D_0049FF60;
extern "C" V D_0049FF70;
static inline void QInit(V& q, const cMatrix& m) { MtxToQuat(&m, &q); }

/* case-24 premultiply: the product pointer is re-taken after the VU0 asm (MW rematerialises the address) and the
   return copy is built one level up from a reference, which gives retail's register colouring and schedule */
static inline V& MulR0(V& r, const V& a, const V& b) { V* p = &r; QMulT(p, &a, &b); p = &r; return *p; }
static inline V MulR(const V& a, const V& b) { V r; return V(MulR0(r, a, b), 1); }
static inline void PreMulR0(V& q, const V& a) { V t = MulR(a, q); { V* pd = &q; const V* ps = &t; __int128 x; asm volatile { lq x, 0(ps); sq x, 0(pd) } } }
static inline void PreMulR(V& q, const V& a) { PreMulR0(q, a); }
extern "C" unsigned char UpperBody_HandRotation(cHumanIkRoutine* self, V& rWristTargetRot_Local, unsigned char iMode, const V& aimAtPoint_SkelSpace, const V& worldUpVector_SkelSpace, const V& aimAtRot_SkelSpace, const V& currAimOrientation_OffsetFrom_TargetAimOrientation)
{
    unsigned char wasCalculated = 0;
    switch (iMode) {
    case 3: case 4: case 5: case 6: case 7: case 10: case 11: case 23: {
        if (!D_004F47C0) { QInit(D_0049FF60, cMatrixE(cEuler(1.5707964f, 0.0f, 1.5707964f))); D_004F47C0 = 1; }
        cBoneIk* wristIk = &D_004F46B0;
        cBoneIk* elbowIk = wristIk->parent;
        rWristTargetRot_Local = D_0049FF60;
        if (!IsNearIdentity(self->gunRecoil)) {
            const V* pr = &self->gunRecoil; V gunRecoilAdditionalFraction = QLerp1(Identity1(), *pr, 0.35f);
            PreMul(rWristTargetRot_Local, gunRecoilAdditionalFraction);
        }
        cMatrixC aimMatrix = LookAt3((const V&)(aimAtPoint_SkelSpace - wristIk->LimbPose().Pos()), worldUpVector_SkelSpace);
        PreMul(rWristTargetRot_Local, Q(aimMatrix));
        if (IsNeg3(rWristTargetRot_Local)) Negate(rWristTargetRot_Local);
        PreMul(rWristTargetRot_Local, currAimOrientation_OffsetFrom_TargetAimOrientation);
        PreMul(rWristTargetRot_Local, Inverse1(elbowIk->LimbPose().Rot()));
        wasCalculated = true;
        break;
    }
    case 12: case 16: {
        if (!D_004F47C8) { QInit(D_0049FF70, cMatrixE(cEuler(1.5707964f, 0.0f, 1.5707964f))); D_004F47C8 = 1; }
        cBoneIk* wristIk = &D_004F46B0;
        cBoneIk* elbowIk = wristIk->parent;
        rWristTargetRot_Local = D_0049FF70;
        PreMul(rWristTargetRot_Local, aimAtRot_SkelSpace);
        if (IsNeg3(rWristTargetRot_Local)) Negate(rWristTargetRot_Local);
        PreMul(rWristTargetRot_Local, currAimOrientation_OffsetFrom_TargetAimOrientation);
        PreMul(rWristTargetRot_Local, Inverse1(elbowIk->LimbPose().Rot()));
        wasCalculated = true;
        break;
    }
    case 13: case 14: case 15: {
        cBoneIk& rWristIk = D_004F46B0;
        rWristTargetRot_Local = rWristIk.ikAnimLocal;
        wasCalculated = true;
        break;
    }
    case 24: {
        cBoneIk& rWristIk = D_004F46B0;
        cBoneIk& rElbowIk = *rWristIk.Parent();
        { const V& r = self->H660().Rot(); rWristTargetRot_Local = r; }
        PreMulR(rWristTargetRot_Local, Inverse1(rElbowIk.LimbPose().Rot()));
        { cBoneIk& w = D_004F46B0; SameHemisphere(rWristTargetRot_Local, w.JointRef()); }
        wasCalculated = 1;
        break;
    }
    case 0: case 1: case 2: case 8: case 9: case 17: case 18: case 19: case 20: case 21: case 22:
        break;
    }
    return wasCalculated;
}
static inline void merge_flush_func_001D40E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D40E0 */
