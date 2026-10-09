/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003E2630(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_003E2640(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
