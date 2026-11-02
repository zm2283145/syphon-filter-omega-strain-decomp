/*
 * SFOGame/Source/humanCollision: 6 files, 001E9600-001E9980
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E9600 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { char pad[0x10]; __int128 q10; __int128 q20; __int128 q30; __int128 q40; __int128 q50; } P_9600;
void cPointMass_ClearPhysics(P_9600* p) {
    __int128* d; __int128* s; __int128 t; __int128* z;
    V4StoreZero(&p->q50);
    V4StoreZero(&p->q40);
    d = &p->q20; s = &p->q10; z = &p->q30;
    t = V4Load(s); V4Store(d, t);
    VZeroF(z);
}
static inline void merge_flush_func_001E9600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9600 */

/* merge_units: begin func_001E9630 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x10]; V4 pos; V4 p2; } PS;
static inline void Sub2_(V4* q, V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q)
    }
}
static inline void QCopy_(V4* pd, V4* ps) {
    /* lq into the dead source-pointer register (retail reuses it) */
    asm volatile {
        lq ps, 0(ps)
        sq ps, 0(pd)
    }
}
static inline void AddEq_(V4* x, V4* y) {
    V4* d = x; V4* e = x; V4* p = y;
    asm {
        lqc2 vf1, 0x0(e)
        lqc2 vf2, 0x0(p)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cPointMass_Teleport(PS* s, V4* t) {
    V4 u;
    V4 tmp;
    Sub2_(&tmp, t, &s->pos);
    QCopy_(&u, &tmp);
    AddEq_(&s->pos, &u);
    AddEq_(&s->p2, &u);
}
#pragma pop
static inline void merge_flush_func_001E9630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9630 */

/* merge_units: begin func_001E96A0 */
#pragma push /* merge_units */
typedef struct { char pad[0xB0]; int coll; } B5aOwner;
typedef struct { char pad[0xC]; B5aOwner* owner; char pad2[0xE4 - 0x10]; float z; } B5aObj;
extern float g_NegFltMax;
extern int D_004A03C8;
extern void* RootCollection_FindByKey(void* coll, void* key);
extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
extern float* cQuatVec_Translation(void* p);
float cHumanCollisionRoutine_GetWaterDepth(B5aObj* o) {
    float r;
    if (o->z != g_NegFltMax) {
        float* p = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RootCollection_FindByKey(&o->owner->coll, &D_004A03C8)));
        r = o->z - p[2];
    } else {
        r = 0.0f;
    }
    return r;
}
static inline void merge_flush_func_001E96A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E96A0 */

