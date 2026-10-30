/* 001D2C10 cHumanIkRoutine_PositionArm -- cHumanIkRoutine::PositionArm (humanIk.cc). l5 match. */
#pragma cplusplus on
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma peephole off
#pragma opt_propagation off
#pragma opt_dead_assignments off

class cVector {
public:
    float x, y, z, w;
    cVector& operator=(const cVector& source) { u_long128 reg; const cVector* s = &source; cVector* d = this; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
} __attribute__((aligned(16)));

class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(const cQuaternion& source) { cQuaternion* refThis = this; u_long128 reg; const cQuaternion* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(refThis) } }
    cQuaternion& Assign(const cQuaternion& source) { u_long128 reg; const cQuaternion* s = &source; cQuaternion* d = this; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    cQuaternion& operator=(const cQuaternion& source) { const cQuaternion* s = &source; cQuaternion* d = this; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
} __attribute__((aligned(16)));

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
    cPose& operator=(const cPose& o) { LocalRot().Assign(o.LocalRot()); Rot().Assign(o.Rot()); Pos() = o.Pos(); return *this; }
};

struct cIntermediatePose : cPose {
    cVector pad;
};

struct cBaseIkPose {
    cQuaternion rot;
    cQuaternion pad0;
    cVector pad2;
    cVector pad3;
    const cQuaternion& Rot() const { const cBaseIkPose* t = this; return t->rot; }
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

extern cBoneIk UpperBodyNodeTable[];

extern "C" void nIk_TwoLimbIK(cQuaternion& a, cQuaternion& b, const cVector& c, const cVector& d, const cQuaternion& e,
    const cJointLimits& f, const cQuaternion& g, const cVector& h, const cQuaternion& i, const cJointLimits& j,
    const cQuaternion& k, const cQuaternion& l, const cVector& m);
extern "C" void cBoneIk_LimbPose_CalculateSkelSpaceInfo(cBoneIk* self);
extern "C" void cBoneIk_LimbPose_CalculateSkelSpacePos(cBoneIk* self);

static inline void NegateIfDotProductNegative(cQuaternion& a, const cQuaternion& b)
{
    int t;
    cQuaternion* pa = &a;
    const cQuaternion* pb = &b;
    asm volatile {
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

static inline cQuaternion LERP(const cQuaternion& b, const cQuaternion& c, float s)
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

static inline cQuaternion Blend(const cQuaternion& from, const cQuaternion& to, float weight)
{
    cQuaternion t = to;
    NegateIfDotProductNegative(t, from);
    return LERP(from, t, weight);
}


extern "C" void cHumanIkRoutine_PositionArm(void* self, const cVector& desiredWristPos_SkelSpace, float weight, unsigned int wristIndex)
{
    cBoneIk* wristIk = &UpperBodyNodeTable[wristIndex];
    cBoneIk* elbowIk = wristIk->parent;
    cBoneIk* shoulderIk = elbowIk->parent;
    cBoneIk* collarIk = shoulderIk->parent;
    cBoneIk* chestIk = collarIk->parent;
    if (weight > 0.0f) {
        cQuaternion newShoulderRot_Local;
        cQuaternion newElbowRot_Local;
        const cIntermediatePose& wLA = wristIk->lookAt;
        const cIntermediatePose& cLA = collarIk->lookAt;
        const cVector* rd;
        const cQuaternion* re;
        const cQuaternion* ri;
        const cVector* rh;
        const cQuaternion* rl;
        const cVector* rm;
        rd = &shoulderIk->lookAt.Pos();
        re = &shoulderIk->lookAt.LocalRot();
        ri = &elbowIk->lookAt.LocalRot();
        rh = &elbowIk->lookAt.Pos();
        rm = &wLA.Pos();
        rl = &cLA.Rot();
        nIk_TwoLimbIK(newShoulderRot_Local, newElbowRot_Local, desiredWristPos_SkelSpace,
            *rd, *re,
            func_001D2870(&shoulderIk->jointInfo), cJointInfo_CenterPosition_InBoneSpace(&shoulderIk->jointInfo),
            *rh, *ri,
            func_001D2870(&elbowIk->jointInfo), cJointInfo_CenterPosition_InBoneSpace(&elbowIk->jointInfo),
            *rl, *rm);
        if (weight < 1.0f) {
            shoulderIk->limbPose.LocalRot() = Blend(shoulderIk->ikAnim.Rot(), newShoulderRot_Local, weight);
            elbowIk->limbPose.LocalRot() = Blend(elbowIk->ikAnim.Rot(), newElbowRot_Local, weight);
        } else {
            shoulderIk->limbPose.LocalRot() = newShoulderRot_Local;
            elbowIk->limbPose.LocalRot() = newElbowRot_Local;
        }
    } else {
        shoulderIk->limbPose.LocalRot() = shoulderIk->ikAnim.Rot();
        elbowIk->limbPose.LocalRot() = elbowIk->ikAnim.Rot();
    }
    { const cQuaternion* p = &chestIk->lookAt.localRot; cQuaternion* d = &chestIk->limbPose.localRot; d[0] = p[0]; d[1] = p[1]; d[2] = p[2]; }
    { cQuaternion* d = &collarIk->limbPose.localRot; const cQuaternion* p = &collarIk->lookAt.localRot; d[0] = p[0]; d[1] = p[1]; d[2] = p[2]; }
    cBoneIk_LimbPose_CalculateSkelSpaceInfo(shoulderIk);
    cBoneIk_LimbPose_CalculateSkelSpaceInfo(elbowIk);
    cBoneIk_LimbPose_CalculateSkelSpacePos(wristIk);
}
