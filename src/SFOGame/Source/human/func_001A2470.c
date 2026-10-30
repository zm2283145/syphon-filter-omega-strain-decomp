// cHuman::JumpLaunchApplyForce. Keys: ClampM zero-init+param copies (const order/mtc1 zero); rotate asm in nested RotIP inline kills dead addiu;
// `const cVector* t; (t = &T())->PlusD(Rotate(...))` makes this-vreg early (coloring a3) but def after asm; extra nop = 8-byte branch-target alignment.
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct cVector {
    float x, y, z, w;
    const float& Z() const { return z; }
    float ZV() const { return z; }
    float ZL() const { float r = z; return r; }
    const float& ZR() const { const float& r = z; return r; }
    const float* ZP() const { return &z; }
    cVector() {}
    cVector(float ix, float iy, float iz, float iw) : x(ix), y(iy), z(iz), w(iw) {}
    cVector(const cVector& o) { __int128 t; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(this) } }
    cVector operator+(const cVector& b) const;
    cVector PlusD(const cVector& b) const;
    cVector& operator=(const cVector& o) { __int128 t; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(this) } return *this; }
} __attribute__((aligned(16)));

struct cQuaternion { float x, y, z, w; } __attribute__((aligned(16)));

static inline void SubV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
static inline void AddV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}

inline cVector cVector::operator+(const cVector& b) const { cVector r; AddV(&r, this, &b); return r; }
static inline cVector AddR(const cVector& a, const cVector& b) { cVector r; AddV(&r, &a, &b); return r; }
inline cVector cVector::PlusD(const cVector& b) const { return AddR(*this, b); }
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; SubV(&r, &a, &b); return r; }
static inline cVector& operator+=(cVector& a, const cVector& b) { const cVector* pb = &b; cVector* pr = &a; const cVector* pa = &a; asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) } return a; }

static inline void RotIP(cVector* p, const cQuaternion* q) {
    asm volatile {
        lqc2 vf1, 0(p)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0(q)
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
        sqc2 vf6, 0(p)
    }
}
static inline cVector Rotate(const cVector& vv, const cQuaternion* q) {
    cVector v = vv; cVector* p = &v; RotIP(p, q); return *p;
}

static inline float Mul(float a, float b) { return a * b; }
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Clamp(float v, float lo, float hi) { float r = 0.0f; float l = lo; float h = hi; asm { max.s r, v, l; min.s r, r, h } return r; }
static inline float ClampM(float v, float lo, float hi) { float r = 0.0f; r = v; float l = lo; float h = hi; asm { max.s r, r, l; min.s r, r, h } return r; }
static inline float ClampX(float v, float lo, float hi) { float r = 0.0f; float l = lo; float h = hi; r = l; asm { max.s r, v, r; min.s r, r, h } return r; }

extern "C" void cQuatVec_ctor_cQuatVecR(struct cQuatVec* d, const struct cQuatVec* s);
struct cQuatVec {
    cQuaternion q;
    cVector t;
    const cVector& T() const { return t; }
    cQuatVec() {}
    cQuatVec(const cQuatVec& o) { cQuatVec_ctor_cQuatVecR(this, &o); }
};

extern "C" {
void cQuatVec_ctor_cQuatVecR(cQuatVec* d, const cQuatVec* s);
cQuatVec cQuatVec_GetUnit(void);
const cQuaternion* cQuatVec_Rotation(const cQuatVec* q);
const cVector* cQuatVec_Translation(const cQuatVec* q);
cVector* cVector_Transform_cQuaternionR_cVectorR(cVector* v, const cQuaternion* q, const cVector* t);
const cQuatVec* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* node);
}

struct cString48 {
    char s[0x30];
    cString48(const char* p) {
        bool end = 0;
        int i;
        for (i = 0; i < 0x2F; i++) {
            if (p[i] == 0) end = 1;
            s[i] = end ? 0 : p[i];
        }
        s[i] = 0;
    }
};

struct cSkaAnim;
extern "C" {
cSkaAnim* cSkaSystem_GetAnimation(void* sys, const cString48& name);
void* cSkaParams_Skeleton(void* params);
void* cSkeleton_GetSkeletonData(void* skel);
cQuatVec cSkaAnim_GetFirstFrameRootTransform(cSkaAnim* a, void* skelData);
cVector nPhysics_CalculateInitialVelocityForTrajectory(const cVector& from, const cVector& to, float g, float arc, float ang, cVector* out);
extern float g_ThrowGravity;
extern char D_0049DD30[];
extern char D_0049E1B0[];
}

struct cSkaSystem {
    char pad0[0x10];
    char mParams[4];
    cSkaAnim* GetAnimation(const cString48& n) { return cSkaSystem_GetAnimation(this, n); }
    void* GetSkeletonData() { return cSkeleton_GetSkeletonData(cSkaParams_Skeleton(mParams)); }
};

