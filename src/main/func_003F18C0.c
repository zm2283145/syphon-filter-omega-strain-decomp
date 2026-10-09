/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003F3370(int, int, int, int);
extern int func_003F3900(int, int);

Rel* func_003F18C0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_003F18E0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_003F3370(a0, (tmp1 + (tmp0 << 4)), 1, a1);
}

int func_003F1900(int a0, int a1) {
    return func_003F3900(a0, a1);
}
