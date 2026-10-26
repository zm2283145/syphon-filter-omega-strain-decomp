/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

FloatPair* cSkaBlendSequenceExtents_opAssign(FloatPair* dst, FloatPair* src) {
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}

Word* cPointer_cSkaNode_opAssign(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
