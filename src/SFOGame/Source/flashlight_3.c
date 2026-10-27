/*
 * SFOGame/Source/flashlight: 1 file, 0045BBE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045BBE0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0045BBE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045BBE0 */
