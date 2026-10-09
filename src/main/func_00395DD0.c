/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DF970[];
extern int func_0036D630(int);
extern int func_003CF0E0(int, int, int, int);

int func_00395DD0(int a0, int a1, int a2) {
    int a3, s0, v0, v1;

    a3 = a2;
    a2 = 0 + 1;
    s0 = a0;
    v0 = func_003CF0E0(a0, a1, a2, a3);
    a0 = s0 + 116;
    v0 = (int)D_004DF970;
    *(int*)(char*)s0 = v0;
    *(int*)(char*)(s0 + 108) = s0;
    *(int*)(char*)(s0 + 112) = 0;
    v0 = func_0036D630(a0);
    v1 = 0 + 1;
    v0 = s0;
    *(char*)(char*)(s0 + 496) = v1;
    *(char*)(char*)(s0 + 497) = v1;
    *(char*)(char*)(s0 + 498) = 0;
    *(char*)(char*)(s0 + 499) = 0;
    *(char*)(char*)(s0 + 47) = v1;
    goto ret;
ret:
    return v0;
}

int func_00395E40(int a0) {
    int loc[1];
    int a1, a2, a3, s0, v0, v1;

    a2 = 0 + 1;
    a3 = (int)loc;
    s0 = a0;
    *(int*)(char*)loc = 0;
    v0 = func_003CF0E0(a0, a1, a2, a3);
    a0 = s0 + 116;
    v0 = (int)D_004DF970;
    *(int*)(char*)s0 = v0;
    *(int*)(char*)(s0 + 108) = s0;
    *(int*)(char*)(s0 + 112) = 0;
    v0 = func_0036D630(a0);
    v1 = 0 + 1;
    v0 = s0;
    *(char*)(char*)(s0 + 496) = v1;
    *(char*)(char*)(s0 + 497) = v1;
    *(char*)(char*)(s0 + 498) = 0;
    *(char*)(char*)(s0 + 499) = 0;
    *(char*)(char*)(s0 + 47) = v1;
    goto ret;
ret:
    return v0;
}
