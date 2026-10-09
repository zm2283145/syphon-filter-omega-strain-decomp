/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00370080(void) {
    return 0;
}

void func_00370090(void) {
}

void func_003700A0(void) {
}

void func_003700B0(void) {
}

void func_003700C0(void) {
}

int func_003700D0(int a0, int a1) {
    int v0, v1;

    v0 = a1 << 2;
    v1 = a0 + v0;
    v1 = *(int*)(char*)v1;
    v0 = 0x14000000;
    v0 = v1 | v0;
    goto ret;
ret:
    return v0;
}
