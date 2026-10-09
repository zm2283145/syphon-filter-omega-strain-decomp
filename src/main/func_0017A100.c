/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE908[];
extern char D_004FFB50[];
extern char D_00555070[];
extern int func_001310F0(int, int);
extern int func_00131240(int);
extern int func_00131320(int, int);
extern void func_00282020(int);
extern int func_003E1AA0(int, int, int);

int func_0017A100(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    func_001310F0((int)D_004FFB50, tmp0);
    return 0;
}

int func_0017A130(void) {
    func_00131240((int)D_004FFB50);
    return 0;
}

int func_0017A160(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    func_00131320((int)D_004FFB50, tmp0);
    return 0;
}

void func_0017A190(void) {
}

int func_0017A1A0(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE908;
    return tmp0;
}

int func_0017A1B0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

void func_0017A1D0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 36);
    func_00282020(tmp0);
}
