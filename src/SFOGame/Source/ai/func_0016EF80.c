/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copy.
 */

#include "types.h"

Word* cConstLListIterator_cTargetAwarenessPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
