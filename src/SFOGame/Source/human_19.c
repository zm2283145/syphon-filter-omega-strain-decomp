/*
 * SFOGame/Source/human: 2 files, 001A1C80-001A2470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A1C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(12)
#include "types.h"
#include "alloc_guard.h"

struct cString48 {
    char charArray[48];
    void Init(const char* s)
    {
        unsigned char ended = 0;
        int i;
        for (i = 0; i < 47; i++) {
            char c;
            if (s[i] == 0)
                ended = 1;
            if (ended)
                c = 0;
            else
                c = s[i];
            charArray[i] = c;
        }
        charArray[i] = 0;
    }
} __attribute__((aligned(16)));
struct tEvPair { int id; void* obj; };
extern "C" void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
extern "C" void cArray_cTimedEvent_ctor_void(void* p);
struct cAnimCheckpoints { unsigned char kind; char pad[3]; tEvPair pairs[7]; char tail[0x10];
    cAnimCheckpoints() { cAnimCheckpoints* t = this; t->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(t->pairs); cArray_cTimedEvent_ctor_void(t->tail); }
    void Add(int i, int id, void* o) { tEvPair* p = &pairs[i]; p->id = id; p->obj = o; kind = 1; }
};
struct cCrossFade { float a, b, c, d; };
struct cPlaybackGroupId { int a, b; };
struct cSkaSys { char* lib; };
struct cPrioBits { char pad[0x28]; int top; int bits[1]; };
struct cTimeCb { int duration; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; struct cHuman* human; unsigned char type; };
struct cHuman {
    char pad0[0x2EC0];
    cSkaSys sys; char pad2EC4[0x320C - 0x2EC4];
    int prio; int f3210; char pad3214[0x3248 - 0x3214];
    int f3248; char pad324C[0x3310 - 0x324C];
    cPrioBits* prioBits;
};
struct cAnimEndedMsg { char d[0x40]; };

extern "C" {
extern char D_0049DD30[]; extern char D_0049DCF0[]; extern char D_0049D910[]; extern char D_0049D8D0[];
extern char D_004DAE30[]; extern char D_004D9DE0[]; extern char D_004DA870[]; extern char g_Game[];
extern float g_DefaultMotionTransition;
void Actor_ClearAction(cHuman* a, signed char k);
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
int cSkaAnimationSet_GetNode_cString16NR(char* lib, cString48* n);
void cSkaAnimEndedMessage_ctor_void(void* e);
void cSkaAnimEndedMessage_dtor(void* p, int f);
void* func_0018C6A0(cSkaSys* s);
cPlaybackGroupId nSka_GetPlaybackGroupId(int m);
void cSkaRequestStream_AddRequest(void* s, int node, int mode, cCrossFade* cf, const cPlaybackGroupId& pg, const cAnimEndedMsg& m1, const cAnimEndedMsg& m2, cAnimCheckpoints* x, float f0, float f1);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void);
void cSndFx_ctor_int_charP_cGOBJP_int(void* s, int a, char* name, void* g, int b);
void cPlaySoundMsg_ctor_cSndFxR(void* m, void* s, void* g);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* t, int f);
void cFileMan_dtor(void* p, int f);
void cMessage_dtor(void* m, int f);
int Libc_Rand(void);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nCallback_SetCallback(void* p);
}
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct cAnimEndedMsgT : cAnimEndedMsg { cAnimEndedMsgT() { cSkaAnimEndedMessage_ctor_void(this); } __declspec(weak) __declspec(DROPDTOR) ~cAnimEndedMsgT() { cSkaAnimEndedMessage_dtor(this, -1); } };
static inline float Inv(float t) { return t != 0.0f ? 1.0f / t : 3.4028235e38f; }
static inline void Prio(char* p0, int k, int v)
{
    char* p = p0;
    unsigned char on = AnimPriority_Helper3(p + 0xC, k);
    AnimPriority_Helper2(p + 4, k, v);
    AnimPriority_Helper1(p);
    AnimPriority_Helper0(p, k, on);
}
static inline void Play(cSkaSys* sys, int node, int mode, cCrossFade* cf, cAnimCheckpoints* cp)
{
    if (node) {
        cSkaRequestStream_AddRequest(func_0018C6A0(sys), node, mode, cf, nSka_GetPlaybackGroupId(node), cAnimEndedMsgT(), cAnimEndedMsgT(), cp, -1.0f, 0.0f);
    }
}
static inline unsigned char IsSet(int* b, int n) { return ((b[n / 32] >> (n & 31)) & 1) != 0; }
static inline void SetBit(cPrioBits* s, int n)
{
    int i;
    s->bits[0] |= 1 << n;
    for (i = 12; i >= 0 && !IsSet(s->bits, i); i--) {
    }
    if (!IsSet(s->bits, i)) s->top = -1; else s->top = i;
}
/* cvt.w.s+mfc1: a C (int) cast compiles to trunc.w.s */
static inline int F2I(float f) { int r; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }
static inline int RandN(int n) { int r = Libc_Rand(); return F2I((float)n * ((float)r / 2147483648.0f)); }
static inline int RandRange(int lo, int hi) { int n = hi - lo + 1; return lo + RandN(n); }

