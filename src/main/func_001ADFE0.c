/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001ADFE0(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}

int func_001ADFF0(int a0, int a1) {
    *(float*)((char*)a0 + 8) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 16) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 20) = *(float*)((char*)a1 + 12);
    *(char*)((char*)a0 + 5) = 1;
    return a0;
}
