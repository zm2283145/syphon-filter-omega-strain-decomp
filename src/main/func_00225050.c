/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00225790(int);
extern int func_00229000(int);
extern int func_00229100(int);

int func_00225050(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225790(tmp0);
    func_00229100(tmp1);
    return 0;
}

int func_00225080(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225790(tmp0);
    func_00229000(tmp1);
    return 0;
}

int func_002250B0(int a0) {
    int tmp0;
    int tmp1;
    unsigned char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225790(tmp0);
    tmp3 = *(unsigned char*)((char*)tmp1 + 37);
    return tmp3;
}

int Script_Objective_WasFailed(int a0) {
    int tmp0;
    int tmp1;
    signed char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225790(tmp0);
    tmp3 = *(signed char*)((char*)tmp1 + 36);
    return ((unsigned int)((tmp3 ^ 2)) < (unsigned int)(1));
}

int Script_Objective_IsComplete(int a0) {
    int tmp0;
    int tmp1;
    signed char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225790(tmp0);
    tmp3 = *(signed char*)((char*)tmp1 + 36);
    return ((unsigned int)((tmp3 ^ 1)) < (unsigned int)(1));
}

int func_00225130(int a0) {
    unsigned char tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(unsigned char*)((char*)a0 + 4);
    tmp1 = *(int*)(char*)a0;
    tmp2 = func_00225790(tmp1);
    *(char*)((char*)tmp2 + 36) = tmp0;
    return 0;
}

int func_00225160(int a0) {
    int tmp0;
    int tmp1;
    unsigned char tmp3;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00225790(tmp0);
    tmp3 = *(unsigned char*)((char*)tmp1 + 36);
    return tmp3;
}
