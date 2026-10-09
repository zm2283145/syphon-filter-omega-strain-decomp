/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001C6890(int, int);
extern int func_001C6A00(int, int);
extern int func_001C6B70(int, int, int);
extern int func_001C6C50(int, int);
extern int func_001C6D00(int, int, int);
extern int func_001C6EA0(int, int);
extern int func_003CC820(int);

int func_001C71C0(int a0) {
    int loc[1];
    int a1, s0, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    s0 = *(int*)(char*)loc;
    a0 = *(int*)(char*)(a0 + 4);
    v0 = func_003CC820(a0);
    a0 = s0;
    a1 = v0;
    v0 = func_001C6890(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_001C7200(int a0) {
    int loc[1];
    int a1, s0, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    s0 = *(int*)(char*)loc;
    a0 = *(int*)(char*)(a0 + 4);
    v0 = func_003CC820(a0);
    a0 = s0;
    a1 = v0;
    v0 = func_001C6A00(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_001C7240(int a0) {
    int loc[1];
    int a1, a2, s0, s1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    s0 = *(signed char*)(char*)a0;
    a0 = *(int*)(char*)(a0 + 8);
    s1 = *(int*)(char*)loc;
    v0 = func_003CC820(a0);
    a0 = s0;
    a1 = s1;
    a2 = v0;
    v0 = func_001C6B70(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_001C7290(int a0) {
    int loc[1];
    int a1, a2, s0, s1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    s0 = *(signed char*)(char*)a0;
    a0 = *(int*)(char*)(a0 + 8);
    s1 = *(int*)(char*)loc;
    v0 = func_003CC820(a0);
    a0 = s0;
    a1 = s1;
    a2 = v0;
    v0 = func_001C6D00(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_001C72E0(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(signed char*)(char*)a0;
    v0 = func_001C6C50(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_001C7310(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(signed char*)(char*)a0;
    v0 = func_001C6EA0(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
