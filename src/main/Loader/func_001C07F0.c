/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"
#include "Loader_types.h"

extern PtrVec* func_001C0840(PtrVec* v);

/* Zero-initialise a three-word vector. */
Rel* func_001C07F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Construct an empty vector that owns its elements. */
LoaderOwnedVec* func_001C0810(LoaderOwnedVec* self) {
    func_001C0840(&self->vec);
    self->owns = 1;
    return self;
}
