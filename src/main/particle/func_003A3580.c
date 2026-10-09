/*
 * Matched functions (byte-identical with the retail executable).
 * Small container helpers.
 */

#include "types.h"

Word* func_003A3580(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
