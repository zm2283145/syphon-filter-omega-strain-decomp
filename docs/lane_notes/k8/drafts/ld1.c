#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct cString16N {
    char charArray[32];
    cString16N(const char* s)
    {
        unsigned char ended = 0;
        int i;
        for (i = 0; i < 31; i++) {
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
struct cMsg { void* vtable; char pad4[0x20]; int f24; unsigned char b28; char pad29[3]; int f2C; unsigned char b30; char pad31[3]; int f34; char pad38[8]; };
struct tEvPair { int id; void* obj; };
extern "C" void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
extern "C" void cArray_cTimedEvent_ctor_void(void* p);
struct cAnimCheckpoints { unsigned char kind; char pad[3]; tEvPair pairs[7]; char tail[0x10];
    cAnimCheckpoints() { cAnimCheckpoints* t = this; t->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(t->pairs); cArray_cTimedEvent_ctor_void(t->tail); }
    void Add(int i, int id, void* o) { tEvPair* p = &pairs[i]; p->id = id; p->obj = o; kind = 1; }
};
struct cCrossFade { float a, b, c, d; };
struct cPhysicsX { char pad[0x11]; unsigned char b11; char pad12[0x9C0 - 0x12]; unsigned char b9C0; };
struct cTimeCb { int duration; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; struct cHuman* human; unsigned char type; };
struct cHuman {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual unsigned char GetHealthState();
    char pad4[0x2EC0 - 4];
    char* animSet; char pad2EC4[0x30A0 - 0x2EC4];
    float f30A0; char pad30A4[0x3210 - 0x30A4];
    int f3210; char pad3214[0x3248 - 0x3214];
    int f3248; char pad324C[0x326C - 0x324C];
    int* blend326C; char pad3270[0x3310 - 0x3270];
    cPhysicsX* physics;
    void Land(unsigned char playLandAnimation);
};

extern "C" {
extern char D_00542B60[];
extern char D_004DA930[];
extern char D_004D9DE0[];
extern char D_004DA870[];
extern char D_0049D8D0[];
extern float g_DefaultMotionTransition;
extern char D_0049E148[];
extern char D_0049E160[];
void cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(void* it, void* arr, cString16N* key);
int** cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(void* it);
void cMessage_ctor_cMessageNameR(cMsg* m, void* name);
void cMessage_dtor(cMsg* m, int f);
void cSkaRequestStream_AddRequest(void* s, int id, int mode, cCrossFade* cf, void* pg, cMsg* m1, cMsg* m2, cAnimCheckpoints* x, float f0, float f1);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void);
void cSkaAnimCheckpoints_ctor_void(void* p);
void cSkaAnimCheckpoints_dtor(void* p, int f);
float cSkaAnimationSet_DefaultCrossFadeDuration(void* m);
void* cSkaCrossFadeDuration_ctor_float(void* p, float f);
void cSkaSystem_PlayAnimation(void* sys, int* blend, int instr, void* cfd, void* cp);
void cHuman_HandleFootstepEvent(cHuman* h, int foot, int force);
int Libc_Rand(void);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nCallback_SetCallback(void* p);
}

static inline void MsgInit(cMsg* m0)
{
    cMsg* m = m0;
    cMessage_ctor_cMessageNameR(m, D_00542B60);
    m->vtable = D_004DA930;
    m->f24 = 0; m->b28 = 0; m->f2C = 0; m->b30 = 0; m->f34 = 0;
}
struct cMsgT : cMsg { cMsgT() { MsgInit(this); } ~cMsgT() { vtable = D_004DA930; cMessage_dtor(this, 0); } };
static inline cMsg* MP(const cMsgT& m) { return (cMsg*)&m; }
static inline float Inv(float t) { return t != 0.0f ? 1.0f / t : 3.4028235e38f; }
static inline int RandN(int n) { return (int)((float)n * ((float)Libc_Rand() / 2147483648.0f)); }
struct cCp3 { char d[0x50]; };
struct cCfd { float a, b, c, d; };

static inline unsigned char IsDeadOrDying(cHuman* h)
{
    unsigned char s = h->GetHealthState();
    return s == 3 || s == 2;
}

extern "C" void cHuman_Land(cHuman* self, unsigned char playLandAnimation)
{
    char* animationName;
    float transitionTime;
    int callbackWaitDuration;
    cTimeCb* callback;
    if (IsDeadOrDying(self))
        return;
    if (playLandAnimation) {
        if (!((self->f3210 >> 11) & 1)) {
            static cString16N land(D_0049E148);
            static cString16N forwardFallLand(D_0049E148);
            static cString16N runningJumpLand(D_0049E148);
            static cString16N swimLand(D_0049E160);
            int instr;
            float t2 = g_DefaultMotionTransition;
            unsigned char inWater = self->f30A0 == 0.0f;
            if (inWater) {
                animationName = swimLand.charArray;
                transitionTime = 0.35f;
                instr = 0;
                t2 = transitionTime;
            } else if ((self->f3248 >> 11) & 1) {
                animationName = land.charArray;
                transitionTime = 0.2f;
                instr = 0;
            } else if ((self->f3248 >> 13) & 1) {
                animationName = forwardFallLand.charArray;
                transitionTime = 0.2f;
                instr = 0;
            } else {
                animationName = runningJumpLand.charArray;
                transitionTime = 0.2f;
                instr = 0;
            }
            {
                cCrossFade cf;
                cAnimCheckpoints cp;
                cp.Add(0, 0x25, self);
                cAnimCheckpoints* pcp = &cp;
                pcp->Add(3, 0x26, self);
                pcp->Add(5, 0x27, self);
                pcp->Add(6, 0x28, self);
                cf.a = transitionTime;
                cf.b = transitionTime;
                cf.c = Inv(transitionTime);
                cf.d = Inv(transitionTime);
                int it;
                cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(&it, self->animSet + 0x44, (cString16N*)animationName);
                int* blend = *cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(&it);
                char* ac = (char*)&self->animSet;
                cSkaRequestStream_AddRequest(ac + 0x34, blend[0], 1, &cf, blend + 1, MP(cMsgT()), MP(cMsgT()), pcp, -1.0f, 0.0f);
                func_001BE5A0(cp.tail, 0);
                __destroy_array(cp.pairs, (void*)func_0018A210, 8, 7);
            }
            {
                cCrossFade cf;
                cAnimCheckpoints cp;
                cf.a = t2;
                cf.b = t2;
                cf.c = Inv(t2);
                cf.d = Inv(t2);
                int* blend = self->blend326C;
                char* ac = (char*)&self->animSet;
                cSkaRequestStream_AddRequest(ac + 0x34, blend[0], instr, &cf, blend + 1, MP(cMsgT()), MP(cMsgT()), &cp, -1.0f, 0.0f);
                func_001BE5A0(cp.tail, 0);
                __destroy_array(cp.pairs, (void*)func_0018A210, 8, 7);
            }
        }
    } else {
        int* blend = self->blend326C;
        cCp3 cp;
        cCfd cfd;
        cSkaAnimCheckpoints_ctor_void(&cp);
        char** as = &self->animSet;
        cSkaSystem_PlayAnimation(as, blend, 3, cSkaCrossFadeDuration_ctor_float(&cfd, cSkaAnimationSet_DefaultCrossFadeDuration(*as)), &cp);
        cSkaAnimCheckpoints_dtor(&cp, -1);
        if (self->physics)
            self->physics->b9C0 = 0;
        if (self->physics)
            self->physics->b11 = 1;
    }
    cHuman_HandleFootstepEvent(self, 2, 1);
    callbackWaitDuration = RandN(31) + 70;
    {
        AllocGuard guard;
        callback = (cTimeCb*)cMemMan_Allocate(0, 0x14, D_0049D8D0, 0x2433);
    }
    if (callback) {
        callback->vt = D_004D9DE0;
        callback->b4 = 1;
        callback->duration = callbackWaitDuration;
        callback->b5 = 0;
        callback->vt = D_004DA870;
        callback->human = self;
        callback->type = 0;
    }
    nCallback_SetCallback(callback);
}
