/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_00298420(int);
extern int func_004147A0(void);

void func_00297350(int a0) {
    int a1, s0, v0, v1;
    int cond;

    v1 = *(unsigned char*)(char*)(a0 + 128);
    cond = v1 == 0;
    s0 = a0;
    if (cond) goto L00297398;
    v0 = func_004147A0();
    a1 = *(int*)(char*)(v0 + 104);
    v1 = 0 + -13;
    a0 = s0;
    v1 = a1 & v1;
    *(int*)(char*)(v0 + 104) = v1;
    func_00298420(a0);
    v1 = 0 + -1;
    *(int*)(char*)(s0 + 460) = v1;
    *(int*)(char*)(s0 + 464) = 0;
    *(char*)(char*)(s0 + 128) = 0;
L00297398:;
    goto ret;
ret:;
}
