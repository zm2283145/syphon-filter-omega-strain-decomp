/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

FloatPair* cVector_SetY(FloatPair* self, float value) {
    self->b = value;
    return self;
}
