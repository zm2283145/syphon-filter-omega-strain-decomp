/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_00434600(int, int, int);

void func_004344A0(int a0, int a1) {
    int loc[1];
    int a2;

    *(int*)(char*)loc = a1;
    a1 = (int)loc;
    func_00434600(a0, a1, a2);
    goto ret;
ret:;
}
