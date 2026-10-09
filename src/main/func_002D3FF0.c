/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0015DDB0(int);

int func_002D3FF0(int a0) {
    int v0;
    int cond;

    v0 = *(int*)(char*)(a0 + 480);
    v0 = (unsigned int)0 < (unsigned int)v0;
    cond = v0 == 0;
    if (cond) goto L002D4008;
    v0 = *(int*)(char*)(a0 + 484);
    v0 = (unsigned int)0 < (unsigned int)v0;
L002D4008:;
    cond = v0 == 0;
    if (cond) goto L002D401C;
    v0 = *(int*)(char*)(a0 + 484);
    v0 = *(unsigned char*)(char*)(v0 + 4);
    v0 = (unsigned int)0 < (unsigned int)v0;
L002D401C:;
    goto ret;
ret:
    return v0;
}

int func_002D4030(int a0) {
    int v0;
    int cond;

    v0 = *(int*)(char*)(a0 + 480);
    v0 = (unsigned int)0 < (unsigned int)v0;
    cond = v0 == 0;
    if (cond) goto L002D4048;
    v0 = *(int*)(char*)(a0 + 484);
    v0 = (unsigned int)0 < (unsigned int)v0;
L002D4048:;
    cond = v0 == 0;
    if (cond) goto L002D405C;
    v0 = *(int*)(char*)(a0 + 484);
    v0 = *(unsigned char*)(char*)(v0 + 4);
    v0 = (unsigned int)0 < (unsigned int)v0;
L002D405C:;
    goto ret;
ret:
    return v0;
}

void func_002D4070(int a0, int a1) {
    int tmp0;

    *(int*)((char*)a0 + 520) = a1;
    tmp0 = func_0015DDB0(a1);
    *(int*)((char*)a0 + 488) = tmp0;
}
