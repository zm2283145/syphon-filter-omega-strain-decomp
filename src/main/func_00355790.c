/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_00356C70(int);
extern int func_0036B250(int);
extern int func_0036B3B0(int, int, int);

int func_00355790(int a0) {
    int tmp4;

    func_00356C70(a0);
    func_0036B250(1);
    tmp4 = func_0036B3B0(1, 1048576, 2048);
    return tmp4;
}
