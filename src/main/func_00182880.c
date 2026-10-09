/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_00181E80(void* self, int* it);
extern int func_00182260(void* self, int* it);

int func_00182880(Unk00182880* self) {
    int it[1];

    it[0] = self->unk10;
    return func_00181E80(self, it);
}

int func_001828B0(Unk00182880* self) {
    int it[1];

    it[0] = self->unk08;
    return func_00182260(self, it);
}
