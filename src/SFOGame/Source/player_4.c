/*
 * SFOGame/Source/player: 7 files, 00176EF0-00177380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00176EF0 */
#pragma push /* merge_units */
#include "types.h"

int cSafePtr_cGOBJ_opAssign_cGOBJP(int a0, int a1) {
    int loc[1];
    int v0, v1;
    int cond;

    cond = a1 == 0;
    *(int*)(char*)a0 = a1;
    if (cond) goto L00176F08;
    v0 = a1 + 12;
    goto L00176F18;
L00176F08:;
    v0 = 0 + -1;
    *(int*)(char*)loc = v0;
    v0 = (int)loc;
L00176F18:;
    v1 = *(int*)(char*)v0;
    v0 = a1;
    *(int*)((char*)a0 + 4) = v1;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_00176EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00176EF0 */

/* merge_units: begin func_00176F30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Item: only the slots used here are named (vtable offset in comments). */
struct Item {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int flag); /* +0x5C */
    virtual void Method60(int flag); /* +0x60 */
};

typedef struct cPlayer {
    char pad[0x50];
    int sub50; /* +0x50 */
    char pad54[0x1A0 - 0x54];
    Item* held; /* +0x1A0 */
} cPlayer;

extern "C" void cPlayerControls_InitializeCamera(int* sub, Item* item);

