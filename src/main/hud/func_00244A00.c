/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern void Hud_ClearTargetLock(void* self);

void Hud_CrosshairRelease(void* self) {
    Hud_ClearTargetLock(self);
}
