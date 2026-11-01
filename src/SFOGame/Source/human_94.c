/*
 * SFOGame/Source/human: 6 files, 001B3400-001B3B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B3400 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x3314]; void* p3314; char pad2[0x352C - 0x3318]; float f352C; } A1_S;
extern float D_0048A208;
extern void cHumanIkRoutine_ApplyGunRecoil_float_float(void*);
void cHuman_DoWeaponRecoil(A1_S* s, float dt) {
    s->f352C += dt;
    if (s->f352C > D_0048A208) s->f352C = D_0048A208;
    if (s->p3314) cHumanIkRoutine_ApplyGunRecoil_float_float(s->p3314);
}
static inline void merge_flush_func_001B3400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B3400 */

/* merge_units: begin func_001B3460 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off
#include "vslot_pad.h"

/* cHuman_Load: bind the skeleton, pick the model kind from its name, place the root from the
   model matrix, reset the heading history and start the idle motion. */

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct Plc4 { V4 rot, pos; };
struct Mtx { V4 r0, r1, r2, r3; };

typedef struct { float x, y, z, w; } V4_L;
typedef struct { int id; void* a; } Pair_L;
typedef struct { unsigned char kind; char pad[3]; Pair_L pairs[7]; char tail[0x10]; } X_L;
typedef struct { unsigned char mode; char pad1[0xF]; char sub[0x30]; int f40; int f44; unsigned char f48; char pad49[3]; X_L x; float f98; int f9C; } Sel_L;
typedef struct { void* model; char pad4; unsigned char b5; char pad6[2]; V4_L v; } Anim_L;
typedef struct { void* lib; char pad4[0xC]; char f10[0x24]; Anim_L anim; } Sys_L;
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { char pad[0x160]; int f160; } Root_L;

struct Elem { VPAD16(a) VPAD4(b) virtual void Sync(); char pad04[0xC]; Mtx m; unsigned char b50; };

struct Npc {
    char pad0[0x50];
    Elem* elem;                 /* 0x50 */
    char pad54[0xD0 - 0x54];
    char name[0x10];            /* 0xD0 */
    char padE0[0x2EC0 - 0xE0];
    Sys_L sys;                  /* 0x2EC0 */
    char pad2F04[0x3030 - 0x2EC0 - sizeof(Sys_L)];
    char heading[0x58];         /* 0x3030 */
    char hist[0x10];            /* 0x3088 */
    int i3098;                  /* 0x3098 */
    char pad309C[0x3260 - 0x309C];
    unsigned char kind;         /* 0x3260 */
    char pad3261[0x326C - 0x3261];
    int f326C;                  /* 0x326C */
    char pad3270[0x3290 - 0x3270];
    Root_L* root;               /* 0x3290 */
};

extern "C" {
extern char D_0049E830[];
extern char D_0049E840[];
void cSKM_GOBJ_Load(Npc* a, int* desc);
int strcmp(const char* a, const char* b);
void cHuman_InitAnimationSet(Npc* a);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(Root_L* r, Plc4* p);
float Libc_Atan2f(float y, float x);
float* cArray_cTargetZRotationStackSlot_opIndex(char* h, int i);
void cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(char* h, float f);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void cString16N_3_ctor_void(void* p);
void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(void* d, void* s);
void cSkaPlaybackGroupId_ctor_int(void* p, int v);
void cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(Sel_L* sel, int* out, Y_L* y, void* model);
float cSkaAnimationSet_DefaultCrossFadeDuration(void* m);
V4_L* cSkaCrossFadeDuration_ctor_float(V4_L* p, float f);
V4_L* cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(V4_L* d, V4_L* s);
void cSkaAnimEndedMessage_ctor_void(Ev_L* e);
signed char cSkaRequestStream_AnimationPacket_GetInstruction(Sel_L* s);
void* cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(Sel_L* s);
float cSkaRequestStream_AnimationPacket_GetDuration(Sel_L* s);
float func_0018A2C0(Sel_L* s);
void cSkaRequestStream_AddRequest(void* ctl, int id, signed char mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void cSkaAnimEndedMessage_dtor(void* p, int f);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void cHuman_ResetAnimationSliderValuesToDefaults(Npc* a);
}

static inline Plc4* MtxToPlc(Mtx* m, Plc4* out) {
    Plc4* o = out;
    Mtx* mm = m;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(mm)
        lqc2 vf2, 0x10(mm)
        lqc2 vf3, 0x20(mm)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(o)
        .set reorder
    }
    Q16(&out->pos, &m->r3);
    return out;
}

