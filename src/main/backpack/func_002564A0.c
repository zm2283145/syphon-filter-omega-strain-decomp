/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00258E10(int, int, int, int);

int func_002564A0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_00258E10(a0, (tmp1 + (tmp0 << 3)), 1, a1);
}

int func_002564C0(int a0, int a1) {
    return ((unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)) < (unsigned int)(1));
}

void func_002564E0(int a0, int a1) {
    *(int*)((char*)a0) = (*(int*)((char*)a1 + 8) + (*(int*)((char*)a1 + 4) << 3));
}
