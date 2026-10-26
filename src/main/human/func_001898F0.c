#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "cmessage.h"

struct Ctl_898F0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsPlayer();
};
struct Vec4_898F0 { float x, y, z, w; };
struct Anim_898F0 { void* model; char pad4; unsigned char b5; char pad6[2]; Vec4_898F0 v; };
struct Sub3310_898F0 { char pad0[0x11]; unsigned char b11; char pad12[0x374 - 0x12]; float f374; char pad378[0x9C0 - 0x378]; unsigned char b9C0; };
struct Sub3584_898F0 { char pad0[0x34]; unsigned char b34; };
struct Act_898F0 {
    char pad0[0x14]; unsigned char b14; char pad15[0x58 - 0x15];
    Ctl_898F0* ctl; char pad5C[4];
    char f60[0x2EF4 - 0x60];
    Anim_898F0 anim; char pad2F0C[0x30AC - 0x2F0C];
    unsigned char b30AC; char pad30AD[0x320C - 0x30AD];
    char prio[0x3248 - 0x320C];
    char f3248[0x3269 - 0x3248];
    unsigned char b3269; char pad326A[2];
    int f326C; char pad3270[0x3310 - 0x3270];
    Sub3310_898F0* s3310; char pad3314[0x3398 - 0x3314];
    int f3398; int f339C; int f33A0; unsigned char b33A4; unsigned char b33A5; char pad33A6[2];
    int f33A8; int f33AC; int f33B0; char pad33B4[0x33F0 - 0x33B4];
    char f33F0[0x3524 - 0x33F0];
    int f3524; char pad3528[0x3584 - 0x3528];
    Sub3584_898F0* s3584;
};
struct X_898F0 { unsigned char kind; char pad[3]; char pairs[0x38]; char tail[0x10]; };
struct Sel_898F0 { unsigned char mode; char pad1[0xF]; char sub[0x34]; int f44; unsigned char f48; char pad49[3]; X_898F0 x; float f98; int f9C; };
struct Msg1_898F0 { CMSG_HEADER; int f24; unsigned char b28; char pad29[7]; };
struct Msg3_898F0 { CMSG_HEADER; char pad24[0xC]; };
struct Msg4_898F0 { CMSG_HEADER; int f24; int f28; int f2C; };
struct Ev_898F0 { char pad[0x40]; };
struct Y_898F0 { int a, b; };
struct Obj_898F0 { int f0; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; Act_898F0* fC; unsigned char b10; };

extern "C" {
extern char g_ActorActionMsgClass[]; extern char D_004E0840[];
extern char g_NotifyCheckpointMsgClass[]; extern char D_004DB8B0[];
extern char g_CasEventMsgClass[]; extern char D_004DA950[];
extern char D_004D9DE0[]; extern char D_004DA970[];
extern char D_0049D8D0[];
extern unsigned char g_IsMultiplayer;
extern float D_004A03E0;
void MotionTokens_Init(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void cString16N_3_ctor_void(void* p);
void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(void* d, void* s);
void cSkaPlaybackGroupId_ctor_int(void* p, int v);
void Actor_ResolveMotionSelection(Sel_898F0* sel, int* out, Y_898F0* y, void* model);
float Model_GetFirstFloat(void* m);
Vec4_898F0* AnimRate_Init(Vec4_898F0* p, float f);
Vec4_898F0* Vec4_Copy_18A350(Vec4_898F0* d, Vec4_898F0* s);
void AnimEvent_Construct(Ev_898F0* e);
signed char MotionRequest_GetMode(Sel_898F0* s);
void* cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(Sel_898F0* s);
float cSkaRequestStream_AnimationPacket_GetDuration(Sel_898F0* s);
float func_0018A2C0(Sel_898F0* s);
void AnimCtl_InstallMotion(void* ctl, int id, signed char mode, Vec4_898F0* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void AnimEvent_dtor(void* p, int f);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void);
void Actor_ResetAnimChannels(Act_898F0* a);
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void Actor_EnterDeadState(Act_898F0* a);
void ActionPriority_Reset(void* p, int v);
void ActionFlags_Clear(void* p);
void ActorModel_Deactivate(void* p);
void* Mem_Alloc(int pool, int size, char* file, int line);
void EventQueue_Admit(void* p);
void* Object_GetRootNode(void* p);
void* Transform_GetUpdated(void* p);
void Actor_RequestTeleport(Act_898F0* a, void* t);
void Actor_Ignite(float f, Act_898F0* a, int b, int c, int d, int e);
void Actor_SetHealth(Act_898F0* a, int h, int f);
void cWeapon_SetAmmoPlayerDeath(int p);
}

static inline void D3_898F0(void* p) { if (p) func_001BE5A0(p, 0); }
static inline void D2_898F0(void* p) { if (p) D3_898F0(p); }
static inline void D1_898F0(void* p) { if (p) D2_898F0(p); }
static inline void PD_898F0(void* p) { if (p) __destroy_array(p, (void*)func_0018A210, 8, 7); }
static inline void XInit_898F0(X_898F0* x) { x->kind = 0; MotionTokens_Init(x->pairs); cArray_cTimedEvent_ctor_void(x->tail); }
static inline void XDtor_898F0(X_898F0* p) {
    if (p) {
        void* t = p->tail;
        if (t) { if (t) { if (t) func_001BE5A0(t, 0); } }
        if (p->pairs) __destroy_array(p->pairs, (void*)func_0018A210, 8, 7);
    }
}
static inline void SelInit_898F0(Sel_898F0* s, int v, X_898F0* x) {
    s->mode = 2;
    cString16N_3_ctor_void(s->sub);
    s->f44 = v;
    s->f48 = 3;
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&s->x, x);
    s->f98 = -1.0f;
    s->f9C = 0;
}
static inline void Prio_898F0(char* p, signed char k) {
    unsigned char on;
    char* q = p;
    on = AnimPriority_Helper3(q + 0xC, k);
    AnimPriority_Helper2(q + 4, k, 0);
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}

