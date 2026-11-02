/*
 * SFOGame/Source/humanIk: 4 files, 001D29F0-001D2C10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D29F0 */
#pragma push /* merge_units */
/* 001D29F0 nIk_ApplyJointLimits -- nIk::ApplyJointLimits (humanIk.cc). l5 match. */
#pragma cplusplus on
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma peephole on
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma opt_dead_assignments off

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(float ax, float ay, float az, float aw) {  x = ax; y = ay; z = az; w = aw; }
    cVector(const cVector& source) { cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); }
    float X() const { return x; }
    float Y() const { return y; }
    float Z() const { return z; }
} __attribute__((aligned(16)));

class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion& operator=(const cQuaternion& o) { u_long128 reg; const cQuaternion* s = &o; cQuaternion* d = this; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
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
    float X() const { return x; }
    float Y() const { return y; }
    float Z() const { return z; }
    float W() const { return w; }
    float& X() { return x; }
    float& Y() { return y; }
    float& Z() { return z; }
    float& W() { return w; }
} __attribute__((aligned(16)));

static inline cVector& Normalize(const cVector& vv, float& returnLength)
{
        cVector* v = (cVector*)&vv; u_long128 reg = 0; float* pl = &returnLength;
        asm {
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
    return (cVector&)vv;
}
class cJointLimits {
public:
    float x, y, z, pad;
} __attribute__((aligned(16)));

static inline float SQUARE(float f) { return f * f; }
static inline float SQRT(float x) { float r = 0.0f; asm volatile { sqrt.s r, x } return r; }
static inline float CLAMP_LOW(float a, float b) { float r = 0.0f; float bb = b; asm volatile { max.s a, bb, a } r = a; return r; }

extern "C" unsigned char nIk_ApplyJointLimits(cQuaternion& output, const cQuaternion& input, const cJointLimits& oneOverLimitSinHalfAngleSquared)
{
    if (input.IsZeroXYZ()) {
        output = input;
        return false;
    }
    float sinHalfAngle;
    
    cVector axis(Normalize(cVector(input.X(), input.Y(), input.Z(), 0.0f), sinHalfAngle));
    float limitSinSquared = 0.0f;
    u_long128 reg;
    __asm__ volatile("lqc2 vf1, 0(%1)\n lqc2 vf2, 0(%2)\n vmul.xyz vf3, vf1, vf1\n vmul.xyz vf4, vf3, vf2\n vmulax.w ACC, vf0, vf4x\n vmadday.w ACC, vf0, vf4y\n vmaddz.w vf5, vf0, vf4z\n vdiv Q, vf0w, vf5w\n vwaitq\n vaddq.x vf6, vf0, Q\n qmfc2.ni %0, vf6" : "=r"(reg) : "r"(&axis), "r"(&oneOverLimitSinHalfAngleSquared));
    __asm__ volatile("mtc1 %1, %0" : "=f"(limitSinSquared) : "r"(reg));
    if (SQUARE(sinHalfAngle) > limitSinSquared || input.W() < 0.0f) {
        float limitCosSquared = CLAMP_LOW(1.0f - limitSinSquared, 0.0f);
        output.W() = SQRT(limitCosSquared);
        float limitSin = SQRT(limitSinSquared);
        output.X() = limitSin * axis.X();
        output.Y() = limitSin * axis.Y();
        output.Z() = limitSin * axis.Z();
        return true;
    }
    output = input;
    return false;
}
static inline void merge_flush_func_001D29F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D29F0 */

/* merge_units: begin func_001D2BA0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
/* VU0 hand-scheduled block (MAC-flag test with branch-likely), emitted as written */
void nIk_NegateIfDotProductNegative(V4* a, V4* b) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
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
        sqc2 vf5, 0x0(a)
        nop
    done:
        .set reorder
    }
}
static inline void merge_flush_func_001D2BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D2BA0 */

/* merge_units: begin func_001D2C00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* cJointInfo_BoneSpaceToJointSpaceTransform(char* self) {
    return self + 32;
}
static inline void merge_flush_func_001D2C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D2C00 */

/* merge_units: begin func_001D2C10 */
#pragma push /* merge_units */
/* 001D2C10 cHumanIkRoutine_PositionArm -- cHumanIkRoutine::PositionArm (humanIk.cc). l5 match. */
#pragma cplusplus on

#pragma inline_depth(10)
#pragma peephole off
#pragma opt_propagation off
#pragma opt_dead_assignments off

