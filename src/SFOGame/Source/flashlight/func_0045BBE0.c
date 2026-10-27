/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between flashlight.cc (ends 0x0045BAD0) and GuiGameScreen.cc (starts 0x0045BC10).
 */

#include "loose05_types.h"

const float FlashDazzleSize[4] = { 8.0f, 0.0f, 0.0f, 0.0f };

float cDazzleLight_GetDazzlePct(Float40* self) {
    return self->unk40;
}

int cDazzleLight_DazzleCoversScreen(void) {
    return 0;
}

float cDazzleLight_GetAttenDist(void) {
    return (*(float*)FlashDazzleSize);
}
