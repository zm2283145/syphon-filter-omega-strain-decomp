/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00487860[];

int func_00117008(int a0) {
    int v0, v1;
    int cond;

    v0 = *(int*)((char*)a0 + 4);
    cond = v0 == 0;
    v1 = *(int*)(char*)a0;
    if (cond) goto L0011701C;
    *(int*)(char*)v0 = v1;
    goto L00117024;
L0011701C:;
    *(int*)(char*)D_00487860 = v1;
L00117024:;
    if (v1 == 0) {
    *(int*)((char*)a0 + 4) = 0;
    goto L00117038;
    }
    v0 = *(int*)((char*)a0 + 4);
    *(int*)((char*)v1 + 4) = v0;
    *(int*)((char*)a0 + 4) = 0;
L00117038:;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