class cVector_001D2C10 {
public:
    float x, y, z, w;
    cVector_001D2C10& operator=(const cVector_001D2C10& source) { u_long128 reg; const cVector_001D2C10* s = &source; cVector_001D2C10* d = this; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
} __attribute__((aligned(16)));

class cQuaternion_001D2C10 {
public:
    float x, y, z, w;
    cQuaternion_001D2C10() {}
    cQuaternion_001D2C10(const cQuaternion_001D2C10& source) { cQuaternion_001D2C10* refThis = this; u_long128 reg; const cQuaternion_001D2C10* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(refThis) } }
    cQuaternion_001D2C10& Assign(const cQuaternion_001D2C10& source) { u_long128 reg; const cQuaternion_001D2C10* s = &source; cQuaternion_001D2C10* d = this; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    cQuaternion_001D2C10& operator=(const cQuaternion_001D2C10& source) { const cQuaternion_001D2C10* s = &source; cQuaternion_001D2C10* d = this; u_long128 reg; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
} __attribute__((aligned(16)));

class cJointLimits_001D2C10 { public: float x, y, z, w; } __attribute__((aligned(16)));

class cJointInfo { public: char pad[0x30]; };

extern "C" const cJointLimits_001D2C10& func_001D2870(const cJointInfo* self);
extern "C" const cQuaternion_001D2C10& cJointInfo_CenterPosition_InBoneSpace(const cJointInfo* self);

struct cPose {
    cQuaternion_001D2C10 localRot;
    cQuaternion_001D2C10 rot;
    cVector_001D2C10 pos;
    cVector_001D2C10& Pos() { cPose* t = this; return t->pos; }
    cQuaternion_001D2C10& LocalRot() { cPose* t = this; return t->localRot; }
    cQuaternion_001D2C10& Rot() { cPose* t = this; return t->rot; }
    const cVector_001D2C10& Pos() const { const cPose* t = this; return t->pos; }
    const cQuaternion_001D2C10& LocalRot() const { const cPose* t = this; return t->localRot; }
    const cQuaternion_001D2C10& Rot() const { const cPose* t = this; return t->rot; }
    cPose& operator=(const cPose& o) { LocalRot().Assign(o.LocalRot()); Rot().Assign(o.Rot()); Pos() = o.Pos(); return *this; }
};

struct cIntermediatePose : cPose {
    cVector_001D2C10 pad;
};

struct cBaseIkPose {
    cQuaternion_001D2C10 rot;
    cQuaternion_001D2C10 pad0;
    cVector_001D2C10 pad2;
    cVector_001D2C10 pad3;
    const cQuaternion_001D2C10& Rot() const { const cBaseIkPose* t = this; return t->rot; }
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

extern "C" void nIk_TwoLimbIK(cQuaternion_001D2C10& a, cQuaternion_001D2C10& b, const cVector_001D2C10& c, const cVector_001D2C10& d, const cQuaternion_001D2C10& e,
    const cJointLimits_001D2C10& f, const cQuaternion_001D2C10& g, const cVector_001D2C10& h, const cQuaternion_001D2C10& i, const cJointLimits_001D2C10& j,
    const cQuaternion_001D2C10& k, const cQuaternion_001D2C10& l, const cVector_001D2C10& m);
extern "C" void cBoneIk_LimbPose_CalculateSkelSpaceInfo(cBoneIk* self);
extern "C" void cBoneIk_LimbPose_CalculateSkelSpacePos(cBoneIk* self);

static inline void NegateIfDotProductNegative(cQuaternion_001D2C10& a, const cQuaternion_001D2C10& b)
{
    int t;
    cQuaternion_001D2C10* pa = &a;
    const cQuaternion_001D2C10* pb = &b;
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

static inline cQuaternion_001D2C10 LERP(const cQuaternion_001D2C10& b, const cQuaternion_001D2C10& c, float s)
{
    cQuaternion_001D2C10 l0;
    cQuaternion_001D2C10* q1 = &l0;
    const cQuaternion_001D2C10* bb = &b;
    const cQuaternion_001D2C10* cc = &c;
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

static inline cQuaternion_001D2C10 Blend(const cQuaternion_001D2C10& from, const cQuaternion_001D2C10& to, float weight)
{
    cQuaternion_001D2C10 t = to;
    NegateIfDotProductNegative(t, from);
    return LERP(from, t, weight);
}


extern "C" void cHumanIkRoutine_PositionArm(void* self, const cVector_001D2C10& desiredWristPos_SkelSpace, float weight, unsigned int wristIndex)
{
    cBoneIk* wristIk = &UpperBodyNodeTable[wristIndex];
    cBoneIk* elbowIk = wristIk->parent;
    cBoneIk* shoulderIk = elbowIk->parent;
    cBoneIk* collarIk = shoulderIk->parent;
    cBoneIk* chestIk = collarIk->parent;
    if (weight > 0.0f) {
        cQuaternion_001D2C10 newShoulderRot_Local;
        cQuaternion_001D2C10 newElbowRot_Local;
        const cIntermediatePose& wLA = wristIk->lookAt;
        const cIntermediatePose& cLA = collarIk->lookAt;
        const cVector_001D2C10* rd;
        const cQuaternion_001D2C10* re;
        const cQuaternion_001D2C10* ri;
        const cVector_001D2C10* rh;
        const cQuaternion_001D2C10* rl;
        const cVector_001D2C10* rm;
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
    { const cQuaternion_001D2C10* p = &chestIk->lookAt.localRot; cQuaternion_001D2C10* d = &chestIk->limbPose.localRot; d[0] = p[0]; d[1] = p[1]; d[2] = p[2]; }
    { cQuaternion_001D2C10* d = &collarIk->limbPose.localRot; const cQuaternion_001D2C10* p = &collarIk->lookAt.localRot; d[0] = p[0]; d[1] = p[1]; d[2] = p[2]; }
    cBoneIk_LimbPose_CalculateSkelSpaceInfo(shoulderIk);
    cBoneIk_LimbPose_CalculateSkelSpaceInfo(elbowIk);
    cBoneIk_LimbPose_CalculateSkelSpacePos(wristIk);
}
static inline void merge_flush_func_001D2C10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D2C10 */
