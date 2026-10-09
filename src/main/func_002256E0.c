/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7670[];
extern int func_00225790(int);
extern void func_00228D90(int);
extern int func_003CB1D0(void);
extern void func_003D9440(int, int);

int func_002256E0(int a0) {
    unsigned char tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(unsigned char*)((char*)a0 + 4);
    tmp1 = *(int*)(char*)a0;
    tmp2 = func_00225790(tmp1);
    *(char*)((char*)tmp2 + 38) = tmp0;
    return 0;
}

int func_00225710(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225790(tmp0);
    func_00228D90(tmp1);
    return 0;
}

void func_00225740(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CB1D0();
    tmp2 = *(int*)D_004F7670;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}
