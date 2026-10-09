/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003EEE70(int, int);

int func_003E8EB0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 112);
    return func_003EEE70(tmp0, a0);
}
