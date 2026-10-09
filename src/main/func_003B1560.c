/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003B7470(int, int, int, int);

Rel* func_003B1560(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

unsigned char func_003B1580(unsigned char* self) {
    return self[69];
}

int func_003B1590(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_003B7470(a0, (tmp1 + (tmp0 << 5)), 1, a1);
}
