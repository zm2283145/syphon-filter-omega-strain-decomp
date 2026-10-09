/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int D_005331D0;
extern int func_00341F00(int);

Rel* func_00345000(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_00345020(void) {
    return func_00341F00(D_005331D0);
}
