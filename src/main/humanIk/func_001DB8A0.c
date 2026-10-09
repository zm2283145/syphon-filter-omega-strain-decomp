/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001DB8A0(int a0, int a1) {
    *(char*)((char*)a0) = *(signed char*)(char*)a1;
    *(char*)((char*)a0 + 1) = *(signed char*)((char*)a1 + 1);
    return a0;
}
