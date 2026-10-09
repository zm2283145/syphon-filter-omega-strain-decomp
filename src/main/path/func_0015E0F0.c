/*
 * Matched functions (byte-identical with the retail executable).
 * PathPoint constructor.
 */

#include "types.h"
#include "path_types.h"

PathPoint* func_0015E0F0(PathPoint* self, int tag, float x, float y) {
    self->x = x;
    self->y = y;
    self->tag = tag;
    return self;
}
