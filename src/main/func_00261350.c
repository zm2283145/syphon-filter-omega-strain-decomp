/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F82A0[];

void func_00261350(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    *(int*)D_004F82A0 = tmp0;
}
