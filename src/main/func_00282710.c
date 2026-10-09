/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00506218[];

Rel* func_00282710(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int cBeamMsg_v05(void) {
    int tmp0;

    tmp0 = *(int*)D_00506218;
    return tmp0;
}
