/*
 * Matched functions (byte-identical with the retail executable).
 * List iterator dereference.
 */

#include "types.h"
#include "path_types.h"

int* cConstLListIterator_cPathSystemRequestPtr_opMul(PathListNode** it) {
    return &(*it)->value;
}
