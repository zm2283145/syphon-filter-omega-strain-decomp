/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0011C750(int, int);

int func_00100230(int a0, int a1) {
    int tmp0;

    tmp0 = func_0011C750(a0, a1);
    return ((tmp0 < 0) ^ 1);
}

int func_00100260(int a0, int a1) {
    int tmp0;

    tmp0 = func_0011C750(a0, a1);
    return (0 < tmp0);
}

int func_00100280(int a0, int a1) {
    int tmp0;

    tmp0 = func_0011C750(a0, a1);
    return ((0 < tmp0) ^ 1);
}

int func_001002B0(int a0, int a1) {
    int tmp0;

    tmp0 = func_0011C750(a0, a1);
    return ((unsigned int)(0) < (unsigned int)(tmp0));
}
