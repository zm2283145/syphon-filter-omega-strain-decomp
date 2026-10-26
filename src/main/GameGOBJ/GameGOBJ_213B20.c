/*
 * main/GameGOBJ: range (2 files, 00213B20-00213C70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

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
extern void SoundStopMsg_Ctor(LdSnd2_00213B20* e, void* action, Lift_00213B20* l);
extern void Lift_ActivateRecipients(Lift_00213B20* l);
extern void Event_Construct(LdMsg_00213B20* m, void* type);
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void SoundEvent_CtorFromPreset(LdSnd_00213B20* e, void* preset, Lift_00213B20* l);
extern void FileMan_Release(LdStr_00213B20* s, int flag);
void Lift_FinishArrival(Lift_00213B20* l)
{
    LdSnd_00213B20 ev;
    LdSnd2_00213B20 ev1;
    LdMsg_00213B20 msg;
    SoundStopMsg_Ctor(&ev1, l->action, l);
    Event_Send(&ev1, g_Game, 1);
    ev1.vt = D_004DADF0;
    FileMan_Release(&ev1.s114, -1);
    FileMan_Release(&ev1.s78, -1);
    cMessage_dtor(&ev1, 0);
    SoundEvent_CtorFromPreset(&ev, l->preset, l);
    ev.flag = 1;
    Event_Send(&ev, g_Game, 1);
    if (!g_IsMultiplayer || (g_IsMultiplayer ? D_005721C0 : 1)) {
        Event_Construct(&msg, D_004F5448);
        msg.vtable = D_004DAED0;
        msg.kind = 0;
        msg.arg = 0;
        Event_Send(&msg, l, 0);
        msg.vtable = D_004DAED0;
        cMessage_dtor(&msg, 0);
    }
    Lift_ActivateRecipients(l);
    ev.vt = D_004DAE30;
    FileMan_Release(&ev.s114, -1);
    FileMan_Release(&ev.s78, -1);
    cMessage_dtor(&ev, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00213B20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00213B20 */

/* merge_units: begin func_00213C70 */
#pragma push /* merge_units */
typedef struct { void* vt; char base[0x1C]; unsigned char action; char pad21[3]; int floor; unsigned char locked; char pad29[3]; } LiftMsg_f4;
typedef struct { char pad[0x10]; int transport; char pad14[0xF8]; int nfloors; int* locks; } Lift_f4;
extern char D_004F54C8[];
extern void Message_GetScriptTypeKey();
extern void cNetLockElevatorMsg_Pack();
extern void cNetLockElevatorMsg_dtor();
extern void cNetLockElevatorMsg_Clone();
void * const D_004DAEF0[8] = { (void*)0x0, (void*)0x0, (void*)cNetLockElevatorMsg_dtor, (void*)cNetLockElevatorMsg_Clone, (void*)cNetLockElevatorMsg_Pack, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
#if 0 /* merge_units */
extern void Event_Construct(LiftMsg_f4*, void*);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

extern void Transport_Send(int, LiftMsg_f4*, int, int);
#if 0 /* merge_units */
extern void cMessage_dtor(LiftMsg_f4*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

#pragma opt_strength_reduction off
int Lift_PublishFloorLocks(Lift_f4* self, void* dest)
{
    LiftMsg_f4 msg;
    int i;
    for (i = 0; i != self->nfloors; i++) {
        if (self->locks[i] != 0) {
            Event_Construct(&msg, D_004F54C8);
            msg.vt = ((char*)D_004DAEF0);
            msg.floor = i;
            msg.locked = 1;
            msg.action = 4;
            Transport_Send(self->transport, &msg, 0, (int)(void*)dest);
            msg.vt = ((char*)D_004DAEF0);
            cMessage_dtor(&msg, 0);
        }
    }
    return 1;
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00213C70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00213C70 */
