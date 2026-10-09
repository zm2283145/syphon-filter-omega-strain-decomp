/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F5881[];
extern char D_004F58C1[];

int func_00223A98(void) {
    int a0, v0, v1;

    v1 = *(unsigned char*)(char*)D_004F58C1;
    a0 = *(unsigned char*)(char*)D_004F5881;
    v0 = 0 + -1;
    v1 = v1 ^ a0;
    if (v1 == 0) v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00223AB8(void) {
    int a0, v0, v1;

    v1 = *(unsigned char*)(char*)D_004F58C1;
    a0 = *(unsigned char*)(char*)D_004F5881;
    v0 = 0 + -1;
    v1 = v1 ^ a0;
    if (v1 == 0) v0 = 0;
    goto ret;
ret:
    return v0;
}