static inline cQuatVec QW1(cSkaAnim* a, void* d) { return cQuatVec(cSkaAnim_GetFirstFrameRootTransform(a, d)); }
static inline cQuatVec QW2(cSkaAnim* a, void* d) { return QW1(a, d); }
static inline cQuatVec QW3(cSkaAnim* a, void* d) { return QW2(a, d); }
static inline cQuatVec QW4(cSkaAnim* a, void* d) { return QW3(a, d); }
static inline cQuatVec GetFirstFrameRootTransform(cSkaSystem* s, const cString48& name) {
    cSkaSystem* ska = s;
    cSkaAnim* anim = ska->GetAnimation(name);
    if (anim) return QW4(anim, ska->GetSkeletonData());
    return cQuatVec_GetUnit();
}

struct cXform {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0x3C];
    cVector mPos;
    unsigned char mDirty;
    cVector GetPosition() { if (mDirty) Update(); return mPos; }
};

struct cMovement { char pad[0xA0]; cVector mVelocity; };
struct cGOBJ2 { char pad[0x54]; cMovement* mMovement; };
struct cCollisionRoutine {
    char pad0[0x1F4];
    cGOBJ2* mParent;
    char pad1F8[0x374 - 0x1F8];
    float mJumpHeight;
    char pad378[0x9C0 - 0x378];
    unsigned char mHasJumpVel;
    char pad9C1[0xF];
    cVector mJumpVel;
    void SetJumpVelocity(const cVector& v) { mHasJumpVel = 1; mJumpVel = v; }
};

#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();

struct cHuman {
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f)
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6();
    virtual cVector GetPosition();
    char pad4[0x4C];
    cXform* mXform;
    char pad54[0x2EC0 - 0x54];
    cSkaSystem mSka;
    cSkaSystem* GetSka() { return &mSka; }
    char pad2ED4[0x3248 - 0x2ED4];
    int mFlags;
    char pad324C[0x3290 - 0x324C];
    void* mAnchor;
    char pad3294[0x3310 - 0x3294];
    cCollisionRoutine* mCollisionRoutine;
    char pad3314[0x3490 - 0x3314];
    unsigned char mJumpMode;
    char pad3491[0x34A0 - 0x3491];
    cQuatVec mJumpFrom;
    cVector mJumpTarget;
    cVector mJumpVelocity;
};

extern "C" void cHuman_JumpLaunchApplyForce(cHuman* self, float f)
{
    if (self->mCollisionRoutine) {
        cVector centerOfMass = self->GetPosition();
        cVector jumpFromPoint = centerOfMass;
        float arcAmount;
        if (self->mJumpMode == 2) {
            cVector firstFrame = GetFirstFrameRootTransform(self->GetSka(), D_0049DD30).t;
            self->mCollisionRoutine->mJumpHeight = 0.5f * Abs(firstFrame.y);
            cVector xformPos = self->mXform->GetPosition();
            cVector xformToCenterOfMass = centerOfMass - xformPos;
            float fy = -0.45f;
            cVector fudge(0.0f, fy, 0.0f, 0.0f);
            self->mJumpTarget = *cVector_Transform_cQuaternionR_cVectorR(&(firstFrame + fudge), cQuatVec_Rotation(&self->mJumpFrom), cQuatVec_Translation(&self->mJumpFrom)) + xformToCenterOfMass;
            self->mJumpTarget.w = 1.0f;
            float deltaZ = self->mJumpFrom.T().Z() - jumpFromPoint.ZV();
            arcAmount = 0.5f - Mul(12.0f - deltaZ, 0.0225f);
            if ((self->mFlags >> 10) & 1)
                arcAmount = ClampX(arcAmount, 0.1f, 1.0f);
            else
                arcAmount = Clamp(arcAmount, 0.5f, 1.0f);
        } else if (self->mJumpMode == 1) {
            cVector firstFrame = GetFirstFrameRootTransform(self->GetSka(), D_0049E1B0).t;
            cVector xformPos = self->mXform->GetPosition();
            cVector xformToCenterOfMass = centerOfMass - xformPos;
            float fz = 0.0f;
            cVector fudge(0.0f, 0.0f, fz, 0.0f);
            const cVector* t;
            self->mJumpTarget = (t = &self->mJumpFrom.T())->PlusD(Rotate(firstFrame, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(self->mAnchor)))).PlusD(xformToCenterOfMass).operator+(fudge);
            self->mJumpTarget.w = 1.0f;
            float deltaZ = self->mJumpTarget.Z() - jumpFromPoint.ZV();
            arcAmount = ClampM(0.5f - Mul(9.0f - deltaZ, 0.0225f), 0.1f, 1.0f);
        } else {
            arcAmount = 0.0f;
        }
        cVector initVelocity = nPhysics_CalculateInitialVelocityForTrajectory(jumpFromPoint, self->mJumpTarget, g_ThrowGravity, arcAmount, 0.785398185f, &self->mJumpVelocity);
        if ((self->mFlags >> 10) & 1) {
            cGOBJ2* parentObject = self->mCollisionRoutine->mParent;
            if (parentObject) {
                cMovement* movementInfo = parentObject->mMovement;
                if (movementInfo) {
                    initVelocity += movementInfo->mVelocity;
                    self->mJumpVelocity += movementInfo->mVelocity;
                }
            }
        }
        self->mCollisionRoutine->SetJumpVelocity(initVelocity);
    }
}



