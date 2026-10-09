/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F8310[];
extern char D_004F8318[];
extern char D_00555070[];
extern int func_003CC830(void);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

void func_00261D90(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004F8318;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00261DC0(void) {
    int tmp0;

    tmp0 = *(int*)D_004F8310;
    return tmp0;
}

int func_00261DD0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
