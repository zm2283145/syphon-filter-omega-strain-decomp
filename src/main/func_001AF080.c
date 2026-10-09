/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048A198[];
extern char D_0048A1A0[];
extern char D_004DA380[];
extern char D_004DA840[];
extern int Curve_Bind(int, int);
extern int Curve_InitConstant(int, int, int, float);
extern void func_001BB100(int, int, int);

int func_001AF080(int a0) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;

    *(int*)((char*)a0) = (int)D_004DA380;
    tmp0 = *(float*)D_0048A198;
    *(float*)((char*)a0 + 4) = tmp0;
    tmp1 = *(float*)D_0048A198;
    *(float*)((char*)a0 + 8) = tmp1;
    tmp2 = *(float*)D_0048A1A0;
    *(float*)((char*)a0 + 12) = tmp2;
    tmp3 = *(float*)D_0048A198;
    *(float*)((char*)a0 + 16) = tmp3;
    *(int*)((char*)a0 + 20) = 0;
    Curve_InitConstant((a0 + 24), (int)D_0048A198, (int)D_0048A1A0, 0.0f);
    Curve_Bind((a0 + 48), (a0 + 24));
    *(int*)((char*)a0) = (int)D_004DA840;
    *(char*)((char*)a0 + 56) = 0;
    return a0;
}

int func_001AF120(int a0) {
    return (*(int*)(char*)a0 + 24);
}

int func_001AF130(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_001AF150(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_001AF160(int a0) {
    int loc[1];
    int a1, a2, s0, v1;

    s0 = a0;
    a0 = (int)loc;
    func_001BB100(a0, a1, a2);
    v1 = *(int*)(char*)loc;
    *(int*)(char*)s0 = v1;
    goto ret;
ret:;
}
