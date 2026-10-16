/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiScoresEquip.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00535D20[];
extern int LightMgr_RebuildTable(void* p);
extern int GuiWidget_Draw(void* self);

int func_0035BF70(void* self) {
    LightMgr_RebuildTable(D_00535D20);
    return GuiWidget_Draw(self);
}
