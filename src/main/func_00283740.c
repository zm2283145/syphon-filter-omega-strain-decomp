/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00506280[];
extern int func_003CC830(void);
extern void func_003D9440(int, int);

void func_00283740(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_00506280;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}
