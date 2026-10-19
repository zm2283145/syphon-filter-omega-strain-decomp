/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentModify.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char g_LightMgr[];
extern int LightMgr_RebuildTable(void* p);
extern int GuiWidget_Draw(void* self);

int func_002C0380(void* self) {
    LightMgr_RebuildTable(g_LightMgr);
    return GuiWidget_Draw(self);
}
