/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001C0840(int);

Rel* func_001C07F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_001C0810(int a0) {
    func_001C0840(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
