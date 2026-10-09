/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003E4700(int a0, int a1) {
    Q tmp0;

    tmp0 = *(Q*)(char*)a1;
    *(Q*)((char*)a0) = tmp0;
}

void func_003E4710(char* self, int value) {
    *(int*)(self + 40) = value;
}
