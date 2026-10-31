#pragma cplusplus on
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma enumsalwaysint off
#pragma opt_propagation off
#pragma opt_dead_assignments off

class cQuaternion;
class cVector;
static inline void SubTo(cVector* pr, const cVector* pa, const cVector* pb);

static inline void AddTo(cVector* pr, const cVector* pa, const cVector* pb);
class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& source) { u_long128 reg; const cVector* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(this) } }
    cVector& operator=(const cVector& source) { u_long128 reg; cVector* d = this; const cVector* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    cVector(const cVector& source, int) { cVector* d = this; const cVector* s = &source; __int128 t; __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "0"(s) : "memory"); }
    cVector operator-(const cVector& b) const;
    cVector AddG(const cVector& b) const { cVector r; cVector* pr = &r; AddTo(pr, this, &b); return cVector(r, 0); }
    cVector SubF(const cVector& b) const { return *this - b; }
    cVector ScaleW(float k) const { return *this * k; }
    cVector ScaleW2(float k) const { return Scale_(k); }
    cVector AddF(const cVector& b) const { return *this + b; }
    cVector AddF2(const cVector& b) const { return AddF(b); }
    cVector operator+(const cVector& b) const {
        cVector r; cVector* pr = &r; AddTo(pr, this, &b); return r;
    }
    cVector operator*(float k) const {
        u_long128 z = 0;
        cVector r;
        int t;
        const cVector* pv = this;
        cVector* pr = &r;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0x0(pv)
            mfc1 t, k
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(pr)
            .set reorder
        }
        return r;
    }
    cVector Scale_(float k) const {
        u_long128 z = 0;
        cVector r;
        const cVector* pv = this;
        cVector* pr = &r;
        int t;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0x0(pv)
            mfc1 t, k
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(pr)
            .set reorder
        }
        return r;
    }
    cVector NormalizeV() {
        cVector* p = this;
        asm volatile {
            lqc2 vf1, 0x0(p)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vrsqrt Q, vf0w, vf3w
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0x0(p)
        }
        return *this;
    }
    cVector& Normalize() {
        cVector* p = this;
        asm volatile {
            lqc2 vf1, 0x0(p)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vrsqrt Q, vf0w, vf3w
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0x0(p)
        }
        return *this;
    }
#undef p
    
    bool IsZero() const {
        int k, fl;
        int r = 0;
        const cVector* v = this;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyzw vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xF
            vnop
            vnop
            vnop
            vnop
            cfc2.ni fl, vi17
            bne k, fl, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return (unsigned char)r;
    }
    cVector& Rotate(const cQuaternion& q);
} __attribute__((aligned(16)));

inline cVector ScaleF(const cVector& v, float k) {
        u_long128 z = 0;
        cVector r;
        int t;
        const cVector* pv = &v;
        cVector* pr = &r;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0x0(pv)
            mfc1 t, k
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(pr)
            .set reorder
        }
        return r;
    }
inline cVector ScaleV(float k, const cVector& v) {
        u_long128 z = 0;
        cVector r;
        int t;
        const cVector* pv = &v;
        cVector* pr = &r;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0x0(pv)
            mfc1 t, k
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(pr)
            .set reorder
        }
        return r;
    }
static inline cVector Mid(const cVector& a, const cVector& b) { return (a + b) * 0.5f; }
static inline cVector Half(cVector v) { return v * 0.5f; }
static inline cVector Normalized(cVector v) { v.Normalize(); return v; }
static inline const cVector& NormalizedR(cVector v) { v.Normalize(); return v; }
static inline cVector NormalizedC(const cVector& v) { cVector* p = (cVector*)&v; p->Normalize(); return *p; }
static inline const cVector& NormalizedCR(const cVector& v) { cVector* p = (cVector*)&v; p->Normalize(); return *p; }

