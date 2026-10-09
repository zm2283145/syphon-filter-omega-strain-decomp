/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

unsigned char func_00260940(unsigned char* self) {
    return self[1];
}

void func_00260950(Unk260940* self, float a, float b, float c, float d) {
    self->unk08 = a;
    self->unk0C = b;
    self->unk10 = c;
    self->unk14 = d;
}

void func_00260970(Unk260940* self) {
    self->unk04 = 0;
    self->unk14 = 0.0f;
    self->unk10 = 0.0f;
    self->unk0C = 0.0f;
    self->unk08 = 0.0f;
    self->unk00 = 0;
    self->unk01 = 0;
}
