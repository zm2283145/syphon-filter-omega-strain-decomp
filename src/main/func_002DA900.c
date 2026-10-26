/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

int GetLocalID(Obj2D9* self, int* out) {
    *out = self->unk78;
    return 0;
}

int GetCurChannel(Obj2D9* self) {
    return self->unk98;
}
