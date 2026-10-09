/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

FloatPair* MotionSliderChild_CopyThresholds(FloatPair* dst, FloatPair* src) {
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}

FloatPair* func_001F4460(FloatPair* self, float a, float b) {
    self->a = a;
    self->b = b;
    return self;
}
