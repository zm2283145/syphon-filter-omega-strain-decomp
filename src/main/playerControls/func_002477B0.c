/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

extern int func_001BE090(Pair8Vec* v, Pair8* pos, int n, Pair8* value);

int func_002477B0(ControlsUnk5C* self) {
    return self->unk5C + -1;
}

/* push_back on a vector of 8-byte elements. */
int func_002477C0(Pair8Vec* v, Pair8* value) {
    return func_001BE090(v, v->data + v->count, 1, value);
}

OptFloat* func_002477E0(OptFloat* self, float value) {
    self->set = 1;
    self->value = value;
    return self;
}
