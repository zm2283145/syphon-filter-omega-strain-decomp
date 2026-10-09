/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F75F0[];
extern int func_003CB1D0(void);
extern void func_003D9440(int, int);

void func_00225BF0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CB1D0();
    tmp2 = *(int*)D_004F75F0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}
