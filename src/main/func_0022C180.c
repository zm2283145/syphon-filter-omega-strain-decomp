/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004A64A0[];
extern char D_004FFC2C[];
extern int func_00127358(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern int func_0022C1F0(int);
extern int func_00273890(int, int, int);
extern int GObj_IdentityB(int);

int func_0022C180(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = GObj_IdentityB(tmp0);
    func_0022C1F0(tmp1);
    return 0;
}

int func_0022C1B0(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3, float f12, float f13, float f14, float f15, float f16, float f17, float f18, float f19) {
    int tmp2;

    func_00127358((int)D_004A64A0, a1, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    tmp2 = func_0022C1F0(a0);
    return tmp2;
}

int func_0022C1F0(int a0) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    return func_00273890((tmp0 + 144), (a0 + 12), 1);
}
