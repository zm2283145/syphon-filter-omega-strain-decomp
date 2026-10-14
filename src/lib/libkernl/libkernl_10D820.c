/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00123320(void);

int func_0010D820(void) {
    int tmp0;

    tmp0 = func_00123320();
    *(int*)((char*)tmp0) = 5;
    return -1;
}

int func_0010D848(void) {
    return -1;
}
