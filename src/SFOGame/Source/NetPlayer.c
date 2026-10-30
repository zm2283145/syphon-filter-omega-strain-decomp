/*
 * SFOGame/Source/NetPlayer: 9 files, 002D7C80-002D8570
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D7C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "player_ctl_level.h"

/* Controller level of the player, -1 without an active controller. */
DEFINE_PLAYER_CTL_LEVEL(cNetPlayer_Team)
static inline void merge_flush_func_002D7C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7C80 */

/* merge_units: begin func_002D7D10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "cmessage.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct Msg : CMsg { int a24; unsigned char a28; char p29[7]; };
struct Msg2 : Msg { int val; int id; unsigned char m38; char p39[7]; V4 v; float f50; char p54[0xC]; };
struct Info { unsigned char dead; char p1[7]; int val; signed char id; };
struct Obj { char p0[0x44]; Info* info; char p48[4]; void* target; };
extern "C" {
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0200[];
extern signed char D_004E1D88;
extern V4 D_004E1D90;
}
static inline const V4& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return D_004E1D90;
}
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void cNetPlayer_WeaponShoot(Obj* o)
{
    Info* in = o->info;
    if (in) {
        Msg2* m; int id = in->id;
        int val[1]; val[0] = in->dead ? -1 : in->val;
        Msg2 msg;
        m = &msg;
        cMessage_ctor_cMessageNameR(m, g_ActorActionMsgClass);
        m->vtable = D_004E0840;
        m->a24 = 0x3B;
        m->a28 = 0xB;
        m->vtable = D_004E0200;
        {
            const V4* z = &Zero();
            m->val = val[0];
            m->id = id;
            m->m38 = 0;
            V4_Copy(&m->v, z);
            m->f50 = 0.0f;
        }
        QueueMessage_cMessageR_cSystemP_int(&msg, o->target, 0);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
}
static inline void merge_flush_func_002D7D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7D10 */

/* merge_units: begin func_002D7E40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cNetPlayer_NoticeDeath(void) {
}
static inline void merge_flush_func_002D7E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7E40 */

/* merge_units: begin func_002D7E50 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct M_7E50 { __int128 q[4]; } M_7E50;
typedef struct N_7E50 { char pad[0x4C]; char* p30; } N_7E50;
extern "C" void cMan_GetGunBarrelMatrix(M_7E50* out, void* p, unsigned char f);

extern "C" int func_002D7E50(N_7E50* self, M_7E50* out, int flag)
{
    M_7E50 tmp; int r;
    __int128 qa; __int128 qb; M_7E50* s;
    /* asm { .set reorder } is an empty barrier that keeps the branchy bool (known trick) */
    { unsigned short f; if (flag) { f = 1; asm { .set reorder } } else f = 0; cMan_GetGunBarrelMatrix(&tmp, self->p30 + 0x60, f); }
    s = &tmp; r = 1;
    asm {
        .set noreorder
        lq qa, 0x0(s)
        lq qb, 0x10(s)
        sq qa, 0x0(out)
        lq qa, 0x20(s)
        sq qb, 0x10(out)
        lq qb, 0x30(s)
        sq qa, 0x20(out)
        sq qb, 0x30(out)
        .set reorder
    }
    return r;
}
static inline void merge_flush_func_002D7E50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7E50 */

/* merge_units: begin func_002D7ED0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNetPlayer_AimWeapon: objective-marker update - tell the marker's target to show the tracked actor
   (or the fixed objective position once done), or to hide, then refresh the marker if its
   objective state changed. */
