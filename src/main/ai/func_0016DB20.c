/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copies.
 */

#include "types.h"

Word* func_0016DB20(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0016DB30(Word* dst, Word* src) {
    dst->value = src->value;
}
