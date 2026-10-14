/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002FDA18(int, int);

int func_002FD088(int a0, int a1) {
    int tmp0;

    tmp0 = func_002FDA18((a0 & 65535), (a1 & 255));
    return tmp0;
}
