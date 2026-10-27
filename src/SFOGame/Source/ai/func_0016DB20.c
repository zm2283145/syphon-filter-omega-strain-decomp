/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copies.
 */

#include "types.h"

Word* std_list_cTargetAwarenessPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cTargetAwarenessPtr_generic_iterator_opCast(Word* dst, Word* src) {
    dst->value = src->value;
}
