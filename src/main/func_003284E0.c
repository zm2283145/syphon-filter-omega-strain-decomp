/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern Rel* std_vector_imp_Slide_ctor(Rel* r);

/* Owning vector constructor. */
OwnedRel* cArray_Slide_ctor(OwnedRel* self) {
    std_vector_imp_Slide_ctor(&self->vec);
    self->owned = 1;
    return self;
}
