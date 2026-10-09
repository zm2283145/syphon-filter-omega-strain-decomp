/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC04[];
extern int func_002CAC80(int, int);
extern void func_0033D360(int);
extern int func_004147A0(void);
extern int func_0044F6B0(int);

int func_0029ECD0(int a0) {
    int tmp8;
    int tmp9;
    int tmp11;
    int tmp12;
    int tmp13;
    int tmp14;

    func_0033D360(a0);
    func_0044F6B0((a0 + 152));
    func_0044F6B0((a0 + 180));
    func_0044F6B0((a0 + 208));
    tmp8 = *(int*)D_004FFC04;
    *(char*)((char*)tmp8 + 42) = 1;
    tmp9 = func_004147A0();
    tmp11 = *(int*)((char*)tmp9 + 104);
    *(int*)((char*)tmp9 + 104) = (tmp11 & -13);
    tmp12 = *(int*)D_004FFC04;
    tmp13 = *(int*)((char*)a0 + 72);
    tmp14 = func_002CAC80(tmp12, tmp13);
    return tmp14;
}
