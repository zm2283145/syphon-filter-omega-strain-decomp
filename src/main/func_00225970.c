/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00225790(int);
extern int func_00225C40(int);
extern int func_002260F0(int, int, int);
extern int func_003CC820(int);

int func_00225970(int a0) {
    int a1, a2, s0, s1, v0;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = func_00225C40(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s1 = v0;
    v0 = func_00225790(a0);
    a0 = *(int*)(char*)(s0 + 8);
    s0 = v0;
    v0 = func_003CC820(a0);
    a0 = s1;
    a1 = s0;
    a2 = v0;
    v0 = func_002260F0(a0, a1, a2);
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
    v0 = func_00225790(a0);
    a0 = s0;
    a1 = v0;
    a2 = 0;
    v0 = func_002260F0(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
