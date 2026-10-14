/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048C438[];
extern int func_002F5160(void);

int func_002D86A0(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_002F5160();
    tmp2 = *(int*)D_0048C438;
    return (tmp0 - tmp2);
}

void func_002D86C8(int a0, int a1, int a2) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 48);
    tmp1 = *(int*)((char*)a0 + 40);
    *(int*)((char*)a0 + 48) = (tmp0 + a2);
    *(int*)((char*)a0 + 40) = (tmp1 + a1);
}

void func_002D86E8(int a0, int a1, int a2) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 52);
    tmp1 = *(int*)((char*)a0 + 44);
    *(int*)((char*)a0 + 52) = (tmp0 + a2);
    *(int*)((char*)a0 + 44) = (tmp1 + a1);
}
