/*
 * Matched functions (byte-identical with the retail executable).
 * PathCursor constructor.
 */

#include "types.h"
#include "path_types.h"

PathCursor* func_00161930(PathCursor* self, int owner) {
    self->owner = owner;
    self->unk20 = 0;
    self->unk28 = 0;
    self->unk14 = -1;
    self->unk10 = -1;
    return self;
}
