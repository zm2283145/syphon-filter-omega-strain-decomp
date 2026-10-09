/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE948[];
extern int func_003CC800(int);

int func_0017A050(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return func_003CC800(tmp1);
}

void func_0017A060(void) {
}

int func_0017A070(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE948;
    return tmp0;
}
