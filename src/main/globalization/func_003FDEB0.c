/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc
 */

#include "types.h"

extern int func_003FECD0(int a0, int a1);

/* Thunk to func_003FECD0. */
int func_003FDEB0(int a0, int a1) {
    return func_003FECD0(a0, a1);
}

/* Zero-initialise a three-word record. */
Rel* func_003FDEC0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
