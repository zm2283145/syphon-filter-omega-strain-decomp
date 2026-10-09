/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003339E0(int, int);
extern int func_00333B10(int, int);
extern int func_00333B90(int, int, int);

int func_0032FBD0(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = func_003339E0(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int func_0032FC00(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = func_00333B10(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int func_0032FC30(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    a1 = *(int*)(char*)loc;
    a2 = 0;
    v0 = func_00333B90(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_0032FC60(int a0) {
    int loc[1];
    int at, v0, v1;
    int cond;

    v0 = *(unsigned char*)(char*)(a0 + 4);
    v1 = *(int*)(char*)a0;
    at = v0 < 31;
    cond = at == 0;
    if (cond) goto L0032FC84;
    v0 = v0 << 2;
    v0 = v0 + v1;
    v0 = *(int*)(char*)(v0 + 8);
    goto L0032FC88;
L0032FC84:;
    v0 = 0;
L0032FC88:;
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}
