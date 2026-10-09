/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0053B500[];
extern char D_0053B508[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int, int);

void ScriptType_cPARTICLE_GOBJ_Init(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = cGOBJ_GetScriptTypeKeyPtr();
    tmp2 = *(int*)D_0053B508;
    tmp3 = *(int*)(char*)tmp0;
    ScriptType_SetParent(tmp2, tmp3);
}

int func_003926A0(void) {
    int tmp0;

    tmp0 = *(int*)D_0053B500;
    return tmp0;
}

int func_003926B0(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
