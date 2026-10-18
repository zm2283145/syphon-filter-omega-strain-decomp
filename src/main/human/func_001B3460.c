#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off
#include "vslot_pad.h"

/* Npc_InitModel: bind the skeleton, pick the model kind from its name, place the root from the
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
void Skel_Bind(Npc* a, int* desc);
int strcmp(const char* a, const char* b);
void Npc_SetupModel(Npc* a);
void Root_SetWorldPlacement(Root_L* r, Plc4* p);
float Math_Atan2f(float y, float x);
float* History_At(char* h, int i);
void ActorHeading_RetargetLast(char* h, float f);
void func_0018A910(void* p);
void func_0018A8C0(void* p);
void func_0018A890(void* p);
void func_0018A710(void* d, void* s);
void func_0018A700(void* p, int v);
void Actor_ResolveMotionSelection(Sel_L* sel, int* out, Y_L* y, void* model);
float Model_GetFirstFloat(void* m);
V4_L* AnimRate_Init(V4_L* p, float f);
V4_L* Vec4_Copy_18A350(V4_L* d, V4_L* s);
void AnimEvent_Construct(Ev_L* e);
signed char MotionRequest_GetMode(Sel_L* s);
void* func_0018A2E0(Sel_L* s);
float func_0018A2D0(Sel_L* s);
float func_0018A2C0(Sel_L* s);
void AnimCtl_InstallMotion(void* ctl, int id, signed char mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void func_0018A260(void* p, int f);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void Actor_ResetAnimChannels(Npc* a);
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
static inline float H180(V4* v) { return Math_Atan2f(GetY(v), GetX(v)); }
static inline float H170(float* v) { return Math_Atan2f(-v[0], v[1]); }
static inline X_L* XInit_L(X_L* x) { X_L* px = x; px->kind = 0; func_0018A910(px->pairs); func_0018A8C0(px->tail); return px; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
static inline void XDtorN_L(X_L* p) {
    void* t = p->tail;
    if (t) { if (t) { if (t) func_001BE5A0(t, 0); } }
    if (p->pairs) __destroy_array(p->pairs, (void*)func_0018A210, 8, 7);
}
static inline void SelAuto_L(Sel_L* s, int v, X_L* x) { s->mode = 2; func_0018A890(s->sub); s->f44 = v; s->f48 = 3; func_0018A710(&s->x, x); }
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
    func_0018A700(&y, -1);
    Actor_ResolveMotionSelection(sel, &out, &y, an->model);
    if (out) {
        V4_L* p;
        if (an->b5)
            p = &an->v;
        else
            p = AnimRate_Init(&rate, Model_GetFirstFloat(an->model));
        Vec4_Copy_18A350(&vec, p);
        an->b5 = 0;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        AnimCtl_InstallMotion(an, out, MotionRequest_GetMode(sel), &vec, &y, &e1, &e2, func_0018A2E0(sel), func_0018A2D0(sel), func_0018A2C0(sel));
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
extern "C" void Npc_InitModel(Npc* a, int* desc)
{
    Mtx m;
    Plc4 pl;
    X_L x;
    Sel_L sel;
    Skel_Bind(a, desc);
    char* name = a->name;
    if (!strcmp(name, D_0049E830)) {
        a->kind = 2;
    } else if (!strcmp(name, D_0049E840)) {
        a->kind = 1;
    }
    Npc_SetupModel(a);
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
        Root_SetWorldPlacement(r, &pl);
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
            History_At(a->hist, idx)[1] = h;
        }
        ActorHeading_RetargetLast(a->heading, -1.0f);
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
    Actor_ResetAnimChannels(a);
}
