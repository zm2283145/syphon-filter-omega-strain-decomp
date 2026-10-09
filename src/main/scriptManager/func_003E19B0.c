/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003E1A00(int);

Rel* func_003E19B0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_003E19D0(int a0) {
    func_003E1A00(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
