/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copy.
 */

#include "types.h"

Word* cConstLListIterator_cActiveListItemPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
