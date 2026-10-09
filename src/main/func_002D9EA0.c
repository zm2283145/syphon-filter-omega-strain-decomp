/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sets flag bits; returns the new flags. */
unsigned int func_002D9EA0(Obj2D9* self, unsigned int bits) {
    return self->flags |= bits;
}
