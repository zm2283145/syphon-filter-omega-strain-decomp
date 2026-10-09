/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00412050(int a0) {
    int a1, a2, a3, t0, v1;

    *(int*)(char*)(a0 + 96) = 0;
    v1 = 0x749d0000;
    *(int*)(char*)(a0 + 144) = 0;
    a3 = v1 | 0xc5ae;
    *(int*)(char*)(a0 + 108) = 0;
    t0 = 0x3f800000;
    *(int*)(char*)(a0 + 100) = 0;
    a2 = 0xbf800000;
    *(int*)(char*)(a0 + 148) = 0;
    a1 = 0 + 3;
    *(int*)(char*)(a0 + 112) = 0;
    v1 = 0 + 1;
    *(int*)(char*)(a0 + 104) = 0;
    *(int*)(char*)(a0 + 152) = 0;
    *(int*)(char*)(a0 + 116) = 0;
    *(int*)(char*)(a0 + 128) = t0;
    *(int*)(char*)(a0 + 132) = t0;
    *(int*)(char*)(a0 + 136) = t0;
    *(int*)(char*)(a0 + 140) = t0;
    *(int*)(char*)(a0 + 156) = a3;
    *(int*)(char*)(a0 + 160) = a2;
    *(int*)(char*)(a0 + 164) = a1;
    *(int*)(char*)(a0 + 168) = v1;
    *(char*)(char*)(a0 + 172) = 0;
    goto ret;
ret:;
}
