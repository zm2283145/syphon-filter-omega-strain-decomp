/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00374DF0(int);
extern float func_0037D9A0(int);

int func_00411550(int a0) {
    func_0037D9A0(a0);
    return (a0 + 3776);
}

int func_00411580(int a0) {
    int s0, v0, v1;

    v1 = *(int*)(char*)(a0 + 2672);
    v0 = v1 << 4;
    v0 = v0 + v1;
    v0 = v0 << 4;
    v0 = a0 + v0;
    s0 = v0 + 496;
    a0 = s0;
    v0 = func_00374DF0(a0);
    v0 = s0 + 160;
    goto ret;
ret:
    return v0;
}

int func_004115C0(int a0) {
    int s0, v0, v1;

    v1 = *(int*)(char*)(a0 + 2672);
    v0 = v1 << 4;
    v0 = v0 + v1;
    v0 = v0 << 4;
    v0 = a0 + v0;
    s0 = v0 + 496;
    a0 = s0;
    v0 = func_00374DF0(a0);
    v0 = s0 + 144;
    goto ret;
ret:
    return v0;
}
