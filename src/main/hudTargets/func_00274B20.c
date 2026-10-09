/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

/* Clears a fresh marker record. */
ObjMarkerRecord* ObjMarkerRecord_Init(ObjMarkerRecord* self) {
    self->id = 0;
    self->icon0 = 0;
    self->icon1 = 0;
    self->unk0C = 0;
    self->unk18 = -2;
    self->unk14 = 0;
    self->text = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->text2 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    return self;
}
