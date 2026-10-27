/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator constructor.
 */

#include "types.h"

/* volatile mirrors the original stack temporary. */
Word* std_list_cTargetAwarenessPtr_generic_iterator_1_ctor(Word* self, int value) {
    volatile int tmp = value;
    self->value = tmp;
    return self;
}
