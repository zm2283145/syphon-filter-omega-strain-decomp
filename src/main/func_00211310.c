/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PathObj_ResetAndTrigger(int);

int Script_Mover_GetPos(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 208);
    v0 = *(int*)(char*)v0;
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int PathObj_ScriptResetAndTrigger(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    PathObj_ResetAndTrigger(tmp0);
    return 0;
}
