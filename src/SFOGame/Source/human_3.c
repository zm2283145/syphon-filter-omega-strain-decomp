/*
 * SFOGame/Source/human: 12 files, 00185210-00185630
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00185210 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cCharActionMsg_Int_dtor_void_2, D_004DA9D0, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_00185210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00185210 */

/* merge_units: begin func_00185280 */
#pragma push /* merge_units */
#pragma cplusplus on
#define B7V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
struct B7_GObj {
    char pad0[0x4C];
    int type;
};
struct B7_Human {
    B7V8(a) B7V8(b) B7V8(c) B7V8(d) B7V8(e) B7V8(f) B7V8(g) B7V8(h)
    virtual unsigned char GetState(); /* +0x108 */
    char pad4[0x33BC - 4];
    float health;
};
#if 0 /* merge_units */
extern "C" B7_GObj* cGOBJ_SOBJ_convert(int id);
#endif /* merge_units */
extern "C" void* cGOBJ_SOBJ_convert(int); /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((B7_GObj *)cGOBJ_SOBJ_convert((a0))) /* merge_units */

extern "C" int g_HumanActorClassKey;
extern "C" void cHuman_Shock(B7_Human* o, float a, float b, int c, int d);
extern "C" int Script_ShockToDeath(int* args)
{
    B7_GObj* o = cGOBJ_SOBJ_convert(args[0]);
    if (o && o->type == g_HumanActorClassKey) {
        B7_Human* h = (B7_Human*)o;
        unsigned char s = h->GetState();
        bool dying = (s == 2 || s == 3);
        if (!dying && h->health < 0.0f) {
            cHuman_Shock(h, 0.5f, 10000.0f, 1, 1);
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185280(void) {}
#undef cGOBJ_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00185280 */

/* merge_units: begin func_00185330 */
#pragma push /* merge_units */
typedef struct { char pad[0x3524]; void* weapons; } H_185330;
typedef struct { char pad[0x30]; H_185330* player; } G_185330;
extern G_185330* g_LocalPlayer;
extern void cWeapon_RemoveAllWeapons(void* w);
extern void cWeapon_Add(void* w, int id, int a, int b, int c, int d);
extern int cWeapon_GetWeaponSlot(int id);
extern void cWeapon_DrawWeapon_eWpnSlot(void* w, int slot);
int Script_SetPlayerWeapons(int* args)
{
    volatile int b;
    volatile int a;
    int pa;
    int pb;
    void* w;
    b = args[1];
    pb = b;
    a = args[0];
    pa = a;
    w = g_LocalPlayer->player->weapons;
    cWeapon_RemoveAllWeapons(w);
    if (pa > -1) cWeapon_Add(w, pa, 1, 0, 1, 0);
    if (pb > -1) {
        cWeapon_Add(w, pb, 1, 0, 1, 0);
        if (pa < 0) pa = pb;
    }
    if (pa >= 0) cWeapon_DrawWeapon_eWpnSlot(w, cWeapon_GetWeaponSlot(pa));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185330 */

/* merge_units: begin func_00185410 */
#pragma push /* merge_units */
typedef struct { void* vtable; char base[0x18]; int size; unsigned char kind; char pad[0xF]; } Msg_5410;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; int holster; } Hum_5410;
#if 0 /* merge_units */
int cMessage_ctor_cMessageNameR(Msg_5410*, void*);
#endif /* merge_units */
int cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

int QueueMessage_cMessageR_cSystemP_int(Msg_5410*, void*, int);
#if 0 /* merge_units */
Hum_5410* cGOBJ_SOBJ_convert(int);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((Hum_5410 *)cGOBJ_SOBJ_convert((a0))) /* merge_units */

int cWeapon_ForceHolster(int);
#if 0 /* merge_units */
int cMessage_dtor(Msg_5410*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int g_HumanActorClassKey;
#endif /* merge_units */
#define g_HumanActorClassKey (*(int*)&g_HumanActorClassKey) /* merge_units */

extern char D_004DA9B0[];
extern char D_004DCF10[];
extern char D_004EF030[];
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
static inline unsigned char IsLocal_5410(void) { unsigned char v; if (g_IsMultiplayer) v = D_005721C0; else v = 1; return v; }
static inline void Holster_5410(Hum_5410* selfp) {
    Msg_5410 msg;
    Hum_5410* self = selfp;
    cWeapon_ForceHolster(self->holster);
    if (g_IsMultiplayer) {
        if (IsLocal_5410()) {
            cMessage_ctor_cMessageNameR(&msg, D_004EF030);
            msg.vtable = D_004DA9B0;
            msg.size = 0x40;
            msg.kind = 8;
            QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
            msg.vtable = D_004DCF10;
            cMessage_dtor(&msg, 0);
        }
    }
}
/* script: force the target human to holster; notify when networked and local */
#pragma push
#pragma opt_propagation off
int Script_ForceHolster(int* args)
{
    Hum_5410* g = cGOBJ_SOBJ_convert(args[0]);
    if (g && g->classKey == g_HumanActorClassKey) Holster_5410(g);
    return 0;
}
#pragma pop
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cGOBJ_SOBJ_convert /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef g_HumanActorClassKey /* merge_units */
static inline void merge_flush_func_00185410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00185410 */

/* merge_units: begin func_001854E0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetForceHolsterMsg_dtor, D_004DA9B0, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_001854E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001854E0 */

/* merge_units: begin func_00185550 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* weapons; } G_185550;
typedef union { int i; unsigned char b; } A_185550;
#if 0 /* merge_units */
extern int g_HumanActorClassKey;
#endif /* merge_units */
#define g_HumanActorClassKey (*(int*)&g_HumanActorClassKey) /* merge_units */

#if 0 /* merge_units */
extern G_185550* cGOBJ_SOBJ_convert(int handle);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((G_185550 *)cGOBJ_SOBJ_convert((a0))) /* merge_units */

extern void cWeapon_SetHardpointVisibility(void* w, unsigned char hp, unsigned char vis);
int Script_SetHardpointVis(A_185550* args)
{
    unsigned char vis = args[2].i != 0;
    unsigned char hp = args[1].b;
    G_185550* g = cGOBJ_SOBJ_convert(args[0].i);
    if (g && g->classKey == g_HumanActorClassKey) cWeapon_SetHardpointVisibility(g->weapons, hp, vis);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185550(void) {}
#undef g_HumanActorClassKey /* merge_units */
#undef cGOBJ_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00185550 */

/* merge_units: begin func_001855C0 */
#pragma push /* merge_units */
typedef struct { int pad0; int pad4; int id; int padC; } Slot_1855C0;
typedef struct { Slot_1855C0 s[8]; char pad80[4]; unsigned char cur; } W_1855C0;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; W_1855C0* weapons; } G_1855C0;
#if 0 /* merge_units */
extern G_1855C0* cGOBJ_SOBJ_convert(int handle);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((G_1855C0 *)cGOBJ_SOBJ_convert((a0))) /* merge_units */


int Script_GetActiveWeapon(int* args)
{
    volatile int r;
    G_1855C0* g = cGOBJ_SOBJ_convert(args[0]);
    int v = -1;
    if (g && g->classKey == g_HumanActorClassKey) {
        W_1855C0* w = g->weapons;
        v = (w->cur != 6) ? w->s[w->cur].id : -1;
    }
    r = v;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001855C0(void) {}
#undef cGOBJ_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001855C0 */

/* merge_units: begin func_00185630 */
#pragma push /* merge_units */
#include "vslot_pad.h"
#include "net_local_id.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { void* vtable; char base[0x18]; int size; char pad20[4]; unsigned char holster; char pad25[0xB]; } Msg_185630;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* weapons; } G_185630;
#if 0 /* merge_units */
extern int g_HumanActorClassKey;
#endif /* merge_units */
#define g_HumanActorClassKey (*(int*)&g_HumanActorClassKey) /* merge_units */

extern signed char* D_005061D0;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_185630* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_185630* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cWeapon_ForceHolster(void* w);
#endif /* merge_units */
#define cWeapon_ForceHolster(a0) ((void)cWeapon_ForceHolster((int)(a0))) /* merge_units */

void cNetForceHolsterMsg_NetReceive(G_185630* g)
{
    Msg_185630 msg;
    cMessage_ctor_cMessageNameR(&msg, D_004EF030);
    msg.vtable = D_004DA9B0;
    msg.size = 0x40;
    msg.holster = *D_005061D0++ != 0;
    if (g && g->classKey == g_HumanActorClassKey) cWeapon_ForceHolster(g->weapons);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185630(void) {}
#undef g_HumanActorClassKey /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cWeapon_ForceHolster /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00185630 */

/* merge_units: begin func_001856D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct Ctl_56D0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int isNet(); };
typedef struct { char pad[0xC]; int idC; int id10; char pad14[0x18]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x29]; Ctl_56D0* ctl; } Obj_56D0;
extern "C" {
int cNetObj_IsOwner(int id);
void cNetHuman_CreateNetHuman(void* key, int id);
int cNetObj_AddSystem(int id, int owner, Obj_56D0* o);
}
static inline unsigned char IsNet_56D0(Obj_56D0* o)
{
    unsigned char ok = 0;
    Ctl_56D0* c = o->ctl;
    if (c && c->isNet()) ok = 1;
    return ok;
}
extern "C" void cHuman_InitNetwork(Obj_56D0* o)
{
    if (IsNet_56D0(o)) o->id10 = o->idC;
    else { int v = o->idC; if (v == -1) o->id10 = v; else { o->id10 = v; asm { .set reorder } /* barrier: keeps the identical arms from merging */ } }
    if (IsNet_56D0(o) || cNetObj_IsOwner(o->id10)) {
        int ok = o->b2D != 0;
        ok = ok ? o->b2C != 0 : ok;
        ok = ok ? (o->b2E != 0) ^ 1 : ok;
        if (ok) cNetHuman_CreateNetHuman(&o->idC, o->id10);
    }
    {
        int t = o->id10;
        cNetObj_AddSystem(t, NetLocalId(), o);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001856D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001856D0 */

/* merge_units: begin func_00185840 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
int cNetObj_GetDelayedMsgs(int* a, unsigned char* flag, void** p);
void netCreatePlayer_HandleNetPlayerCreate(void* p, int a);
void netCreateNPC_HandleNetNPCCreate(void* p, int a);
}
extern "C" void cHuman_LoadNetworkData(void)
{
    unsigned char flag;
    void* p;
    int a;
    while (cNetObj_GetDelayedMsgs(&a, &flag, &p)) {
        if (flag) netCreatePlayer_HandleNetPlayerCreate(p, a);
        else netCreateNPC_HandleNetNPCCreate(p, a);
        {
            void* q = p;
            AllocGuard guard;
            cMemMan_Deallocate(0, q, "human.cc", 0x447D);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185840 */

/* merge_units: begin func_00185940 */
#pragma push /* merge_units */
void cHuman_SetNetworkID(int a0, int a1) {
    int v1;
    int cond;

    v1 = 0 + -1;
    cond = a1 != v1;
    if (cond) goto L00185958;
    v1 = *(int*)((char*)a0 + 12);
    *(int*)((char*)a0 + 16) = v1;
    goto L00185960;
L00185958:;
    *(int*)((char*)a0 + 16) = a1;
L00185960:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185940 */

/* merge_units: begin func_00185970 */
#pragma push /* merge_units */
#pragma cplusplus on
class C_185970 { public: VPAD32(a) virtual unsigned char Mode(); char pad4[0x40]; void* t44; void* t48; char pad4C[0x1E0 - 0x4C]; void* t1E0; void* t1E4; };
struct R_185970 { char pad[0x10]; char* target; };
struct O_185970 { char pad[0x58]; C_185970* ctl; char pad5C[0x3584 - 0x5C]; char* target; };
extern "C" void cHuman_SetupNetworkFields(O_185970* o, R_185970* r)
{
    if (r->target) {
        o->target = r->target;
        if (o->ctl->Mode() == 2) {
            o->ctl->t1E0 = r->target;
            { char* x = r->target; if (x) x += 0x1C; o->ctl->t1E4 = x; }
        } else {
            o->ctl->t44 = r->target;
            { char* x = r->target; if (x) x += 0x1C; o->ctl->t48 = x; }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185970 */
