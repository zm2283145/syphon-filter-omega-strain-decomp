/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern void cHud_ClearTarget(void* self);

void cHud_DeactivateAimCursor(void* self) {
    cHud_ClearTarget(self);
}
