/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00583970[];
extern char D_00583978[];
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

int func_0043FB40(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 36);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void func_0043FB60(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_00583978;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_0043FB90(void) {
    return (int)D_00583970;
}

int func_0043FBA0(void) {
    int tmp0;

    tmp0 = *(int*)D_00583970;
    return tmp0;
}
