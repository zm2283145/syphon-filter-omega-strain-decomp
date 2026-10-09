/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003D3600(int a0) {
    return (*(int*)((char*)a0 + 4) + 8);
}

void func_003D3610(char* self, float value) {
    *(float*)(self + 3988) = value;
}

void func_003D3620(int a0, int a1, int a2) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 8) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 12);
    *(char*)((char*)a0 + 261) = a2;
    *(char*)((char*)a0 + 262) = 1;
}

Vec4* func_003D3650(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}
