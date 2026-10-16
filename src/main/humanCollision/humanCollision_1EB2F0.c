/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Reset the state block that follows a mask set (+0x30 flag, +0x50/+0x54 ids). */
Unk001EB2F0* func_001EB2F0(Unk001EB2F0* self) {
    self->unk30 = 0;
    self->unk50 = -1;
    self->unk54 = -1;
    self->unk58 = 0;
    return self;
}

/* Fill four mask words from pointers (same layout as HumanColPreset +0x04..+0x10). */
IntQuad* func_001EB310(IntQuad* self, int* m0, int* m1, int* m2, int* m3) {
    self->v[0] = *m0;
    self->v[1] = *m1;
    self->v[2] = *m2;
    self->v[3] = *m3;
    return self;
}
