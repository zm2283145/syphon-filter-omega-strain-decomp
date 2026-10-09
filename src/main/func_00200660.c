/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Motion_Lookup(int, int);
extern int func_00198AD0(int, int);
extern int func_001ADFE0(int, int);

int func_00200660(int a0, int a1, int a2, int a3) {
    int s0, s1, v0;

    s1 = a0;
    s0 = a3;
    a0 = a2;
    v0 = Motion_Lookup(a0, a1);
    a1 = v0;
    a0 = s1;
    v0 = func_001ADFE0(a0, a1);
    a1 = s0;
    a0 = s1 + 4;
    v0 = func_00198AD0(a0, a1);
    v0 = s1;
    goto ret;
ret:
    return v0;
}
