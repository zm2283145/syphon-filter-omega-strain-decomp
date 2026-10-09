/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00554F30[];

int func_003D75C0(int a0) {
    int tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(int*)D_00554F30;
    tmp1 = *(int*)((char*)tmp0 + 8);
    tmp2 = *(int*)(char*)(tmp1 + ((a0 + -10) << 2));
    return tmp2;
}
