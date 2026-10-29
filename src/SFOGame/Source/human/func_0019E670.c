#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off

typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { int id; void* a; } Pair_L;
typedef struct { unsigned char kind; char pad[3]; Pair_L pairs[7]; char tail[0x10]; } X_L;
typedef struct { float x, y, z, w; } Rate_L;
typedef struct { void* lib; char pad4[0x30]; } Sys_L;
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { char pad[0x18]; } Anm_L;
typedef struct { char pad[0xDC]; unsigned char bDC; } Phys_L;

struct Ctl_L {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB();
    char pad4[0x110];
    int f114;
};
typedef struct {
    char pad0[0x58];
    Ctl_L* ctl; char pad5C[0x2EC0 - 0x5C];
    Sys_L sys; char pad2EF4_[0x320C - 0x2EC0 - sizeof(Sys_L)];
    char prio[4]; int f3210; char pad3214[0x3310 - 0x3214];
    Phys_L* s3310;
} Act_L;

extern "C" {
Anm_L* cSkaAnimationSet_GetNode_cString16NR(void* lib, Name_L* n);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void cSkaAnimEndedMessage_ctor_void(Ev_L* e);
void cSkaRequestStream_AddRequest(void* ctl, void* id, signed char mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void cSkaAnimEndedMessage_dtor(void* p, int f);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void* func_0018C6A0(Sys_L* s);
void nSka_GetPlaybackGroupId(Y_L* y, Anm_L* m);
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(Act_L* a, Name_L* n, float* t, int x, int y);
}

static inline void QZero_L(void* dd) { int n = 3; void* d = dd;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
static const float kZero_L = 0.0f;
static const float kZero2_L = 0.0f;
static inline float Zf() { return 0.0f; }
static inline float Recip_L(float v) { float r; if (v != kZero_L) r = 1.0f / v; else { r = 3.4028235e38f; asm { .set reorder } } return r; }
static inline float RecipB_L(float v) { float r; float z; __asm__ volatile("mtc1 $0, %0" : "=f"(z)); if (z != v) r = 1.0f / v; else { r = 3.4028235e38f; asm { .set reorder } } return r; }
static inline X_L* XInit_L(X_L* x) { X_L* px = x; px->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(px->pairs); cArray_cTimedEvent_ctor_void(px->tail); return px; }
static inline X_L* XSetR2_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* p = &x->pairs[i]; p->id = id; p->a = a; x->kind = k; return x; }
static inline X_L* XSetR_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* p = &x->pairs[i]; p->id = id; p->a = a; x->kind = k; return x; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
static inline void Prio_L(char* p, signed char k, int v)
{
    char* q = p;
    unsigned char on;
    on = AnimPriority_Helper3(q + 0xC, k);
    AnimPriority_Helper2(q + 4, k, v);
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}
static inline bool FTest_L(int w, int n) { return ((w >> n) & 1) != 0; }
static inline bool Landed_L(Act_L* a) { bool r = 0; if (a->s3310 && a->s3310->bDC) r = 1; return r; }
static inline bool CtlA_L(Act_L* a) { bool r = 0; if (a->ctl && a->ctl->IsA()) r = 1; return r; }
static inline bool CtlB_L(Act_L* a) { bool r = 0; if (a->ctl && a->ctl->IsB()) r = 1; return r; }

static inline void Mot_L(Sys_L* sys, Anm_L* m, int mode, Rate_L* r, X_L* px)
{
    Ev_L e1;
    Ev_L e2;
    Y_L y;
    void* ctl;
    cSkaAnimEndedMessage_ctor_void(&e1);
    cSkaAnimEndedMessage_ctor_void(&e2);
    ctl = func_0018C6A0(sys);
    nSka_GetPlaybackGroupId(&y, m);
    cSkaRequestStream_AddRequest(ctl, m, mode, r, &y, &e1, &e2, px, -1.0f, 0.0f);
    cSkaAnimEndedMessage_dtor(&e2, -1);
    cSkaAnimEndedMessage_dtor(&e1, -1);
}
static inline void Mot2_L(Sys_L* sys, Anm_L* m, int mode, Rate_L* r, X_L* px) { if (m) Mot_L(sys, m, mode, r, px); }
static inline void RateSet_L(Rate_L* r, float d) { r->x = d; r->y = d; r->z = Recip_L(d); r->w = RecipB_L(d); }
extern "C" void Actor_LandDead(Act_L* a, int force)
{
    if (Landed_L(a) && !force)
        return;
    if (FTest_L(a->f3210, 29) || FTest_L(a->f3210, 30)) {
        Name_L n;
        float t;
        Rate_L r;
        X_L x;
        X_L* px;
        Sys_L* sys;
        Anm_L* m;
        Prio_L(a->prio, 0x1D, 0);
        Prio_L(a->prio, 0x1E, 0);
        QZero_L(&n);
        cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(a, &n, &t, 0, 0);
        XInit_L(&x);
        px = XSetR_L(XSetR_L(XSetR_L(&x, 4, 0x92, a, 1), 5, 0x92, a, 1), 6, 0x92, a, 1);
        RateSet_L(&r, t);
        sys = &a->sys;
        m = cSkaAnimationSet_GetNode_cString16NR(sys->lib, &n);
        if (m) Mot_L(sys, m, 1, &r, px);
        XDtor_L(&x);
        if (CtlA_L(a) || CtlB_L(a))
            a->ctl->f114 = 0;
    }
}
