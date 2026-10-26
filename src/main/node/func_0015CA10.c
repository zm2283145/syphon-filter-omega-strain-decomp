/*
 * Matched functions (byte-identical with the retail executable).
 * Vector clear: resets the element count.
 */

#include "types.h"
#include "node_types.h"

void std_vector_deleter_tNodeLink_clear(PtrVec* v) {
    v->count = 0;
}