extern "C" void cHuman_GrabLedge(cHuman* self)
{
    float transitionTime;
    int callbackWaitDuration;
    cTimeCb* callback;
    /* Mode switch, emits nothing: retail GrabLedge (like cHuman_Land) is compiled in MW's less-optimised mode that
       any volatile asm in a function selects (un-strength-reduced name-copy loop, cAnimCheckpoints pointers
       recomputed instead of CSE'd into extra s-registers, unretargeted `b; nop` branches, RandRange's n kept
       as an int across Libc_Rand). A live volatile asm would add an instruction or pin the scheduling around
       the cvt.w.s, so it sits in a dead block. */
    if (0) { asm volatile { nop } }
    if ((self->f3210 >> 7) & 1) return;
    if ((self->f3210 >> 8) & 1) return;
    if ((self->f3210 >> 5) & 1) Actor_ClearAction(self, 5);
    Prio((char*)&self->prio, 7, 1);
    if (IsSet(&self->f3248, 10)) transitionTime = 0.25f; else transitionTime = 0.3f;
    {
        cString48 name;
        cCrossFade cf;
        cAnimCheckpoints cp;
        cAnimCheckpoints* pcp;
        cSkaSys* sys = &self->sys;
        cf.a = transitionTime;
        cf.b = transitionTime;
        cf.c = Inv(transitionTime);
        cf.d = Inv(transitionTime);
        cp.Add(0, 0x14, self);
        pcp = &cp;
        pcp->Add(1, 0x15, self);
        pcp->Add(3, 0x16, self);
        pcp->Add(5, 0x17, self);
        pcp->Add(6, 0x18, self);
        name.Init(D_0049DD30);
        int node = cSkaAnimationSet_GetNode_cString16NR(sys->lib, &name);
        Play(sys, node, 1, &cf, pcp);
        func_001BE5A0(cp.tail, 0);
        __destroy_array(cp.pairs, (void*)func_0018A210, 8, 7);
    }
    {
        cString48 name;
        cCrossFade cf;
        cAnimCheckpoints cp;
        cAnimCheckpoints* pcp;
        cSkaSys* sys = &self->sys;
        cf.a = g_DefaultMotionTransition;
        cf.b = g_DefaultMotionTransition;
        cf.c = Inv(g_DefaultMotionTransition);
        cf.d = Inv(g_DefaultMotionTransition);
        cp.Add(0, 0x19, self);
        pcp = &cp;
        pcp->Add(3, 0x1A, self);
        pcp->Add(5, 0x1B, self);
        pcp->Add(6, 0x1C, self);
        name.Init(D_0049DCF0);
        int node = cSkaAnimationSet_GetNode_cString16NR(sys->lib, &name);
        Play(sys, node, 0, &cf, pcp);
        func_001BE5A0(cp.tail, 0);
        __destroy_array(cp.pairs, (void*)func_0018A210, 8, 7);
    }
    if (self->prioBits) {
        SetBit(self->prioBits, 5);
        SetBit(self->prioBits, 1);
    }
    {
        char snd[0x190] __attribute__((aligned(16)));
        char msg[0x1C0] __attribute__((aligned(16)));
        cSndFx_ctor_int_charP_cGOBJP_int(snd, 1, D_0049D910, 0, 0);
        cPlaySoundMsg_ctor_cSndFxR(msg, snd, self);
        msg[0x20] = 1;
        QueueMessage_cMessageR_cSystemP_int(msg, g_Game, 1);
        *(void**)msg = D_004DAE30;
        cFileMan_dtor(msg + 0x114, -1);
        cFileMan_dtor(msg + 0x78, -1);
        cMessage_dtor(msg, 0);
        cFileMan_dtor(snd + 0xE4, -1);
        cFileMan_dtor(snd + 0x48, -1);
    }
    callbackWaitDuration = RandRange(20, 40);
    {
        AllocGuard guard;
        callback = (cTimeCb*)cMemMan_Allocate(0, 0x14, D_0049D8D0, 0x2349);
    }
    if (callback) {
        callback->vt = D_004D9DE0;
        callback->b4 = 1;
        callback->duration = callbackWaitDuration;
        callback->b5 = 0;
        callback->vt = D_004DA870;
        callback->human = self;
        callback->type = 1;
    }
    nCallback_SetCallback(callback);
}
static inline void merge_flush_func_001A1C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A1C80 */

