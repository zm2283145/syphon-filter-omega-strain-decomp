/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE898[];
extern char D_004EE8A0[];
extern char D_00555070[];
extern int func_003CC830(void);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

void func_00179160(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004EE8A0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00179190(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE898;
    return tmp0;
}

int func_001791A0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
