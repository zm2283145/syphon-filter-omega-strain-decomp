/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00493A20[];
extern char D_00493A40[];
extern char D_0055D470[];

int func_003FE090(void) {
    unsigned char tmp0;
    int tmp1;

    tmp0 = *(unsigned char*)D_0055D470;
    tmp1 = *(int*)(char*)((int)D_00493A40 + (tmp0 << 2));
    return tmp1;
}

int func_003FE0B0(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)((int)D_00493A20 + ((a0 & 255) << 2));
    return tmp0;
}

int func_003FE0D0(void) {
    unsigned char tmp0;
    int tmp1;

    tmp0 = *(unsigned char*)D_0055D470;
    tmp1 = *(int*)(char*)((int)D_00493A20 + (tmp0 << 2));
    return tmp1;
}

int func_003FE0F0(void) {
    signed char tmp0;

    tmp0 = *(signed char*)D_0055D470;
    return tmp0;
}

void func_003FE100(int a0) {
    *(char*)D_0055D470 = a0;
}
