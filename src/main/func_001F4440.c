/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

FloatPair* cSkaBlendSequenceExtents_ctor_cSkaBlendSequenceExtentsR(FloatPair* dst, FloatPair* src) {
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}

FloatPair* cSkaBlendSequenceExtents_ctor_float_float(FloatPair* self, float a, float b) {
    self->a = a;
    self->b = b;
    return self;
}
