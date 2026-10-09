/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F79A0[];
extern char D_004F79A8[];
extern char D_004F79B0[];
extern char D_004F79B8[];
extern char D_004F79C0[];
extern char D_004F79C8[];
extern char D_004F79D0[];
extern char D_004F79D8[];
extern char D_00555070[];
extern int GObj_IdentityB(int);
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_0022DD20(void);
extern int func_0022DDA0(void);
extern int func_0022DE00(void);
extern int func_0022DE60(void);
extern int Global_SetPlayersCheckpoint(int, int);
extern int func_003C8C50(void);
extern int func_003CC830(void);
extern void func_003D9440(int, int);

void ScriptType_cCheckpoint_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004F79D8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022DD20(void) {
    return (int)D_004F79D0;
}

int cCheckpoint_v0B(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_0022DD20();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int cCheckpoint_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

void ScriptType_cRespawnMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F79C8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022DDA0(void) {
    return (int)D_004F79C0;
}

int cRespawnMsg_v03(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_0022DDA0();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

void ScriptType_cNotifyCheckpointMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F79B8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022DE00(void) {
    return (int)D_004F79B0;
}

int cNotifyCheckpointMsg_v03(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_0022DE00();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

void ScriptType_cAddCheckpointMsg_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F79A8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0022DE60(void) {
    return (int)D_004F79A0;
}

int cAddCheckpointMsg_v03(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_0022DE60();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int Script_SetPlayersCheckpoint(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = GObj_IdentityB(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    v0 = Global_SetPlayersCheckpoint(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
