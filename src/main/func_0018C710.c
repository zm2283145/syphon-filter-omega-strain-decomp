/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0018C710(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void func_0018C730(Iter* out, Tree* t) {
    out->p = &t->header;
}
