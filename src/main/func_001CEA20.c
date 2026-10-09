/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* True when byte +0x380 is clear and byte +0x381 is set. */
int func_001CEA20(Unk001CEA20* self) {
    int v0;

    v0 = (self->unk380 != 0) ^ 1;
    if (v0 != 0) {
        v0 = self->unk381 != 0;
    }
    return v0;
}

/* Store a byte and whether it is non-zero. */
void func_001CEA50(ByteBool* self, int value) {
    self->value = value;
    self->nonZero = (value & 255) != 0;
}
