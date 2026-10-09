/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00532FE8[];
extern int func_002CCA40(int, int, int);

int func_002CA6F0(void) {
    *(char*)D_00532FE8 = 1;
    return func_002CCA40(8192, 0, 0);
}
