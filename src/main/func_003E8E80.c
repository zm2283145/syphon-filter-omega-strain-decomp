/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00138EA0(int, int, int, int);
extern int func_003EEE70(int, int);

int func_003E8E80(int a0, int a1) {
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

int func_003E8EB0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 112);
    return func_003EEE70(tmp0, a0);
}
