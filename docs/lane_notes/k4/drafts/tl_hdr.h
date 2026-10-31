/* 001D1740 nIk_TwoLimbIK -- nIk::TwoLimbIK (humanIk.cc). l5 draft. */
#pragma cplusplus on
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma opt_dead_assignments off

class cVector;

class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    cQuaternion(const cVector& v, float aw);
    void CopyFrom(const cQuaternion& source) { cQuaternion* refThis = this; u_long128 reg; const cQuaternion* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(refThis) } }
    cQuaternion(const cQuaternion& source) { CopyFrom(source); }
    cQuaternion& operator=(const cQuaternion& source) { cQuaternion* d = this; const cQuaternion* s = &source; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    float W() const { return w; }
    void Negate() { cQuaternion* d = this; cQuaternion* s = this; asm volatile { lqc2 vf1, 0(s); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0(d) } }
    cQuaternion& Invert() { asm volatile { lqc2 vf1, 0(this); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0(this) } return *this; }
    cQuaternion GetInverse() const { return cQuaternion(*this).Invert(); }
    static void MulTo(cQuaternion* q1, const cQuaternion* b, const cQuaternion* cc)
    {
        asm volatile {
            lqc2 vf1, 0x0(b)
            lqc2 vf2, 0x0(cc)
            vmul.xyzw vf3, vf1, vf2
            vopmula.xyz ACC, vf1, vf2
            vmaddaw.xyz ACC, vf1, vf2w
            vmaddaw.xyz ACC, vf2, vf1w
            vopmsub.xyz vf4, vf2, vf1
            vsubaz.w ACC, vf3, vf3z
            vmsubay.w ACC, vf0, vf3y
            vmsubx.w vf4, vf0, vf3x
            sqc2 vf4, 0x0(q1)
        }
    }
    cQuaternion& SetMul(const cQuaternion& a, const cQuaternion& c) { MulTo(this, &a, &c); return *this; }
    const cQuaternion& Ref() const { return *this; }

    unsigned char IsZeroXYZ() const
    {
        int k, f, r;
        const cQuaternion* v = this;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
    cQuaternion SetRotationArc(const cVector& from, const cVector& to);
    cQuaternion GetRotated(const cQuaternion& delta) const;
    cQuaternion& Rotate(const cQuaternion& delta);
    cQuaternion& RotateR(const cQuaternion& delta);
    cQuaternion& PreMul(const cQuaternion& delta);
} __attribute__((aligned(16)));
inline cQuaternion operator*(const cQuaternion& a, const cQuaternion& c) { cQuaternion l0; l0.SetMul(a, c); return l0; }
inline cQuaternion cQuaternion::GetRotated(const cQuaternion& delta) const { return delta * *this; }
inline cQuaternion& cQuaternion::Rotate(const cQuaternion& delta) { *this = delta * *this; return *this; }
inline cQuaternion& cQuaternion::RotateR(const cQuaternion& delta) { *this = GetRotated(delta); return *this; }


class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& source) { cVector* refThis = this; u_long128 reg; const cVector* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(refThis) } }
    cVector& operator=(const cVector& source) { const cVector* s = &source; cVector* d = this; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    float X() const { return x; }
    float Y() const { return y; }
    float Z() const { return z; }
    cVector& operator+=(const cVector& b) { cVector* d = this; const cVector* s = &b; asm volatile { lqc2 vf1, 0(d); lqc2 vf2, 0(s); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0(d) } return *this; }
    cVector operator+(const cVector& b) const { return cVector(*this) += b; }
    static void SubTo(cVector* rr, const cVector* a, const cVector* bb) { asm volatile { lqc2 vf1, 0(a); lqc2 vf2, 0(bb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(rr) } }
    cVector operator-(const cVector& b) const { cVector r; SubTo(&r, this, &b); return r; }
    static void NegTo(cVector* rr, const cVector* a) { asm volatile { lqc2 vf1, 0(a); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0(rr) } }
    void NegFrom(const cVector& src) { cVector* rr = this; const cVector* a = &src; asm volatile { lqc2 vf1, 0(a); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0(rr) } }
    cVector operator-() const { cVector r; const cVector* a = this; cVector* rr = &r; asm volatile { lqc2 vf1, 0(a); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0(rr) } return r; }
    cVector operator*(float s) const { cVector r; cVector* rr = &r; const cVector* a = this; int t; asm volatile { .set noreorder; lqc2 vf1, 0(a); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyz vf1, vf1, vf2x; sqc2 vf1, 0(rr); .set reorder } return r; }
    cVector& Normalize(float& returnLength)
    {
        cVector* v = this; u_long128 reg = 0; float* pl = &returnLength;
        asm volatile {
            lqc2 vf1, 0(v)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            vdiv Q, vf0w, vf4x
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0(v)
            qmfc2.ni reg, vf4
            sw reg, 0(pl)
        }
        return *this;
    }
    cVector& Normalize()
    {
        cVector* v = this;
        asm volatile {
            lqc2 vf1, 0(v)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vrsqrt Q, vf0w, vf3w
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0(v)
        }
        return *this;
    }
    float Length() const
    {
        const cVector* v = this; float r = 0.0f; u_long128 reg;
        asm volatile {
            lqc2 vf1, 0(v)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            qmfc2.ni reg, vf4
            mtc1 reg, r
        }
        return r;
    }
    cVector& Rotate(const cQuaternion& q)
    {
        cVector* v = this; const cQuaternion* qq = &q;
        asm volatile {
            lqc2 vf1, 0(v)
            vmove.w vf6, vf1
            vmr32.w vf1, vf0
            lqc2 vf2, 0(qq)
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
            sqc2 vf6, 0(v)
        }
        return *this;
    }
    unsigned char IsZeroXYZ() const
    {
        int k, f, r = 0;
        const cVector* v = this;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
} __attribute__((aligned(16)));

static inline float Dot(const cVector& a, const cVector& b)
{
    float r = 0.0f; u_long128 reg; const cVector* aa = &a; const cVector* bb = &b;
    asm volatile {
        lqc2 vf1, 0(aa)
        lqc2 vf2, 0(bb)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni reg, vf4
        qfsrv reg, reg, reg
        mtc1 reg, r
    }
    return r;
}

static inline cVector Cross(const cVector& a, const cVector& b)
{
    cVector r; cVector* rr = &r; const cVector* aa = &a; const cVector* bb = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vopmula.xyz $ACC, $vf1, $vf2; vopmsub.xyz $vf3, $vf2, $vf1; vsubw.w $vf3, $vf0, $vf0w; sqc2 $vf3, 0x0(%0)" : : "r"(rr), "r"(aa), "r"(bb) : "memory");
    return r;
}

inline cQuaternion cQuaternion::SetRotationArc(const cVector& from, const cVector& to)
{
    cQuaternion* d = this; const cVector* a = &from; const cVector* b = &to; int f;
    asm volatile {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmul.xyzw vf3, vf1, vf2
        vadd.w vf10, vf0, vf0
        lui f, 0x3F00
        qmtc2.ni f, vf11
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        vaddax.w ACC, vf10, vf0x
        vmaddw.w vf5, vf10, vf4w
        vsqrt Q, vf5w
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf6, vf2, vf1
        vwaitq
        vmulq.w vf7, vf0, Q
        vdiv Q, vf0w, vf7w
        vmulx.w vf8, vf7, vf11x
        vwaitq
        vmulq.xyz vf8, vf6, Q
        j done
        nop
    L1:
        vaddw.x vf8, vf0, vf0w
        vmulx.yzw vf8, vf0, vf0x
    done:
        sqc2 vf8, 0(d)
        .set reorder
    }
    return *this;
}

inline cQuaternion::cQuaternion(const cVector& v, float aw) { x = v.X(); y = v.Y(); z = v.Z(); w = aw; }
static inline void NegateIfWNegative(cQuaternion& q) { if (q.W() < 0.0f) q.Negate(); }

static inline float SQUARE_I(float f) { return f * f; }
static inline float SQRT_I(float x) { float r = 0.0f; asm volatile { sqrt.s r, x } return r; }
static inline float CLAMP_LOW_I(float a, float b) { float r = 0.0f; float bb = b; asm volatile { max.s r, bb, a } return r; }
static inline float CLAMP2_I(float a, float lo, float hi) { float r; asm volatile { max.s r, a, lo; min.s r, r, hi } return r; }
static inline float CLAMP4_I(float a, float lo, float hi) { float r = 0.0f; float l = lo; float h = hi; asm volatile { max.s r, a, l; min.s r, r, h } return r; }
static inline float CLAMP3_I(float a, float lo, float hi) { float r = 0.0f; asm volatile { max.s r, a, lo; min.s r, r, hi } return r; }
static inline float CLAMP_I(float a, float lo, float hi) { asm volatile { max.s a, a, lo; min.s a, a, hi } return a; }

class cJointLimits { public: float x, y, z, pad; } __attribute__((aligned(16)));

extern "C" {
cQuaternion cQuaternion_GetConjugate(const cQuaternion* self);
unsigned char cQuaternion_IsZeroXYZ(const cQuaternion* self);
cQuaternion* cQuaternion_opAssign(cQuaternion* self, const cQuaternion* src);
float* cQuaternion_W_void(cQuaternion* self);
float* cQuaternion_X_void(cQuaternion* self);
float* cQuaternion_Y_void(cQuaternion* self);
float* cQuaternion_Z_void(cQuaternion* self);
float cQuaternion_W_void_2(const cQuaternion* self);
float cQuaternion_X_void_2(const cQuaternion* self);
float cQuaternion_Y_void_2(const cQuaternion* self);
float cQuaternion_Z_void_2(const cQuaternion* self);
cVector* cVector_ctor_cVectorR(cVector* self, const cVector* src);
cVector* cVector_ctor_float_float_float_float(cVector* self, float x, float y, float z, float w);
cVector* cVector_Normalize_floatR(cVector* self, float* len);
float cVector_X_void(const cVector* self);
float cVector_Y_void(const cVector* self);
float cVector_Z_void(const cVector* self);
float SQUARE(float f);
float SQRT(float f);
float CLAMP_LOW(float a, float b);
}

static inline unsigned char ApplyJointLimits(cQuaternion& output, const cQuaternion& input, const cJointLimits& oneOverLimitSinHalfAngleSquared)
{
    if (cQuaternion_IsZeroXYZ(&input)) {
        cQuaternion_opAssign(&output, &input);
        return false;
    }
    float sinHalfAngle;
    cVector axis;
    cVector tmp;
    {
        float qx = cQuaternion_X_void_2(&input);
        float qy = cQuaternion_Y_void_2(&input);
        float qz = cQuaternion_Z_void_2(&input);
        cVector_ctor_cVectorR(&axis, cVector_Normalize_floatR(cVector_ctor_float_float_float_float(&tmp, qx, qy, qz, 0.0f), &sinHalfAngle));
    }
    float limitSinSquared = 0.0f;
    u_long128 reg;
    __asm__ volatile("lqc2 vf1, 0(%1)\n lqc2 vf2, 0(%2)\n vmul.xyz vf3, vf1, vf1\n vmul.xyz vf4, vf3, vf2\n vmulax.w ACC, vf0, vf4x\n vmadday.w ACC, vf0, vf4y\n vmaddz.w vf5, vf0, vf4z\n vdiv Q, vf0w, vf5w\n vwaitq\n vaddq.x vf6, vf0, Q\n qmfc2.ni %0, vf6" : "=r"(reg) : "r"(&axis), "r"(&oneOverLimitSinHalfAngleSquared));
    __asm__ volatile("mtc1 %1, %0" : "=f"(limitSinSquared) : "r"(reg));
    if (SQUARE(sinHalfAngle) > limitSinSquared || cQuaternion_W_void_2(&input) < 0.0f) {
        float limitCos = SQRT(CLAMP_LOW(1.0f - limitSinSquared, 0.0f));
        *cQuaternion_W_void(&output) = limitCos;
        float limitSin = SQRT(limitSinSquared);
        *cQuaternion_X_void(&output) = limitSin * cVector_X_void(&axis);
        *cQuaternion_Y_void(&output) = limitSin * cVector_Y_void(&axis);
        *cQuaternion_Z_void(&output) = limitSin * cVector_Z_void(&axis);
        return true;
    }
    cQuaternion_opAssign(&output, &input);
    return false;
}

static inline void ApplyCenteredJointLimits_unused(cQuaternion& rot, const cJointLimits& limits, const cQuaternion& centeringTransform)
{
    rot = centeringTransform.GetInverse() * rot;
    ApplyJointLimits(rot, rot, limits);
    rot = centeringTransform * rot;
}
#define ApplyCenteredJointLimits(rot, limits, centeringTransform) { rot = (centeringTransform).GetInverse() * rot; ApplyJointLimits(rot, rot, limits); rot = (centeringTransform) * rot; }


