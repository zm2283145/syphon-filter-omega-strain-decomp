/*
 * Matched functions (byte-identical with the retail executable).
 * Light parameter setters.
 */

#include "types.h"
#include "gameLight_types.h"

void LightEffect_SetOuter(GameLightParams* self, float value) {
    self->unk14 = value;
}

void LightEffect_SetInner(GameLightParams* self, float value) {
    self->unk10 = value;
}
