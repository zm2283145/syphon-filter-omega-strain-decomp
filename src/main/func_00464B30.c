/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004C28A8[];
extern char D_004FFC2C[];
extern int func_0026DBC0(int);
extern int func_0041DB80(int, int);
extern int func_0041EFA0(int);
extern int func_0041F150(int);

int func_00464B30(int a0) {
    int tmp2;
    int tmp3;
    int tmp4;
    int tmp5;

    func_0041EFA0(a0);
    tmp2 = *(int*)D_004FFC2C;
    tmp3 = *(int*)((char*)tmp2 + 1696);
    *(int*)((char*)a0 + 76) = tmp3;
    tmp4 = *(int*)((char*)a0 + 76);
    tmp5 = func_0026DBC0(tmp4);
    return tmp5;
}

void func_00464B70(int a0) {
    int tmp2;

    func_0041F150(a0);
    tmp2 = func_0041DB80(a0, (int)D_004C28A8);
    *(int*)((char*)a0 + 72) = tmp2;
}