/* Replaces the held item: releases the old one (virtual +0x60), attaches and activates the new one (virtual +0x5C). */
extern "C" void cPlayer_SetCamera(cPlayer* self, Item* item)
{
    if (self->held)
        self->held->Method60(1);
    self->held = item;
    if (item) {
        cPlayerControls_InitializeCamera(&self->sub50, item);
        item->Method5C(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176F30 */

/* merge_units: begin func_00176FA0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Part: only the slots used here are named (vtable offset in comments). */
struct Part {
    virtual void v00();
    virtual void Update(void* arg); /* +0xC */
};

typedef struct PlayerBody {
    char pad[0x2E0];
    Part partA; /* +0x2E0 */
    char pad2E4[0x3A0 - 0x2E4];
    Part partB; /* +0x3A0 */
} PlayerBody;

typedef struct cPlayer_00176FA0 { char pad[0x1A0]; PlayerBody* body; /* +0x1A0 */ } cPlayer_00176FA0;

/* Player virtual 0x12: forwards arg to the two body parts' virtual +0xC. */
extern "C" void cPlayer_CleanUpAfterTeleportationOfGobj(cPlayer_00176FA0* self, void* arg)
{
    PlayerBody* body = self->body;
    body->partA.Update(arg);
    body->partB.Update(arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176FA0 */

/* merge_units: begin func_00176FF0 */
#pragma push /* merge_units */
#include "vslot_pad.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char p0[0x10]; V4 a; V4 b; char p1[0x10]; V4 c; char p2[0x10]; V4 d; char p3[0x10]; V4 e; } O_6FF0;
#define ADD1(D) { V4* d_ = D; asm { lqc2 vf1, 0x0(d_); lqc2 vf2, 0x0(v); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#define ADD2(D) { V4* d_; V4* e_; e_ = D; d_ = D; asm { lqc2 vf1, 0x0(e_); lqc2 vf2, 0x0(v); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cSplinedMotion_cVector_TeleportByDelta(O_6FF0* o, V4* v) {
    ADD1(&o->a)
    ADD2(&o->b)
    ADD2(&o->c)
    ADD1(&o->d)
    ADD1(&o->e)
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176FF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176FF0 */

/* merge_units: begin func_00177060 */
#pragma push /* merge_units */
#pragma cplusplus on
class Obj_7060 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Attach(int on);
    virtual void Detach(int on);
};
struct S_7060 { char pad[0x1A4]; Obj_7060* obj; };
extern "C" {
void nGobjManager_RemoveGOBJ(Obj_7060* o);
void cSystem_ActualScheduleDelete(float t, Obj_7060* o);
void nGobjManager_AddGOBJ(Obj_7060* o);
}
extern "C" void cPlayer_AtmosphericParticleEffect(S_7060* self, Obj_7060* o)
{
    if (self->obj) {
        self->obj->Detach(1);
        nGobjManager_RemoveGOBJ(self->obj);
        cSystem_ActualScheduleDelete(0.1f, self->obj);
        self->obj = 0;
    }
    if (o) {
        self->obj = o;
        nGobjManager_AddGOBJ(o);
        o->Attach(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00177060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00177060 */

/* merge_units: begin func_001770F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    V& operator=(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
} __attribute__((aligned(16)));
struct Mtx { V r[4]; };
struct Sub110 { char pad[0x64]; int* p64; };
struct Ctl3584 { char pad[0x33]; unsigned char b33; };
struct Obj {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual Mtx GetMatrix();
    virtual int GetVec(V* out);
    VPAD4(f) VPAD1(g)
    virtual Sub110* Get110();
    char pad[0x10]; unsigned char b14; char pad15[0x3584 - 0x15]; Ctl3584* p3584;
};
struct Player { char pad[0x30]; Obj* obj; char pad34[0x50 - 0x34]; char input[0x1A0 - 0x50]; int x1A0; char pad1A4[4]; float f1A8; float f1AC; char pad1B0[0x10]; int t1C0; };


extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_00582B88;
extern int g_Hud;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern char D_004E0100[];
int cDME_GetTime(int);
V* cMatrix_GetAxis(Mtx*, int);
float Libc_Atan2f(float, float);
void cMessage_ctor_cMessageNameR(void*, void*);
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
#endif /* merge_units */
unsigned char QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate); /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) ((void)QueueMessage_cMessageR_cSystemP_int((a0), (a1), (a2))) /* merge_units */

void cMessage_dtor(void*, int);
void PlayerInput_Update(void*, int, Obj*, float);
void cPlayerControls_PrintDebugInfoToScreen(void*, int, Obj*);
void cHudRadar_SetDanger(int, int, float);
}

struct MsgBase { void* vt; char pad[0x20]; int x24; unsigned char x28;
    MsgBase(void* n) { cMessage_ctor_cMessageNameR(this, n); vt = D_004E0840; x24 = 0; x28 = 0xD; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgBase() { vt = D_004E0840; cMessage_dtor(this, 0); }
};
static inline float Min(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Payload { V a; V b; float ang; float s; int id;
    Payload(const V& pa, const V& pb, float g, float sc, int i) { Payload* t = this; t->a = pa; t->b = pb; t->ang = g; t->s = Min(sc, 1.0f); t->id = i; }
};
struct Msg : MsgBase { char pad2c[4]; Payload p;
    Msg(const V& pa, const V& pb, float g, float sc, int i) : MsgBase(g_ActorActionMsgClass), p(pa, pb, g, sc, i) { vt = D_004E0100; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Msg() { vt = D_004E0100; }
};
static inline float Yaw(Mtx& m) {
    V r0 = *cMatrix_GetAxis(&m, 0);
    V r1 = *cMatrix_GetAxis(&m, 1);
    float a = r1.z; float b = r0.z; if (b < a) { float x = r0.x; return Libc_Atan2f(r0.y, x); }
    return Libc_Atan2f(-r1.x, r1.y);
}
extern "C" void cPlayer_NextFrame(Player* self, float dt)
{
    if (g_IsMultiplayer) {
        Obj* o = self->obj;
        if (o->b14) {
            if (o && o->p3584)
                o->p3584->b33 = D_00582B88;
            if (self->t1C0 < cDME_GetTime(1)) {
                Mtx m = self->obj->GetMatrix();
                V v;
                const V& pos = m.r[3];
                int id = 0;
                if (!o->GetVec(&v)) {
                    V z; z.x = 0; z.y = 0; z.z = 0; z.w = 0;
                    v = z;
                } else {
                    Sub110* s = o->Get110();
                    if (s) id = *s->p64;
                }
                { Msg msg(pos, v, Yaw(m), 1.0f, id);
                QueueMessage_cMessageR_cSystemP_int(&msg, self->obj, 0); }
                self->t1C0 = cDME_GetTime(1) + 250;
            }
        }
    }
    { Obj* ob = self->obj; PlayerInput_Update(self->input, self->x1A0, ob, dt); }
    { Obj* ob = self->obj; cPlayerControls_PrintDebugInfoToScreen(self->input, self->x1A0, ob); }
    cHudRadar_SetDanger(g_Hud + 0xD0, 1, self->f1AC);
    self->f1A8 = 0;
    self->f1AC = 0;
}
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
static inline void merge_flush_func_001770F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001770F0 */

/* merge_units: begin func_00177380 */
#pragma push /* merge_units */
#pragma cplusplus on
#define CMSG_NO_PROTOS
#define CMSG_KIND_T signed char
#include "cmessage.h"
/* cPlayer_HandleMessage: the player component's message handler (zone enter/leave, pickup
   triggers, teleports, flags); anything else goes to the base receiver. */
struct M4_177380 { float m[16]; } __attribute__((aligned(16)));
struct TMsg_177380 { CMSG_HEADER; signed char mode; char pad25[0xB]; M4_177380 mtx; } __attribute__((aligned(16)));
struct TrigMsg_177380 { CMSG_HEADER; int a24; int a28; int a2C; int a30; int a34; };
struct Msg_177380 { CMSG_HEADER; unsigned char b24; char pad25[3]; int sub; int id; };
/* the same byte read through a signed view: the (unsigned char) compares of case 13 then give
   retail's lbu + move (the function's quad-copy asm keeps the conversion) */
struct MsgS_177380 { CMSG_HEADER; signed char s24; };
struct MsgI_177380 { CMSG_HEADER; int v; };
struct Player_177380 {
    char pad0[0x14];
    unsigned char active;   /* 0x14 */
    char pad15[0x30 - 0x15];
    void* owner;            /* 0x30 */
    char pad34[0x50 - 0x34];
    char input[0x110];      /* 0x50 */
    unsigned char b160;     /* 0x160 */
    char pad161[0x17C - 0x161];
    unsigned char b17C;     /* 0x17C */
    char pad17D[0x180 - 0x17D];
    int f180;               /* 0x180 */
    int f184;               /* 0x184 */
    unsigned char b188;     /* 0x188 */
    char pad189[0x1B8 - 0x189];
    int f1B8;               /* 0x1B8 */
    unsigned char b1BC;     /* 0x1BC */
};
extern "C" {
extern int g_CasEventMsgClass;
extern int D_004EE698;
extern int D_004F53F0;
extern int g_TeleportMsgClass;
extern int D_0055D4D8;
extern int D_004F53F8;
extern int D_004A0318;
extern int D_00588038;
extern char D_004D9360[];
extern char D_004D9DA0[];
extern char D_004DAF10[];
extern char D_004DFD80[];
int* cMessage_Name(void* m);
unsigned char QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
#if 0 /* merge_units */
void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

unsigned char cPlayer_HandleCASEvent(Player_177380* self, void* m);
unsigned char cSystem_HandleMessage(Player_177380* self, void* m);
void cPlayerControls_HandleEnterCrawlBox(void* in, void* owner);
void cPlayerControls_HandleExitCrawlBox(void* in, void* owner);
void cPlayerControls_HandleEnterJumpBox(void* in, int kind, int* id);
void cPlayerControls_HandleExitJumpBox(void* in);
void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
int PlayerInput_IsPickupMenuForZone(void* in, void* zone);
void cPlayerControls_KillPickup(void* in);
void cGOBJTriggerEventMsg_ctor(void* m, int a, int b, void* c, int d);
unsigned char cPlayer_HandleMessage(Player_177380* self, Msg_177380* m);
}

unsigned char cPlayer_HandleMessage(Player_177380* self, Msg_177380* m)
{
    int jid;
    int oid;
    TrigMsg_177380 trig;
    TMsg_177380 m1;
    TMsg_177380 m2;
    int t;
    int sub;
    t = *cMessage_Name(m);
    if (t == g_CasEventMsgClass)
        return cPlayer_HandleCASEvent(self, m);
    t = *cMessage_Name(m);
    if (t == D_004EE698) {
        sub = m->sub;
        switch (sub) {
        case 8:
        case 10:
        case 11:
        case 12:
        case 14:
        case 17:
            break;
        case 9:
            switch (m->b24) {
            case 0:
                cPlayerControls_HandleEnterCrawlBox(self->input, self->owner);
                break;
            case 2:
                cPlayerControls_HandleExitCrawlBox(self->input, self->owner);
                break;
            }
            break;
        case 15:
        case 16:
            switch (m->b24) {
            case 0:
                jid = m->id;
                { int* pj = &jid; bool b = sub == 16; cPlayerControls_HandleEnterJumpBox(self->input, b ? 2 : 1, pj); }
                break;
            case 2:
                cPlayerControls_HandleExitJumpBox(self->input);
                break;
            }
            break;
        case 18: {
            void* o;
            oid = m->id;
            o = nGobjManager_LookupGOBJ_cObjectIdR(&oid);
            if (o) {
                /* retail reads the word and masks it (lw + andi 0xff) */
                int k = ((MsgI_177380*)m)->v;
                k &= 0xFF;
                if (k == 2) {
                    if (PlayerInput_IsPickupMenuForZone(self->input, o))
                        cPlayerControls_KillPickup(self->input);
                } else if (k == 0) {
                    if (self->active) {
                        self->b17C = 0;
                        self->b1BC = 1;
                        { void* ow = self->owner; cGOBJTriggerEventMsg_ctor(&trig, 4, m->id, ow, 0); }
                        trig.kind = 1;
                        QueueMessage_cMessageR_cSystemP_int(&trig, o, 1);
                        trig.vtable = D_004DAF10;
                        cMessage_dtor(&trig, 0);
                    }
                }
            }
            break;
        }
        case 13:
            if ((unsigned char)((MsgS_177380*)m)->s24 == 0)
                self->f184++;
            else if ((unsigned char)((MsgS_177380*)m)->s24 == 2)
                self->f184--;
            break;
        }
        return 0;
    }
    t = *cMessage_Name(m);
    if (t == D_004F53F0) {
        self->b160 = !self->b160;
        return 1;
    }
    t = *cMessage_Name(m);
    if (t == g_TeleportMsgClass) {
        void* tg = self->owner;
        if (tg) {
            unsigned char r;
            {
                TMsg_177380* p = &m1;
                TMsg_177380* s = (TMsg_177380*)m;
                __int128 qa;
                __int128 qb;
                p->vtable = D_004DFD80;
                p->type = s->type;
                p->magic = s->magic;
                p->time = s->time;
                p->unk10 = s->unk10;
                p->target = s->target;
                p->stampKind = s->stampKind;
                p->flags = s->flags;
                p->kind = s->kind;
                p->vtable = D_004D9360;
                p->mode = s->mode;
                /* 64-byte matrix copy as an lq/sq interleave (128-bit GPR moves, not expressible in C) */
                __asm__ volatile(
                "lq %0, 0x0(%3)\n"
                "lq %1, 0x10(%3)\n"
                "sq %0, 0x0(%2)\n"
                "lq %0, 0x20(%3)\n"
                "sq %1, 0x10(%2)\n"
                "lq %1, 0x30(%3)\n"
                "sq %0, 0x20(%2)\n"
                "sq %1, 0x30(%2)"
                : "=&r"(qa), "=&r"(qb) : "r"(&p->mtx), "r"(&s->mtx) : "memory");
            }
            r = QueueMessage_cMessageR_cSystemP_int(&m1, tg, 1);
            m1.vtable = D_004D9360;
            cMessage_dtor(&m1, 0);
            return r;
        }
        return 0;
    }
    t = *cMessage_Name(m);
    if (t == D_0055D4D8) {
        void* tg = self->owner;
        if (tg) {
            unsigned char r;
            {
                TMsg_177380* p = &m2;
                TMsg_177380* s = (TMsg_177380*)m;
                __int128 qa;
                __int128 qb;
                p->vtable = D_004DFD80;
                p->type = s->type;
                p->magic = s->magic;
                p->time = s->time;
                p->unk10 = s->unk10;
                p->target = s->target;
                p->stampKind = s->stampKind;
                p->flags = s->flags;
                p->kind = s->kind;
                p->vtable = D_004D9DA0;
                p->mode = s->mode;
                /* 64-byte matrix copy as an lq/sq interleave (128-bit GPR moves, not expressible in C) */
                __asm__ volatile(
                "lq %0, 0x0(%3)\n"
                "lq %1, 0x10(%3)\n"
                "sq %0, 0x0(%2)\n"
                "lq %0, 0x20(%3)\n"
                "sq %1, 0x10(%2)\n"
                "lq %1, 0x30(%3)\n"
                "sq %0, 0x20(%2)\n"
                "sq %1, 0x30(%2)"
                : "=&r"(qa), "=&r"(qb) : "r"(&p->mtx), "r"(&s->mtx) : "memory");
            }
            r = QueueMessage_cMessageR_cSystemP_int(&m2, tg, 1);
            m2.vtable = D_004D9DA0;
            cMessage_dtor(&m2, 0);
            return r;
        }
        return 0;
    }
    t = *cMessage_Name(m);
    if (t == D_004F53F8) {
        self->f1B8 = ((MsgI_177380*)m)->v;
        return 1;
    }
    t = *cMessage_Name(m);
    if (t == D_004A0318) {
        self->f180 = ((MsgI_177380*)m)->v;
        return 1;
    }
    t = *cMessage_Name(m);
    if (t == D_00588038) {
        self->b188 = m->b24;
        return 1;
    }
    return cSystem_HandleMessage(self, m);
}
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00177380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00177380 */
