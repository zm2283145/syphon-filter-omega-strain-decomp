/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003D2710(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_003D2720(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

int func_003D2740(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

int func_003D2760(int a0) {
    return (*(int*)(char*)a0 + 8);
}

int func_003D2770(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    return a0;
}

void* func_003D2780(void* self) {
    return self;
}
