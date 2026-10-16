/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Rec377C30 constructor: zero all words, set the flag byte. */
Rec377C30* func_00377C30(Rec377C30* self) {
    self->unk[0] = 0;
    self->unk[1] = 0;
    self->unk[2] = 0;
    self->unk[3] = 0;
    self->unk[4] = 0;
    self->unk[5] = 0;
    self->unk[6] = 0;
    self->unk[7] = 0;
    self->unk[8] = 0;
    self->unk[9] = 0;
    self->unk[10] = 0;
    self->unk2C = 1;
    return self;
}
