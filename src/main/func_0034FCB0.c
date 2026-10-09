/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DEE70[];
extern int func_0034FE40(int);
extern int func_00356FF0(int);

int func_0034FCB0(int a0) {
    int s0, s1, v0, v1;

    s1 = a0;
    v0 = func_00356FF0(a0);
    s0 = s1 + 112;
    v0 = (int)D_004DEE70;
    a0 = s0;
    *(int*)(char*)s1 = v0;
    v0 = func_0034FE40(a0);
    v1 = 0 + 1;
    v0 = s1;
    *(char*)(char*)(s0 + 12) = v1;
    *(int*)(char*)(s1 + 108) = 0;
    goto ret;
ret:
    return v0;
}
