/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiEquipmentSetup_types.h"

extern char D_00535D20[];
extern int LightMgr_RebuildTable(void* p);
extern int func_0041E470(GuiEquipmentSetup* self);

int func_002A2EC0(GuiEquipmentSetup* self) {
    LightMgr_RebuildTable(D_00535D20);
    return func_0041E470(self);
}
