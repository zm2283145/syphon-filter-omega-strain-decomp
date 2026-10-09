/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"
#include "Loader_types.h"

extern PtrVec* func_001C0700(PtrVec* v);

/* Construct an empty vector that owns its elements. */
LoaderOwnedVec* func_001C05E0(LoaderOwnedVec* self) {
    func_001C0700(&self->vec);
    self->owns = 1;
    return self;
}
