/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiMissionList.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiMissionList_types.h"

extern int func_002ACB70(GuiMissionList* self);

/* Stores a1 at +0x11C, resets three selection indices to -1 and refreshes. */
int func_002ACC80(GuiMissionList* self, int a1) {
    self->unk11C = a1;
    self->unkCC = -1;
    self->unkC4 = -1;
    self->unkC0 = -1;
    return func_002ACB70(self);
}
