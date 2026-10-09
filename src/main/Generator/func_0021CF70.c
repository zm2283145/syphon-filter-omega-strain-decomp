/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F56D8[];
extern char D_004F56F0[];
extern char D_004F56F8[];
extern char D_004F5700[];
extern char D_004F5708[];
extern char D_004F5710[];
extern char D_004F5718[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int cGOBJ_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int, int);
extern void ScriptType_SetParent(int, int);

int ScriptType_cGenerator_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp7;
    int tmp10;
    int tmp11;
    int tmp12;

    tmp0 = cGOBJ_GetScriptTypeKeyPtr();
    tmp2 = *(int*)D_004F5718;
    tmp3 = *(int*)(char*)tmp0;
    ScriptType_SetParent(tmp2, tmp3);
    tmp6 = *(int*)D_004F5718;
    tmp7 = *(int*)D_004F56F0;
    ScriptType_AddAccepted(tmp6, tmp7);
    tmp10 = *(int*)D_004F5718;
    tmp11 = *(int*)D_004F5700;
    tmp12 = ScriptType_AddAccepted(tmp10, tmp11);
    return tmp12;
}

int cGenerator_v0B(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5710;
    return tmp0;
}

int cGenerator_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

void ScriptType_cDespawnedNPCMsg_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004F5708;
    tmp1 = *(int*)D_004F56D8;
    ScriptType_SetParent(tmp0, tmp1);
}

int cDespawnedNPCMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5700;
    return tmp0;
}

void ScriptType_cSpawnedNPCMsg_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004F56F8;
    tmp1 = *(int*)D_004F56D8;
    ScriptType_SetParent(tmp0, tmp1);
}

int cSpawnedNPCMsg_v03(void) {
    int tmp0;

    tmp0 = *(int*)D_004F56F0;
    return tmp0;
}
