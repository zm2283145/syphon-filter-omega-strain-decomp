/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00225790(int);
extern int func_00225C40(int);
extern int func_00225F00(int, int);

int func_00225A70(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225C40(tmp0);
    tmp3 = *(int*)((char*)a0 + 4);
    tmp4 = func_00225790(tmp3);
    func_00225F00(tmp1, tmp4);
    return 0;
}
