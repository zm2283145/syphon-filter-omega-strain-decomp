/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAchievementScreen virtual (vtable D_004DEF90 slot 5).
 */

#include "loose03_types.h"

extern int Agent_GetSelected(void* agents, int index);
extern char D_004FFB50[];       /* agent list */
extern void func_00299510(void*);
extern int func_003334C0(int agent, int a1, void* a2);
extern void func_00356C70(GuiAchievementScreen*);  /* GuiPersonnelScreen slot 5 */

/* GuiAchievementScreen vtable slot 5: refresh unk6C, pass it with unk7C to the selected agent, then call func_00356C70. */
void func_00353800(GuiAchievementScreen* self) {
    func_00299510(self->unk6C);
    func_003334C0(Agent_GetSelected(D_004FFB50, -1), self->unk7C, self->unk6C);
    func_00356C70(self);
}
