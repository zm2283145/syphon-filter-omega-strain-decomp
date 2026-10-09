/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE898[];
extern char D_004EE8B8[];
extern char D_004EE8C0[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern void ScriptType_SetParent(int, int);

void ScriptType_cGameSceneLight_Init(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004EE8C0;
    tmp1 = *(int*)D_004EE898;
    ScriptType_SetParent(tmp0, tmp1);
}

int cGameSceneLight_v0B(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE8B8;
    return tmp0;
}

int cGameSceneLight_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
