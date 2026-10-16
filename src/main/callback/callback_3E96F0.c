/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern void IeElement_SetPosition(int, void*);
extern void HudTracker_ToCameraSpace(void*);
extern float IeElement_Fade(int, float);
extern void IeElement_EvaluateAt(int, float);

void func_003E96F0(Unk3E96F0* self) {
    HudTracker_ToCameraSpace(self->unk70);
    IeElement_SetPosition(self->unk60, self->unk70);
}

void func_003E9730(Unk3E96F0* self) {
    IeElement_EvaluateAt(self->unk60, 0.0f);
    self->unk84 = 1;
}

void HudTracker_Kill(Unk3E96F0* self) {
    IeElement_Fade(self->unk60, 0.0f);
    self->unk84 = 1;
}

void HudTracker_Attach(Unk3E96F0* self, int* value, int arg) {
    self->unk68 = *value;
    self->unk64 = 1;
    self->unk80 = arg;
}
