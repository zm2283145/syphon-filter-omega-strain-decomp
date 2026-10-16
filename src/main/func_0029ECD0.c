/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern GameMachine* D_004FFC04;
extern int FrontEnd_ClosePopup(GameMachine* machine, int arg);
extern void GuiScreen_Sleep(GuiScreen* self);
extern GuiManager* Gui_GetScreenStack(void);
extern int LobbyArray_Free(GuiSlot* slot);

/* GuiOnlineConnect vtable slot 6: base call, reset the three slots, clear manager flags 0x0C. */
int func_0029ECD0(GuiOnlineConnect* self) {
    GuiManager* mgr;

    GuiScreen_Sleep(&self->base);
    LobbyArray_Free(&self->slots[0]);
    LobbyArray_Free(&self->slots[1]);
    LobbyArray_Free(&self->slots[2]);
    D_004FFC04->unk2A = 1;
    mgr = Gui_GetScreenStack();
    mgr->flags &= ~0xC;
    return FrontEnd_ClosePopup(D_004FFC04, self->base.base.unk48);
}
