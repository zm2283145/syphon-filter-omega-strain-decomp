/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC2C[];
extern int GObj_IdentityB(int);
extern int func_0014A690(int);
extern int func_00242B40(int, int, int, int, int);
extern int func_00267FC0(int);
extern int func_00268010(int);

int func_00267F90(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_0014A690(tmp0);
    func_00267FC0(tmp1);
    return 0;
}

int func_00267FC0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 48);
    tmp1 = *(int*)D_004FFC2C;
    return func_00242B40(tmp1, (tmp0 + 12), 0, 0, 1);
}

int func_00267FE0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = GObj_IdentityB(tmp0);
    func_00268010(tmp1);
    return 0;
}

int func_00268010(int a0) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    return func_00242B40(tmp0, (a0 + 12), 0, 0, 1);
}
