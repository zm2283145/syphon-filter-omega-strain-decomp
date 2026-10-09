/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator constructors.
 */

#include "types.h"

/* volatile mirrors the original stack temporary. */
Word* func_0016E860(Word* self, int value) {
    volatile int tmp = value;
    self->value = tmp;
    return self;
}

void func_0016E880(Iter* out, PtrVec* v) {
    out->p = v->data;
}
