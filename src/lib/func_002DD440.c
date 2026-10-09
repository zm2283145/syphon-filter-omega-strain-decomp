/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004ADB58[];
extern int sprintf(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);

int func_002DD440(int a0, int a1) {
    int a2, a3, t0, t1, t2, t3, v0;
    float f12, f13, f14, f15, f16, f17, f18, f19;
    int cond;

    v0 = a1;
    cond = a0 == 0;
    if (cond) goto L002DD478;
    cond = v0 == 0;
    if (cond) goto L002DD478;
    t1 = *(unsigned char*)((char*)v0 + 3);
    a2 = *(unsigned char*)(char*)v0;
    a1 = (int)D_004ADB58;
    a3 = *(unsigned char*)((char*)v0 + 1);
    t0 = *(unsigned char*)((char*)v0 + 2);
    v0 = sprintf(a0, a1, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    v0 = 0;
    goto L002DD47C;
L002DD478:;
    v0 = 0 + 10;
L002DD47C:;
    goto ret;
ret:
    return v0;
}
