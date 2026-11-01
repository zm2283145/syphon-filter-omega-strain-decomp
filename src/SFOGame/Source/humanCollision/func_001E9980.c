/* 001E9980 cHumanCollisionRoutine::NextFrame(float, cSystem&, const cArray<cCollisionFace>&, const cCollisionModelList*)
 * (humanCollision.cc), rebuilt from the prototype DWARF/.line data. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    /* 128-bit lq/sq quadword copy: MW splits a C struct copy into words */
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
    unsigned char IsZero() const;
    /* 128-bit sq of $zero: MW zeroes a struct word by word */
    void Zero() { V* p = this; asm volatile { sq zero, 0(p) } }
} __attribute__((aligned(16)));
struct M { float m[4][4]; } __attribute__((aligned(16)));

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void AddM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void MulT(V* d, const V* p, float s) { __int128 t = 0; asm volatile { .set noreorder; lqc2 vf1, 0(p); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(d); .set reorder } }
/* VU0 all-components-zero test via the MAC status flags (vi17), not expressible in C */
inline unsigned char V::IsZero() const
{
    int k, f, r;
    const V* v = this;
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
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
        nop
    done:
        .set reorder
    }
    return r;
}
/* min.s (EE FPU min), not expressible in C */
static inline float Min(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline V operator*(const V& v, float s) { V r; MulT(&r, &v, s); return r; }
static inline V& operator+=(V& a, const V& b) { AddM(&a, &a, &b); return a; }

extern "C" {
V cVector_opSub(const V* a, const V* b);
V cVector_opMul(const V* a, float s);
V cVector_opAdd(const V* a, const V* b);
V opMul(float s, const V* v);
V* cVector_opAssign(V* d, const V* s);
void cVector_WSet1(V* v);
V* cVector_WSet0(V* v);
V* cVector_ctor_cVectorR(V* d, const V* s);
unsigned char cVector_IsZeroXYZ(const V* v);
V cVector_GetNormalized_floatR(const V* v, float* len);
extern float g_NegFltMax;
extern char D_004A03D0[];
}

static inline V ImpulseToForce(V impulse, float timeStep) { const V* pv = &impulse; return *pv * (1.0f / timeStep); }
struct cCollisionFace { V vertices[3]; V unitNormal; char pad40[0x70 - 0x40]; };
struct cPointMass {
    float mass;
    float invMass;
    char pad8[0x10 - 8];
    V pos;
    V prevPos;
    V vel;
    V accel;
    V force;
    char pad60[0x80 - 0x60];
    void ResetMotion() { force.Zero(); accel.Zero(); prevPos = pos; vel.Zero(); }
    void AddForce(V f) { force += f; }
    /* the integrator bodies sit two inline levels below the call: puts their temps below the impulse temps, as retail */
    void Integrate(float timeStep, float prevTimeStep) { Integrate2(timeStep, prevTimeStep); }
    void Integrate2(float timeStep, float prevTimeStep) { Integrate3(timeStep, prevTimeStep); }
    void Integrate3(float timeStep, float prevTimeStep)
    {
        float ts2;
        float ratio;
        if (prevTimeStep != 0.0f) ratio = timeStep / prevTimeStep;
        else ratio = 1.0f;
        ts2 = timeStep * timeStep;
        V newPos = cVector_opAdd(&cVector_opAdd(&pos, &cVector_opMul(&cVector_opSub(&pos, &prevPos), ratio)), &cVector_opMul(&force, invMass * ts2));
        cVector_opAssign(&prevPos, &pos);
        cVector_opAssign(&pos, &newPos);
        cVector_WSet1(&pos);
        V oldVel;
        cVector_ctor_cVectorR(&oldVel, &vel);
        cVector_opAssign(&vel, &cVector_opMul(&cVector_opSub(&pos, &prevPos), 1.0f / timeStep));
        cVector_opAssign(&accel, &cVector_opMul(&cVector_opSub(&vel, &oldVel), 1.0f / timeStep));
    }
    void IntegrateLimited(float timeStep, float prevTimeStep) { IntegrateLimited2(timeStep, prevTimeStep); }
    void IntegrateLimited2(float timeStep, float prevTimeStep) { IntegrateLimited3(timeStep, prevTimeStep); }
    void IntegrateLimited3(float timeStep, float prevTimeStep)
    {
        float ts2;
        float ratio;
        if (prevTimeStep != 0.0f) ratio = timeStep / prevTimeStep;
        else ratio = 1.0f;
        ts2 = timeStep * timeStep;
        V newPos = cVector_opAdd(&cVector_opAdd(&pos, &cVector_opMul(&cVector_opSub(&pos, &prevPos), ratio)), &cVector_opMul(&force, invMass * ts2));
        cVector_opAssign(&prevPos, &pos);
        cVector_opAssign(&pos, &newPos);
        cVector_WSet1(&pos);
        V newVel = cVector_opMul(&cVector_opSub(&pos, &prevPos), 1.0f / timeStep);
        V acc = cVector_opMul(&cVector_opSub(&newVel, &vel), 1.0f / timeStep);
        if (!cVector_IsZeroXYZ(&acc)) {
            float len;
            V dir = cVector_GetNormalized_floatR(&acc, &len);
            if (len > 900.0f) {
                V maxAccel = opMul(900.0f, &dir);
                V clampedVel = cVector_opAdd(&vel, &cVector_opMul(&maxAccel, timeStep));
                V delta;
                cVector_ctor_cVectorR(&delta, cVector_WSet0(&cVector_opMul(&clampedVel, timeStep)));
                cVector_opAssign(&prevPos, &cVector_opSub(&pos, &delta));
            }
        }
        V oldVel;
        cVector_ctor_cVectorR(&oldVel, &vel);
        cVector_opAssign(&vel, &cVector_opMul(&cVector_opSub(&pos, &prevPos), 1.0f / timeStep));
        cVector_opAssign(&accel, &cVector_opMul(&cVector_opSub(&vel, &oldVel), 1.0f / timeStep));
    }
};
struct cHumanCollisionRoutine;
struct cSystem;
struct cArray;
struct cQuatVec { V rot, trans; };
extern "C" {
void cHumanCollisionRoutine_InitializePosition(cHumanCollisionRoutine*);
void Physical_CopyModeRecord(void* d, const void* s);
void cHumanCollisionRoutine_UpdateClimbingEdge(cHumanCollisionRoutine*, cSystem&, const cArray&);
void cHumanCollisionRoutine_Transport_StartOfFrameUpdate(cHumanCollisionRoutine*, V*, V*, cQuatVec*, float);
void ActorPhys_RunResponse(cHumanCollisionRoutine*, cSystem&, float, float, const cArray&, const V*, const V*);
void cHumanCollisionRoutine_Transport_EndOfFrameUpdate(cHumanCollisionRoutine*);
void* RootCollection_FindByKey(void*, void*);
V* Physical_GetPositionPtr(cPointMass*);
M cSkeleton_GetBoneToWorldMatrix(void*, int);
V* func_00133EC0(M*);
void ActorPhys_AuxiliaryProbe(void*, const cArray&, const V*, void*, float);
void cHumanCollisionRoutine_HandleWaterCollisionIfDetected(cHumanCollisionRoutine*, float);
}
struct cModeSwitch { int a, b; };
struct cModeFlags { int bits[1]; cModeFlags& operator=(const cModeFlags& o) { for (int i = 0; i < 1; i++) bits[i] = o.bits[i]; return *this; } };
struct cAnimSys { char pad0[0xB0]; char root[1]; };

struct cHumanCollisionRoutine {
    void* vt;
    void* mGobj;
    void* skeleton;
    cAnimSys* animationSystem;
    unsigned char hasGoneThroughFirstPassOfNextFrame;
    unsigned char reset;
    char pad12[0x18 - 0x12];
    cModeSwitch modes[3];
    cModeFlags flags[3];
    char pad3C[0xE0 - 0x3C];
    float mFloorZ;
    float mWaterSurfaceZ;
    char padE8[0x170 - 0xE8];
    cCollisionFace mWaterPoly;
    char pad1E0[0x2D0 - 0x1E0];
    float prevTimeStep;
    char pad2D4[0x2E0 - 0x2D4];
    cPointMass pointMass;
    V centerOfMassOffset;
    float collisionSphereRadius;
    float targetCollisionSphereRadius;
    char pad378[0x380 - 0x378];
    V collisionSphereOffsetFromCenterOfMass;
    char pad390[0x3D1 - 0x390];
    char auxProbe;
    char pad3D2[0x9D0 - 0x3D2];
    V jumpInitVelocity;

    /* one extra level: the bone matrix temp lands in retail's deepest slot */
    V* BonePos1() { return BonePos2(); }
    V* BonePos2() { return func_00133EC0(&cSkeleton_GetBoneToWorldMatrix(skeleton, 0)); }
    V GetSphereCenter()
    {
        if (hasGoneThroughFirstPassOfNextFrame)
            return cVector_opAdd(Physical_GetPositionPtr(&pointMass), &collisionSphereOffsetFromCenterOfMass);
        return cVector_opAdd(BonePos1(), &collisionSphereOffsetFromCenterOfMass);
    }
    bool IsWaterDetected() const { return mWaterSurfaceZ != g_NegFltMax; }
    const cCollisionFace* GetWaterPoly() const { return IsWaterDetected() ? &mWaterPoly : 0; }
    bool IsInWater() const { return IsWaterDetected() && GetWaterPoly()->unitNormal.z > 0.974f; }
};

extern "C" void cHumanCollisionRoutine_NextFrame(cHumanCollisionRoutine* self, float timeStep, cSystem& eventReceiver, const cArray& faceList)
{
    float oneOverTimeStep = 1.0f / timeStep;
    float prevWaterSurfaceZ = self->IsInWater() ? self->mWaterSurfaceZ : -3.40282347e+38f;
    float radiusChange;
    V deltaPosFromTransportMovement[3];
    V velocityFromTransportMovement[3];
    cQuatVec deltaTransformFromTransportMovement[3];
    if (self->reset)
        cHumanCollisionRoutine_InitializePosition(self);
    Physical_CopyModeRecord(&self->modes[0], &self->modes[1]);
    Physical_CopyModeRecord(&self->modes[1], &self->modes[2]);
    self->flags[0] = self->flags[1];
    self->flags[1] = self->flags[2];
    radiusChange = Min(timeStep, self->targetCollisionSphereRadius - self->collisionSphereRadius);
    self->collisionSphereRadius += radiusChange;
    if (!self->jumpInitVelocity.IsZero()) {
        self->pointMass.ResetMotion();
        self->pointMass.AddForce(ImpulseToForce(self->jumpInitVelocity * self->pointMass.mass, timeStep));
        self->pointMass.Integrate(timeStep, self->prevTimeStep);
    } else {
        self->pointMass.IntegrateLimited(timeStep, self->prevTimeStep);
    }
    self->pointMass.force.Zero();
    cHumanCollisionRoutine_UpdateClimbingEdge(self, eventReceiver, faceList);
    cHumanCollisionRoutine_Transport_StartOfFrameUpdate(self, deltaPosFromTransportMovement, velocityFromTransportMovement, deltaTransformFromTransportMovement, oneOverTimeStep);
    switch (self->modes[1].a) {
    case 0: case 12: case 5: case 9: case 10: case 11:
        ActorPhys_RunResponse(self, eventReceiver, timeStep, oneOverTimeStep, faceList, deltaPosFromTransportMovement, velocityFromTransportMovement);
        break;
    }
    cHumanCollisionRoutine_Transport_EndOfFrameUpdate(self);
    self->jumpInitVelocity.Zero();
    void* found = RootCollection_FindByKey(self->animationSystem->root, D_004A03D0);
    ActorPhys_AuxiliaryProbe(&self->auxProbe, faceList, &self->GetSphereCenter(), found, self->mFloorZ);
    cHumanCollisionRoutine_HandleWaterCollisionIfDetected(self, prevWaterSurfaceZ);
    ((V*)((char*)self + 0x1E0))->Zero();
    self->prevTimeStep = timeStep;
    if (!self->hasGoneThroughFirstPassOfNextFrame)
        self->hasGoneThroughFirstPassOfNextFrame = 1;
    if (self->reset)
        self->reset = 0;
}
