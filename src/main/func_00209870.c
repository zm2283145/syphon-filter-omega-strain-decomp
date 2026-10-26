/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cPointer_cSkaNode_ctor_cPointerR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
