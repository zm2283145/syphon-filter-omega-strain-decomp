/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0760[];
extern char D_004E0780[];
extern int ScalarCollection_Init(int);
extern void func_003EC2A0(int);

int func_003EC1D0(int a0) {
    int s0, v0;

    v0 = (int)D_004E0780;
    s0 = a0;
    *(int*)(char*)(a0 + 20) = v0;
    v0 = ScalarCollection_Init(a0);
    *(char*)(char*)(s0 + 12) = 0;
    v0 = (int)D_004E0760;
    *(int*)(char*)(s0 + 16) = 0;
    a0 = s0;
    *(int*)(char*)(s0 + 20) = v0;
    func_003EC2A0(a0);
    v0 = s0;
    goto ret;
ret:
    return v0;
}
