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

int func_003D3670(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 2672);
    return ((a0 + (tmp0 * 272)) + 496);
}

void func_003D3690(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 2672);
    *(int*)((char*)a0 + 2672) = (tmp0 + 1);
    tmp1 = *(int*)((char*)a0 + 2672);
    *(char*)((char*)(a0 + (tmp1 * 272)) + 758) = 1;
}

void func_003D36C0(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 244) = (a2 & 255);
}

unsigned char func_003D36D0(unsigned char* self) {
    return self[16];
}

int func_003D36E0(char* self) {
    return *(int*)(self + 12);
}

int func_003D36F0(char* self) {
    return *(int*)(self + 8);
}
