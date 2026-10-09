/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cElevatorGOBJ (lift) script natives and script type registration.
 * "volatile" locals mirror the original stack temporaries.
 */

#include "gobj_types.h"

extern int D_004F54F0;   /* cPathedGOBJ script-type value */
extern int D_004F5540;   /* cElevatorGOBJ script-type value */
extern int D_004F5548;   /* cElevatorGOBJ script-type key */
extern int D_004F5610;   /* cElevatorNotice script-type value */
extern char D_00555070[];
extern unsigned char Lift_CloseDoors(cElevatorGOBJ* lift);
extern unsigned char Lift_OpenDoors(cElevatorGOBJ* lift);
extern int Lift_SeekFloor(cElevatorGOBJ* lift, int floor, int a2, int a3);
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int cElevatorGOBJ_ChooseFloor(cElevatorGOBJ* lift);
extern unsigned char cElevatorGOBJ_GetState(cElevatorGOBJ* lift);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int base);

int Script_cElevatorGOBJ_ChooseFloor(ScriptArg* args) {
    cElevatorGOBJ_ChooseFloor(args[0].p);
    return 0;
}

int Script_cElevatorGOBJ_GetCurrentFloor(ScriptArg* args) {
    volatile int floor = ((cElevatorGOBJ*)args[0].p)->state->index;
    return floor;
}

int Script_cElevatorGOBJ_GetDestFloor(ScriptArg* args) {
    volatile int floor = ((cElevatorGOBJ*)args[0].p)->state->dest;
    return floor;
}

/* Passengers(lift): true when the passenger count is positive. */
int Script_cElevatorGOBJ_Passengers(ScriptArg* args) {
    volatile int any = ((cElevatorGOBJ*)args[0].p)->passengers > 0;
    return any;
}

int Script_cElevatorGOBJ_GetState(ScriptArg* args) {
    return cElevatorGOBJ_GetState(args[0].p);
}

int Script_cElevatorGOBJ_CloseDoors(ScriptArg* args) {
    return Lift_CloseDoors(args[0].p);
}

int Script_cElevatorGOBJ_OpenDoors(ScriptArg* args) {
    return Lift_OpenDoors(args[0].p);
}

/* SeekFloor(lift, floor, flag). */
int Script_cElevatorGOBJ_SeekFloor(ScriptArg* args) {
    int loc[1];   /* stack copy of the floor argument (kept for matching) */
    cElevatorGOBJ* lift;
    int flag;
    int floor;

    flag = args[2].i;
    floor = args[1].i;
    *(int*)(char*)loc = floor;
    lift = args[0].p;
    floor = *(int*)(char*)loc;
    Lift_SeekFloor(lift, floor, (unsigned int)flag != 0, 0);
    return 0;
}

/* Registers the cElevatorGOBJ script type under cPathedGOBJ; accepts cElevatorNotice. */
int ScriptType_cElevatorGOBJ_Init(void) {
    ScriptType_SetParent(D_004F5548, D_004F54F0);
    return ScriptType_AddAccepted(D_004F5548, D_004F5610);
}

int Lift_GetScriptType(void) {
    return D_004F5540;
}

int Lift_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

int Script_Mover_SetSpeed(Args* a) {
    union { int i; float f; } u;
    u.i = a->arg1;
    a->obj->speed = u.f;
    return 0;
}