class cQuaternion;
static inline void QMulTo(cQuaternion* pr, const cQuaternion* pa, const cQuaternion* pb)
{
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
        sqc2 vf4, 0x0(pr)
    }
}
class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion& SetRotationBetween(const cVector& a, const cVector& b);
    cQuaternion(const cQuaternion& source) { cQuaternion* refThis = this; u_long128 reg; const cQuaternion* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(refThis) } }
    cQuaternion& operator=(const cQuaternion& source) { const cQuaternion* s = &source; cQuaternion* d = this; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    cQuaternion operator*(const cQuaternion& b) const;
    cQuaternion& PreMultiply(const cQuaternion& q) { cQuaternion* p = this; *this = q * *p; p = this; return *p; }
    cQuaternion GetConjugate() const { return Conj_(); }
    cQuaternion ConjX() const { return Conj_(); }
    cQuaternion Conj_() const {
        cQuaternion r(*this); cQuaternion* p = &r;
        asm volatile { lqc2 vf1, 0x0(p); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(p) }
        return *p;
    }
} __attribute__((aligned(16)));

static inline cQuaternion QMulR(const cQuaternion& a, const cQuaternion& b) { cQuaternion r; QMulTo(&r, &a, &b); return r; }
static inline const cQuaternion& QMulRef(const cQuaternion& a, const cQuaternion& b) { cQuaternion r; QMulTo(&r, &a, &b); return r; }
static inline const cQuaternion& QMulRef2(const cQuaternion& a, const cQuaternion& b) { cQuaternion r; cQuaternion* p = &r; QMulTo(p, &a, &b); return *p; }
static inline const cQuaternion& QMulRefP(const cQuaternion* a, const cQuaternion* b) { cQuaternion r; QMulTo(&r, a, b); return r; }
static inline cQuaternion QMulR2(const cQuaternion& a, const cQuaternion& b) { return QMulR(a, b); }
inline cQuaternion cQuaternion::operator*(const cQuaternion& b) const {
    return QMulRef(*this, b);
}
inline cVector& cVector::Rotate(const cQuaternion& q)
{
    cVector* p = this;
    const cQuaternion* pq = &q;
    asm volatile {
        lqc2 vf1, 0x0(p)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(pq)
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
        sqc2 vf6, 0x0(p)
    }
    return *this;
}
#undef p

inline cQuaternion& cQuaternion::SetRotationBetween(const cVector& a, const cVector& b)
{
    cQuaternion* pr = this;
    const cVector* pa = &a;
    const cVector* pb = &b;
    int t;
    asm volatile {
        .set noreorder
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        vmul.xyzw vf3, vf1, vf2
        vadd.w vf10, vf0, vf0
        lui t, 0x3F00
        qmtc2 t, vf11
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        vaddax.w ACC, vf10, vf0x
        vmaddw.w vf5, vf10, vf4w
        vsqrt Q, vf5w
        vnop
        cfc2 t, vi17
        andi t, t, 0x11
        bnel t, zero, L1
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
    L1:
        vaddw.x vf8, vf0, vf0w
        vmulx.yzw vf8, vf0, vf0x
    done:
        sqc2 vf8, 0x0(pr)
        .set reorder
    }
    return *pr;
}

