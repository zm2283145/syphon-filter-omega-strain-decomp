/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern GameMachine* D_004FFC04;
extern int FrontEnd_ClosePopup(GameMachine* machine, int arg);
extern void func_0033D360(GuiScreen* self);
extern GuiManager* Gui_GetScreenStack(void);
extern int func_0044F6B0(GuiSlot* slot);

/* GuiOnlineConnect vtable slot 6: base call, reset the three slots, clear manager flags 0x0C. */
int func_0029ECD0(GuiOnlineConnect* self) {
    GuiManager* mgr;

    func_0033D360(&self->base);
    func_0044F6B0(&self->slots[0]);
    func_0044F6B0(&self->slots[1]);
    func_0044F6B0(&self->slots[2]);
    D_004FFC04->unk2A = 1;
    mgr = Gui_GetScreenStack();
    mgr->flags &= ~0xC;
    return FrontEnd_ClosePopup(D_004FFC04, self->base.base.unk48);
}
