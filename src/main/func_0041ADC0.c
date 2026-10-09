/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0A40[];
extern int func_0041C7D0(int);

int func_0041ADC0(int a0) {
    int s0, v0, v1;

    s0 = a0;
    v0 = func_0041C7D0(a0);
    v1 = 0 + 100;
    v0 = (int)D_004E0A40;
    *(int*)(char*)s0 = v0;
    a0 = *(unsigned short*)((char*)s0 + 20);
    v0 = s0;
    a0 = a0 | 128;
    *(short*)((char*)s0 + 20) = a0;
    *(char*)((char*)s0 + 128) = 0;
    *(int*)((char*)s0 + 132) = v1;
    *(int*)((char*)s0 + 140) = 0;
    *(char*)((char*)s0 + 136) = 0;
    goto ret;
ret:
    return v0;
}
