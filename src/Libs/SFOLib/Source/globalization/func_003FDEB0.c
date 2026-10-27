/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc
 */

#include "types.h"

extern int std_vector_imp_1_reserve(int a0, int a1);

/* Thunk to std_vector_imp_1_reserve. */
int std_vector_1_reserve(int a0, int a1) {
    return std_vector_imp_1_reserve(a0, a1);
}

/* Zero-initialise a three-word record. */
Rel* std_vector_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
