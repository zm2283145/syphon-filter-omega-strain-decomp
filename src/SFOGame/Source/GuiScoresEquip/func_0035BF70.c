/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiScoresEquip.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char g_LightMgr[];
extern int cLightMan_BuildVisibleLightSubset(void* p);
extern int GuiWidget_onRender(void* self);

int GuiScoresEquip_onRender(void* self) {
    cLightMan_BuildVisibleLightSubset(g_LightMgr);
    return GuiWidget_onRender(self);
}
