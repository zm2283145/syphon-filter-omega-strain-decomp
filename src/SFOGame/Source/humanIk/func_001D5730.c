/* 001D5730 cHumanIkRoutine_CalculateIntermediatePose -- cHumanIkRoutine::CalculateIntermediatePose (humanIk.cc). l5 match. */
#pragma cplusplus on
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma defer_codegen on
#pragma enumsalwaysint off
#pragma opt_rotateloops off

class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(const cQuaternion& source) { cQuaternion* refThis = this; u_long128 reg; const cQuaternion* s = &source; asm { lq reg, 0(s); sq reg, 0(refThis) } }
    cQuaternion& operator=(const cQuaternion& source) { cQuaternion* d = this; const cQuaternion* s = &source; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    void SetIdentity() { cQuaternion* d = this; asm volatile { sqc2 vf0, 0(d) } }
    void Invert() { cQuaternion* d = this; asm volatile { lqc2 vf1, 0(d); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0(d) } }
    cQuaternion GetRotated(const cQuaternion& c) const
    {
        cQuaternion l0;
        const cQuaternion* b = this;
        cQuaternion* q1 = &l0;
        const cQuaternion* cc = &c;
        asm volatile {
            lqc2 vf1, 0x0(cc)
            lqc2 vf2, 0x0(b)
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
        return l0;
    }
    void Rotate(const cQuaternion& c) { cQuaternion* p = this; *p = p->GetRotated(c); }
} __attribute__((aligned(16)));

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { const cVector* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
    cVector& operator=(const cVector& source) { const cVector* s = &source; cVector* d = this; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    void SetZero() { cVector* d = this; asm volatile { sq zero, 0(d) } }
    float& W() { return w; }
    inline void RT(const cQuaternion& q, const cVector& t);
    inline void AddXYZm(const cVector& o) { cVector* pa = this; const cVector* pb = &o; asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(pa) } }
    const float& W() const { return w; }
} __attribute__((aligned(16)));

enum eAnimSource {
    M_SOURCE_None,
    M_SOURCE_CalculatePositionOnly,
    M_SOURCE_NonIkPose,
    M_SOURCE_BaseIkPoseBlendedWithOtherSource,
    M_SOURCE_BaseIkPose,
    M_SOURCE_LookAtPoseBlendedWithOtherSource,
    M_SOURCE_LookAtPose
};

class cBone {
public:
    char pad[0x1A0];
    cQuaternion currAnimFrame_LocalRotation;
    cVector currAnimFrame_LocalOffset;
    cQuaternion ikResult;
};

struct cJointLimits { float x, y, z, pad; };

class cJointInfo {
public:
    cJointLimits limits_InJointSpace;
    cQuaternion jointSpaceToBoneSpaceTransform;
    cQuaternion boneSpaceToJointSpaceTransform;
};

struct cPose {
    cQuaternion rot_Local;
    cQuaternion rot_SkelSpace;
    cVector pos_SkelSpace;
};

struct cAnimSource { eAnimSource curr; eAnimSource next; };

struct cBaseIkPose : public cPose { unsigned char getsCalculated; };
struct cIntermediatePose : public cPose {
    cAnimSource animSource;
    float lookAtWeight;
    unsigned char stickCloseToPrevRotInDoingLookAt;
};

class cBoneIk {
public:
    cBone* bone;
    char pad4[0xC];
    cJointInfo jointInfo;
    cBaseIkPose ikAnim;
    cIntermediatePose lookAt;
    cBoneIk* parent;
    char padC4[0xC];
    cPose limbPose;
    char pad100[0x100 - 0x100];
};

extern cBoneIk UpperBodyNodeTable[];

extern "C" void cQuaternion_ctor_cQuaternionR(cQuaternion* self, const cQuaternion* src);
extern "C" cQuaternion cQuaternion_GetRotated(const cQuaternion* self, const cQuaternion* q);
extern "C" void nIk_NegateIfWNegative(cQuaternion* q);
extern "C" void nIk_NegateIfDotProductNegative(cQuaternion* a, const cQuaternion* b);
extern "C" cQuaternion LerpAndNormalize(const cQuaternion* a, const cQuaternion* b, float s);
extern "C" void nIk_ApplyJointLimits(cQuaternion* out, const cQuaternion* in, const cJointLimits* limits);
extern "C" cQuaternion* cQuaternion_opAssign(cQuaternion* d, const cQuaternion* s);

union __wrap_iterator { cBone* volatile p; };
class Iterator {
public:
    __wrap_iterator mIterator;
    Iterator() {}
    Iterator(cBone* q) { mIterator.p = q; }
    Iterator(const Iterator& o) { mIterator.p = o.mIterator.p; }
    bool operator==(const Iterator& o) const { cBone* b = o.mIterator.p; return mIterator.p == b; }
    bool operator!=(const Iterator& o) const { return !(*this == o); }
    Iterator& operator++() { ++mIterator.p; return *this; }
    cBone& operator*() const { return *mIterator.p; }
};

extern "C" cBone** std_vector_deleter_cBone_data_void_2(void* self);

class cArray {
public:
    int pad0;
    int mSize;
    cBone* mData;
    unsigned char mCanExpand;
    Iterator Begin() { Iterator it(*std_vector_deleter_cBone_data_void_2(this)); return it; }
    Iterator End() { Iterator it(*std_vector_deleter_cBone_data_void_2(this) + mSize); return it; }
};

struct cSkel { char pad[0x18]; cArray boneList; };

class cHumanIkRoutine {
public:
    void* vtbl;
    cSkel* skel;
    char pad8[0x31C - 8];
    float modeTransitionLerpValue;
};

static inline eAnimSource Max(eAnimSource a, eAnimSource b) { return a > b ? a : b; }
static inline eAnimSource Min(eAnimSource a, eAnimSource b) { return a < b ? a : b; }

static inline void NegQ(cQuaternion* d, const cQuaternion* p)
{
    asm volatile {
        lqc2 vf1, 0(p)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0(d)
    }
}
static inline void NegateIfWNegative(cQuaternion& q)
{
    if (q.w < 0.0f) {
        NegQ(&q, &q);
    }
}

static inline void NegateIfDotProductNegative(cQuaternion& a, const cQuaternion& b)
{
    int t;
    cQuaternion* pa = &a;
    const cQuaternion* pb = &b;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
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
        cfc2.ni t, vi17
        andi t, t, 0x10
        beql t, zero, done
        nop
        sqc2 vf5, 0x0(pa)
    done:
        .set reorder
    }
}

