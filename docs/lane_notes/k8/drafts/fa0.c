#pragma cplusplus on
#include "types.h"

struct cVector { float x, y, z, w; } __attribute__((aligned(16)));
struct cVectorC { float x, y, z, w; cVectorC(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
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
struct cMat4 { cVector r[4]; const cVector& Row(int i) const { return r[i]; } };
struct cXformObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0x10 - 4]; cMat4 mat; unsigned char dirty;
    const cMat4& GetMatrix() { if (dirty) Update(); return mat; }
};
struct cPhysics { char pad[0x310]; cVector velocity; };
struct cMsg { void* vtable; char pad4[0x20]; int f24; unsigned char b28; char pad29[3]; int f2C; unsigned char b30; char pad31[3]; int f34; char pad38[8]; };
struct tEvPair { int id; void* obj; };
extern "C" void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
extern "C" void cArray_cTimedEvent_ctor_void(void* p);
struct cAnimCheckpoints { unsigned char kind; char pad[3]; tEvPair pairs[7]; char tail[0x10];
    cAnimCheckpoints() { cAnimCheckpoints* t = this; t->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(t->pairs); cArray_cTimedEvent_ctor_void(t->tail); }
    void Add(int i, int id, void* o) { tEvPair* p = &pairs[i]; p->id = id; p->obj = o; kind = 1; }
};
struct cCrossFade { float a, b, c, d; };
struct cHuman {
    char pad0[0x50]; cXformObj* xform; char pad54[0x2EC0 - 0x54];
    char* animSet; char pad2EC4[0x2EF4 - 0x2EC4];
    char reqStream[0x320C - 0x2EF4];
    int curState; int stateFlags; char pad3214[0x3248 - 0x3214];
    union { int moveFlags; struct { unsigned mf0 : 13; unsigned b13 : 1; unsigned mf14 : 18; } mb; }; char pad324C[0x3310 - 0x324C];
    cPhysics* physics;
};

extern "C" {
extern char D_00542B60[];
extern char D_004DA930[];
extern float g_DefaultMotionTransition;
extern char D_0049E180[];
extern char D_0049E190[];
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(void* it, void* arr, cString16N* key);
int** cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(void* it);
void cMessage_ctor_cMessageNameR(cMsg* m, void* name);
void cMessage_dtor(cMsg* m, int f);
void cSkaRequestStream_AddRequest(void* s, int id, int mode, cCrossFade* cf, void* pg, cMsg* m1, cMsg* m2, cAnimCheckpoints* x, float f0, float f1);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void);
}

static inline void Prio(char* p0, int k, int v)
{
    char* p = p0;
    unsigned char on = AnimPriority_Helper3(p + 0xC, k);
    AnimPriority_Helper2(p + 4, k, v);
    AnimPriority_Helper1(p);
    AnimPriority_Helper0(p, k, on);
}
static inline const cVector& Velocity(cHuman* h)
{
    if (h->physics)
        return h->physics->velocity;
    static cVectorC zero(0.0f, 0.0f, 0.0f, 0.0f);
    return *(const cVector*)&zero;
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

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct VQ { float x, y, z, w; VQ() {} VQ(const VQ& o) { VQ* d = this; Q16(d, &o); } VQ& operator=(const VQ& o) { VQ* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
static inline void NormV(VQ* v) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(v) : "memory"); }
static inline const VQ& FlatC(const VQ& v0) { VQ* v = (VQ*)&v0; v->z = 0.0f; return *v; }
static inline VQ Flat(const VQ& v) { VQ r = v; r.z = 0.0f; return r; }
static inline VQ FlatV(const VQ& s) { VQ r = s; VQ* p = &r; p->z = 0.0f; return *p; }
extern "C" void cHuman_Fall(cHuman* self)
{
    char* animationName;
    int* blend;
    int* st = &self->curState;
    if (self->curState == 0x1B || self->curState == 0x1F) {
        Prio((char*)&self->curState, 0x1D, 1);
        return;
    }
    if ((st[1] >> 10) & 1)
        return;
    static cString16N fall(D_0049E180);
    static cString16N grabLedgeFall(D_0049E180);
    static cString16N forwardFall(D_0049E190);
    static cString16N runningJumpFall(D_0049E180);
    VQ v2 = FlatC(VQ(*(const VQ*)&Velocity(self)));
    cXformObj* x = self->xform;
    VQ dir = FlatC(VQ(*(const VQ*)&x->GetMatrix().Row(1)));
    float dot;
    {
        int t;
        NormV(&dir);
        dot = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%3); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; mtsah $zero, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(dot), "=&r"(t) : "r"(&dir), "r"(&v2) : "memory");
    }
    float ten = 10.0f;
    float one = 1.0f;
    float lim = ten / one;
    if (!(dot <= lim)) {
        if (!((self->moveFlags >> 10) & 1) && !((self->moveFlags >> 11) & 1) && !((self->moveFlags >> 12) & 1))
            self->moveFlags = *(volatile int*)&self->moveFlags | 0x2000;
    }
    if ((self->moveFlags >> 11) & 1)
        animationName = fall.charArray;
    else if ((self->moveFlags >> 13) & 1)
        animationName = grabLedgeFall.charArray;
    else if ((self->moveFlags >> 12) & 1)
        animationName = forwardFall.charArray;
    else
        animationName = runningJumpFall.charArray;

    cCrossFade cf;
    cAnimCheckpoints cp;
    cp.Add(0, 0x21, self);
    cAnimCheckpoints* pcp = &cp;
    pcp->Add(3, 0x22, self);
    pcp->Add(5, 0x23, self);
    pcp->Add(6, 0x24, self);
    cf.a = g_DefaultMotionTransition;
    cf.b = g_DefaultMotionTransition;
    cf.c = Inv(g_DefaultMotionTransition);
    cf.d = Inv(g_DefaultMotionTransition);
    int it;
    cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(&it, self->animSet + 0x44, (cString16N*)animationName);
    blend = *cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(&it);
    char* ac = (char*)&self->animSet;
    cSkaRequestStream_AddRequest(ac + 0x34, blend[0], 1, &cf, blend + 1, MP(cMsgT()), MP(cMsgT()), pcp, -1.0f, 0.0f);
    func_001BE5A0(cp.tail, 0);
    __destroy_array(cp.pairs, (void*)func_0018A210, 8, 7);
}
