/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC2C[];
extern void func_0022C0D0(int);
extern int func_0022C120(int);
extern void func_00272D10(int, int);
extern int func_00272D50(int, int, int);
extern int func_003CC820(int);

int func_0022C0A0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003CC820(tmp0);
    func_0022C0D0(tmp1);
    return 0;
}

void func_0022C0D0(int a0) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    func_00272D10((tmp0 + 144), a0);
}

int func_0022C0F0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003CC820(tmp0);
    func_0022C120(tmp1);
    return 0;
}

int func_0022C120(int a0) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    return func_00272D50((tmp0 + 144), (a0 + 12), 0);
}
