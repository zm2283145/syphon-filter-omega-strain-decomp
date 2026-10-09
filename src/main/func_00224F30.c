/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Objective_ResolveReceiver(int);
extern int func_00228050(int, int);
extern int func_00228190(int, int, int, int);
extern int func_002283A0(int, int, int);
extern int func_00228490(int, int, int);
extern int func_00228580(int, int, int);
extern int func_00228670(int, int, int);
extern int func_00228760(int, int, int);
extern int func_00228850(int, int, int);
extern int func_00228940(int, int, int);
extern int func_00228A30(int, int, int);
extern int Objective_Activate(int);
extern int Objective_Deactivate(int);
extern int GObj_IdentityB(int);

int func_00224F30(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    tmp3 = *(int*)((char*)a0 + 4);
    func_00228050(tmp1, ((unsigned int)(0) < (unsigned int)(tmp3)));
    return 0;
}

int func_00224F70(int a0) {
    int a1, v0;

    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a0 = v0;
    a1 = 0;
    v0 = func_00228050(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00224FA0(int a0) {
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
    v0 = func_00228190(a0, a1, a2, a3);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225000(int a0) {
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
    v0 = func_00228190(a0, a1, a2, a3);
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

int func_002250B0(int a0) {
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

int func_00225130(int a0) {
    unsigned char tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(unsigned char*)((char*)a0 + 4);
    tmp1 = *(int*)(char*)a0;
    tmp2 = Objective_ResolveReceiver(tmp1);
    *(char*)((char*)tmp2 + 36) = tmp0;
    return 0;
}

int func_00225160(int a0) {
    int tmp0;
    int tmp1;
    unsigned char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = Objective_ResolveReceiver(tmp0);
    tmp3 = *(unsigned char*)((char*)tmp1 + 36);
    return tmp3;
}

int func_00225180(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = func_002283A0(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_002251C0(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = func_00228490(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225200(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = func_00228580(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225240(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = func_00228670(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225280(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = func_00228760(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_002252C0(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = func_00228850(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225300(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = func_00228940(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00225340(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = Objective_ResolveReceiver(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0;
    v0 = func_00228A30(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
