/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00494150[];
extern char D_004E0D20[];
extern int PtrVec_PushBack_1C1080(int, int);
extern int func_001C10A0(int);
extern int func_0041F690(int);

int func_00424C50(int a0) {
    int a1, s0, s1, v0, v1;

    s0 = a0;
    v0 = func_0041F690(a0);
    s1 = s0 + 96;
    v0 = (int)D_004E0D20;
    a0 = s1;
    *(int*)(char*)s0 = v0;
    v0 = func_001C10A0(a0);
    v1 = 0 + 1;
    *(char*)(char*)(s1 + 12) = v1;
    v0 = 0 + 24;
    *(char*)(char*)(s0 + 88) = 0;
    a0 = s1;
    *(int*)(char*)(s0 + 72) = v1;
    a1 = (int)D_00494150;
    *(int*)(char*)(s0 + 76) = v1;
    *(int*)(char*)(s0 + 80) = 0;
    *(int*)(char*)(s0 + 84) = 0;
    *(int*)(char*)(s0 + 92) = v0;
    v0 = PtrVec_PushBack_1C1080(a0, a1);
    v1 = *(int*)(char*)(s0 + 72);
    v0 = s0;
    *(int*)(char*)(s0 + 112) = v1;
    v1 = *(int*)(char*)(s0 + 76);
    *(int*)(char*)(s0 + 116) = v1;
    v1 = *(int*)(char*)(s0 + 80);
    *(int*)(char*)(s0 + 120) = v1;
    v1 = *(int*)(char*)(s0 + 84);
    *(int*)(char*)(s0 + 124) = v1;
    *(char*)(char*)(s0 + 130) = 0;
    *(int*)(char*)(s0 + 132) = 0;
    *(char*)(char*)(s0 + 129) = 0;
    *(char*)(char*)(s0 + 128) = 0;
    *(int*)(char*)(s0 + 136) = 0;
    *(int*)(char*)(s0 + 140) = 0;
    goto ret;
ret:
    return v0;
}
