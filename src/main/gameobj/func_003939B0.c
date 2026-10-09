/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Address of the value stored at +8 of the current node. */
char* func_003939B0(Iter16* it) {
    return it->p + 8;
}

void func_003939C0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
