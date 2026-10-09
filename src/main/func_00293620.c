/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_002CC260(int, int);

int* func_00293620(PtrVec* v, int i) {
    return v->data + i;
}

Rel* func_00293630(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

void func_00293650(void) {
    func_002CC260(0, 0);
}
