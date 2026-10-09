/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00492EE8[];
extern char D_00492EF0[];
extern char D_004DA380[];
extern char D_004DA840[];
extern int func_0017F3D0(int, int);
extern int func_0017F3E0(int, int, int, float);

int func_003636C0(int a0) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;

    *(int*)((char*)a0) = (int)D_004DA380;
    tmp0 = *(float*)D_00492EE8;
    *(float*)((char*)a0 + 4) = tmp0;
    tmp1 = *(float*)D_00492EE8;
    *(float*)((char*)a0 + 8) = tmp1;
    tmp2 = *(float*)D_00492EF0;
    *(float*)((char*)a0 + 12) = tmp2;
    tmp3 = *(float*)D_00492EE8;
    *(float*)((char*)a0 + 16) = tmp3;
    *(int*)((char*)a0 + 20) = 0;
    func_0017F3E0((a0 + 24), (int)D_00492EE8, (int)D_00492EF0, 0.0f);
    func_0017F3D0((a0 + 48), (a0 + 24));
    *(int*)((char*)a0) = (int)D_004DA840;
    *(char*)((char*)a0 + 56) = 0;
    return a0;
}
