/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CC800(int);

int func_00408060(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 44);
}

int func_00408070(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 45);
}

int func_00408080(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 40);
    return func_003CC800(tmp1);
}
