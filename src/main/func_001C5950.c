/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DAA10[];
extern char D_004DF860[];
extern int func_003CF0E0(int, int, int, int);

int func_001C5950(int a0, int a1, int a2) {
    int loc[1];
    int a3, s0, s1, v0, v1;

    a3 = (int)loc;
    s1 = a0;
    s0 = a2;
    *(int*)(char*)loc = 0;
    a2 = 0 + 4;
    v0 = func_003CF0E0(a0, a1, a2, a3);
    v0 = (int)D_004DF860;
    a1 = 0x3f800000;
    *(int*)(char*)s1 = v0;
    a0 = 0 + 1;
    *(int*)(char*)(s1 + 96) = s0;
    v1 = (int)D_004DAA10;
    *(int*)(char*)(s1 + 100) = 0;
    v0 = s1;
    *(short*)(char*)(s1 + 104) = 0;
    *(int*)(char*)(s1 + 112) = a1;
    *(char*)(char*)(s1 + 47) = a0;
    *(int*)(char*)s1 = v1;
    goto ret;
ret:
    return v0;
}
