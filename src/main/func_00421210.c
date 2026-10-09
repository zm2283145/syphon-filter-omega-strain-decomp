/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0013D680(int, int);

int func_00421210(int a0, int a1) {
    int tmp2;
    signed char tmp3;

    func_0013D680(a0, a1);
    tmp2 = *(int*)((char*)a1 + 12);
    *(int*)((char*)a0 + 12) = tmp2;
    tmp3 = *(signed char*)((char*)a1 + 16);
    *(char*)((char*)a0 + 16) = tmp3;
    return a0;
}

int func_00421260(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    return (tmp0 + (a1 * 20));
}

int func_00421280(char* self) {
    return *(int*)(self + 4);
}
