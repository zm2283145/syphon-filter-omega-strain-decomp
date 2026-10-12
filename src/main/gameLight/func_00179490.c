/*
 * Matched functions (byte-identical with the retail executable).
 * Light parameter setter.
 */

#include "types.h"
#include "gameLight_types.h"

void Light_SetId(GameLightParams* self, int value) {
    self->unk08 = value;
}
