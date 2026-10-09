/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003A74E0(int, int, int, int, int);
extern int func_003A7990(int, int, int);

void func_003A81A0(int a0) {
    int loc[1];
    int a1, a2, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a0 = 0 + 10;
    v0 = func_003A7990(a0, a1, a2);
    goto ret;
ret:;
}

void func_003A81D0(int a0, int a1) {
    int loc[2];
    int a2, a3, t0, v0;

    a3 = 0;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    t0 = 0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 9;
    a1 = 0 + 8;
    v0 = func_003A74E0(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A8210(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 6;
    t0 = 0;
    v0 = func_003A74E0(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

int func_003A8240(void) {
    return func_003A74E0(8, 0, 0, 0, 0);
}
