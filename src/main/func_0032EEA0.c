/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00337B10(int, int, int, int);

int func_0032EEA0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_00337B10(a0, (tmp1 + (tmp0 << 3)), 1, a1);
}

int func_0032EEC0(int a0, int a1, int a2) {
    *(int*)((char*)a0) = a1;
    *(int*)((char*)a0 + 4) = a2;
    return a0;
}
