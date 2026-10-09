/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int AgentData_IsObjectiveComplete(int, int);
extern int AgentData_SetObjectiveBit(int, int, int);
extern int cAgentData_AreObjectivesComplete(int, int);

int Script_cAgentData_AreObjectivesComplete(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = cAgentData_AreObjectivesComplete(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int Game_IsObjectiveComplete(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = AgentData_IsObjectiveComplete(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int AgentData_AddObjective(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    a1 = *(int*)(char*)loc;
    a2 = 0;
    v0 = AgentData_SetObjectiveBit(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cAgentData_GetStat(int a0) {
    int loc[1];
    int at, v0, v1;
    int cond;

    v0 = *(unsigned char*)(char*)(a0 + 4);
    v1 = *(int*)(char*)a0;
    at = v0 < 31;
    cond = at == 0;
    if (cond) goto L0032FC84;
    v0 = v0 << 2;
    v0 = v0 + v1;
    v0 = *(int*)(char*)(v0 + 8);
    goto L0032FC88;
L0032FC84:;
    v0 = 0;
L0032FC88:;
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}
