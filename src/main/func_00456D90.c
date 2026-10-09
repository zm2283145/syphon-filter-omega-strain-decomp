/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E1430[];
extern int func_00368E10(int, int, int);

int func_00456D90(int a0) {
    int a1, a2, s0, v0, v1;

    a1 = 0 + 1;
    a2 = a1;
    s0 = a0;
    v0 = func_00368E10(a0, a1, a2);
    v0 = s0;
    v1 = (int)D_004E1430;
    *(int*)(char*)s0 = v1;
    *(int*)((char*)s0 + 144) = 0;
    *(int*)((char*)s0 + 148) = 0;
    *(int*)((char*)s0 + 152) = 0;
    *(int*)((char*)s0 + 156) = 0;
    *(int*)((char*)s0 + 160) = 0;
    *(int*)((char*)s0 + 164) = 0;
    *(int*)((char*)s0 + 168) = 0;
    v1 = *(unsigned short*)((char*)s0 + 20);
    v1 = v1 & 65503;
    *(short*)((char*)s0 + 20) = v1;
    goto ret;
ret:
    return v0;
}
