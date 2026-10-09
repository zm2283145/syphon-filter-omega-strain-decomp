/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001396D0(int, int);
extern int func_00336E40(int);

Rel* func_00336DC0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_00336DE0(int a0, int a1) {
    return func_001396D0(a0, a1);
}

Rel* func_00336DF0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_00336E10(int a0) {
    func_00336E40(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
