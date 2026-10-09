/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_003A6CD0(int, int, int);

int func_001C70D0(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = 0 + 1;
    a1 = *(int*)(char*)loc;
    a2 = a1;
    func_003A6CD0(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
