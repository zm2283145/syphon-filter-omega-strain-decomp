/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00129A70(int, int, int);
extern int func_003EBEF0(int);

int func_0036E4B0(int a0, int a1, int a2, int a3) {
    int s0, s1, s2, s3, v0;
    int cond;

    s3 = a1;
    s2 = a2;
    s1 = a3;
    s0 = a0;
    a0 = s0 + 136;
    v0 = func_003EBEF0(a0);
    *(int*)(char*)s0 = 0;
    a1 = s3;
    a0 = s0 + 4;
    a2 = 0 + 128;
    *(int*)(char*)s0 = 0;
    v0 = func_00129A70(a0, a1, a2);
    *(int*)(char*)(s0 + 152) = s2;
    v0 = *(int*)(char*)s0;
    v0 = v0 | 1;
    cond = s1 == 0;
    *(int*)(char*)s0 = v0;
    if (cond) goto L0036E518;
    v0 = *(int*)(char*)s0;
    v0 = v0 | 4;
    *(int*)(char*)s0 = v0;
L0036E518:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}

int func_0036E540(int a0, int a1, int a2, int a3) {
    int s0, s1, s2, s3, v0;
    int cond;

    s3 = a1;
    s2 = a2;
    s1 = a3;
    s0 = a0;
    a0 = s0 + 136;
    v0 = func_003EBEF0(a0);
    *(int*)(char*)s0 = 0;
    a1 = s3;
    a0 = s0 + 4;
    a2 = 0 + 128;
    *(int*)(char*)s0 = 0;
    v0 = func_00129A70(a0, a1, a2);
    *(int*)(char*)(s0 + 152) = s2;
    v0 = *(int*)(char*)s0;
    v0 = v0 | 2;
    cond = s1 == 0;
    *(int*)(char*)s0 = v0;
    if (cond) goto L0036E5A8;
    v0 = *(int*)(char*)s0;
    v0 = v0 | 4;
    *(int*)(char*)s0 = v0;
L0036E5A8:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}

int func_0036E5D0(int a0) {
    func_003EBEF0((a0 + 136));
    *(int*)((char*)a0) = 0;
    return a0;
}
