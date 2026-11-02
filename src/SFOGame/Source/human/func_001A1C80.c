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
