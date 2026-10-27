/*
 * main/GameGOBJ: range (2 files, 00213DC0-00213EE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00213DC0 */
#pragma push /* merge_units */
typedef struct { char d[0x9C]; } LdStr_f3;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    LdStr_f3 s78;
    LdStr_f3 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) LdSnd_f3;
typedef struct { void* vtable; char base[0x20]; int kind; int arg; } LdMsg_f3;
typedef struct { char pad[0x150]; char preset[1]; } Lift_f3;
extern char D_004F5448[];
extern char D_004DAED0[];
extern char g_Game[];
extern char D_004DAE30[];
extern int cElevatorGOBJ_InsideDoorsAreClosed(Lift_f3* l);
extern int cElevatorGOBJ_ToggleInsideDoors(Lift_f3* l);
extern int cElevatorGOBJ_OutsideDoorsAreClosed(Lift_f3* l);
extern void cElevatorGOBJ_ToggleOutsideDoors(Lift_f3* l);
extern void cMessage_ctor_cMessageNameR(LdMsg_f3* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void cPlaySoundMsg_ctor_cSndFxR(LdSnd_f3* e, void* preset, Lift_f3* l);
extern void cFileMan_dtor(LdStr_f3* s, int flag);
unsigned char cElevatorGOBJ_OpenDoors(Lift_f3* l)
{
    LdSnd_f3 ev;
    LdMsg_f3 msg;
    unsigned char r;
    if (cElevatorGOBJ_InsideDoorsAreClosed(l)) {
        r = cElevatorGOBJ_ToggleInsideDoors(l);
        if (r) {
            cMessage_ctor_cMessageNameR(&msg, D_004F5448);
            msg.vtable = D_004DAED0;
            msg.kind = 2;
            msg.arg = 0;
            QueueMessage_cMessageR_cSystemP_int(&msg, l, 0);
            msg.vtable = D_004DAED0;
            cMessage_dtor(&msg, 0);
        }
        cPlaySoundMsg_ctor_cSndFxR(&ev, l->preset, l);
        ev.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
        ev.vt = D_004DAE30;
        cFileMan_dtor(&ev.s114, -1);
        cFileMan_dtor(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    } else {
        r = 1;
    }
    if (cElevatorGOBJ_OutsideDoorsAreClosed(l)) {
        cElevatorGOBJ_ToggleOutsideDoors(l);
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00213DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00213DC0 */

/* merge_units: begin func_00213EE0 */
#pragma push /* merge_units */
typedef struct MsgLC {
    void* vtable;
    char base[0x20];
    int f24;
    int f28;
    char pad[4];
} MsgLC;
extern int cElevatorGOBJ_InsideDoorsAreOpen(void* lift);
#if 0 /* merge_units */
extern unsigned char cElevatorGOBJ_ToggleInsideDoors(void* lift);
#endif /* merge_units */
#define cElevatorGOBJ_ToggleInsideDoors(a0) ((unsigned char)cElevatorGOBJ_ToggleInsideDoors((void *)(a0))) /* merge_units */

extern int cElevatorGOBJ_OutsideDoorsAreOpen(void* lift);
#if 0 /* merge_units */
extern void cElevatorGOBJ_ToggleOutsideDoors(void* lift);
#endif /* merge_units */
#define cElevatorGOBJ_ToggleOutsideDoors(a0) (cElevatorGOBJ_ToggleOutsideDoors((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(MsgLC* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(MsgLC* msg, void* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(MsgLC* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

unsigned char cElevatorGOBJ_CloseDoors(void* lift)
{
    unsigned char r = 1;
    if (cElevatorGOBJ_InsideDoorsAreOpen(lift)) {
        r = cElevatorGOBJ_ToggleInsideDoors(lift);
        if (r) {
            MsgLC msg;
            cMessage_ctor_cMessageNameR(&msg, D_004F5448);
            msg.vtable = D_004DAED0;
            msg.f24 = 3;
            msg.f28 = 0;
            QueueMessage_cMessageR_cSystemP_int(&msg, lift, 0);
            msg.vtable = D_004DAED0;
            cMessage_dtor(&msg, 0);
        }
    }
    if (cElevatorGOBJ_OutsideDoorsAreOpen(lift)) {
        cElevatorGOBJ_ToggleOutsideDoors(lift);
    }
    return r;
}
#undef cElevatorGOBJ_ToggleInsideDoors /* merge_units */
#undef cElevatorGOBJ_ToggleOutsideDoors /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00213EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00213EE0 */
