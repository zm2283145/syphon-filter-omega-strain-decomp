/*
 * main/GameGOBJ: range (4 files, 002109F0-00210E30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"
#include "types.h"

/* merge_units: begin func_002109F0 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cSoundGOBJ script type and cInteractGOBJ script natives.
 */


extern int D_004F5680;   /* cSoundGOBJ script-type value */
extern int D_004F5688;   /* cSoundGOBJ script-type key */
extern char D_00555070[];
extern int GObj_IdentityA(int obj);
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int base);

/* Registers the cSoundGOBJ script type under cGOBJ. */
void ScriptType_cSoundGOBJ_Init(void) {
    int* base;

    base = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F5688, *base);
}

int cSoundGOBJ_v0B(void) {
    return D_004F5680;
}

int cSoundGOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/* GetLocationObj(interact): returns the object stored at +0xA8. */
int Script_cInteractGOBJ_GetLocationObj(ScriptArg* args) {
    return GObj_IdentityA(*(int*)((char*)args[0].p + 0xA8));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002109F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002109F0 */

/* merge_units: begin func_00210A60 */
#pragma push /* merge_units */
extern int func_00171EB0(void*);
extern int* func_00171EA0(void*, int);

/* Script: cInteractGOBJ.GetTarget(index) -> target handle or 0. */
int Script_cInteractGOBJ_GetTarget(ScriptArg* args) {
    volatile int result;
    int index[1];
    char* self;
    int indexValue;
    int target;
    index[0] = args[1].i;
    self = args[0].p;
    indexValue = *(int*)index;
    if (func_00171EB0(self + 0x98) != 0) {
        target = *func_00171EA0(self + 0x98, indexValue);
    } else {
        target = 0;
    }
    result = target;
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00210A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00210A60 */

/* merge_units: begin func_00210AC0 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * Script types and natives for cInteractGOBJ, the GOBJ notice messages
 * (cPathedNotice, cElevatorNotice, cGOBJTriggerEventMsg) and the cElevatorGOBJ
 * floor-lock and sound setters. "volatile" locals mirror the original stack
 * temporaries of the script natives.
 */


extern int D_004F54D0;   /* cGameGOBJ script-type value */
extern int D_004F55D8;   /* cGOBJTriggerEventMsg script-type value */
extern int D_004F55E0;   /* cGOBJTriggerEventMsg script-type key */
extern int D_004F5610;   /* cElevatorNotice script-type value */
extern int D_004F5618;   /* cElevatorNotice script-type key */
extern int D_004F5638;   /* cPathedNotice script-type value */
extern int D_004F5640;   /* cPathedNotice script-type key */
extern int D_004F5660;   /* cInteractGOBJ script-type value */
extern int D_004F5668;   /* cInteractGOBJ script-type key */
extern int Object_LookupById(int* id);
extern int SoundAction_CtorVoice(LiftSound* snd, int a1, int id, cElevatorGOBJ* owner, int a4);
extern int cElevatorGOBJ_LockFloor(cElevatorGOBJ* lift, int floor, int a2);
extern int cElevatorGOBJ_UnlockFloor(cElevatorGOBJ* lift, int floor, int a2);
extern int* Message_GetScriptTypeKeyPtr(void);

/* Registers the cInteractGOBJ script type under cGameGOBJ. */
void ScriptType_cInteractGOBJ_Init(void) {
    ScriptType_SetParent(D_004F5668, D_004F54D0);
}

int cInteractGOBJ_v0B(void) {
    return D_004F5660;
}

int cInteractGOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/* --- cPathedNotice --- */

int Script_cPathedNotice_Data(ScriptArg* args) {
    volatile int data = ((cGOBJNotice*)args[0].p)->data;
    return data;
}

int PathedNotice_GetAction(ScriptArg* args) {
    return ((cGOBJNotice*)args[0].p)->action;
}

/* Registers the cPathedNotice script type under the notice base type. */
void ScriptType_cPathedNotice_Init(void) {
    int* base;

    base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F5640, *base);
}

int PathedNotice_GetScriptType(void) {
    return D_004F5638;
}

/* --- cElevatorNotice --- */

int Script_cElevatorNotice_Data(ScriptArg* args) {
    volatile int data = ((cGOBJNotice*)args[0].p)->data;
    return data;
}

int Script_cElevatorNotice_Action(ScriptArg* args) {
    return ((cGOBJNotice*)args[0].p)->action;
}

/* Registers the cElevatorNotice script type under the notice base type. */
void ScriptType_cElevatorNotice_Init(void) {
    int* base;

    base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F5618, *base);
}

