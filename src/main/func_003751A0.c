/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

float XLib_GetZBuffMin(Obj3751A0* self) {
    return self->unk34;
}

float XLib_GetZBuffMax(Obj3751A0* self) {
    return self->unk38;
}

float XLib_GetGuardBandScaleY(Obj3751A0* self) {
    return self->unk78[self->unk88];
}

float XLib_GetGuardBandScaleX(Obj3751A0* self) {
    return self->unk68[self->unk88];
}

void* XLib_GetFullscreenWindow(char* self) {
    return self + 3968;
}
