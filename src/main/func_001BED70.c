/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

float func_001BED70(FloatPair* self) {
    return self->b;
}

/* Copy six floats. */
Float6* func_001BED80(Float6* d, Float6* s) {
    d->f[0] = s->f[0];
    d->f[1] = s->f[1];
    d->f[2] = s->f[2];
    d->f[3] = s->f[3];
    d->f[4] = s->f[4];
    d->f[5] = s->f[5];
    return d;
}