static inline cQuaternion Lerp(const cQuaternion& b, const cQuaternion& c, float s)
{
    cQuaternion l0;
    cQuaternion* q1 = &l0;
    const cQuaternion* bb = &b;
    const cQuaternion* cc = &c;
    int rv1;
    asm volatile {
        lqc2 vf1, 0x0(bb)
        lqc2 vf2, 0x0(cc)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        sqc2 vf4, 0x0(q1)
    }
    return l0;
}

static inline cQuaternion BlendShortest0(const cQuaternion& a, const cQuaternion& b, float t)
{
    cQuaternion other = b;
    NegateIfDotProductNegative(other, a);
    return Lerp(a, other, t);
}


static inline void RotateVector(cVector& v, const cQuaternion& q)
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
}

static inline cVector Scale(const cVector& b, float s)
{
    cVector l0;
    cVector* q1 = &l0;
    const cVector* bb = &b;
    int rv1;
    asm volatile {
        .set noreorder
        lqc2 vf1, 0x0(bb)
        mfc1 rv1, s
        qmtc2.ni rv1, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q1)
        .set reorder
    }
    return *q1;
}


static inline void BlendLookAt3(cQuaternion* out, const cJointLimits* limits, const cQuaternion* j2b, const cQuaternion& b2jSrc, const cQuaternion& nonIkPoseRot_Local, const cQuaternion& lookAtRot_Local, const cQuaternion& referenceRot_Local, float weight);
static inline void BlendLookAt2(cQuaternion* out, const cJointLimits* limits, const cQuaternion* j2b, const cQuaternion& b2jSrc, const cQuaternion& nonIkPoseRot_Local, const cQuaternion& lookAtRot_Local, const cQuaternion& referenceRot_Local, float weight)
{
    BlendLookAt3(out, limits, j2b, b2jSrc, nonIkPoseRot_Local, lookAtRot_Local, referenceRot_Local, weight);
}
static inline void BlendLookAt1(cQuaternion* out, const cJointLimits* limits, const cQuaternion* j2b, const cQuaternion& b2jSrc, const cQuaternion& nonIkPoseRot_Local, const cQuaternion& lookAtRot_Local, const cQuaternion& referenceRot_Local, float weight)
{
    BlendLookAt2(out, limits, j2b, b2jSrc, nonIkPoseRot_Local, lookAtRot_Local, referenceRot_Local, weight);
}

