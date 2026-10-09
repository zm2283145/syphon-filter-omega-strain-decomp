/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DDB80[];
extern int func_002AD080(int);
extern int func_00424C50(int);

int func_002ACEA0(int a0) {
    int a1, s0, s1, v0, v1;

    s1 = a0;
    v0 = func_00424C50(a0);
    s0 = s1 + 268;
    v0 = (int)D_004DDB80;
    a0 = s0;
    *(int*)(char*)s1 = v0;
    v0 = func_002AD080(a0);
    a1 = 0 + 1;
    a0 = 0 + -1;
    *(char*)(char*)(s0 + 12) = a1;
    v1 = 0 + 2;
    *(int*)(char*)(s1 + 168) = 0;
    v0 = s1;
    *(char*)(char*)(s1 + 172) = a1;
    *(char*)(char*)(s1 + 173) = a1;
    *(int*)(char*)(s1 + 176) = 0;
    *(char*)(char*)(s1 + 180) = 0;
    *(char*)(char*)(s1 + 181) = 0;
    *(int*)(char*)(s1 + 184) = a0;
    *(char*)(char*)(s1 + 88) = v1;
    *(int*)(char*)(s1 + 284) = 0;
    *(char*)(char*)(s1 + 188) = 0;
    *(int*)(char*)(s1 + 204) = a0;
    *(int*)(char*)(s1 + 196) = a0;
    *(int*)(char*)(s1 + 192) = a0;
    goto ret;
ret:
    return v0;
}
