/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator constructors.
 */

#include "types.h"

/* volatile mirrors the original stack temporary. */
Word* std_list_cActiveListItemPtr_generic_iterator_1_ctor(Word* self, int value) {
    volatile int tmp = value;
    self->value = tmp;
    return self;
}

void std_list_deleter_voidPtr_begin_void_2(Iter* out, PtrVec* v) {
    out->p = v->data;
}
