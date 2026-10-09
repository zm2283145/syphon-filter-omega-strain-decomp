/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int AgentData_IsObjectiveComplete(int, int);
extern char D_0049D010[];
extern int GObj_IdentityB(int);
extern int func_00185C70(int);
extern int Global_IsObjectiveComplete(int, int);
extern int cAgentData_HasBonusLevel(int, int);
extern void cAgentData_UnlockWeapon(int, int);
extern void cAgentData_UnlockLevel(int, int);

int Script_cAgentData_UnlockWeapon(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    cAgentData_UnlockWeapon(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cAgentData_UnlockLevel(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    cAgentData_UnlockLevel(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_IsObjectiveComplete(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = GObj_IdentityB(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    v0 = Global_IsObjectiveComplete(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int Global_IsObjectiveComplete(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 76);
    v0 = *(int*)(char*)D_0049D010;
    cond = v1 != v0;
    s0 = a1;
    if (cond) goto L0032F63C;
    v0 = func_00185C70(a0);
    a1 = s0;
    a0 = v0;
    v0 = AgentData_IsObjectiveComplete(a0, a1);
    goto L0032F644;
L0032F63C:;
    v0 = 0;
L0032F644:;
    goto ret;
ret:
    return v0;
}

int Script_cAgentData_HasBonusLevel(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = cAgentData_HasBonusLevel(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}
