/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7D20[];
extern char D_004F7D28[];
extern int func_003C8C50(void);
extern void func_003D9440(int, int);

int func_00237500(int a0) {
    return *(unsigned char*)((char*)*(int*)(char*)a0 + 36);
}

void func_00237510(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003C8C50();
    tmp2 = *(int*)D_004F7D28;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_00237540(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7D20;
    return tmp0;
}
