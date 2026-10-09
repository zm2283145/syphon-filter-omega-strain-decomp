/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FF178[];
extern char D_004FF210[];
extern char D_004FF218[];
extern char D_004FF220[];
extern char D_004FF228[];
extern int func_003C8C50(void);
extern int func_003CC800(int);
extern void func_003D9440(int, int);

int func_0026EDB0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 36);
    return func_003CC800(tmp1);
}

void func_0026EDC0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004FF228;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0026EDF0(void) {
    return (int)D_004FF220;
}

int func_0026EE00(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF220;
    return tmp0;
}

void func_0026EE10(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004FF218;
    tmp1 = *(int*)D_004FF178;
    func_003D9440(tmp0, tmp1);
}

int func_0026EE30(void) {
    return (int)D_004FF210;
}

int func_0026EE40(void) {
    int tmp0;

    tmp0 = *(int*)D_004FF210;
    return tmp0;
}

int func_0026EE50(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 48);
}
