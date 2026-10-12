/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between flashlight.cc (ends 0x0045BAD0) and GuiGameScreen.cc (starts 0x0045BC10).
 */

#include "loose05_types.h"

extern float FlashDazzleSize;

float FlashGlare_GetCoronaSize(Float40* self) {
    return self->unk40;
}

int FlashGlare_GetCoronaFlag(void) {
    return 0;
}

float FlashGlare_GetRange(void) {
    return FlashDazzleSize;
}