static inline float GetX(V4* v) { return v->x; }
static inline float GetY(V4* v) { return v->y; }
static inline float GetZ(V4* v) { return v->z; }
static inline float H180(V4* v) { return Libc_Atan2f(GetY(v), GetX(v)); }
static inline float H170(float* v) { return Libc_Atan2f(-v[0], v[1]); }
static inline X_L* XInit_L(X_L* x) { X_L* px = x; px->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(px->pairs); cArray_cTimedEvent_ctor_void(px->tail); return px; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
static inline void XDtorN_L(X_L* p) {
    void* t = p->tail;
    if (t) { if (t) { if (t) func_001BE5A0(t, 0); } }
    if (p->pairs) __destroy_array(p->pairs, (void*)func_0018A210, 8, 7);
}
static inline void SelAuto_L(Sel_L* s, int v, X_L* x) { s->mode = 2; cString16N_3_ctor_void(s->sub); s->f44 = v; s->f48 = 3; cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&s->x, x); }
static inline void Install_L(Npc* a, Sel_L* sel)
{
    int out;
    Y_L y;
    V4_L vec;
    V4_L rate;
    Ev_L e1;
    Ev_L e2;
    Sys_L* sys = &a->sys;
    Anim_L* an = &sys->anim;
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(sel, &out, &y, an->model);
    if (out) {
        V4_L* p;
        if (an->b5)
            p = &an->v;
        else
            p = cSkaCrossFadeDuration_ctor_float(&rate, cSkaAnimationSet_DefaultCrossFadeDuration(an->model));
        cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&vec, p);
        an->b5 = 0;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        cSkaRequestStream_AddRequest(an, out, cSkaRequestStream_AnimationPacket_GetInstruction(sel), &vec, &y, &e1, &e2, cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(sel), cSkaRequestStream_AnimationPacket_GetDuration(sel), func_0018A2C0(sel));
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
extern "C" void cHuman_Load(Npc* a, int* desc)
{
    Mtx m;
    Plc4 pl;
    X_L x;
    Sel_L sel;
    cSKM_GOBJ_Load(a, desc);
    char* name = a->name;
    if (!strcmp(name, D_0049E830)) {
        a->kind = 2;
    } else if (!strcmp(name, D_0049E840)) {
        a->kind = 1;
    }
    cHuman_InitAnimationSet(a);
    {
        Elem* e = a->elem;
        Root_L* r;
        if (e->b50) {
            e->Sync();
        }
        {
            /* 64-byte matrix copy, two quads alternating (retail form); GCC-style asm so MW does not CSE &m across it */
            const Mtx* ps = &e->m;
            Mtx* pd = &m;
            __int128 qa, qb;
            __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(pd), "r"(ps) : "memory");
        }
        r = a->root;
        MtxToPlc(&m, &pl);
        cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r, &pl);
        r->f160 = 0;
        {
            int idx = a->i3098;
            float h;
            V4 r0;
            V4 r1;
            V4* d0 = &r0;
            Q16(d0, &m.r0);
            Q16(&r1, &m.r1);
            /* Mtx_GetHeading inlined */
            if (GetZ(&r0) < GetZ(&r1)) h = H180(&r0); else h = H170(&r1.x);
            cArray_cTargetZRotationStackSlot_opIndex(a->hist, idx)[1] = h;
        }
        cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(a->heading, -1.0f);
    }
    XInit_L(&x);
    {
        Sel_L* ps = &sel;
        SelAuto_L(ps, a->f326C, &x);
        ps->f98 = 0.0f;
        ps->f9C = 0;
        Install_L(a, &sel);
        XDtorN_L((X_L*)((char*)&sel + 0x4C));
    }
    XDtor_L(&x);
    cHuman_ResetAnimationSliderValuesToDefaults(a);
}
static inline void merge_flush_func_001B3460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B3460 */

