/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E10C0[];
extern int func_0041F690(int);

int func_0043F910(int a0) {
    int a1, a2, s0, v0, v1;

    s0 = a0;
    v0 = func_0041F690(a0);
    a1 = 0 + 100;
    v0 = (int)D_004E10C0;
    a0 = 0 + 10;
    *(int*)(char*)s0 = v0;
    v1 = 0 + 1;
    a2 = *(unsigned short*)((char*)s0 + 20);
    v0 = s0;
    a2 = a2 | 128;
    *(short*)((char*)s0 + 20) = a2;
    *(char*)((char*)s0 + 96) = 0;
    *(int*)((char*)s0 + 100) = 0;
    *(int*)((char*)s0 + 104) = 0;
    *(int*)((char*)s0 + 108) = a1;
    *(int*)((char*)s0 + 112) = a0;
    *(char*)((char*)s0 + 76) = 0;
    *(int*)((char*)s0 + 80) = 0;
    *(int*)((char*)s0 + 88) = 0;
    *(char*)((char*)s0 + 77) = 0;
    *(int*)((char*)s0 + 84) = 0;
    *(int*)((char*)s0 + 88) = 0;
    *(int*)((char*)s0 + 72) = v1;
    goto ret;
ret:
    return v0;
}
