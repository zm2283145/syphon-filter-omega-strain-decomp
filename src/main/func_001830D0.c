/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Byte +0x2D and byte +0x2C set and byte +0x2E clear. */
int func_001830D0(Unk001830D0* self) {
    int v0;

    v0 = self->unk2D != 0;
    if (v0 != 0) {
        v0 = self->unk2C != 0;
    }
    if (v0 != 0) {
        v0 = (self->unk2E != 0) ^ 1;
    }
    return v0;
}
