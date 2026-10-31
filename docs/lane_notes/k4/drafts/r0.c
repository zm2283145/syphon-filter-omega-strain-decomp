#pragma cplusplus on
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma enumsalwaysint off
#pragma opt_rotateloops off

class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(const cQuaternion& source) { cQuaternion* refThis = this; u_long128 reg; const cQuaternion* s = &source; asm { lq reg, 0(s); sq reg, 0(refThis) } }
    cQuaternion& operator=(const cQuaternion& source) { const cQuaternion* s = &source; cQuaternion* d = this; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
} __attribute__((aligned(16)));

enum eAnimSource { M_SOURCE_None, M_SOURCE_NonIkPose, M_SOURCE_BaseIkPose, M_SOURCE_IntermediatePose, M_SOURCE_LimbPose };

class cBone {
public:
    char pad[0x1A0];
    cQuaternion localRot;
    char pad1B0[0x10];
    cQuaternion rot;
};

class cJointInfo { public: char pad[0x10]; cQuaternion center; char pad20[0x10]; };

struct cPose {
    cQuaternion localRot;
    cQuaternion rot;
    cQuaternion pos;
};

class cBoneIk {
public:
    cBone* bone;
    char pad4[0xC];
    cJointInfo jointInfo;
    cPose ikAnim;
    char pad70[0x10];
    cPose lookAt;
    char padB0[0x10];
    cBoneIk* parent;
    char padC4[0xC];
    cPose limbPose;
    const cQuaternion& GetRot(eAnimSource src) const
    {
        switch (src) {
        case M_SOURCE_None:
        case M_SOURCE_NonIkPose:
            return bone->localRot;
        case M_SOURCE_BaseIkPose:
            return ikAnim.localRot;
        case M_SOURCE_IntermediatePose:
            return lookAt.localRot;
        case M_SOURCE_LimbPose:
            return limbPose.localRot;
        }
        return bone->localRot;
    }
};

extern cBoneIk UpperBodyNodeTable[];

struct SecState { char pad[0x44]; eAnimSource* resultPoseSources; char pad48[8]; };
extern SecState SecondaryStateTable[];
static inline SecState& GetSecState(int i) { return SecondaryStateTable[i]; }

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

extern "C" cBone** std_vector_deleter_cBone_data_void(void* self);

class cArray {
public:
    int pad0;
    int mSize;
    cBone* mData;
    unsigned char mCanExpand;
    Iterator Begin() { Iterator it(*std_vector_deleter_cBone_data_void(this)); return it; }
    Iterator End() { Iterator it(*std_vector_deleter_cBone_data_void(this) + mSize); return it; }
};

struct cSkel { char pad[0x18]; cArray boneList; };

class cHumanIkRoutine {
public:
    void* vtbl;
    cSkel* skel;
    char pad8[0x310 - 8];
    unsigned char currMode;
    unsigned char nextMode;
    char pad312[0x31C - 0x312];
    float modeTransitionLerpValue;
};

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

static inline cQuaternion NLERP(const cQuaternion& b, const cQuaternion& c, float s)
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
        vmul.xyzw vf5, vf4, vf4
        vmulax.w ACC, vf0, vf5x
        vmadday.w ACC, vf0, vf5y
        vmaddaz.w ACC, vf0, vf5z
        vmaddw.w vf6, vf0, vf5w
        vrsqrt Q, vf0w, vf6w
        vwaitq
        vmulq.xyzw vf7, vf4, Q
        sqc2 vf7, 0x0(q1)
    }
    return l0;
}

extern "C" void cHumanIkRoutine_CalculateResultPose(cHumanIkRoutine* self)
{
    unsigned char isInModeTransition = self->currMode != self->nextMode;
    cArray& boneList = self->skel->boneList;
    eAnimSource* curr_AnimSourceForResultPose_Iterator = GetSecState(self->currMode).resultPoseSources;
    eAnimSource* next_AnimSourceForResultPose_Iterator = GetSecState(self->nextMode).resultPoseSources;
    Iterator currBone = boneList.Begin();
    Iterator endBone = boneList.End();
    cBoneIk* currBoneIk = UpperBodyNodeTable;
    for (; currBone != endBone; ++currBone) {
        cQuaternion result;
        eAnimSource curr_AnimSourceForResultPose = *curr_AnimSourceForResultPose_Iterator;
        if (isInModeTransition) {
            eAnimSource next_AnimSourceForResultPose = *next_AnimSourceForResultPose_Iterator;
            if (curr_AnimSourceForResultPose != next_AnimSourceForResultPose) {
                cQuaternion currRot = currBoneIk->GetRot(curr_AnimSourceForResultPose);
                cQuaternion nextRot = currBoneIk->GetRot(next_AnimSourceForResultPose);
                NegateIfDotProductNegative(currRot, currBoneIk->jointInfo.center);
                NegateIfDotProductNegative(nextRot, currBoneIk->jointInfo.center);
                result = NLERP(currRot, nextRot, self->modeTransitionLerpValue);
            } else {
                result = currBoneIk->GetRot(curr_AnimSourceForResultPose);
                NegateIfDotProductNegative(result, currBoneIk->jointInfo.center);
            }
        } else {
            result = currBoneIk->GetRot(curr_AnimSourceForResultPose);
            NegateIfDotProductNegative(result, currBoneIk->jointInfo.center);
        }
        (*currBone).rot = result;
        currBoneIk++;
        curr_AnimSourceForResultPose_Iterator++;
        next_AnimSourceForResultPose_Iterator++;
    }
}
