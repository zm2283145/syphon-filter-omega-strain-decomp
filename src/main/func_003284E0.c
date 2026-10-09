/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern Rel* func_003285D0(Rel* r);

/* Owning vector constructor. */
OwnedRel* func_003284E0(OwnedRel* self) {
    func_003285D0(&self->vec);
    self->owned = 1;
    return self;
}
