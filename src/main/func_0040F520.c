/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void Tree_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

void Tree_Begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