/* merge_units: begin func_001A2470 */
#pragma push /* merge_units */
// cHuman::JumpLaunchApplyForce. Keys: ClampM zero-init+param copies (const order/mtc1 zero); rotate asm in nested RotIP inline kills dead addiu;
// `const cVector* t; (t = &T())->PlusD(Rotate(...))` makes this-vreg early (coloring a3) but def after asm; extra nop = 8-byte branch-target alignment.
#pragma cplusplus on
#pragma inline_depth(8)

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

struct cString48_001A2470 {
    char s[0x30];
    cString48_001A2470(const char* p) {
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
cSkaAnim* cSkaSystem_GetAnimation(void* sys, const cString48_001A2470& name);
void* cSkaParams_Skeleton(void* params);
void* cSkeleton_GetSkeletonData(void* skel);
cQuatVec cSkaAnim_GetFirstFrameRootTransform(cSkaAnim* a, void* skelData);
cVector nPhysics_CalculateInitialVelocityForTrajectory(const cVector& from, const cVector& to, float g, float arc, float ang, cVector* out);
extern float g_ThrowGravity;
extern char D_0049E1B0[];
}

struct cSkaSystem {
    char pad0[0x10];
    char mParams[4];
    cSkaAnim* GetAnimation(const cString48_001A2470& n) { return cSkaSystem_GetAnimation(this, n); }
    void* GetSkeletonData() { return cSkeleton_GetSkeletonData(cSkaParams_Skeleton(mParams)); }
};

static inline cQuatVec QW1(cSkaAnim* a, void* d) { return cQuatVec(cSkaAnim_GetFirstFrameRootTransform(a, d)); }
static inline cQuatVec QW2(cSkaAnim* a, void* d) { return QW1(a, d); }
static inline cQuatVec QW3(cSkaAnim* a, void* d) { return QW2(a, d); }
static inline cQuatVec QW4(cSkaAnim* a, void* d) { return QW3(a, d); }
static inline cQuatVec GetFirstFrameRootTransform(cSkaSystem* s, const cString48_001A2470& name) {
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

struct cHuman_001A2470 {
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

extern "C" void cHuman_JumpLaunchApplyForce(cHuman_001A2470* self, float f)
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
static inline void merge_flush_func_001A2470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A2470 */
