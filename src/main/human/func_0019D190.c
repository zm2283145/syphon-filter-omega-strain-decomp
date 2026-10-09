/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_0019D190(char* self) {
    return self + 16;
}

void* func_0019D1A0(void* self) {
    return self;
}

int func_0019D1B0(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 8) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 16) = *(float*)((char*)a1 + 16);
    *(float*)((char*)a0 + 20) = *(float*)((char*)a1 + 20);
    *(float*)((char*)a0 + 24) = *(float*)((char*)a1 + 24);
    *(float*)((char*)a0 + 32) = *(float*)((char*)a1 + 32);
    *(float*)((char*)a0 + 36) = *(float*)((char*)a1 + 36);
    *(float*)((char*)a0 + 40) = *(float*)((char*)a1 + 40);
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 12);
    *(float*)((char*)a0 + 28) = *(float*)((char*)a1 + 28);
    *(float*)((char*)a0 + 44) = *(float*)((char*)a1 + 44);
    return a0;
}

void* func_0019D220(char* self) {
    return self + 8;
}

int func_0019D230(char* self) {
    return *(int*)(self + 4);
}

int func_0019D240(char* self) {
    return *(int*)(self + 12948);
}
