/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiEquipmentSetup_types.h"

extern void* D_00506550;
extern int func_002A2590(void* p);

void func_002A5440(EquipSetupState* self, int value) {
    EquipSlot* slot = self->slot;

    if (slot != 0) {
        slot->unk32 = value;
    }
}

int func_002A5460(void) {
    return func_002A2590(D_00506550);
}
