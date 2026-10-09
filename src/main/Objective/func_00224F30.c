/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GObj_IdentityB(int);
extern int Objective_Activate(int);
extern int Objective_Deactivate(int);
extern int Objective_ResolveReceiver(int);
extern int cObjective_ClearMapObject(int, int);
extern int cObjective_SetAddLabel(int, int, int);
extern int cObjective_SetCompleteLabel(int, int, int);
extern int cObjective_SetFailLabel(int, int, int);
extern int cObjective_SetMapLabel(int, int, int);
extern int cObjective_SetMapObject(int, int, int, int);
extern int cObjective_SetMenuLabel(int, int, int);
extern int cObjective_SetNameLabel(int, int, int);
extern int cObjective_SetPluralLabel(int, int, int);
extern int cObjective_SetSingleLabel(int, int, int);

int Script_cObjective_ClearMapObject_2(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    tmp3 = *(int*)((char*)a0 + 4);
    cObjective_ClearMapObject(tmp1, ((unsigned int)(0) < (unsigned int)(tmp3)));
    return 0;
}

int Script_cObjective_ClearMapObject(int a0) {
    int a1, v0;

    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a0 = v0;
    a1 = 0;
    v0 = cObjective_ClearMapObject(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetMapObject_2(int a0) {
    int loc[1];
    int a1, a2, a3, s0, v0;

    v0 = *(int*)(char*)(a0 + 8);
    s0 = a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s0 = v0;
    v0 = GObj_IdentityB(a0);
    a2 = *(int*)(char*)loc;
    a0 = s0;
    a1 = v0;
    a3 = 0;
    v0 = cObjective_SetMapObject(a0, a1, a2, a3);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetMapObject(int a0) {
    int a1, a2, a3, s0, v0;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s0 = v0;
    v0 = GObj_IdentityB(a0);
    a0 = s0;
    a1 = v0;
    a2 = 0;
    a3 = 0;
    v0 = cObjective_SetMapObject(a0, a1, a2, a3);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Objective_ScriptDeactivate(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    Objective_Deactivate(tmp1);
    return 0;
}

int Objective_ScriptActivate(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    Objective_Activate(tmp1);
    return 0;
}

int Script_cObjective_IsActive(int a0) {
    int tmp0;
    int tmp1;
    unsigned char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    tmp3 = *(unsigned char*)((char*)tmp1 + 37);
    return tmp3;
}

int Script_Objective_WasFailed(int a0) {
    int tmp0;
    int tmp1;
    signed char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    tmp3 = *(signed char*)((char*)tmp1 + 36);
    return ((unsigned int)((tmp3 ^ 2)) < (unsigned int)(1));
}

int Script_Objective_IsComplete(int a0) {
    int tmp0;
    int tmp1;
    signed char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    tmp3 = *(signed char*)((char*)tmp1 + 36);
    return ((unsigned int)((tmp3 ^ 1)) < (unsigned int)(1));
}

int Script_cObjective_SetState(int a0) {
    unsigned char tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(unsigned char*)((char*)a0 + 4);
    tmp1 = *(int*)(char*)a0;
    tmp2 = Objective_ResolveReceiver(tmp1);
    *(char*)((char*)tmp2 + 36) = tmp0;
    return 0;
}

int Script_cObjective_GetState(int a0) {
    int tmp0;
    int tmp1;
    unsigned char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    tmp3 = *(unsigned char*)((char*)tmp1 + 36);
    return tmp3;
}

int Script_cObjective_SetPluralLabel(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = cObjective_SetPluralLabel(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetSingleLabel(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = cObjective_SetSingleLabel(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetFailLabel(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = cObjective_SetFailLabel(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetCompleteLabel(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = cObjective_SetCompleteLabel(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetAddLabel(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = cObjective_SetAddLabel(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetMapLabel(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = cObjective_SetMapLabel(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetMenuLabel(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = cObjective_SetMenuLabel(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_cObjective_SetNameLabel(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = cObjective_SetNameLabel(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
