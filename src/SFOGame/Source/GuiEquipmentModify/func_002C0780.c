/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentModify.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GuiWidget_onWake(void* self);

int GuiEquipmentModify_onWake(void* self) {
    return GuiWidget_onWake(self);
}
