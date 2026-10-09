/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Sets the float at +0x48 of the sub-object, if present. */
void func_003FA190(Unk3FA190* self, float value) {
    Unk3FA190Sub* sub = self->unk50C;

    if (sub != 0) {
        sub->unk48 = value;
    }
}
