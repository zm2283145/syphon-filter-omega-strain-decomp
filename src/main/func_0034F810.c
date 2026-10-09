/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int func_0034F900(FlaggedRel*);

/* FlaggedRel constructor. */
FlaggedRel* func_0034F810(FlaggedRel* self) {
    func_0034F900(self);
    self->unk0C = 1;
    return self;
}
