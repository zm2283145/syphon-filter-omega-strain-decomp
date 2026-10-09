/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatistics message handler (vtable D_004DEE70 slot 13).
 */

#include "loose03_types.h"

extern int func_00356B30(GuiMissionStatistics* self, int a1, int msg, int value);

/* GuiMissionStatistics message handler (vtable slot 13): 0x3000 stores `value`, everything else goes to func_00356B30. */
int func_0034FA40(GuiMissionStatistics* self, int a1, int msg, int value) {
    if ((msg & 0xFFFF) == 0x3000) {
        self->unk80 = value;
        return 1;
    }
    return func_00356B30(self, a1, msg, value);
}
