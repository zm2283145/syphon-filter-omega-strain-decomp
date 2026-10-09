/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00543610[];

void func_003C8C40(void) {
}

int func_003C8C50(void) {
    return (int)D_00543610;
}

int func_003C8C60(void) {
    int tmp0;

    tmp0 = *(int*)D_00543610;
    return tmp0;
}
