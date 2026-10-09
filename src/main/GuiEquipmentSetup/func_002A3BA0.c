/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0041EFA0(int);

int func_002A3BA0(char* self) {
    return *(int*)(self + 0);
}

int func_002A3BB0(int a0) {
    int tmp0;

    tmp0 = func_0041EFA0(a0);
    *(int*)((char*)a0 + 220) = 0;
    *(int*)((char*)a0 + 104) = 1078530011;
    return tmp0;
}
