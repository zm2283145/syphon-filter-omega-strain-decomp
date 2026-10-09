/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Swaps in a new value and returns the old one. */
int func_003F5CD0(Unk3F5CD0* self, int value) {
    int old = self->unkA8;

    self->unkA8 = value;
    return old;
}

int func_003F5CE0(Unk3F5CD0* self) {
    return self->unkA8;
}

void func_003F5CF0(Unk3F5CD0* self) {
    self->unkA8 = 1;
}
