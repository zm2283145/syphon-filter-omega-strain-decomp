/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055C0A8[];
extern int func_00138EA0(int, int, int, int);
extern int func_003EC2D0(int, int);

void func_003EC2A0(int a0) {
    int loc[1];
    int a1, v0;

    a1 = (int)loc;
    *(int*)(char*)loc = a0;
    a0 = (int)D_0055C0A8;
    v0 = func_003EC2D0(a0, a1);
    goto ret;
ret:;
}

int func_003EC2D0(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    v0 = a0 + 4;
    a1 = a0;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    a2 = (int)loc;
    v0 = func_00138EA0(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}
