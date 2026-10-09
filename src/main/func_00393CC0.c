/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00393D10(int);
extern int func_00393D40(int);
extern int func_00393EC0(int);

Rel* func_00393CC0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_00393CE0(int a0) {
    func_00393D10(a0);
    return a0;
}

int func_00393D10(int a0) {
    func_00393D40(a0);
    return a0;
}

int func_00393D40(int a0) {
    func_00393EC0(a0);
    *(int*)((char*)a0 + 16) = 0;
    *(int*)((char*)a0 + 20) = 0;
    return a0;
}