static inline void AddTo(cVector* pr, const cVector* pa, const cVector* pb)
{
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
static inline void SubTo(cVector* pr, const cVector* pa, const cVector* pb)
{
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
inline cVector cVector::operator-(const cVector& b) const {
    cVector r; cVector* pr = &r; SubTo(pr, this, &b); return r;
}
static inline cVector Rotated(cVector v, const cQuaternion& q) { v.Rotate(q); return v; }
static inline const cVector& RotR(cVector v, const cQuaternion& q) { v.Rotate(q); return v; }
static inline const cVector& RotP(cVector v, const cQuaternion& q) { cVector* p = &v; p->Rotate(q); return v; }
static inline cVector SubC(const cVector& a, const cVector& b) { return a - b; }
class cJointLimits { public: float x, y, z, w; } __attribute__((aligned(16)));
class cJointInfo { public: char pad[0x30]; };

extern "C" const cJointLimits& func_001D2870(const cJointInfo* self);
extern "C" const cQuaternion& cJointInfo_CenterPosition_InBoneSpace(const cJointInfo* self);

struct cPose {
    cQuaternion localRot;
    cQuaternion rot;
    cVector pos;
    cVector& Pos() { cPose* t = this; return t->pos; }
    cQuaternion& LocalRot() { cPose* t = this; return t->localRot; }
    cQuaternion& Rot() { cPose* t = this; return t->rot; }
    const cVector& Pos() const { const cPose* t = this; return t->pos; }
    const cQuaternion& LocalRot() const { const cPose* t = this; return t->localRot; }
    const cQuaternion& Rot() const { const cPose* t = this; return t->rot; }
};

struct cIntermediatePose : cPose {
    cVector pad;
};

struct cBaseIkPose {
    cQuaternion rot;
    cQuaternion pad0;
    cVector pad2;
    cVector pad3;
};

class cBoneIk {
public:
    void* bone;
    char pad4[0xC];
    cJointInfo jointInfo;
    cBaseIkPose ikAnim;
    cIntermediatePose lookAt;
    cBoneIk* parent;
    char padC4[0xC];
    cPose limbPose;
};

enum eLod { eLod_0, eLod_1, eLod_2 };
struct cHumanIkRoutine {
    char pad0[8];
    eLod mLod;
};

extern cBoneIk UpperBodyNodeTable[];

extern "C" void nIk_TwoLimbIK(cQuaternion& a, cQuaternion& b, const cVector& c, const cVector& d, const cQuaternion& e,
    const cJointLimits& f, const cQuaternion& g, const cVector& h, const cQuaternion& i, const cJointLimits& j,
    const cQuaternion& k, const cQuaternion& l, const cVector& m);
extern "C" void cBoneIk_LimbPose_CalculateSkelSpaceInfo(cBoneIk* self);

extern "C" void cHumanIkRoutine_PositionLeg(cHumanIkRoutine* self, const cVector& desiredToePos_SkelSpace, unsigned int toeIndex, bool performIk)
{
    cBoneIk* toeIk = &UpperBodyNodeTable[toeIndex];
    cBoneIk* ankleIk = toeIk->parent;
    cBoneIk* kneeIk = ankleIk->parent;
    cBoneIk* sideHipIk = kneeIk->parent;
    cBoneIk* hipIk = sideHipIk->parent;
    if (performIk || self->mLod == eLod_2) {
        cQuaternion newKneeRot_Local = kneeIk->lookAt.LocalRot();
        cVector newToePos_SkelSpace = toeIk->lookAt.Pos();
        cVector kneeStartVec = NormalizedR(ankleIk->lookAt.Pos() - kneeIk->lookAt.Pos());
        cVector kneeEndVec = ankleIk->lookAt.Pos().AddG(sideHipIk->lookAt.Pos()).Scale_(0.5f).operator-(kneeIk->lookAt.Pos()).Normalize();
        if (!kneeStartVec.IsZero() && !kneeEndVec.IsZero()) {
            cQuaternion fudgeRot = cQuaternion().SetRotationBetween(kneeStartVec, kneeEndVec);
            newKneeRot_Local = newKneeRot_Local.PreMultiply(sideHipIk->lookAt.Rot()).PreMultiply(fudgeRot).PreMultiply(sideHipIk->lookAt.Rot().GetConjugate());
            newToePos_SkelSpace = RotR(SubC(newToePos_SkelSpace, kneeIk->lookAt.Pos()), fudgeRot) + kneeIk->lookAt.Pos();
        }
        nIk_TwoLimbIK(sideHipIk->limbPose.LocalRot(), kneeIk->limbPose.LocalRot(), desiredToePos_SkelSpace,
            sideHipIk->lookAt.Pos(), sideHipIk->lookAt.LocalRot(),
            func_001D2870(&sideHipIk->jointInfo), cJointInfo_CenterPosition_InBoneSpace(&sideHipIk->jointInfo),
            kneeIk->lookAt.Pos(), newKneeRot_Local,
            func_001D2870(&kneeIk->jointInfo), cJointInfo_CenterPosition_InBoneSpace(&kneeIk->jointInfo),
            hipIk->limbPose.Rot(), newToePos_SkelSpace);
        ankleIk->limbPose.LocalRot() = ankleIk->lookAt.LocalRot();
        cBoneIk_LimbPose_CalculateSkelSpaceInfo(sideHipIk);
        cBoneIk_LimbPose_CalculateSkelSpaceInfo(kneeIk);
        cBoneIk_LimbPose_CalculateSkelSpaceInfo(ankleIk);
    } else {
        sideHipIk->limbPose.LocalRot() = sideHipIk->lookAt.LocalRot();
        kneeIk->limbPose.LocalRot() = kneeIk->lookAt.LocalRot();
        ankleIk->limbPose.LocalRot() = ankleIk->lookAt.LocalRot();
    }
}
