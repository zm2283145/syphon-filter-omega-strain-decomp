/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFD30[];
extern int func_00147840(int, int);

void func_00286950(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FFD30;
    *(int*)((char*)a0 + 108) = a1;
    tmp1 = func_00147840(tmp0, a1);
    *(int*)((char*)a0 + 104) = tmp1;
}
