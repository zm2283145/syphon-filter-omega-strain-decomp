/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002B0F00(int, int);
extern int func_003CC820(int);

int func_002B0EC0(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_003CC820(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    v0 = func_002B0F00(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
