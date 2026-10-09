/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator constructor.
 */

#include "types.h"

/* volatile mirrors the original stack temporary. */
Word* func_0016EFC0(Word* self, int value) {
    volatile int tmp = value;
    self->value = tmp;
    return self;
}
