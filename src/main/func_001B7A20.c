/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Curve_Bind(int, int);
extern int Curve_InitConstant(int, int, int, float);
extern char D_0048A1B8[];
extern char D_0048A1C0[];
extern char D_004DA380[];
extern char D_004DA7D0[];

Rel* func_001B7A20(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_001B7A40(int a0) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;

    *(int*)((char*)a0) = (int)D_004DA380;
    tmp0 = *(float*)D_0048A1B8;
    *(float*)((char*)a0 + 4) = tmp0;
    tmp1 = *(float*)D_0048A1B8;
    *(float*)((char*)a0 + 8) = tmp1;
    tmp2 = *(float*)D_0048A1C0;
    *(float*)((char*)a0 + 12) = tmp2;
    tmp3 = *(float*)D_0048A1B8;
    *(float*)((char*)a0 + 16) = tmp3;
    *(int*)((char*)a0 + 20) = 0;
    Curve_InitConstant((a0 + 24), (int)D_0048A1B8, (int)D_0048A1C0, 0.0f);
    Curve_Bind((a0 + 48), (a0 + 24));
    *(int*)((char*)a0) = (int)D_004DA7D0;
    return a0;
}

Rel* func_001B7AE0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
