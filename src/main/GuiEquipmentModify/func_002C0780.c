/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentModify.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GuiWidget_BaseWake(void* self);

int GuiEquipmentModify_Wake(void* self) {
    return GuiWidget_BaseWake(self);
}
