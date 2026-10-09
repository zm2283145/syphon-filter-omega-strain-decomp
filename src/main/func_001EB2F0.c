/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001EB2F0(int a0) {
    *(char*)((char*)a0 + 48) = 0;
    *(int*)((char*)a0 + 80) = -1;
    *(int*)((char*)a0 + 84) = -1;
    *(int*)((char*)a0 + 88) = 0;
    return a0;
}

int func_001EB310(int a0, int a1, int a2, int a3, int t0) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
    *(int*)((char*)a0 + 4) = *(int*)(char*)a2;
    *(int*)((char*)a0 + 8) = *(int*)(char*)a3;
    *(int*)((char*)a0 + 12) = *(int*)(char*)t0;
    return a0;
}

int func_001EB340(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 8) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 12);
    *(float*)((char*)a0 + 16) = *(float*)((char*)a1 + 16);
    *(float*)((char*)a0 + 20) = *(float*)((char*)a1 + 20);
    *(char*)((char*)a0 + 24) = *(unsigned char*)((char*)a1 + 24);
    return a0;
}

Word* func_001EB380(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* func_001EB390(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
