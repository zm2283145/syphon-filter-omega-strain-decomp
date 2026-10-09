/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE860[];
extern char D_004EE868[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int, int);

void ScriptType_cEnvSettings_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = cGOBJ_GetScriptTypeKeyPtr();
    tmp2 = *(int*)D_004EE868;
    tmp3 = *(int*)(char*)tmp0;
    ScriptType_SetParent(tmp2, tmp3);
}

int cEnvSettings_v0B(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE860;
    return tmp0;
}

int cEnvSettings_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
