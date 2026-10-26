/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"
#include "Loader_types.h"

extern PtrVec* std_vector_imp_cSkaNodePtr_1_ctor(PtrVec* v);

/* Construct an empty vector that owns its elements. */
LoaderOwnedVec* cArray_cSkaNodePtr_ctor(LoaderOwnedVec* self) {
    std_vector_imp_cSkaNodePtr_1_ctor(&self->vec);
    self->owns = 1;
    return self;
}
