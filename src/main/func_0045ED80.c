/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0045EDB0(int, int);

int func_0045ED80(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    a1 = 0;
    func_0045EDB0(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
