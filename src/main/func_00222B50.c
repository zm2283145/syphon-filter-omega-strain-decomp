/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

void* func_00222B50(char* self) {
    return self + 4;
}

/* Empty circular list: header node points to itself. */
List* func_00222B60(List* l) {
    l->count = 0;
    l->last = &l->first;
    l->first = &l->first;
    return l;
}