int cElevatorNotice_v03(void) {
    return D_004F5610;
}

/* --- cGOBJTriggerEventMsg --- */

/* Box(msg): resolves the trigger box object id. */
int Script_cGOBJTriggerEventMsg_Box(ScriptArg* args) {
    int id = ((cGOBJNotice*)args[0].p)->box;
    return GObj_IdentityA(Object_LookupById(&id));
}

/* Who(msg): resolves the triggering object id. */
int Script_cGOBJTriggerEventMsg_Who(ScriptArg* args) {
    int id = ((cGOBJNotice*)args[0].p)->who;
    return GObj_IdentityA(Object_LookupById(&id));
}

int Script_cGOBJTriggerEventMsg_Data(ScriptArg* args) {
    volatile int data = ((cGOBJNotice*)args[0].p)->data;
    return data;
}

int Script_cGOBJTriggerEventMsg_Action(ScriptArg* args) {
    return ((cGOBJNotice*)args[0].p)->action;
}

/* Registers the cGOBJTriggerEventMsg script type under the notice base type. */
void ScriptType_cGOBJTriggerEventMsg_Init(void) {
    int* base;

    base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F55E0, *base);
}

/* Address of the cGOBJTriggerEventMsg script-type value. */
int* cGOBJTriggerEventMsg_GetScriptTypeKeyPtr(void) {
    return &D_004F55D8;
}

int TriggerEvent_GetScriptType(void) {
    return D_004F55D8;
}

/* --- cElevatorGOBJ floor locks and sounds --- */

int Script_cElevatorGOBJ_UnlockFloor(ScriptArg* args) {
    int loc[1];   /* stack copy of the floor argument (kept for matching) */
    cElevatorGOBJ* lift;
    int floor;

    floor = args[1].i;
    *(int*)(char*)loc = floor;
    lift = args[0].p;
    floor = *(int*)(char*)loc;
    cElevatorGOBJ_UnlockFloor(lift, floor, 0);
    return 0;
}

int Script_cElevatorGOBJ_LockFloor(ScriptArg* args) {
    int loc[1];   /* stack copy of the floor argument (kept for matching) */
    cElevatorGOBJ* lift;
    int floor;

    floor = args[1].i;
    *(int*)(char*)loc = floor;
    lift = args[0].p;
    floor = *(int*)(char*)loc;
    cElevatorGOBJ_LockFloor(lift, floor, 0);
    return 0;
}

int Script_cElevatorGOBJ_SetLoopSound(ScriptArg* args) {
    volatile int id = args[1].i;
    cElevatorGOBJ* lift = args[0].p;
    SoundAction_CtorVoice(&lift->loopSound, 0, id, lift, 0);
    return 0;
}

int Script_cElevatorGOBJ_SetStopSound(ScriptArg* args) {
    volatile int id = args[1].i;
    cElevatorGOBJ* lift = args[0].p;
    SoundAction_CtorVoice(&lift->stopSound, 0, id, lift, 0);
    return 0;
}

int Script_cElevatorGOBJ_SetStartSound(ScriptArg* args) {
    volatile int id = args[1].i;
    cElevatorGOBJ* lift = args[0].p;
    SoundAction_CtorVoice(&lift->startSound, 0, id, lift, 0);
    return 0;
}

int Script_cElevatorGOBJ_SetDingSound(ScriptArg* args) {
    volatile int id = args[1].i;
    cElevatorGOBJ* lift = args[0].p;
    SoundAction_CtorVoice(&lift->dingSound, 0, id, lift, 0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00210AC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00210AC0 */

/* merge_units: begin func_00210E30 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg_00210E30;

extern void cElevatorGOBJ_SetFloorName(void* elevator, int floor, int name);

/* Script native: sets the name of an elevator floor. */
int Script_cElevatorGOBJ_SetFloorName(ScriptArg_00210E30* args)
{
    int name[1];
    int floor[1];
    name[0] = args[2].i;
    floor[0] = args[1].i;
    cElevatorGOBJ_SetFloorName(args[0].p, *(int*)floor, *(int*)name);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00210E30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00210E30 */
