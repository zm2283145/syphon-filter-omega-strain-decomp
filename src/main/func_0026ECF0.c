/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FF178[];
extern char D_004FF240[];
extern char D_004FF248[];
extern char D_004FF250[];
extern char D_004FF258[];
extern int func_003C8C50(void);
extern int func_003CC800(int);
extern void func_003D9440(int, int);

int func_0026ECF0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return func_003CC800(tmp1);
}

void func_0026ED00(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004FF258;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0026ED30(void) {
    return (int)D_004FF250;
}

int func_0026ED40(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF250;
    return tmp0;
}

void func_0026ED50(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF248;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026ED70(void) {
    return (int)D_004FF240;
}

int func_0026ED80(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF240;
    return tmp0;
}
