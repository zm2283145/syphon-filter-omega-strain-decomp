/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005723D0[];
extern int func_003FE0D0(void);

void func_002CCA20(int a0, int a1) {
    *(char*)D_005723D0 = 0;
    *(char*)((char*)a0 + 48) = a1;
}

int func_002CCA30(void) {
    return func_003FE0D0();
}
