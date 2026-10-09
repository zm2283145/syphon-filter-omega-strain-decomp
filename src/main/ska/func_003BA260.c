/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003BA290(int);

int func_003BA260(int a0) {
    func_003BA290(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