extern "C" void Actor_Revive(Act_898F0* self)
{
    int out __attribute__((aligned(8))); /* retail slot is 0x2A8, not the top word 0x2AC */
    Y_898F0 y;
    Msg3_898F0 m3;
    Msg1_898F0 m1;
    X_898F0 x;
    Sel_898F0 sel;
    Msg4_898F0 m4;
    Vec4_898F0 vec;
    Vec4_898F0 rate;
    Ev_898F0 e1;
    Ev_898F0 e2;
    Anim_898F0* an;

    Event_Construct(&m1, g_ActorActionMsgClass);
    m1.vtable = D_004E0840;
    m1.kind = 1;
    m1.f24 = 0xA;
    m1.b28 = 0;
    Event_Send(&m1, self, 1);
    m1.vtable = D_004E0840;
    cMessage_dtor(&m1, 0);

    XInit_898F0(&x);
    SelInit_898F0(&sel, self->f326C, &x);
    an = &self->anim;
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    Actor_ResolveMotionSelection(&sel, &out, &y, an->model);
    if (out) {
        Vec4_898F0* r;
        if (an->b5)
            r = &an->v;
        else
            r = AnimRate_Init(&rate, Model_GetFirstFloat(an->model));
        Vec4_Copy_18A350(&vec, r);
        an->b5 = 0;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        AnimCtl_InstallMotion(an, out, MotionRequest_GetMode(&sel), &vec, &y, &e1, &e2, cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(&sel), cSkaRequestStream_AnimationPacket_GetDuration(&sel), func_0018A2C0(&sel));
        AnimEvent_dtor(&e2, -1);
        AnimEvent_dtor(&e1, -1);
    }
    /* spelled differently from &sel.x so the address is not kept in a saved register */
    XDtor_898F0((X_898F0*)((char*)&sel + 0x4C));
    D1_898F0(x.tail);
    PD_898F0(x.pairs);

    Actor_ResetAnimChannels(self);
    if (self->s3310) self->s3310->b11 = 1;
    if (self->s3310) self->s3310->b9C0 = 0;
    Prio_898F0(self->prio, 0x1A);
    Actor_EnterDeadState(self);
    Prio_898F0(self->prio, 0x1F);
    ActionPriority_Reset(self->prio, 0);
    ActionFlags_Clear(self->f3248);
    if (self->s3310) self->s3310->f374 = D_004A03E0;
    ActorModel_Deactivate(self->f60);
    {
        unsigned char r = 0;
        Ctl_898F0* c = self->ctl;
        if (c && c->IsPlayer())
            r = 1;
        if (r && self->b14) {
            Obj_898F0* o;
            self->b33A4 = 1;
            if (g_IsMultiplayer && self->b14 && self->s3584)
                self->s3584->b34 = 1;
            {
                AllocGuard guard;
                o = (Obj_898F0*)Mem_Alloc(0, 0x14, D_0049D8D0, 0x3E38);
            }
            if (o) {
                o->vt = D_004D9DE0;
                o->b4 = 1;
                o->f0 = 0x3E8;
                o->b5 = 0;
                o->vt = D_004DA970;
                o->fC = self;
                o->b10 = 0;
            }
            EventQueue_Admit(o);
            self->b3269 = 1;
        }
    }
    Actor_RequestTeleport(self, Transform_GetUpdated(Object_GetRootNode(self->f33F0)));
    self->b30AC = 0;
    self->f33B0 = 0;
    Actor_Ignite(-1.0f, self, 0, 0, 0, 0);
    Actor_SetHealth(self, self->f3398, 1);
    self->f33A0 = self->f339C;
    cWeapon_SetAmmoPlayerDeath(self->f3524);
    self->f33A8 = 0;
    self->f33AC = 0;
    self->b33A5 = 0;
    Event_Construct(&m3, g_NotifyCheckpointMsgClass);
    m3.vtable = D_004DB8B0;
    Event_Send(&m3, self->ctl, 0);
    Event_Construct(&m4, g_CasEventMsgClass);
    m4.vtable = D_004DA950;
    m4.f2C = 0;
    m4.f24 = 0x11;
    m4.f28 = -1;
    Event_Send(&m4, self->ctl, 0);
    m4.vtable = D_004DA950;
    cMessage_dtor(&m4, 0);
    m3.vtable = D_004DB8B0;
    cMessage_dtor(&m3, 0);
}
