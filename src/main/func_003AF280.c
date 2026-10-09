/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003AF280(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void* func_003AF290(char* self) {
    return self + 8;
}
