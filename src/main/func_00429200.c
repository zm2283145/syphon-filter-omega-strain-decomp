/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00582550[];
extern int Transport_Send(int, int, int, int);

int func_00429200(int a0, int a1, int a2) {
    return Transport_Send(a1, a0, -1, a2);
}

void func_00429220(int a0) {
    int a1, a2, a3, t0, t1, v1;
    int cond;

    t1 = 0;
    t0 = (int)D_00582550;
    a2 = 0 + -77;
L00429230:;
    a3 = a0 + t1;
    a1 = *(signed char*)(char*)a3;
    t1 = t1 + 8;
    v1 = t1 < 32;
    a1 = a1 ^ a2;
    *(char*)(char*)t0 = a1;
    a1 = *(signed char*)(char*)(a3 + 1);
    a1 = a1 ^ a2;
    *(char*)(char*)(t0 + 1) = a1;
    a1 = *(signed char*)(char*)(a3 + 2);
    a1 = a1 ^ a2;
    *(char*)(char*)(t0 + 2) = a1;
    a1 = *(signed char*)(char*)(a3 + 3);
    a1 = a1 ^ a2;
    *(char*)(char*)(t0 + 3) = a1;
    a1 = *(signed char*)(char*)(a3 + 4);
    a1 = a1 ^ a2;
    *(char*)(char*)(t0 + 4) = a1;
    a1 = *(signed char*)(char*)(a3 + 5);
    a1 = a1 ^ a2;
    *(char*)(char*)(t0 + 5) = a1;
    a1 = *(signed char*)(char*)(a3 + 6);
    a1 = a1 ^ a2;
    *(char*)(char*)(t0 + 6) = a1;
    a1 = *(signed char*)(char*)(a3 + 7);
    a1 = a1 ^ a2;
    *(char*)(char*)(t0 + 7) = a1;
    cond = v1 != 0;
    t0 = t0 + 8;
    if (cond) goto L00429230;
    goto ret;
ret:;
}
