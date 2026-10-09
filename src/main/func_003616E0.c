/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0033D310(int);
extern int func_004147A0(void);

void func_003616E0(int a0) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    func_0033D310(a0);
    v1 = *(int*)(char*)(s0 + 288);
    cond = v1 == 0;
    if (cond) goto L00361720;
    v0 = func_004147A0();
    v1 = *(int*)(char*)(v0 + 44);
    v1 = *(int*)(char*)(v1 + 8);
    cond = v1 == s0;
    if (cond) goto L00361720;
    v1 = *(int*)(char*)(s0 + 288);
    *(int*)(char*)(v1 + 1248) = 0;
L00361720:;
    goto ret;
ret:;
}
