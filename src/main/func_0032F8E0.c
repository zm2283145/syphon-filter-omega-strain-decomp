/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00532AB8[];
extern int cAgentData_HasCommendation(int, int);
extern int cAgentData_HasSpecialRating(int, int);
extern int cAgentData_HasRating(int, int);
extern int func_00335350(int, int, int, int);

int Script_cAgentData_HasSpecialRating(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = cAgentData_HasSpecialRating(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int Script_cAgentData_HasCommendation(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = cAgentData_HasCommendation(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int Script_cAgentData_HasRating(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = cAgentData_HasRating(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}

int Script_cAgentData_HasOmega(int a0) {
    int a1, a2, a3, s0, v0;
    int cond;

    a3 = 0;
    a0 = *(int*)(char*)a0;
    a2 = *(int*)(char*)D_00532AB8;
    s0 = *(int*)(char*)(a0 + 2800);
    a1 = s0;
    v0 = func_00335350(a0, a1, a2, a3);
    cond = s0 == 0;
    v0 = 0;
    if (cond) goto L0032F9A8;
    v0 = *(unsigned char*)(char*)s0;
    v0 = (unsigned int)0 < (unsigned int)v0;
L0032F9A8:;
    v0 = (unsigned int)0 < (unsigned int)v0;
    goto ret;
ret:
    return v0;
}
