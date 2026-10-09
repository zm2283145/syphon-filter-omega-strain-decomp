/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00129A70(int, int, int);
extern int func_00461770(int, int, int, int);

int func_00462620(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 8);
    tmp1 = *(int*)((char*)a0 + 4);
    return func_00461770(a0, (tmp0 + (tmp1 * 12)), 1, a1);
}

int func_00462650(int a0, int a1, int a2) {
    func_00129A70(a0, a1, 8);
    *(int*)((char*)a0 + 8) = a2;
    return a0;
}
