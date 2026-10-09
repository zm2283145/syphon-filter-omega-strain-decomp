/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00398AE0(int a0, int a1) {
    return ((a0 + ((a1 & 255) << 2)) + 4);
}

int func_00398B00(int a0, int a1) {
    return *(int*)(char*)(*(int*)((char*)a0 + 8) + (a1 << 2));
}
