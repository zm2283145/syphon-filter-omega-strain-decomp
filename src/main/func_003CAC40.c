/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00138EA0(int, int, int, int);
extern int func_003CAC70(int, int);

int func_003CAC40(int a0, int a1) {
    int loc[1];
    int v0;

    a0 = a0 + 32;
    *(int*)(char*)loc = a1;
    a1 = (int)loc;
    v0 = func_003CAC70(a0, a1);
    v0 = 0 + 1;
    goto ret;
ret:
    return v0;
}

int func_003CAC70(int a0, int a1) {
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
