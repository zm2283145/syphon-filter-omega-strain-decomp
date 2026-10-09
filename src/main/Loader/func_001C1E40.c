/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048B2F8[];
extern char D_004FFC30[];
extern int func_00236FF0(int, int);
extern int func_00260A50(int);

int func_001C1E40(int a0, int a1, int a2) {
    int tmp2;
    int tmp3;

    func_00236FF0((int)D_0048B2F8, a2);
    tmp2 = *(int*)D_004FFC30;
    tmp3 = func_00260A50(tmp2);
    return tmp3;
}
