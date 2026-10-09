/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005061D0[];

void func_0022F2A0(int a0) {
    int v1;

    a0 = *(int*)(char*)(a0 + 36);
    v1 = *(int*)(char*)D_005061D0;
    *(char*)(char*)v1 = a0;
    v1 = *(int*)(char*)D_005061D0;
    v1 = v1 + 1;
    *(int*)(char*)D_005061D0 = v1;
    goto ret;
ret:;
}
