/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DD460[];
extern char D_004E1220[];
extern int func_00292E80(int);
extern int func_0041EFA0(int);
extern void func_0041F690(int);

int func_002936E0(int a0) {
    int tmp2;

    func_00292E80(a0);
    tmp2 = func_0041EFA0(a0);
    return tmp2;
}

int func_00293710(int a0, int a1) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004E1220;
    *(int*)((char*)a0 + 72) = -2;
    *(int*)((char*)a0) = (int)D_004DD460;
    *(int*)((char*)a0 + 120) = 1092616192;
    *(char*)((char*)a0 + 124) = a1;
    return a0;
}
