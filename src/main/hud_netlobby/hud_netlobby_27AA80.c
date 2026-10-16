/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Word* func_0027AA80(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Address 8 bytes past the node stored at +8. */
char* func_0027AA90(PtrVec* self) {
    return (char*)self->data + 8;
}
