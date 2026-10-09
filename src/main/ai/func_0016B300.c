/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copy.
 */

#include "types.h"

Word* func_0016B300(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
