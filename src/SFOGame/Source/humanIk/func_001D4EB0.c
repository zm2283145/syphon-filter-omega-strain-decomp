#pragma cplusplus on
class cVector;
struct CallCopy {};
extern "C" cVector* cVector_ctor_cVectorR(cVector*, const cVector*);
static inline cVector* CtorP(cVector* t, const cVector* s) { cVector_ctor_cVectorR(t, s); return t; }
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma peephole on
#pragma opt_propagation off

#pragma opt_dead_assignments off

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(const cVector* ps) { cVector_ctor_cVectorR(this, ps); cVector* t = this; (void)t; }
    cVector& operator=(const cVector& o) { cVector* pd = this; const cVector* ps = &o; u_long128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
    cVector(const cVector* b, int) { cVector* q1 = this; asm volatile { lqc2 vf1, 0x0(b); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(q1) } }
    cVector(const cVector* a, const cVector* b) { cVector* pr = this; asm volatile { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(b); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) } }
    cVector(const cVector& source) { const cVector* s = &source; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(this) } }
    cVector operator-() const
    {
        cVector l0;
        cVector* q1 = &l0;
        const cVector* b = this;
        asm volatile {
            lqc2 vf1, 0x0(b)
            vmulax.xyzw ACC, vf0, vf0x
            vmsubw.xyzw vf1, vf1, vf0w
            sqc2 vf1, 0x0(q1)
        }
        return l0;
    }
    cVector& operator+=(const cVector& v)
    {
        cVector* t = this;
        const cVector* o = &v;
        asm volatile {
            lqc2 vf1, 0x0(t)
            lqc2 vf2, 0x0(o)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0x0(t)
        }
        return *this;
    }
    cVector& operator-=(const cVector& v) { cVector* t = this; cVector n; cVector m(&v, 0); n = m; return *t += n; }
    cVector operator-(const cVector& v) const
    {
        cVector r; r.SubOf(this, &v);
        
        return r;
    }
    void SubOf(const cVector* a, const cVector* b) { asm volatile { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(b); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(this) } }
    cVector operator+(const cVector& v) const
    {
        cVector r;
        cVector* pr = &r;
        const cVector* a = this;
        const cVector* b = &v;
        asm volatile {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(b)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(pr)
        }
        return r;
    }
    cVector operator*(float s) const
    {
        cVector r;
        cVector* pr = &r;
        const cVector* a = this;
        int t;
        // VU0 scale; noreorder keeps mfc1/qmtc2 back-to-back (no hazard nop), as in retail
        asm volatile {
            .set noreorder
            lqc2 vf1, 0x0(a)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(pr)
            .set reorder
        }
        return *pr;
    }
    friend cVector operator*(float s, const cVector& v)
    {
        cVector r;
        cVector* pr = &r;
        const cVector* a = &v;
        u_long128 t = 0;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0x0(a)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(pr)
            .set reorder
        }
        return r;
    }
    cVector& SetSub(const cVector& a, const cVector& b) { Set(cVector(&a, &b)); return *this; }
    void Set(const cVector& o) { cVector* pd = this; const cVector* ps = &o; u_long128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    void Set2(const cVector& o) { const cVector* ps = &o; u_long128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
    cVector& Set3(const cVector& o) { cVector* pd = this; const cVector* ps = &o; u_long128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *pd; }
    cVector& SetSub2(const cVector& a, const cVector& b) { cVector* t = this; cVector r(&a, &b); *t = r; return *t; }
    cVector& SetSub3(const cVector& a, const cVector& b) { return *this = a - b; }
    float Length() const
    {
        float len = 0.0f;
        const cVector* v = this;
        int t;
        asm volatile {
            lqc2 vf1, 0x0(v)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            qmfc2.ni t, vf4
            mtc1 t, len
        }
        return len;
    }
    cVector& Normalize()
    {
        cVector* refThis = this;
        asm volatile {
            lqc2 vf1, 0x0(refThis)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vrsqrt Q, vf0w, vf3w
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0x0(refThis)
        }
        return *this;
    }
} __attribute__((aligned(16)));

class cQuaternion {
public:
    float x, y, z, w;
    bool NearId2() const { const cQuaternion* p = this; float d = 1.0f - p->w; float r = 0.0f; asm { abs.s r, d } return r <= 1e-7f; }
} __attribute__((aligned(16)));

struct cMatrix { float m[4][4]; } __attribute__((aligned(16)));
struct cPose {
    char pad0[0x10];
    cQuaternion rot;
    cVector pos;
};

struct cBoneIk {
    char pad0[0x50];
    cQuaternion ikAnimRot;
    cVector ikAnimPos;
    char pad70[0x20];
    cQuaternion lookAtRot;
    cVector lookAtPos;
    char padB0[0x20];
    cPose limbPose;
};

struct cHandTarget {
    char pad0[0x120];
    cVector pos;
};

struct cHumanIkRoutine {
    char pad0[0x250];
    cQuaternion q250;
    cQuaternion& GetQ() { return q250; }
    cQuaternion* GetQP() { return &q250; }
    char pad260[0x490 - 0x260];
    cVector v490;
    cHandTarget h4A0;
    char pad5D0[0x660 - 0x5D0];
    cHandTarget h660;
};

static inline bool IsNearIdentity(const cQuaternion& cQuaternion) { float d = 1.0f - cQuaternion.w; float r = 0.0f; asm { abs.s r, d } return r <= 1e-7f; }

static inline bool IsNearIdentityP(const cQuaternion* qq) { float d = 1.0f - qq->w; float r = 0.0f; asm { abs.s r, d } return r <= 1e-7f; }
static inline const cQuaternion& Ref(const cQuaternion& x) { return x; }
static inline bool IsNearIdentityR(const cQuaternion& x) { const cQuaternion* qq = &x; float d = 1.0f - qq->w; float r = 0.0f; asm { abs.s r, d } return r <= 1e-7f; }
extern "C" {
cVector* cVector_Transform_cQuaternionR_cVectorR(cVector*, const cQuaternion*, const cVector*);
extern cBoneIk D_004F40B0;
extern cBoneIk D_004F41B0;
extern cBoneIk UpperBodyNodeTable[];
cVector* cVector_InverseTranslate(cVector*, const cVector*);
cVector* cVector_InverseRotate_cQuaternionR(cVector*, const cQuaternion*);
extern cBoneIk D_004F46B0;
}

static inline cVector XformPt(const cVector& v, const cQuaternion& rot, const cVector& pos)
{
    cVector tmp;
    return cVector(cVector_Transform_cQuaternionR_cVectorR(cVector_ctor_cVectorR(&tmp, &v), &rot, &pos));
}


static inline cVector Sb(const cVector& a, const cVector& b) { return cVector(&a, &b); }
static inline void Dz(const cVector& a) { cVector z(&a, 0); }
static inline cVector R0(const cVector& a) { return a; }
static inline void D2(const cVector& a) { Dz(a); }
static inline void D3(const cVector& a) { D2(a); }
static inline void D4(const cVector& a) { D3(a); }
static inline void D5(const cVector& a) { D4(a); }
#define DD D3
static inline void Keep1(cVector& a) { cVector u2 = a; a = u2; }
static inline cVector Sub1(const cVector& a, const cVector& b) { return a - b; }
static inline cVector Add1(const cVector& a, const cVector& b) { return a + b; }
static inline cVector Mul1(const cVector& a, float k) { return a * k; }
static inline cVector XformPt1(const cVector& v, const cQuaternion& rot, const cVector& pos) { return XformPt(v, rot, pos); }
static inline cVector XformPt2(const cVector& v, const cQuaternion& rot, const cVector& pos) { return XformPt1(v, rot, pos); }
static inline cVector XformPt3(const cVector& v, const cQuaternion& rot, const cVector& pos) { return XformPt2(v, rot, pos); }
static inline void SubEq1(cVector& a, const cVector& b, const cVector& c) { (a -= b) += c; }

static inline cVector& Rotate(cVector& v, const cQuaternion& q)
{
    cVector* pv = &v;
    const cQuaternion* pq = &q;
    asm volatile {
        lqc2 vf1, 0x0(pv)
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
        sqc2 vf6, 0x0(pv)
    }
    return v;
}

static inline cVector MulT(const cVector& v, float s)
{
    int t; cVector r; cVector* pr = &r; const cVector* a = &v;
    asm volatile {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(pr)
        .set reorder
    }
    return r;
}

static inline cVector& Translate(cVector& v, const cVector& t)
{
    float* pw = &v.w;
    float w = *pw;
    if (1.0f == w) {
        v += t;
    } else {
        cVector s = MulT(t, w);
        v += s;
        float* pw2 = &v.w;
        *pw2 = s.w;
    }
    return v;
}

static inline cVector& InverseTranslate(cVector& v, const cVector& t) { return *cVector_InverseTranslate(&v, &t); }
static inline cVector& InverseRotate(cVector& v, const cQuaternion& q) { return *cVector_InverseRotate_cQuaternionR(&v, &q); }

static inline signed char RefBone(unsigned char m)
{
    if (m == 10 || m == 11) {
        return 14;
    } else if (m == 12 || m == 16) {
        return 0;
    } else {
        return 0;
    }
}

extern "C" unsigned char cHumanIkRoutine_CalculateRightWristTargetPos_SkelSpace(cHumanIkRoutine* self, cVector& rWristTargetPos_SkelSpace, unsigned char iMode)
{
    unsigned char wasCalculated = 0;
    switch (iMode) {
    case 4:
    case 5:
    case 23: {
        cBoneIk& rWristIk = D_004F46B0;
        cBoneIk& headIk = D_004F40B0;
        cBoneIk& rShoulderIk = D_004F41B0;
        const cVector& rWristPos_BaseIk = rWristIk.ikAnimPos;
        const cVector& headPos_BaseIk = headIk.ikAnimPos;
        const cVector& headPos_LookAt = headIk.lookAtPos;
        const cVector& rShoulderPos_BaseIk = rShoulderIk.ikAnimPos;
        const cVector& rShoulderPos_LookAt = rShoulderIk.lookAtPos;
        cVector rWristPos_LookAt(rWristPos_BaseIk);
        (rWristPos_LookAt -= headPos_BaseIk) += headPos_LookAt;
        float armExtension = cVector().SetSub(rWristPos_BaseIk, rShoulderPos_BaseIk).Length();
        cVector armDir((rWristPos_LookAt - rShoulderPos_LookAt).Normalize());
        if (!IsNearIdentityR(self->q250)) {
            cVector up;
            cMatrix armMatrix;
            cQuaternion gunRecoilAdditionalFraction;
            if (0) {
            up = armDir;
            armMatrix.m[0][0] = 0.0f;
            gunRecoilAdditionalFraction = self->q250;
            up = Sb(armDir, headPos_LookAt); up = armDir * 2.0f; up = up + armDir;
            Keep1(up);
            }
        }
        rWristTargetPos_SkelSpace = rShoulderPos_LookAt + armDir * armExtension;
        wasCalculated = 1;
        break;
    }
    case 3: {
        cBoneIk& rWristIk = D_004F46B0;
        cBoneIk& headIk = D_004F40B0;
        cBoneIk& rShoulderIk = D_004F41B0;
        const cVector& rWristPos_BaseIk = rWristIk.ikAnimPos;
        const cVector& headPos_BaseIk = headIk.ikAnimPos;
        const cQuaternion& headRot_BaseIk = headIk.ikAnimRot;
        const cVector& headPos_LookAt = headIk.lookAtPos;
        const cQuaternion& headRot_LookAt = headIk.lookAtRot;
        const cVector& rShoulderPos_BaseIk = rShoulderIk.ikAnimPos;
        const cVector& rShoulderPos_LookAt = rShoulderIk.lookAtPos;
        cQuaternion& q = self->q250;
        float r = 0.0f; float d = 1.0f - q.w; asm { abs.s r, d } bool b = r <= 1e-7f;
        cVector rWristPos_LookAt(rWristPos_BaseIk);
        cQuaternion gunRecoilAdditionalFraction;
        if (0) { gunRecoilAdditionalFraction = self->q250; R0(rWristPos_LookAt); Dz(rWristPos_LookAt); Dz(rWristPos_LookAt); D2(rWristPos_LookAt); D2(rWristPos_LookAt); }
        Translate(Rotate(InverseRotate(InverseTranslate(rWristPos_LookAt, headPos_BaseIk), headRot_BaseIk), headRot_LookAt), headPos_LookAt);
        float armExtension = (rWristPos_BaseIk - rShoulderPos_BaseIk).Length();
        cVector armDir((rWristPos_LookAt - rShoulderPos_LookAt).Normalize());
        rWristTargetPos_SkelSpace = rShoulderPos_LookAt + armExtension * armDir;
        if (0) { DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); }
        wasCalculated = 1;
        break;
    }
    case 6:
    case 7: {
        cBoneIk& rWristIk = D_004F46B0;
        cBoneIk& rShoulderIk = D_004F41B0;
        const cVector& rWristPos_BaseIk = rWristIk.ikAnimPos;
        const cVector& rShoulderPos_BaseIk = rShoulderIk.ikAnimPos;
        const cVector& rShoulderPos_LookAt = rShoulderIk.lookAtPos;
        cVector armVec(rWristPos_BaseIk - rShoulderPos_BaseIk);
        rWristTargetPos_SkelSpace = rShoulderPos_LookAt + armVec;
        wasCalculated = 1;
        break;
    }
    case 10:
    case 11:
    case 12:
    case 16: {
        signed char refBone;
        if (iMode == 10 || iMode == 11) {
            refBone = 14;
        } else if (iMode == 12 || iMode == 16) {
            refBone = 0;
        } else {
            refBone = 0;
        }
        cBoneIk& rWristIk = D_004F46B0;
        cBoneIk& refBoneIk = UpperBodyNodeTable[refBone];
        const cVector& rWristPos_BaseIk = rWristIk.ikAnimPos;
        const cVector& refBonePos_BaseIk = refBoneIk.ikAnimPos;
        const cQuaternion& refBoneRot_BaseIk = refBoneIk.ikAnimRot;
        const cVector& refBonePos_LookAt = refBoneIk.lookAtPos;
        const cQuaternion& refBoneRot_LookAt = refBoneIk.lookAtRot;
        switch (iMode) {
        case 10:
        case 11: {
            cQuaternion& q = self->q250;
            float d = 1.0f - q.w; float r = 0.0f; asm { abs.s r, d } bool b = r <= 1e-7f;
            cQuaternion gunRecoilAdditionalFraction;
            if (0) { gunRecoilAdditionalFraction = self->q250; R0(rWristTargetPos_SkelSpace); Dz(rWristTargetPos_SkelSpace); Dz(rWristTargetPos_SkelSpace); D2(rWristTargetPos_SkelSpace); D2(rWristTargetPos_SkelSpace); }
            rWristTargetPos_SkelSpace = rWristPos_BaseIk;
            Translate(Rotate(InverseRotate(InverseTranslate(rWristTargetPos_SkelSpace, refBonePos_BaseIk), refBoneRot_BaseIk), refBoneRot_LookAt), refBonePos_LookAt);
            break;
        }
        case 12:
        case 16:
            rWristTargetPos_SkelSpace = rWristPos_BaseIk;
            Translate(Rotate(InverseRotate(InverseTranslate(rWristTargetPos_SkelSpace, refBonePos_BaseIk), refBoneRot_BaseIk), refBoneRot_LookAt), refBonePos_LookAt);
            break;
        }
        wasCalculated = 1;
        break;
    }
    case 0: case 1: case 2: case 8: case 9: case 13: case 14: case 15:
    case 17: case 18: case 19: case 20: case 21: case 22:
        break;
    case 24: {
        cHandTarget& h = self->h660;
        rWristTargetPos_SkelSpace = h.pos;
        wasCalculated = 1;
        break;
    }
    }
    return wasCalculated;
}
