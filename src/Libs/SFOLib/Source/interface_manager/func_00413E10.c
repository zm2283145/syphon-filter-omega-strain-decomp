/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */

#include "types.h"

/* Zero-initialise a three-word record. */
Rel* func_00413E10(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
