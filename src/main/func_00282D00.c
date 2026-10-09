/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CC990(int, int, int);

int func_00282D00(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)a0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)(v0 + 96);
    a2 = 0;
    v0 = func_003CC990(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
