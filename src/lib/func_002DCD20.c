/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048C49C[];
extern char D_0048C4A0[];

int func_002DCD20(int a0) {
    return ((a0 & 65535) + ((unsigned int)((a0 & 65535)) < (unsigned int)(5)));
}

int func_002DCD30(int a0, int a1) {
    *(int*)D_0048C49C = a0;
    *(int*)D_0048C4A0 = a1;
    return 0;
}
