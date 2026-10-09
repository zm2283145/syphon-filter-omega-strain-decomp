/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003B0120(int a0, int a1) {
    return ((unsigned int)((*(int*)(char*)a0 ^ a1)) < (unsigned int)(1));
}

int func_003B0130(char* self) {
    return *(int*)(self + 4);
}

int func_003B0140(char* self) {
    return *(int*)(self + 0);
}

int func_003B0150(int a0, int a1) {
    return (*(int*)((char*)a1 + 144) + (*(int*)((char*)a0 + 32) << 3));
}

int func_003B0170(char* self) {
    return *(int*)(self + 0);
}

int func_003B0180(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    return (tmp0 + (a1 * 20));
}

int func_003B01A0(int a0, int a1) {
    return *(int*)((char*)(*(int*)((char*)a0 + 144) + (a1 << 3)) + 4);
}
