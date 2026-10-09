/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CB1A0(int);
extern int func_003D9970(int);
extern int func_003D9990(int, int);

void func_003D96C0(char* self) {
    *(int*)(self + 4) = 0;
}

int func_003D96D0(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_003D9970(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    v0 = func_003D9990(a0, a1);
    a0 = v0;
    v0 = func_003CB1A0(a0);
    goto ret;
ret:
    return v0;
}

int func_003D9710(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = func_003D9970(a0);
    v0 = *(int*)(char*)(v0 + 4);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}
