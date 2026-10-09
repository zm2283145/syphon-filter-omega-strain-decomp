/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA780[];
extern int func_003CC830(void);
extern void func_003D9440(int, int);

void func_0015C080(void) {
}

int func_0015C090(void) {
    return 1;
}

int func_0015C0A0(void) {
    return 0;
}

int func_0015C0B0(int a0) {
    return ((unsigned int)(0) < (unsigned int)((*(unsigned short*)((char*)a0 + 4) & *(int*)((char*)*(int*)(char*)a0 + 100))));
}

void func_0015C0D0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004EA780;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}
