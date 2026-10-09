/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00555070[];
extern int func_003DCF70(int, int, int, int);

int func_003DC540(int a0, int a1, int a2, int a3, int t0) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003DCF70((int)D_00555070, a1, a3, t0);
    tmp2 = *(int*)((char*)a0 + 72);
    tmp3 = *(int*)((char*)tmp0 + 20);
    *(int*)((char*)(tmp2 + (a2 << 2))) = tmp3;
    return tmp0;
}
