/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00571740[];
extern char D_00571748[];
extern int func_0040B790(int, int);
extern void func_0040C990(int, int);

int func_0040C9D0(int a0) {
    int tmp0;
    int tmp3;

    tmp0 = *(int*)D_00571748;
    func_0040C990(a0, tmp0);
    tmp3 = func_0040B790(tmp0, a0);
    return tmp3;
}

int func_0040CA20(void) {
    int tmp0;

    tmp0 = *(int*)D_00571740;
    return tmp0;
}

int func_0040CA30(void) {
    int tmp0;

    tmp0 = *(int*)D_00571748;
    return tmp0;
}
