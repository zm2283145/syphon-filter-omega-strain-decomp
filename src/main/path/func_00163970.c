/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D9720[];
extern char D_004D9730[];
extern char D_004D9740[];
extern char D_004D9750[];

int func_00163970(int a0) {
    int a1, a2, a3, v0, v1;

    v0 = (int)D_004D9740;
    *(int*)(char*)a0 = v0;
    a1 = (int)D_004D9730;
    a2 = a0 + 16;
    v0 = (int)D_004D9720;
    a3 = a0 + 4;
    *(int*)(char*)(a0 + 4) = v0;
    v1 = (int)D_004D9750;
    *(int*)(char*)(a0 + 4) = a1;
    *(int*)(char*)(a0 + 16) = v0;
    *(int*)(char*)(a0 + 16) = a1;
    v0 = a0;
    *(int*)(char*)(a0 + 8) = a2;
    *(int*)(char*)(a0 + 12) = a3;
    *(int*)(char*)(a0 + 20) = a2;
    *(int*)(char*)(a0 + 24) = a3;
    *(int*)(char*)(a0 + 28) = 0;
    *(int*)(char*)a0 = v1;
    goto ret;
ret:
    return v0;
}
