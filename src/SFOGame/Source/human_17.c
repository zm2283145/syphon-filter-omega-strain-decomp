/*
 * SFOGame/Source/human: 3 files, 0019E660-0019E9A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019E660 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

Vec4* cVector_SetW(Vec4* v, float w) {
    v->w = w;
    return v;
}
static inline void merge_flush_func_0019E660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019E660 */

/* merge_units: begin func_0019E670 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
void cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(Act_L* a, Name_L* n, float* t, int x, int y);
#endif /* merge_units */
struct Actor_0019E9A0; /* merge_units */
struct Name48; /* merge_units */
void cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(Actor_0019E9A0* self, Name48* out, float* blend, int air, int alt); /* merge_units */
#define cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(a0, a1, a2, a3, a4) (cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration((Actor_0019E9A0 *)(a0), (Name48 *)(a1), (a2), (a3), (a4))) /* merge_units */

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
#undef cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration /* merge_units */
static inline void merge_flush_func_0019E670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019E670 */

/* merge_units: begin func_0019E9A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(8)
typedef int Q128 __attribute__((mode(TI)));
static inline void QCopy(void* d, const void* s) { void* dd; Q128 q; const void* ss = s; dd = d; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }

struct V4 {
    float x, y, z, w;
    V4& operator=(const V4& o) { QCopy(this, &o); return *this; }
} __attribute__((aligned(16)));
struct V4Z : V4 { V4Z(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
extern "C" signed char D_004E1D88;
extern "C" V4 D_004E1D90;
struct Mtx {
    V4 r[4];
    V4* Pos() { return &r[3]; }
} __attribute__((aligned(16)));

static inline V4 operator+(const V4& a, const V4& b)
{
    V4 r; const V4* p0; const V4* p1 = &b; p0 = &a; V4* q = &r;
    asm {
        lqc2 vf1, 0x0(p0)
        lqc2 vf2, 0x0(p1)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q)
    }
    return r;
}
static inline V4 operator-(const V4& a)
{
    V4 r; V4* q = &r; const V4* p0 = &a;
    __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(q), "r"(p0) : "memory");
    return r;
}
static inline float Dot3(const V4* a, const V4* b)
{
    const V4* pb = b; const V4* pa = a; int t; float r = 0.0f;
    asm {
        lqc2 vf1, 0(pa)
        lqc2 vf2, 0(pb)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
static inline Mtx* QuatToMtx(Mtx* a, const V4* b)
{
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
    return a;
}
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Clamp(float v, float lo, float hi)
{
    float r = 0.0f;
    asm { max.s r, v, lo }
    asm { min.s r, r, hi }
    return r;
}

static inline void QLoop3(void* d0, const void* s0) { int n = 3; void* d = d0; const void* s = s0;
    asm {
        .set noreorder
    lp:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v1, -0x10(d)
        .set reorder
    }
}
static inline float Clamp01S(float v, float k) { float r = 0.0f; float x = v * k; float lo = 0.0f; float hi = 1.0f; asm { max.s r, x, lo } asm { min.s r, r, hi } return r; }
static inline float AddF(float x, float y) { return x + y; }
static inline float AddR(float x, float y) { float r = x + y; return r; }
static inline float Clamp01P(float v, float k) { float r = 0.0f; float x = (v + 3.1415927f) * k; float lo = 0.0f; float hi = 1.0f; asm { max.s r, x, lo } asm { min.s r, r, hi } return r; }
static inline float Clamp01Q(float v, float k) { float r = 0.0f; float p = 3.1415927f; float x = (v + p) * k; float lo = 0.0f; float hi = 1.0f; asm { max.s r, x, lo } asm { min.s r, r, hi } return r; }
static inline float Clamp01T(float v, float k) { float r = 0.0f; v += 3.1415927f; float x = v * k; float lo = 0.0f; float hi = 1.0f; asm { max.s r, x, lo } asm { min.s r, r, hi } return r; }
static inline float Wrap(float v) { return v + 3.1415927f; }

static inline float Clamp01(float v) { float r = 0.0f; float lo = 0.0f; float hi = 1.0f; asm { max.s r, v, lo } asm { min.s r, r, hi } return r; }
static inline float Clamp2(float v, float lo, float hi) { float r = 0.0f; r = v; asm { max.s r, r, lo } asm { min.s r, r, hi } return r; }
struct Raw48 { char s[0x30]; } __attribute__((aligned(16)));
struct Name48 {
    Raw48 r;
    Name48(const char* src) { bool done = false; int i = 0; char c; const char* sp_ = src; for (; i < 0x2F; i++) { if (!sp_[i]) done = true; if (done) c = 0; else c = sp_[i]; r.s[i] = c; } r.s[i] = 0; }
    Name48& operator=(const Name48& o)
    {
        if (r.s[0] || o.r.s[0]) QLoop3(this, &o);
        return *this;
    }
};

extern "C" {
char* cArray_cBone_opIndex_int(PtrVec* v, int i);
void* cBone_Xform(void* n);
void* cXform_GetMatrix(void* t);
void cMatrix_GetTransformed(Mtx* out, void* in, void* m);
void cMatrix_ctor_cMatrixR(Mtx* out, void* m);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* root);
V4* cQuatVec_Rotation(void* pl);
V4 cVector_ctor_cVectorR(const V4* s);
V4* cVector_InverseRotate_cMatrixR(V4* v, Mtx* m);
float Libc_Atan2f(float y, float x);
void cSkaParams_SetSliderValue_int_float(float v, void* ch, int i);
}

struct SoundRequest { char pad000[0x48]; char partA[0x9C]; char partB[0xAC]; };
struct SoundMsg { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; };
extern "C" {
void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, const char* name, int a, int b);
void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(SoundMsg* msg, SoundRequest* req, V4* pos);
void QueueMessage_cMessageR_cSystemP_int(SoundMsg* msg, void* target, int flags);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(SoundMsg* msg, int flags);
}
extern char g_Game[];
extern char D_004DAE30[];
extern char D_0049E090[];
extern char D_0049E0B0[];
extern char D_0049E0E0[];
extern char D_0049E100[];
extern char D_0049E128[];
extern char D_0049E138[];
extern float D_0049CF10;

#define MKNAME(n, src) { bool done = false; int i = 0; char c; char* sp_ = src; for (; i < 0x2F; i++) { if (!sp_[i]) done = true; if (done) c = 0; else c = sp_[i]; n.r.s[i] = c; } n.r.s[i] = 0; }
struct Skel {
    char p0[0x14];
    unsigned char b14; char p15[3];
    PtrVec nodes;
    char p24[4];
    void* root;
};
struct Chan { char p0[0x10]; char ch[0x10]; };
struct Phys { char p0[0x310]; V4 vel; };
struct Actor_0019E9A0;
struct ActorVt {
    char p0[0xF4];
    void (*GetMtx)(Mtx* out, Actor_0019E9A0* a);
};
struct Actor_0019E9A0 {
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4(); virtual void vf5(); virtual void vf6(); virtual void vf7(); virtual void vf8(); virtual void vf9(); virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15(); virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19(); virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23(); virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27(); virtual void vf28(); virtual void vf29(); virtual void vf30(); virtual void vf31(); virtual void vf32(); virtual void vf33(); virtual void vf34(); virtual void vf35(); virtual void vf36(); virtual void vf37(); virtual void vf38(); virtual void vf39(); virtual void vf40(); virtual void vf41(); virtual void vf42(); virtual void vf43(); virtual void vf44(); virtual void vf45(); virtual void vf46(); virtual void vf47(); virtual void vf48(); virtual void vf49(); virtual void vf50(); virtual void vf51(); virtual void vf52(); virtual void vf53(); virtual void vf54(); virtual void vf55(); virtual void vf56(); virtual void vf57(); virtual void vf58();
    virtual Mtx GetMtx();
    char p4[0x2E50 - 4];
    Skel skel;
    char p2E7C[0x2EC0 - 0x2E7C];
    Chan anim;
    Chan* Anim() { return &anim; }
    char p2EE0[0x30A8 - 0x2EE0];
    float f30A8;
    char p30AC[0x3290 - 0x30AC];
    void* root;
    char p3294[0x3310 - 0x3294];
    Phys* phys;
    void NodeWorld(Mtx* out, int i)
    {
        Skel* s = &skel;
        if (skel.b14) cMatrix_GetTransformed(out, cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(&s->nodes, i))), cXform_GetMatrix(s->root));
        else cMatrix_ctor_cMatrixR(out, cXform_GetMatrix(s->root));
    }
    const V4& Vel()
    {
        if (phys) return phys->vel;
        if (!D_004E1D88) {
            D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f;
            D_004E1D88 = 1;
        }
        return D_004E1D90;
    }
};

typedef V4 (*VRetFn)(const V4*);
static inline V4* Addr(const V4& v) { return (V4*)&v; }
namespace P { extern "C" V4* cVector_ctor_cVectorR(V4* d, const V4* s); }
static inline V4 Xform(const V4& v, Mtx* m) { V4 t; return cVector_ctor_cVectorR(cVector_InverseRotate_cMatrixR(P::cVector_ctor_cVectorR(&t, &v), m)); }
static inline float Yaw(const V4& l) { return Libc_Atan2f(-l.x, l.y); }
static inline V4 XformW(const V4& v, Mtx* m) { return Xform(v, m); }
extern "C" void cHuman_HandleFootstepEvent(Actor_0019E9A0* a, int b, int c);

extern "C" void cHuman_HandleBodyImpactWithGroundAndReturnAnimationToPlayAndTransitionDuration(Actor_0019E9A0* self, Name48* out, float* blend, int air, int alt)
{
    Mtx m0;
    Mtx m2;
    V4 pos;
    self->NodeWorld(&m0, 0);
    self->NodeWorld(&m2, 2);
    bool down;
    { const V4& u = m0.r[2]; down = u.z < 0.0f; }
    const V4& up = m0.r[2];
    const V4& fwd = m0.r[1];
    bool side = Abs(up.z) > 0.7071f;
    if (down || !side) {
        pos = m2.r[1];
    } else {
        Mtx m1;
        Mtx m3;
        self->NodeWorld(&m1, 1);
        self->NodeWorld(&m3, 3);
        pos = m1.r[1] + m3.r[1];
    }
    Mtx rot;
    V4 dir;
    QuatToMtx(&rot, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(self->root)));
    if (Dot3(&pos, &rot.r[2]) <= 0.0f && !air) {
        if (!alt) *out = Name48(D_0049E090);
        else *out = Name48(D_0049E0B0);
        if (side) dir = fwd;
        else dir = up;
    } else {
        if (!alt) *out = Name48(D_0049E0E0);
        else *out = Name48(D_0049E100);
        if (side) dir = -fwd;
        else dir = up;
    }
    {
        float a = Yaw(XformW(dir, &rot));
        float c = Clamp01T(a, 0.15915494f); cSkaParams_SetSliderValue_int_float(c, self->Anim()->ch, 0x16);
    }
    {
        float g = -16.0f;
        float k = 0.2f / g;
        float hi, lo; hi = 0.25f; lo = 0.125f;
        const V4& v = self->Vel();
        float b = 1.2f - k * v.z;
        b = b * hi;
        *blend = Clamp2(b, lo, hi);
    }
    SoundRequest req;
    {
    bool soft = self->f30A8 <= D_0049CF10;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, soft ? D_0049E128 : D_0049E138, 0, 0);
    }
    {
        SoundMsg msg;
        cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, &req, self->GetMtx().Pos());
        msg.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
        msg.vtbl = D_004DAE30;
        cFileMan_dtor(msg.partB, -1);
        cFileMan_dtor(msg.partA, -1);
        cMessage_dtor(&msg, 0);
    }
    cFileMan_dtor(req.partB, -1);
    cFileMan_dtor(req.partA, -1);
    cHuman_HandleFootstepEvent(self, 0, 1);
}
static inline void merge_flush_func_0019E9A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019E9A0 */
