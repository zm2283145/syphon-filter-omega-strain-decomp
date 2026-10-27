/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Swaps in a new value and returns the old one. */
int videoDecSetState(Unk3F5CD0* self, int value) {
    int old = self->unkA8;

    self->unkA8 = value;
    return old;
}

int videoDecGetState(Unk3F5CD0* self) {
    return self->unkA8;
}

void videoDecAbort(Unk3F5CD0* self) {
    self->unkA8 = 1;
}
