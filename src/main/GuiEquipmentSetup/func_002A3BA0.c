/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiEquipmentSetup_types.h"

extern int func_0041EFA0(GuiEquipmentSetup* self);

int func_002A3BA0(char* self) {
    return *(int*)(self + 0);
}

/* Calls the base handler, then resets +0xDC and the view angle to pi. */
int func_002A3BB0(GuiEquipmentSetup* self) {
    int result = func_0041EFA0(self);

    self->unkDC = 0;
    self->angle = 3.14159265f;
    return result;
}
