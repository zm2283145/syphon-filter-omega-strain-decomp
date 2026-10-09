/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00209F60(int);

int func_0020A050(int a0) {
    int tmp0;

    tmp0 = func_00209F60(a0);
    return (tmp0 + 8);
}

void* func_0020A070(void* self) {
    return self;
}
