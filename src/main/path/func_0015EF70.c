/*
 * Matched functions (byte-identical with the retail executable).
 * List iterator dereference.
 */

#include "types.h"
#include "path_types.h"

int* func_0015EF70(PathListNode** it) {
    return &(*it)->value;
}
