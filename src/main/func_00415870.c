/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055A300[];
extern char D_0055A700[];
extern int func_004153F0(int, int);
extern int func_00415510(int, int);

void func_00415870(int a0) {
    int a1, s0, v0, v1;
    int cond;

    v1 = *(unsigned short*)(char*)(a0 + 20);
    v1 = v1 & 4;
    cond = v1 == 0;
    s0 = a0;
    if (cond) goto L004158B0;
    a1 = (int)D_0055A300;
    v0 = func_00415510(a0, a1);
    v1 = *(unsigned char*)(char*)(s0 + 81);
    cond = v1 == 0;
    if (cond) goto L004158B0;
    a0 = s0;
    a1 = (int)D_0055A700;
    v0 = func_004153F0(a0, a1);
L004158B0:;
    goto ret;
ret:;
}
