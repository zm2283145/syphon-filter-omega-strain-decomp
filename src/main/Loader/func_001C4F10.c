/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* Clear the element count. */
void std_vector_deleter_cString4_clear(PtrVec* v) {
    v->count = 0;
}
