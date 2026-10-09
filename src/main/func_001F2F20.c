/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F2ED0(int, int);

int func_001F2F20(int a0, int a1) {
    int loc[1];
    int s0, v0;

    *(int*)(char*)loc = a1;
    s0 = a0;
    a1 = (int)loc;
    v0 = func_001F2ED0(a0, a1);
    v0 = s0;
    goto ret;
ret:
    return v0;
}
