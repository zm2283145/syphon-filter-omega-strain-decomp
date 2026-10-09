/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003EE740(int);

int func_003E7ED0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 112);
    return func_003EE740(tmp0);
}
