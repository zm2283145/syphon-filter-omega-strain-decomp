/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0053924C[];
extern void func_003D2190(int, int);
extern void func_003D2320(int, int);

int func_00378110(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)D_0053924C;
    func_003D2190(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00378140(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)D_0053924C;
    func_003D2320(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
