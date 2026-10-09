/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005061D0[];

int func_00199290(void) {
    int tmp0;
    signed char tmp1;

    tmp0 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp0 + 1);
    tmp1 = *(signed char*)(char*)tmp0;
    return tmp1;
}
