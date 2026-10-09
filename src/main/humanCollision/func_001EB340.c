/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int HumanColPreset_Copy(int a0, int a1) {
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
