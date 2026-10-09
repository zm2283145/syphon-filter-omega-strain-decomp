/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

FloatPair* func_00209EB0(FloatPair* dst, FloatPair* src) {
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}

Word* func_00209ED0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
