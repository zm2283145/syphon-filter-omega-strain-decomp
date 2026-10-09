/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern void* func_0013BCB0(void* dst, void* src);
extern Rel* func_0032A0B0(Rel* dst, Rel* src);

/* Copy constructor. */
Rec32A050* func_0032A050(Rec32A050* self, Rec32A050* src) {
    OwnedRel* vec;

    func_0013BCB0(self, src);
    vec = &self->vec;
    func_0032A0B0(&vec->vec, &src->vec.vec);
    vec->owned = src->vec.owned;
    self->unk1C = src->unk1C;
    return self;
}
