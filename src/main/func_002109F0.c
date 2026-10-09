/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F5680[];
extern char D_004F5688[];
extern char D_00555070[];
extern int func_003CC800(int);
extern int func_003CC830(void);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

void func_002109F0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004F5688;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00210A20(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5680;
    return tmp0;
}

int func_00210A30(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

int func_00210A50(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 168);
    return func_003CC800(tmp1);
}
