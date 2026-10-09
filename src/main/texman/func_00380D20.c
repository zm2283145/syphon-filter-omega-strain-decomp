/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator helpers.
 */

#include "types.h"
#include "texman_types.h"

/* Address of the value held by the iterator's node. */
int* func_00380D20(TexListIter* it) {
    return &it->node->value;
}

void func_00380D30(Iter* out, PtrVec* v) {
    out->p = v->data;
}
