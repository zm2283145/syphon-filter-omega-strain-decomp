/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* Zero-initialise a three-word vector. */
Rel* func_001C29F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
