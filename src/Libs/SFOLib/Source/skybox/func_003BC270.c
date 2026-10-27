/*
 * Matched functions (byte-identical with the retail executable).
 * cSKYBOX_GOBJ field setter.
 */

#include "types.h"
#include "skybox_types.h"

void cSKYBOX_GOBJ_Init(cSkyboxGobj* self, int value) {
    self->unk8C = value;
}
