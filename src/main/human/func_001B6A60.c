/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001B6A90(int);

int func_001B6A60(int a0) {
    func_001B6A90(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
