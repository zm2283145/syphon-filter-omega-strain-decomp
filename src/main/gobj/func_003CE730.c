/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Builds a three-word record from one word of a and two words of b. */
Rel* func_003CE730(Rel* r, int* a, int* b) {
    r->a = a[0];
    r->b = b[0];
    r->c = b[1];
    return r;
}
