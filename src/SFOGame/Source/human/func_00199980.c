#pragma cplusplus on
#pragma always_inline on

typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { int id; void* a; } Pair_L;
typedef struct { unsigned char kind; char pad[3]; Pair_L pairs[7]; char tail[0x10]; } X_L; /* cSkaAnimCheckpoints */
typedef struct { float x, y, z, w; } Rate_L; /* cSkaCrossFadeDuration */
typedef struct { void* model; char pad4; unsigned char b5; char pad6[2]; float v[4]; } Anim_L;
typedef struct { void* lib; char pad4[0xC]; char f10[0x24]; Anim_L anim; } Sys_L;
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { char pad[0x24]; char* f24; } Anm_L;
typedef struct {
    void* vtable; int f04; int f08; int f0C; int f10; int f14; int f18; int f1C; signed char f20; char pad21[3];
    int f24; unsigned char f28; char pad29[3]; int f2C; unsigned char f30; char pad31[3]; float f34; char pad38[8];
} AEv_L; /* cSkaAnimEventMessage-like, 0x40 bytes */

extern "C" {
extern char D_00542B60[]; extern char D_004DA930[];
extern float g_DefaultMotionTransition;
void cMessage_ctor_cMessageNameR(void* m, void* t);
void cMessage_dtor(void* m, int f);
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
}

#define NAME_COPY(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        for (; ckc_i < 0x2F; ckc_i++) { \
            if ((src)[ckc_i] == 0) ckc_end = 1; \
            if (ckc_end) ckc_c = 0; else ckc_c = (src)[ckc_i]; \
            (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }


#define STATIC_NAME(guard, dst, src) \
    if (!guard) { NAME_COPY((dst).c, src) guard = 1; }

static inline float Recip_L(float v) { return v != 0.0f ? 1.0f / v : 3.4028235e38f; }

static inline X_L* XInit_L(X_L* x) { X_L* px = x; px->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(px->pairs); cArray_cTimedEvent_ctor_void(px->tail); return px; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
static inline void RateDef_L(Rate_L* r)
{
    float d = g_DefaultMotionTransition;
    r->x = d;
    r->y = d;
    r->z = Recip_L(d);
    r->w = Recip_L(g_DefaultMotionTransition);
}
static inline void Prio_L(char* p, signed char k, int v)
{
    char* q = p;
    unsigned char on;
    on = AnimPriority_Helper3(q + 0xC, k);
    AnimPriority_Helper2(q + 4, k, v);
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}
static inline void AEvInit_L(AEv_L* e)
{
    cMessage_ctor_cMessageNameR(e, D_00542B60);
    e->vtable = D_004DA930;
    e->f24 = 0;
    e->f28 = 0;
    e->f2C = 0;
    e->f30 = 0;
    e->f34 = 0.0f;
}

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
static inline void* YOf_L(int* p) { return p + 1; }


typedef struct {
    char pad0[0x2EC0];
    Sys_L sys; char pad2EF4_[0x320C - 0x2EC0 - sizeof(Sys_L)];
    int f320C; char pad3210[0x326C - 0x3210];
    int* f326C; char pad3270[0x3539 - 0x3270];
    unsigned char b3539;
    unsigned char b353A;
    char pad353B;
    float f353C;
    float f3540;
} Stun_L;
extern "C" {
extern float D_0048A248;
extern float D_0048A240;
extern signed char D_004EEE40;
extern Name_L D_004EEE50;
extern char D_0049E080[];
int Libc_Rand(void);
}
static inline float RandRange_L(float lo, float hi) { float m = 2147483648.0f; return lo + (hi - lo) * ((float)Libc_Rand() / (1.0f + m)); }
extern "C" void cHuman_Choke_NextFrame(Stun_L* a, float dt)
{
    /* Compiler-mode selector only: this dead block emits no code. Any volatile asm in a
       function makes MW compile it in its less-optimised mode, which the retail function
       was built in (event pointers kept in their own s-registers, un-strength-reduced
       name-copy loop, b;nop kept). */
    if (0) { asm volatile { nop } }

    if (a->b3539 || a->b353A) {
        a->f353C += dt;
        a->b3539 = 0;
    }
    if (a->f353C <= a->f3540) return;
    a->f353C = 0.0f;
    a->b353A = !a->b353A;
    if (a->b353A) {
        a->f3540 = RandRange_L(D_0048A248 / 2.0f, D_0048A248);
        if (a->f320C == 0) {
            Prio_L((char*)&a->f320C, 0x19, 1);
            STATIC_NAME(D_004EEE40, D_004EEE50, D_0049E080)
            {
                Rate_L r;
                X_L x;
                Sys_L* sys;
                Anm_L* m;
                XInit_L(&x);
                RateDef_L(&r);
                sys = &a->sys;
                m = cSkaAnimationSet_GetNode_cString16NR(sys->lib, &D_004EEE50);
                Mot2_L(sys, m, 1, &r, &x);
                XDtor_L(&x);
            }
        }
    } else {
        a->f3540 = RandRange_L(D_0048A240 / 2.0f, D_0048A240);
        if (a->f320C == 0x19) {
            Prio_L((char*)&a->f320C, 0x19, 0);
            {
                Rate_L r;
                X_L x;
                AEv_L e1;
                AEv_L e2;
                AEv_L* p1;
                AEv_L* p2;
                int* s2;
                Sys_L* sys;
                XInit_L(&x);
                RateDef_L(&r);
                s2 = a->f326C;
                sys = &a->sys;
                p1 = &e1;
                AEvInit_L(p1);
                p2 = &e2;
                AEvInit_L(p2);
                cSkaRequestStream_AddRequest(&sys->anim, (void*)*s2, 0, &r, YOf_L(s2), p1, p2, &x, -1.0f, 0.0f);
                e2.vtable = D_004DA930;
                cMessage_dtor(p2, 0);
                e1.vtable = D_004DA930;
                cMessage_dtor(p1, 0);
                XDtor_L(&x);
            }
        }
    }
}
