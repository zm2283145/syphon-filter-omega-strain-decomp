/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7EF8[];
extern char D_004F7F00[];
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

void func_00258440(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F7F00;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00258470(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7EF8;
    return tmp0;
}
