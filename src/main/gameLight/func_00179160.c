/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE898[];
extern char D_004EE8A0[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int, int);

void ScriptType_cGameLight_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = cGOBJ_GetScriptTypeKeyPtr();
    tmp2 = *(int*)D_004EE8A0;
    tmp3 = *(int*)(char*)tmp0;
    ScriptType_SetParent(tmp2, tmp3);
}

int cGameLight_v0B(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE898;
    return tmp0;
}

int cGameLight_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
