/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005061D0[];

int func_0012F370(void) {
    return 0;
}

void func_0012F380(int a0) {
    int tmp0;
    signed char tmp1;

    tmp0 = *(int*)D_005061D0;
    tmp1 = *(signed char*)(char*)tmp0;
    *(int*)D_005061D0 = (tmp0 + 1);
    *(char*)((char*)a0) = ((unsigned int)(0) < (unsigned int)(tmp1));
}

void func_0012F3B0(int a0) {
    int tmp0;
    signed char tmp1;

    tmp0 = *(int*)D_005061D0;
    tmp1 = *(signed char*)(char*)tmp0;
    *(int*)D_005061D0 = (tmp0 + 1);
    *(char*)((char*)a0) = tmp1;
}
