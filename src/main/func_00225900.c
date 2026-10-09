/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00225770(int);
extern int Objective_ResolveReceiver(int);
extern int func_00225C40(int);
extern int func_00225DF0(int, int, int);
extern int func_00225F00(int, int);
extern int Objective_Succeed(int, int, int);
extern int Objective_Fail(int, int, int);
extern int ObjMan_StartStage(int, int, int);
extern int ObjMan_GetObjective(int, int);
extern int GObj_IdentityB(int);

int func_00225900(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    v0 = *(int*)(char*)(v0 + 164);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

int ObjMan_ScriptStartStage(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = ObjMan_StartStage(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225970(int a0) {
    int a1, a2, s0, s1, v0;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s1 = v0;
    v0 = Objective_ResolveReceiver(a0);
    a0 = *(int*)(char*)(s0 + 8);
    s0 = v0;
    v0 = GObj_IdentityB(a0);
    a0 = s1;
    a1 = s0;
    a2 = v0;
    v0 = Objective_Fail(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_Objective_Fail(int a0) {
    int a1, a2, s0, v0;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s0 = v0;
    v0 = Objective_ResolveReceiver(a0);
    a0 = s0;
    a1 = v0;
    a2 = 0;
    v0 = Objective_Fail(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225A20(int a0) {
    int loc[1];
    int a1, a2, s0, v0;

    v0 = *(int*)(char*)(a0 + 8);
    s0 = a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s0 = v0;
    v0 = Objective_ResolveReceiver(a0);
    a2 = *(int*)(char*)loc;
    a0 = s0;
    a1 = v0;
    v0 = func_00225DF0(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225A70(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225C40(tmp0);
    tmp3 = *(int*)((char*)a0 + 4);
    tmp4 = Objective_ResolveReceiver(tmp3);
    func_00225F00(tmp1, tmp4);
    return 0;
}

int func_00225AC0(int a0) {
    int a1, a2, s0, s1, v0;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s1 = v0;
    v0 = Objective_ResolveReceiver(a0);
    a0 = *(int*)(char*)(s0 + 8);
    s0 = v0;
    v0 = GObj_IdentityB(a0);
    a0 = s1;
    a1 = s0;
    a2 = v0;
    v0 = Objective_Succeed(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_Objective_Succeed(int a0) {
    int a1, a2, s0, v0;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s0 = v0;
    v0 = Objective_ResolveReceiver(a0);
    a0 = s0;
    a1 = v0;
    a2 = 0;
    v0 = Objective_Succeed(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_GetObjective(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    v0 = ObjMan_GetObjective(a0, a1);
    a0 = v0;
    v0 = func_00225770(a0);
    goto ret;
ret:
    return v0;
}
