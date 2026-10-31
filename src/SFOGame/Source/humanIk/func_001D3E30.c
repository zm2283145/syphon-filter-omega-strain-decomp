#pragma cplusplus on
class cVector;
struct CallCopy {};
extern "C" cVector* cVector_ctor_cVectorR(cVector*, const cVector*);
static inline cVector* CtorP(cVector* t, const cVector* s) { cVector_ctor_cVectorR(t, s); return t; }
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(16)
#pragma peephole on
#pragma opt_propagation off
#pragma opt_common_subs off
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
    char pad0[0x60];
    cVector ikAnimPos;
    char pad70[0x30];
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
};

static inline bool IsNearIdentity(const cQuaternion& cQuaternion) { float d = 1.0f - cQuaternion.w; float r = 0.0f; asm { abs.s r, d } return r <= 1e-7f; }

static inline bool IsNearIdentityP(const cQuaternion* qq) { float d = 1.0f - qq->w; float r = 0.0f; asm { abs.s r, d } return r <= 1e-7f; }
static inline const cQuaternion& Ref(const cQuaternion& x) { return x; }
static inline bool IsNearIdentityR(const cQuaternion& x) { const cQuaternion* qq = &x; float d = 1.0f - qq->w; float r = 0.0f; asm { abs.s r, d } return r <= 1e-7f; }
extern "C" {
cVector* cVector_Transform_cQuaternionR_cVectorR(cVector*, const cQuaternion*, const cVector*);
extern cBoneIk D_004F3FB0;
extern cBoneIk D_004F40B0;
extern cBoneIk D_004F45B0;
extern cBoneIk D_004F46B0;
}

static inline cVector XformPt(const cVector& v, const cQuaternion& rot, const cVector& pos)
{
    cVector tmp;
    return cVector(cVector_Transform_cQuaternionR_cVectorR(cVector_ctor_cVectorR(&tmp, &v), &rot, &pos));
}


static inline cVector Sb(const cVector& a, const cVector& b) { return cVector(&a, &b); }
static inline void Dz(const cVector& a) { cVector z(&a, 0); }
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

extern "C" unsigned char cHumanIkRoutine_CalculateLeftWristTargetPos_SkelSpace(cHumanIkRoutine* self, cVector& lWristTargetPos_SkelSpace, unsigned char iMode)
{
    unsigned char wasCalculated = 0;
    switch (iMode) {
    case 5: {
        cBoneIk& lWristIk = D_004F45B0;
        cBoneIk& headIk = D_004F40B0;
        cBoneIk& lShoulderIk = D_004F3FB0;
        const cVector& lWristPos_BaseIk = lWristIk.ikAnimPos;
        const cVector& headPos_BaseIk = headIk.ikAnimPos;
        const cVector& headPos_LookAt = headIk.lookAtPos;
        const cVector& lShoulderPos_BaseIk = lShoulderIk.ikAnimPos;
        const cVector& lShoulderPos_LookAt = lShoulderIk.lookAtPos;
        cVector lWristPos_LookAt(lWristPos_BaseIk);
        (lWristPos_LookAt -= headPos_BaseIk) += headPos_LookAt;
        float armExtension = cVector().SetSub(lWristPos_BaseIk, lShoulderPos_BaseIk).Length();
        cVector armDir((lWristPos_LookAt - lShoulderPos_LookAt).Normalize());
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
        lWristTargetPos_SkelSpace = lShoulderPos_LookAt + armDir * armExtension;
        if (0) { DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); DD(armDir); }
        wasCalculated = 1;
        break;
    }
    case 3:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16: {
        cBoneIk* otherWristIk = &D_004F46B0;
        cPose& p = otherWristIk->limbPose;
        const cQuaternion* rot;
        const cVector* pos = &p.pos;
        rot = &p.rot;
        lWristTargetPos_SkelSpace = XformPt1(self->v490, *rot, *pos);
        wasCalculated = 1;
        break;
    }
    case 0: case 1: case 2: case 4: case 6: case 7: case 8: case 9:
    case 17: case 18: case 19: case 20: case 21: case 22: case 23:
        break;
    case 24:
        cHandTarget& h = self->h4A0;
        lWristTargetPos_SkelSpace = h.pos;
        wasCalculated = 1;
        break;
    }
    return wasCalculated;
}
