/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003EBEF0(int);

int func_0036E5D0(int a0) {
    func_003EBEF0((a0 + 136));
    *(int*)((char*)a0) = 0;
    return a0;
}
