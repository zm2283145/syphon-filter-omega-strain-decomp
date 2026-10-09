/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7CF8[];
extern char D_004F7D00[];
extern char D_004F7D20[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int cGOBJ_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int, int);
extern void ScriptType_SetParent(int, int);

int ScriptType_cNIEventLight_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp7;
    int tmp8;

    tmp0 = cGOBJ_GetScriptTypeKeyPtr();
    tmp2 = *(int*)D_004F7D00;
    tmp3 = *(int*)(char*)tmp0;
    ScriptType_SetParent(tmp2, tmp3);
    tmp6 = *(int*)D_004F7D00;
    tmp7 = *(int*)D_004F7D20;
    tmp8 = ScriptType_AddAccepted(tmp6, tmp7);
    return tmp8;
}

int cNIEventLight_v0B(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7CF8;
    return tmp0;
}

int cNIEventLight_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
