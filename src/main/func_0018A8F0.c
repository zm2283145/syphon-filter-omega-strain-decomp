/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001004B0(int, int, int, int, int);
extern int func_0018A210(int, int);
extern int func_0018A870(int);

Rel* func_0018A8F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_0018A910(int a0) {
    func_001004B0(a0, (int)func_0018A870, (int)func_0018A210, 8, 7);
    return a0;
}