struct NetPlayerAimVec4 { float x, y, z, w; NetPlayerAimVec4() {} NetPlayerAimVec4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
struct Info_002D7ED0 { unsigned char dead; char p1[0xB]; signed char id; char pD[3]; float x, y, z; };
struct Flags { char p0[5]; unsigned char b5; };
struct Act { char p0[0xC]; int serial; char p10[0x1C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; int& Serial() { return serial; } };
struct Obj_002D7ED0 { char p0[0x44]; Info_002D7ED0* info; Flags* flags; void* target; };
extern "C" {
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E01A0[], D_004E0200[], D_004E0140[], D_004D9320[];
extern unsigned char D_0048C428[], D_0048C430[];
#if 0 /* merge_units */
extern NetPlayerAimVec4 D_004E1D90;
#endif /* merge_units */
#define D_004E1D90 (*(NetPlayerAimVec4*)&D_004E1D90) /* merge_units */

int cAimWeapon_GetFireWeapon(Flags* f);
#if 0 /* merge_units */
void cNetPlayer_WeaponShoot(Obj_002D7ED0* o);
#endif /* merge_units */
#define cNetPlayer_WeaponShoot(a0) (cNetPlayer_WeaponShoot((Obj *)(a0))) /* merge_units */

void cNetPlayer_AimWeapon(Obj_002D7ED0* o, Act* a);
}
static inline const NetPlayerAimVec4& Zero_002D7ED0()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return D_004E1D90;
}
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy_002D7ED0(NetPlayerAimVec4* d, const NetPlayerAimVec4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgI : MsgB {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};
static inline const int& Serial(Act* a) { return a->serial; }
struct MsgSerial : MsgI { int serial; MsgSerial(const int& s) : MsgI(62, 5) { vtable = D_004E01A0; serial = s; } __declspec(weak) __declspec(MSG_DTOR) ~MsgSerial() {} };
struct MsgTrack : MsgI { int pad2C; int val; int id; unsigned char m38; char p39[7]; NetPlayerAimVec4 v; float f50; char p54[0xC];
    MsgTrack(const int& s, int i) : MsgI(57, 11) { vtable = D_004E0200; { const NetPlayerAimVec4* z = &Zero_002D7ED0(); val = s; id = i; m38 = 0; V4_Copy_002D7ED0(&v, z); f50 = 0.0f; } } __declspec(weak) __declspec(MSG_DTOR) ~MsgTrack() {} };
struct MsgPos : MsgI { int pad2C; NetPlayerAimVec4 v; MsgPos(const NetPlayerAimVec4& p) : MsgI(57, 4) { vtable = D_004E0140; V4_Copy_002D7ED0(&v, &p); } __declspec(weak) __declspec(MSG_DTOR) ~MsgPos() {} };
/* the message ctors take references: MW binds them lazily, so the loads land after cMessage_ctor_cMessageNameR as in retail */
struct MsgHide : MsgI { unsigned char b; char p2D[3]; MsgHide(const unsigned char& x) : MsgI(57, 1) { vtable = D_004D9320; b = x; } __declspec(weak) __declspec(MSG_DTOR) ~MsgHide() {} };

static inline unsigned char Alive(Act* a)
{
    unsigned char r = 0;
    unsigned char f = 0;
    if (a->b2D && a->b2C)
        f = 1;
    if (f && ((a->b2E != 0) ^ 1))
        r = 1;
    return r;
}

void cNetPlayer_AimWeapon(Obj_002D7ED0* o, Act* a)
{
    if (o->info && ((a && Alive(a)) || o->info->dead) && o->flags) {
        if (o->info->dead || (o->flags->b5 && a)) {
            if (!o->info->dead) {
                {
                    MsgSerial m(a->Serial());
                    QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
                }
                {
                    MsgTrack m(a->Serial(), o->info->id);
                    QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
                }
            } else {
                {
                    MsgI m(63, 0);
                    QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
                }
                {
                    NetPlayerAimVec4 pos(o->info->x, o->info->y, o->info->z, 1.0f);
                    {
                        MsgPos m(pos);
                        QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
                    }
                }
            }
        } else {
            {
                MsgI m(63, 0);
                QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
            }
            {
                MsgHide m(D_0048C428[0]);
                QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
            }
        }
    } else {
        {
            MsgI m(63, 0);
            QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
        }
        {
            MsgHide m(D_0048C430[0]);
            QueueMessage_cMessageR_cSystemP_int(&m, o->target, 1);
        }
    }
    if (o->flags && cAimWeapon_GetFireWeapon(o->flags))
        cNetPlayer_WeaponShoot(o);
}
#undef D_004E1D90 /* merge_units */
#undef cNetPlayer_WeaponShoot /* merge_units */
static inline void merge_flush_func_002D7ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7ED0 */

/* merge_units: begin func_002D83B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cNetPlayer_HandleMessage(void) {
    return 0;
}
static inline void merge_flush_func_002D83B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D83B0 */

/* merge_units: begin func_002D83C0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
#include "vslot_pad.h"
struct HuB { char pad[0x1C]; };
struct HuC { int a; short pad; short id; short Id() { return id; } };
struct HuItem : HuB, HuC {};
struct HuSlot { int a, b, id, c; };
struct HuInv {
    HuSlot slots[8];
    char pad80[4];
    unsigned char cur;
    int CurId() { return cur != 6 ? slots[cur].id : -1; }
};
struct HuOwner { char pad[0x3524]; HuInv* inv; char pad3528[0x3584 - 0x3528]; HuItem* item; };
struct HuTarget {
    VPAD32(a) VPAD32(b)
    virtual unsigned char State();
    char pad4[0x2C - 4];
    unsigned char b2C, b2D, b2E;
    bool IsActive() { return b2D && b2C && !b2E; }
};
struct HuRef { char pad[8]; int id; };
struct HuSelf {
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void Select(HuTarget* t, int id, int n);
    char pad4[0x40];
    HuItem* ref;
    HuC* item;
    HuOwner* owner;
};
extern "C" {
HuTarget* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void cWeapon_Select(HuInv* inv, int id);
#if 0 /* merge_units */
void cNetPlayer_AimWeapon(HuSelf* s, HuTarget* t);
#endif /* merge_units */
#define cNetPlayer_AimWeapon(a0, a1) (cNetPlayer_AimWeapon((Obj_002D7ED0 *)(a0), (Act *)(a1))) /* merge_units */


}
extern "C" void cNetPlayer_NextFrame(HuSelf* s)
{
    HuTarget* t = 0;
    if (!s->ref) {
        HuItem* it = s->owner->item;
        if (it)
            s->ref = it;
    }
    if (!s->item) {
        HuItem* it = s->owner->item;
        if (it)
            s->item = it;
    }
    if (s->ref && s->item) {
        HuInv* inv = s->owner->inv;
        short id = s->item->Id();
        int cur = inv->CurId();
        if (cur != id)
            cWeapon_Select(inv, id);
    }
    if (s->ref) {
        int id = ((HuRef*)s->ref)->id;
        HuTarget* p;
        if ((p = nGobjManager_LookupGOBJ_cObjectIdR(&id)) != 0) {
            t = p;
            if (t->State() != 3 && t->IsActive())
                s->Select(t, s->owner->inv->CurId(), -1);
            else
                t = 0;
        }
    }
    cNetPlayer_AimWeapon(s, t);
}
#undef cNetPlayer_AimWeapon /* merge_units */
static inline void merge_flush_func_002D83C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D83C0 */

/* merge_units: begin func_002D8570 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Actor_VirtualNop1753D0();
extern "C" void Actor_VirtualNop1753E0();
extern "C" void cGameGobjController_SetGobj();
extern "C" void cGameGobjController_GetVelocity();
extern "C" void cGameGobjController_Enemy_cGOBJP();
extern "C" void cGameGobjController_Enemy_int();
extern "C" void cGameGobjController_UpdateToHitProbability();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cSystem_IsNetworked();
extern "C" void cGobjController_IsNPC();
extern "C" void cGobjController_IsNetNPC();
extern "C" void func_0015B820();
extern "C" void cGobjController_CleanUpAfterTeleportationOfGobj();
extern "C" void cGobjController_GetCopyMsg();
extern "C" void cGobjController_NoticeEnvironmentalDanger();
extern "C" void func_0016F9E0();
extern "C" void PlayerComp_OnHitNop();
extern "C" void PlayerComp_GetDeathCode();
extern "C" void func_0016FA20();
extern "C" void func_001753F0();
extern "C" void cGameGobjController_v0B();
extern "C" void cGameGobjController_ScriptHandleMessage();
extern "C" void cNetPlayer_GetControllerType();
extern "C" void cNetPlayer_IsPlayer();
struct PlyCtlLevelObj;
extern "C" int cNetPlayer_Team(PlyCtlLevelObj*);
#if 0 /* merge_units */
extern "C" void cNetPlayer_NoticeDeath();
#endif /* merge_units */
#define cNetPlayer_NoticeDeath() (cNetPlayer_NoticeDeath()) /* merge_units */

struct N_7E50; struct M_7E50;
#if 0 /* merge_units */
extern "C" int func_002D7E50(N_7E50*, M_7E50*, int);
#endif /* merge_units */
#define func_002D7E50(a0, a1, a2) (func_002D7E50((a0), (a1), (a2))) /* merge_units */

extern "C" int cNetPlayer_HandleMessage(void);
struct HuSelf;
#if 0 /* merge_units */
extern "C" void cNetPlayer_NextFrame(HuSelf*);
#endif /* merge_units */
#define cNetPlayer_NextFrame(a0) (cNetPlayer_NextFrame((a0))) /* merge_units */

extern "C" void cGobjController_WantsToBeActive();
extern "C" void cGobjController_ScriptGetObjectId();
extern void * const D_004DE530[];
void* cGameGobjController_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cNetPlayer_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DE530);
        cGameGobjController_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE530[40] = { (void*)0x0, (void*)0x0, (void*)cNetPlayer_dtor, (void*)cNetPlayer_HandleMessage, (void*)cGobjController_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGameGobjController_v0B, (void*)cGameGobjController_ScriptHandleMessage, (void*)func_0016F9E0, (void*)cNetPlayer_NextFrame, (void*)cGobjController_WantsToBeActive, (void*)Actor_VirtualNop1753D0, (void*)Actor_VirtualNop1753E0, (void*)func_0015B820, (void*)cNetPlayer_IsPlayer, (void*)cGobjController_IsNPC, (void*)cGobjController_IsNetNPC, (void*)cGameGobjController_UpdateToHitProbability, (void*)func_002D7E50, (void*)cNetPlayer_Team, (void*)cGameGobjController_Enemy_int, (void*)cGameGobjController_Enemy_cGOBJP, (void*)cGameGobjController_GetVelocity, (void*)PlayerComp_OnHitNop, (void*)cNetPlayer_NoticeDeath, (void*)cGobjController_CleanUpAfterTeleportationOfGobj, (void*)PlayerComp_GetDeathCode, (void*)cNetPlayer_GetControllerType, (void*)cGameGobjController_SetGobj, (void*)func_0016FA20, (void*)cGobjController_GetCopyMsg, (void*)func_001753F0, (void*)cGobjController_NoticeEnvironmentalDanger };
