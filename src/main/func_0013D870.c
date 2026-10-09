/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Iterator from a node pointer (passed through the stack). */
Iter* func_0013D870(Iter* out, int* node) {
    int* volatile tmp = node; /* stored to the stack and reloaded */

    out->p = tmp;
    return out;
}

void func_0013D890(Iter* out, Tree* t) {
    out->p = &t->header;
}
