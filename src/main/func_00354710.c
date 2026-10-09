/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int func_00354890(FlaggedRel*);

/* FlaggedRel constructor. */
FlaggedRel* func_00354710(FlaggedRel* self) {
    func_00354890(self);
    self->unk0C = 1;
    return self;
}
