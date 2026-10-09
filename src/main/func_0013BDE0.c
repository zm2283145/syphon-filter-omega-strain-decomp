/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_0013BCB0(Unk0013BDE0* self, int a1);

/* Base init through func_0013BCB0, then store the word at +0x0C. */
int func_0013BDE0(Unk0013BDE0* self, int a1, int value) {
    int result;

    result = func_0013BCB0(self, a1);
    self->unk0C = value;
    return result;
}
