/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0036DFB0(int, int, int);
extern int func_0036E5D0(int);
extern int func_003F8450(int);
extern int func_003F8D20(int);

int func_003F9380(int a0, int a1, int a2) {
    int s0, s1, s2, v0;

    s2 = a0;
    s1 = a1;
    *(int*)(char*)a0 = 0;
    s0 = a2;
    *(int*)(char*)(a0 + 4) = 0;
    *(int*)(char*)(a0 + 8) = 0;
    *(int*)(char*)(a0 + 12) = 0;
    *(int*)(char*)(a0 + 16) = 0;
    *(int*)(char*)(a0 + 20) = 0;
    *(int*)(char*)(a0 + 24) = 0;
    *(int*)(char*)(a0 + 28) = 0;
    *(int*)(char*)(a0 + 32) = 0;
    *(int*)(char*)(a0 + 36) = 0;
    *(int*)(char*)(a0 + 40) = 0;
    *(int*)(char*)(a0 + 44) = 0;
    *(int*)(char*)(a0 + 48) = 0;
    *(int*)(char*)(a0 + 52) = 0;
    *(int*)(char*)(a0 + 56) = 0;
    *(int*)(char*)(a0 + 60) = 0;
    *(int*)(char*)(a0 + 64) = 0;
    *(int*)(char*)(a0 + 68) = 0;
    *(int*)(char*)(a0 + 72) = 0;
    *(int*)(char*)(a0 + 76) = 0;
    a0 = s2 + 108;
    v0 = func_0036E5D0(a0);
    *(int*)(char*)(s2 + 392) = 0;
    a0 = s2 + 400;
    *(int*)(char*)(s2 + 396) = 0;
    v0 = func_0036E5D0(a0);
    *(int*)(char*)(s2 + 556) = s0;
    v0 = 0 + 1;
    *(char*)(char*)(s2 + 560) = 0;
    a0 = s2 + 400;
    *(char*)(char*)(s2 + 561) = 0;
    a1 = s1 + 4;
    *(char*)(char*)(s2 + 562) = 0;
    a2 = s1;
    *(char*)(char*)(s2 + 563) = 0;
    *(char*)(char*)(s2 + 564) = 0;
    *(char*)(char*)(s2 + 565) = 0;
    *(char*)(char*)(s2 + 566) = v0;
    v0 = func_0036DFB0(a0, a1, a2);
    a0 = s2;
    v0 = func_003F8D20(a0);
    a0 = s2;
    v0 = func_003F8450(a0);
    v0 = s2;
    goto ret;
ret:
    return v0;
}
