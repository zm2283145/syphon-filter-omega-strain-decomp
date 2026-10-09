/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00131F70(int a0, int a1) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;

    tmp0 = *(float*)((char*)a1 + 12);
    tmp1 = *(float*)((char*)a1 + 8);
    tmp2 = *(float*)((char*)a1 + 4);
    tmp3 = *(float*)(char*)a1;
    *(float*)((char*)a0 + 32) = tmp3;
    *(float*)((char*)a0 + 36) = tmp2;
    *(float*)((char*)a0 + 40) = tmp1;
    *(float*)((char*)a0 + 44) = tmp0;
    return a0;
}

int func_00131FA0(int a0, int a1) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;

    tmp0 = *(float*)((char*)a1 + 12);
    tmp1 = *(float*)((char*)a1 + 8);
    tmp2 = *(float*)((char*)a1 + 4);
    tmp3 = *(float*)(char*)a1;
    *(float*)((char*)a0 + 16) = tmp3;
    *(float*)((char*)a0 + 20) = tmp2;
    *(float*)((char*)a0 + 24) = tmp1;
    *(float*)((char*)a0 + 28) = tmp0;
    return a0;
}

int func_00131FD0(int a0, int a1) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;

    tmp0 = *(float*)((char*)a1 + 12);
    tmp1 = *(float*)((char*)a1 + 8);
    tmp2 = *(float*)((char*)a1 + 4);
    tmp3 = *(float*)(char*)a1;
    *(float*)((char*)a0) = tmp3;
    *(float*)((char*)a0 + 4) = tmp2;
    *(float*)((char*)a0 + 8) = tmp1;
    *(float*)((char*)a0 + 12) = tmp0;
    return a0;
}

Vec4* func_00132000(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

Vec4* Vec4_Assign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}
