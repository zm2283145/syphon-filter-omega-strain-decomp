/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001D7840(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
    *(int*)((char*)a0 + 4) = *(int*)((char*)a1 + 4);
    *(float*)((char*)a0 + 8) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 12);
    *(int*)((char*)a0 + 16) = *(int*)((char*)a1 + 16);
    *(float*)((char*)a0 + 20) = *(float*)((char*)a1 + 20);
    *(int*)((char*)a0 + 24) = *(int*)((char*)a1 + 24);
    *(int*)((char*)a0 + 28) = *(int*)((char*)a1 + 28);
    *(char*)((char*)a0 + 32) = *(unsigned char*)((char*)a1 + 32);
    return a0;
}
