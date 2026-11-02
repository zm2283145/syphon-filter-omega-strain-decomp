/*
 * SFOGame/Source/GameGOBJ: 4 files, 00213A60-00213B20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00213A60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cElevatorNotice_dtor, D_004DAED0, cMessage_dtor)
static inline void merge_flush_func_00213A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00213A60 */

/* merge_units: begin func_00213AC0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef struct Link { int head; } Link;

/* Virtual-call view of Target: only the slots used here are named (vtable offset in comments). */
struct Target {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F();
    virtual int Method88(); /* +0x88 */
    char pad04[0x68 - 4];
    Link* link; /* +0x68 */
    bool HasItems() { return link->head != 0; }
};

typedef struct Holder {
    char pad[0x60];
    unsigned char enabled; /* +0x60 */
    char pad61[3];
    Target* target; /* +0x64 */
} Holder;

static inline bool IsReady(Holder* self)
{
    return self->enabled && self->target->HasItems();
}

/* Returns the target's virtual +0x88 result when enabled and its link is non-empty, else 0. */
#pragma optimization_level 3
extern "C" int cGameGOBJ_GetBBox(Holder* self)
{
    if (!IsReady(self))
        return 0;
    return self->target->Method88();
}
#pragma optimization_level reset
static inline void merge_flush_func_00213AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00213AC0 */

/* merge_units: begin func_00213B20 */
#pragma push /* merge_units */
typedef struct { char d[0x9C]; } LdStr_00213B20;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    LdStr_00213B20 s78;
    LdStr_00213B20 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) LdSnd_00213B20;
typedef struct {
    void* vt;
    char pad4[0x74];
    LdStr_00213B20 s78;
    LdStr_00213B20 s114;
    char pad1B0[0x20];
} LdSnd2_00213B20;
typedef struct { void* vtable; char base[0x20]; int kind; int arg; } LdMsg_00213B20;
typedef struct { char pad[0x150]; char preset[0x2E0 - 0x150]; char action[1]; } Lift_00213B20;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_004F5448[];
extern char D_004DAED0[];
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern void cStopSoundMsg_ctor_cSndFxR_cGOBJP(LdSnd2_00213B20* e, void* action, Lift_00213B20* l);
extern void cElevatorGOBJ_EnableCallboxes(Lift_00213B20* l);
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(LdMsg_00213B20* m, void* type);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
#if 0 /* merge_units */
extern void cMessage_dtor(void* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

extern void cPlaySoundMsg_ctor_cSndFxR(LdSnd_00213B20* e, void* preset, Lift_00213B20* l);
extern void cFileMan_dtor(LdStr_00213B20* s, int flag);
void cElevatorGOBJ_DoorlessArrive(Lift_00213B20* l)
{
    LdSnd_00213B20 ev;
    LdSnd2_00213B20 ev1;
    LdMsg_00213B20 msg;
    cStopSoundMsg_ctor_cSndFxR_cGOBJP(&ev1, l->action, l);
    QueueMessage_cMessageR_cSystemP_int(&ev1, g_Game, 1);
    ev1.vt = D_004DADF0;
    cFileMan_dtor(&ev1.s114, -1);
    cFileMan_dtor(&ev1.s78, -1);
    cMessage_dtor(&ev1, 0);
    cPlaySoundMsg_ctor_cSndFxR(&ev, l->preset, l);
    ev.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
    if (!g_IsMultiplayer || (g_IsMultiplayer ? D_005721C0 : 1)) {
        cMessage_ctor_cMessageNameR(&msg, D_004F5448);
        msg.vtable = D_004DAED0;
        msg.kind = 0;
        msg.arg = 0;
        QueueMessage_cMessageR_cSystemP_int(&msg, l, 0);
        msg.vtable = D_004DAED0;
        cMessage_dtor(&msg, 0);
    }
    cElevatorGOBJ_EnableCallboxes(l);
    ev.vt = D_004DAE30;
    cFileMan_dtor(&ev.s114, -1);
    cFileMan_dtor(&ev.s78, -1);
    cMessage_dtor(&ev, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00213B20(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00213B20 */

/* merge_units: begin func_00213C70 */
#pragma push /* merge_units */
typedef struct { void* vt; char base[0x1C]; unsigned char action; char pad21[3]; int floor; unsigned char locked; char pad29[3]; } LiftMsg_f4;
typedef struct { char pad[0x10]; int transport; char pad14[0xF8]; int nfloors; int* locks; } Lift_f4;
extern char D_004F54C8[];
extern void cMessage_getSOBJClassId();
extern void cNetLockElevatorMsg_Pack();
extern void cNetLockElevatorMsg_dtor();
extern void cNetLockElevatorMsg_Clone();
void * const D_004DAEF0[8] = { (void*)0x0, (void*)0x0, (void*)cNetLockElevatorMsg_dtor, (void*)cNetLockElevatorMsg_Clone, (void*)cNetLockElevatorMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(LiftMsg_f4*, void*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


extern void cNetObj_SendMessage_int_cMessageR_int_int(int, LiftMsg_f4*, int, int);
#if 0 /* merge_units */
extern void cMessage_dtor(LiftMsg_f4*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


#pragma opt_strength_reduction off
int cElevatorGOBJ_SendCreated(Lift_f4* self, void* dest)
{
    LiftMsg_f4 msg;
    int i;
    for (i = 0; i != self->nfloors; i++) {
        if (self->locks[i] != 0) {
            cMessage_ctor_cMessageNameR(&msg, D_004F54C8);
            msg.vt = ((char*)D_004DAEF0);
            msg.floor = i;
            msg.locked = 1;
            msg.action = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(self->transport, &msg, 0, (int)(void*)dest);
            msg.vt = ((char*)D_004DAEF0);
            cMessage_dtor(&msg, 0);
        }
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00213C70(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00213C70 */
