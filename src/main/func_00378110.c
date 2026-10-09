/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0053924C[];
extern void Global_DecTexture(int, int);
extern void Global_IncTexture(int, int);

int Script_DecTexture(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)D_0053924C;
    Global_DecTexture(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_IncTexture(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)D_0053924C;
    Global_IncTexture(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
