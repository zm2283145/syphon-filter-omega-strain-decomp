/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

/* Iterator equality against a raw value. */
int func_0024FD80(Word* it, int value) {
    return it->value == value;
}

void* func_0024FD90(void* self) {
    return self;
}
