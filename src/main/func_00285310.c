/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CC990(int, int, int);

int func_00285310(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 96);
    return func_003CC990(tmp0, a1, 0);
}
