/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F56D8[];
extern char D_004F56F0[];
extern char D_004F56F8[];
extern char D_004F5700[];
extern char D_004F5708[];
extern char D_004F5710[];
extern char D_004F5718[];
extern char D_00555070[];
extern int func_003CC830(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

int func_0021CF70(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp7;
    int tmp10;
    int tmp11;
    int tmp12;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004F5718;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = *(int*)D_004F5718;
    tmp7 = *(int*)D_004F56F0;
    func_003D9400(tmp6, tmp7);
    tmp10 = *(int*)D_004F5718;
    tmp11 = *(int*)D_004F5700;
    tmp12 = func_003D9400(tmp10, tmp11);
    return tmp12;
}

int func_0021CFD0(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5710;
    return tmp0;
}

int func_0021CFE0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

void func_0021D000(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004F5708;
    tmp1 = *(int*)D_004F56D8;
    func_003D9440(tmp0, tmp1);
}

int func_0021D020(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5700;
    return tmp0;
}

void func_0021D030(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004F56F8;
    tmp1 = *(int*)D_004F56D8;
    func_003D9440(tmp0, tmp1);
}

int func_0021D050(void) {
    int tmp0;

    tmp0 = *(int*)D_004F56F0;
    return tmp0;
}
