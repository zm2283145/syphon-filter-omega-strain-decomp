/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentCreate.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00535D20[];
extern int LightMgr_RebuildTable(void* p);
extern int func_0041E470(void* self);

int func_0028E600(void* self) {
    LightMgr_RebuildTable(D_00535D20);
    return func_0041E470(self);
}