/* merge_units: begin func_001E9710 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct VC;
#if 0 /* merge_units */
extern "C" VC* cVector_ctor_cVectorR(VC* d, const VC* s);
#endif /* merge_units */
extern "C" void* cVector_ctor_cVectorR(void*, void*); /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((VC *)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

struct VC {
    float x, y, z, w;
    VC(const VC& o) { cVector_ctor_cVectorR(this, &o); }
} __attribute__((aligned(16)));
struct Mtx;
struct Node;
struct Obj8 { char pad[0x14]; unsigned char m14; char pad2[3]; char skel[0x10]; Node* m28; };
struct Self { char pad[8]; Obj8* m8; char pad2[0xE8 - 0xC]; unsigned char mE8; char pad3[7]; char plane[0x10]; };
extern "C" {
void* cArray_cBone_opIndex_int(void*, long);
void* cBone_Xform(void*);
VC* cXform_GetTranslation(void*);
Mtx* cXform_GetMatrix(Node*);
VC cVector_GetTransformed(VC* v, Mtx* m);
float cPlane_C(void*);
float Plane_HeightAt(void*, V*);
V* cVector_ctor_float_float_float_float(V* o, float x, float y, float z, float w);
}
static inline V Unit() { V l0; V* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
static inline long NodeId(int m) { signed char n; if (m == 1) n = 7; else n = 11; return n; }
static inline float H2(void* pl, float x, float y) { V t; return Plane_HeightAt(pl, cVector_ctor_float_float_float_float(&t, x, y, 0.0f, 1.0f)); }
static inline float H1(void* pl, float x, float y) { return -H2(pl, x, y); }
static inline VC GetPos(Obj8* o, long n)
{
    if (o->m14) return cVector_GetTransformed(cXform_GetTranslation(cBone_Xform(cArray_cBone_opIndex_int(o->skel, n))), cXform_GetMatrix(o->m28));
    return *cXform_GetTranslation(o->m28);
}
extern "C" V cHumanCollisionRoutine_GetFloorContactPoint(Self* self, bool* hit, int mode, float thresh)
{
    V r = Unit();
    int m;
    *hit = 0;
    if (self->mE8 && (m = (unsigned char)mode)) {
        long n = NodeId(m);
        Obj8* o = self->m8;
        VC pos = GetPos(o, n);
        float px;
        float py;
        py = pos.y;
        px = pos.x;
        float z = cPlane_C(self->plane) != 0.0f ? H1(self->plane, px, py) / cPlane_C(self->plane) : 0.0f;
        r = V(px, py, z, 1.0f);
        if (pos.z - r.z < thresh) *hit = 1;
    }
    return r;
}
#undef cVector_ctor_cVectorR /* merge_units */
static inline void merge_flush_func_001E9710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9710 */

/* merge_units: begin func_001E98F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x38]; float level; } W_98F0;
typedef struct { int pad0; int id; char pad8[0xE4 - 8]; float depth; char padE8[0x170 - 0xE8]; W_98F0 water; } A_98F0;
int cWaterFx_RemoveBody(int, int);
extern int D_004FFC34;
/* drop the water effect when the actor is in water deeper than 0.974 */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void cHumanCollisionRoutine_HandleHumanDeactivation(A_98F0* a)
{
    unsigned char r = 0;
    {
        float k = g_NegFltMax;
        float d = a->depth;
        if (d != g_NegFltMax) {
            W_98F0* w = (d != k) ? &a->water : 0;
            if (!(w->level <= 0.974f)) r = 1;
        }
    }
    if (r) cWaterFx_RemoveBody(D_004FFC34, a->id);
}
#pragma pop
static inline void merge_flush_func_001E98F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E98F0 */

/* merge_units: begin func_001E9980 */
#pragma push /* merge_units */
/* 001E9980 cHumanCollisionRoutine::NextFrame(float, cSystem&, const cArray<cCollisionFace>&, const cCollisionModelList*)
 * (humanCollision.cc), rebuilt from the prototype DWARF/.line data. */
#pragma cplusplus on
#pragma inline_depth(8)

struct V_001E9980 {
    float x, y, z, w;
    V_001E9980() {}
    /* 128-bit lq/sq quadword copy: MW splits a C struct copy into words */
    V_001E9980(const V_001E9980& o) { V_001E9980* pd = this; const V_001E9980* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V_001E9980& operator=(const V_001E9980& o) { V_001E9980* pd = this; const V_001E9980* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
    unsigned char IsZero() const;
    /* 128-bit sq of $zero: MW zeroes a struct word by word */
    void Zero() { V_001E9980* p = this; asm volatile { sq zero, 0(p) } }
} __attribute__((aligned(16)));
struct M { float m[4][4]; } __attribute__((aligned(16)));

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void AddM(V_001E9980* d, const V_001E9980* p, const V_001E9980* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void MulT(V_001E9980* d, const V_001E9980* p, float s) { __int128 t = 0; asm volatile { .set noreorder; lqc2 vf1, 0(p); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(d); .set reorder } }
/* VU0 all-components-zero test via the MAC status flags (vi17), not expressible in C */
inline unsigned char V_001E9980::IsZero() const
{
    int k, f, r;
    const V_001E9980* v = this;
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
static inline V_001E9980 operator*(const V_001E9980& v, float s) { V_001E9980 r; MulT(&r, &v, s); return r; }
static inline V_001E9980& operator+=(V_001E9980& a, const V_001E9980& b) { AddM(&a, &a, &b); return a; }

extern "C" {
V_001E9980 cVector_opSub(const V_001E9980* a, const V_001E9980* b);
V_001E9980 cVector_opMul(const V_001E9980* a, float s);
V_001E9980 cVector_opAdd(const V_001E9980* a, const V_001E9980* b);
V_001E9980 opMul(float s, const V_001E9980* v);
V_001E9980* cVector_opAssign(V_001E9980* d, const V_001E9980* s);
void cVector_WSet1(V_001E9980* v);
V_001E9980* cVector_WSet0(V_001E9980* v);
#if 0 /* merge_units */
V_001E9980* cVector_ctor_cVectorR(V_001E9980* d, const V_001E9980* s);
#endif /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) ((V_001E9980 *)cVector_ctor_cVectorR((void *)(a0), (void *)(a1))) /* merge_units */

unsigned char cVector_IsZeroXYZ(const V_001E9980* v);
V_001E9980 cVector_GetNormalized_floatR(const V_001E9980* v, float* len);
extern char D_004A03D0[];
}

static inline V_001E9980 ImpulseToForce(V_001E9980 impulse, float timeStep) { const V_001E9980* pv = &impulse; return *pv * (1.0f / timeStep); }
struct cCollisionFace { V_001E9980 vertices[3]; V_001E9980 unitNormal; char pad40[0x70 - 0x40]; };
struct cPointMass {
    float mass;
    float invMass;
    char pad8[0x10 - 8];
    V_001E9980 pos;
    V_001E9980 prevPos;
    V_001E9980 vel;
    V_001E9980 accel;
    V_001E9980 force;
    char pad60[0x80 - 0x60];
    void ResetMotion() { force.Zero(); accel.Zero(); prevPos = pos; vel.Zero(); }
    void AddForce(V_001E9980 f) { force += f; }
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
        V_001E9980 newPos = cVector_opAdd(&cVector_opAdd(&pos, &cVector_opMul(&cVector_opSub(&pos, &prevPos), ratio)), &cVector_opMul(&force, invMass * ts2));
        cVector_opAssign(&prevPos, &pos);
        cVector_opAssign(&pos, &newPos);
        cVector_WSet1(&pos);
        V_001E9980 oldVel;
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
        V_001E9980 newPos = cVector_opAdd(&cVector_opAdd(&pos, &cVector_opMul(&cVector_opSub(&pos, &prevPos), ratio)), &cVector_opMul(&force, invMass * ts2));
        cVector_opAssign(&prevPos, &pos);
        cVector_opAssign(&pos, &newPos);
        cVector_WSet1(&pos);
        V_001E9980 newVel = cVector_opMul(&cVector_opSub(&pos, &prevPos), 1.0f / timeStep);
        V_001E9980 acc = cVector_opMul(&cVector_opSub(&newVel, &vel), 1.0f / timeStep);
        if (!cVector_IsZeroXYZ(&acc)) {
            float len;
            V_001E9980 dir = cVector_GetNormalized_floatR(&acc, &len);
            if (len > 900.0f) {
                V_001E9980 maxAccel = opMul(900.0f, &dir);
                V_001E9980 clampedVel = cVector_opAdd(&vel, &cVector_opMul(&maxAccel, timeStep));
                V_001E9980 delta;
                cVector_ctor_cVectorR(&delta, cVector_WSet0(&cVector_opMul(&clampedVel, timeStep)));
                cVector_opAssign(&prevPos, &cVector_opSub(&pos, &delta));
            }
        }
        V_001E9980 oldVel;
        cVector_ctor_cVectorR(&oldVel, &vel);
        cVector_opAssign(&vel, &cVector_opMul(&cVector_opSub(&pos, &prevPos), 1.0f / timeStep));
        cVector_opAssign(&accel, &cVector_opMul(&cVector_opSub(&vel, &oldVel), 1.0f / timeStep));
    }
};
struct cHumanCollisionRoutine;
struct cSystem;
struct cArray;
struct cQuatVec { V_001E9980 rot, trans; };
extern "C" {
void cHumanCollisionRoutine_InitializePosition(cHumanCollisionRoutine*);
void Physical_CopyModeRecord(void* d, const void* s);
void cHumanCollisionRoutine_UpdateClimbingEdge(cHumanCollisionRoutine*, cSystem&, const cArray&);
void cHumanCollisionRoutine_Transport_StartOfFrameUpdate(cHumanCollisionRoutine*, V_001E9980*, V_001E9980*, cQuatVec*, float);
void ActorPhys_RunResponse(cHumanCollisionRoutine*, cSystem&, float, float, const cArray&, const V_001E9980*, const V_001E9980*);
void cHumanCollisionRoutine_Transport_EndOfFrameUpdate(cHumanCollisionRoutine*);
#if 0 /* merge_units */
void* RootCollection_FindByKey(void*, void*);
#endif /* merge_units */
#define RootCollection_FindByKey(a0, a1) (RootCollection_FindByKey((a0), (a1))) /* merge_units */

V_001E9980* Physical_GetPositionPtr(cPointMass*);
M cSkeleton_GetBoneToWorldMatrix(void*, int);
V_001E9980* func_00133EC0(M*);
void ActorPhys_AuxiliaryProbe(void*, const cArray&, const V_001E9980*, void*, float);
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
    V_001E9980 centerOfMassOffset;
    float collisionSphereRadius;
    float targetCollisionSphereRadius;
    char pad378[0x380 - 0x378];
    V_001E9980 collisionSphereOffsetFromCenterOfMass;
    char pad390[0x3D1 - 0x390];
    char auxProbe;
    char pad3D2[0x9D0 - 0x3D2];
    V_001E9980 jumpInitVelocity;

    /* one extra level: the bone matrix temp lands in retail's deepest slot */
    V_001E9980* BonePos1() { return BonePos2(); }
    V_001E9980* BonePos2() { return func_00133EC0(&cSkeleton_GetBoneToWorldMatrix(skeleton, 0)); }
    V_001E9980 GetSphereCenter()
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
    V_001E9980 deltaPosFromTransportMovement[3];
    V_001E9980 velocityFromTransportMovement[3];
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
    ((V_001E9980*)((char*)self + 0x1E0))->Zero();
    self->prevTimeStep = timeStep;
    if (!self->hasGoneThroughFirstPassOfNextFrame)
        self->hasGoneThroughFirstPassOfNextFrame = 1;
    if (self->reset)
        self->reset = 0;
}
#undef cVector_ctor_cVectorR /* merge_units */
#undef RootCollection_FindByKey /* merge_units */
static inline void merge_flush_func_001E9980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9980 */
