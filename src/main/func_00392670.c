/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0053B4F0[];
extern char D_0053B4F8[];
extern char D_0053B500[];
extern char D_0053B508[];
extern char D_00555070[];
extern int func_003CC830(void);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

void func_00392670(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_0053B508;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_003926A0(void) {
    int tmp0;

    tmp0 = *(int*)D_0053B500;
    return tmp0;
}

int func_003926B0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

void func_003926D0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_0053B4F8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00392700(void) {
    int tmp0;

    tmp0 = *(int*)D_0053B4F0;
    return tmp0;
}

int func_00392710(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
