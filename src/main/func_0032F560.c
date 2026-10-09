/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0049D010[];
extern int func_00185C70(int);
extern int func_0032F600(int, int);
extern int func_0032F680(int, int);
extern void func_00333050(int, int);
extern void func_003330C0(int, int);
extern int AgentData_IsObjectiveComplete(int, int);
extern int GObj_IdentityB(int);

int func_0032F560(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    func_00333050(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_0032F590(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    func_003330C0(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_0032F5C0(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = GObj_IdentityB(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    v0 = func_0032F600(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int func_0032F600(int a0, int a1) {
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

int func_0032F650(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = func_0032F680(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}
