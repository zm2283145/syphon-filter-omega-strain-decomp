/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0013BCB0(int, int);
extern int func_0032A0B0(int, int);

int func_0032A050(int a0, int a1) {
    int s0, s1, s2, v0, v1;

    s2 = a0;
    s1 = a1;
    v0 = func_0013BCB0(a0, a1);
    s0 = s2 + 12;
    a1 = s1 + 12;
    a0 = s0;
    v0 = func_0032A0B0(a0, a1);
    v1 = *(unsigned char*)(char*)(s1 + 24);
    v0 = s2;
    *(char*)(char*)(s0 + 12) = v1;
    v1 = *(int*)(char*)(s1 + 28);
    *(int*)(char*)(s2 + 28) = v1;
    goto ret;
ret:
    return v0;
}
