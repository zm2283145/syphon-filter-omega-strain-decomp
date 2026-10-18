/*
 * Matched functions (byte-identical with the retail executable).
 * PathPoint constructor.
 */

#include "types.h"
#include "path_types.h"

PathPoint* NpcNodeSearch_SetQuery(PathPoint* self, int tag, float x, float y) {
    self->x = x;
    self->y = y;
    self->tag = tag;
    return self;
}
