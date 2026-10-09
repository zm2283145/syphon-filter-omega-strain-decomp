/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F54D0[];
extern char D_004F55D8[];
extern char D_004F55E0[];
extern char D_004F5610[];
extern char D_004F5618[];
extern char D_004F5638[];
extern char D_004F5640[];
extern char D_004F5660[];
extern char D_004F5668[];
extern char D_00555070[];
extern int GObj_IdentityA(int);
extern int Object_LookupById(int);
extern int ScriptFilter_Dispatch(int, int, int);
extern int SoundAction_CtorVoice(int, int, int, int, int);
extern int cElevatorGOBJ_LockFloor(int, int, int);
extern int cElevatorGOBJ_UnlockFloor(int, int, int);
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

void ScriptType_cInteractGOBJ_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004F5668;
    tmp1 = *(int*)D_004F54D0;
    func_003D9440(tmp0, tmp1);
}

int cInteractGOBJ_v0B(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5660;
    return tmp0;
}

int cInteractGOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int Script_cPathedNotice_Data(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int PathedNotice_GetAction(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void ScriptType_cPathedNotice_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F5640;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int PathedNotice_GetScriptType(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5638;
    return tmp0;
}

int Script_cElevatorNotice_Data(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int Script_cElevatorNotice_Action(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void ScriptType_cElevatorNotice_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F5618;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int cElevatorNotice_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5610;
    return tmp0;
}

int Script_cGOBJTriggerEventMsg_Box(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 44);
    a0 = (int)loc;
    *(int*)(char*)loc = v0;
    v0 = Object_LookupById(a0);
    a0 = v0;
    v0 = GObj_IdentityA(a0);
    goto ret;
ret:
    return v0;
}

int Script_cGOBJTriggerEventMsg_Who(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 48);
    a0 = (int)loc;
    *(int*)(char*)loc = v0;
    v0 = Object_LookupById(a0);
    a0 = v0;
    v0 = GObj_IdentityA(a0);
    goto ret;
ret:
    return v0;
}

int Script_cGOBJTriggerEventMsg_Data(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 40);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int Script_cGOBJTriggerEventMsg_Action(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void ScriptType_cGOBJTriggerEventMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F55E0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00210CB0(void) {
    return (int)D_004F55D8;
}

int TriggerEvent_GetScriptType(void) {
    int tmp0;

    tmp0 = *(int*)D_004F55D8;
    return tmp0;
}

int Script_cElevatorGOBJ_UnlockFloor(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    a1 = *(int*)(char*)loc;
    a2 = 0;
    v0 = cElevatorGOBJ_UnlockFloor(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cElevatorGOBJ_LockFloor(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    a1 = *(int*)(char*)loc;
    a2 = 0;
    v0 = cElevatorGOBJ_LockFloor(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cElevatorGOBJ_SetLoopSound(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0;
    t0 = 0;
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a3 = *(int*)(char*)a0;
    a2 = *(int*)(char*)loc;
    a0 = a3 + 736;
    v0 = SoundAction_CtorVoice(a0, a1, a2, a3, t0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cElevatorGOBJ_SetStopSound(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0;
    t0 = 0;
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a3 = *(int*)(char*)a0;
    a2 = *(int*)(char*)loc;
    a0 = a3 + 1536;
    v0 = SoundAction_CtorVoice(a0, a1, a2, a3, t0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cElevatorGOBJ_SetStartSound(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0;
    t0 = 0;
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a3 = *(int*)(char*)a0;
    a2 = *(int*)(char*)loc;
    a0 = a3 + 1136;
    v0 = SoundAction_CtorVoice(a0, a1, a2, a3, t0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cElevatorGOBJ_SetDingSound(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0;
    t0 = 0;
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a3 = *(int*)(char*)a0;
    a2 = *(int*)(char*)loc;
    a0 = a3 + 336;
    v0 = SoundAction_CtorVoice(a0, a1, a2, a3, t0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
