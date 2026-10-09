/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern void func_003E8180(int, void*);
extern void func_003E9A60(void*);
extern float func_003F44E0(int, float);
extern void func_003F45A0(int, float);

void func_003E96F0(Unk3E96F0* self) {
    func_003E9A60(self->unk70);
    func_003E8180(self->unk60, self->unk70);
}

void func_003E9730(Unk3E96F0* self) {
    func_003F45A0(self->unk60, 0.0f);
    self->unk84 = 1;
}

void func_003E9770(Unk3E96F0* self) {
    func_003F44E0(self->unk60, 0.0f);
    self->unk84 = 1;
}

void func_003E97B0(Unk3E96F0* self, int* value, int arg) {
    self->unk68 = *value;
    self->unk64 = 1;
    self->unk80 = arg;
}