static inline void BlendLookAt0(cQuaternion* out, const cJointLimits* limits, const cQuaternion* j2b, const cQuaternion& b2jSrc, const cQuaternion& nonIkPoseRot_Local, const cQuaternion& lookAtRot_Local, const cQuaternion& referenceRot_Local, float weight)
{
    BlendLookAt1(out, limits, j2b, b2jSrc, nonIkPoseRot_Local, lookAtRot_Local, referenceRot_Local, weight);
}


inline void cVector::RT(const cQuaternion& q, const cVector& t) {
    RotateVector(*this, q);
    float w = W();
    if (w == 1.0f) {
        AddXYZm(t);
    } else {
        cVector s = Scale(t, w);
        AddXYZm(s);
        W() = s.W();
    }
}

extern "C" void cHumanIkRoutine_CalculateIntermediatePose(cHumanIkRoutine* self, const cQuaternion& dirToLookAtTarget_SkelSpace)
{
    cArray& boneList = self->skel->boneList;
    Iterator currBone = boneList.Begin();
    Iterator endBone = boneList.End();
    cBoneIk* currBoneIk = UpperBodyNodeTable;
    for (; currBone != endBone; ++currBone, currBoneIk++) {
        eAnimSource dominantSource = Max(currBoneIk->lookAt.animSource.curr, currBoneIk->lookAt.animSource.next);
        if (dominantSource != M_SOURCE_None) {
            cBoneIk* parentIk = currBoneIk->parent;
            cQuaternion parentRot_SkelSpace;
            cVector parentPos_SkelSpace;
            if (parentIk) {
                parentRot_SkelSpace = parentIk->lookAt.rot_SkelSpace;
                parentPos_SkelSpace = parentIk->lookAt.pos_SkelSpace;
            } else {
                parentRot_SkelSpace.SetIdentity();
                parentPos_SkelSpace.SetZero();
            }
            switch (dominantSource) {
            case M_SOURCE_None:
            case M_SOURCE_CalculatePositionOnly:
                break;
            case M_SOURCE_LookAtPose:
            case M_SOURCE_LookAtPoseBlendedWithOtherSource: {
                cQuaternion nonIkPoseRot_Local;
                nonIkPoseRot_Local = (*currBone).currAnimFrame_LocalRotation;
                cQuaternion parentRot_Inverse_SkelSpace;
                cQuaternion lookAtRot_Local;
                if (parentIk) {
                    (parentRot_Inverse_SkelSpace = parentRot_SkelSpace).Invert();
                    (lookAtRot_Local = currBoneIk->ikAnim.rot_SkelSpace).Rotate(parentRot_Inverse_SkelSpace);
                } else {
                    parentRot_Inverse_SkelSpace.SetIdentity();
                    lookAtRot_Local = currBoneIk->ikAnim.rot_SkelSpace;
                }
                cQuaternion referenceRot_Local;
                if (currBoneIk->lookAt.stickCloseToPrevRotInDoingLookAt) {
                    referenceRot_Local = (*currBone).ikResult;
                } else {
                    (referenceRot_Local = dirToLookAtTarget_SkelSpace).Rotate(parentRot_Inverse_SkelSpace);
                    NegateIfWNegative(referenceRot_Local);
                }
                {
                    float weight = currBoneIk->lookAt.lookAtWeight;
                    cQuaternion* out;
                    const cJointLimits* limits;
                    const cQuaternion* j2b;
                    const cQuaternion& b2js = currBoneIk->jointInfo.boneSpaceToJointSpaceTransform;
                    j2b = &currBoneIk->jointInfo.jointSpaceToBoneSpaceTransform;
                    limits = &currBoneIk->jointInfo.limits_InJointSpace;
                    out = &currBoneIk->lookAt.rot_Local;
                    BlendLookAt0(out, limits, j2b, b2js, nonIkPoseRot_Local, lookAtRot_Local, referenceRot_Local, weight);
                }

                break;
            }
            case M_SOURCE_BaseIkPose:
            case M_SOURCE_BaseIkPoseBlendedWithOtherSource:
                currBoneIk->lookAt.rot_Local = currBoneIk->ikAnim.rot_Local;
                break;
            case M_SOURCE_NonIkPose:
                currBoneIk->lookAt.rot_Local = (*currBone).currAnimFrame_LocalRotation;
                break;
            }
            switch (dominantSource) { case M_SOURCE_LookAtPoseBlendedWithOtherSource: case M_SOURCE_BaseIkPoseBlendedWithOtherSource: {
                eAnimSource subordinateSource = Min(currBoneIk->lookAt.animSource.curr, currBoneIk->lookAt.animSource.next);
                if (subordinateSource != dominantSource) {
                    switch (subordinateSource) {
                    case M_SOURCE_None:
                        break;
                    case M_SOURCE_NonIkPose:
                    case M_SOURCE_BaseIkPoseBlendedWithOtherSource:
                    case M_SOURCE_BaseIkPose: {
                        cQuaternion rotFromOtherSource_Local;
                        switch (subordinateSource) {
                        case M_SOURCE_NonIkPose:
                            rotFromOtherSource_Local = (*currBone).currAnimFrame_LocalRotation;
                            break;
                        case M_SOURCE_BaseIkPoseBlendedWithOtherSource:
                        case M_SOURCE_BaseIkPose:
                            rotFromOtherSource_Local = currBoneIk->ikAnim.rot_Local;
                            break;
                        }
                        float lerpValue;
                        eAnimSource c = currBoneIk->lookAt.animSource.curr;
                        if (dominantSource == c) {
                            lerpValue = 1.0f - self->modeTransitionLerpValue;
                        } else {
                            lerpValue = self->modeTransitionLerpValue;
                        }
                        currBoneIk->lookAt.rot_Local = BlendShortest0(rotFromOtherSource_Local, currBoneIk->lookAt.rot_Local, lerpValue);

                        break;
                    }
                    }
                }
            }}
            if (dominantSource != M_SOURCE_CalculatePositionOnly) {
                cQuaternion& rs = currBoneIk->lookAt.rot_SkelSpace;
                rs = currBoneIk->lookAt.rot_Local;
                rs.Rotate(parentRot_SkelSpace);
            }
            cVector& ps = currBoneIk->lookAt.pos_SkelSpace;
            (ps = (*currBone).currAnimFrame_LocalOffset).RT(parentRot_SkelSpace, parentPos_SkelSpace);
       }
    }
}

static inline void BlendLookAt3(cQuaternion* out, const cJointLimits* limits, const cQuaternion* j2b, const cQuaternion& b2jSrc, const cQuaternion& nonIkPoseRot_Local, const cQuaternion& lookAtRot_Local, const cQuaternion& referenceRot_Local, float weight)
{
    cQuaternion b2j;
    cQuaternion_ctor_cQuaternionR(&b2j, &b2jSrc);
    cQuaternion a = cQuaternion_GetRotated(&nonIkPoseRot_Local, &b2j);
    cQuaternion b = cQuaternion_GetRotated(&lookAtRot_Local, &b2j);
    cQuaternion c = cQuaternion_GetRotated(&referenceRot_Local, &b2j);
    nIk_NegateIfWNegative(&a);
    nIk_NegateIfDotProductNegative(&b, &c);
    cQuaternion r = LerpAndNormalize(&a, &b, weight);
    nIk_ApplyJointLimits(&r, &r, limits);
    cQuaternion_opAssign(out, &cQuaternion_GetRotated(&r, j2b));
}