/* merge_units: begin func_001B3950 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void cSKM_GOBJ_Init(void*);

void cHuman_Init(void* self) {
    cSKM_GOBJ_Init(self);
}
static inline void merge_flush_func_001B3950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B3950 */

/* merge_units: begin func_001B3960 */
#pragma push /* merge_units */
#pragma cplusplus on
struct P_1B3960 { char pad[0xC]; int h; };
class O_1B3960 { public: VPAD16(a) VPAD4(b) VPAD2(c) virtual void Kill(int f); char pad4[0x54]; void* npc; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
P_1B3960* cNetObj_GetPlayer(int i);
int cNetObj_GetOwner(int h);
void cNPC_Deactivate_cGOBJP(void* npc, P_1B3960* p);
}
static inline int Net_1B3960(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline void Deact_1B3960(void* npc, P_1B3960* f) { if (f && Net_1B3960()) cNPC_Deactivate_cGOBJP(npc, f); }
extern "C" void cHuman_NetDisable(O_1B3960* self, int id)
{
    P_1B3960* found = 0;
    if (id >= 0) {
        if (Net_1B3960()) {
            int i;
            for (i = 0; i < 4; i++) {
                P_1B3960* p = cNetObj_GetPlayer(i);
                if (p && cNetObj_GetOwner(p->h) == id) { found = p; break; }
            }
        }
        Deact_1B3960(self->npc, found);
    } else {
        self->Kill(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B3960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B3960 */

/* merge_units: begin func_001B3A60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct P_1B3A60 { char pad[0xC]; int h; };
class T_1B3A60 { public: VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void Set(int v); };
struct N_1B3A60 { char pad[0x30]; T_1B3A60* t; };
struct O_1B3A60 { char pad[0x58]; N_1B3A60* npc; };
extern "C" {
#if 0 /* merge_units */
P_1B3A60* cNetObj_GetPlayer(int i);
#endif /* merge_units */
#define cNetObj_GetPlayer(a0) ((P_1B3A60 *)cNetObj_GetPlayer((a0))) /* merge_units */



void cNPC_Activate_cGOBJP(N_1B3A60* npc, P_1B3A60* p);
}
static inline int Net_1B3A60(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline void Act_1B3A60(N_1B3A60* npc, P_1B3A60* f) { if (f && Net_1B3A60()) cNPC_Activate_cGOBJP(npc, f); }
extern "C" void cHuman_NetEnable(O_1B3A60* self, int id)
{
    P_1B3A60* found = 0;
    if (id >= 0 && Net_1B3A60()) {
        int i;
        for (i = 0; i < 4; i++) {
            P_1B3A60* p = cNetObj_GetPlayer(i);
            if (p && cNetObj_GetOwner(p->h) == id) { found = p; break; }
        }
    }
    self->npc->t->Set(-1);
    Act_1B3A60(self->npc, found);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B3A60(void) {}
#undef cNetObj_GetPlayer /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B3A60 */

/* merge_units: begin func_001B3B60 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
typedef struct Ev {
    void* vt;
    char pad4[0x8];
    int xC;
    char pad10[0x14];
    int x24;
    unsigned int x28;
    int x2C;
    int x30;
    unsigned char x34;
    char pad35[3];
    int x38;
} Ev;

struct Ev;struct Npc_001B3B60;struct Player;
struct Sub {
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void f64(int);

};
struct Ctl {
    virtual void v8();
    virtual int Handle(Ev*);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual int f44();
    virtual void f48();
    virtual void v4C();
    virtual void v50();
    virtual int IsPlayer();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual unsigned char State();
    char pad4[0x30 - 4];
    Sub* x30;
    char pad34[0x141 - 0x34];
    unsigned char b141l : 7;
    unsigned char b141h : 1;
    char pad142[0x150 - 0x142];
    int x150;
};
struct Node_001B3B60 {
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void Update();
    char pad4[0xC];
    char mtx[0x30];
    char pos[0x10];
    Node_001B3B60* x50;
};
struct Xf {
    virtual void v8();
    virtual void SetMtx(void*);
    virtual void v10();
    virtual void SetPos(void*);

};
struct Npc_001B3B60 {
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void Activate(int);
    virtual void Deactivate(int);
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual int f7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFC();
    virtual void PlayAnim(int, int, int, int, int, int, float);
    char pad4[0x14 - 4];
    unsigned char b14;
    char pad15[0x2C - 0x15];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x40 - 0x2F];
    float x40;
    char pad44[0x58 - 0x44];
    Ctl* ctl;
    char pad5C[0x60 - 0x5C];
    char x60[0x31B1 - 0x60];
    unsigned char b31B1;
    char pad31B2[0x31F0 - 0x31B2];
    int x31F0;
    char pad31F4[0x3210 - 0x31F4];
    int x3210;
    char pad3214[0x33A0 - 0x3214];
    int x33A0;
    char pad33A4[0x33F0 - 0x33A4];
    char x33F0[0x3440 - 0x33F0];
    Xf* xf;
    char pad3444[0x3450 - 0x3444];
    int x3450;
    char pad3454[4];
    int x3458;
    char pad345C[0x3524 - 0x345C];
    void* inv;
    char pad3528[0x3584 - 0x3528];
    void* x3584;
    char pad3588[0x3594 - 0x3588];
    int x3594;
};

struct Player { char pad[0xC]; void* p; };

extern int* cMessage_Name(Ev*);
extern int D_0052ACB0, g_CasEventMsgClass, D_004EE550, D_00588038, D_004EE698, D_00582680, D_00582730;
extern int g_ActorActionMsgClass, D_004F82F0, D_00542B60, D_00542B68, D_0055D4D8, g_TeleportMsgClass;
extern int g_cEnableMsgClass, g_cDisableMsgClass, D_004F7930, D_004F7940, D_004F80B8, D_004F80A8;
extern int D_0051F0C0, D_0052ACC8, D_004F53F8, D_0052AF10, D_004A0318, D_004EE960;
extern int D_004E0840, D_0049D8D0;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern unsigned char g_IsMultiplayer, D_005721C0;

extern void cHuman_CreateGobjController(Npc_001B3B60*, int, void*, void*);
extern void Alloc_Lock(int);
extern void EnableIntc(int);
extern void* cMemMan_Allocate(int, int, void*, int);
extern void* cNetNPC_ctor(void*, int, Npc_001B3B60*);
extern void cNetHuman_Deactivate(void*);
extern int cHuman_HandleActionRequest(Npc_001B3B60*, Ev*);
extern void cMessage_ctor_cMessageNameR(void*, void*);
extern void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
extern void cMessage_dtor(void*, int);
extern int Actor_HandleEmbeddedEvent(Npc_001B3B60*, Ev*);
extern int AnimToken_Handle(Npc_001B3B60*, Ev*);
extern int cHuman_HandleMoveMessage_cMoveMsgTemplateR(Npc_001B3B60*, Ev*);
extern int cHuman_HandleMoveMessage_cMoveMsgTemplateR_2(Npc_001B3B60*, Ev*);
#if 0 /* merge_units */
extern Player* cNetObj_GetPlayer(int);
#endif /* merge_units */
#define cNetObj_GetPlayer(a0) ((Player *)cNetObj_GetPlayer((a0))) /* merge_units */

#if 0 /* merge_units */
extern int cNetObj_GetOwner(void*);
#endif /* merge_units */
#define cNetObj_GetOwner(a0) (cNetObj_GetOwner((int)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cNPC_Activate_cGOBJP(Ctl*, Player*);
#endif /* merge_units */
#define cNPC_Activate_cGOBJP(a0, a1) (cNPC_Activate_cGOBJP((N_1B3A60 *)(a0), (P_1B3A60 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cNPC_Deactivate_cGOBJP(Ctl*, Player*);
#endif /* merge_units */
#define cNPC_Deactivate_cGOBJP(a0, a1) (cNPC_Deactivate_cGOBJP((void *)(a0), (P_1B3960 *)(a1))) /* merge_units */

extern void cNode_GetLoc(void*, Node_001B3B60*);
extern void cNode_GetNodeMatrix(void*, Node_001B3B60*);
extern void cCheckpoint_SetString(void*, int);
extern void Actor_Revive(Npc_001B3B60*);
extern void Actor_EnterDeadState(Npc_001B3B60*);
extern char* nGobjManager_LookupGOBJ_cObjectIdR(int*);
extern void cMan_AddCostume(void*, void*);
extern void cMan_RemoveCostume(void*);
extern void cWeapon_RemoveWeapon(void*, int, int, int, int);
extern void cWeapon_RemoveAmmo(void*, int, int, int, int);
extern void cWeapon_Add(void*, int, bool, int, bool, int);
extern void cWeapon_PickupClip(void*, int, int, int);
extern void cWeapon_PickupAmmo_eWpnSlot_int_bool(void*, int, int, int);
extern void cWeapon_EqualizeDualWieldAmmo(void*);
extern void cHuman_TurnOnWeaponPickup(Npc_001B3B60*);
extern int cGOBJ_HandleMessage(Npc_001B3B60*, Ev*);

}
typedef struct Msg { void* vt; char pad[0x20]; int x24; unsigned char x28; char pad29[0x30 - 0x29]; } Msg;

struct IA { int* p; int q; IA(int* a, int b) { p = a; q = b; } };
static inline char* Lookup(int id) { return nGobjManager_LookupGOBJ_cObjectIdR(&id); }
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct ActMsg { void* vt; char pad[0x20]; int x24; unsigned char x28; char pad29[7];
    ActMsg(int k) { cMessage_ctor_cMessageNameR(this, &g_ActorActionMsgClass); vt = &D_004E0840; x24 = k; x28 = 0; }
    __declspec(weak) __declspec(MSG_DTOR) ~ActMsg() { vt = &D_004E0840; cMessage_dtor(this, 0); } };
static inline void SendTo(const ActMsg& m, void* to) { QueueMessage_cMessageR_cSystemP_int((void*)&m, to, 1); }
static inline bool IsPl(Npc_001B3B60* a) { bool r = 0; if (a->ctl && a->ctl->IsPlayer()) r = 1; return r; }
static inline bool Active(Npc_001B3B60* a) { return a->b2D && a->b2C && !a->b2E; }

static inline Player* FindPlayer(Ev* e) {
    Player* found = 0;
    int i;
    if (g_IsMultiplayer ? D_005721C0 : 1) {
        for (i = 0; i < 4; i++) {
            Player* p = cNetObj_GetPlayer(i);
            if (p && e->x24 == cNetObj_GetOwner(p->p)) {
                found = p;
                break;
            }
        }
    }
    return found;
}

extern "C" int cHuman_HandleMessage(Npc_001B3B60* self, Ev* e) {
    int t;
    if ((t = *cMessage_Name(e), t == D_0052ACB0)) {
        Ctl* c = self->ctl;
        if (c && c->State() == 4) return c->Handle(e);
    } else if ((t = *cMessage_Name(e), t == g_CasEventMsgClass) || (t = *cMessage_Name(e), t == D_004EE550) || (t = *cMessage_Name(e), t == D_00588038)) {
        Ctl* c = self->ctl;
        if (c && c->State() != 2 && c->State() != 4) return c->Handle(e);
    } else if ((t = *cMessage_Name(e), t == D_004EE698)) {
        switch (e->x28 - 8) {
        case 8 - 8: case 9 - 8: case 12 - 8: case 13 - 8: case 14 - 8: case 15 - 8: case 16 - 8: case 18 - 8:
            if (self->ctl) return self->ctl->Handle(e);
        case 10 - 8: case 11 - 8: case 17 - 8:
        default:
            return 0;
        }
    } else if ((t = *cMessage_Name(e), t == D_00582680)) {
        if (self->ctl->State() == 2) cHuman_CreateGobjController(self, 2, 0, 0);
        self->Activate(0);
    } else if ((t = *cMessage_Name(e), t == D_00582730)) {
        switch ((unsigned char)e->x24) {
        case 2: {
            Ctl* c = self->ctl;
            void* p;
            if (!c || (c && c->State() != 2)) {
                if (g_ProfileLockEnabled) Alloc_Lock(9);
                g_ProfileLockDepth++;
                p = cMemMan_Allocate(0, 0x220, &D_0049D8D0, 0x543);
                if (g_ProfileLockEnabled) EnableIntc(9);
                g_ProfileLockDepth--;
                if (p) p = cNetNPC_ctor(p, 0, self);
                cHuman_CreateGobjController(self, 4, 0, p);
                if (Active(self)) self->ctl->f48();
            }
            if (self->x3584) cNetHuman_Deactivate(self->x3584);
            break;
        }
        case 1: {
            Ctl* c = self->ctl;
            if (c && c->State() != 1) {
                if (self->f7C()) {
                    int w = self->x31F0;
                    int v = self->ctl->x150;
                    IA arg(&v, w);
                    cHuman_CreateGobjController(self, 2, &arg, 0);
                } else {
                    cHuman_CreateGobjController(self, 2, 0, 0);
                }
                if (Active(self)) self->ctl->f48();
            }
            break;
        }
        }
    } else if ((t = *cMessage_Name(e), t == g_ActorActionMsgClass)) {
        return cHuman_HandleActionRequest(self, e);
    } else if ((t = *cMessage_Name(e), t == D_004F82F0)) {
        if (self->b14) {
            switch ((signed char)e->x24) {
            case 0: {
                SendTo(ActMsg(6), self);
                break;
            }
            case 1:
                self->PlayAnim(e->x28, 2, 2, 0, 0, 0, (int)self->x40);
                break;
            case 2:
                self->PlayAnim(e->x28, 1, 14, 0, 0, 0, (int)self->x40);
                break;
            }
            return 1;
        }
    } else if ((t = *cMessage_Name(e), t == D_00542B60)) {
        return Actor_HandleEmbeddedEvent(self, e);
    } else if ((t = *cMessage_Name(e), t == D_00542B68)) {
        return AnimToken_Handle(self, e);
    } else if ((t = *cMessage_Name(e), t == D_0055D4D8)) {
        return cHuman_HandleMoveMessage_cMoveMsgTemplateR(self, e);
    } else if ((t = *cMessage_Name(e), t == g_TeleportMsgClass)) {
        return cHuman_HandleMoveMessage_cMoveMsgTemplateR_2(self, e);
    } else if ((t = *cMessage_Name(e), t == g_cEnableMsgClass)) {
        Ctl* c = self->ctl;
        if (g_IsMultiplayer) {
            if (e->x24 >= 0) {
                Player* p = FindPlayer(e);
                self->ctl->x30->f64(-1);
                if (p && (g_IsMultiplayer ? D_005721C0 : 1) && c->f44())
                    cNPC_Activate_cGOBJP(c, p);
            }
        } else if (!Active(self) && c->f44()) {
            self->Activate(1);
        }
        return 1;
    } else if ((t = *cMessage_Name(e), t == g_cDisableMsgClass)) {
        if (g_IsMultiplayer) {
            if (e->x24 >= 0) {
                Player* p = FindPlayer(e);
                Ctl* c = self->ctl;
                if (p && (g_IsMultiplayer ? D_005721C0 : 1)) cNPC_Deactivate_cGOBJP(c, p);
            }
        } else if (Active(self) && !self->ctl->b141h) {
            self->Deactivate(1);
        }
        return 1;
    } else if ((t = *cMessage_Name(e), t == D_004F7930)) {
        Node_001B3B60* n = (Node_001B3B60*)e->x24;
        if (n) {
            char pos[0x10];
            char mtx[0x40];
            Xf* x = self->xf;
            cNode_GetLoc(pos, n);
            x->SetPos(pos);
            x = self->xf;
            cNode_GetNodeMatrix(mtx, n);
            x->SetMtx(mtx);
        } else {
            Xf* x;
            Node_001B3B60* m = n->x50;
            x = self->xf;
            if (((unsigned char*)m)[0x50]) m->Update();
            x->SetPos(m->pos);
            {
            Xf* x2;
            Node_001B3B60* m2 = n->x50;
            x2 = self->xf;
            if (((unsigned char*)m2)[0x50]) m2->Update();
            x2->SetMtx(m2->mtx);
            }
        }
        self->x3450 = (int)self->x40;
        self->x3458 = self->x33A0;
        cCheckpoint_SetString(self->x33F0, e->x28);
        return 1;
    } else if ((t = *cMessage_Name(e), t == D_004F7940)) {
        self->x3594 = e->xC;
        if (!IsPl(self) || !self->b14 || (self->x3210 >> 31) & 1)
            Actor_Revive(self);
        else
            Actor_EnterDeadState(self);
    } else if ((t = *cMessage_Name(e), t == D_004F80B8)) {
        int id0, id1, id2;
        char* o;
        { int* z = &id0; if (!z) return 0; }
        id1 = e->x30;
        o = nGobjManager_LookupGOBJ_cObjectIdR(&id1);
        id2 = e->x2C;
        nGobjManager_LookupGOBJ_cObjectIdR(&id2);
        cMan_AddCostume(self->x60, o + 0xA0);
    } else if ((t = *cMessage_Name(e), t == D_004F80A8)) {
        cMan_RemoveCostume(self->x60);
    } else if ((t = *cMessage_Name(e), t == D_0051F0C0)) {
        self->ctl->Handle(e);
    } else if ((t = *cMessage_Name(e), t == D_0052ACC8)) {
        unsigned char k = e->x2C;
        switch (k) {
        case 0:
            if (!((self->x3210 >> 27) & 1))
                cWeapon_RemoveWeapon(self->inv, e->x34, 0, e->x38 != 0, 1);
            break;
        case 1:
            cWeapon_RemoveAmmo(self->inv, e->x34, e->x38, 1, 1);
            break;
        case 5:
            cWeapon_Add(self->inv, e->x34, e->x38 & 1, 0, (e->x38 >> 1) & 1, 1);
            break;
        case 3:
            cWeapon_PickupClip(self->inv, e->x34, e->x38, 1);
            break;
        case 4:
            cWeapon_PickupAmmo_eWpnSlot_int_bool(self->inv, e->x34, e->x38, 1);
            cWeapon_EqualizeDualWieldAmmo(self->inv);
            break;
        }
    } else if ((t = *cMessage_Name(e), t == D_004F53F8)) {
        Ctl* c = self->ctl;
        int r = 0;
        if (c) r = c->Handle(e);
        return r;
    } else if ((t = *cMessage_Name(e), t == D_0052AF10)) {
        self->b31B1 = *(unsigned char*)&e->x24;
    } else if ((t = *cMessage_Name(e), t == D_004A0318)) {
        QueueMessage_cMessageR_cSystemP_int(e, self->ctl, 1);
    } else if ((t = *cMessage_Name(e), t == D_004EE960)) {
        cHuman_TurnOnWeaponPickup(self);
    } else {
        return cGOBJ_HandleMessage(self, e);
    }
    return 0;
}
#undef cNetObj_GetPlayer /* merge_units */
#undef cNetObj_GetOwner /* merge_units */
#undef cNPC_Activate_cGOBJP /* merge_units */
#undef cNPC_Deactivate_cGOBJP /* merge_units */
static inline void merge_flush_func_001B3B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B3B60 */
