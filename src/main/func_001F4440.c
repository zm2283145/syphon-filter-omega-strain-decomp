/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001F4440(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    return a0;
}

int func_001F4460(int a0, float f12, float f13) {
    *(float*)((char*)a0) = f12;
    *(float*)((char*)a0 + 4) = f13;
    return a0;
}
