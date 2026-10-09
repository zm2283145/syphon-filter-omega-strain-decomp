/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Address of element i in an array of 32-byte elements. */
char* func_003AE340(SkaVec* v, int i) {
    return v->data + (i << 5);
}
