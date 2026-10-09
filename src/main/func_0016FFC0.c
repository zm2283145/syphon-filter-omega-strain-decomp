/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE700[];
extern char D_004EE708[];
extern int func_003C8C50(void);
extern int func_003CC800(int);
extern void func_003D9440(int, int);

int func_0016FFC0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 48);
    return func_003CC800(tmp1);
}

int func_0016FFD0(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void func_0016FFE0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004EE708;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00170010(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE700;
    return tmp0;
}
