/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00571700[];
extern char D_00571708[];
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

void func_004080B0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_00571708;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_004080E0(void) {
    return (int)D_00571700;
}

int func_004080F0(void) {
    int tmp0;

    tmp0 = *(int*)D_00571700;
    return tmp0;
}