#undef cNetPlayer_NoticeDeath /* merge_units */
#undef func_002D7E50 /* merge_units */
#undef cNetPlayer_NextFrame /* merge_units */
static inline void merge_flush_func_002D8570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D8570 */

/* merge_units: begin func_002D85D0 */
#pragma push /* merge_units */
typedef struct { char p0[0x3584]; char* sub; } Own2D85D0;
typedef struct { void* vt; char p4[0x40]; char* p44; char* p48; Own2D85D0* owner; short h50; } C2D85D0;
#if 0 /* merge_units */
extern char D_004DE530[];
#endif /* merge_units */
#define D_004DE530 ((char*)&D_004DE530) /* merge_units */


extern void cGameGobjController_ctor(C2D85D0* c);
/* Component constructor: binds the owner and caches its sub-object. */
C2D85D0* cNetPlayer_ctor(C2D85D0* c, char* a, Own2D85D0* owner)
{
    cGameGobjController_ctor(c);
    c->vt = D_004DE530;
    c->p44 = a;
    c->p48 = 0;
    c->owner = owner;
    c->h50 = 0;
    if (c->owner && c->owner->sub) {
        if (!c->p44) c->p44 = c->owner->sub;
        { char* p = c->owner->sub; if (p) p += 0x1C; c->p48 = p; }
    }
    return c;
}
#undef D_004DE530 /* merge_units */
static inline void merge_flush_func_002D85D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D85D0 */
