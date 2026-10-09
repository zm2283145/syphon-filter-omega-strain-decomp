/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003A74E0(int, int, int, int, int);

void func_003A7EC0(int a0, int a1, int a2, int a3) {
    int loc[4];
    int t0, v0;

    t0 = 0;
    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 34;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 16;
    *(int*)((char*)loc + 12) = a3;
    a2 = (int)loc;
    a3 = 0;
    v0 = func_003A74E0(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A7F00(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    int loc[8];
    int v0;

    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 33;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 24;
    *(int*)((char*)loc + 12) = a3;
    a2 = (int)loc;
    *(int*)((char*)loc + 16) = t0;
    a3 = t2;
    *(int*)((char*)loc + 20) = t1;
    t0 = t3;
    v0 = func_003A74E0(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A7F50(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 97;
    t0 = 0;
    v0 = func_003A74E0(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A7F80(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 23;
    t0 = 0;
    v0 = func_003A74E0(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A7FB0(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 22;
    t0 = 0;
    v0 = func_003A74E0(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

int func_003A7FE0(void) {
    return func_003A74E0(24, 0, 0, 0, 0);
}
