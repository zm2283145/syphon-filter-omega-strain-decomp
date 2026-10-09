/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0800[];
extern int func_003F2020(int, int, int, int);

Rel* func_003F1BF0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_003F1C10(int a0) {
    *(int*)((char*)a0) = (int)D_004E0800;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0xbf800000;
    *(int*)((char*)a0 + 12) = 0xbf800000;
    *(int*)((char*)a0 + 16) = 0;
    *(char*)((char*)a0 + 20) = 0;
    return a0;
}

int func_003F1C40(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 8);
    tmp1 = *(int*)((char*)a0 + 4);
    return func_003F2020(a0, (tmp0 + tmp1), 1, a1);
}
