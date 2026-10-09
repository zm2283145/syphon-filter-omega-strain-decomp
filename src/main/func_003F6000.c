/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

int func_003F6000(Unk3F6000* self) {
    return self->unk0C == self->unk10;
}

void func_003F6020(Unk3F6000* self) {
    self->unk0C = 0;
    self->unk08 = 0;
}

void func_003F6030(void) {
}
